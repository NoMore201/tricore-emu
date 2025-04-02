use std::{cell::RefCell, rc::Rc};

use crate::{
    bus::{BusError, BusInterface},
    memory::MemoryRegion,
    utils::KiB,
};

const SCU_START_ADDRESS: u32 = 0xF0036000;
const SCU_SIZE: usize = 1 * KiB;

const RSTSTAT_ADDRESS: u32 = 0xF0036050;

/// Reset vaule:
/// - PORST (bit [16]) set to 1
/// - LBTERM (bit [30]) set to 1 to simulate correct LBIST procedure
const RSTSTAT_RESET_VALUE: u32 = 0x40010000;

pub struct Scu {
    memory_region: MemoryRegion,
}

impl Scu {
    pub fn create_rc() -> Rc<RefCell<Scu>> {
        let instance = Rc::new(RefCell::new(Scu {
            memory_region: MemoryRegion::create(SCU_START_ADDRESS, SCU_SIZE, "SCU"),
        }));
        let result = instance.borrow_mut().init();
        match result {
            Ok(_) => instance,
            Err(err) => {
                tracing::error!("Unable to initialize SCU peripheral: {}", err);
                std::process::exit(1);
            }
        }
    }

    fn init(&mut self) -> Result<(), BusError> {
        self.write32(RSTSTAT_ADDRESS, RSTSTAT_RESET_VALUE)
    }
}

impl BusInterface for Scu {
    fn read(&mut self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        self.memory_region.read(address, data).and_then(|_| {
            on_successfull_read(&mut self.memory_region, address);
            Ok(())
        })
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        self.memory_region.write(address, data).and_then(|_| {
            on_successfull_write(&mut self.memory_region, address);
            Ok(())
        })
    }

    fn address_is_managed(&self, address: u32) -> bool {
        self.memory_region.address_is_managed(address)
    }
}

fn on_successfull_read(mem: &mut MemoryRegion, address: u32) {
    match address {
        RSTSTAT_ADDRESS => tracing::debug!("SCU: read access to RSTSTAT"),
        _ => {
            tracing::warn!("SCU: register at address 0x{:08X} not handled", address);
        }
    }
}

fn on_successfull_write(mem: &mut MemoryRegion, address: u32) {
    match address {
        RSTSTAT_ADDRESS => tracing::debug!("SCU: write access to RSTSTAT"),
        _ => {
            tracing::warn!("SCU: register at address 0x{:08X} not handled", address);
        }
    }
}
