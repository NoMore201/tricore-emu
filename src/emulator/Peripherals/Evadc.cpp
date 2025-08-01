
/**
 * @brief Module source for Evadc peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Evadc.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 evadc_clc_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_id_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_globcfg_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_accprot0_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_accprot1_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_accprot2_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_glob_bound_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_glob_eflag_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_glob_evnp_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_glob_tf_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_glob_te_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_glob_rcr_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_glob_res_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_glob_resd_reset_value = 0; // TODO: change according manual
constexpr u32 evadc_emuxsel_reset_value = 0; // TODO: change according manual

constexpr u32 evadc_memory_start_address = 0xf0020000U;
constexpr u32 evadc_memory_size = 0; // TODO: update according manual;
constexpr u32 evadc_memory_end_address = evadc_memory_start_address + evadc_memory_size;

constexpr u32 reg_evadc_clc_address = 0xf0020000;
constexpr u32 reg_evadc_clc_offset = reg_evadc_clc_address - evadc_memory_start_address;
constexpr u32 reg_evadc_id_address = 0xf0020008;
constexpr u32 reg_evadc_id_offset = reg_evadc_id_address - evadc_memory_start_address;
constexpr u32 reg_evadc_ocs_address = 0xf0020028;
constexpr u32 reg_evadc_ocs_offset = reg_evadc_ocs_address - evadc_memory_start_address;
constexpr u32 reg_evadc_krstclr_address = 0xf002002c;
constexpr u32 reg_evadc_krstclr_offset = reg_evadc_krstclr_address - evadc_memory_start_address;
constexpr u32 reg_evadc_krst1_address = 0xf0020030;
constexpr u32 reg_evadc_krst1_offset = reg_evadc_krst1_address - evadc_memory_start_address;
constexpr u32 reg_evadc_krst0_address = 0xf0020034;
constexpr u32 reg_evadc_krst0_offset = reg_evadc_krst0_address - evadc_memory_start_address;
constexpr u32 reg_evadc_accen0_address = 0xf002003c;
constexpr u32 reg_evadc_accen0_offset = reg_evadc_accen0_address - evadc_memory_start_address;
constexpr u32 reg_evadc_globcfg_address = 0xf0020080;
constexpr u32 reg_evadc_globcfg_offset = reg_evadc_globcfg_address - evadc_memory_start_address;
constexpr u32 reg_evadc_accprot0_address = 0xf0020088;
constexpr u32 reg_evadc_accprot0_offset = reg_evadc_accprot0_address - evadc_memory_start_address;
constexpr u32 reg_evadc_accprot1_address = 0xf002008c;
constexpr u32 reg_evadc_accprot1_offset = reg_evadc_accprot1_address - evadc_memory_start_address;
constexpr u32 reg_evadc_accprot2_address = 0xf0020090;
constexpr u32 reg_evadc_accprot2_offset = reg_evadc_accprot2_address - evadc_memory_start_address;
constexpr u32 reg_evadc_glob_bound_address = 0xf00200b8;
constexpr u32 reg_evadc_glob_bound_offset = reg_evadc_glob_bound_address - evadc_memory_start_address;
constexpr u32 reg_evadc_glob_eflag_address = 0xf00200e0;
constexpr u32 reg_evadc_glob_eflag_offset = reg_evadc_glob_eflag_address - evadc_memory_start_address;
constexpr u32 reg_evadc_glob_evnp_address = 0xf0020140;
constexpr u32 reg_evadc_glob_evnp_offset = reg_evadc_glob_evnp_address - evadc_memory_start_address;
constexpr u32 reg_evadc_glob_tf_address = 0xf0020160;
constexpr u32 reg_evadc_glob_tf_offset = reg_evadc_glob_tf_address - evadc_memory_start_address;
constexpr u32 reg_evadc_glob_te_address = 0xf0020164;
constexpr u32 reg_evadc_glob_te_offset = reg_evadc_glob_te_address - evadc_memory_start_address;
constexpr u32 reg_evadc_glob_rcr_address = 0xf0020280;
constexpr u32 reg_evadc_glob_rcr_offset = reg_evadc_glob_rcr_address - evadc_memory_start_address;
constexpr u32 reg_evadc_glob_res_address = 0xf0020300;
constexpr u32 reg_evadc_glob_res_offset = reg_evadc_glob_res_address - evadc_memory_start_address;
constexpr u32 reg_evadc_glob_resd_address = 0xf0020380;
constexpr u32 reg_evadc_glob_resd_offset = reg_evadc_glob_resd_address - evadc_memory_start_address;
constexpr u32 reg_evadc_emuxsel_address = 0xf00203f0;
constexpr u32 reg_evadc_emuxsel_offset = reg_evadc_emuxsel_address - evadc_memory_start_address;

} // anonymous namespace

Tricore::Evadc::Evadc()
    : m_evadc_clc(evadc_clc_reset_value)
    , m_evadc_id(evadc_id_reset_value)
    , m_evadc_ocs(evadc_ocs_reset_value)
    , m_evadc_krstclr(evadc_krstclr_reset_value)
    , m_evadc_krst1(evadc_krst1_reset_value)
    , m_evadc_krst0(evadc_krst0_reset_value)
    , m_evadc_accen0(evadc_accen0_reset_value)
    , m_evadc_globcfg(evadc_globcfg_reset_value)
    , m_evadc_accprot0(evadc_accprot0_reset_value)
    , m_evadc_accprot1(evadc_accprot1_reset_value)
    , m_evadc_accprot2(evadc_accprot2_reset_value)
    , m_evadc_glob_bound(evadc_glob_bound_reset_value)
    , m_evadc_glob_eflag(evadc_glob_eflag_reset_value)
    , m_evadc_glob_evnp(evadc_glob_evnp_reset_value)
    , m_evadc_glob_tf(evadc_glob_tf_reset_value)
    , m_evadc_glob_te(evadc_glob_te_reset_value)
    , m_evadc_glob_rcr(evadc_glob_rcr_reset_value)
    , m_evadc_glob_res(evadc_glob_res_reset_value)
    , m_evadc_glob_resd(evadc_glob_resd_reset_value)
    , m_evadc_emuxsel(evadc_emuxsel_reset_value)
{
}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Evadc::read(byte* buffer_out, u32 address, usize length)
{
    const u32 offset = address - evadc_memory_start_address;
    switch (offset) {
    case reg_evadc_clc_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_CLC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_clc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_id_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_ID in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_id);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_ocs_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_OCS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_ocs);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_krstclr_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_KRSTCLR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_krstclr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_krst1_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_KRST1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_krst1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_krst0_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_KRST0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_krst0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_accen0_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_ACCEN0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_accen0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_globcfg_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOBCFG in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_globcfg);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_accprot0_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_ACCPROT0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_accprot0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_accprot1_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_ACCPROT1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_accprot1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_accprot2_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_ACCPROT2 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_accprot2);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_glob_bound_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_BOUND in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_glob_bound);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_glob_eflag_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_EFLAG in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_glob_eflag);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_glob_evnp_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_EVNP in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_glob_evnp);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_glob_tf_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_TF in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_glob_tf);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_glob_te_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_TE in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_glob_te);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_glob_rcr_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_RCR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_glob_rcr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_glob_res_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_RES in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_glob_res);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_glob_resd_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_RESD in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_glob_resd);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_evadc_emuxsel_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_EMUXSEL in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_evadc_emuxsel);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Evadc peripheral", address) };
        break;
    }
}

void Tricore::Evadc::write(const byte* buffer_in, u32 address,
    usize length)
{
    const u32 offset = address - evadc_memory_start_address;
    switch (offset) {
    case reg_evadc_clc_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_clc));
    } break;
    case reg_evadc_id_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_id));
    } break;
    case reg_evadc_ocs_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_ocs));
    } break;
    case reg_evadc_krstclr_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_krstclr));
    } break;
    case reg_evadc_krst1_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_krst1));
    } break;
    case reg_evadc_krst0_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_krst0));
    } break;
    case reg_evadc_accen0_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_accen0));
    } break;
    case reg_evadc_globcfg_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOBCFG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_globcfg));
    } break;
    case reg_evadc_accprot0_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_ACCPROT0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_accprot0));
    } break;
    case reg_evadc_accprot1_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_ACCPROT1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_accprot1));
    } break;
    case reg_evadc_accprot2_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_ACCPROT2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_accprot2));
    } break;
    case reg_evadc_glob_bound_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_BOUND in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_glob_bound));
    } break;
    case reg_evadc_glob_eflag_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_EFLAG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_glob_eflag));
    } break;
    case reg_evadc_glob_evnp_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_EVNP in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_glob_evnp));
    } break;
    case reg_evadc_glob_tf_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_TF in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_glob_tf));
    } break;
    case reg_evadc_glob_te_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_TE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_glob_te));
    } break;
    case reg_evadc_glob_rcr_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_RCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_glob_rcr));
    } break;
    case reg_evadc_glob_res_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_RES in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_glob_res));
    } break;
    case reg_evadc_glob_resd_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_GLOB_RESD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_glob_resd));
    } break;
    case reg_evadc_emuxsel_offset: {
        spdlog::debug("EVADC: accessing EVADC.EVADC_EMUXSEL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_evadc_emuxsel));
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Evadc peripheral", address) };
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
