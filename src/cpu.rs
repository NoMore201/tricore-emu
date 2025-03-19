use std::{cell::RefCell, rc::Rc};

use crate::{
    bus::{BusClient, BusForwarder},
    utils::{sign_extend, BitManipulation},
};

const OPCODE_ADD_SRC: u8 = 0xC2;
const OPCODE_JI_SR: u8 = 0xDC;
const OPCODE_LEA_BOL: u8 = 0xD9;
const OPCODE_LDW_BOL: u8 = 0x19;
const OPCODE_LDW_SLR: u8 = 0x54;
const OPCODE_MOV_RLC: u8 = 0x3B;
const OPCODE_MOVHA: u8 = 0x91;
const OPCODE_MTCR: u8 = 0xCD;
const OPCODE_0DH: u8 = 0x0D;

struct MemoryProxy {
    bus_handler: Rc<RefCell<BusForwarder>>,
}

pub struct TricoreCpu {
    mem_proxy: MemoryProxy,
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
            mem_proxy: MemoryProxy {
                bus_handler: bus_handler.clone(),
            },
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
            let opcode = self.mem_proxy.read8(self.pc);
            self.decode(opcode);
        }
    }

    fn get_core_register_by_offset(&mut self, offset: u16) -> &mut u32 {
        match offset {
            0xFE04u16 => &mut self.psw,
            _ => {
                tracing::error!(
                    "Mapping to core register at offset 0x{:04X} not implemented",
                    offset
                );
                std::process::exit(1);
            }
        }
    }

    fn decode(&mut self, opcode: u8) {
        match opcode {
            OPCODE_MOVHA => self.insn_movha(),
            OPCODE_LEA_BOL => self.insn_lea_bol(),
            OPCODE_JI_SR => self.insn_ji_sr(),
            OPCODE_MOV_RLC => self.insn_mov_rlc(),
            OPCODE_MTCR => self.insn_mtcr(),
            OPCODE_LDW_BOL => self.insn_ldw_bol(),
            OPCODE_0DH => self.parse_0dh_opcodes(),
            OPCODE_LDW_SLR => self.insn_ldw_slr(),
            OPCODE_ADD_SRC => self.insn_add_src(),
            _ => {
                tracing::error!("Instruction with opcode 0x{:02X} not implemented", opcode);
                std::process::exit(1);
            }
        }
    }

    fn parse_0dh_opcodes(&mut self) {
        let insn = self.mem_proxy.read32(self.pc);
        let id = insn.extract(22, 6);

        match id {
            0x12 => self.insn_dsync(),
            0x13 => self.insn_isync(),
            _ => {
                tracing::error!(
                    "Instruction with opcode 0x0D and identifier 0x{:02X} not implemented",
                    id
                );
                std::process::exit(1);
            }
        }

        self.pc += 4;
    }

    fn insn_dsync(&self) {
        tracing::trace!("Decode DSYNC");
    }

    fn insn_isync(&self) {
        tracing::trace!("Decode ISYNC");
    }

    fn insn_movha(&mut self) {
        let insn = self.mem_proxy.read32(self.pc);
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
        let insn = self.mem_proxy.read32(self.pc);
        bol_parser(insn, |a, b, off16| {
            let ea = self.address_regs[b].wrapping_add(sign_extend(off16 as i32, 16) as u32);
            self.address_regs[a] = ea;
            tracing::trace!("Decode LEA [{:08X}] A[{}]={:08X}", insn, a, ea);
            self.pc += 4;
        });
    }

    fn insn_ji_sr(&mut self) {
        let insn = self.mem_proxy.read16(self.pc);
        sr_parser(insn, |a, _| {
            self.pc = self.address_regs[a] & !1u32;
            tracing::trace!("Decode JI [{:04X}] PC=A[{}]={:08X}", insn, a, self.pc);
        });
    }

    fn insn_mov_rlc(&mut self) {
        let insn = self.mem_proxy.read32(self.pc);
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

    fn insn_mtcr(&mut self) {
        let insn = self.mem_proxy.read32(self.pc);
        rlc_parser(insn, |a, _, off16| {
            let value = self.data_regs[a];
            let cr = self.get_core_register_by_offset(off16 as u16);
            *cr = value;
            tracing::trace!(
                "Decode MTCR [{:08X}] CR[0x{:04X}]=D[{}]={:08X}",
                insn,
                off16,
                a,
                value
            );
            self.pc += 4;
        });
    }

    fn insn_ldw_bol(&mut self) {
        let insn = self.mem_proxy.read32(self.pc);
        bol_parser(insn, |a, b, off16| {
            let sign_extended_off16 = sign_extend(off16 as i32, 16) as u32;
            let ea = self.address_regs[b].wrapping_add(sign_extended_off16);
            self.data_regs[a] = self.mem_proxy.read32(ea);
            tracing::trace!(
                "Decode LD.W [{:08X}] D[{}]={:08X}",
                insn,
                a,
                self.data_regs[a]
            );
            self.pc += 4;
        });
    }

    fn insn_ldw_slr(&mut self) {
        let insn = self.mem_proxy.read16(self.pc);
        slr_parser(insn, |c, b| {
            self.data_regs[c] = self.mem_proxy.read32(self.address_regs[b]);
            tracing::trace!(
                "Decode LD.W [{:04X}] D[{}]={:08X}",
                insn,
                c,
                self.data_regs[c]
            );
            self.pc += 2;
        });
    }

    fn insn_add_src(&mut self) {
        let insn = self.mem_proxy.read16(self.pc);
        src_parser(insn, |a, const4| {
            let result = self.data_regs[a] + sign_extend(const4 as i32, 4) as u32;
            self.data_regs[a] = result;
            tracing::trace!(
                "Decode ADD [{:04X}] D[{}]={:08X}",
                insn,
                a,
                self.data_regs[a]
            );
            self.pc += 2;
        });
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

fn slr_parser<F>(insn: u16, mut callback: F)
where
    F: FnMut(usize, usize),
{
    sr_parser(insn, callback);
}

fn src_parser<F>(insn: u16, mut callback: F)
where
    F: FnMut(usize, usize),
{
    sr_parser(insn, callback);
}
