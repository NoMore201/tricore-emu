use std::{cell::RefCell, rc::Rc};

use crate::{
    memory::MemoryRegion,
    utils::KiB,
};

const XRAM_START_ADDRESS: u32 = 0xF0240000;
const XRAM_SIZE: usize = 8 * KiB;

pub fn create_rc() -> Rc<RefCell<MemoryRegion>> {
    MemoryRegion::create_rc(XRAM_START_ADDRESS, XRAM_SIZE, "XRAM")
}
