#include "Cpu/Cpu.hpp"
#include "Cpu/InstructionFormat.hpp"
#include "Error.hpp"
#include "Types.hpp"
#include "Utils.hpp"

#include <fmt/base.h>
#include <gsl/assert>
#include <spdlog/spdlog.h>

#include <concepts>

namespace {

constexpr byte bytecode_movha_id = byte { 0x91 };
constexpr byte bytecode_mov_rlc = byte { 0x3B };
constexpr byte bytecode_lea_bol = byte { 0xD9 };
constexpr byte bytecode_ji_sr = byte { 0xDC };
constexpr byte bytecode_mtcr = byte { 0xCD };
constexpr byte bytecode_mfcr = byte { 0x4D };
constexpr byte bytecode_sync = byte { 0x0D };
constexpr byte bytecode_ldw_slr = byte { 0x54 };
constexpr byte bytecode_ldw_bol = byte { 0x19 };
constexpr byte bytecode_add_c2 = byte { 0xC2 };
constexpr byte bytecode_movh = byte { 0x7B };
constexpr byte bytecode_and_srr = byte { 0x26 };
constexpr byte bytecode_jump_df = byte { 0xDF };
constexpr byte bytecode_01 = byte { 0x01 };
constexpr byte bytecode_movd_srr = byte { 0x80 };
constexpr byte bytecode_stw_bol = byte { 0x59 };
constexpr byte bytecode_jli = byte { 0x2D };
constexpr byte bytecode_jnzt_brn = byte { 0x6F };
constexpr byte bytecode_jnzt_brn_2 = byte { 0xEF };
constexpr byte bytecode_ldbu_bol = byte { 0x39 };
constexpr byte bytecode_8f_rc = byte { 0x8F };
constexpr byte bytecode_stb_bol = byte { 0xE9 };
constexpr byte bytecode_jump_5f = byte { 0x5F };
constexpr byte bytecode_jltu_brc = byte { 0xBF };
constexpr byte bytecode_00 = byte { 0x00 };
constexpr byte bytecode_j_b = byte { 0x1D };
constexpr byte bytecode_jgeu_brc = byte { 0xFF };
constexpr byte bytecode_extru_rrpw = byte { 0x37 };
constexpr byte bytecode_sh_src = byte { 0x06 };
constexpr byte bytecode_insert_rcpw = byte { 0xB7 };
constexpr byte bytecode_or_srr = byte { 0xA6 };
constexpr byte bytecode_stw_ssr = byte { 0x74 };
constexpr byte bytecode_lha_abs = byte { 0xC5 };
constexpr byte bytecode_8b_rc = byte { 0x8B };
constexpr byte bytecode_0b_rr = byte { 0x0B };
constexpr byte bytecode_addi_rlc = byte { 0x1B };
constexpr byte bytecode_mov_src = byte { 0x82 };
constexpr byte bytecode_mova_src = byte { 0xA0 };
constexpr byte bytecode_call_32 = byte { 0x6D };
constexpr byte bytecode_mova_srr = byte { 0x60 };
constexpr byte bytecode_mov_srr = byte { 0x02 };
constexpr byte bytecode_movaa_srr = byte { 0x40 };
constexpr byte bytecode_suba_sc = byte { 0x20 };
constexpr byte bytecode_sth_bol = byte { 0xF9 };
constexpr byte bytecode_sta_bol = byte { 0xB5 };
constexpr byte bytecode_ldhu_bol = byte { 0xB9 };
constexpr byte bytecode_lda_bol = byte { 0x99 };
constexpr byte bytecode_ldh_bol = byte { 0xC9 };
constexpr byte bytecode_movu_rlc = byte { 0xBB };
constexpr byte bytecode_not_sr = byte { 0x46 };
constexpr byte bytecode_4b = byte { 0x4B };

constexpr u32 cpu_psw_cde_mask = (1U << 7U);

struct SrrFormatParser {
    u16 insn {};

    template<std::invocable<u32, u32> F>
    void parse(F&& callback)
    {
        namespace Utils = Tricore::Utils;
        const auto index_a = Utils::extract16(insn, 8, 4);
        const auto index_b = Utils::extract16(insn, 12, 4);
        callback(index_a, index_b);
    }
};

using SrcFormatParser = SrrFormatParser;
using SsrFormatParser = SrrFormatParser;

struct ScFormatParser {
    u16 insn {};

    template<std::invocable<u32> F>
    void parse(F&& callback)
    {
        namespace Utils = Tricore::Utils;
        const auto const8 = Utils::extract16(insn, 8, 8);
        callback(const8);
    }
};

struct BrrFormatParser {
    u32 insn {};

    template<std::invocable<u32, u32, u32> F>
    void parse(F&& callback)
    {
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
    u32 insn {};

    template<std::invocable<u32> F>
    void parse(F&& callback)
    {
        namespace Utils = Tricore::Utils;
        u32 disp24 = Utils::extract32(insn, 16, 16);
        disp24 |= Utils::extract32(insn, 8, 8) << 16U;
        u32 sign_extended_disp24 = Utils::sign_extend32<24>(disp24);
        callback(sign_extended_disp24);
    }
};

struct RrpwFormatParser {
    u32 insn {};

    template<std::invocable<u32, u32, u32, u32> F>
    void parse(F&& callback)
    {
        namespace Utils = Tricore::Utils;
        u32 index_a = Utils::extract32(insn, 8, 4);
        u32 width = Utils::extract32(insn, 16, 5);
        u32 pos = Utils::extract32(insn, 23, 5);
        u32 index_c = Utils::extract32(insn, 28, 4);
        callback(index_a, width, pos, index_c);
    }
};

struct RcpwFormatParser {
    u32 insn {};

    template<std::invocable<u32, u32, u32, u32, u32> F>
    void parse(F&& callback)
    {
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
    u32 insn {};

    template<std::invocable<u32, u32> F>
    void parse(F&& callback)
    {
        namespace Utils = Tricore::Utils;
        u32 index_a = Utils::extract32(insn, 8, 4);
        u32 offset = Utils::extract32(insn, 16, 6);
        offset |= Utils::extract32(insn, 28, 4) << 6U;
        offset |= Utils::extract32(insn, 22, 4) << 10U;
        offset |= Utils::extract32(insn, 12, 4) << 14U;
        callback(index_a, offset);
    }
};

struct RlcFormatParser {
    u32 insn {};

