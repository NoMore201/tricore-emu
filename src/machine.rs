use std::{cell::RefCell, rc::Rc};

use crate::{
    bus::{BusError, BusInterface, BusProxy},
    config::MachineConfig,
    cpu::CpuState,
    elf::ElfData,
    memory::{MemoryRegion, MemoryRegionMirror},
    peripherals,
};

pub struct Machine {
    memory_regions: Vec<Rc<RefCell<MemoryRegion>>>,
    mirrored_regions: Vec<Rc<RefCell<MemoryRegionMirror>>>,
    bus_handler: Rc<RefCell<BusProxy>>,
    cpu: CpuState,
    peripherals: Vec<Rc<RefCell<dyn BusInterface>>>,
}

impl Machine {
    pub fn from_config(config: &MachineConfig) -> Machine {
        let bus_handler = Rc::new(RefCell::new(BusProxy::new()));
        let mut machine = Self {
            memory_regions: Vec::new(),
            mirrored_regions: Vec::new(),
            bus_handler: bus_handler.clone(),
            cpu: CpuState::create(bus_handler.clone()),
            peripherals: peripherals::create_rc(),
        };

        for area in config.memory_areas.iter() {
            let region = Rc::new(RefCell::new(MemoryRegion::create(
                area.address,
                area.size,
                &area.name,
            )));

            if let Some(mirror_address) = area.mirror_address {
                machine
                    .mirrored_regions
                    .push(Rc::new(RefCell::new(MemoryRegionMirror::create(
                        mirror_address,
                        region.clone(),
                    ))));
            }
            machine.memory_regions.push(region);
        }

        machine
    }

    pub fn init_from_elf(&mut self, elf_data: &ElfData) {
        tracing::info!("Initializing machine from ELF data");

        // register all memory regions in bus handler
        for region in self.memory_regions.iter() {
            self.bus_handler
                .borrow_mut()
                .register_device(region.clone());
        }
        // register all memory regions mirrors in bus handler
        for mirrored_region in self.mirrored_regions.iter() {
            self.bus_handler
                .borrow_mut()
                .register_device(mirrored_region.clone());
        }
        // register all peripherals in bus handler
        for peripheral in &self.peripherals {
            self.bus_handler
                .borrow_mut()
                .register_device(peripheral.clone());
        }

        self.cpu.set_program_counter(elf_data.entrypoint);

        for section in elf_data
            .section_headers
            .iter()
            .filter(|&s| !s.data.is_empty() && s.address != 0)
        {
            if let Err(error) = self
                .bus_handler
                .borrow_mut()
                .write(section.address, &section.data)
            {
                match error {
                    BusError::InvalidAddress(_) => {
                        tracing::debug!(
                            "Section {} address is not mapped into machine. Ignoring..",
                            section.name
                        );
                    }
                    BusError::OutOfBounds => {
                        tracing::warn!(
                            "Section {} data [addr={:08X}, length={}] does not fit currently configured memory regions",
                            section.name, section.address, section.data.len()
                        );
                    }
                }
            }
        }
    }

    pub fn start(&mut self) {
        self.cpu.start();
    }
}

#[cfg(test)]
mod tests {
    use std::{cell::RefCell, rc::Rc};

    use crate::{
        bus::BusInterface,
        config::{MachineConfig, MemoryDetails},
    };

    use super::{Machine, MemoryRegion, MemoryRegionMirror};

    #[test]
    fn test_machine_creation() {
        let config = MachineConfig {
            num_of_cpus: 1,
            memory_areas: vec![
                MemoryDetails {
                    name: String::from("ram"),
                    size: 12345678,
                    address: 0xDEADBEEFu32,
                    mirror_address: Some(0xDADADADAu32),
                },
                MemoryDetails {
                    name: String::from("rom"),
                    size: 987654,
                    address: 0x10000000u32,
                    mirror_address: None,
                },
            ],
        };

        let machine = Machine::from_config(&config);
        assert_eq!(machine.memory_regions.len(), 2);
        assert_eq!(machine.memory_regions[0].borrow().name, "ram");
        assert_eq!(
            machine.memory_regions[0].borrow().start_address,
            0xDEADBEEFu32
        );
        assert_eq!(machine.memory_regions[0].borrow().buffer.len(), 12345678);
        assert!(machine.memory_regions[0]
            .borrow()
            .buffer
            .iter()
            .all(|&b| b == 0));
        assert_eq!(machine.memory_regions[1].borrow().name, "rom");
        assert_eq!(
            machine.memory_regions[1].borrow().start_address,
            0x10000000u32
        );
        assert_eq!(machine.memory_regions[1].borrow().buffer.len(), 987654);
        assert!(machine.memory_regions[1]
            .borrow()
            .buffer
            .iter()
            .all(|&b| b == 0));

        assert_eq!(machine.mirrored_regions.len(), 1);
        assert_eq!(
            machine.mirrored_regions[0].borrow().start_address,
            0xDADADADAu32
        );
    }
}
