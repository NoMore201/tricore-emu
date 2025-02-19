
/**
 * @brief Module source for Gpt12 peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Gpt12.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 gpt120_clc_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_pisel_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_id_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_t2con_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_t3con_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_t4con_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_t5con_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_t6con_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_caprel_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_t2_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_t3_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_t4_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_t5_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_t6_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 gpt120_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 gpt12_memory_start_address = 0xf0001800U;
constexpr u32 gpt12_memory_size = 0; // TODO: update according manual;
constexpr u32 gpt12_memory_end_address = gpt12_memory_start_address + gpt12_memory_size;

constexpr u32 reg_gpt120_clc_address = 0xf0001800;
constexpr u32 reg_gpt120_clc_offset = reg_gpt120_clc_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_pisel_address = 0xf0001804;
constexpr u32 reg_gpt120_pisel_offset = reg_gpt120_pisel_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_id_address = 0xf0001808;
constexpr u32 reg_gpt120_id_offset = reg_gpt120_id_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_t2con_address = 0xf0001810;
constexpr u32 reg_gpt120_t2con_offset = reg_gpt120_t2con_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_t3con_address = 0xf0001814;
constexpr u32 reg_gpt120_t3con_offset = reg_gpt120_t3con_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_t4con_address = 0xf0001818;
constexpr u32 reg_gpt120_t4con_offset = reg_gpt120_t4con_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_t5con_address = 0xf000181c;
constexpr u32 reg_gpt120_t5con_offset = reg_gpt120_t5con_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_t6con_address = 0xf0001820;
constexpr u32 reg_gpt120_t6con_offset = reg_gpt120_t6con_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_caprel_address = 0xf0001830;
constexpr u32 reg_gpt120_caprel_offset = reg_gpt120_caprel_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_t2_address = 0xf0001834;
constexpr u32 reg_gpt120_t2_offset = reg_gpt120_t2_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_t3_address = 0xf0001838;
constexpr u32 reg_gpt120_t3_offset = reg_gpt120_t3_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_t4_address = 0xf000183c;
constexpr u32 reg_gpt120_t4_offset = reg_gpt120_t4_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_t5_address = 0xf0001840;
constexpr u32 reg_gpt120_t5_offset = reg_gpt120_t5_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_t6_address = 0xf0001844;
constexpr u32 reg_gpt120_t6_offset = reg_gpt120_t6_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_ocs_address = 0xf00018e8;
constexpr u32 reg_gpt120_ocs_offset = reg_gpt120_ocs_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_krstclr_address = 0xf00018ec;
constexpr u32 reg_gpt120_krstclr_offset = reg_gpt120_krstclr_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_krst1_address = 0xf00018f0;
constexpr u32 reg_gpt120_krst1_offset = reg_gpt120_krst1_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_krst0_address = 0xf00018f4;
constexpr u32 reg_gpt120_krst0_offset = reg_gpt120_krst0_address - gpt12_memory_start_address;
constexpr u32 reg_gpt120_accen0_address = 0xf00018fc;
constexpr u32 reg_gpt120_accen0_offset = reg_gpt120_accen0_address - gpt12_memory_start_address;

} // anonymous namespace


Tricore::Gpt12::Gpt12()
    : m_gpt120_clc(gpt120_clc_reset_value)
    , m_gpt120_pisel(gpt120_pisel_reset_value)
    , m_gpt120_id(gpt120_id_reset_value)
    , m_gpt120_t2con(gpt120_t2con_reset_value)
    , m_gpt120_t3con(gpt120_t3con_reset_value)
    , m_gpt120_t4con(gpt120_t4con_reset_value)
    , m_gpt120_t5con(gpt120_t5con_reset_value)
    , m_gpt120_t6con(gpt120_t6con_reset_value)
    , m_gpt120_caprel(gpt120_caprel_reset_value)
    , m_gpt120_t2(gpt120_t2_reset_value)
    , m_gpt120_t3(gpt120_t3_reset_value)
    , m_gpt120_t4(gpt120_t4_reset_value)
    , m_gpt120_t5(gpt120_t5_reset_value)
    , m_gpt120_t6(gpt120_t6_reset_value)
    , m_gpt120_ocs(gpt120_ocs_reset_value)
    , m_gpt120_krstclr(gpt120_krstclr_reset_value)
    , m_gpt120_krst1(gpt120_krst1_reset_value)
    , m_gpt120_krst0(gpt120_krst0_reset_value)
    , m_gpt120_accen0(gpt120_accen0_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Gpt12::read(std::byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - gpt12_memory_start_address;
    switch (offset) {
    case reg_gpt120_clc_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_pisel_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_PISEL in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_pisel);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_id_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_t2con_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_T2CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_t2con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_t3con_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_T3CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_t3con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_t4con_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_T4CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_t4con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_t5con_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_T5CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_t5con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_t6con_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_T6CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_t6con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_caprel_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_CAPREL in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_caprel);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_t2_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_T2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_t2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_t3_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_T3 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_t3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_t4_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_T4 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_t4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_t5_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_T5 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_t5);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_t6_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_T6 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_t6);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_ocs_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_krstclr_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_krst1_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_krst0_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gpt120_accen0_offset: {
            spdlog::debug("GPT12: accessing GPT12.GPT120_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_gpt120_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Gpt12 peripheral", address)};
        break;
    }
}

void Tricore::Gpt12::write(const std::byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - gpt12_memory_start_address;
    switch (offset) {
    case reg_gpt120_clc_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_clc));
    } break;
    case reg_gpt120_pisel_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_PISEL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_pisel));
    } break;
    case reg_gpt120_id_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_id));
    } break;
    case reg_gpt120_t2con_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_T2CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_t2con));
    } break;
    case reg_gpt120_t3con_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_T3CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_t3con));
    } break;
    case reg_gpt120_t4con_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_T4CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_t4con));
    } break;
    case reg_gpt120_t5con_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_T5CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_t5con));
    } break;
    case reg_gpt120_t6con_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_T6CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_t6con));
    } break;
    case reg_gpt120_caprel_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_CAPREL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_caprel));
    } break;
    case reg_gpt120_t2_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_T2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_t2));
    } break;
    case reg_gpt120_t3_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_T3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_t3));
    } break;
    case reg_gpt120_t4_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_T4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_t4));
    } break;
    case reg_gpt120_t5_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_T5 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_t5));
    } break;
    case reg_gpt120_t6_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_T6 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_t6));
    } break;
    case reg_gpt120_ocs_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_ocs));
    } break;
    case reg_gpt120_krstclr_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_krstclr));
    } break;
    case reg_gpt120_krst1_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_krst1));
    } break;
    case reg_gpt120_krst0_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_krst0));
    } break;
    case reg_gpt120_accen0_offset: {
        spdlog::debug("GPT12: accessing GPT12.GPT120_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_gpt120_accen0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Gpt12 peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
