#include "Elf.hpp"

#include <fstream>
#include <optional>
#include <string>

namespace {

// elf.h constants

constexpr char elf_magic_number_0 = '\x7F';
constexpr char elf_magic_number_1 = 'E';
constexpr char elf_magic_number_2 = 'L';
constexpr char elf_magic_number_3 = 'F';

} // anonymous namespace

Tricore::Elf::Elf() = default;

Tricore::Elf::SectionHeader Tricore::Elf::get_string_table()
{

    const std::ifstream::pos_type string_header_offset = m_header.e_shoff + (m_header.e_shstrndx * m_header.e_shentsize);

    SectionHeader section_header {};
    m_file.seekg(string_header_offset);
    m_file.read(reinterpret_cast<std::ifstream::char_type*>(&section_header), sizeof(SectionHeader));
    return section_header;
}

std::vector<Tricore::Elf::SectionHeaderWithName> Tricore::Elf::get_section_headers_with_names()
{
    auto string_table = get_string_table();

    std::vector<Tricore::Elf::SectionHeaderWithName> section_list {};
    section_list.reserve(m_header.e_shnum);

    // skip first entry since it's reserved
    for (u32 pos = m_header.e_shoff + m_header.e_shentsize; pos < m_header.e_shoff + (m_header.e_shnum * m_header.e_shentsize);
         pos += m_header.e_shentsize) {
        SectionHeader section_header {};
        m_file.seekg(pos);
        m_file.read(reinterpret_cast<std::ifstream::char_type*>(&section_header), sizeof(SectionHeader));

        m_file.seekg(string_table.sh_offset + section_header.sh_name);
        std::string name {};
        std::getline(m_file, name, '\0');
        section_list.emplace_back(section_header, name);
    }

    return section_list;
}

std::optional<Tricore::Elf::Error> Tricore::Elf::parse_file(const std::filesystem::path& file_path)
{
    m_file = std::ifstream(file_path, std::ios::binary);
    m_file.seekg(0);

    if (!m_file) {
        return Error::ReadError;
    }

    if (!m_file.read(reinterpret_cast<char*>(&m_header), sizeof(m_header))) {
        return Error::InvalidFile;
    }

    if (m_header.e_ident[0] != elf_magic_number_0 || m_header.e_ident[1] != elf_magic_number_1 || m_header.e_ident[2] != elf_magic_number_2 || m_header.e_ident[3] != elf_magic_number_3) {
        return Error::InvalidFile;
    }

    return {};
}

std::vector<byte> Tricore::Elf::get_section_data(const SectionHeader& section)
{
    std::vector<byte> data {};

    data.resize(section.sh_size);
    m_file.seekg(section.sh_offset);
    m_file.read(reinterpret_cast<std::ifstream::char_type*>(data.data()), section.sh_size);

    return data;
}
