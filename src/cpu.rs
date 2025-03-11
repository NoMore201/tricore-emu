use std::{cell::RefCell, rc::Rc};

use crate::{
    bit_utils::BitManipulation,
    bus::{BusClient, BusForwarder},
};

const OPCODE_MOVHA: u8 = 0x91u8;

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

    pub fn start(&mut self) {
        loop {
            let opcode = self.read8();
            self.decode(opcode);
        }
    }

    fn read32(&self) -> u32 {
        let mut bytes = [0u8; 4];
        if let Err(error) = self.bus_handler.borrow().read(self.pc, &mut bytes) {
            println!(
                "Cannot fetch instruction from address 0x{:08X}, {}",
                self.pc, error
            );
            std::process::exit(1);
        }
        u32::from_le_bytes(bytes)
    }

    fn read8(&self) -> u8 {
        let mut bytes = [0u8; 1];
        if let Err(error) = self.bus_handler.borrow().read(self.pc, &mut bytes) {
            println!(
                "Cannot fetch instruction from address 0x{:08X}, {}",
                self.pc, error
            );
            std::process::exit(1);
        }
        bytes[0]
    }

    fn decode(&mut self, opcode: u8) {
        match opcode {
            OPCODE_MOVHA => self.insn_movha(),
            _ => {
                println!("Instruction with opcode 0x{:02X} not implemented", opcode);
                std::process::exit(1);
            }
        }
    }

    fn insn_movha(&mut self) {
        let insn = self.read32();
        let c = insn.extract(28, 4) as usize;
        let const16 = insn.extract(12, 16);
        self.address_regs[c] = const16;
        tracing::trace!("Decode MOVH.A [{:08X}] A[{}]={:08X}", insn, c, const16);
        self.pc += 4;
    }
}
