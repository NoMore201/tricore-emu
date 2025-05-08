
/**
 * @brief Module source for Pfi peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Pfi.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 pfi0_eccr_reset_value = 0; // TODO: change according manual
constexpr u32 pfi0_eccs_reset_value = 0; // TODO: change according manual

constexpr u32 pfi_memory_start_address = 0xa8080000U;
constexpr u32 pfi_memory_size = 0; // TODO: update according manual;
constexpr u32 pfi_memory_end_address = pfi_memory_start_address + pfi_memory_size;

constexpr u32 reg_pfi0_eccr_address = 0xa8080000;
constexpr u32 reg_pfi0_eccr_offset = reg_pfi0_eccr_address - pfi_memory_start_address;
constexpr u32 reg_pfi0_eccs_address = 0xa8080020;
constexpr u32 reg_pfi0_eccs_offset = reg_pfi0_eccs_address - pfi_memory_start_address;

} // anonymous namespace


Tricore::Pfi::Pfi()
    : m_pfi0_eccr(pfi0_eccr_reset_value)
    , m_pfi0_eccs(pfi0_eccs_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Pfi::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - pfi_memory_start_address;
    switch (offset) {
    case reg_pfi0_eccr_offset: {
            spdlog::debug("PFI: accessing PFI.PFI0_ECCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pfi0_eccr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pfi0_eccs_offset: {
            spdlog::debug("PFI: accessing PFI.PFI0_ECCS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pfi0_eccs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Pfi peripheral", address)};
        break;
    }
}

void Tricore::Pfi::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - pfi_memory_start_address;
    switch (offset) {
    case reg_pfi0_eccr_offset: {
        spdlog::debug("PFI: accessing PFI.PFI0_ECCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pfi0_eccr));
    } break;
    case reg_pfi0_eccs_offset: {
        spdlog::debug("PFI: accessing PFI.PFI0_ECCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pfi0_eccs));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Pfi peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
