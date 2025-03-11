mod bit_utils;
mod bus;
mod config;
mod cpu;
mod elf;
mod machine;

use std::path::PathBuf;

use config::MachineConfig;
use machine::Machine;

use clap::Parser;

#[derive(Parser)]
#[command(version, about, long_about = None)]
struct Cli {
    #[arg(short, long, value_name = "FILE")]
    kernel: Option<PathBuf>,
}

fn main() {
    let cli = Cli::parse();

    tracing_subscriber::fmt()
        .with_max_level(tracing::Level::TRACE)
        .init();

    if let Some(file) = cli.kernel.as_deref() {
        let file_data = std::fs::read(file).expect("Cannot read file");
        let slice = file_data.as_slice();
        let elf_parse_result = elf::parse_elf_data(slice);

        match elf_parse_result {
            Ok(elf_data) => {
                let config = MachineConfig::create_tc33x();
                let mut machine = Machine::from_config(&config);
                machine.init_from_elf(&elf_data);
                machine.start();
            }
            Err(e) => {
                tracing::error!("Cannot parse ELF file {}: {}", file.display(), e);
            }
        }
    }
}
