use elf::endian::LittleEndian;
use elf::{ElfBytes, ParseError};

use std::error::Error;

pub struct SectionHeader<'data> {
    pub name: &'data str,
    pub data: &'data [u8],
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
                    name: string_name.clone(),
                    data: data_slice.clone(),
                });
            }
            return Ok(final_list);
        }
        (_, _) => {
            return Err(Box::from(ParseError::BadOffset(0u64)));
        }
    }
}
