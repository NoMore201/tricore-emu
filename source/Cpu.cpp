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
constexpr std::byte bytecode_add_c2 = std::byte{0xC2};

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
        default:
            throw Exception{
                fmt::format("Instruction with opcode 0x{:02X} not implemented",
                            insn_opcode)};
        }
    }
}

void Tricore::Cpu::insn_movha() {
    u32 insn = read_32(m_core_registers.pc);
    spdlog::debug("Cpu: MOVH.A 0x{:08X}", insn);
    const auto addr_register_index = Utils::extract32(insn, 28, 4);
    const auto msb_half_word = Utils::extract32(insn, 12, 16);
    m_address_registers.at(addr_register_index) = 0U | (msb_half_word << 16U);
    spdlog::debug("==> Cpu: MOVH.A value 0x{:08X} to A[{}]",
                  m_address_registers.at(addr_register_index),
                  addr_register_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_mov_rlc() {
    u32 insn = read_32(m_core_registers.pc);
    spdlog::debug("Cpu: MOV 0x{:08X}", insn);
    const auto data_register_index = Utils::extract32(insn, 28, 4);
    const u32 const16 = Utils::extract32(insn, 12, 16);
    auto sign_ext_const16 =
        Utils::sign_extend<i32, 32>(static_cast<i32>(const16));
    m_data_registers.at(data_register_index) =
        static_cast<u32>(sign_ext_const16);
    spdlog::debug("==> Cpu: MOV final value 0x{:08X} to D[{}]",
                  m_data_registers.at(data_register_index),
                  data_register_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_lea_bol() {
    u32 insn = read_32(m_core_registers.pc);
    spdlog::debug("Cpu: LEA 0x{:08X}", insn);
    const auto addr_index_a = Utils::extract32(insn, 8, 4);
    const auto addr_index_b = Utils::extract32(insn, 12, 4);
    u32 off16 = Utils::extract32(insn, 16, 6);
    off16 |= Utils::extract32(insn, 28, 4) << 6U;
    off16 |= Utils::extract32(insn, 22, 6) << 10U;
    i32 sign_extended_off16 =
        Utils::sign_extend<i32, 16>(static_cast<i32>(off16));
    // EA = A[b] + sign_ext(off16)
    const u32 effective_address = m_address_registers.at(addr_index_b) +
                                  static_cast<u32>(sign_extended_off16);
    // A[a] = EA[31:0]
    m_address_registers.at(addr_index_a) = effective_address;
    spdlog::debug("==> Cpu: LEA final address 0x{:08X} to A[{}]",
                  effective_address, addr_index_a);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_ji_sr() {
    const auto insn = read_16(m_core_registers.pc);
    spdlog::debug("Cpu: JI 0x{:04X}", insn);
    const auto addr_index = Utils::extract32(insn, 8, 4);
    const auto final_address =
        m_address_registers.at(addr_index) & ((~0U) - 1U);
    spdlog::debug("==> Cpu: JI final address 0x{:08X}", final_address);
    m_core_registers.pc = final_address;
}

void Tricore::Cpu::insn_mtcr() {
    const auto insn = read_32(m_core_registers.pc);
    spdlog::debug("Cpu: MTCR 0x{:08X}", insn);
    const auto data_index = Utils::extract32(insn, 8, 4);
    const auto const16 = Utils::extract32(insn, 12, 16);
    m_core_registers[const16] = m_data_registers.at(data_index);
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_isync() {
    spdlog::debug("Cpu: ISYNC");
    // do nothing
    m_core_registers.pc += 4;
}

void Tricore::Cpu::insn_ldw_slr() {
    const auto insn = read_16(m_core_registers.pc);
    spdlog::debug("Cpu: LD.W 0x{:04X}", insn);
    const auto addr_index_b = Utils::extract32(insn, 12, 4);
    const auto data_index_c = Utils::extract32(insn, 8, 4);
    m_data_registers.at(data_index_c) =
        read_32(m_address_registers.at(addr_index_b));
    spdlog::debug(
        "==> Cpu: LD.W loaded data 0x{:08X} from address 0x{:08X} into D[{}]",
        m_data_registers.at(data_index_c), m_address_registers.at(addr_index_b),
        data_index_c);
    m_core_registers.pc += 2;
}

void Tricore::Cpu::insn_add_c2() {
    const auto insn = read_16(m_core_registers.pc);
    spdlog::debug("Cpu: ADD 0x{:04X}", insn);
    const auto const4 = Utils::extract32(insn, 12, 4);
    const auto data_index_a = Utils::extract32(insn, 8, 4);
    const auto sign_extended_const4 =
        Utils::sign_extend<i32, 4>(static_cast<i32>(const4));
    m_data_registers.at(data_index_a) += static_cast<u32>(sign_extended_const4);
    spdlog::debug("==> Cpu: ADD write value 0x{:08X} in D[{}]",
                  m_data_registers.at(data_index_a), data_index_a);
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