use std::{cell::RefCell, rc::Rc};

use crate::{
    bus::{BusClient, BusError, BusForwarder},
    config::MachineConfig,
};

struct MemoryArea {
    name: String,
    start_address: u32,
    buffer: Vec<u8>,
}

struct MemoryRegionAlias {}

pub struct Machine {
    memory_regions: Vec<Rc<RefCell<MemoryArea>>>,
    bus_handler: BusForwarder,
}

impl MemoryArea {
    fn create(start_address: u32, size: usize, name: &str) -> Self {
        MemoryArea {
            name: String::from(name),
            start_address,
            buffer: vec![0; size],
        }
    }

    fn address_is_managed(&self, address: u32) -> bool {
        address < self.start_address || address >= self.start_address + (self.buffer.len() as u32)
    }
}

impl BusClient for MemoryArea {
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        if !self.address_is_managed(address) {
            return Err(BusError::InvalidAddress(address));
        }

        let offset: usize = (address as usize) - (self.start_address as usize);
        data.copy_from_slice(&self.buffer[offset..offset + data.len()]);

        Ok(())
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        if !self.address_is_managed(address) {
            return Err(BusError::InvalidAddress(address));
        }

        let offset: usize = (address as usize) - (self.start_address as usize);
        for byte in data {
            self.buffer[offset] = *byte;
        }

        Ok(())
    }
}

impl Machine {
    pub fn from_config(config: MachineConfig) -> Machine {
        let mut machine = Self {
            memory_regions: Vec::new(),
            bus_handler: BusForwarder::new(),
        };
        machine
            .memory_regions
            .push(Rc::new(RefCell::new(MemoryArea::create(
                0xA0000000u32,
                config.pflash_size,
                "pflash",
            ))));
        machine
            .memory_regions
            .push(Rc::new(RefCell::new(MemoryArea::create(
                0xAF000000u32,
                config.dflash0_size,
                "dflash0",
            ))));
        machine
            .memory_regions
            .push(Rc::new(RefCell::new(MemoryArea::create(
                0xAFC00000u32,
                config.dflash1_size,
                "dflash1",
            ))));
        machine
            .memory_regions
            .push(Rc::new(RefCell::new(MemoryArea::create(
                0x70100000u32,
                config.psram_size,
                "psram",
            ))));
        machine
            .memory_regions
            .push(Rc::new(RefCell::new(MemoryArea::create(
                0x70000000u32,
                config.dsram_size,
                "dsram",
            ))));

        machine
    }

    pub fn start(&mut self) {
        for region in self.memory_regions.iter() {
            self.bus_handler.register_device(region.clone());
        }
    }
}
