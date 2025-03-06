

pub struct MachineConfig {
    pub num_of_cpus: i32,
    pub pflash_size: usize,
    pub dflash0_size: usize,
    pub dflash1_size: usize,
    pub psram_size: usize,
    pub dsram_size: usize
}

const KB: usize = 1024;
const MB: usize = KB * KB; 

impl MachineConfig {

// TODO: create factory function to initialize from a config file

pub fn create_tc33x() -> Self {
    MachineConfig{
        num_of_cpus: 1,
        pflash_size: 2 * MB,
        dflash0_size: 128 * KB,
        dflash1_size: 128 * KB,
        psram_size: 8 * KB,
        dsram_size: 192 * KB
    }
}

}