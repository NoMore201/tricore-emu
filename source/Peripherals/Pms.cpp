

#include "Peripherals/Pms.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

// Reset value:
// 0
constexpr u32 cmd_stdby_reset_value = 0x0;

// Reset value:
// LBISTDONE set to 1 to simulate successful LBIST
constexpr u32 monbistctrl_reset_value = 0x0;

// Reset value:
// ENDINIT set to 0
// LCK set to 1
// PW set to 0x3
// REL set to 0xFFFC
constexpr u32 monfilt_reset_value = 0x300U;

constexpr u32 pms_memory_start_address = 0xF0248000U;
constexpr u32 pms_memory_size = 512U;
constexpr u32 pms_memory_end_address =
    pms_memory_start_address + pms_memory_size;

} // anonymous namespace


Tricore::Pms::Pms()
    : m_cmd_stdby(cmd_stdby_reset_value)
    , m_monbistctrl(monbistctrl_reset_value)
    , m_monfilt(monfilt_reset_value)
{}

void Tricore::Pms::read(std::byte *buffer_out, u32 address, usize length) {
    if (address < pms_memory_start_address ||
        address >= pms_memory_end_address) {
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by PMS peripheral", address)};
    }
    const u32 offset = address - pms_memory_start_address;
    switch (offset) {
    case 0x19CU: {
        spdlog::debug("Pms: accessing PMS.CMD_STDBY in read mode");
        const auto *range_start = reinterpret_cast<std::byte *>(&m_cmd_stdby);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case 0x198U: {
        spdlog::debug("Pms: accessing PMS.MONBISTCTRL in read mode");
        const auto *range_start = reinterpret_cast<std::byte *>(&m_monbistctrl);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case 0x70U: {
        spdlog::debug("Pms: accessing PMS.MONFILT in read mode");
        const auto *range_start = reinterpret_cast<std::byte *>(&m_monfilt);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    default:
        spdlog::warn("Address 0x{:08X} not yet handled by PMS peripheral",
                     address);
        break;
    }
}

void Tricore::Pms::write(const std::byte *buffer_in, u32 address,
                         usize length) {

    if (address < pms_memory_start_address ||
        address >= pms_memory_end_address) {
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by PMS peripheral", address)};
    }
    const u32 offset = address - pms_memory_start_address;
    switch (offset) {
    case 0x19C: {
        spdlog::debug("Pms: accessing PMS.CMD_STDBY in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cmd_stdby));
    } break;
    case 0x198U: {
        spdlog::debug("Pms: accessing PMS.MONBISTCTRL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_monbistctrl));
    } break;
    case 0x70U: {
        spdlog::debug("Pms: accessing PMS.MONFILT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_monfilt));
    } break;
    default:
        spdlog::warn("Address 0x{:08X} not yet handled by PMS peripheral",
                     address);
        break;
    }
}