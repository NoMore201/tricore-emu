use std::{cell::RefCell, cmp::Ordering, rc::Rc};

use crate::bus::{BusError, BusInterface};

pub struct MemoryRegion {
    pub name: String,
    pub start_address: u32,
    pub buffer: Vec<u8>,
}

pub struct MemoryRegionMirror {
    pub start_address: u32,
    pub original_region: Rc<RefCell<MemoryRegion>>,
}

impl MemoryRegion {
    pub fn create(start_address: u32, size: usize, name: &str) -> Self {
        MemoryRegion {
            name: String::from(name),
            start_address,
            buffer: vec![0; size],
        }
    }

    fn out_of_bounds_check(&self, address: u32, length: usize) -> bool {
        address as usize + length > self.start_address as usize + self.buffer.len()
    }
}

impl MemoryRegionMirror {
    pub fn create(start_address: u32, orig_region: Rc<RefCell<MemoryRegion>>) -> MemoryRegionMirror {
        MemoryRegionMirror { start_address, original_region: orig_region } 
    }
}

impl BusInterface for MemoryRegion {
    fn address_is_managed(&self, address: u32) -> bool {
        address >= self.start_address && address < self.start_address + (self.buffer.len() as u32)
    }

    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        if !self.address_is_managed(address) {
            return Err(BusError::InvalidAddress(address));
        }

        if self.out_of_bounds_check(address, data.len()) {
            return Err(BusError::OutOfBounds);
        }

        tracing::trace!("Reading from memory region {} at address 0x{:08X}", self.name, address);
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

        tracing::trace!("Writing to memory region {} at address 0x{:08X}", self.name, address);
        let mut offset: usize = (address as usize) - (self.start_address as usize);
        for byte in data {
            self.buffer[offset] = *byte;
            offset += 1;
        }

        Ok(())
    }
}

impl BusInterface for MemoryRegionMirror {
    fn address_is_managed(&self, address: u32) -> bool {
        address >= self.start_address
            && address < self.start_address + (self.original_region.borrow().buffer.len() as u32)
    }

    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        if !self.address_is_managed(address) {
            return Err(BusError::InvalidAddress(address));
        }

        let original_start_address = self.original_region.borrow().start_address;

        match original_start_address.cmp(&self.start_address) {
            Ordering::Greater => {
                let diff = original_start_address - self.start_address;
                let mapped_address = address + diff;
                self.original_region.borrow().read(mapped_address, data)
            }
            Ordering::Equal | Ordering::Less => {
                let diff = self.start_address - original_start_address;
                let mapped_address = address - diff;
                self.original_region.borrow().read(mapped_address, data)
            }
        }
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        if !self.address_is_managed(address) {
            return Err(BusError::InvalidAddress(address));
        }

        let original_start_address = self.original_region.borrow().start_address;

        match original_start_address.cmp(&self.start_address) {
            Ordering::Greater => {
                let diff = original_start_address - self.start_address;
                let mapped_address = address + diff;
                self.original_region
                    .borrow_mut()
                    .write(mapped_address, data)
            }
            Ordering::Equal | Ordering::Less => {
                let diff = self.start_address - original_start_address;
                let mapped_address = address - diff;
                self.original_region
                    .borrow_mut()
                    .write(mapped_address, data)
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use std::{cell::RefCell, rc::Rc};

    use crate::{
        bus::BusInterface,
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