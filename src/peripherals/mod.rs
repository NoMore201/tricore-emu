mod scu;

use crate::{
    bus::{BusError, BusInterface, BusProxy},
    memory::MemoryRegion,
    utils::KiB,
};

const XRAM_START_ADDRESS: u32 = 0xF0240000;
const XRAM_SIZE: usize = 8 * KiB;

pub struct PeripheralHandler {
    proxy: BusProxy,
}

impl PeripheralHandler {
    pub fn new() -> Self {
        let mut proxy = BusProxy::new();
        proxy.register_device(MemoryRegion::create_rc(
            XRAM_START_ADDRESS,
            XRAM_SIZE,
            "XRAM",
        ));
        PeripheralHandler { proxy }
    }
}

impl BusInterface for PeripheralHandler {
    fn read(&self, address: u32, data: &mut [u8]) -> Result<(), BusError> {
        self.proxy.read(address, data)
    }

    fn write(&mut self, address: u32, data: &[u8]) -> Result<(), BusError> {
        self.proxy.write(address, data)
    }

    fn address_is_managed(&self, address: u32) -> bool {
        self.proxy.address_is_managed(address)
    }
}
