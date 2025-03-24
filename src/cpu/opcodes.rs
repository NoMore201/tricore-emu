use std::error::Error;
use std::fmt::Display;

use crate::cpu::utils::parser;
use crate::cpu::CpuState;
use crate::utils::{sign_extend, BitManipulation};

const OPCODE_ADD_SRC: u8 = 0xC2;
const OPCODE_JI_SR: u8 = 0xDC;
const OPCODE_LEA_BOL: u8 = 0xD9;
const OPCODE_LDW_BOL: u8 = 0x19;
const OPCODE_LDW_SLR: u8 = 0x54;
const OPCODE_MOV_RLC: u8 = 0x3B;
const OPCODE_MOVHA: u8 = 0x91;
const OPCODE_MOVH: u8 = 0x7B;
const OPCODE_MTCR: u8 = 0xCD;
const OPCODE_0DH: u8 = 0x0D;
const OPCODE_STW_BOL: u8 = 0x59;

pub type Result<T> = std::result::Result<T, Box<dyn std::error::Error>>;

#[derive(Debug)]
enum OpcodeError {
    InvalidOpcode(u8),
    InvalidVariant(u8, u8),
}

pub fn decode(cpu: &mut CpuState, opcode: u8) -> Result<()> {
    match opcode {
        OPCODE_MOVHA => insn_movha(cpu),
        OPCODE_MOVH => insn_movh(cpu),
        OPCODE_LEA_BOL => insn_lea_bol(cpu),
        OPCODE_JI_SR => insn_ji_sr(cpu),
        OPCODE_MOV_RLC => insn_mov_rlc(cpu),
        OPCODE_MTCR => insn_mtcr(cpu),
        OPCODE_LDW_BOL => insn_ldw_bol(cpu),
        OPCODE_STW_BOL => insn_stw_bol(cpu),
        OPCODE_0DH => parse_0dh_opcodes(cpu),
        OPCODE_LDW_SLR => insn_ldw_slr(cpu),
        OPCODE_ADD_SRC => insn_add_src(cpu),
        _ => Err(Box::new(OpcodeError::InvalidOpcode(opcode))),
    }
}

fn parse_0dh_opcodes(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc);
    match insn {
        Err(error) => Err(error.into()),
        Ok(word) => {
            let id = word.extract(22, 6);

            match id {
                0x12 => insn_dsync(cpu),
                0x13 => insn_isync(cpu),
                _ => Err(Box::new(OpcodeError::InvalidVariant(0x0D, id as u8))),
            }
        }
    }
}

fn insn_dsync(cpu: &mut CpuState) -> Result<()> {
    cpu.registers.pc += 4;
    tracing::trace!("Decode DSYNC");
    Ok(())
}

fn insn_isync(cpu: &mut CpuState) -> Result<()> {
    cpu.registers.pc += 4;
    tracing::trace!("Decode ISYNC");
    Ok(())
}

fn insn_movha(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    parser::rlc_parser(insn, |_, c, const16| {
        cpu.registers.address[c] = const16 << 16;
        tracing::trace!(
            "Decode MOVH.A [{:08X}] A[{}]={:08X}",
            insn,
            c,
            cpu.registers.address[c]
        );
        cpu.registers.pc += 4;
        Ok(())
    })
}

fn insn_movh(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    parser::rlc_parser(insn, |_, c, const16| {
        cpu.registers.data[c] = const16 << 16;
        tracing::trace!(
            "Decode MOVH [{:08X}] A[{}]={:08X}",
            insn,
            c,
            cpu.registers.address[c]
        );
        cpu.registers.pc += 4;
        Ok(())
    })
}

fn insn_lea_bol(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    parser::bol_parser(insn, |a, b, off16| {
        let ea = cpu.registers.address[b].wrapping_add(sign_extend(off16 as i32, 16) as u32);
        cpu.registers.address[a] = ea;
        tracing::trace!("Decode LEA [{:08X}] A[{}]={:08X}", insn, a, ea);
        cpu.registers.pc += 4;
        Ok(())
    })
}

