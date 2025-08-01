
/**
 * @brief Module source for Dma peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Dma.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 dma_clc_reset_value = 0; // TODO: change according manual
constexpr u32 dma_id_reset_value = 0; // TODO: change according manual
constexpr u32 dma_otss_reset_value = 0; // TODO: change according manual
constexpr u32 dma_prr0_reset_value = 0; // TODO: change according manual
constexpr u32 dma_prr1_reset_value = 0; // TODO: change according manual
constexpr u32 dma_time_reset_value = 0; // TODO: change according manual

constexpr u32 dma_memory_start_address = 0xf0010000U;
constexpr u32 dma_memory_size = 0; // TODO: update according manual;
constexpr u32 dma_memory_end_address = dma_memory_start_address + dma_memory_size;

constexpr u32 reg_dma_clc_address = 0xf0010000;
constexpr u32 reg_dma_clc_offset = reg_dma_clc_address - dma_memory_start_address;
constexpr u32 reg_dma_id_address = 0xf0010008;
constexpr u32 reg_dma_id_offset = reg_dma_id_address - dma_memory_start_address;
constexpr u32 reg_dma_otss_address = 0xf0011200;
constexpr u32 reg_dma_otss_offset = reg_dma_otss_address - dma_memory_start_address;
constexpr u32 reg_dma_prr0_address = 0xf0011208;
constexpr u32 reg_dma_prr0_offset = reg_dma_prr0_address - dma_memory_start_address;
constexpr u32 reg_dma_prr1_address = 0xf001120c;
constexpr u32 reg_dma_prr1_offset = reg_dma_prr1_address - dma_memory_start_address;
constexpr u32 reg_dma_time_address = 0xf0011210;
constexpr u32 reg_dma_time_offset = reg_dma_time_address - dma_memory_start_address;

} // anonymous namespace

Tricore::Dma::Dma()
    : m_dma_clc(dma_clc_reset_value)
    , m_dma_id(dma_id_reset_value)
    , m_dma_otss(dma_otss_reset_value)
    , m_dma_prr0(dma_prr0_reset_value)
    , m_dma_prr1(dma_prr1_reset_value)
    , m_dma_time(dma_time_reset_value)
{
}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Dma::read(byte* buffer_out, u32 address, usize length)
{
    const u32 offset = address - dma_memory_start_address;
    switch (offset) {
    case reg_dma_clc_offset: {
        spdlog::debug("DMA: accessing DMA.DMA_CLC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_dma_clc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_dma_id_offset: {
        spdlog::debug("DMA: accessing DMA.DMA_ID in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_dma_id);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_dma_otss_offset: {
        spdlog::debug("DMA: accessing DMA.DMA_OTSS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_dma_otss);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_dma_prr0_offset: {
        spdlog::debug("DMA: accessing DMA.DMA_PRR0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_dma_prr0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_dma_prr1_offset: {
        spdlog::debug("DMA: accessing DMA.DMA_PRR1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_dma_prr1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_dma_time_offset: {
        spdlog::debug("DMA: accessing DMA.DMA_TIME in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_dma_time);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Dma peripheral", address) };
        break;
    }
}

void Tricore::Dma::write(const byte* buffer_in, u32 address,
    usize length)
{
    const u32 offset = address - dma_memory_start_address;
    switch (offset) {
    case reg_dma_clc_offset: {
        spdlog::debug("DMA: accessing DMA.DMA_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_dma_clc));
    } break;
    case reg_dma_id_offset: {
        spdlog::debug("DMA: accessing DMA.DMA_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_dma_id));
    } break;
    case reg_dma_otss_offset: {
        spdlog::debug("DMA: accessing DMA.DMA_OTSS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_dma_otss));
    } break;
    case reg_dma_prr0_offset: {
        spdlog::debug("DMA: accessing DMA.DMA_PRR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_dma_prr0));
    } break;
    case reg_dma_prr1_offset: {
        spdlog::debug("DMA: accessing DMA.DMA_PRR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_dma_prr1));
    } break;
    case reg_dma_time_offset: {
        spdlog::debug("DMA: accessing DMA.DMA_TIME in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_dma_time));
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Dma peripheral", address) };
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
