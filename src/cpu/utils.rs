pub mod parser {
    use crate::utils::BitManipulation;

    pub fn rlc_parser<F>(insn: u32, mut callback: F)
    where
        F: FnMut(usize, usize, u32),
    {
        let a = insn.extract(8, 4) as usize;
        let c = insn.extract(28, 4) as usize;
        let const16 = insn.extract(12, 16);
        callback(a, c, const16);
    }

    pub fn bol_parser<F>(insn: u32, mut callback: F)
    where
        F: FnMut(usize, usize, u32),
    {
        let a = insn.extract(8, 4) as usize;
        let b = insn.extract(12, 4) as usize;
        let off16 = insn.extract(16, 6) | (insn.extract(28, 4) << 6) | (insn.extract(22, 6) << 10);
        callback(a, b, off16);
    }

    pub fn sr_parser<F>(insn: u16, mut callback: F)
    where
        F: FnMut(usize, usize),
    {
        let a = insn.extract(8, 4) as usize;
        let b = insn.extract(12, 4) as usize;
        callback(a, b);
    }

    pub fn slr_parser<F>(insn: u16, callback: F)
    where
        F: FnMut(usize, usize),
    {
        sr_parser(insn, callback);
    }

    pub fn src_parser<F>(insn: u16, callback: F)
    where
        F: FnMut(usize, usize),
    {
        sr_parser(insn, callback);
    }
}
