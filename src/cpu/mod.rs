mod opcodes;

use std::{cell::RefCell, rc::Rc};

use crate::bus::BusInterface;
use crate::bus::BusProxy;

struct Registers {
    pub data: [u32; 16],
    pub address: [u32; 16],
    pub pcxi: u32,
    pub psw: u32,
    pub pc: u32,
    pub syscon: u32,
    pub cpu_id: u32,
    pub core_id: u32,
    pub biv: u32,
    pub btv: u32,
    pub isp: u32,
    pub icr: u32,
    pub fcx: u32,
    pub lcx: u32,
}

pub struct CpuState {
    memory_proxy: Rc<RefCell<BusProxy>>,
    registers: Registers,
}

impl CpuState {
    pub fn create(bus_proxy: Rc<RefCell<BusProxy>>) -> Self {
        Self {
            memory_proxy: bus_proxy,
            registers: Registers {
                data: [0; 16],
                address: [0; 16],
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
            },
        }
    }

    pub fn set_program_counter(&mut self, address: u32) {
        self.registers.pc = address
    }

    pub fn start(&mut self) {
        loop {
            let opcode = self.memory_proxy.borrow().read8(self.registers.pc);
            match opcode {
                Ok(byte) => {
                    if let Err(error) = opcodes::decode(self, byte) {
                        tracing::error!("Instruction decoding error: {}", error);
                        std::process::exit(1);
                    }
                },
                Err(error) => {
                    tracing::error!("Cannot fetch byte from PC address: {}", error);
                    std::process::exit(1);
                }
            }
        }
    }

    fn get_core_register_by_offset(&mut self, offset: u16) -> &mut u32 {
        match offset {
            0xFE04u16 => &mut self.registers.psw,
            _ => {
                tracing::error!(
                    "Mapping to core register at offset 0x{:04X} not implemented",
                    offset
                );
                std::process::exit(1);
            }
        }
    }
}
