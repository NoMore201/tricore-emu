use std::cell::RefCell;
use std::error::Error;
use std::fmt;
use std::rc::Rc;

#[derive(Debug)]
pub enum BusError {
    InvalidAddress(u32),
    OutOfBounds,
}

pub trait BusInterface {
    /// Read bytes at provided address. Number of bytes to read is equal to
    /// data length
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError>;

    /// Write data at provided address. Number of bytes to read is equal to
    /// data length
    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError>;

    fn read32(&self, address: u32) -> Result<u32, BusError> {
        let mut bytes = [0u8; 4];
        self.read(address, &mut bytes)?;
        Ok(u32::from_le_bytes(bytes))
    }

    fn read16(&self, address: u32) -> Result<u16, BusError> {
        let mut bytes = [0u8; 2];
        self.read(address, &mut bytes)?;
        Ok(u16::from_le_bytes(bytes))
    }

    fn read8(&self, address: u32) -> Result<u8, BusError> {
        let mut bytes = [0u8; 1];
        self.read(address, &mut bytes)?;
        Ok(bytes[0])
    }

    fn write32(&mut self, address: u32, value: u32) -> Result<(), BusError> {
        let slice = value.to_le_bytes();
        self.write(address, &slice)
    }

    fn address_is_managed(&self, address: u32) -> bool;
}

/// Collect devices connected to the bus and forward read/write
/// request to all devices listening
pub struct BusProxy {
    registered_devices: Vec<Rc<RefCell<dyn BusInterface>>>,
}

impl BusProxy {
    pub fn new() -> Self {
        BusProxy {
            registered_devices: Vec::new(),
        }
    }

    pub fn register_device(&mut self, device: Rc<RefCell<dyn BusInterface>>) {
        self.registered_devices.push(device)
    }
}

impl BusInterface for BusProxy {
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        for dev in self.registered_devices.iter() {
            let result = dev.borrow().read(address, data);
            if result.is_err() {
                continue;
            }
            return result;
        }

        Err(BusError::InvalidAddress(address))
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        for dev in self.registered_devices.iter() {
            let result = dev.borrow_mut().write(address, data);
            if result.is_err() {
                continue;
            }
            return result;
        }

        Err(BusError::InvalidAddress(address))
    }

    fn address_is_managed(&self, address: u32) -> bool {
        self.registered_devices
            .iter()
            .any(|bc| bc.borrow().address_is_managed(address))
    }
}

impl fmt::Display for BusError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match *self {
            BusError::InvalidAddress(addr) => write!(f, "Address 0x{:08X} not handled", addr),
            BusError::OutOfBounds => write!(f, "Memory write out of bounds"),
        }
    }
}

impl Error for BusError {}

#[cfg(test)]
mod tests {
    use super::{BusError, BusInterface, BusProxy};
    use std::cell::RefCell;
    use std::rc::Rc;

    struct SampleClient {}

    impl BusInterface for SampleClient {
        fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
            Ok(())
        }

        fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
            Ok(())
        }

        fn address_is_managed(&self, address: u32) -> bool {
            true
        }
    }

    #[test]
    fn test_bus_handler() {
        let mut handler = BusProxy::new();
        let sample_client1 = Rc::new(RefCell::new(SampleClient {}));
        let sample_client2 = Rc::new(RefCell::new(SampleClient {}));
        handler.register_device(sample_client1);
        handler.register_device(sample_client2);
        assert_eq!(handler.registered_devices.len(), 2);
    }
}
