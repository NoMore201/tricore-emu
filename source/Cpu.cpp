#include "Cpu.hpp"
#include "Error.hpp"
#include "Memory.hpp"
#include "Types.hpp"
#include "Utils.hpp"

#include <spdlog/spdlog.h>

namespace {

constexpr std::byte bytecode_movha_id = std::byte{0x91};
constexpr std::byte bytecode_mov_rlc = std::byte{0x3B};
constexpr std::byte bytecode_lea_bol = std::byte{0xD9};
constexpr std::byte bytecode_ji_sr = std::byte{0xDC};
constexpr std::byte bytecode_mtcr = std::byte{0xCD};
constexpr std::byte bytecode_isync = std::byte{0x0D};
constexpr std::byte bytecode_ldw_slr = std::byte{0x54};
constexpr std::byte bytecode_ldw_bol = std::byte{0x19};
constexpr std::byte bytecode_add_c2 = std::byte{0xC2};
constexpr std::byte bytecode_movh = std::byte{0x7B};
constexpr std::byte bytecode_and_srr = std::byte{0x26};
constexpr std::byte bytecode_jne_brc = std::byte{0xDF};
constexpr std::byte bytecode_suba_rr = std::byte{0x01};
constexpr std::byte bytecode_movd_srr = std::byte{0x80};
constexpr std::byte bytecode_stw_bol = std::byte{0x59};
constexpr std::byte bytecode_jli = std::byte{0x2D};
constexpr std::byte bytecode_jnzt_brn = std::byte{0x6F};
constexpr std::byte bytecode_jnzt_brn_2 = std::byte{0xEF};
constexpr std::byte bytecode_ldbu_bol = std::byte{0x39};
constexpr std::byte bytecode_or_rc = std::byte{0x8F};
constexpr std::byte bytecode_stb_bol = std::byte{0xE9};
constexpr std::byte bytecode_jne_brr = std::byte{0x5F};
constexpr std::byte bytecode_jltu_brc = std::byte{0xBF};
constexpr std::byte bytecode_nop = std::byte{0x00};
constexpr std::byte bytecode_j_b = std::byte{0x1D};
constexpr std::byte bytecode_jgeu_brc = std::byte{0xFF};
constexpr std::byte bytecode_extru_rrpw = std::byte{0x37};
constexpr std::byte bytecode_sh_src = std::byte{0x06};
constexpr std::byte bytecode_insert_rcpw = std::byte{0xB7};
constexpr std::byte bytecode_or_srr = std::byte{0xA6};
constexpr std::byte bytecode_stw_ssr = std::byte{0x74};
constexpr std::byte bytecode_lha_abs = std::byte{0xC5};
constexpr std::byte bytecode_ne_rc = std::byte{0x8B};
constexpr std::byte bytecode_ne_rr = std::byte{0x0B};

struct BolFormatParser {
    u32 insn{};

    template <typename F> void parse(F &&callback) {
        namespace Utils = Tricore::Utils;
        const auto index_a = Utils::extract32(insn, 8, 4);
        const auto index_b = Utils::extract32(insn, 12, 4);
        u32 off16 = Utils::extract32(insn, 16, 6);
        off16 |= Utils::extract32(insn, 28, 4) << 6U;
        off16 |= Utils::extract32(insn, 22, 6) << 10U;
        u32 sign_extended_off16 = Utils::sign_extend32<16>(off16);
        callback(index_a, index_b, sign_extended_off16);
    }
};

struct RrFormatParser {
    u32 insn{};

    template <typename F> void parse(F &&callback) {
        namespace Utils = Tricore::Utils;
        const auto index_a = Utils::extract32(insn, 8, 4);
        const auto index_b = Utils::extract32(insn, 12, 4);
        const auto index_c = Utils::extract32(insn, 28, 4);
        callback(index_a, index_b, index_c);
    }
};

struct BrnFormatParser {
    u32 insn{};

    template <typename F> void parse(F &&callback) {
        namespace Utils = Tricore::Utils;
        const auto index_a = Utils::extract32(insn, 8, 4);
        const auto bit_n = Utils::extract32(insn, 12, 4);
        const auto disp15 = Utils::extract32(insn, 16, 15);
        u32 sign_extended_disp15 = Utils::sign_extend32<15>(disp15);
        callback(index_a, sign_extended_disp15, bit_n);
    }
};

struct RcFormatParser {
    u32 insn{};

