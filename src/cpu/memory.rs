use std::{cell::RefCell, rc::Rc};

use crate::bus::{BusError, BusInterface, BusProxy};

/// Perform accesses to memory through the virtual bus
pub struct MemoryProxy {
    bus_handler: Rc<RefCell<BusProxy>>,
}

impl MemoryProxy {

    pub fn new(bus_handler: Rc<RefCell<BusProxy>>) -> Self {
        Self { bus_handler }
    }

    pub fn read32(&self, address: u32) -> Result<u32, BusError> {
        let mut bytes = [0u8; 4];
        self.bus_handler.borrow().read(address, &mut bytes)?;
        Ok(u32::from_le_bytes(bytes))
    }

    pub fn read16(&self, address: u32) -> Result<u16, BusError> {
        let mut bytes = [0u8; 2];
        self.bus_handler.borrow().read(address, &mut bytes)?;
        Ok(u16::from_le_bytes(bytes))
    }

    pub fn read8(&self, address: u32) -> Result<u8, BusError> {
        let mut bytes = [0u8; 1];
        self.bus_handler.borrow().read(address, &mut bytes)?;
        Ok(bytes[0])
    }

    pub fn write32(&self, address: u32, value: u32) -> Result<(), BusError> {
        let slice = value.to_le_bytes();
        self.bus_handler.borrow_mut().write(address, &slice)
    }
}