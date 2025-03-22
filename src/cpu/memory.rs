use std::{cell::RefCell, rc::Rc};

use crate::bus::{BusInterface, BusProxy};

/// Perform accesses to memory through the virtual bus
pub struct MemoryProxy {
    bus_handler: Rc<RefCell<BusProxy>>,
}

impl MemoryProxy {

    pub fn new(bus_handler: Rc<RefCell<BusProxy>>) -> Self {
        Self { bus_handler }
    }

    pub fn read_or_panic(&self, address: u32, buffer: &mut [u8]) {
        if let Err(error) = self.bus_handler.borrow().read(address, buffer) {
            println!(
                "Cannot fetch data from address 0x{:08X}, {}",
                address, error
            );
            std::process::exit(1);
        }
    }

    pub fn write_or_panic(&self, address: u32, buffer: &[u8]) {
        if let Err(error) = self.bus_handler.borrow_mut().write(address, buffer) {
            println!("Cannot write data to address 0x{:08X}, {}", address, error);
            std::process::exit(1);
        }
    }

    pub fn read32(&self, address: u32) -> u32 {
        let mut bytes = [0u8; 4];
        self.read_or_panic(address, &mut bytes);
        u32::from_le_bytes(bytes)
    }

    pub fn read16(&self, address: u32) -> u16 {
        let mut bytes = [0u8; 2];
        self.read_or_panic(address, &mut bytes);
        u16::from_le_bytes(bytes)
    }

    pub fn read8(&self, address: u32) -> u8 {
        let mut bytes = [0u8; 1];
        self.read_or_panic(address, &mut bytes);
        bytes[0]
    }

    pub fn write32(&self, address: u32, value: u32) {
        let slice = value.to_le_bytes();
        self.write_or_panic(address, &slice);
    }
}