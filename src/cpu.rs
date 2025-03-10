use std::{cell::RefCell, rc::Rc};

use crate::bus::{BusClient, BusError, BusForwarder};

pub struct TricoreCpu {
    bus_handler: Rc<RefCell<BusForwarder>>,

    data_regs: [u32; 16],
    address_regs: [u32; 16],
    pcxi: u32,
    psw: u32,
    pc: u32,
    syscon: u32,
    cpu_id: u32,
    core_id: u32,
    biv: u32,
    btv: u32,
    isp: u32,
    icr: u32,
    fcx: u32,
    lcx: u32,
}

impl TricoreCpu {
    pub fn create(bus_handler: Rc<RefCell<BusForwarder>>) -> Self {
        Self {
            bus_handler: bus_handler.clone(),
            data_regs: [0; 16],
            address_regs: [0; 16],
            pcxi: 0,
            psw: 0,
            pc: 0,
            syscon: 0,
            cpu_id: 0,
            core_id: 0,
            biv: 0,
            btv: 0,
            isp: 0,
            icr: 0,
            fcx: 0,
            lcx: 0,
        }
    }

    pub fn set_program_counter(&mut self, address: u32) {
        self.pc = address
    }

    pub fn start(&self) {
        loop {
            let mut opcode = [0u8];
            if let Err(error) = self.bus_handler.borrow().read(self.pc, &mut opcode) {
                match error {
                    BusError::InvalidAddress(addr) => {
                        println!("Address 0x{:08X} not handled by current machine configuration", addr);
                        std::process::exit(1);
                    },
                    BusError::OutOfBounds => {
                        panic!("Attempting to read outside bounds")
                    }
                }
            }
        }
        
    }
}
