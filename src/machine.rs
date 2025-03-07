use std::{cell::RefCell, rc::Rc};

use crate::{
    bus::{BusClient, BusError, BusForwarder},
    config::MachineConfig,
};

struct MemoryRegion {
    name: String,
    start_address: u32,
    buffer: Vec<u8>,
}

struct MemoryRegionMirror {
    start_address: u32,
    original_region: Rc<RefCell<MemoryRegion>>,
}

pub struct Machine {
    memory_regions: Vec<Rc<RefCell<MemoryRegion>>>,
    mirrored_regions: Vec<Rc<RefCell<MemoryRegionMirror>>>,
    bus_handler: BusForwarder,
}

impl MemoryRegion {
    fn create(start_address: u32, size: usize, name: &str) -> Self {
        MemoryRegion {
            name: String::from(name),
            start_address,
            buffer: vec![0; size],
        }
    }

    fn address_is_managed(&self, address: u32) -> bool {
        address >= self.start_address && address < self.start_address + (self.buffer.len() as u32)
    }

    fn out_of_bounds_check(&self, address: u32, length: usize) -> bool {
        address as usize + length > self.start_address as usize + self.buffer.len()
    }
}

impl BusClient for MemoryRegion {
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        if !self.address_is_managed(address) {
            return Err(BusError::InvalidAddress(address));
        }

        if self.out_of_bounds_check(address, data.len()) {
            return Err(BusError::OutOfBounds);
        }

        let offset: usize = (address as usize) - (self.start_address as usize);
        data.copy_from_slice(&self.buffer[offset..offset + data.len()]);

        Ok(())
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        if !self.address_is_managed(address) {
            return Err(BusError::InvalidAddress(address));
        }

        if self.out_of_bounds_check(address, data.len()) {
            return Err(BusError::OutOfBounds);
        }

        let mut offset: usize = (address as usize) - (self.start_address as usize);
        for byte in data {
            self.buffer[offset] = *byte;
            offset += 1;
        }

        Ok(())
    }
}

impl BusClient for MemoryRegionMirror {
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        let offset_to_original_region_address: i32 =
            (self.original_region.borrow().start_address as i32) - (self.start_address as i32);
        let address_into_original_region = address as i32 + offset_to_original_region_address;
        self.original_region
            .borrow()
            .read(address_into_original_region as u32, data)
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        let offset_to_original_region_address: i32 =
            (self.original_region.borrow().start_address as i32) - (self.start_address as i32);
        let address_into_original_region = address as i32 + offset_to_original_region_address;
        self.original_region
            .borrow_mut()
            .write(address_into_original_region as u32, data)
    }
}

impl Machine {
    pub fn from_config(config: &MachineConfig) -> Machine {
        let mut machine = Self {
            memory_regions: Vec::new(),
            mirrored_regions: Vec::new(),
            bus_handler: BusForwarder::new(),
        };

        for area in config.memory_areas.iter() {
            let region = Rc::new(RefCell::new(MemoryRegion::create(
                area.address,
                area.size,
                &area.name,
            )));

            if let Some(mirror_address) = area.mirror_address {
                machine
                    .mirrored_regions
                    .push(Rc::new(RefCell::new(MemoryRegionMirror {
                        start_address: mirror_address,
                        original_region: region.clone(),
                    })));
            }
            machine.memory_regions.push(region);
        }

        machine
    }

    pub fn start(&mut self) {
        for region in self.memory_regions.iter() {
            self.bus_handler.register_device(region.clone());
        }
        for mirrored_region in self.mirrored_regions.iter() {
            self.bus_handler.register_device(mirrored_region.clone());
        }
    }
}
#[cfg(test)]
mod tests {
    use std::{cell::RefCell, rc::Rc};

    use crate::{
        bus::BusClient,
        config::{MachineConfig, MemoryDetails},
    };

    use super::{Machine, MemoryRegion, MemoryRegionMirror};

