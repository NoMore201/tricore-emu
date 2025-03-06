use std::rc::Rc;
use std::cell::RefCell;

pub enum BusError {
    InvalidAddress(u32),
}

pub trait BusClient {
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError>;

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError>;

    /// returns true if this bus client handles the provided address. Returns
    /// false otherwise
    fn address_is_managed(&self, address: u32) -> bool;
}

pub struct BusHandler {
    registered_devices: Vec<Rc<RefCell<dyn BusClient>>>,
}

impl BusHandler {
    pub fn new() -> Self {
        BusHandler {
            registered_devices: Vec::new(),
        }
    }

    pub fn register_device(&mut self, device: Rc<RefCell<dyn BusClient>>) {
        self.registered_devices.push(device)
    }
}

impl BusClient for BusHandler {
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        for dev in self.registered_devices.iter() {
            if self.address_is_managed(address) {
                return dev.borrow().read(address, data);
            }
        }

        Err(BusError::InvalidAddress(address))
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        for dev in self.registered_devices.iter() {
            if self.address_is_managed(address) {
                return dev.borrow_mut().write(address, data);
            }
        }

        Err(BusError::InvalidAddress(address))
    }

    fn address_is_managed(&self, address: u32) -> bool {
        self.registered_devices
            .iter()
            .any(|d| d.borrow().address_is_managed(address))
    }
}

#[cfg(test)]
mod tests {
    use super::{BusClient, BusHandler};
    use std::rc::Rc;
    use std::cell::RefCell;

    struct SampleClient {
        address: u32,
        buffer: Vec<u8>,
    }

    impl BusClient for SampleClient {
        fn read(&self, address: u32, data: &mut [u8]) -> Result<(), super::BusError> {
            Ok(())
        }

        fn write(&mut self, address: u32, data: &[u8]) -> Result<(), super::BusError> {
            self.address = address;
            self.buffer.extend_from_slice(data);
            Ok(())
        }

        fn address_is_managed(&self, address: u32) -> bool {
            true
        }
    }

    #[test]
    fn test_bus_handler() {
        let mut handler = BusHandler::new();
        let sample_client = Rc::new(RefCell::new(SampleClient {
            address: 1234,
            buffer: Vec::new(),
        }));
        handler.register_device(sample_client);
        assert_eq!(handler.registered_devices.len(), 1);
    }
}
