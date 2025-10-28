#include "Machine.hpp"
#include "Elf.hpp"
#include "Tricore.hpp"

namespace {

std::vector<Tricore::MemoryRegion> init_flash_layout(Tricore::CpuVariant variant)
{
    std::vector<Tricore::MemoryRegion> flash_layout;
    switch (variant) {
    case Tricore::CpuVariant::TC33X:
    default: {
        // pflash0
        flash_layout.emplace_back(0xA0000000U, 2 * MiB, 0x80000000U);
        // dflash0
        flash_layout.emplace_back(0xAF000000U, 128 * KiB);
        // dsram0
        flash_layout.emplace_back(0x70000000U, 192 * KiB, 0xD0000000U);
        // psram0
        flash_layout.emplace_back(0x70100000U, 8 * KiB, 0xC0000000U);
        // ucb
        flash_layout.emplace_back(0xAF400000U, 24 * KiB);
        // xram
        flash_layout.emplace_back(0xF0240000U, 8 * KiB);
    }
    }

    return flash_layout;
}

}

Tricore::Machine::Machine(Tricore::CpuVariant variant)
    : m_cpu(m_bus)
    , m_flash_layout(init_flash_layout(variant))
{
    for (auto& region : m_flash_layout) {
        m_bus.register_device(region);
    }
}

void Tricore::Machine::init(Elf& elf_file)
{
    m_cpu.initialize_program(elf_file);
}

void Tricore::Machine::start() { m_cpu.start(); }
