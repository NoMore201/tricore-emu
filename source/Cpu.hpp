#ifndef TRICORE_EMU_CPU_HPP
#define TRICORE_EMU_CPU_HPP

#include "Types.hpp"
#include "Memory.hpp"
#include "Elf.hpp"

#include <array>

namespace Tricore {

class Cpu {

public:

    Cpu() = default;

    static Cpu create_tc33x();

    void init(Elf& elf_file);

    void add_memory(Memory mem) { m_memories.push_back(std::move(mem)); }

    void set_program_counter(u32 address) noexcept { m_program_counter = address; }

    void start();

private:

    static constexpr usize register_count = 16;

    // CPU registers
    std::array<u32, register_count> m_data_registers{};
    std::array<u32, register_count> m_address_registers{};
    u32 m_program_counter{};
    // TODO add all registers

    // Memory
    std::vector<Memory> m_memories;
};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_CPU_HPP