mod elf;

fn main() {
    let path = std::path::PathBuf::from("E:\\Workspace\\aurix-cmake-code-sample\\out\\debug\\src\\aurix_sample_tc33x.elf");
    let file_data = std::fs::read(path).expect("Cannot read file");
    let slice = file_data.as_slice();
    let example_file = elf::parse_elf_section_headers(slice);

    match example_file {
        Ok(list) => {
            for sh in list.iter() {
                println!("Section {} length= {}", sh.name, sh.data.len());
            }
        },
        Err(e) => {
            println!("Cannot parse file: {}", e);
        }
    }

    println!("Hello, world!");
}
