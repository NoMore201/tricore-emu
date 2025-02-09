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

struct BolFormatParser {
    u32 insn{};

    template<typename F>
    void parse(F&& callback) {
        namespace Utils = Tricore::Utils;
        const auto index_a = Utils::extract<u32>(insn, 8, 4);
        const auto index_b = Utils::extract<u32>(insn, 12, 4);
        u32 off16 = Utils::extract<u32>(insn, 16, 6);
        off16 |= Utils::extract<u32>(insn, 28, 4) << 6U;
        off16 |= Utils::extract<u32>(insn, 22, 6) << 10U;
        i32 sign_extended_off16 =
            Utils::sign_extend<i32, 16>(static_cast<i32>(off16));
        callback(index_a, index_b, static_cast<u32>(sign_extended_off16));
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
        default:
            throw Exception{
                fmt::format("Instruction with opcode 0x{:02X} not implemented",
                            insn_opcode)};
        }
    }
}

void Tricore::Cpu::insn_movha() {
    u32 insn = read_32(m_core_registers.pc);
    spdlog::trace("Cpu: MOVH.A 0x{:08X}", insn);
    const auto addr_register_index = Utils::extract<u32>(insn, 28, 4);
    const auto msb_half_word = Utils::extract<u32>(insn, 12, 16);
    m_address_registers.at(addr_register_index) = 0U | (msb_half_word << 16U);
    spdlog::trace("==> Cpu: MOVH.A value 0x{:08X} to A[{}]",
                  m_address_registers.at(addr_register_index),
                  addr_register_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_mov_rlc() {
    u32 insn = read_32(m_core_registers.pc);
    spdlog::trace("Cpu: MOV 0x{:08X}", insn);
    const auto data_register_index = Utils::extract<u32>(insn, 28, 4);
    const u32 const16 = Utils::extract<u32>(insn, 12, 16);
    auto sign_ext_const16 =
        Utils::sign_extend<i32, 32>(static_cast<i32>(const16));
    m_data_registers.at(data_register_index) =
        static_cast<u32>(sign_ext_const16);
    spdlog::trace("==> Cpu: MOV final value 0x{:08X} to D[{}]",
                  m_data_registers.at(data_register_index),
                  data_register_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_lea_bol() {
    u32 insn = read_32(m_core_registers.pc);
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
    const auto insn = read_16(m_core_registers.pc);
    spdlog::trace("Cpu: JI 0x{:04X}", insn);
    const auto addr_index = Utils::extract<u32>(insn, 8, 4);
    const auto final_address =
        m_address_registers.at(addr_index) & ((~0U) - 1U);
    spdlog::trace("==> Cpu: JI final address 0x{:08X}", final_address);
    m_core_registers.pc = final_address;
}

void Tricore::Cpu::insn_mtcr() {
    const auto insn = read_32(m_core_registers.pc);
    spdlog::trace("Cpu: MTCR 0x{:08X}", insn);
    const auto data_index = Utils::extract<u32>(insn, 8, 4);
    const auto const16 = Utils::extract<u32>(insn, 12, 16);
    m_core_registers[const16] = m_data_registers.at(data_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_isync() {
    spdlog::trace("Cpu: ISYNC");
    // do nothing
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_ldw_slr() {
    const auto insn = read_16(m_core_registers.pc);
    spdlog::trace("Cpu: LD.W 0x{:04X}", insn);
    const auto addr_index_b = Utils::extract<u32>(insn, 12, 4);
    const auto data_index_c = Utils::extract<u32>(insn, 8, 4);
    m_data_registers.at(data_index_c) =
        read_32(m_address_registers.at(addr_index_b));
    spdlog::trace(
        "==> Cpu: LD.W loaded data 0x{:08X} from address 0x{:08X} into D[{}]",
        m_data_registers.at(data_index_c), m_address_registers.at(addr_index_b),
        data_index_c);
    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_ldw_bol() {
    u32 insn = read_32(m_core_registers.pc);
    spdlog::trace("Cpu: LD.W 0x{:08X}", insn);

    BolFormatParser{insn}.parse(
        [this](u32 data_index_a, u32 addr_index_b, u32 off16) {
        // EA = A[b] + sign_ext(off16)
        const u32 effective_address =
            m_address_registers.at(addr_index_b) + off16;
        // D[a] = M(EA, word)
        m_data_registers.at(data_index_a) = effective_address;
        spdlog::trace("==> Cpu: LD.W final value 0x{:08X} to D[{}]",
                      effective_address, data_index_a);
    });

    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_add_c2() {
    const auto insn = read_16(m_core_registers.pc);
    spdlog::trace("Cpu: ADD 0x{:04X}", insn);
    const auto const4 = Utils::extract<u32>(insn, 12, 4);
    const auto data_index_a = Utils::extract<u32>(insn, 8, 4);
    const auto sign_extended_const4 =
        Utils::sign_extend<i32, 4>(static_cast<i32>(const4));
    m_data_registers.at(data_index_a) += static_cast<u32>(sign_extended_const4);
    spdlog::trace("==> Cpu: ADD write value 0x{:08X} in D[{}]",
                  m_data_registers.at(data_index_a), data_index_a);
    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_movh() {
    // D[c] = {const16, 16 h0000}
    u32 insn = read_32(m_core_registers.pc);
    spdlog::trace("Cpu: MOVH 0x{:08X}", insn);
    const auto data_register_index = Utils::extract<u32>(insn, 28, 4);
    const auto msb_half_word = Utils::extract<u32>(insn, 12, 16);
    m_data_registers.at(data_register_index) = 0U | (msb_half_word << 16U);
    spdlog::trace("==> Cpu: MOVH value 0x{:08X} to D[{}]",
                  m_data_registers.at(data_register_index),
                  data_register_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_and_srr() {
    // D[a] = D[a] & D[b]
    const auto insn = read_16(m_core_registers.pc);
    spdlog::trace("Cpu: AND 0x{:04X}", insn);
    const auto data_index_a = Utils::extract<u32>(insn, 8, 4);
    const auto data_index_b = Utils::extract<u32>(insn, 12, 4);
    m_data_registers.at(data_index_a) &= m_data_registers.at(data_index_b);
    spdlog::trace("==> Cpu: AND write value 0x{:08X} in D[{}]",
                  m_data_registers.at(data_index_a), data_index_a);
    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_jne_brc() {
    // if (D[a] != sign_ext(const4)) then PC = PC + sign_ext(disp15) * 2
    u32 insn = read_32(m_core_registers.pc);
    spdlog::trace("Cpu: JNE 0x{:08X}", insn);
    const auto data_register_a = Utils::extract<u32>(insn, 8, 4);
    const auto const4 = Utils::extract<u32>(insn, 12, 4);
    const auto disp15 = Utils::extract<u32>(insn, 16, 15);
    i32 sign_extended_const4 =
        Utils::sign_extend<i32, 4>(static_cast<i32>(const4));
    i32 sign_extended_disp15 =
        Utils::sign_extend<i32, 15>(static_cast<i32>(disp15));
    if (m_data_registers.at(data_register_a) !=
        static_cast<u32>(sign_extended_const4)) {
        m_core_registers.pc += static_cast<u32>(sign_extended_disp15) * 2U;
        spdlog::trace("==> Cpu: JNE branch taken PC=0x{:08X}",
                      m_core_registers.pc);
    } else {
        m_core_registers.pc += 4;
        spdlog::trace("==> Cpu: JNE branch NOT taken PC=0x{:08X}",
                      m_core_registers.pc);
    }
}

void Tricore::Cpu::insn_suba_rr() {
    // A[c] = A[a] - A[b]
    u32 insn = read_32(m_core_registers.pc);
    spdlog::trace("Cpu: SUB.A 0x{:08X}", insn);
    const auto addr_register_a = Utils::extract<u32>(insn, 8, 4);
    const auto addr_register_b = Utils::extract<u32>(insn, 12, 4);
    const auto addr_register_c = Utils::extract<u32>(insn, 28, 4);
    m_address_registers.at(addr_register_c) =
        m_address_registers.at(addr_register_a) -
        m_address_registers.at(addr_register_b);
    spdlog::trace("==> Cpu: SUB.A writing value 0x{:08X} in A[{}]",
                  m_address_registers.at(addr_register_c), addr_register_c);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_movd_srr() {
    // D[a] = A[b]
    const auto insn = read_16(m_core_registers.pc);
    spdlog::trace("Cpu: MOV.D 0x{:04X}", insn);
    const auto data_index_a = Utils::extract<u32>(insn, 8, 4);
    const auto addr_index_b = Utils::extract<u32>(insn, 12, 4);
    m_data_registers.at(data_index_a) &= m_address_registers.at(addr_index_b);
    spdlog::trace("==> Cpu: MOV.D write value 0x{:08X} in A[{}]",
                  m_data_registers.at(data_index_a), addr_index_b);
    m_core_registers.pc += 2;
}

u32 Tricore::Cpu::read_32(u32 address) {
    u32 data{};

    for (auto *client : m_bus_clients) {
        try {
            client->read(reinterpret_cast<std::byte *>(&data), address, 4);
            return data;
        } catch (InvalidMemoryAccess &) {
            // this client does not handle input address, continue
            continue;
        }
    }

    // Address not handled by any peripherals, re-throw error
    throw InvalidMemoryAccess{
        fmt::format("Address 0x{:08X} not handled by CPU", address)};
}

u16 Tricore::Cpu::read_16(u32 address) {
    u16 data{};

    for (auto *client : m_bus_clients) {
        try {
            client->read(reinterpret_cast<std::byte *>(&data), address, 2);
            return data;
        } catch (InvalidMemoryAccess &) {
            // this client does not handle input address, continue
            continue;
        }
    }

    // Address not handled by any peripherals, re-throw error
    throw InvalidMemoryAccess{
        fmt::format("Address 0x{:08X} not handled by CPU", address)};
}