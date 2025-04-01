mod xram;

use crate::bus::{BusError, BusInterface};

pub struct Peripherals {
    devices: Vec<Box<dyn BusInterface>>,
}

impl Peripherals {
    pub fn new() -> Self {
        Peripherals {
            devices: vec![Box::new(xram::Xram::new())],
        }
    }
}

impl BusInterface for Peripherals {
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        for device in &self.devices {
            let result = device.read(address, data);
            if result.is_err() {
                continue;
            }
            return Ok(());
        }

        Err(BusError::InvalidAddress(address))
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        for device in &mut self.devices {
            let result = device.write(address, data);
            if result.is_err() {
                continue;
            }
            return Ok(());
        }

        Err(BusError::InvalidAddress(address))
    }

    fn address_is_managed(&self, address: u32) -> bool {
        self.devices.iter().any(|d| d.address_is_managed(address))
    }
}
