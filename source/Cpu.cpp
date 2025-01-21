#include "Cpu.hpp"
#include "Memory.hpp"
#include <stdexcept>

Tricore::Cpu Tricore::Cpu::create_tc33x() {
    Cpu cpu{};
    // pflash
    cpu.add_memory(
        Memory{Memory::Layout{2ULL * MiB, 0xA0000000U}, {0x80000000U}});
    // dflash
    cpu.add_memory(Memory{Memory::Layout{128ULL * KiB, 0xAF000000U}});

    return cpu;
}

void Tricore::Cpu::init(Elf &elf_file) {
    set_program_counter(elf_file.entrypoint());

    const auto sections = elf_file.get_section_headers_with_names();
    for (const auto &[section, name] : sections) {
        for (auto &mem : m_memories) {
            if (mem.is_address_valid(section.sh_addr)) {
                const auto data = elf_file.get_section_data(section);
                mem.write(data.data(), section.sh_addr, section.sh_size);
            }
        }
    }
}

void Tricore::Cpu::start() {
    throw std::runtime_error("Not implemented error");
}