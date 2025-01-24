#include "Cpu.hpp"
#include "Memory.hpp"
#include <stdexcept>

#include <fmt/core.h>

Tricore::Cpu Tricore::Cpu::create_tc33x() {
    Cpu cpu{};
    // pflash0
    cpu.m_memory.add_memory_region(Memory::Layout{2ULL * MiB, 0xA0000000U},
                                   {0x80000000U});
    // dflash0
    cpu.m_memory.add_memory_region(Memory::Layout{128ULL * KiB, 0xAF000000U});
    // dsram0
    cpu.m_memory.add_memory_region(Memory::Layout{192ULL * KiB, 0x70000000U},
                                   {0xD0000000U});
    // psram0
    cpu.m_memory.add_memory_region(Memory::Layout{8ULL * KiB, 0x70100000U},
                                   {0xC0000000U});
    // ucb
    cpu.m_memory.add_memory_region(Memory::Layout{24ULL * KiB, 0xAF400000U});
    // xram
    cpu.m_memory.add_memory_region(Memory::Layout{8ULL * KiB, 0xF0240000U});

    return cpu;
}

void Tricore::Cpu::init(Elf &elf_file) {
    set_program_counter(elf_file.entrypoint());

    const auto sections = elf_file.get_section_headers_with_names();

    for (const auto &[section, name] : sections) {
        const auto data = elf_file.get_section_data(section);
        try {
            m_memory.write(data.data(), section.sh_addr, section.sh_size);
            fmt::print("Cpu: initializing memory with content of section {} at "
                       "address 0x{:02X}\n",
                       name, section.sh_addr);
        } catch (InvalidMemoryAccess &) {
            fmt::print(
                "Cpu: ignoring section {}, address 0x{:02X} not handled\n",
                name, section.sh_addr);
        }
    }
}

void Tricore::Cpu::start() {
    throw std::runtime_error("Not implemented error");
}