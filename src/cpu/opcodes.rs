use std::error::Error;
use std::fmt::Display;

use crate::cpu::CpuState;
use crate::utils::{sign_extend, BitManipulation};

const OPCODE_ADD_SRC: u8 = 0xC2;
const OPCODE_AND_SRR: u8 = 0x26;
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
const OPCODE_JUMP_DF: u8 = 0xDF;
const OPCODE_8F: u8 = 0x8F;

pub type Result<T> = std::result::Result<T, Box<dyn std::error::Error>>;

struct BolLayout {
    a: u32,
    b: u32,
    off16: u32,
}

struct RlcLayout {
    a: u32,
    c: u32,
    const16: u32,
}

struct SlrLayout {
    b: u32,
    c: u32,
}

struct SrLayout {
    a: u32,
    b: u32,
}

type SrrLayout = SrLayout;

struct SrcLayout {
    a: u32,
    const4: u32,
}

struct RcLayout {
    a: u32,
    c: u32,
    const9: u32,
}

struct BrcLayout {
    a: u32,
    b: u32,
    disp15: u32,
}

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
        OPCODE_AND_SRR => insn_and_srr(cpu),
        OPCODE_JUMP_DF => insn_jump_df(cpu),
        OPCODE_8F => parse_8fh_opcodes(cpu),
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

fn parse_8fh_opcodes(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc).unwrap();
    let id = insn.extract(21, 7);
    println!("0x{:02X}", id);
    match id {
        0x08 => insn_and_rc(cpu),
        _ => Err(Box::new(OpcodeError::InvalidVariant(0x8F, id as u8))),
    }
}

fn insn_and_rc(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc).unwrap();
    let rc_layout = rc_layout(insn);

    let a = rc_layout.a as usize;
    let c = rc_layout.c as usize;

    cpu.registers.data[c] = cpu.registers.data[a] & rc_layout.const9;
    tracing::trace!(
        "Decode AND [{:08X}] D[{}]={:08X}",
        insn,
        c,
        cpu.registers.data[c]
    );
    cpu.registers.pc += 4;
    Ok(())
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
    let rlc_layout = rlc_layout(insn);

    let c = rlc_layout.c as usize;

    cpu.registers.address[c] = rlc_layout.const16 << 16;
    tracing::trace!(
        "Decode MOVH.A [{:08X}] A[{}]={:08X}",
        insn,
        c,
        cpu.registers.address[c]
    );
    cpu.registers.pc += 4;
    Ok(())
}

fn insn_movh(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    let rlc_layout = rlc_layout(insn);

    let c = rlc_layout.c as usize;

    cpu.registers.data[c] = rlc_layout.const16 << 16;
    tracing::trace!(
        "Decode MOVH [{:08X}] A[{}]={:08X}",
        insn,
        c,
        cpu.registers.address[c]
    );
    cpu.registers.pc += 4;
    Ok(())
}

fn insn_lea_bol(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    let bol_layout = bol_layout(insn);

    let a = bol_layout.a as usize;
    let b = bol_layout.b as usize;
    let sign_extended_off16 = sign_extend(bol_layout.off16 as i32, 16) as u32;

    let ea = cpu.registers.address[b].wrapping_add(sign_extended_off16);
    cpu.registers.address[a] = ea;
    tracing::trace!("Decode LEA [{:08X}] A[{}]={:08X}", insn, a, ea);
    cpu.registers.pc += 4;
    Ok(())
}

fn insn_ji_sr(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read16(cpu.registers.pc)?;
    let sr_layout = sr_layout(insn);

    let a = sr_layout.a as usize;

    cpu.registers.pc = cpu.registers.address[a] & !1u32;
    tracing::trace!(
        "Decode JI [{:04X}] PC=A[{}]={:08X}",
        insn,
        a,
        cpu.registers.pc
    );
    Ok(())
}

fn insn_mov_rlc(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    let rlc_layout = rlc_layout(insn);

    let c = rlc_layout.c as usize;

    let sign_extended_const16 = sign_extend(rlc_layout.const16 as i32, 16) as u32;
    cpu.registers.data[c] = sign_extended_const16;

    tracing::trace!(
        "Decode MOV [{:08X}] D[{}]={:08X}",
        insn,
        c,
        sign_extended_const16
    );
    cpu.registers.pc += 4;
    Ok(())
}

fn insn_mtcr(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    let rlc_layout = rlc_layout(insn);

    let a = rlc_layout.a as usize;

    let value = cpu.registers.data[a];
    let cr = cpu.get_core_register_by_offset(rlc_layout.const16 as u16);
    *cr = value;
    tracing::trace!(
        "Decode MTCR [{:08X}] CR[0x{:04X}]=D[{}]={:08X}",
        insn,
        rlc_layout.const16,
        a,
        value
    );
    cpu.registers.pc += 4;
    Ok(())
}

