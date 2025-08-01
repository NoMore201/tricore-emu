
/**
 * @brief Module source for Converter peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Converter.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 converter_clc_reset_value = 0; // TODO: change according manual
constexpr u32 converter_id_reset_value = 0; // TODO: change according manual
constexpr u32 converter_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 converter_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 converter_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 converter_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 converter_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 converter_ccctrl_reset_value = 0; // TODO: change according manual
constexpr u32 converter_phscfg_reset_value = 0; // TODO: change according manual
constexpr u32 converter_phssfty_reset_value = 0; // TODO: change according manual

constexpr u32 converter_memory_start_address = 0xf0025000U;
constexpr u32 converter_memory_size = 0; // TODO: update according manual;
constexpr u32 converter_memory_end_address = converter_memory_start_address + converter_memory_size;

constexpr u32 reg_converter_clc_address = 0xf0025000;
constexpr u32 reg_converter_clc_offset = reg_converter_clc_address - converter_memory_start_address;
constexpr u32 reg_converter_id_address = 0xf0025008;
constexpr u32 reg_converter_id_offset = reg_converter_id_address - converter_memory_start_address;
constexpr u32 reg_converter_ocs_address = 0xf0025028;
constexpr u32 reg_converter_ocs_offset = reg_converter_ocs_address - converter_memory_start_address;
constexpr u32 reg_converter_krstclr_address = 0xf002502c;
constexpr u32 reg_converter_krstclr_offset = reg_converter_krstclr_address - converter_memory_start_address;
constexpr u32 reg_converter_krst1_address = 0xf0025030;
constexpr u32 reg_converter_krst1_offset = reg_converter_krst1_address - converter_memory_start_address;
constexpr u32 reg_converter_krst0_address = 0xf0025034;
constexpr u32 reg_converter_krst0_offset = reg_converter_krst0_address - converter_memory_start_address;
constexpr u32 reg_converter_accen0_address = 0xf002503c;
constexpr u32 reg_converter_accen0_offset = reg_converter_accen0_address - converter_memory_start_address;
constexpr u32 reg_converter_ccctrl_address = 0xf002507c;
constexpr u32 reg_converter_ccctrl_offset = reg_converter_ccctrl_address - converter_memory_start_address;
constexpr u32 reg_converter_phscfg_address = 0xf0025080;
constexpr u32 reg_converter_phscfg_offset = reg_converter_phscfg_address - converter_memory_start_address;
constexpr u32 reg_converter_phssfty_address = 0xf0025084;
constexpr u32 reg_converter_phssfty_offset = reg_converter_phssfty_address - converter_memory_start_address;

} // anonymous namespace

Tricore::Converter::Converter()
    : m_converter_clc(converter_clc_reset_value)
    , m_converter_id(converter_id_reset_value)
    , m_converter_ocs(converter_ocs_reset_value)
    , m_converter_krstclr(converter_krstclr_reset_value)
    , m_converter_krst1(converter_krst1_reset_value)
    , m_converter_krst0(converter_krst0_reset_value)
    , m_converter_accen0(converter_accen0_reset_value)
    , m_converter_ccctrl(converter_ccctrl_reset_value)
    , m_converter_phscfg(converter_phscfg_reset_value)
    , m_converter_phssfty(converter_phssfty_reset_value)
{
}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Converter::read(byte* buffer_out, u32 address, usize length)
{
    const u32 offset = address - converter_memory_start_address;
    switch (offset) {
    case reg_converter_clc_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_CLC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_converter_clc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_converter_id_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_ID in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_converter_id);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_converter_ocs_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_OCS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_converter_ocs);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_converter_krstclr_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_KRSTCLR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_converter_krstclr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_converter_krst1_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_KRST1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_converter_krst1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_converter_krst0_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_KRST0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_converter_krst0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_converter_accen0_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_ACCEN0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_converter_accen0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_converter_ccctrl_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_CCCTRL in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_converter_ccctrl);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_converter_phscfg_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_PHSCFG in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_converter_phscfg);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_converter_phssfty_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_PHSSFTY in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_converter_phssfty);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Converter peripheral", address) };
        break;
    }
}

void Tricore::Converter::write(const byte* buffer_in, u32 address,
    usize length)
{
    const u32 offset = address - converter_memory_start_address;
    switch (offset) {
    case reg_converter_clc_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_converter_clc));
    } break;
    case reg_converter_id_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_converter_id));
    } break;
    case reg_converter_ocs_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_converter_ocs));
    } break;
    case reg_converter_krstclr_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_converter_krstclr));
    } break;
    case reg_converter_krst1_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_converter_krst1));
    } break;
    case reg_converter_krst0_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_converter_krst0));
    } break;
    case reg_converter_accen0_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_converter_accen0));
    } break;
    case reg_converter_ccctrl_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_CCCTRL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_converter_ccctrl));
    } break;
    case reg_converter_phscfg_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_PHSCFG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_converter_phscfg));
    } break;
    case reg_converter_phssfty_offset: {
        spdlog::debug("CONVERTER: accessing CONVERTER.CONVERTER_PHSSFTY in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_converter_phssfty));
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Converter peripheral", address) };
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