    template <typename F> void parse(F &&callback) {
        namespace Utils = Tricore::Utils;
        const auto index_a = Utils::extract32(insn, 8, 4);
        const auto index_c = Utils::extract32(insn, 28, 4);
        const auto const9 = Utils::extract32(insn, 12, 9);
        callback(index_a, index_c, const9);
    }
};

struct SrrFormatParser {
    u16 insn{};

    template <typename F> void parse(F &&callback) {
        namespace Utils = Tricore::Utils;
        const auto index_a = Utils::extract16(insn, 8, 4);
        const auto index_b = Utils::extract16(insn, 12, 4);
        callback(index_a, index_b);
    }
};

using SrcFormatParser = SrrFormatParser;
using SsrFormatParser = SrrFormatParser;

struct BrrFormatParser {
    u32 insn{};

    template <typename F> void parse(F &&callback) {
        namespace Utils = Tricore::Utils;
        const auto index_a = Utils::extract32(insn, 8, 4);
        const auto index_b = Utils::extract32(insn, 12, 4);
        const auto disp15 = Utils::extract32(insn, 16, 15);
        u32 sign_extended_disp15 = Utils::sign_extend32<15>(disp15);
        callback(index_a, index_b, sign_extended_disp15);
    }
};

using BrcFormatParser = BrrFormatParser;

struct BFormatParser {
    u32 insn{};

    template <typename F> void parse(F &&callback) {
        namespace Utils = Tricore::Utils;
        u32 disp24 = Utils::extract32(insn, 16, 16);
        disp24 |= Utils::extract32(insn, 8, 8) << 16U;
        u32 sign_extended_disp24 = Utils::sign_extend32<24>(disp24);
        callback(sign_extended_disp24);
    }
};

struct RrpwFormatParser {
    u32 insn{};

    template <typename F> void parse(F &&callback) {
        namespace Utils = Tricore::Utils;
        u32 index_a = Utils::extract32(insn, 8, 4);
        u32 width = Utils::extract32(insn, 16, 5);
        u32 pos = Utils::extract32(insn, 23, 5);
        u32 index_c = Utils::extract32(insn, 28, 4);
        callback(index_a, width, pos, index_c);
    }
};

struct RcpwFormatParser {
    u32 insn{};

    template <typename F> void parse(F &&callback) {
        namespace Utils = Tricore::Utils;
        u32 index_a = Utils::extract32(insn, 8, 4);
        u32 const4 = Utils::extract32(insn, 12, 4);
        u32 width = Utils::extract32(insn, 16, 5);
        u32 pos = Utils::extract32(insn, 23, 5);
        u32 index_c = Utils::extract32(insn, 28, 4);
        callback(index_a, const4, width, pos, index_c);
    }
};

struct AbsFormatParser {
    u32 insn{};

    template <typename F> void parse(F &&callback) {
        namespace Utils = Tricore::Utils;
        u32 index_a = Utils::extract32(insn, 8, 4);
        u32 offset = Utils::extract32(insn, 16, 6);
        offset |= Utils::extract32(insn, 28, 4) << 6U;
        offset |= Utils::extract32(insn, 22, 4) << 10U;
        offset |= Utils::extract32(insn, 12, 4) << 14U;
        callback(index_a, offset);
    }
};

} // anonymous namespace

u32 &Tricore::Cpu::CoreRegisters::operator[](usize offset) {
    switch (offset) {
    case 0xFE00U:
        return pcxi;
    case 0xFE04U:
        return psw;
    case 0xFE08U:
        return pc;
    case 0xFE14U:
        return syscon;
    default:
        throw InvalidCoreRegisterOffset{
            fmt::format("Core register offset 0x{:04X} not handled", offset)};
    }
}

