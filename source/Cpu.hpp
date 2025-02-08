#ifndef TRICORE_EMU_CPU_HPP
#define TRICORE_EMU_CPU_HPP

#include "BusClient.hpp"
#include "Elf.hpp"
#include "Memory.hpp"
#include "Types.hpp"

#include <array>
#include <fmt/format.h>
#include <stdexcept>
#include <vector>

namespace Tricore {

struct InvalidCoreRegisterOffset : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class Cpu {

public:
    Cpu() = default;

    static Cpu create_tc33x();

    void init(Elf &elf_file);

    void set_program_counter(u32 address) noexcept {
        m_core_registers.pc = address;
    }

    void start();

private:
    static constexpr usize register_count = 16;

    // Instruction handlers
    void insn_movha();
    void insn_mov_rlc();
    void insn_lea_bol();
    void insn_ji_sr();
    void insn_mtcr();
    void insn_isync();
    void insn_ldw_slr();
    void insn_ldw_bol();
    void insn_add_c2();
    void insn_movh();
    void insn_and_srr();

    // Helpers
    u32 read_32(u32 address);
    u16 read_16(u32 address);

    // CPU registers
    std::array<u32, register_count> m_data_registers{};
    std::array<u32, register_count> m_address_registers{};
    struct CoreRegisters {
        u32 pcxi{0};
        u32 psw{0};
        u32 pc{0};
        u32 syscon{0};
        u32 cpu_id{0};
        u32 core_id{0};
        u32 biv{0};
        u32 btv{0};
        u32 isp{0};
        u32 icr{0};
        u32 fcx{0};
        u32 lcx{0};

        u32 &operator[](usize offset);

    } m_core_registers;
    // TODO add all registers

    // Devices
    std::vector<BusClient *> m_bus_clients;
    Memory m_memory;
};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_CPU_HPP