    template<std::invocable<u32, u32, u32> F>
    void parse(F&& callback)
    {
        namespace Utils = Tricore::Utils;
        const auto index_a = Utils::extract32(insn, 8, 4);
        const auto index_c = Utils::extract32(insn, 28, 4);
        const auto const16 = Utils::extract32(insn, 12, 16);
        callback(index_a, index_c, const16);
    }
};

} // anonymous namespace

Tricore::Cpu::Cpu(Bus& bus)
    : m_bus(bus.create_request_handler())
{
}

u32& Tricore::Cpu::DataRegisters::operator[](usize offset)
{
    switch (offset) {
    case 0:
        return d0;
    case 1:
        return d1;
    case 2:
        return d2;
    case 3:
        return d3;
    case 4:
        return d4;
    case 5:
        return d5;
    case 6:
        return d6;
    case 7:
        return d7;
    case 8:
        return d8;
    case 9:
        return d9;
    case 10:
        return d10;
    case 11:
        return d11;
    case 12:
        return d12;
    case 13:
        return d13;
    case 14:
        return d14;
    case 15:
        return d15;
    default:
        throw InvalidRegisterOffset {
            fmt::format("Data register offset {} not handled", offset)
        };
    }
}

u32& Tricore::Cpu::AddressRegisters::operator[](usize offset)
{
    switch (offset) {
    case 0:
        return a0;
    case 1:
        return a1;
    case 2:
        return a2;
    case 3:
        return a3;
    case 4:
        return a4;
    case 5:
        return a5;
    case 6:
        return a6;
    case 7:
        return a7;
    case 8:
        return a8;
    case 9:
        return a9;
    case 10:
        return a10;
    case 11:
        return a11;
    case 12:
        return a12;
    case 13:
        return a13;
    case 14:
        return a14;
    case 15:
        return a15;
    default:
        throw InvalidRegisterOffset {
            fmt::format("Address register offset {} not handled", offset)
        };
    }
}

u32& Tricore::Cpu::CoreRegisters::operator[](usize offset)
{
    switch (offset) {
    case 0xFE00U:
        return pcxi;
    case 0xFE04U:
        return psw;
    case 0xFE08U:
        return pc;
    case 0xFE14U:
        return syscon;
    case 0xFE1CU:
        return core_id;
    case 0xFE38U:
        return fcx;
    case 0xFE3CU:
        return lcx;
    default:
        throw InvalidRegisterOffset {
            fmt::format("Core register offset 0x{:04X} not handled", offset)
        };
    }
}

void Tricore::Cpu::initialize_program(Elf& elf_file)
{
    set_program_counter(elf_file.entrypoint());

    const auto sections = elf_file.get_section_headers_with_names();

    for (const auto& [section, name] : sections) {
        const auto elf_data = elf_file.get_section_data(section);
        try {
            if (section.sh_type == Elf::elf_sht_progbits) {
                m_bus.write(gsl::make_span(elf_data), section.sh_addr);
                spdlog::debug(
                    "Cpu: initializing memory with content of section {} at "
                    "address 0x{:02X}",
                    name, section.sh_addr);
            } else {
                spdlog::debug(
                    "Section {} is not relevant or has type SHT_NOBITS", name);
            }
        } catch (InvalidMemoryAccess&) {
            spdlog::debug(
                "Cpu: ignoring section {}, address 0x{:02X} not handled", name,
                section.sh_addr);
        }
    }
}

void Tricore::Cpu::start()
{
    for (;;) {
        auto insn_opcode = m_bus.read8(m_core_registers.pc);
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
        case bytecode_mfcr:
            insn_mfcr();
            break;
        case bytecode_sync: {
            const u32 insn = m_bus.read32(m_core_registers.pc);
            const u32 identifier = Utils::extract32(insn, 22, 6);
            switch (identifier) {
            case 0x12U:
                insn_dsync();
                break;
            case 0x13U:
                insn_isync();
                break;
            default:
                fail(fmt::format(
                    "0x{:02X} opcode with identifier 0x{:02X} not implemented",
                    insn, identifier));
            }
        } break;
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
        case bytecode_jump_df: {
            u32 insn = m_bus.read32(m_core_registers.pc);
            const u32 identifier = Utils::extract32(insn, 31U, 1U);
            switch (identifier) {
            case 0x0U:
                insn_jeq_brc();
                break;
            case 0x1U:
                insn_jne_brc();
                break;
            default:
                fail(fmt::format(
                    "0x{:02X} opcode with identifier 0x{:02X} not implemented",
                    bytecode_jump_df, identifier));
            }
        } break;
        case bytecode_01: {
            u32 insn = m_bus.read32(m_core_registers.pc);
            const u32 identifier = Utils::extract32(insn, 20U, 8U);
            switch (identifier) {
            case 0x02U:
                insn_suba_rr();
                break;
            case 0x60U:
                insn_addsca_rr();
                break;
            case 0x01U:
                // ADD.A (RR)
            default:
                fail(fmt::format(
                    "0x{:02X} opcode with identifier 0x{:02X} not implemented",
                    bytecode_01, identifier));
            }
        } break;
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
        case bytecode_8f_rc: {
            u32 insn = m_bus.read32(m_core_registers.pc);
            const u32 identifier = Utils::extract32(insn, 21U, 7U);
            switch (identifier) {
            case 0x0AU:
                insn_or_rc();
                break;
            case 0x0CU:
                insn_xor_rc();
                break;
            case 0x0U:
                insn_sh_rc();
                break;
            case 0x08U:
                insn_and_rc();
                break;
            case 0x0EU:
                insn_andn_rc();
                break;
            default:
                fail(fmt::format(
                    "0x{:02X} opcode with identifier 0x{:02X} not implemented",
                    bytecode_8f_rc, identifier));
            }
        } break;
        case bytecode_stb_bol:
            insn_stb_bol();
            break;
        case bytecode_jump_5f: {
            u32 insn = m_bus.read32(m_core_registers.pc);
            const u32 identifier = Utils::extract32(insn, 31U, 1U);
            switch (identifier) {
            case 0x0U:
                insn_jeq_brr();
                break;
            case 0x1U:
                insn_jne_brr();
                break;
            default:
                fail(fmt::format(
                    "0x{:02X} opcode with identifier 0x{:02X} not implemented",
                    bytecode_jump_5f, identifier));
            }
        } break;
        case bytecode_jltu_brc:
            insn_jltu_brc();
            break;
        case bytecode_00: {
            const u16 insn = m_bus.read16(m_core_registers.pc);
            const u32 identifier = Utils::extract32(insn, 12U, 4U);
            switch (identifier) {
            case 0x00U:
                insn_nop();
                break;
            case 0x09U:
                // TODO: implement RET
                insn_ret_sr();
                break;
            default:
                fail(fmt::format("0x00 instruction with identifier 0x{:02X} "
                                 "not implemented",
                    identifier));
            }
        } break;
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
        case bytecode_8b_rc: {
            const u32 insn = m_bus.read32(m_core_registers.pc);
            const u32 identifier = Utils::extract32(insn, 21U, 7U);
            switch (identifier) {
            case 0x11U:
                insn_ne_rc();
                break;
            case 0x21U:
                insn_andne_rc();
                break;
            default:
                fail(fmt::format(
                    "0x8B (RC) instruction with identifier 0x{:02X} "
                    "not implemented",
                    identifier));
            }
        } break;
        case bytecode_0b_rr: {
            const u32 insn = m_bus.read32(m_core_registers.pc);
            const u32 identifier = Utils::extract32(insn, 20U, 8U);
            switch (identifier) {
            case 0x21U:
                insn_andne_rr();
                break;
            case 0x11U:
                insn_ne_rr();
                break;
            case 0x19U:
                insn_minu_rr();
                break;
            case 0x08U:
                insn_sub_rr();
                break;
            default:
                fail(fmt::format(
                    "0x0B (RR) instruction with identifier 0x{:02X} "
                    "not implemented",
                    identifier));
            }
        } break;
        case bytecode_addi_rlc:
            insn_addi_rlc();
            break;
        case bytecode_mov_src:
            insn_mov_src();
            break;
        case bytecode_mova_src:
            insn_mova_src();
            break;
        case bytecode_call_32:
            insn_call_32();
            break;
        case bytecode_mova_srr:
            insn_mova_srr();
            break;
        case bytecode_mov_srr:
            insn_mov_srr();
            break;
        case bytecode_movaa_srr:
            insn_movaa_srr();
            break;
        case bytecode_suba_sc:
            insn_suba_sc();
            break;
        case bytecode_sth_bol:
            insn_sth_bol();
            break;
        case bytecode_sta_bol:
            insn_sta_bol();
            break;
        case bytecode_ldhu_bol:
            insn_ldhu_bol();
            break;
        case bytecode_lda_bol:
            insn_lda_bol();
            break;
        case bytecode_ldh_bol:
            insn_ldh_bol();
            break;
        case bytecode_movu_rlc:
            insn_movu_rlc();
            break;
        case bytecode_not_sr:
            insn_not_sr();
            break;
        case bytecode_4b: {
            const u32 insn = m_bus.read32(m_core_registers.pc);
            const u32 identifier = Utils::extract32(insn, 20U, 8U);
            switch (identifier) {
            case 0x21U:
                insn_divu_rr();
                break;
            case 0x16U:
                insn_utof_rr();
                break;
            default:
                fail(fmt::format(
                    "0x4B (RR) instruction with identifier 0x{:02X} "
                    "not implemented",
                    identifier));
            }
        } break;
        default:
            fail(fmt::format("Instruction with opcode 0x{:02X} not implemented",
                insn_opcode));
        }
    }
}

void Tricore::Cpu::insn_movha()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: MOVH.A 0x{:08X}", insn);
    const auto addr_register_index = Utils::extract32(insn, 28, 4);
    const auto msb_half_word = Utils::extract32(insn, 12, 16);
    m_addr_reg[addr_register_index] = 0U | (msb_half_word << 16U);
    spdlog::trace("==> Cpu: MOVH.A value 0x{:08X} to A[{}]",
        m_addr_reg[addr_register_index],
        addr_register_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_mov_rlc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: MOV 0x{:08X}", insn);

    RlcFormatParser { insn }.parse([this](u32, u32 index_c, u32 const16) {
        const u32 sign_ext_const16 = Utils::sign_extend32<16>(const16);
        m_data_reg[index_c] = sign_ext_const16;
        spdlog::trace("==> Cpu: MOV final value 0x{:08X} to D[{}]",
            m_data_reg[index_c], index_c);
    });

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_movu_rlc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: MOV.U 0x{:08X}", insn);

    RlcFormatParser { insn }.parse([this](u32, u32 index_c, u32 const16) {
        // D[c] = zero_ext(const16);
        m_data_reg[index_c] = const16;
        spdlog::trace("==> Cpu: MOV.U final value 0x{:08X} to D[{}]",
            m_data_reg[index_c], index_c);
    });

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_lea_bol()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: LEA 0x{:08X}", insn);

    InstructionFormat::Bol format { insn };
    // EA = A[b] + sign_ext(off16)
    u32 effective_address = m_addr_reg[format.b] + Utils::sign_extend32<16>(format.off16);
    // A[a] = EA[31:0]
    m_addr_reg[format.a] = effective_address;
    spdlog::trace("==> Cpu: LEA final address 0x{:08X} to A[{}]",
        effective_address, format.a);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_ji_sr()
{
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: JI 0x{:04X}", insn);
    const auto addr_index = Utils::extract32(insn, 8, 4);
    const auto final_address = m_addr_reg[addr_index] & ((~0U) - 1U);
    spdlog::trace("==> Cpu: JI final address 0x{:08X}", final_address);
    m_core_registers.pc = final_address;
}

void Tricore::Cpu::insn_not_sr()
{
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: NOT 0x{:04X}", insn);
    const auto index_a = Utils::extract32(insn, 8, 4);
    m_data_reg[index_a] = ~m_data_reg[index_a];
    spdlog::trace("==> Cpu: NOT result 0x{:08X}", m_data_reg[index_a]);
    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_mtcr()
{
    const auto insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: MTCR 0x{:08X}", insn);
    RlcFormatParser { insn }.parse([this](u32 index_a, u32, u32 const16) {
        // CR[const16] = D[a];
        m_core_registers[const16] = m_data_reg[index_a];
    });
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_mfcr()
{
    const auto insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: MFCR 0x{:08X}", insn);

    RlcFormatParser { insn }.parse([this](u32, u32 index_c, u32 const16) {
        // D[c] = CR[const16];
        m_data_reg[index_c] = m_core_registers[const16];
    });
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_isync()
{
    spdlog::trace("Cpu: ISYNC");
    // do nothing
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_dsync()
{
    spdlog::trace("Cpu: DSYNC");
    // do nothing
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_ldw_slr()
{
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: LD.W 0x{:04X}", insn);
    const auto addr_index_b = Utils::extract32(insn, 12, 4);
    const auto data_index_c = Utils::extract32(insn, 8, 4);
    m_data_reg[data_index_c] = m_bus.read32(m_addr_reg[addr_index_b]);
    spdlog::trace(
        "==> Cpu: LD.W loaded data 0x{:08X} from address 0x{:08X} into D[{}]",
        m_data_reg[data_index_c], m_addr_reg[addr_index_b],
        data_index_c);
    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_ldw_bol()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: LD.W 0x{:08X}", insn);

    InstructionFormat::Bol format { insn };
    // EA = A[b] + sign_ext(off16)
    u32 effective_address = m_addr_reg[format.b] + Utils::sign_extend32<16>(format.off16);
    // D[a] = M(EA, word)
    m_data_reg[format.a] = m_bus.read32(effective_address);
    spdlog::trace("==> Cpu: LD.W final value 0x{:08X} to D[{}]",
        effective_address, format.a);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_add_c2()
{
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: ADD 0x{:04X}", insn);
    const auto const4 = Utils::extract32(insn, 12, 4);
    const auto data_index_a = Utils::extract32(insn, 8, 4);
    const u32 sign_extended_const4 = Utils::sign_extend32<4>(const4);
    m_data_reg[data_index_a] += sign_extended_const4;
    spdlog::trace("==> Cpu: ADD write value 0x{:08X} in D[{}]",
        m_data_reg[data_index_a], data_index_a);
    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_movh()
{
    // D[c] = {const16, 16 h0000}
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: MOVH 0x{:08X}", insn);
    const auto data_register_index = Utils::extract32(insn, 28, 4);
    const auto msb_half_word = Utils::extract32(insn, 12, 16);
    m_data_reg[data_register_index] = 0U | (msb_half_word << 16U);
    spdlog::trace("==> Cpu: MOVH value 0x{:08X} to D[{}]",
        m_data_reg[data_register_index],
        data_register_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_and_srr()
{
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: AND 0x{:04X}", insn);

    SrrFormatParser { insn }.parse([this](u32 index_a, u32 index_b) {
        // D[a] = D[a] & D[b]
        m_data_reg[index_a] &= m_data_reg[index_b];
        spdlog::trace("==> Cpu: AND write value 0x{:08X} in D[{}]",
            m_data_reg[index_a], index_a);
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_jne_brc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: JNE 0x{:08X}", insn);

    BrcFormatParser { insn }.parse([this](u32 index_a, u32 const4, u32 disp15) {
        // if (D[a] != sign_ext(const4)) then PC = PC + sign_ext(disp15) * 2
        if (m_data_reg[index_a] != const4) {
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

void Tricore::Cpu::insn_jeq_brc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: JEQ 0x{:08X}", insn);

    BrcFormatParser { insn }.parse([this](u32 index_a, u32 const4, u32 disp15) {
        // if (D[a] == sign_ext(const4)) then PC = PC + sign_ext(disp15) * 2
        if (m_data_reg[index_a] == const4) {
            m_core_registers.pc += disp15 * 2U;
            spdlog::trace("==> Cpu: JEQ branch taken PC=0x{:08X}",
                m_core_registers.pc);
        } else {
            m_core_registers.pc += 4;
            spdlog::trace("==> Cpu: JEQ branch NOT taken PC=0x{:08X}",
                m_core_registers.pc);
        }
    });
}

void Tricore::Cpu::insn_suba_rr()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: SUB.A 0x{:08X}", insn);

    InstructionFormat::Rr parser { insn };
    // A[c] = A[a] - A[b]
    m_addr_reg[parser.c] = m_addr_reg[parser.a] - m_addr_reg[parser.b];
    spdlog::trace("==> Cpu: SUB.A writing value 0x{:08X} in A[{}]",
        m_addr_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_addsca_rr()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: ADDSC.A 0x{:08X}", insn);

    const u32 n_value = Utils::extract32(insn, 16, 2);
    InstructionFormat::Rr parser { insn };

    // A[c] = A[b] + (D[a] << n);
    const u32 shifted_data = m_data_reg[parser.a] << n_value;
    m_addr_reg[parser.c] = m_addr_reg[parser.b] + shifted_data;
    spdlog::trace("==> Cpu: ADDSC.A writing value 0x{:08X} in A[{}]",
        m_addr_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_movd_srr()
{
    // D[a] = A[b]
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: MOV.D 0x{:04X}", insn);

    SrrFormatParser { insn }.parse([this](u32 index_a, u32 index_b) {
        m_data_reg[index_a] = m_addr_reg[index_b];
        spdlog::trace("==> Cpu: MOV.D write value 0x{:08X} in D[{}]",
            m_data_reg[index_a], index_a);
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_stw_bol()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: ST.W 0x{:08X}", insn);

    InstructionFormat::Bol format { insn };
    // EA = A[b] + sign_ext(off16)
    u32 effective_address = m_addr_reg[format.b] + Utils::sign_extend32<16>(format.off16);
    // M(EA, word) = D[a]
    u32 data = m_data_reg[format.a];
    m_bus.write32(data, effective_address);
    spdlog::trace("==> Cpu: ST.W store word 0x{:08X} to address 0x{:08X}",
        data, effective_address);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_jli()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: JLI 0x{:08X}", insn);

    InstructionFormat::Rr parser { insn };

    // A[11] = PC + 4
    m_addr_reg.a11 = m_core_registers.pc + 4;
    // PC = {A[a][31:1], 1b0}
    m_core_registers.pc = m_addr_reg[parser.a] & ~0x1U;
    spdlog::trace("==> Cpu: JLI jump to address 0x{:08X}",
        m_core_registers.pc);
}

void Tricore::Cpu::insn_jnzt_brn()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: JNZ.T 0x{:08X}", insn);

    InstructionFormat::Brn parser { insn };

    const u32 data = m_data_reg[parser.a];
    if ((data & (1U << parser.n)) != 0U) {
        m_core_registers.pc += Utils::sign_extend32<15>(parser.disp15) * 2U;
        spdlog::trace("==> Cpu: JNZ.T branch taken PC=0x{:08X}",
            m_core_registers.pc);
    } else {
        spdlog::trace("==> Cpu: JNZ.T branch NOT taken PC=0x{:08X}",
            m_core_registers.pc);
        m_core_registers.pc += 4;
    }
}

void Tricore::Cpu::insn_ldbu_bol()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: LD.BU 0x{:08X}", insn);

    InstructionFormat::Bol format { insn };
    // EA = A[b] + sign_ext(off16)
    u32 effective_address = m_addr_reg[format.b] + Utils::sign_extend32<16>(format.off16);
    // D[a] = zero_ext(M(EA, byte))
    m_data_reg[format.a] = m_bus.read32(effective_address) & 0xFFU;
    spdlog::trace("==> Cpu: LD.BU load value 0x{:08X} into D[{}]",
        m_data_reg[format.a], format.a);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_or_rc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: OR 0x{:08X}", insn);

    InstructionFormat::Rc parser { insn };

    // D[c] = D[a] | zero_ext(const9)
    m_data_reg[parser.c] = m_data_reg[parser.a] | parser.const9;
    spdlog::trace("==> Cpu: OR store result 0x{:08X} into D[{}]",
        m_data_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_and_rc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: AND 0x{:08X}", insn);

    InstructionFormat::Rc parser { insn };

    // D[c] = D[a] & zero_ext(const9);
    m_data_reg[parser.c] = m_data_reg[parser.a] & parser.const9;
    spdlog::trace("==> Cpu: AND store result 0x{:08X} into D[{}]",
        m_data_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_andn_rc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: ANDN 0x{:08X}", insn);

    InstructionFormat::Rc parser { insn };

    // D[c] = D[a] & ~zero_ext(const9);
    m_data_reg[parser.c] = m_data_reg[parser.a] & ~parser.const9;
    spdlog::trace("==> Cpu: ANDN store result 0x{:08X} into D[{}]",
        m_data_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_stb_bol()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: ST.B 0x{:08X}", insn);

    InstructionFormat::Bol format { insn };
    // EA = A[b] + sign_ext(off16)
    u32 effective_address = m_addr_reg[format.b] + Utils::sign_extend32<16>(format.off16);
    // M(EA, byte) = D[a][7:0]
    const u32 data = m_data_reg[format.a] & 0xFFU;
    m_bus.write8(static_cast<u8>(data), effective_address);
    spdlog::trace("==> Cpu: ST.B store byte 0x{:02X} to address 0x{:08X}",
        data, effective_address);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_jne_brr()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: JNE 0x{:08X}", insn);

    BrrFormatParser { insn }.parse([this](u32 index_a, u32 index_b, u32 disp15) {
        // if (D[a] != D[b]) then PC = PC + sign_ext(disp15) * 2
        if (m_data_reg[index_a] != m_data_reg[index_b]) {
            m_core_registers.pc += disp15 * 2U;
            spdlog::trace("==> Cpu: JNE branch taken PC=0x{:08X}",
                m_core_registers.pc);
        } else {
            m_core_registers.pc += 4U;
            spdlog::trace("==> Cpu: JNE branch NOT taken PC=0x{:08X}",
                m_core_registers.pc);
        }
    });
}

void Tricore::Cpu::insn_jeq_brr()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: JEQ 0x{:08X}", insn);

    BrrFormatParser { insn }.parse([this](u32 index_a, u32 index_b, u32 disp15) {
        // if (D[a] == D[b]) then PC = PC + sign_ext(disp15) * 2
        if (m_data_reg[index_a] == m_data_reg[index_b]) {
            m_core_registers.pc += disp15 * 2U;
            spdlog::trace("==> Cpu: JEQ branch taken PC=0x{:08X}",
                m_core_registers.pc);
        } else {
            m_core_registers.pc += 4U;
            spdlog::trace("==> Cpu: JEQ branch NOT taken PC=0x{:08X}",
                m_core_registers.pc);
        }
    });
}

void Tricore::Cpu::insn_jltu_brc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: JLT.U 0x{:08X}", insn);

    BrcFormatParser { insn }.parse([this](u32 index_a, u32 const4, u32 disp15) {
        // if (D[a] < zero_ext(const4)) then { // unsigned comparison
        //   PC = PC + sign_ext(disp15) * 2;
        // }
        if (m_data_reg[index_a] < const4) {
            m_core_registers.pc += disp15 * 2U;
            spdlog::trace("==> Cpu: JLT.U branch taken PC=0x{:08X}",
                m_core_registers.pc);
        } else {
            m_core_registers.pc += 4U;
            spdlog::trace("==> Cpu: JLT.U branch NOT taken PC=0x{:08X}",
                m_core_registers.pc);
        }
    });
}

void Tricore::Cpu::insn_j_b()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: J 0x{:08X}", insn);

    BFormatParser { insn }.parse([this](u32 disp24) {
        // PC = PC + sign_ext(disp24) * 2
        m_core_registers.pc += disp24 * 2U;
        spdlog::trace("==> Cpu: J uncoditional to address 0x{:08X}",
            m_core_registers.pc);
    });
}

void Tricore::Cpu::insn_nop()
{
    spdlog::trace("Cpu: NOP");
    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_jgeu_brc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: JGE.U 0x{:08X}", insn);

    BrcFormatParser { insn }.parse([this](u32 index_a, u32 const4, u32 disp15) {
        // if (D[a] >= zero_ext(const4)) then { // unsigned comparison
        // PC = PC + sign_ext(disp15) * 2;
        // }
        if (m_data_reg[index_a] >= const4) {
            m_core_registers.pc += disp15 * 2U;
            spdlog::trace("==> Cpu: JGE.U branch taken, address 0x{:08X}",
                m_core_registers.pc);
        } else {
            m_core_registers.pc += 4U;
            spdlog::trace("==> Cpu: JGE.U branch NOT taken");
        }
    });
}

void Tricore::Cpu::insn_extru_rrpw()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: EXTR.U 0x{:08X}", insn);

    RrpwFormatParser { insn }.parse(
        [this](u32 index_a, u32 width, u32 pos, u32 index_c) {
            // D[c] = zero_ext((D[a] >> pos)[width-1:0]);
            // If pos + width > 32 or if width = 0, then the results are undefined.
            const u32 result = Utils::extract32(m_data_reg[index_a], pos, width);
            spdlog::trace("===> Cpu: EXTR.U width={} pos={}", width, pos);
            m_data_reg[index_c] = result;
            spdlog::trace("==> Cpu: EXTR.U extracted value 0x{:08X} from D[{}]",
                m_data_reg[index_c], index_a);
        });

    m_core_registers.pc += 4U;
}

void Tricore::Cpu::insn_sh_src()
{
    u16 insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: SH 0x{:04X}", insn);

    SrcFormatParser { insn }.parse([this](u32 index_a, u32 const4) {
        // shift_count = sign_ext(const4[3:0]);
        // D[a] = (shift_count >= 0) ? D[a] << shift_count : D[a] >>
        // (-shift_count);
        const i32 sign_extended_const4 = static_cast<i32>(Utils::sign_extend32<4>(const4));
        if (sign_extended_const4 >= 0) {
            spdlog::trace("==> Cpu: SH shift left by {} value 0x{:08X}",
                sign_extended_const4, m_data_reg[index_a]);
            m_data_reg[index_a] = m_data_reg[index_a]
                << static_cast<u32>(sign_extended_const4);
        } else {
            spdlog::trace("==> Cpu: SH shift right by {} value 0x{:08X}",
                -sign_extended_const4, m_data_reg[index_a]);
            m_data_reg[index_a] = m_data_reg[index_a] >> static_cast<u32>(-sign_extended_const4);
        }
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_xor_rc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: XOR 0x{:08X}", insn);

    InstructionFormat::Rc parser { insn };

    // D[c] = D[a] ^ zero_ext(const9)
    m_data_reg[parser.c] = m_data_reg[parser.a] ^ parser.const9;
    spdlog::trace("==> Cpu: XOR store result 0x{:08X} into D[{}]",
        m_data_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_insert_rcpw()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: INSERT 0x{:08X}", insn);

    RcpwFormatParser { insn }.parse(
        [this](u32 index_a, u32 const4, u32 width, u32 pos, u32 index_c) {
            // mask = (2width -1) << pos;
            // D[c] = (D[a] & ~mask) | ((zero_ext(const4) << pos) & mask);
            // If pos + width > 32, then the result is undefined.

            spdlog::trace("==> Cpu: INSERT value 0x{:02X} at position {} with "
                          "length {} into D[{}]",
                const4, pos, width, index_c);
            m_data_reg[index_c] = Utils::deposit32(const4, pos, width, m_data_reg[index_a]);
        });

    m_core_registers.pc += 4U;
}

void Tricore::Cpu::insn_or_srr()
{
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: OR 0x{:04X}", insn);

    SrrFormatParser { insn }.parse([this](u32 index_a, u32 index_b) {
        // D[a] = D[a] | D[b]
        m_data_reg[index_a] |= m_data_reg[index_b];
        spdlog::trace("==> Cpu: OR write value 0x{:08X} in D[{}]",
            m_data_reg[index_a], index_a);
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_stw_ssr()
{
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: ST.W 0x{:04X}", insn);

    SsrFormatParser { insn }.parse([this](u32 index_a, u32 index_b) {
        //  M(A[b], word) = D[a]
        u32 output = m_data_reg[index_a];
        m_bus.write32(output, m_addr_reg[index_b]);
        spdlog::trace("==> Cpu: ST.W store value 0x{:08X} at address 0x{:08X}",
            output, m_addr_reg[index_b]);
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_lha_abs()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: LHA 0x{:08X}", insn);

    AbsFormatParser { insn }.parse([this](u32 index_a, u32 offset) {
        // EA = {off18[17:0], 14b'0};
        // A[a] = EA[31:0];

        const u32 effective_address = (offset & 0x3FFFFU) << 14U;
        spdlog::trace("==> Cpu: LHA loaded address 0x{:08X} into A[{}]",
            effective_address, index_a);
        m_addr_reg[index_a] = effective_address;
    });

    m_core_registers.pc += 4U;
}

void Tricore::Cpu::insn_ne_rc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: NE 0x{:08X}", insn);

    InstructionFormat::Rc parser { insn };

    // result = (D[a] != sign_ext(const9));
    // D[c] = zero_ext(result);
    m_data_reg[parser.c] = m_data_reg[parser.a] | parser.const9;
    const u32 sign_extended_const9 = Utils::sign_extend32<9>(parser.const9);
    if (m_data_reg[parser.a] != sign_extended_const9) {
        m_data_reg[parser.c] = 0x1U;
    } else {
        m_data_reg[parser.c] = 0;
    }
    spdlog::trace("==> Cpu: NE store result 0x{:08X} into D[{}]",
        m_data_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_andne_rr()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: AND.NE 0x{:08X}", insn);

    InstructionFormat::Rr parser { insn };

    // D[c] = {D[c][31:1], D[c][0] AND (D[a] != D[b])};
    if (m_data_reg[parser.a] != m_data_reg[parser.b]) {
        m_data_reg[parser.c] |= 0x1U;
    } else {
        m_data_reg[parser.c] &= ~1U;
    }
    spdlog::trace("==> Cpu: AND.NE writing value 0x{:08X} in D[{}]",
        m_data_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_addi_rlc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: ADDI 0x{:08X}", insn);

    RlcFormatParser { insn }.parse([this](u32 index_a, u32 index_c, u32 const16) {
        // result = D[a] + sign_ext(const16);
        // D[c] = result[31:0];
        const u32 sign_ext_const16 = Utils::sign_extend32<16>(const16);
        m_data_reg[index_c] = m_data_reg[index_a] + sign_ext_const16;
        spdlog::trace("==> Cpu: ADDI final value 0x{:08X} to D[{}]",
            m_data_reg[index_c], index_c);
    });

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_ne_rr()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: NE 0x{:08X}", insn);

    InstructionFormat::Rr parser { insn };

    // result = (D[a] != D[b]);
    // D[c] = zero_ext(result);
    if (m_data_reg[parser.a] != m_data_reg[parser.b]) {
        m_data_reg[parser.c] = 1U;
    } else {
        m_data_reg[parser.c] = 0U;
    }
    spdlog::trace("==> Cpu: NE writing value 0x{:08X} in D[{}]",
        m_data_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_minu_rr()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: MIN.U 0x{:08X}", insn);

    InstructionFormat::Rr parser { insn };

    // D[c] = (D[a] < D[b]) ? D[a] : D[b]; // unsigned
    if (m_data_reg[parser.a] < m_data_reg[parser.b]) {
        m_data_reg[parser.c] = m_data_reg[parser.a];
    } else {
        m_data_reg[parser.c] = m_data_reg[parser.b];
    }
    spdlog::trace("==> Cpu: MIN.U writing value 0x{:08X} in D[{}]",
        m_data_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_divu_rr()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: DIV.U 0x{:08X}", insn);

    InstructionFormat::Rr parser { insn };

    const u32 dividend = m_data_reg[parser.a];
    const u32 divisor = m_data_reg[parser.b];
    u32 quotient {};
    u32 remainder {};
    bool overflow {};

    if (divisor == 0) {
        quotient = 0xFFFFFFFFU;
        remainder = 0;
    } else {
        remainder = dividend % divisor;
        quotient = (dividend - remainder) / divisor;
    }

    if (divisor == 0 || (divisor == 0xFFFFFFFFU && dividend == 0x80000000U)) {
        overflow = true;
    }

    m_data_reg[parser.c] = quotient;
    m_data_reg[parser.c + 1ULL] = remainder;

    // TODO: update status register

    const u64 final_value = quotient | (static_cast<u64>(remainder) << 32ULL);
    spdlog::trace("==> Cpu: DIV.U writing value 0x{:016X} in E[{}]",
        final_value, parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_sub_rr()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: SUB 0x{:08X}", insn);

    InstructionFormat::Rr parser { insn };

    // D[c] = D[a] - D[b]
    m_data_reg[parser.c] = m_data_reg[parser.a] - m_data_reg[parser.b];
    spdlog::trace("==> Cpu: SUB writing value 0x{:08X} in D[{}]",
        m_data_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_utof_rr()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: UTOF 0x{:08X}", insn);

    InstructionFormat::Rr parser { insn };

    // Default rounding mode is nearest. TODO: check which rounding x86 performs
    f32 converted = static_cast<f32>(m_data_reg[parser.a]);
    spdlog::trace("==> Cpu: UTOF extracted float {}", converted);
    m_data_reg[parser.c] = static_cast<u32>(converted);
    spdlog::trace("==> Cpu: UTOF writing value 0x{:08X} in D[{}]",
        m_data_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_andne_rc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: AND.NE 0x{:08X}", insn);

    InstructionFormat::Rc parser { insn };

    // D[c] = {D[c][31:1], D[c][0] AND (D[a] != sign_ext(const9))};
    const u32 sign_extended_const9 = Utils::sign_extend32<9>(parser.const9);
    if (m_data_reg[parser.a] != sign_extended_const9) {
        m_data_reg[parser.c] |= 0x1U;
    } else {
        m_data_reg[parser.c] &= ~1U;
    }
    spdlog::trace("==> Cpu: AND.NE store result 0x{:08X} into D[{}]",
        m_data_reg[parser.c], parser.c);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_mov_src()
{
    u16 insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: MOV 0x{:04X}", insn);

    SrcFormatParser { insn }.parse([this](u32 index_a, u32 const4) {
        // D[a] = sign_ext(const4);
        const u32 sign_extended_const4 = Utils::sign_extend32<4>(const4);
        spdlog::trace("==> Cpu: MOV value 0x{:08X} into D[{}]",
            sign_extended_const4, index_a);
        m_data_reg[index_a] = sign_extended_const4;
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_sh_rc()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: SH 0x{:08X}", insn);

    InstructionFormat::Rc parser { insn };

    // D[c] = (const9[5:0] >= 0) ? D[a] << const9[5:0] : D[a] >>
    // (-const9[5:0]);
    const auto const9_subset = Utils::extract32(parser.const9, 0, 6);
    const i32 sign_extended_const9 = Utils::sign_extend32<6>(const9_subset);
    if (sign_extended_const9 >= 0) {
        spdlog::trace(
            "==> Cpu: SH shift left value 0x{:08X} of {} positions",
            m_data_reg[parser.a], sign_extended_const9);
        m_data_reg[parser.c] = m_data_reg[parser.a]
            << static_cast<u32>(sign_extended_const9);
    } else {
        spdlog::trace(
            "==> Cpu: SH shift right value 0x{:08X} of {} positions",
            m_data_reg[parser.a], -sign_extended_const9);
        m_data_reg[parser.c] = m_data_reg[parser.a] >> static_cast<u32>(-sign_extended_const9);
    }

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_mova_src()
{
    u16 insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: MOV.A 0x{:04X}", insn);

    SrcFormatParser { insn }.parse([this](u32 index_a, u32 const4) {
        // A[a] = zero_ext(const4);
        spdlog::trace("==> Cpu: MOV.A value 0x{:08X} into A[{}]", const4,
            index_a);
        m_addr_reg[index_a] = const4;
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_call_32()
{
    const u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: CALL 0x{:08X}", insn);

    if (m_core_registers.fcx == 0) {
        fail("CALL TRAP (FCU) => Context Save Area not initialized");
    }

    if ((m_core_registers.psw & cpu_psw_cde_mask) != 0) {
        const u32 call_depth_counter = Utils::extract32(m_core_registers.psw, 0, 7);
        if (call_depth_counter < 0x7FU) {
            u32 leading_ones = 0;

            for (u32 shift = 6U; shift > 1U; shift--) {
                if ((call_depth_counter & (1U << shift)) != 0) {
                    leading_ones++;
                } else {
                    break;
                }
            }

            Ensures(leading_ones <= 6U);

            const u32 counter_bits = 6U - leading_ones;
            const u32 max_depth_counter = (1U << (counter_bits)) - 1U;
            u32 filtered_depth_counter = Utils::extract32(call_depth_counter, 0, counter_bits);
            if (filtered_depth_counter == max_depth_counter) {
                fail("CALL TRAP (CDO) => Call Depth Counter overflow");
            }

            filtered_depth_counter += 1U;
            m_core_registers.psw = Utils::deposit32(
                filtered_depth_counter, 0, counter_bits, m_core_registers.psw);
        }
    } else {
        // set PSW.CDE to 1
        m_core_registers.psw |= cpu_psw_cde_mask;
    }

    const u32 return_address = m_core_registers.pc + 4U;

    const u32 tmp_fcx = m_core_registers.fcx;
    u32 current_context_address = Utils::extract32(tmp_fcx, 16, 4) << 28U;
    current_context_address |= Utils::extract32(tmp_fcx, 0, 16) << 6U;

    const u32 new_fcx = m_bus.read32(current_context_address);
    m_bus.write32(m_core_registers.pcxi, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_core_registers.psw, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_addr_reg.a10, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_addr_reg.a11, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_data_reg.d8, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_data_reg.d9, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_data_reg.d10, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_data_reg.d11, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_addr_reg.a12, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_addr_reg.a13, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_addr_reg.a14, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_addr_reg.a15, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_data_reg.d12, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_data_reg.d13, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_data_reg.d14, current_context_address);
    current_context_address += 4;
    m_bus.write32(m_data_reg.d15, current_context_address);

    spdlog::trace("==> Cpu: CALL FCX pointer 0x{:08X}",
        current_context_address);

    const u32 ccpn = Utils::extract32(m_core_registers.icr, 0, 8);
    m_core_registers.pcxi = Utils::deposit32(ccpn, 22, 8, m_core_registers.pcxi);

    spdlog::trace("==> Cpu: CALL PCPN 0x{:02X}", ccpn);

    const u32 ie_bit = Utils::extract32(m_core_registers.icr, 15, 1);
    m_core_registers.pcxi = Utils::deposit32(ie_bit, 21, 1, m_core_registers.pcxi);

    // PCXI.UL = 1
    m_core_registers.pcxi = Utils::deposit32(1U, 20, 1, m_core_registers.pcxi);

    // PCXI.PCX (PCXO + PCXS) = FCX
    m_core_registers.pcxi = Utils::deposit32(tmp_fcx, 0, 20, m_core_registers.pcxi);

    // FCX = new_FCX
    m_core_registers.fcx = Utils::deposit32(new_fcx, 0, 20, m_core_registers.fcx);

    const u32 disp24 = Utils::extract32(insn, 16, 16) | (Utils::extract32(insn, 8, 8) << 16U);

    const u32 sign_extended_disp24 = Utils::sign_extend32<24>(disp24 * 2U);

    m_core_registers.pc += sign_extended_disp24;
    spdlog::trace("==> Cpu: CALL PC=0x{:08X}", m_core_registers.pc);

    m_addr_reg.a11 = return_address;

    if (tmp_fcx == m_core_registers.lcx) {
        fail("CALL TRAP (FCD): CSA is full");
    }
}

void Tricore::Cpu::insn_mova_srr()
{
    // A[a] = D[b]
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: MOV.A 0x{:04X}", insn);

    SrrFormatParser { insn }.parse([this](u32 index_a, u32 index_b) {
        m_addr_reg[index_a] = m_data_reg[index_b];
        spdlog::trace("==> Cpu: MOV.A write value 0x{:08X} in A[{}]",
            m_addr_reg[index_a], index_a);
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_ret_sr()
{
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: RET 0x{:04X}", insn);

    // if (PSW.CDE) then if (cdc_decrement()) then trap(CDU);
    const u32 call_depth_enable = Utils::extract32(m_core_registers.psw, 7, 1);
    if (call_depth_enable != 0U) {
        const u32 call_depth_counter = Utils::extract32(m_core_registers.psw, 0, 7);
        if (call_depth_counter < 0x7FU) {
            u32 leading_ones = 0;

            for (u32 shift = 6U; shift > 1U; shift--) {
                if ((call_depth_counter & (1U << shift)) != 0) {
                    leading_ones++;
                } else {
                    break;
                }
            }

            Ensures(leading_ones <= 6U);

            const u32 counter_bits = 6U - leading_ones;
            u32 filtered_depth_counter = Utils::extract32(call_depth_counter, 0, counter_bits);
            if (filtered_depth_counter == 0U) {
                fail("CALL TRAP (CDU) => Call Depth Counter underflow");
            }

            filtered_depth_counter -= 1U;
            m_core_registers.psw = Utils::deposit32(
                filtered_depth_counter, 0, counter_bits, m_core_registers.psw);
        }
    }

    const u32 segment_address = Utils::extract32(m_core_registers.pcxi, 0, 20);
    if (segment_address == 0U) {
        fail("CALL TRAP (CSU) => Context Save underflow");
    }

    const u32 context_type = Utils::extract32(m_core_registers.pcxi, 20, 1);
    if (context_type == 0U) {
        fail("CALL TRAP (CTYP) => Wrong context type");
    }

    m_core_registers.pc = m_addr_reg.a11 & ~0x1U;
    spdlog::trace("==> Cpu: RET restore PC=0x{:08X}", m_core_registers.pc);

    const u32 pcxo = Utils::extract32(m_core_registers.pcxi, 0, 16);
    const u32 pcxs = Utils::extract32(m_core_registers.pcxi, 16, 4);

    const u32 effective_address = (pcxo << 6U) | (pcxs << 28U);
    u32 previous_context_address = effective_address;
    spdlog::trace("==> Cpu: RET restore upper context from address 0x{:08X}",
        previous_context_address);

    const u32 new_pcxi = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    const u32 new_psw = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_addr_reg.a10 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_addr_reg.a11 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_data_reg.d8 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_data_reg.d9 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_data_reg.d10 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_data_reg.d11 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_addr_reg.a12 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_addr_reg.a13 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_addr_reg.a14 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_addr_reg.a15 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_data_reg.d12 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_data_reg.d13 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_data_reg.d14 = m_bus.read32(previous_context_address);
    previous_context_address += 4;
    m_data_reg.d15 = m_bus.read32(previous_context_address);
    previous_context_address += 4;

    // Set "next" pointer in previous context area to the current CSA
    m_bus.write32(m_core_registers.fcx, effective_address);

    // Restore active CSA pointer to previous one
    m_core_registers.fcx = Utils::deposit32(pcxo, 0, 16, m_core_registers.fcx);
    m_core_registers.fcx = Utils::deposit32(pcxs, 16, 4, m_core_registers.fcx);

    m_core_registers.pcxi = new_pcxi;
    u32 mask = 0x3U << 24U;
    m_core_registers.psw = (m_core_registers.psw & mask) | (new_psw & (~mask));
}

void Tricore::Cpu::insn_mov_srr()
{
    // D[a] = D[b]
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: MOV 0x{:04X}", insn);

    SrrFormatParser { insn }.parse([this](u32 index_a, u32 index_b) {
        m_data_reg[index_a] = m_data_reg[index_b];
        spdlog::trace("==> Cpu: MOV write value 0x{:08X} in A[{}]",
            m_data_reg[index_a], index_a);
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_suba_sc()
{
    // A[10] = A[10] - zero_ext(const8);
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: SUB.A 0x{:04X}", insn);

    ScFormatParser { insn }.parse([this](u32 const8) {
        m_addr_reg.a10 -= const8;
        spdlog::trace("==> Cpu: SUB.A write value 0x{:08X} in A[10]",
            m_addr_reg.a10);
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_sth_bol()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: ST.H 0x{:08X}", insn);

    InstructionFormat::Bol format { insn };
    // EA = A[b] + sign_ext(off16)
    u32 effective_address = m_addr_reg[format.b] + Utils::sign_extend32<16>(format.off16);
    // M(EA, halfword) = D[a][15:0];
    const u16 value = static_cast<u16>(m_data_reg[format.a] & 0xFFFFU);
    m_bus.write16(value, effective_address);
    spdlog::trace(
        "==> Cpu: ST.H store value 0x{:04X} to memory address 0x{:08X}",
        value, effective_address);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_sta_bol()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: ST.A 0x{:08X}", insn);

    InstructionFormat::Bol format { insn };
    // EA = A[b] + sign_ext(off16)
    u32 effective_address = m_addr_reg[format.b] + Utils::sign_extend32<16>(format.off16);
    // M(EA, word) = A[a];
    m_bus.write32(m_addr_reg[format.a], effective_address);
    spdlog::trace(
        "==> Cpu: ST.A store value 0x{:08X} to memory address 0x{:08X}",
        m_addr_reg[format.a], effective_address);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_ldhu_bol()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: LD.HU 0x{:08X}", insn);

    InstructionFormat::Bol format { insn };
    // EA = A[b] + sign_ext(off16)
    u32 effective_address = m_addr_reg[format.b] + Utils::sign_extend32<16>(format.off16);
    // D[a] = zero_ext(M(EA, halfword));
    const u16 value = m_bus.read16(effective_address);
    m_data_reg[format.a] = value;
    spdlog::trace("==> Cpu: LD.HU loaded value 0x{:08X} from memory address 0x{:08X} to D[{}]",
        m_data_reg[format.a], effective_address, format.a);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_lda_bol()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: LD.A 0x{:08X}", insn);

    InstructionFormat::Bol format { insn };
    // EA = A[b] + sign_ext(off16)
    u32 effective_address = m_addr_reg[format.b] + Utils::sign_extend32<16>(format.off16);
    // A[a] = M(EA, word);
    const u32 value = m_bus.read32(effective_address);
    m_addr_reg[format.a] = value;
    spdlog::trace("==> Cpu: LD.A loaded value 0x{:08X} from memory address 0x{:08X} to A[{}]",
        m_addr_reg[format.a], effective_address,
        format.a);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_ldh_bol()
{
    u32 insn = m_bus.read32(m_core_registers.pc);
    spdlog::trace("Cpu: LD.H 0x{:08X}", insn);

    InstructionFormat::Bol format { insn };
    // EA = A[b] + sign_ext(off16)
    u32 effective_address = m_addr_reg[format.b] + Utils::sign_extend32<16>(format.off16);
    // D[a] = sign_ext(M(EA, halfword));
    const u16 value = m_bus.read16(effective_address);
    m_data_reg[format.a] = Utils::sign_extend32<16>(value);
    spdlog::trace("==> Cpu: LD.H loaded value 0x{:08X} from memory address 0x{:08X} to D[{}]",
        m_data_reg[format.a], effective_address, format.a);

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_movaa_srr()
{
    // A[a] = A[b]
    const auto insn = m_bus.read16(m_core_registers.pc);
    spdlog::trace("Cpu: MOV.AA 0x{:04X}", insn);

    SrrFormatParser { insn }.parse([this](u32 index_a, u32 index_b) {
        m_addr_reg[index_a] = m_addr_reg[index_b];
        spdlog::trace("==> Cpu: MOV.AA write value 0x{:08X} in A[{}]",
            m_addr_reg[index_a], index_a);
    });

    m_core_registers.pc += 2;
}

void Tricore::Cpu::print_cpu_status()
{
    // print CPU status
    fmt::println("===============================================");
    fmt::println(" PC  [0x{:08X}]  PSW [0x{:08X}]  PCXI [0x{:08X}]",
        m_core_registers.pc, m_core_registers.psw,
        m_core_registers.pcxi);
    fmt::println(" FCX [0x{:08X}]  LCX [0x{:08X}]", m_core_registers.fcx,
        m_core_registers.lcx);
    for (usize count = 0; count < register_count; count++) {

        fmt::println(" A{0:<2} [0x{1:08X}]  D{0:<2} [0x{2:08X}]", count,
            m_addr_reg[count], m_data_reg[count]);
    }
    fmt::println("===============================================");
}

void Tricore::Cpu::fail(std::string message)
{
    // print CPU status
    fmt::println("!! Failure in TC-33X CPU !!");
    fmt::println("Reason: {}", message);
    print_cpu_status();
    throw Tricore::Exception { message };
}
