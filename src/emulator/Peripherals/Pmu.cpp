
/**
 * @brief Module source for Pmu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Pmu.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 pmu_id_reset_value = 0; // TODO: change according manual

constexpr u32 pmu_memory_start_address = 0xf8038000U;
constexpr u32 pmu_memory_size = 0; // TODO: update according manual;
constexpr u32 pmu_memory_end_address = pmu_memory_start_address + pmu_memory_size;

constexpr u32 reg_pmu_id_address = 0xf8038508;
constexpr u32 reg_pmu_id_offset = reg_pmu_id_address - pmu_memory_start_address;

} // anonymous namespace

Tricore::Pmu::Pmu()
    : m_pmu_id(pmu_id_reset_value)
{
}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Pmu::read(byte* buffer_out, u32 address, usize length)
{
    const u32 offset = address - pmu_memory_start_address;
    switch (offset) {
    case reg_pmu_id_offset: {
        spdlog::debug("PMU: accessing PMU.PMU_ID in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_pmu_id);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Pmu peripheral", address) };
        break;
    }
}

void Tricore::Pmu::write(const byte* buffer_in, u32 address,
    usize length)
{
    const u32 offset = address - pmu_memory_start_address;
    switch (offset) {
    case reg_pmu_id_offset: {
        spdlog::debug("PMU: accessing PMU.PMU_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_pmu_id));
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Pmu peripheral", address) };
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
