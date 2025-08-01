
/**
 * @brief Module source for Smu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Smu.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <gsl/assert>
#include <gsl/span>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 smu_clc_reset_value = 0;    // TODO: change according manual
constexpr u32 smu_id_reset_value = 0;     // TODO: change according manual
constexpr u32 smu_cmd_reset_value = 0;    // TODO: change according manual
constexpr u32 smu_sts_reset_value = 0;    // TODO: change according manual
constexpr u32 smu_fsp_reset_value = 0;    // TODO: change according manual
constexpr u32 smu_agc_reset_value = 0;    // TODO: change according manual
constexpr u32 smu_rtc_reset_value = 0;    // TODO: change according manual
constexpr u32 smu_keys_reset_value = 0;   // TODO: change according manual
constexpr u32 smu_dbg_reset_value = 0;    // TODO: change according manual
constexpr u32 smu_pctl_reset_value = 0;   // TODO: change according manual
constexpr u32 smu_afcnt_reset_value = 0;  // TODO: change according manual
constexpr u32 smu_rtac00_reset_value = 0; // TODO: change according manual
constexpr u32 smu_rtac01_reset_value = 0; // TODO: change according manual
constexpr u32 smu_rtac10_reset_value = 0; // TODO: change according manual
constexpr u32 smu_rtac11_reset_value = 0; // TODO: change according manual
constexpr u32 smu_aex_reset_value = 0;    // TODO: change according manual
constexpr u32 smu_aexclr_reset_value = 0; // TODO: change according manual
constexpr u32 smu_rmctl_reset_value = 0;  // TODO: change according manual
constexpr u32 smu_rmef_reset_value = 0;   // TODO: change according manual
constexpr u32 smu_rmsts_reset_value = 0;  // TODO: change according manual
constexpr u32 smu_ocs_reset_value = 0;    // TODO: change according manual
constexpr u32 smu_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 smu_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 smu_memory_start_address = 0xf0036800U;
constexpr u32 smu_memory_size = 0; // TODO: update according manual;
constexpr u32 smu_memory_end_address =
    smu_memory_start_address + smu_memory_size;

constexpr u32 reg_smu_clc_address = 0xf0036800;
constexpr u32 reg_smu_clc_offset =
    reg_smu_clc_address - smu_memory_start_address;
constexpr u32 reg_smu_id_address = 0xf0036808;
constexpr u32 reg_smu_id_offset = reg_smu_id_address - smu_memory_start_address;
constexpr u32 reg_smu_cmd_address = 0xf0036820;
constexpr u32 reg_smu_cmd_offset =
    reg_smu_cmd_address - smu_memory_start_address;
constexpr u32 reg_smu_sts_address = 0xf0036824;
constexpr u32 reg_smu_sts_offset =
    reg_smu_sts_address - smu_memory_start_address;
constexpr u32 reg_smu_fsp_address = 0xf0036828;
constexpr u32 reg_smu_fsp_offset =
    reg_smu_fsp_address - smu_memory_start_address;
constexpr u32 reg_smu_agc_address = 0xf003682c;
constexpr u32 reg_smu_agc_offset =
    reg_smu_agc_address - smu_memory_start_address;
constexpr u32 reg_smu_rtc_address = 0xf0036830;
constexpr u32 reg_smu_rtc_offset =
    reg_smu_rtc_address - smu_memory_start_address;
constexpr u32 reg_smu_keys_address = 0xf0036834;
constexpr u32 reg_smu_keys_offset =
    reg_smu_keys_address - smu_memory_start_address;
constexpr u32 reg_smu_dbg_address = 0xf0036838;
constexpr u32 reg_smu_dbg_offset =
    reg_smu_dbg_address - smu_memory_start_address;
constexpr u32 reg_smu_pctl_address = 0xf003683c;
constexpr u32 reg_smu_pctl_offset =
    reg_smu_pctl_address - smu_memory_start_address;
constexpr u32 reg_smu_afcnt_address = 0xf0036840;
constexpr u32 reg_smu_afcnt_offset =
    reg_smu_afcnt_address - smu_memory_start_address;
constexpr u32 reg_smu_rtac00_address = 0xf0036860;
constexpr u32 reg_smu_rtac00_offset =
    reg_smu_rtac00_address - smu_memory_start_address;
constexpr u32 reg_smu_rtac01_address = 0xf0036864;
constexpr u32 reg_smu_rtac01_offset =
    reg_smu_rtac01_address - smu_memory_start_address;
constexpr u32 reg_smu_rtac10_address = 0xf0036868;
constexpr u32 reg_smu_rtac10_offset =
    reg_smu_rtac10_address - smu_memory_start_address;
constexpr u32 reg_smu_rtac11_address = 0xf003686c;
constexpr u32 reg_smu_rtac11_offset =
    reg_smu_rtac11_address - smu_memory_start_address;
constexpr u32 reg_smu_aex_address = 0xf0036870;
constexpr u32 reg_smu_aex_offset =
    reg_smu_aex_address - smu_memory_start_address;
constexpr u32 reg_smu_aexclr_address = 0xf0036874;
constexpr u32 reg_smu_aexclr_offset =
    reg_smu_aexclr_address - smu_memory_start_address;
constexpr u32 reg_smu_rmctl_address = 0xf0036b00;
constexpr u32 reg_smu_rmctl_offset =
    reg_smu_rmctl_address - smu_memory_start_address;
constexpr u32 reg_smu_rmef_address = 0xf0036b04;
constexpr u32 reg_smu_rmef_offset =
    reg_smu_rmef_address - smu_memory_start_address;
constexpr u32 reg_smu_rmsts_address = 0xf0036b08;
constexpr u32 reg_smu_rmsts_offset =
    reg_smu_rmsts_address - smu_memory_start_address;
constexpr u32 reg_smu_ocs_address = 0xf0036fe8;
constexpr u32 reg_smu_ocs_offset =
    reg_smu_ocs_address - smu_memory_start_address;
constexpr u32 reg_smu_accen1_address = 0xf0036ff8;
constexpr u32 reg_smu_accen1_offset =
    reg_smu_accen1_address - smu_memory_start_address;
constexpr u32 reg_smu_accen0_address = 0xf0036ffc;
constexpr u32 reg_smu_accen0_offset =
    reg_smu_accen0_address - smu_memory_start_address;

constexpr u32 reg_smu_agcf_start_address = 0xf0036900;
constexpr u32 reg_smu_agcf_end_address = 0xf0036990;

} // anonymous namespace

Tricore::Peripherals::Smu::Smu()
    : m_smu_clc(smu_clc_reset_value), m_smu_id(smu_id_reset_value),
      m_smu_cmd(smu_cmd_reset_value), m_smu_sts(smu_sts_reset_value),
      m_smu_fsp(smu_fsp_reset_value), m_smu_agc(smu_agc_reset_value),
      m_smu_rtc(smu_rtc_reset_value), m_smu_keys(smu_keys_reset_value),
      m_smu_dbg(smu_dbg_reset_value), m_smu_pctl(smu_pctl_reset_value),
      m_smu_afcnt(smu_afcnt_reset_value), m_smu_rtac00(smu_rtac00_reset_value),
      m_smu_rtac01(smu_rtac01_reset_value),
      m_smu_rtac10(smu_rtac10_reset_value),
      m_smu_rtac11(smu_rtac11_reset_value), m_smu_aex(smu_aex_reset_value),
      m_smu_aexclr(smu_aexclr_reset_value), m_smu_rmctl(smu_rmctl_reset_value),
      m_smu_rmef(smu_rmef_reset_value), m_smu_rmsts(smu_rmsts_reset_value),
      m_smu_ocs(smu_ocs_reset_value), m_smu_accen1(smu_accen1_reset_value),
      m_smu_accen0(smu_accen0_reset_value), m_smu_agcf{} {}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast,
// cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Peripherals::Smu::read(byte *buffer_out, u32 address,
                                     usize length) {
    const u32 offset = address - smu_memory_start_address;

    // special case for AGCF registers
    if (address >= reg_smu_agcf_start_address &&
        address < reg_smu_agcf_end_address) {
        const u32 alarm_offset = address - reg_smu_agcf_start_address;
        const u32 alarm_group_index = (alarm_offset / 4U) / 3U;
        const u32 alarm_reg_index = (alarm_offset / 4U) % 3U;

        Ensures(alarm_group_index < AlarmConfigRegisterNumber &&
                alarm_reg_index < 3);
        gsl::span agcf_view{m_smu_agcf};

        spdlog::debug("SMU: accessing SMU.AGCF[{}][{}] in read mode",
                      alarm_group_index, alarm_reg_index);
        const auto *range_start = reinterpret_cast<byte *>(
            &agcf_view[alarm_group_index][alarm_reg_index]);
        std::ranges::copy(range_start, range_start + length, buffer_out);

        return;
    }

    switch (offset) {
    case reg_smu_clc_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_CLC in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_clc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_id_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_ID in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_id);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_cmd_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_CMD in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_cmd);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_sts_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_STS in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_sts);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_fsp_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_FSP in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_fsp);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_agc_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_AGC in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_agc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_rtc_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RTC in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_rtc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_keys_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_KEYS in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_keys);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_dbg_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_DBG in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_dbg);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_pctl_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_PCTL in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_pctl);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_afcnt_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_AFCNT in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_afcnt);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_rtac00_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RTAC00 in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_rtac00);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_rtac01_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RTAC01 in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_rtac01);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_rtac10_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RTAC10 in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_rtac10);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_rtac11_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RTAC11 in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_rtac11);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_aex_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_AEX in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_aex);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_aexclr_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_AEXCLR in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_aexclr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_rmctl_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RMCTL in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_rmctl);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_rmef_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RMEF in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_rmef);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_rmsts_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RMSTS in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_rmsts);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_ocs_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_OCS in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_ocs);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_accen1_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_ACCEN1 in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_accen1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_smu_accen0_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_ACCEN0 in read mode");
        const auto *range_start = reinterpret_cast<byte *>(&m_smu_accen0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Smu peripheral", address)};
        break;
    }
}

void Tricore::Peripherals::Smu::write(const byte *buffer_in, u32 address,
                                      usize length) {
    const u32 offset = address - smu_memory_start_address;

    // special case for AGCF registers
    if (address >= reg_smu_agcf_start_address &&
        address < reg_smu_agcf_end_address) {
        const u32 alarm_offset = address - reg_smu_agcf_start_address;
        const u32 alarm_group_index = (alarm_offset / 4U) / 3U;
        const u32 alarm_reg_index = (alarm_offset / 4U) % 3U;

        Ensures(alarm_group_index < AlarmConfigRegisterNumber &&
                alarm_reg_index < 3);
        gsl::span agcf_view{m_smu_agcf};

        spdlog::debug("SMU: accessing SMU.AGCF[{}][{}] in write mode",
                      alarm_group_index, alarm_reg_index);
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(
                              &agcf_view[alarm_group_index][alarm_reg_index]));

        return;
    }

    switch (offset) {
    case reg_smu_clc_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_clc));
    } break;
    case reg_smu_id_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_id));
    } break;
    case reg_smu_cmd_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_CMD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_cmd));
    } break;
    case reg_smu_sts_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_STS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_sts));
    } break;
    case reg_smu_fsp_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_FSP in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_fsp));
    } break;
    case reg_smu_agc_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_AGC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_agc));
    } break;
    case reg_smu_rtc_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RTC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_rtc));
    } break;
    case reg_smu_keys_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_KEYS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_keys));
    } break;
    case reg_smu_dbg_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_DBG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_dbg));
    } break;
    case reg_smu_pctl_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_PCTL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_pctl));
    } break;
    case reg_smu_afcnt_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_AFCNT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_afcnt));
    } break;
    case reg_smu_rtac00_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RTAC00 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_rtac00));
    } break;
    case reg_smu_rtac01_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RTAC01 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_rtac01));
    } break;
    case reg_smu_rtac10_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RTAC10 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_rtac10));
    } break;
    case reg_smu_rtac11_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RTAC11 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_rtac11));
    } break;
    case reg_smu_aex_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_AEX in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_aex));
    } break;
    case reg_smu_aexclr_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_AEXCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_aexclr));
    } break;
    case reg_smu_rmctl_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RMCTL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_rmctl));
    } break;
    case reg_smu_rmef_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RMEF in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_rmef));
    } break;
    case reg_smu_rmsts_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_RMSTS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_rmsts));
    } break;
    case reg_smu_ocs_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_ocs));
    } break;
    case reg_smu_accen1_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_accen1));
    } break;
    case reg_smu_accen0_offset: {
        spdlog::debug("SMU: accessing SMU.SMU_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_smu_accen0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Smu peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast,
// cppcoreguidelines-pro-bounds-pointer-arithmetic)
