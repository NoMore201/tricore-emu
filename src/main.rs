mod bus;
mod config;
mod elf;
mod machine;

use std::path::PathBuf;

use clap::Parser;
use config::MachineConfig;
use machine::Machine;

#[derive(Parser)]
#[command(version, about, long_about = None)]
struct Cli {
    #[arg(short, long, value_name = "FILE")]
    kernel: Option<PathBuf>,
}

fn main() {
    let cli = Cli::parse();

    if let Some(file) = cli.kernel.as_deref() {
        let file_data = std::fs::read(file).expect("Cannot read file");
        let slice = file_data.as_slice();
        let example_file = elf::parse_elf_section_headers(slice);

        match example_file {
            Ok(list) => {
                for sh in list.iter() {
                    println!(
                        "Section {} address=0x{:08X} length={}",
                        sh.name,
                        sh.address,
                        sh.data.len()
                    );
                }
                let config = MachineConfig::create_tc33x();
                let mut machine = Machine::from_config(&config);
                machine.start();
            }
            Err(e) => {
                println!("Cannot parse file: {}", e);
            }
        }
    }
}