Tricore::Cpu Tricore::Cpu::create_tc33x() {
    Cpu cpu{};
    // pflash0
    cpu.m_memory.add_memory_region(
        Memory::Layout{.size = 2ULL * MiB, .address = 0xA0000000U},
        {0x80000000U});
    // dflash0
    cpu.m_memory.add_memory_region(
        Memory::Layout{.size = 128ULL * KiB, .address = 0xAF000000U});
    // dsram0
    cpu.m_memory.add_memory_region(
        Memory::Layout{.size = 192ULL * KiB, .address = 0x70000000U},
        {0xD0000000U});
    // psram0
    cpu.m_memory.add_memory_region(
        Memory::Layout{.size = 8ULL * KiB, .address = 0x70100000U},
        {0xC0000000U});
    // ucb
    cpu.m_memory.add_memory_region(
        Memory::Layout{.size = 24ULL * KiB, .address = 0xAF400000U});
    // xram
    cpu.m_memory.add_memory_region(
        Memory::Layout{.size = 8ULL * KiB, .address = 0xF0240000U});

    return cpu;
}

void Tricore::Cpu::init(Elf &elf_file) {
    set_program_counter(elf_file.entrypoint());

    const auto sections = elf_file.get_section_headers_with_names();

    for (const auto &[section, name] : sections) {
        const auto data = elf_file.get_section_data(section);
        try {
            if (section.sh_type == Elf::elf_sht_progbits) {
                m_memory.write(data.data(), section.sh_addr, section.sh_size);
                spdlog::debug(
                    "Cpu: initializing memory with content of section {} at "
                    "address 0x{:02X}",
                    name, section.sh_addr);
            } else {
                spdlog::debug(
                    "Section {} is not relevant or has type SHT_NOBITS", name);
            }
        } catch (InvalidMemoryAccess &) {
            spdlog::debug(
                "Cpu: ignoring section {}, address 0x{:02X} not handled", name,
                section.sh_addr);
        }
    }

    m_bus_clients.push_back(&m_memory);
    m_bus_clients.push_back(&m_scu);
    m_bus_clients.push_back(&m_pms);

    // TODO: register other peripherals as bus clients
}

void Tricore::Cpu::start() {
    for (;;) {
        auto insn_opcode = m_memory.peek_at(m_core_registers.pc);
        switch (insn_opcode) {
        case bytecode_lea_bol:
            insn_lea_bol();
            break;
        case bytecode_movha_id:
            insn_movha();
            break;
        case bytecode_ji_sr:
            insn_ji_sr();
            break;
        case bytecode_mov_rlc:
            insn_mov_rlc();
            break;
        case bytecode_mtcr:
            insn_mtcr();
            break;
        case bytecode_isync:
            insn_isync();
            break;
        case bytecode_ldw_slr:
            insn_ldw_slr();
            break;
        case bytecode_add_c2:
            insn_add_c2();
            break;
        case bytecode_ldw_bol:
            insn_ldw_bol();
            break;
        case bytecode_movh:
            insn_movh();
            break;
        case bytecode_and_srr:
            insn_and_srr();
            break;
        case bytecode_jne_brc:
            insn_jne_brc();
            break;
        case bytecode_suba_rr:
            insn_suba_rr();
            break;
        case bytecode_movd_srr:
            insn_movd_srr();
            break;
        case bytecode_stw_bol:
            insn_stw_bol();
            break;
        case bytecode_jli:
            insn_jli();
            break;
        case bytecode_jnzt_brn:
        case bytecode_jnzt_brn_2:
            insn_jnzt_brn();
            break;
        case bytecode_ldbu_bol:
            insn_ldbu_bol();
            break;
        case bytecode_or_rc: {
            u32 insn = read<u32>(m_core_registers.pc);
            const u32 identifier = Utils::extract32(insn, 21U, 7U);
            switch (identifier) {
            case 0x0AU:
                insn_or_rc();
                break;
            case 0x0CU:
                insn_xor_rc();
                break;
            default:
                throw Exception{fmt::format(
                    "OR instruction with identifier 0x{:02X} not implemented",
                    identifier)};
            }
        } break;
        case bytecode_stb_bol:
            insn_stb_bol();
            break;
        case bytecode_jne_brr:
            insn_jne_brr();
            break;
        case bytecode_jltu_brc:
            insn_jltu_brc();
            break;
        case bytecode_nop:
            insn_nop();
            break;
        case bytecode_j_b:
            insn_j_b();
            break;
        case bytecode_jgeu_brc:
            insn_jgeu_brc();
            break;
        case bytecode_extru_rrpw:
            insn_extru_rrpw();
            break;
        case bytecode_sh_src:
            insn_sh_src();
            break;
        case bytecode_insert_rcpw:
            insn_insert_rcpw();
            break;
        case bytecode_or_srr:
            insn_or_srr();
            break;
        case bytecode_stw_ssr:
            insn_stw_ssr();
            break;
        case bytecode_lha_abs:
            insn_lha_abs();
            break;
        case bytecode_ne_rc: {
            const u32 insn = read<u32>(m_core_registers.pc);
            const u32 identifier = Utils::extract32(insn, 21U, 7U);
            switch (identifier) {
            case 0x11U:
                insn_ne_rc();
                break;
            case 0x21U:
                // insn_andne_rc();
                break;
            default:
                throw Exception{
                    fmt::format("NE (RC) instruction with identifier 0x{:02X} "
                                "not implemented",
                                identifier)};
            }
        } break;
        case bytecode_ne_rr: {
            const u32 insn = read<u32>(m_core_registers.pc);
            const u32 identifier = Utils::extract32(insn, 20U, 8U);
            switch (identifier) {
            case 0x11U:
                // insn_ne_rr();
                break;
            case 0x21U:
                insn_andne_rr();
                break;
            default:
                throw Exception{
                    fmt::format("NE (RR) instruction with identifier 0x{:02X} "
                                "not implemented",
                                identifier)};
            }
        } break;
        default:
            throw Exception{
                fmt::format("Instruction with opcode 0x{:02X} not implemented",
                            insn_opcode)};
        }
    }
}

