
/**
 * @brief Module source for Mtu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Mtu.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 mtu_clc_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_id_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memtest0_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memtest1_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memtest2_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memmap_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memstat0_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memstat1_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memstat2_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memdone0_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memdone1_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memdone2_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memfda0_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memfda1_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_memfda2_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 mtu_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 mtu_memory_start_address = 0xf0060000U;
constexpr u32 mtu_memory_size = 0; // TODO: update according manual;
constexpr u32 mtu_memory_end_address = mtu_memory_start_address + mtu_memory_size;

constexpr u32 reg_mtu_clc_address = 0xf0060000;
constexpr u32 reg_mtu_clc_offset = reg_mtu_clc_address - mtu_memory_start_address;
constexpr u32 reg_mtu_id_address = 0xf0060008;
constexpr u32 reg_mtu_id_offset = reg_mtu_id_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memtest0_address = 0xf0060010;
constexpr u32 reg_mtu_memtest0_offset = reg_mtu_memtest0_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memtest1_address = 0xf0060014;
constexpr u32 reg_mtu_memtest1_offset = reg_mtu_memtest1_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memtest2_address = 0xf0060018;
constexpr u32 reg_mtu_memtest2_offset = reg_mtu_memtest2_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memmap_address = 0xf006001c;
constexpr u32 reg_mtu_memmap_offset = reg_mtu_memmap_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memstat0_address = 0xf0060038;
constexpr u32 reg_mtu_memstat0_offset = reg_mtu_memstat0_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memstat1_address = 0xf006003c;
constexpr u32 reg_mtu_memstat1_offset = reg_mtu_memstat1_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memstat2_address = 0xf0060040;
constexpr u32 reg_mtu_memstat2_offset = reg_mtu_memstat2_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memdone0_address = 0xf0060050;
constexpr u32 reg_mtu_memdone0_offset = reg_mtu_memdone0_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memdone1_address = 0xf0060054;
constexpr u32 reg_mtu_memdone1_offset = reg_mtu_memdone1_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memdone2_address = 0xf0060058;
constexpr u32 reg_mtu_memdone2_offset = reg_mtu_memdone2_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memfda0_address = 0xf0060060;
constexpr u32 reg_mtu_memfda0_offset = reg_mtu_memfda0_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memfda1_address = 0xf0060064;
constexpr u32 reg_mtu_memfda1_offset = reg_mtu_memfda1_address - mtu_memory_start_address;
constexpr u32 reg_mtu_memfda2_address = 0xf0060068;
constexpr u32 reg_mtu_memfda2_offset = reg_mtu_memfda2_address - mtu_memory_start_address;
constexpr u32 reg_mtu_accen1_address = 0xf00600f8;
constexpr u32 reg_mtu_accen1_offset = reg_mtu_accen1_address - mtu_memory_start_address;
constexpr u32 reg_mtu_accen0_address = 0xf00600fc;
constexpr u32 reg_mtu_accen0_offset = reg_mtu_accen0_address - mtu_memory_start_address;

} // anonymous namespace


Tricore::Peripherals::Mtu::Mtu()
    : m_mtu_clc(mtu_clc_reset_value)
    , m_mtu_id(mtu_id_reset_value)
    , m_mtu_memtest0(mtu_memtest0_reset_value)
    , m_mtu_memtest1(mtu_memtest1_reset_value)
    , m_mtu_memtest2(mtu_memtest2_reset_value)
    , m_mtu_memmap(mtu_memmap_reset_value)
    , m_mtu_memstat0(mtu_memstat0_reset_value)
    , m_mtu_memstat1(mtu_memstat1_reset_value)
    , m_mtu_memstat2(mtu_memstat2_reset_value)
    , m_mtu_memdone0(mtu_memdone0_reset_value)
    , m_mtu_memdone1(mtu_memdone1_reset_value)
    , m_mtu_memdone2(mtu_memdone2_reset_value)
    , m_mtu_memfda0(mtu_memfda0_reset_value)
    , m_mtu_memfda1(mtu_memfda1_reset_value)
    , m_mtu_memfda2(mtu_memfda2_reset_value)
    , m_mtu_accen1(mtu_accen1_reset_value)
    , m_mtu_accen0(mtu_accen0_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Peripherals::Mtu::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - mtu_memory_start_address;
    switch (offset) {
    case reg_mtu_clc_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_CLC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_id_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memtest0_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMTEST0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memtest0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memtest1_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMTEST1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memtest1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memtest2_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMTEST2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memtest2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memmap_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMMAP in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memmap);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memstat0_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMSTAT0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memstat0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memstat1_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMSTAT1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memstat1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memstat2_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMSTAT2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memstat2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memdone0_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMDONE0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memdone0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memdone1_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMDONE1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memdone1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memdone2_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMDONE2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memdone2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memfda0_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMFDA0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memfda0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memfda1_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMFDA1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memfda1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_memfda2_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_MEMFDA2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_memfda2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_accen1_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_mtu_accen0_offset: {
            spdlog::debug("MTU: accessing MTU.MTU_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_mtu_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Mtu peripheral", address)};
        break;
    }
}

void Tricore::Peripherals::Mtu::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - mtu_memory_start_address;
    switch (offset) {
    case reg_mtu_clc_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_clc));
    } break;
    case reg_mtu_id_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_id));
    } break;
    case reg_mtu_memtest0_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMTEST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memtest0));
    } break;
    case reg_mtu_memtest1_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMTEST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memtest1));
    } break;
    case reg_mtu_memtest2_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMTEST2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memtest2));
    } break;
    case reg_mtu_memmap_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMMAP in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memmap));
    } break;
    case reg_mtu_memstat0_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMSTAT0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memstat0));
    } break;
    case reg_mtu_memstat1_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMSTAT1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memstat1));
    } break;
    case reg_mtu_memstat2_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMSTAT2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memstat2));
    } break;
    case reg_mtu_memdone0_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMDONE0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memdone0));
    } break;
    case reg_mtu_memdone1_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMDONE1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memdone1));
    } break;
    case reg_mtu_memdone2_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMDONE2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memdone2));
    } break;
    case reg_mtu_memfda0_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMFDA0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memfda0));
    } break;
    case reg_mtu_memfda1_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMFDA1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memfda1));
    } break;
    case reg_mtu_memfda2_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_MEMFDA2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_memfda2));
    } break;
    case reg_mtu_accen1_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_accen1));
    } break;
    case reg_mtu_accen0_offset: {
        spdlog::debug("MTU: accessing MTU.MTU_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_mtu_accen0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Mtu peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
