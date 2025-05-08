
/**
 * @brief Module source for Fce peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Fce.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 fce_clc_reset_value = 0; // TODO: change according manual
constexpr u32 fce_id_reset_value = 0; // TODO: change according manual
constexpr u32 fce_chsts_reset_value = 0; // TODO: change according manual
constexpr u32 fce_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 fce_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 fce_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 fce_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 fce_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 fce_memory_start_address = 0xf0000000U;
constexpr u32 fce_memory_size = 0; // TODO: update according manual;
constexpr u32 fce_memory_end_address = fce_memory_start_address + fce_memory_size;

constexpr u32 reg_fce_clc_address = 0xf0000000;
constexpr u32 reg_fce_clc_offset = reg_fce_clc_address - fce_memory_start_address;
constexpr u32 reg_fce_id_address = 0xf0000008;
constexpr u32 reg_fce_id_offset = reg_fce_id_address - fce_memory_start_address;
constexpr u32 reg_fce_chsts_address = 0xf0000020;
constexpr u32 reg_fce_chsts_offset = reg_fce_chsts_address - fce_memory_start_address;
constexpr u32 reg_fce_krstclr_address = 0xf00000ec;
constexpr u32 reg_fce_krstclr_offset = reg_fce_krstclr_address - fce_memory_start_address;
constexpr u32 reg_fce_krst1_address = 0xf00000f0;
constexpr u32 reg_fce_krst1_offset = reg_fce_krst1_address - fce_memory_start_address;
constexpr u32 reg_fce_krst0_address = 0xf00000f4;
constexpr u32 reg_fce_krst0_offset = reg_fce_krst0_address - fce_memory_start_address;
constexpr u32 reg_fce_accen1_address = 0xf00000f8;
constexpr u32 reg_fce_accen1_offset = reg_fce_accen1_address - fce_memory_start_address;
constexpr u32 reg_fce_accen0_address = 0xf00000fc;
constexpr u32 reg_fce_accen0_offset = reg_fce_accen0_address - fce_memory_start_address;

} // anonymous namespace


Tricore::Fce::Fce()
    : m_fce_clc(fce_clc_reset_value)
    , m_fce_id(fce_id_reset_value)
    , m_fce_chsts(fce_chsts_reset_value)
    , m_fce_krstclr(fce_krstclr_reset_value)
    , m_fce_krst1(fce_krst1_reset_value)
    , m_fce_krst0(fce_krst0_reset_value)
    , m_fce_accen1(fce_accen1_reset_value)
    , m_fce_accen0(fce_accen0_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Fce::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - fce_memory_start_address;
    switch (offset) {
    case reg_fce_clc_offset: {
            spdlog::debug("FCE: accessing FCE.FCE_CLC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_fce_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_fce_id_offset: {
            spdlog::debug("FCE: accessing FCE.FCE_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_fce_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_fce_chsts_offset: {
            spdlog::debug("FCE: accessing FCE.FCE_CHSTS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_fce_chsts);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_fce_krstclr_offset: {
            spdlog::debug("FCE: accessing FCE.FCE_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_fce_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_fce_krst1_offset: {
            spdlog::debug("FCE: accessing FCE.FCE_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_fce_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_fce_krst0_offset: {
            spdlog::debug("FCE: accessing FCE.FCE_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_fce_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_fce_accen1_offset: {
            spdlog::debug("FCE: accessing FCE.FCE_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_fce_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_fce_accen0_offset: {
            spdlog::debug("FCE: accessing FCE.FCE_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_fce_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Fce peripheral", address)};
        break;
    }
}

void Tricore::Fce::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - fce_memory_start_address;
    switch (offset) {
    case reg_fce_clc_offset: {
        spdlog::debug("FCE: accessing FCE.FCE_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_fce_clc));
    } break;
    case reg_fce_id_offset: {
        spdlog::debug("FCE: accessing FCE.FCE_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_fce_id));
    } break;
    case reg_fce_chsts_offset: {
        spdlog::debug("FCE: accessing FCE.FCE_CHSTS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_fce_chsts));
    } break;
    case reg_fce_krstclr_offset: {
        spdlog::debug("FCE: accessing FCE.FCE_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_fce_krstclr));
    } break;
    case reg_fce_krst1_offset: {
        spdlog::debug("FCE: accessing FCE.FCE_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_fce_krst1));
    } break;
    case reg_fce_krst0_offset: {
        spdlog::debug("FCE: accessing FCE.FCE_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_fce_krst0));
    } break;
    case reg_fce_accen1_offset: {
        spdlog::debug("FCE: accessing FCE.FCE_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_fce_accen1));
    } break;
    case reg_fce_accen0_offset: {
        spdlog::debug("FCE: accessing FCE.FCE_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_fce_accen0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Fce peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
