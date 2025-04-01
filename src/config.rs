
use crate::utils::{KiB, MiB};

pub struct MemoryDetails {
    pub name: String,
    pub size: usize,
    pub address: u32,
    pub mirror_address: Option<u32>,
}

pub struct MachineConfig {
    pub num_of_cpus: i32,
    pub memory_areas: Vec<MemoryDetails>,
}

impl MachineConfig {
    pub fn create_tc33x() -> Self {
        MachineConfig {
            num_of_cpus: 1,
            memory_areas: vec![
                MemoryDetails {
                    name: String::from("pflash"),
                    size: 2 * MiB,
                    address: 0xA0000000u32,
                    mirror_address: Some(0x80000000u32),
                },
                MemoryDetails {
                    name: String::from("dflash0"),
                    size: 128 * KiB,
                    address: 0xAF000000u32,
                    mirror_address: None,
                },
                MemoryDetails {
                    name: String::from("dflash1"),
                    size: 128 * KiB,
                    address: 0xAFC00000u32,
                    mirror_address: None,
                },
                MemoryDetails {
                    name: String::from("psram"),
                    size: 8 * KiB,
                    address: 0x70100000u32,
                    mirror_address: Some(0xC0000000u32),
                },
                MemoryDetails {
                    name: String::from("dsram"),
                    size: 192 * KiB,
                    address: 0x70000000u32,
                    mirror_address: Some(0xD0000000u32),
                },
                MemoryDetails {
                    name: String::from("ucb"),
                    size: 24 * KiB,
                    address: 0xAF400000u32,
                    mirror_address: None,
                },
            ],
        }
    }
}