    #[test]
    fn test_memory_region() {
        const START_ADDRESS: u32 = 0xA0000000u32;
        let mut region = MemoryRegion::create(START_ADDRESS, 32, "pflash");

        assert_eq!(region.name, "pflash");
        assert_eq!(region.buffer.len(), 32);
        assert_eq!(region.start_address, START_ADDRESS);
        assert!(region.buffer.iter().all(|&b| b == 0));

        let offset_into_region = 16u32;
        let data = [98u8, 76u8, 54u8, 32u8];
        let write_result = region.write(START_ADDRESS + offset_into_region, &data);
        assert!(write_result.is_ok());

        let mut received = [0u8; 4];
        let read_result = region.read(START_ADDRESS + offset_into_region, &mut received);
        assert!(read_result.is_ok());
        assert_eq!(received[0], 98u8);
        assert_eq!(received[1], 76u8);
        assert_eq!(received[2], 54u8);
        assert_eq!(received[3], 32u8);
    }

    #[test]
    fn test_machine_creation() {
        let config = MachineConfig {
            num_of_cpus: 1,
            memory_areas: vec![
                MemoryDetails {
                    name: String::from("ram"),
                    size: 12345678,
                    address: 0xDEADBEEFu32,
                    mirror_address: Some(0xDADADADAu32),
                },
                MemoryDetails {
                    name: String::from("rom"),
                    size: 987654,
                    address: 0x10000000u32,
                    mirror_address: None,
                },
            ],
        };

        let machine = Machine::from_config(&config);
        assert_eq!(machine.memory_regions.len(), 2);
        assert_eq!(machine.memory_regions[0].borrow().name, "ram");
        assert_eq!(
            machine.memory_regions[0].borrow().start_address,
            0xDEADBEEFu32
        );
        assert_eq!(machine.memory_regions[0].borrow().buffer.len(), 12345678);
        assert!(machine.memory_regions[0]
            .borrow()
            .buffer
            .iter()
            .all(|&b| b == 0));
        assert_eq!(machine.memory_regions[1].borrow().name, "rom");
        assert_eq!(
            machine.memory_regions[1].borrow().start_address,
            0x10000000u32
        );
        assert_eq!(machine.memory_regions[1].borrow().buffer.len(), 987654);
        assert!(machine.memory_regions[1]
            .borrow()
            .buffer
            .iter()
            .all(|&b| b == 0));

        assert_eq!(machine.mirrored_regions.len(), 1);
        assert_eq!(
            machine.mirrored_regions[0].borrow().start_address,
            0xDADADADAu32
        );
    }

    #[test]
    fn test_memory_region_alias() {
        let region = Rc::new(RefCell::new(MemoryRegion::create(
            0xD0000000u32,
            64,
            "flash",
        )));

        let mut mirror = MemoryRegionMirror {
            start_address: 0,
            original_region: region.clone(),
        };

        let sent: Vec<u8> = (0u8..32u8).collect();
        let write_result = mirror.write(4, &sent);
        assert!(write_result.is_ok());

        let mut received = [0u8; 32];
        let read_result = region.borrow().read(0xD0000004, &mut received);
        assert!(read_result.is_ok());
        assert!(sent.iter().zip(received.iter()).all(|(&l, &r)| l == r));

        // ensure that reading out of bounds triggers error from both mirrored region and original
        assert!(mirror.read(128, &mut received).is_err());
        assert!(mirror.read(48, &mut received).is_err());
        assert!(mirror.read(0xD0000000, &mut received).is_err());
        assert!(region.borrow().read(0xD0000030, &mut received).is_err());
        assert!(region.borrow().read(0xCFFFFFFF, &mut received).is_err());
        assert!(region.borrow().read(0xD0000021, &mut received).is_err());
        assert!(region.borrow().read(0xD0000020, &mut received).is_ok());
    }
}
