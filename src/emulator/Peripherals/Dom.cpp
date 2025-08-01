
/**
 * @brief Module source for Dom peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Dom.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 dom0_id_reset_value = 0; // TODO: change according manual
constexpr u32 dom0_pestat_reset_value = 0; // TODO: change according manual
constexpr u32 dom0_tidstat_reset_value = 0; // TODO: change according manual
constexpr u32 dom0_tiden_reset_value = 0; // TODO: change according manual
constexpr u32 dom0_brcon_reset_value = 0; // TODO: change according manual
constexpr u32 dom0_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 dom0_accen1_reset_value = 0; // TODO: change according manual

constexpr u32 dom_memory_start_address = 0xf8700000U;
constexpr u32 dom_memory_size = 0; // TODO: update according manual;
constexpr u32 dom_memory_end_address = dom_memory_start_address + dom_memory_size;

constexpr u32 reg_dom0_id_address = 0xf8700408;
constexpr u32 reg_dom0_id_offset = reg_dom0_id_address - dom_memory_start_address;
constexpr u32 reg_dom0_pestat_address = 0xf8700410;
constexpr u32 reg_dom0_pestat_offset = reg_dom0_pestat_address - dom_memory_start_address;
constexpr u32 reg_dom0_tidstat_address = 0xf8700418;
constexpr u32 reg_dom0_tidstat_offset = reg_dom0_tidstat_address - dom_memory_start_address;
constexpr u32 reg_dom0_tiden_address = 0xf8700420;
constexpr u32 reg_dom0_tiden_offset = reg_dom0_tiden_address - dom_memory_start_address;
constexpr u32 reg_dom0_brcon_address = 0xf8700430;
constexpr u32 reg_dom0_brcon_offset = reg_dom0_brcon_address - dom_memory_start_address;
constexpr u32 reg_dom0_accen0_address = 0xf87004f0;
constexpr u32 reg_dom0_accen0_offset = reg_dom0_accen0_address - dom_memory_start_address;
constexpr u32 reg_dom0_accen1_address = 0xf87004f8;
constexpr u32 reg_dom0_accen1_offset = reg_dom0_accen1_address - dom_memory_start_address;

} // anonymous namespace


Tricore::Dom::Dom()
    : m_dom0_id(dom0_id_reset_value)
    , m_dom0_pestat(dom0_pestat_reset_value)
    , m_dom0_tidstat(dom0_tidstat_reset_value)
    , m_dom0_tiden(dom0_tiden_reset_value)
    , m_dom0_brcon(dom0_brcon_reset_value)
    , m_dom0_accen0(dom0_accen0_reset_value)
    , m_dom0_accen1(dom0_accen1_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Dom::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - dom_memory_start_address;
    switch (offset) {
    case reg_dom0_id_offset: {
            spdlog::debug("DOM: accessing DOM.DOM0_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dom0_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dom0_pestat_offset: {
            spdlog::debug("DOM: accessing DOM.DOM0_PESTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dom0_pestat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dom0_tidstat_offset: {
            spdlog::debug("DOM: accessing DOM.DOM0_TIDSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dom0_tidstat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dom0_tiden_offset: {
            spdlog::debug("DOM: accessing DOM.DOM0_TIDEN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dom0_tiden);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dom0_brcon_offset: {
            spdlog::debug("DOM: accessing DOM.DOM0_BRCON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dom0_brcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dom0_accen0_offset: {
            spdlog::debug("DOM: accessing DOM.DOM0_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dom0_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dom0_accen1_offset: {
            spdlog::debug("DOM: accessing DOM.DOM0_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dom0_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Dom peripheral", address)};
        break;
    }
}

void Tricore::Dom::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - dom_memory_start_address;
    switch (offset) {
    case reg_dom0_id_offset: {
        spdlog::debug("DOM: accessing DOM.DOM0_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dom0_id));
    } break;
    case reg_dom0_pestat_offset: {
        spdlog::debug("DOM: accessing DOM.DOM0_PESTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dom0_pestat));
    } break;
    case reg_dom0_tidstat_offset: {
        spdlog::debug("DOM: accessing DOM.DOM0_TIDSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dom0_tidstat));
    } break;
    case reg_dom0_tiden_offset: {
        spdlog::debug("DOM: accessing DOM.DOM0_TIDEN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dom0_tiden));
    } break;
    case reg_dom0_brcon_offset: {
        spdlog::debug("DOM: accessing DOM.DOM0_BRCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dom0_brcon));
    } break;
    case reg_dom0_accen0_offset: {
        spdlog::debug("DOM: accessing DOM.DOM0_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dom0_accen0));
    } break;
    case reg_dom0_accen1_offset: {
        spdlog::debug("DOM: accessing DOM.DOM0_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dom0_accen1));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Dom peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
