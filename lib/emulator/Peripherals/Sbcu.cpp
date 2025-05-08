
/**
 * @brief Module source for Sbcu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Sbcu.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 sbcu_id_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_con_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_prioh_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_priol_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_econ_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_eadd_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_edat_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_dbcntl_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_dbgrnt_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_dbadr1_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_dbadr2_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_dbbos_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_dbgntt_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_dbadrt_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_dbbost_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_dbdat_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_alctrl_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_fegen_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 sbcu_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 sbcu_memory_start_address = 0xf0030000U;
constexpr u32 sbcu_memory_size = 0; // TODO: update according manual;
constexpr u32 sbcu_memory_end_address = sbcu_memory_start_address + sbcu_memory_size;

constexpr u32 reg_sbcu_id_address = 0xf0030008;
constexpr u32 reg_sbcu_id_offset = reg_sbcu_id_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_con_address = 0xf0030010;
constexpr u32 reg_sbcu_con_offset = reg_sbcu_con_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_prioh_address = 0xf0030014;
constexpr u32 reg_sbcu_prioh_offset = reg_sbcu_prioh_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_priol_address = 0xf0030018;
constexpr u32 reg_sbcu_priol_offset = reg_sbcu_priol_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_econ_address = 0xf0030020;
constexpr u32 reg_sbcu_econ_offset = reg_sbcu_econ_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_eadd_address = 0xf0030024;
constexpr u32 reg_sbcu_eadd_offset = reg_sbcu_eadd_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_edat_address = 0xf0030028;
constexpr u32 reg_sbcu_edat_offset = reg_sbcu_edat_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_dbcntl_address = 0xf0030030;
constexpr u32 reg_sbcu_dbcntl_offset = reg_sbcu_dbcntl_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_dbgrnt_address = 0xf0030034;
constexpr u32 reg_sbcu_dbgrnt_offset = reg_sbcu_dbgrnt_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_dbadr1_address = 0xf0030038;
constexpr u32 reg_sbcu_dbadr1_offset = reg_sbcu_dbadr1_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_dbadr2_address = 0xf003003c;
constexpr u32 reg_sbcu_dbadr2_offset = reg_sbcu_dbadr2_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_dbbos_address = 0xf0030040;
constexpr u32 reg_sbcu_dbbos_offset = reg_sbcu_dbbos_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_dbgntt_address = 0xf0030044;
constexpr u32 reg_sbcu_dbgntt_offset = reg_sbcu_dbgntt_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_dbadrt_address = 0xf0030048;
constexpr u32 reg_sbcu_dbadrt_offset = reg_sbcu_dbadrt_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_dbbost_address = 0xf003004c;
constexpr u32 reg_sbcu_dbbost_offset = reg_sbcu_dbbost_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_dbdat_address = 0xf0030050;
constexpr u32 reg_sbcu_dbdat_offset = reg_sbcu_dbdat_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_alctrl_address = 0xf0030080;
constexpr u32 reg_sbcu_alctrl_offset = reg_sbcu_alctrl_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_fegen_address = 0xf0030084;
constexpr u32 reg_sbcu_fegen_offset = reg_sbcu_fegen_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_accen1_address = 0xf00300f8;
constexpr u32 reg_sbcu_accen1_offset = reg_sbcu_accen1_address - sbcu_memory_start_address;
constexpr u32 reg_sbcu_accen0_address = 0xf00300fc;
constexpr u32 reg_sbcu_accen0_offset = reg_sbcu_accen0_address - sbcu_memory_start_address;

} // anonymous namespace


Tricore::Sbcu::Sbcu()
    : m_sbcu_id(sbcu_id_reset_value)
    , m_sbcu_con(sbcu_con_reset_value)
    , m_sbcu_prioh(sbcu_prioh_reset_value)
    , m_sbcu_priol(sbcu_priol_reset_value)
    , m_sbcu_econ(sbcu_econ_reset_value)
    , m_sbcu_eadd(sbcu_eadd_reset_value)
    , m_sbcu_edat(sbcu_edat_reset_value)
    , m_sbcu_dbcntl(sbcu_dbcntl_reset_value)
    , m_sbcu_dbgrnt(sbcu_dbgrnt_reset_value)
    , m_sbcu_dbadr1(sbcu_dbadr1_reset_value)
    , m_sbcu_dbadr2(sbcu_dbadr2_reset_value)
    , m_sbcu_dbbos(sbcu_dbbos_reset_value)
    , m_sbcu_dbgntt(sbcu_dbgntt_reset_value)
    , m_sbcu_dbadrt(sbcu_dbadrt_reset_value)
    , m_sbcu_dbbost(sbcu_dbbost_reset_value)
    , m_sbcu_dbdat(sbcu_dbdat_reset_value)
    , m_sbcu_alctrl(sbcu_alctrl_reset_value)
    , m_sbcu_fegen(sbcu_fegen_reset_value)
    , m_sbcu_accen1(sbcu_accen1_reset_value)
    , m_sbcu_accen0(sbcu_accen0_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Sbcu::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - sbcu_memory_start_address;
    switch (offset) {
    case reg_sbcu_id_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_con_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_CON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_prioh_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_PRIOH in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_prioh);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_priol_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_PRIOL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_priol);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_econ_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_ECON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_econ);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_eadd_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_EADD in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_eadd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_edat_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_EDAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_edat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_dbcntl_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_DBCNTL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_dbcntl);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_dbgrnt_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_DBGRNT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_dbgrnt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_dbadr1_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_DBADR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_dbadr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_dbadr2_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_DBADR2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_dbadr2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_dbbos_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_DBBOS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_dbbos);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_dbgntt_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_DBGNTT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_dbgntt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_dbadrt_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_DBADRT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_dbadrt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_dbbost_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_DBBOST in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_dbbost);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_dbdat_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_DBDAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_dbdat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_alctrl_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_ALCTRL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_alctrl);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_fegen_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_FEGEN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_fegen);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_accen1_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sbcu_accen0_offset: {
            spdlog::debug("SBCU: accessing SBCU.SBCU_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sbcu_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Sbcu peripheral", address)};
        break;
    }
}

void Tricore::Sbcu::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - sbcu_memory_start_address;
    switch (offset) {
    case reg_sbcu_id_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_id));
    } break;
    case reg_sbcu_con_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_con));
    } break;
    case reg_sbcu_prioh_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_PRIOH in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_prioh));
    } break;
    case reg_sbcu_priol_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_PRIOL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_priol));
    } break;
    case reg_sbcu_econ_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_ECON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_econ));
    } break;
    case reg_sbcu_eadd_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_EADD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_eadd));
    } break;
    case reg_sbcu_edat_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_EDAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_edat));
    } break;
    case reg_sbcu_dbcntl_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_DBCNTL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_dbcntl));
    } break;
    case reg_sbcu_dbgrnt_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_DBGRNT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_dbgrnt));
    } break;
    case reg_sbcu_dbadr1_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_DBADR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_dbadr1));
    } break;
    case reg_sbcu_dbadr2_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_DBADR2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_dbadr2));
    } break;
    case reg_sbcu_dbbos_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_DBBOS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_dbbos));
    } break;
    case reg_sbcu_dbgntt_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_DBGNTT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_dbgntt));
    } break;
    case reg_sbcu_dbadrt_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_DBADRT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_dbadrt));
    } break;
    case reg_sbcu_dbbost_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_DBBOST in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_dbbost));
    } break;
    case reg_sbcu_dbdat_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_DBDAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_dbdat));
    } break;
    case reg_sbcu_alctrl_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_ALCTRL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_alctrl));
    } break;
    case reg_sbcu_fegen_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_FEGEN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_fegen));
    } break;
    case reg_sbcu_accen1_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_accen1));
    } break;
    case reg_sbcu_accen0_offset: {
        spdlog::debug("SBCU: accessing SBCU.SBCU_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sbcu_accen0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Sbcu peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
