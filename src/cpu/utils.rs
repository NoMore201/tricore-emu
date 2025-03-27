pub mod parser {
    use crate::cpu::opcodes::Result;
    use crate::utils::BitManipulation;

    pub fn rc_parser<F>(insn: u32, mut callback: F) -> Result<()>
    where
        F: FnMut(usize, usize, u32) -> Result<()>,
    {
        let a = insn.extract(8, 4) as usize;
        let c = insn.extract(28, 4) as usize;
        let const9 = insn.extract(12, 9);
        callback(a, c, const9)
    }

    pub fn rlc_parser<F>(insn: u32, mut callback: F) -> Result<()>
    where
        F: FnMut(usize, usize, u32) -> Result<()>,
    {
        let a = insn.extract(8, 4) as usize;
        let c = insn.extract(28, 4) as usize;
        let const16 = insn.extract(12, 16);
        callback(a, c, const16)
    }

    pub fn sr_parser<F>(insn: u16, mut callback: F) -> Result<()>
    where
        F: FnMut(usize, usize) -> Result<()>,
    {
        let a = insn.extract(8, 4) as usize;
        let b = insn.extract(12, 4) as usize;
        callback(a, b)
    }

    pub fn slr_parser<F>(insn: u16, callback: F) -> Result<()>
    where
        F: FnMut(usize, usize) -> Result<()>,
    {
        sr_parser(insn, callback)
    }

    pub fn src_parser<F>(insn: u16, callback: F) -> Result<()>
    where
        F: FnMut(usize, usize) -> Result<()>,
    {
        sr_parser(insn, callback)
    }

    pub fn srr_parser<F>(insn: u16, callback: F) -> Result<()>
    where
        F: FnMut(usize, usize) -> Result<()>,
    {
        sr_parser(insn, callback)
    }

    pub fn brc_parser<F>(insn: u32, mut callback: F) -> Result<()>
    where
        F: FnMut(usize, usize, u32) -> Result<()>,
    {
        let a = insn.extract(8, 4) as usize;
        let b = insn.extract(12, 4) as usize;
        let disp15 = insn.extract(16, 15);
        callback(a, b, disp15)
    }
}
