
/**
 * @brief Module source for Src peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Src.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {



constexpr u32 src_memory_start_address = 0xf0038000U;
constexpr u32 src_memory_size = 0; // TODO: update according manual;
constexpr u32 src_memory_end_address = src_memory_start_address + src_memory_size;



} // anonymous namespace


Tricore::Src::Src()
    :
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Src::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - src_memory_start_address;
    switch (offset) {

    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Src peripheral", address)};
        break;
    }
}

void Tricore::Src::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - src_memory_start_address;
    switch (offset) {

    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Src peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
