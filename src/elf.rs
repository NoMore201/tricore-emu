use elf::endian::LittleEndian;
use elf::{ElfBytes, ParseError};

use std::error::Error;

pub struct SectionHeader {
    pub name: String,
    pub data: Vec<u8>,
    pub address: u32
}

pub fn parse_elf_section_headers(file_data: &[u8]) -> Result<Vec<SectionHeader>, Box<dyn Error>> {
    let file = ElfBytes::<LittleEndian>::minimal_parse(file_data)?;

    let tables = file.section_headers_with_strtab()?;

    match tables {
        (Some(sh_table), Some(string_table)) => {
            let mut final_list: Vec<SectionHeader> = Vec::new();
            for section in sh_table {
                let (data_slice, _) = file.section_data(&section)?;
                let string_name = string_table.get(section.sh_name as usize)?;
                final_list.push(SectionHeader {
                    name: string_name.into(),
                    data: data_slice.into(),
                    address: section.sh_addr as u32
                });
            }
            Ok(final_list)
        }
        (_, _) => {
            Err(Box::from(ParseError::BadOffset(0u64)))
        }
    }
}