fn insn_ji_sr(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read16(cpu.registers.pc)?;
    parser::sr_parser(insn, |a, _| {
        cpu.registers.pc = cpu.registers.address[a] & !1u32;
        tracing::trace!(
            "Decode JI [{:04X}] PC=A[{}]={:08X}",
            insn,
            a,
            cpu.registers.pc
        );
        Ok(())
    })
}

fn insn_mov_rlc(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    parser::rlc_parser(insn, |_, c, off16| {
        let sign_extended_const16 = sign_extend(off16 as i32, 16) as u32;
        cpu.registers.data[c] = sign_extended_const16;
        tracing::trace!(
            "Decode MOV [{:08X}] D[{}]={:08X}",
            insn,
            c,
            sign_extended_const16
        );
        cpu.registers.pc += 4;
        Ok(())
    })
}

fn insn_mtcr(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    parser::rlc_parser(insn, |a, _, off16| {
        let value = cpu.registers.data[a];
        let cr = cpu.get_core_register_by_offset(off16 as u16);
        *cr = value;
        tracing::trace!(
            "Decode MTCR [{:08X}] CR[0x{:04X}]=D[{}]={:08X}",
            insn,
            off16,
            a,
            value
        );
        cpu.registers.pc += 4;
        Ok(())
    })
}

fn insn_ldw_bol(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    parser::bol_parser(insn, |a, b, off16| {
        let sign_extended_off16 = sign_extend(off16 as i32, 16) as u32;
        let ea = cpu.registers.address[b].wrapping_add(sign_extended_off16);
        cpu.registers.data[a] = cpu.memory_proxy.read32(ea)?;
        tracing::trace!(
            "Decode LD.W [{:08X}] D[{}]={:08X}",
            insn,
            a,
            cpu.registers.data[a]
        );
        cpu.registers.pc += 4;
        Ok(())
    })
}

fn insn_stw_bol(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    parser::bol_parser(insn, |a, b, off16| {
        let sign_extended_off16 = sign_extend(off16 as i32, 16) as u32;
        let ea = cpu.registers.address[b].wrapping_add(sign_extended_off16);
        cpu.memory_proxy.write32(ea, cpu.registers.data[a])?;
        tracing::trace!(
            "Decode ST.W [{:08X}] MEM[0x{:08X}]={:08X}",
            insn,
            ea,
            cpu.registers.data[a]
        );
        cpu.registers.pc += 4;
        Ok(())
    })
}

fn insn_ldw_slr(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read16(cpu.registers.pc)?;
    parser::slr_parser(insn, |c, b| {
        cpu.registers.data[c] = cpu.memory_proxy.read32(cpu.registers.address[b])?;
        tracing::trace!(
            "Decode LD.W [{:04X}] D[{}]={:08X}",
            insn,
            c,
            cpu.registers.data[c]
        );
        cpu.registers.pc += 2;
        Ok(())
    })
}

fn insn_add_src(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read16(cpu.registers.pc)?;
    parser::src_parser(insn, |a, const4| {
        let result = cpu.registers.data[a] + sign_extend(const4 as i32, 4) as u32;
        cpu.registers.data[a] = result;
        tracing::trace!(
            "Decode ADD [{:04X}] D[{}]={:08X}",
            insn,
            a,
            cpu.registers.data[a]
        );
        cpu.registers.pc += 2;
        Ok(())
    })
}

impl Display for OpcodeError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match *self {
            OpcodeError::InvalidOpcode(opcode) => {
                write!(f, "Invalid instruction opcode 0x{:02X}", opcode)
            }
            OpcodeError::InvalidVariant(opcode, variant) => write!(
                f,
                "Invalid variant 0x{:02X} for opcode 0x{:02X}",
                variant, opcode
            ),
        }
    }
}

impl Error for OpcodeError {}