void Tricore::Cpu::insn_movha() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: MOVH.A 0x{:08X}", insn);
    const auto addr_register_index = Utils::extract32(insn, 28, 4);
    const auto msb_half_word = Utils::extract32(insn, 12, 16);
    m_address_registers.at(addr_register_index) = 0U | (msb_half_word << 16U);
    spdlog::trace("==> Cpu: MOVH.A value 0x{:08X} to A[{}]",
                  m_address_registers.at(addr_register_index),
                  addr_register_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_mov_rlc() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: MOV 0x{:08X}", insn);
    const auto data_register_index = Utils::extract32(insn, 28, 4);
    const u32 const16 = Utils::extract32(insn, 12, 16);
    const u32 sign_ext_const16 = Utils::sign_extend32<16>(const16);
    m_data_registers.at(data_register_index) = sign_ext_const16;
    spdlog::trace("==> Cpu: MOV final value 0x{:08X} to D[{}]",
                  m_data_registers.at(data_register_index),
                  data_register_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_lea_bol() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: LEA 0x{:08X}", insn);

    BolFormatParser{insn}.parse(
        [this](u32 addr_index_a, u32 addr_index_b, u32 off16) {
        // EA = A[b] + sign_ext(off16)
        const u32 effective_address =
            m_address_registers.at(addr_index_b) + static_cast<u32>(off16);
        // A[a] = EA[31:0]
        m_address_registers.at(addr_index_a) = effective_address;
        spdlog::trace("==> Cpu: LEA final address 0x{:08X} to A[{}]",
                      effective_address, addr_index_a);
    });
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_ji_sr() {
    const auto insn = read<u16>(m_core_registers.pc);
    spdlog::trace("Cpu: JI 0x{:04X}", insn);
    const auto addr_index = Utils::extract32(insn, 8, 4);
    const auto final_address =
        m_address_registers.at(addr_index) & ((~0U) - 1U);
    spdlog::trace("==> Cpu: JI final address 0x{:08X}", final_address);
    m_core_registers.pc = final_address;
}

void Tricore::Cpu::insn_mtcr() {
    const auto insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: MTCR 0x{:08X}", insn);
    const auto data_index = Utils::extract32(insn, 8, 4);
    const auto const16 = Utils::extract32(insn, 12, 16);
    m_core_registers[const16] = m_data_registers.at(data_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_isync() {
    spdlog::trace("Cpu: ISYNC");
    // do nothing
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_ldw_slr() {
    const auto insn = read<u16>(m_core_registers.pc);
    spdlog::trace("Cpu: LD.W 0x{:04X}", insn);
    const auto addr_index_b = Utils::extract32(insn, 12, 4);
    const auto data_index_c = Utils::extract32(insn, 8, 4);
    m_data_registers.at(data_index_c) =
        read<u32>(m_address_registers.at(addr_index_b));
    spdlog::trace(
        "==> Cpu: LD.W loaded data 0x{:08X} from address 0x{:08X} into D[{}]",
        m_data_registers.at(data_index_c), m_address_registers.at(addr_index_b),
        data_index_c);
    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_ldw_bol() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: LD.W 0x{:08X}", insn);

    BolFormatParser{insn}.parse(
        [this](u32 data_index_a, u32 addr_index_b, u32 off16) {
        // EA = A[b] + sign_ext(off16)
        const u32 effective_address =
            m_address_registers.at(addr_index_b) + off16;
        // D[a] = M(EA, word)
        m_data_registers.at(data_index_a) = read<u32>(effective_address);
        spdlog::trace("==> Cpu: LD.W final value 0x{:08X} to D[{}]",
                      effective_address, data_index_a);
    });

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_add_c2() {
    const auto insn = read<u16>(m_core_registers.pc);
    spdlog::trace("Cpu: ADD 0x{:04X}", insn);
    const auto const4 = Utils::extract32(insn, 12, 4);
    const auto data_index_a = Utils::extract32(insn, 8, 4);
    const u32 sign_extended_const4 = Utils::sign_extend32<4>(const4);
    m_data_registers.at(data_index_a) += sign_extended_const4;
    spdlog::trace("==> Cpu: ADD write value 0x{:08X} in D[{}]",
                  m_data_registers.at(data_index_a), data_index_a);
    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_movh() {
    // D[c] = {const16, 16 h0000}
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: MOVH 0x{:08X}", insn);
    const auto data_register_index = Utils::extract32(insn, 28, 4);
    const auto msb_half_word = Utils::extract32(insn, 12, 16);
    m_data_registers.at(data_register_index) = 0U | (msb_half_word << 16U);
    spdlog::trace("==> Cpu: MOVH value 0x{:08X} to D[{}]",
                  m_data_registers.at(data_register_index),
                  data_register_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_and_srr() {
    const auto insn = read<u16>(m_core_registers.pc);
    spdlog::trace("Cpu: AND 0x{:04X}", insn);

    SrrFormatParser{insn}.parse([this](u32 index_a, u32 index_b) {
        // D[a] = D[a] & D[b]
        m_data_registers.at(index_a) &= m_data_registers.at(index_b);
        spdlog::trace("==> Cpu: AND write value 0x{:08X} in D[{}]",
                      m_data_registers.at(index_a), index_a);
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_jne_brc() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: JNE 0x{:08X}", insn);

    BrcFormatParser{insn}.parse([this](u32 index_a, u32 const4, u32 disp15) {
        // if (D[a] != sign_ext(const4)) then PC = PC + sign_ext(disp15) * 2
        if (m_data_registers.at(index_a) != const4) {
            m_core_registers.pc += disp15 * 2U;
            spdlog::trace("==> Cpu: JNE branch taken PC=0x{:08X}",
                          m_core_registers.pc);
        } else {
            m_core_registers.pc += 4;
            spdlog::trace("==> Cpu: JNE branch NOT taken PC=0x{:08X}",
                          m_core_registers.pc);
        }
    });
}

void Tricore::Cpu::insn_suba_rr() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: SUB.A 0x{:08X}", insn);

    RrFormatParser{insn}.parse([this](u32 index_a, u32 index_b, u32 index_c) {
        // A[c] = A[a] - A[b]
        m_address_registers.at(index_c) =
            m_address_registers.at(index_a) - m_address_registers.at(index_b);
        spdlog::trace("==> Cpu: SUB.A writing value 0x{:08X} in A[{}]",
                      m_address_registers.at(index_c), index_c);
    });
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_movd_srr() {
    // D[a] = A[b]
    const auto insn = read<u16>(m_core_registers.pc);
    spdlog::trace("Cpu: MOV.D 0x{:04X}", insn);

    SrrFormatParser{insn}.parse([this](u32 index_a, u32 index_b) {
        m_data_registers.at(index_a) &= m_address_registers.at(index_b);
        spdlog::trace("==> Cpu: MOV.D write value 0x{:08X} in A[{}]",
                      m_data_registers.at(index_a), index_b);
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_stw_bol() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: ST.W 0x{:08X}", insn);

    BolFormatParser{insn}.parse([this](u32 index_a, u32 index_b, u32 off16) {
        // EA = A[b] + sign_ext(off16)
        const u32 effective_address = m_address_registers.at(index_b) + off16;
        // M(EA, word) = D[a]
        const u32 data = m_data_registers.at(index_a);
        write<u32>(effective_address, data);
        spdlog::trace("==> Cpu: ST.W store word 0x{:08X} to address 0x{:08X}",
                      data, effective_address);
    });

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_jli() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: JLI 0x{:08X}", insn);

    RrFormatParser{insn}.parse([this](u32 index_a, u32, u32) {
        // A[11] = PC + 4
        m_address_registers.at(11) = m_core_registers.pc + 4;
        // PC = {A[a][31:1], 1b0}
        m_core_registers.pc = m_address_registers.at(index_a) & ~0x1U;
        spdlog::trace("==> Cpu: JLI jump to address 0x{:08X}",
                      m_core_registers.pc);
    });
}

void Tricore::Cpu::insn_jnzt_brn() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: JNZ.T 0x{:08X}", insn);

    BrnFormatParser{insn}.parse([this](u32 index_a, u32 disp15, u32 bit_n) {
        const u32 data = m_data_registers.at(index_a);
        if ((data & (1U << bit_n)) != 0U) {
            m_core_registers.pc += disp15 * 2U;
            spdlog::trace("==> Cpu: JNZ.T branch taken, address 0x{:08X}",
                          m_core_registers.pc);
        } else {
            spdlog::trace("==> Cpu: JNZ.T branch NOT taken");
            m_core_registers.pc += 4;
        }
    });
}

void Tricore::Cpu::insn_ldbu_bol() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: LD.BU 0x{:08X}", insn);

    BolFormatParser{insn}.parse([this](u32 index_a, u32 index_b, u32 off16) {
        // EA = A[b] + sign_ext(off16)
        const u32 effective_address = m_address_registers.at(index_b) + off16;
        // D[a] = zero_ext(M(EA, byte))
        m_data_registers.at(index_a) = read<u32>(effective_address) & 0xFFU;
        spdlog::trace("==> Cpu: LD.BU load value 0x{:08X} into D[{}]",
                      m_data_registers.at(index_a), index_a);
    });

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_or_rc() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: OR 0x{:08X}", insn);

    RcFormatParser{insn}.parse([this](u32 index_a, u32 index_c, u32 const9) {
        // D[c] = D[a] | zero_ext(const9)
        m_data_registers.at(index_c) = m_data_registers.at(index_a) | const9;
        spdlog::trace("==> Cpu: OR store result 0x{:08X} into D[{}]",
                      m_data_registers.at(index_c), index_c);
    });

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_stb_bol() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: ST.B 0x{:08X}", insn);

    BolFormatParser{insn}.parse([this](u32 index_a, u32 index_b, u32 off16) {
        // EA = A[b] + sign_ext(off16)
        const u32 effective_address = m_address_registers.at(index_b) + off16;
        // M(EA, byte) = D[a][7:0]
        const u32 data = m_data_registers.at(index_a) & 0xFFU;
        write<u8>(effective_address, static_cast<u8>(data));
        spdlog::trace("==> Cpu: ST.B store byte 0x{:02X} to address 0x{:08X}",
                      data, effective_address);
    });

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_jne_brr() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: JNE 0x{:08X}", insn);

    BrrFormatParser{insn}.parse([this](u32 index_a, u32 index_b, u32 disp15) {
        // if (D[a] != D[b]) then PC = PC + sign_ext(disp15) * 2
        if (m_data_registers.at(index_a) != m_data_registers.at(index_b)) {
            m_core_registers.pc += disp15 * 2U;
            spdlog::trace("==> Cpu: JNE branch taken, address 0x{:08X}",
                          m_core_registers.pc);
        } else {
            m_core_registers.pc += 4U;
            spdlog::trace("==> Cpu: JNE branch NOT taken");
        }
    });
}

void Tricore::Cpu::insn_jltu_brc() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: JLT.U 0x{:08X}", insn);

    BrcFormatParser{insn}.parse([this](u32 index_a, u32 const4, u32 disp15) {
        // if (D[a] < zero_ext(const4)) then { // unsigned comparison
        //   PC = PC + sign_ext(disp15) * 2;
        // }
        if (m_data_registers.at(index_a) < const4) {
            m_core_registers.pc += disp15 * 2U;
            spdlog::trace("==> Cpu: JLT.U branch taken, address 0x{:08X}",
                          m_core_registers.pc);
        } else {
            m_core_registers.pc += 4U;
            spdlog::trace("==> Cpu: JLT.U branch NOT taken");
        }
    });
}

void Tricore::Cpu::insn_j_b() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: J 0x{:08X}", insn);

    BFormatParser{insn}.parse([this](u32 disp24) {
        // PC = PC + sign_ext(disp24) * 2
        m_core_registers.pc += disp24 * 2U;
        spdlog::trace("==> Cpu: J uncoditional to address 0x{:08X}",
                      m_core_registers.pc);
    });
}

void Tricore::Cpu::insn_nop() {
    spdlog::trace("Cpu: NOP");
    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_jgeu_brc() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: JGE.U 0x{:08X}", insn);

    BrcFormatParser{insn}.parse([this](u32 index_a, u32 const4, u32 disp15) {
        // if (D[a] >= zero_ext(const4)) then { // unsigned comparison
        // PC = PC + sign_ext(disp15) * 2;
        // }
        if (m_data_registers.at(index_a) >= const4) {
            m_core_registers.pc += disp15 * 2U;
            spdlog::trace("==> Cpu: JGE.U branch taken, address 0x{:08X}",
                          m_core_registers.pc);
        } else {
            m_core_registers.pc += 4U;
            spdlog::trace("==> Cpu: JGE.U branch NOT taken");
        }
    });
}

void Tricore::Cpu::insn_extru_rrpw() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: EXTR.U 0x{:08X}", insn);

    RrpwFormatParser{insn}.parse(
        [this](u32 index_a, u32 width, u32 pos, u32 index_c) {
        // D[c] = zero_ext((D[a] >> pos)[width-1:0]);
        // If pos + width > 32 or if width = 0, then the results are undefined.
        const u32 result =
            Utils::extract32(m_data_registers.at(index_a), pos, width);
        m_data_registers.at(index_c) = result;
        spdlog::trace("==> Cpu: EXTR.U extracted value 0x{:08X} from D[{}]",
                      m_data_registers.at(index_c), index_a);
    });

    m_core_registers.pc += 4U;
}

void Tricore::Cpu::insn_sh_src() {
    u16 insn = read<u16>(m_core_registers.pc);
    spdlog::trace("Cpu: SH 0x{:04X}", insn);

    SrcFormatParser{insn}.parse([this](u32 index_a, u32 const4) {
        // shift_count = sign_ext(const4[3:0]);
        // D[a] = (shift_count >= 0) ? D[a] << shift_count : D[a] >>
        // (-shift_count);
        const i32 sign_extended_const4 =
            static_cast<i32>(Utils::sign_extend32<4>(const4));
        if (sign_extended_const4 >= 0) {
            spdlog::trace("==> Cpu: SH shift left by {} value 0x{:08X}",
                          sign_extended_const4, m_data_registers.at(index_a));
            m_data_registers.at(index_a) =
                m_data_registers.at(index_a)
                << static_cast<u32>(sign_extended_const4);
        } else {
            spdlog::trace("==> Cpu: SH shift right by {} value 0x{:08X}",
                          -sign_extended_const4, m_data_registers.at(index_a));
            m_data_registers.at(index_a) =
                m_data_registers.at(index_a) >>
                static_cast<u32>(-sign_extended_const4);
        }
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_xor_rc() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: XOR 0x{:08X}", insn);

    RcFormatParser{insn}.parse([this](u32 index_a, u32 index_c, u32 const9) {
        // D[c] = D[a] ^ zero_ext(const9)
        m_data_registers.at(index_c) = m_data_registers.at(index_a) ^ const9;
        spdlog::trace("==> Cpu: XOR store result 0x{:08X} into D[{}]",
                      m_data_registers.at(index_c), index_c);
    });

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_insert_rcpw() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: INSERT 0x{:08X}", insn);

    RcpwFormatParser{insn}.parse(
        [this](u32 index_a, u32 const4, u32 width, u32 pos, u32 index_c) {
        // mask = (2width -1) << pos;
        // D[c] = (D[a] & ~mask) | ((zero_ext(const4) << pos) & mask);
        // If pos + width > 32, then the result is undefined.

        spdlog::trace("==> Cpu: INSERT value 0x{:02X} at position {} with "
                      "length {} into D[{}]",
                      const4, pos, width, index_c);
        m_data_registers.at(index_c) =
            Utils::deposit32(const4, pos, width, m_data_registers.at(index_a));
    });

    m_core_registers.pc += 4U;
}

void Tricore::Cpu::insn_or_srr() {
    const auto insn = read<u16>(m_core_registers.pc);
    spdlog::trace("Cpu: OR 0x{:04X}", insn);

    SrrFormatParser{insn}.parse([this](u32 index_a, u32 index_b) {
        // D[a] = D[a] | D[b]
        m_data_registers.at(index_a) |= m_data_registers.at(index_b);
        spdlog::trace("==> Cpu: OR write value 0x{:08X} in D[{}]",
                      m_data_registers.at(index_a), index_a);
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_stw_ssr() {
    const auto insn = read<u16>(m_core_registers.pc);
    spdlog::trace("Cpu: ST.W 0x{:04X}", insn);

    SsrFormatParser{insn}.parse([this](u32 index_a, u32 index_b) {
        //  M(A[b], word) = D[a]
        u32 output = m_data_registers.at(index_a);
        write<u32>(m_address_registers.at(index_b), output);
        spdlog::trace("==> Cpu: ST.W store value 0x{:08X} at address 0x{:08X}",
                      output, m_address_registers.at(index_b));
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_lha_abs() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: LHA 0x{:08X}", insn);

    AbsFormatParser{insn}.parse([this](u32 index_a, u32 offset) {
        // EA = {off18[17:0], 14b'0};
        // A[a] = EA[31:0];

        const u32 effective_address = (offset & 0x3FFFFU) << 14U;
        spdlog::trace("==> Cpu: LHA loaded address 0x{:08X} into A[{}]",
                      effective_address, index_a);
        m_address_registers.at(index_a) = effective_address;
    });

    m_core_registers.pc += 4U;
}

void Tricore::Cpu::insn_ne_rc() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: NE 0x{:08X}", insn);

    RcFormatParser{insn}.parse([this](u32 index_a, u32 index_c, u32 const9) {
        // result = (D[a] != sign_ext(const9));
        // D[c] = zero_ext(result);
        m_data_registers.at(index_c) = m_data_registers.at(index_a) | const9;
        const u32 sign_extended_const9 = Utils::sign_extend32<9>(const9);
        if (m_data_registers.at(index_a) != sign_extended_const9) {
            m_data_registers.at(index_c) = 0x1U;
        } else {
            m_data_registers.at(index_c) = 0;
        }
        spdlog::trace("==> Cpu: NE store result 0x{:08X} into D[{}]",
                      m_data_registers.at(index_c), index_c);
    });

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_andne_rr() {
    u32 insn = read<u32>(m_core_registers.pc);
    spdlog::trace("Cpu: AND.NE 0x{:08X}", insn);

    RrFormatParser{insn}.parse([this](u32 index_a, u32 index_b, u32 index_c) {
        // D[c] = {D[c][31:1], D[c][0] AND (D[a] != D[b])};
        if (m_data_registers.at(index_a) != m_data_registers.at(index_b)) {
            m_data_registers.at(index_c) |= 0x1U;
        } else {
            m_data_registers.at(index_c) &= ~1U;
        }
        spdlog::trace("==> Cpu: AND.NE writing value 0x{:08X} in D[{}]",
                      m_data_registers.at(index_c), index_c);
    });
    m_core_registers.pc += 4;
}