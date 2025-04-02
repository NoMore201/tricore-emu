mod xram;

use std::{cell::RefCell, rc::Rc};

use crate::bus::{BusError, BusInterface, BusProxy};

pub struct PeripheralHandler {
    proxy: BusProxy,
}

impl PeripheralHandler {
    pub fn new() -> Self {
        let mut proxy = BusProxy::new();
        proxy.register_device(Rc::new(RefCell::new(xram::Xram::new())));
        PeripheralHandler { proxy }
    }
}

impl BusInterface for PeripheralHandler {
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        self.proxy.read(address, data)
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        self.proxy.write(address, data)
    }

    fn address_is_managed(&self, address: u32) -> bool {
        self.proxy.address_is_managed(address)
    }
}
