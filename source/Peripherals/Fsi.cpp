
/**
 * @brief Module source for Fsi peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Fsi.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 fsi_comm_1_reset_value = 0; // TODO: change according manual
constexpr u32 fsi_comm_2_reset_value = 0; // TODO: change according manual
constexpr u32 fsi_hsmcomm_1_reset_value = 0; // TODO: change according manual
constexpr u32 fsi_hsmcomm_2_reset_value = 0; // TODO: change according manual

constexpr u32 fsi_memory_start_address = 0xf8030000U;
constexpr u32 fsi_memory_size = 0; // TODO: update according manual;
constexpr u32 fsi_memory_end_address = fsi_memory_start_address + fsi_memory_size;

constexpr u32 reg_fsi_comm_1_address = 0xf8030004;
constexpr u32 reg_fsi_comm_1_offset = reg_fsi_comm_1_address - fsi_memory_start_address;
constexpr u32 reg_fsi_comm_2_address = 0xf8030005;
constexpr u32 reg_fsi_comm_2_offset = reg_fsi_comm_2_address - fsi_memory_start_address;
constexpr u32 reg_fsi_hsmcomm_1_address = 0xf8030006;
constexpr u32 reg_fsi_hsmcomm_1_offset = reg_fsi_hsmcomm_1_address - fsi_memory_start_address;
constexpr u32 reg_fsi_hsmcomm_2_address = 0xf8030007;
constexpr u32 reg_fsi_hsmcomm_2_offset = reg_fsi_hsmcomm_2_address - fsi_memory_start_address;

} // anonymous namespace


Tricore::Fsi::Fsi()
    : m_fsi_comm_1(fsi_comm_1_reset_value)
    , m_fsi_comm_2(fsi_comm_2_reset_value)
    , m_fsi_hsmcomm_1(fsi_hsmcomm_1_reset_value)
    , m_fsi_hsmcomm_2(fsi_hsmcomm_2_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Fsi::read(std::byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - fsi_memory_start_address;
    switch (offset) {
    case reg_fsi_comm_1_offset: {
            spdlog::debug("FSI: accessing FSI.FSI_COMM_1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_fsi_comm_1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_fsi_comm_2_offset: {
            spdlog::debug("FSI: accessing FSI.FSI_COMM_2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_fsi_comm_2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_fsi_hsmcomm_1_offset: {
            spdlog::debug("FSI: accessing FSI.FSI_HSMCOMM_1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_fsi_hsmcomm_1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_fsi_hsmcomm_2_offset: {
            spdlog::debug("FSI: accessing FSI.FSI_HSMCOMM_2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_fsi_hsmcomm_2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Fsi peripheral", address)};
        break;
    }
}

void Tricore::Fsi::write(const std::byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - fsi_memory_start_address;
    switch (offset) {
    case reg_fsi_comm_1_offset: {
        spdlog::debug("FSI: accessing FSI.FSI_COMM_1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_fsi_comm_1));
    } break;
    case reg_fsi_comm_2_offset: {
        spdlog::debug("FSI: accessing FSI.FSI_COMM_2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_fsi_comm_2));
    } break;
    case reg_fsi_hsmcomm_1_offset: {
        spdlog::debug("FSI: accessing FSI.FSI_HSMCOMM_1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_fsi_hsmcomm_1));
    } break;
    case reg_fsi_hsmcomm_2_offset: {
        spdlog::debug("FSI: accessing FSI.FSI_HSMCOMM_2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_fsi_hsmcomm_2));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Fsi peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
