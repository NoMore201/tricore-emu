#ifndef TRICORE_EMU_ELF_HPP
#define TRICORE_EMU_ELF_HPP

#include "Types.hpp"

#include <cstddef>
#include <filesystem>
#include <fstream>
#include <optional>
#include <string>
#include <vector>


namespace Tricore {

class Elf {

public:
    static constexpr std::size_t n_ident_size = 16;

    static constexpr u32 elf_sht_progbits = 1;

    struct ProgramHeader {
        u32 p_type;
        u32 p_offset;
        u32 p_vaddr;
        u32 p_paddr;
        u32 p_filesz;
        u32 p_memsz;
        u32 p_flags;
        u32 p_align;
    };

    struct ElfHeader {
        u8 e_ident[n_ident_size];
        u16 e_type;
        u16 e_machine;
        u32 e_version;
        u32 e_entry;
        u32 e_phoff;
        u32 e_shoff;
        u32 e_flags;
        u16 e_ehsize;
        u16 e_phentsize;
        u16 e_phnum;
        u16 e_shentsize;
        u16 e_shnum;
        u16 e_shstrndx;
    };

    struct SectionHeader {
        u32 sh_name;
        u32 sh_type;
        u32 sh_flags;
        u32 sh_addr;
        u32 sh_offset;
        u32 sh_size;
        u32 sh_link;
        u32 sh_info;
        u32 sh_addralign;
        u32 sh_entsize;
    };

    struct SectionHeaderWithName {
        SectionHeader header;
        std::string name;
    };

    enum class Error { InvalidFile, ReadError };

    Elf();

    u32 entrypoint() const noexcept { return m_header.e_entry; }

    SectionHeader get_string_table();

    std::vector<SectionHeaderWithName> get_section_headers_with_names();

    std::optional<Error> parse_file(const std::filesystem::path &file_path);

    std::vector<byte> get_section_data(const SectionHeader& section);

private:
    ElfHeader m_header{};
    std::ifstream m_file;
};

} // namespace Tricore

#endif // TRICORE_EMU_ELF_HPP