fn insn_ldw_bol(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    let bol_layout = bol_layout(insn);

    let a = bol_layout.a as usize;
    let b = bol_layout.b as usize;
    let sign_extended_off16 = sign_extend(bol_layout.off16 as i32, 16) as u32;

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
}

fn insn_stw_bol(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    let bol_layout = bol_layout(insn);

    let a = bol_layout.a as usize;
    let b = bol_layout.b as usize;
    let sign_extended_off16 = sign_extend(bol_layout.off16 as i32, 16) as u32;

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
}

fn insn_ldw_slr(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read16(cpu.registers.pc)?;
    let slr_layout = slr_layout(insn);

    let b = slr_layout.b as usize;
    let c = slr_layout.c as usize;

    cpu.registers.data[c] = cpu.memory_proxy.read32(cpu.registers.address[b])?;
    tracing::trace!(
        "Decode LD.W [{:04X}] D[{}]={:08X}",
        insn,
        c,
        cpu.registers.data[c]
    );
    cpu.registers.pc += 2;
    Ok(())
}

fn insn_add_src(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read16(cpu.registers.pc)?;
    let src_layout = src_layout(insn);

    let a = src_layout.a as usize;

    let result = cpu.registers.data[a] + sign_extend(src_layout.const4 as i32, 4) as u32;
    cpu.registers.data[a] = result;
    tracing::trace!(
        "Decode ADD [{:04X}] D[{}]={:08X}",
        insn,
        a,
        cpu.registers.data[a]
    );
    cpu.registers.pc += 2;
    Ok(())
}

fn insn_and_srr(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read16(cpu.registers.pc)?;
    let srr_layout = srr_layout(insn);

    let a = srr_layout.a as usize;
    let b = srr_layout.b as usize;

    cpu.registers.data[a] = cpu.registers.data[a] & cpu.registers.data[b];
    tracing::trace!(
        "Decode AND [{:04X}] D[{}]={:08X}",
        insn,
        a,
        cpu.registers.data[a]
    );
    cpu.registers.pc += 2;
    Ok(())
}

fn insn_jump_df(cpu: &mut CpuState) -> Result<()> {
    let insn = cpu.memory_proxy.read32(cpu.registers.pc)?;
    let brc_layout = brc_layout(insn);

    let a = brc_layout.a as usize;
    let b = brc_layout.b as usize;

    let sign_extended_const4 = sign_extend(b as i32, 4) as u32;
    let sign_extended_disp15 = sign_extend(brc_layout.disp15 as i32, 15) as u32;
    let identifier = insn.extract(31, 1);
    let (condition, name) = match identifier {
        0 => (cpu.registers.data[a] == sign_extended_const4, "JEQ"),
        1 => (cpu.registers.data[a] != sign_extended_const4, "JNE"),
        _ => {
            return Err(Box::new(OpcodeError::InvalidVariant(
                0xDF,
                identifier as u8,
            )))
        }
    };
    if condition {
        cpu.registers.pc += sign_extended_disp15 * 2;
    }
    let outcome_str = match condition {
        false => "not taken",
        true => "taken",
    };

    tracing::trace!("Decode {} [{:08X}] branch {}", name, insn, outcome_str);
    cpu.registers.pc += 4;
    Ok(())
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

fn bol_layout(insn: u32) -> BolLayout {
    BolLayout {
        a: insn.extract(8, 4),
        b: insn.extract(12, 4),
        off16: insn.extract(16, 6) | (insn.extract(28, 4) << 6) | (insn.extract(22, 6) << 10),
    }
}

fn rlc_layout(insn: u32) -> RlcLayout {
    RlcLayout {
        a: insn.extract(8, 4),
        c: insn.extract(28, 4),
        const16: insn.extract(12, 16),
    }
}

fn slr_layout(insn: u16) -> SlrLayout {
    SlrLayout {
        b: insn.extract(12, 4) as u32,
        c: insn.extract(8, 4) as u32,
    }
}

fn sr_layout(insn: u16) -> SrLayout {
    SrLayout {
        a: insn.extract(8, 4) as u32,
        b: insn.extract(12, 4) as u32,
    }
}

fn srr_layout(insn: u16) -> SrLayout {
    SrrLayout {
        a: insn.extract(8, 4) as u32,
        b: insn.extract(12, 4) as u32,
    }
}

fn src_layout(insn: u16) -> SrcLayout {
    SrcLayout {
        a: insn.extract(8, 4) as u32,
        const4: insn.extract(12, 4) as u32,
    }
}

fn rc_layout(insn: u32) -> RcLayout {
    RcLayout {
        a: insn.extract(8, 4),
        c: insn.extract(28, 4),
        const9: insn.extract(12, 9),
    }
}

fn brc_layout(insn: u32) -> BrcLayout {
    BrcLayout {
        a: insn.extract(8, 4),
        b: insn.extract(12, 4),
        disp15: insn.extract(16, 15),
    }
}
