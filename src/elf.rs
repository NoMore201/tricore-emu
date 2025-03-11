use elf::endian::LittleEndian;
use elf::{ElfBytes, ParseError};

use std::error::Error;

pub struct SectionHeader {
    pub name: String,
    pub data: Vec<u8>,
    pub address: u32
}

pub struct ElfData {
    pub entrypoint: u32,
    pub section_headers: Vec<SectionHeader>
}

pub fn parse_elf_data(file_data: &[u8]) -> Result<ElfData, Box<dyn Error>> {
    let file = ElfBytes::<LittleEndian>::minimal_parse(file_data)?;

    let tables = file.section_headers_with_strtab()?;
    let mut final_list: Vec<SectionHeader> = Vec::new();

    match tables {
        (Some(sh_table), Some(string_table)) => {
            for section in sh_table {
                let (data_slice, _) = file.section_data(&section)?;
                let string_name = string_table.get(section.sh_name as usize)?;
                tracing::debug!("Found section {} [address=0x{:08X}, length={}]", string_name, section.sh_addr, section.sh_size);
                // filter only progbits regions
                if section.sh_type == elf::abi::SHT_PROGBITS && data_slice.len() != 0 {
                    final_list.push(SectionHeader {
                        name: string_name.into(),
                        data: data_slice.into(),
                        address: section.sh_addr as u32
                    });
                }
            }
        }
        (_, _) => {
            return Err(Box::from(ParseError::BadOffset(0u64)));
        }
    }
    
    Ok(ElfData{ entrypoint: file.ehdr.e_entry as u32, section_headers: final_list})
}
