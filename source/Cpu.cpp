#include "Cpu.hpp"
#include "Error.hpp"
#include "Memory.hpp"
#include "Utils.hpp"

#include <fmt/base.h>
#include <fmt/core.h>

namespace {

constexpr u32 peripherals_start_address = 0xF0000000U;

constexpr std::byte insn_movha_id = std::byte{0x91};
constexpr std::byte insn_lea_bol = std::byte{0xD9};

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
    u32 insn = read_32(m_program_counter);
    fmt::print("Cpu: MOVH.A 0x{:08X}\n", insn);
    const auto addr_register_index = Utils::extract32(insn, 28, 4);
    const auto msb_half_word = Utils::extract32(insn, 12, 16);
    m_address_registers.at(addr_register_index) = 0U | (msb_half_word << 16U);
    m_program_counter += 4;
}

void Tricore::Cpu::insn_lea_bol() {
    // u32 insn = read_32(m_program_counter);
    // fmt::print("Cpu: LEA 0x{:08X}\n", insn);
    // const auto addr_index_a = Utils::extract32(insn, 8, 4);
    // const auto addr_index_b = Utils::extract32(insn, 12, 4);
    // const auto off10 = Utils::extract32(insn, 16, 6);
    // const u32 effective_address = m_address_registers.at(addr_index_a);
    // m_address_registers.at(addr_register_index) = 0U | (msb_half_word << 16U);
    // m_program_counter += 4;
}

u32 Tricore::Cpu::read_32(u32 address) {
    u32 data{};
    m_memory.read(reinterpret_cast<std::byte *>(&data), m_program_counter, 4);
    return data;
}