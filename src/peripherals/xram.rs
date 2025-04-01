use crate::utils::KiB;

use crate::bus::{BusError, BusInterface};
use crate::memory::MemoryRegion;

const START_ADDRESS: u32 = 0xF0240000;
const SIZE: usize = 8 * KiB;

pub struct Xram {
    memory_region: MemoryRegion,
}

impl Xram {
    pub fn new() -> Xram {
        Xram {
            memory_region: MemoryRegion::create(START_ADDRESS, SIZE, "XRAM"),
        }
    }
}

impl BusInterface for Xram {
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        self.memory_region.read(address, data)
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        self.memory_region.write(address, data)
    }

    fn address_is_managed(&self, address: u32) -> bool {
        self.memory_region.address_is_managed(address)
    }
}
