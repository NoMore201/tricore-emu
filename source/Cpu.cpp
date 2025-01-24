#include "Cpu.hpp"
#include "Memory.hpp"
#include "Error.hpp"

#include <fmt/base.h>
#include <fmt/core.h>

namespace {

constexpr std::byte insn_movha_id = std::byte{0x91};

} // anonymous namespace

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
    for (;;) {
        switch (m_memory.peek_at(m_program_counter)) {
            case insn_movha_id:
                insn_movha();
                break;
            default:
                throw Exception{"Instruction not implemented"};
        }
    }
}


void Tricore::Cpu::insn_movha() {
    u32 insn{};
    m_memory.read(reinterpret_cast<std::byte*>(&insn), m_program_counter, 4);
    fmt::print("Cpu: MOVH.A 0x{:08X}\n", insn);
    m_program_counter += 4;
}