use crate::bus::{BusClient, BusError};

pub struct Peripherals {}

impl Peripherals {
    pub fn new() -> Self {
        Peripherals {}
    }
}

impl BusClient for Peripherals {
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        tracing::warn!(
            "Accessing peripheral address 0x{:08X}, not yet implemented",
            address
        );
        Ok(())
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        tracing::warn!(
            "Accessing peripheral address 0x{:08X}, not yet implemented",
            address
        );
        Ok(())
    }

    fn address_is_managed(&self, address: u32) -> bool {
        address >= 0xF0000000u32
    }
}
