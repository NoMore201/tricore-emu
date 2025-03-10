use std::cell::RefCell;
use std::rc::Rc;

pub enum BusError {
    InvalidAddress(u32),
    OutOfBounds,
}

pub trait BusClient {
    /// Read bytes at provided address. Number of bytes to read is equal to
    /// data length
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError>;

    /// Write data at provided address. Number of bytes to read is equal to
    /// data length
    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError>;

    fn address_is_managed(&self, address: u32) -> bool;
}

/// Collect devices connected to the bus and forward read/write
/// request to all devices listening
pub struct BusForwarder {
    registered_devices: Vec<Rc<RefCell<dyn BusClient>>>,
}

impl BusForwarder {
    pub fn new() -> Self {
        BusForwarder {
            registered_devices: Vec::new(),
        }
    }

    pub fn register_device(&mut self, device: Rc<RefCell<dyn BusClient>>) {
        self.registered_devices.push(device)
    }
}

impl BusClient for BusForwarder {
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

#[cfg(test)]
mod tests {
    use super::{BusClient, BusError, BusForwarder};
    use std::cell::RefCell;
    use std::rc::Rc;

    struct SampleClient {}

    impl BusClient for SampleClient {
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
        let mut handler = BusForwarder::new();
        let sample_client1 = Rc::new(RefCell::new(SampleClient {}));
        let sample_client2 = Rc::new(RefCell::new(SampleClient {}));
        handler.register_device(sample_client1);
        handler.register_device(sample_client2);
        assert_eq!(handler.registered_devices.len(), 2);
    }
}
