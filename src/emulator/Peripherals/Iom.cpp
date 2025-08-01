
/**
 * @brief Module source for Iom peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Iom.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 iom_clc_reset_value = 0; // TODO: change according manual
constexpr u32 iom_id_reset_value = 0; // TODO: change according manual
constexpr u32 iom_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 iom_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 iom_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 iom_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 iom_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 iom_ecmccfg_reset_value = 0; // TODO: change according manual
constexpr u32 iom_ecmselr_reset_value = 0; // TODO: change according manual
constexpr u32 iom_ecmeth0_reset_value = 0; // TODO: change according manual
constexpr u32 iom_ecmeth1_reset_value = 0; // TODO: change according manual
constexpr u32 iom_gtmexr_reset_value = 0; // TODO: change according manual
constexpr u32 iom_fpcesr_reset_value = 0; // TODO: change according manual

constexpr u32 iom_memory_start_address = 0xf0035000U;
constexpr u32 iom_memory_size = 0; // TODO: update according manual;
constexpr u32 iom_memory_end_address = iom_memory_start_address + iom_memory_size;

constexpr u32 reg_iom_clc_address = 0xf0035000;
constexpr u32 reg_iom_clc_offset = reg_iom_clc_address - iom_memory_start_address;
constexpr u32 reg_iom_id_address = 0xf0035008;
constexpr u32 reg_iom_id_offset = reg_iom_id_address - iom_memory_start_address;
constexpr u32 reg_iom_krstclr_address = 0xf003501c;
constexpr u32 reg_iom_krstclr_offset = reg_iom_krstclr_address - iom_memory_start_address;
constexpr u32 reg_iom_krst1_address = 0xf0035020;
constexpr u32 reg_iom_krst1_offset = reg_iom_krst1_address - iom_memory_start_address;
constexpr u32 reg_iom_krst0_address = 0xf0035024;
constexpr u32 reg_iom_krst0_offset = reg_iom_krst0_address - iom_memory_start_address;
constexpr u32 reg_iom_accen1_address = 0xf0035028;
constexpr u32 reg_iom_accen1_offset = reg_iom_accen1_address - iom_memory_start_address;
constexpr u32 reg_iom_accen0_address = 0xf003502c;
constexpr u32 reg_iom_accen0_offset = reg_iom_accen0_address - iom_memory_start_address;
constexpr u32 reg_iom_ecmccfg_address = 0xf0035030;
constexpr u32 reg_iom_ecmccfg_offset = reg_iom_ecmccfg_address - iom_memory_start_address;
constexpr u32 reg_iom_ecmselr_address = 0xf0035034;
constexpr u32 reg_iom_ecmselr_offset = reg_iom_ecmselr_address - iom_memory_start_address;
constexpr u32 reg_iom_ecmeth0_address = 0xf0035038;
constexpr u32 reg_iom_ecmeth0_offset = reg_iom_ecmeth0_address - iom_memory_start_address;
constexpr u32 reg_iom_ecmeth1_address = 0xf003503c;
constexpr u32 reg_iom_ecmeth1_offset = reg_iom_ecmeth1_address - iom_memory_start_address;
constexpr u32 reg_iom_gtmexr_address = 0xf0035040;
constexpr u32 reg_iom_gtmexr_offset = reg_iom_gtmexr_address - iom_memory_start_address;
constexpr u32 reg_iom_fpcesr_address = 0xf0035078;
constexpr u32 reg_iom_fpcesr_offset = reg_iom_fpcesr_address - iom_memory_start_address;

} // anonymous namespace

Tricore::Iom::Iom()
    : m_iom_clc(iom_clc_reset_value)
    , m_iom_id(iom_id_reset_value)
    , m_iom_krstclr(iom_krstclr_reset_value)
    , m_iom_krst1(iom_krst1_reset_value)
    , m_iom_krst0(iom_krst0_reset_value)
    , m_iom_accen1(iom_accen1_reset_value)
    , m_iom_accen0(iom_accen0_reset_value)
    , m_iom_ecmccfg(iom_ecmccfg_reset_value)
    , m_iom_ecmselr(iom_ecmselr_reset_value)
    , m_iom_ecmeth0(iom_ecmeth0_reset_value)
    , m_iom_ecmeth1(iom_ecmeth1_reset_value)
    , m_iom_gtmexr(iom_gtmexr_reset_value)
    , m_iom_fpcesr(iom_fpcesr_reset_value)
{
}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Iom::read(byte* buffer_out, u32 address, usize length)
{
    const u32 offset = address - iom_memory_start_address;
    switch (offset) {
    case reg_iom_clc_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_CLC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_clc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_iom_id_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ID in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_id);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_iom_krstclr_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_KRSTCLR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_krstclr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_iom_krst1_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_KRST1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_krst1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_iom_krst0_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_KRST0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_krst0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_iom_accen1_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ACCEN1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_accen1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_iom_accen0_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ACCEN0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_accen0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_iom_ecmccfg_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ECMCCFG in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_ecmccfg);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_iom_ecmselr_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ECMSELR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_ecmselr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_iom_ecmeth0_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ECMETH0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_ecmeth0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_iom_ecmeth1_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ECMETH1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_ecmeth1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_iom_gtmexr_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_GTMEXR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_gtmexr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_iom_fpcesr_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_FPCESR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_iom_fpcesr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Iom peripheral", address) };
        break;
    }
}

void Tricore::Iom::write(const byte* buffer_in, u32 address,
    usize length)
{
    const u32 offset = address - iom_memory_start_address;
    switch (offset) {
    case reg_iom_clc_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_clc));
    } break;
    case reg_iom_id_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_id));
    } break;
    case reg_iom_krstclr_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_krstclr));
    } break;
    case reg_iom_krst1_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_krst1));
    } break;
    case reg_iom_krst0_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_krst0));
    } break;
    case reg_iom_accen1_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_accen1));
    } break;
    case reg_iom_accen0_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_accen0));
    } break;
    case reg_iom_ecmccfg_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ECMCCFG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_ecmccfg));
    } break;
    case reg_iom_ecmselr_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ECMSELR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_ecmselr));
    } break;
    case reg_iom_ecmeth0_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ECMETH0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_ecmeth0));
    } break;
    case reg_iom_ecmeth1_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_ECMETH1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_ecmeth1));
    } break;
    case reg_iom_gtmexr_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_GTMEXR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_gtmexr));
    } break;
    case reg_iom_fpcesr_offset: {
        spdlog::debug("IOM: accessing IOM.IOM_FPCESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_iom_fpcesr));
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Iom peripheral", address) };
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
