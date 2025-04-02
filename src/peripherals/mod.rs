mod scu;
mod xram;

use std::{cell::RefCell, rc::Rc};

use crate::bus::BusInterface;

pub fn create_rc() -> Vec<Rc<RefCell<dyn BusInterface>>> {
    vec![xram::create_rc(), scu::Scu::create_rc()]
}
