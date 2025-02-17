
#include "Peripherals/Scu.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

// Reset value:
// LBTERM set to 1 to simulate successful LBIST
// PORST set to 1
constexpr u32 rststat_reset_value = 0x40010000U;

// Reset value:
// LBISTDONE set to 1 to simulate successful LBIST
constexpr u32 lbistctrl0_reset_value = 0x10000000U;

// Reset value:
// ENDINIT set to 0
// LCK set to 1
// PW set to 0x3
// REL set to 0xFFFC
constexpr u32 wdts_con0_reset_value = 0xFFFC000EU;

constexpr u32 scu_memory_start_address = 0xF0036000U;
constexpr u32 scu_memory_size = 1U * KiB;
constexpr u32 scu_memory_end_address =
    scu_memory_start_address + scu_memory_size;

} // anonymous namespace


Tricore::Scu::Scu()
    : m_rststat(rststat_reset_value)
    , m_lbistctrl0(lbistctrl0_reset_value)
    , m_wdts_con0(wdts_con0_reset_value)
{}

void Tricore::Scu::read(std::byte *buffer_out, u32 address, usize length) {
    if (address < scu_memory_start_address ||
        address >= scu_memory_end_address) {
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by SCU peripheral", address)};
    }
    const u32 offset = address - scu_memory_start_address;
    switch (offset) {
    case 0x50U: {
        spdlog::debug("Scu: accessing SCU.RSTSTAT in read mode");
        const auto *range_start = reinterpret_cast<std::byte *>(&m_rststat);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case 0x164U: {
        spdlog::debug("Scu: accessing SCU.LBISTCTRL0 in read mode");
        const auto *range_start = reinterpret_cast<std::byte *>(&m_lbistctrl0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case 0x2A8U: {
        spdlog::debug("Scu: accessing SCU.WDTS_CON0 in read mode");
        const auto *range_start = reinterpret_cast<std::byte *>(&m_wdts_con0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    default:
        spdlog::warn("Address 0x{:08X} not yet handled by SCU peripheral",
                     address);
        break;
    }
}

void Tricore::Scu::write(const std::byte *buffer_in, u32 address,
                         usize length) {

    if (address < scu_memory_start_address ||
        address >= scu_memory_end_address) {
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by SCU peripheral", address)};
    }
    const u32 offset = address - scu_memory_start_address;
    switch (offset) {
    case 0x50U: {
        spdlog::debug("Scu: accessing SCU.RSTSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_rststat));
    } break;
    case 0x164U: {
        spdlog::debug("Scu: accessing SCU.LBISTCTRL0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_lbistctrl0));
    } break;
    case 0x2A8U: {
        spdlog::debug("Scu: accessing SCU.WDTS_CON0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_wdts_con0));
    } break;
    default:
        spdlog::warn("Address 0x{:08X} not yet handled by SCU peripheral",
                     address);
        break;
    }
}