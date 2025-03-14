use std::{cell::RefCell, rc::Rc};

use crate::{
    bus::{BusClient, BusForwarder},
    utils::{sign_extend, BitManipulation},
};

const OPCODE_MOVHA: u8 = 0x91u8;
const OPCODE_LEA_BOL: u8 = 0xD9u8;
const OPCODE_JI_SR: u8 = 0xDCu8;
const OPCODE_MOV_RLC: u8 = 0x3Bu8;

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

    fn read_or_panic(&self, buffer: &mut [u8]) {
        if let Err(error) = self.bus_handler.borrow().read(self.pc, buffer) {
            println!(
                "Cannot fetch instruction from address 0x{:08X}, {}",
                self.pc, error
            );
            std::process::exit(1);
        }
    }

    fn read32(&self) -> u32 {
        let mut bytes = [0u8; 4];
        self.read_or_panic(&mut bytes);
        u32::from_le_bytes(bytes)
    }

    fn read16(&self) -> u16 {
        let mut bytes = [0u8; 2];
        self.read_or_panic(&mut bytes);
        u16::from_le_bytes(bytes)
    }

    fn read8(&self) -> u8 {
        let mut bytes = [0u8; 1];
        self.read_or_panic(&mut bytes);
        bytes[0]
    }

    fn decode(&mut self, opcode: u8) {
        match opcode {
            OPCODE_MOVHA => self.insn_movha(),
            OPCODE_LEA_BOL => self.insn_lea_bol(),
            OPCODE_JI_SR => self.insn_ji_sr(),
            OPCODE_MOV_RLC => self.insn_mov_rlc(),
            _ => {
                tracing::error!("Instruction with opcode 0x{:02X} not implemented", opcode);
                std::process::exit(1);
            }
        }
    }

    fn insn_movha(&mut self) {
        let insn = self.read32();
        rlc_parser(insn, |_, c, const16| {
            self.address_regs[c] = const16 << 16;
            tracing::trace!(
                "Decode MOVH.A [{:08X}] A[{}]={:08X}",
                insn,
                c,
                self.address_regs[c]
            );
            self.pc += 4;
        });
    }

    fn insn_lea_bol(&mut self) {
        let insn = self.read32();
        bol_parser(insn, |a, b, off16| {
            let ea = self.address_regs[b].wrapping_add(sign_extend(off16 as i32, 16) as u32);
            self.address_regs[a] = ea;
            tracing::trace!("Decode LEA [{:08X}] A[{}]={:08X}", insn, a, ea);
            self.pc += 4;
        });
    }

    fn insn_ji_sr(&mut self) {
        let insn = self.read16();
        sr_parser(insn, |a, _| {
            self.pc = self.address_regs[a] & !1u32;
            tracing::trace!("Decode JI [{:04X}] PC=A[{}]={:08X}", insn, a, self.pc);
        });
    }

    fn insn_mov_rlc(&mut self) {
        let insn = self.read32();
        rlc_parser(insn, |_, c, off16| {
            let sign_extended_const16 = sign_extend(off16 as i32, 16) as u32;
            self.data_regs[c] = sign_extended_const16;
            tracing::trace!(
                "Decode MOV [{:08X}] D[{}]={:08X}",
                insn,
                c,
                sign_extended_const16
            );
            self.pc += 4;
        });
    }
}

fn rlc_parser<F>(insn: u32, mut callback: F)
where
    F: FnMut(usize, usize, u32),
{
    let a = insn.extract(8, 4) as usize;
    let c = insn.extract(28, 4) as usize;
    let const16 = insn.extract(12, 16);
    callback(a, c, const16);
}

fn bol_parser<F>(insn: u32, mut callback: F)
where
    F: FnMut(usize, usize, u32),
{
    let a = insn.extract(8, 4) as usize;
    let b = insn.extract(12, 4) as usize;
    let off16 = insn.extract(16, 6) | (insn.extract(28, 4) << 6) | (insn.extract(22, 6) << 10);
    callback(a, b, off16);
}

fn sr_parser<F>(insn: u16, mut callback: F)
where
    F: FnMut(usize, usize),
{
    let a = insn.extract(8, 4) as usize;
    let b = insn.extract(12, 4) as usize;
    callback(a, b);
}
