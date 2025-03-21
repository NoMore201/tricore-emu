mod opcodes;
mod utils;

use std::{cell::RefCell, rc::Rc};

use crate::
    bus::{BusClient, BusForwarder}
;

struct MemoryProxy {
    bus_handler: Rc<RefCell<BusForwarder>>,
}

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
    pub lcx: u32
}

pub struct CpuState {
    mem_proxy: MemoryProxy,
    registers: Registers
}

impl CpuState {
    pub fn create(bus_handler: Rc<RefCell<BusForwarder>>) -> Self {
        Self {
            mem_proxy: MemoryProxy {
                bus_handler: bus_handler.clone(),
            },
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
            }
        }
    }

    pub fn set_program_counter(&mut self, address: u32) {
        self.registers.pc = address
    }

    pub fn start(&mut self) {
        loop {
            let opcode = self.mem_proxy.read8(self.registers.pc);
            opcodes::decode(self, opcode);
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

impl MemoryProxy {
    fn read_or_panic(&self, address: u32, buffer: &mut [u8]) {
        if let Err(error) = self.bus_handler.borrow().read(address, buffer) {
            println!(
                "Cannot fetch data from address 0x{:08X}, {}",
                address, error
            );
            std::process::exit(1);
        }
    }

    fn write_or_panic(&self, address: u32, buffer: &[u8]) {
        if let Err(error) = self.bus_handler.borrow_mut().write(address, buffer) {
            println!("Cannot write data to address 0x{:08X}, {}", address, error);
            std::process::exit(1);
        }
    }

    fn read32(&self, address: u32) -> u32 {
        let mut bytes = [0u8; 4];
        self.read_or_panic(address, &mut bytes);
        u32::from_le_bytes(bytes)
    }

    fn read16(&self, address: u32) -> u16 {
        let mut bytes = [0u8; 2];
        self.read_or_panic(address, &mut bytes);
        u16::from_le_bytes(bytes)
    }

    fn read8(&self, address: u32) -> u8 {
        let mut bytes = [0u8; 1];
        self.read_or_panic(address, &mut bytes);
        bytes[0]
    }

    fn write32(&self, address: u32, value: u32) {
        let slice = value.to_le_bytes();
        self.write_or_panic(address, &slice);
    }
}
