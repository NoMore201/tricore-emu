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

struct MemoryRegionAlias {}

pub struct Machine {
    memory_regions: Vec<Rc<RefCell<MemoryRegion>>>,
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
}

impl BusClient for MemoryRegion {
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        if !self.address_is_managed(address) {
            return Err(BusError::InvalidAddress(address));
        }

        let offset: usize = (address as usize) - (self.start_address as usize);
        data.copy_from_slice(&self.buffer[offset..offset + data.len()]);

        Ok(())
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        if !self.address_is_managed(address) {
            return Err(BusError::InvalidAddress(address));
        }

        let mut offset: usize = (address as usize) - (self.start_address as usize);
        for byte in data {
            self.buffer[offset] = *byte;
            offset += 1;
        }

        Ok(())
    }
}

impl Machine {
    pub fn from_config(config: &MachineConfig) -> Machine {
        let mut machine = Self {
            memory_regions: Vec::new(),
            bus_handler: BusForwarder::new(),
        };

        for area in config.memory_areas.iter() {
            machine
                .memory_regions
                .push(Rc::new(RefCell::new(MemoryRegion::create(
                    area.address,
                    area.size,
                    &area.name,
                ))));
        }

        machine
    }

    pub fn start(&mut self) {
        for region in self.memory_regions.iter() {
            self.bus_handler.register_device(region.clone());
        }
    }
}
#[cfg(test)]
mod tests {
    use crate::{
        bus::BusClient,
        config::{MachineConfig, MemoryDetails},
    };

    use super::{Machine, MemoryRegion};

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
    }
}
