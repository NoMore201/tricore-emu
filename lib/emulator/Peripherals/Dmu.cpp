
/**
 * @brief Module source for Dmu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Dmu.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 dmu_hf_id_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_status_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_control_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_operation_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_protect_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_confirm0_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_confirm1_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_confirm2_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_eer_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_errsr_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_clre_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_eccr_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_eccs_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_eccc_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_eccw_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_ccontrol_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_pstatus_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_pcontrol_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_pwait_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_dwait_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_proconusr_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_proconpf_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_procontp_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_procondf_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_proconram_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_procondbg_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_suspend_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_margin_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_hf_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_status_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_control_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_operation_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_eer_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_errsr_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_clre_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_eccr_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_eccs_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_eccc_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_eccw_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_proconusr_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_suspend_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sf_margin_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sp_proconhsmcfg_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sp_proconhsmcbs_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sp_proconhsmcx0_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sp_proconhsmcx1_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sp_proconhsmcotp0_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sp_proconhsmcotp1_reset_value = 0; // TODO: change according manual
constexpr u32 dmu_sp_proconhsm_reset_value = 0; // TODO: change according manual

constexpr u32 dmu_memory_start_address = 0xf8040000U;
constexpr u32 dmu_memory_size = 0; // TODO: update according manual;
constexpr u32 dmu_memory_end_address = dmu_memory_start_address + dmu_memory_size;

constexpr u32 reg_dmu_hf_id_address = 0xf8040008;
constexpr u32 reg_dmu_hf_id_offset = reg_dmu_hf_id_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_status_address = 0xf8040010;
constexpr u32 reg_dmu_hf_status_offset = reg_dmu_hf_status_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_control_address = 0xf8040014;
constexpr u32 reg_dmu_hf_control_offset = reg_dmu_hf_control_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_operation_address = 0xf8040018;
constexpr u32 reg_dmu_hf_operation_offset = reg_dmu_hf_operation_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_protect_address = 0xf804001c;
constexpr u32 reg_dmu_hf_protect_offset = reg_dmu_hf_protect_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_confirm0_address = 0xf8040020;
constexpr u32 reg_dmu_hf_confirm0_offset = reg_dmu_hf_confirm0_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_confirm1_address = 0xf8040024;
constexpr u32 reg_dmu_hf_confirm1_offset = reg_dmu_hf_confirm1_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_confirm2_address = 0xf8040028;
constexpr u32 reg_dmu_hf_confirm2_offset = reg_dmu_hf_confirm2_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_eer_address = 0xf8040030;
constexpr u32 reg_dmu_hf_eer_offset = reg_dmu_hf_eer_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_errsr_address = 0xf8040034;
constexpr u32 reg_dmu_hf_errsr_offset = reg_dmu_hf_errsr_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_clre_address = 0xf8040038;
constexpr u32 reg_dmu_hf_clre_offset = reg_dmu_hf_clre_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_eccr_address = 0xf8040040;
constexpr u32 reg_dmu_hf_eccr_offset = reg_dmu_hf_eccr_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_eccs_address = 0xf8040044;
constexpr u32 reg_dmu_hf_eccs_offset = reg_dmu_hf_eccs_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_eccc_address = 0xf8040048;
constexpr u32 reg_dmu_hf_eccc_offset = reg_dmu_hf_eccc_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_eccw_address = 0xf804004c;
constexpr u32 reg_dmu_hf_eccw_offset = reg_dmu_hf_eccw_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_ccontrol_address = 0xf8040050;
constexpr u32 reg_dmu_hf_ccontrol_offset = reg_dmu_hf_ccontrol_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_pstatus_address = 0xf8040060;
constexpr u32 reg_dmu_hf_pstatus_offset = reg_dmu_hf_pstatus_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_pcontrol_address = 0xf8040064;
constexpr u32 reg_dmu_hf_pcontrol_offset = reg_dmu_hf_pcontrol_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_pwait_address = 0xf8040068;
constexpr u32 reg_dmu_hf_pwait_offset = reg_dmu_hf_pwait_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_dwait_address = 0xf804006c;
constexpr u32 reg_dmu_hf_dwait_offset = reg_dmu_hf_dwait_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_proconusr_address = 0xf8040074;
constexpr u32 reg_dmu_hf_proconusr_offset = reg_dmu_hf_proconusr_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_proconpf_address = 0xf8040080;
constexpr u32 reg_dmu_hf_proconpf_offset = reg_dmu_hf_proconpf_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_procontp_address = 0xf8040084;
constexpr u32 reg_dmu_hf_procontp_offset = reg_dmu_hf_procontp_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_procondf_address = 0xf8040088;
constexpr u32 reg_dmu_hf_procondf_offset = reg_dmu_hf_procondf_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_proconram_address = 0xf804008c;
constexpr u32 reg_dmu_hf_proconram_offset = reg_dmu_hf_proconram_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_procondbg_address = 0xf8040090;
constexpr u32 reg_dmu_hf_procondbg_offset = reg_dmu_hf_procondbg_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_suspend_address = 0xf80400f0;
constexpr u32 reg_dmu_hf_suspend_offset = reg_dmu_hf_suspend_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_margin_address = 0xf80400f4;
constexpr u32 reg_dmu_hf_margin_offset = reg_dmu_hf_margin_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_accen1_address = 0xf80400f8;
constexpr u32 reg_dmu_hf_accen1_offset = reg_dmu_hf_accen1_address - dmu_memory_start_address;
constexpr u32 reg_dmu_hf_accen0_address = 0xf80400fc;
constexpr u32 reg_dmu_hf_accen0_offset = reg_dmu_hf_accen0_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_status_address = 0xf8060010;
constexpr u32 reg_dmu_sf_status_offset = reg_dmu_sf_status_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_control_address = 0xf8060014;
constexpr u32 reg_dmu_sf_control_offset = reg_dmu_sf_control_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_operation_address = 0xf8060018;
constexpr u32 reg_dmu_sf_operation_offset = reg_dmu_sf_operation_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_eer_address = 0xf8060030;
constexpr u32 reg_dmu_sf_eer_offset = reg_dmu_sf_eer_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_errsr_address = 0xf8060034;
constexpr u32 reg_dmu_sf_errsr_offset = reg_dmu_sf_errsr_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_clre_address = 0xf8060038;
constexpr u32 reg_dmu_sf_clre_offset = reg_dmu_sf_clre_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_eccr_address = 0xf8060040;
constexpr u32 reg_dmu_sf_eccr_offset = reg_dmu_sf_eccr_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_eccs_address = 0xf8060044;
constexpr u32 reg_dmu_sf_eccs_offset = reg_dmu_sf_eccs_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_eccc_address = 0xf8060048;
constexpr u32 reg_dmu_sf_eccc_offset = reg_dmu_sf_eccc_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_eccw_address = 0xf806004c;
constexpr u32 reg_dmu_sf_eccw_offset = reg_dmu_sf_eccw_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_proconusr_address = 0xf8060074;
constexpr u32 reg_dmu_sf_proconusr_offset = reg_dmu_sf_proconusr_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_suspend_address = 0xf80600e8;
constexpr u32 reg_dmu_sf_suspend_offset = reg_dmu_sf_suspend_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sf_margin_address = 0xf80600ec;
constexpr u32 reg_dmu_sf_margin_offset = reg_dmu_sf_margin_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sp_proconhsmcfg_address = 0xf8070000;
constexpr u32 reg_dmu_sp_proconhsmcfg_offset = reg_dmu_sp_proconhsmcfg_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sp_proconhsmcbs_address = 0xf8070004;
constexpr u32 reg_dmu_sp_proconhsmcbs_offset = reg_dmu_sp_proconhsmcbs_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sp_proconhsmcx0_address = 0xf8070008;
constexpr u32 reg_dmu_sp_proconhsmcx0_offset = reg_dmu_sp_proconhsmcx0_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sp_proconhsmcx1_address = 0xf807000c;
constexpr u32 reg_dmu_sp_proconhsmcx1_offset = reg_dmu_sp_proconhsmcx1_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sp_proconhsmcotp0_address = 0xf8070010;
constexpr u32 reg_dmu_sp_proconhsmcotp0_offset = reg_dmu_sp_proconhsmcotp0_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sp_proconhsmcotp1_address = 0xf8070014;
constexpr u32 reg_dmu_sp_proconhsmcotp1_offset = reg_dmu_sp_proconhsmcotp1_address - dmu_memory_start_address;
constexpr u32 reg_dmu_sp_proconhsm_address = 0xf8070040;
constexpr u32 reg_dmu_sp_proconhsm_offset = reg_dmu_sp_proconhsm_address - dmu_memory_start_address;

} // anonymous namespace


Tricore::Dmu::Dmu()
    : m_dmu_hf_id(dmu_hf_id_reset_value)
    , m_dmu_hf_status(dmu_hf_status_reset_value)
    , m_dmu_hf_control(dmu_hf_control_reset_value)
    , m_dmu_hf_operation(dmu_hf_operation_reset_value)
    , m_dmu_hf_protect(dmu_hf_protect_reset_value)
    , m_dmu_hf_confirm0(dmu_hf_confirm0_reset_value)
    , m_dmu_hf_confirm1(dmu_hf_confirm1_reset_value)
    , m_dmu_hf_confirm2(dmu_hf_confirm2_reset_value)
    , m_dmu_hf_eer(dmu_hf_eer_reset_value)
    , m_dmu_hf_errsr(dmu_hf_errsr_reset_value)
    , m_dmu_hf_clre(dmu_hf_clre_reset_value)
    , m_dmu_hf_eccr(dmu_hf_eccr_reset_value)
    , m_dmu_hf_eccs(dmu_hf_eccs_reset_value)
    , m_dmu_hf_eccc(dmu_hf_eccc_reset_value)
    , m_dmu_hf_eccw(dmu_hf_eccw_reset_value)
    , m_dmu_hf_ccontrol(dmu_hf_ccontrol_reset_value)
    , m_dmu_hf_pstatus(dmu_hf_pstatus_reset_value)
    , m_dmu_hf_pcontrol(dmu_hf_pcontrol_reset_value)
    , m_dmu_hf_pwait(dmu_hf_pwait_reset_value)
    , m_dmu_hf_dwait(dmu_hf_dwait_reset_value)
    , m_dmu_hf_proconusr(dmu_hf_proconusr_reset_value)
    , m_dmu_hf_proconpf(dmu_hf_proconpf_reset_value)
    , m_dmu_hf_procontp(dmu_hf_procontp_reset_value)
    , m_dmu_hf_procondf(dmu_hf_procondf_reset_value)
    , m_dmu_hf_proconram(dmu_hf_proconram_reset_value)
    , m_dmu_hf_procondbg(dmu_hf_procondbg_reset_value)
    , m_dmu_hf_suspend(dmu_hf_suspend_reset_value)
    , m_dmu_hf_margin(dmu_hf_margin_reset_value)
    , m_dmu_hf_accen1(dmu_hf_accen1_reset_value)
    , m_dmu_hf_accen0(dmu_hf_accen0_reset_value)
    , m_dmu_sf_status(dmu_sf_status_reset_value)
    , m_dmu_sf_control(dmu_sf_control_reset_value)
    , m_dmu_sf_operation(dmu_sf_operation_reset_value)
    , m_dmu_sf_eer(dmu_sf_eer_reset_value)
    , m_dmu_sf_errsr(dmu_sf_errsr_reset_value)
    , m_dmu_sf_clre(dmu_sf_clre_reset_value)
    , m_dmu_sf_eccr(dmu_sf_eccr_reset_value)
    , m_dmu_sf_eccs(dmu_sf_eccs_reset_value)
    , m_dmu_sf_eccc(dmu_sf_eccc_reset_value)
    , m_dmu_sf_eccw(dmu_sf_eccw_reset_value)
    , m_dmu_sf_proconusr(dmu_sf_proconusr_reset_value)
    , m_dmu_sf_suspend(dmu_sf_suspend_reset_value)
    , m_dmu_sf_margin(dmu_sf_margin_reset_value)
    , m_dmu_sp_proconhsmcfg(dmu_sp_proconhsmcfg_reset_value)
    , m_dmu_sp_proconhsmcbs(dmu_sp_proconhsmcbs_reset_value)
    , m_dmu_sp_proconhsmcx0(dmu_sp_proconhsmcx0_reset_value)
    , m_dmu_sp_proconhsmcx1(dmu_sp_proconhsmcx1_reset_value)
    , m_dmu_sp_proconhsmcotp0(dmu_sp_proconhsmcotp0_reset_value)
    , m_dmu_sp_proconhsmcotp1(dmu_sp_proconhsmcotp1_reset_value)
    , m_dmu_sp_proconhsm(dmu_sp_proconhsm_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Dmu::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - dmu_memory_start_address;
    switch (offset) {
    case reg_dmu_hf_id_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_status_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_STATUS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_status);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_control_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_CONTROL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_control);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_operation_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_OPERATION in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_operation);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_protect_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_PROTECT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_protect);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_confirm0_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_CONFIRM0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_confirm0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_confirm1_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_CONFIRM1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_confirm1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_confirm2_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_CONFIRM2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_confirm2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_eer_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_EER in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_eer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_errsr_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_ERRSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_errsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_clre_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_CLRE in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_clre);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_eccr_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_ECCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_eccr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_eccs_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_ECCS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_eccs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_eccc_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_ECCC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_eccc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_eccw_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_ECCW in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_eccw);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_ccontrol_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_CCONTROL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_ccontrol);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_pstatus_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_PSTATUS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_pstatus);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_pcontrol_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_PCONTROL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_pcontrol);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_pwait_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_PWAIT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_pwait);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_dwait_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_DWAIT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_dwait);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_proconusr_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_PROCONUSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_proconusr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_proconpf_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_PROCONPF in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_proconpf);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_procontp_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_PROCONTP in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_procontp);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_procondf_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_PROCONDF in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_procondf);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_proconram_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_PROCONRAM in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_proconram);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_procondbg_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_PROCONDBG in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_procondbg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_suspend_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_SUSPEND in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_suspend);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_margin_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_MARGIN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_margin);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_accen1_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_hf_accen0_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_HF_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_hf_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_status_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_STATUS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_status);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_control_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_CONTROL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_control);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_operation_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_OPERATION in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_operation);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_eer_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_EER in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_eer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_errsr_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_ERRSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_errsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_clre_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_CLRE in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_clre);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_eccr_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_ECCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_eccr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_eccs_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_ECCS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_eccs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_eccc_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_ECCC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_eccc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_eccw_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_ECCW in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_eccw);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_proconusr_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_PROCONUSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_proconusr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_suspend_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_SUSPEND in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_suspend);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sf_margin_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SF_MARGIN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sf_margin);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sp_proconhsmcfg_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSMCFG in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sp_proconhsmcfg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sp_proconhsmcbs_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSMCBS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sp_proconhsmcbs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sp_proconhsmcx0_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSMCX0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sp_proconhsmcx0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sp_proconhsmcx1_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSMCX1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sp_proconhsmcx1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sp_proconhsmcotp0_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSMCOTP0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sp_proconhsmcotp0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sp_proconhsmcotp1_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSMCOTP1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sp_proconhsmcotp1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_dmu_sp_proconhsm_offset: {
            spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSM in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_dmu_sp_proconhsm);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Dmu peripheral", address)};
        break;
    }
}

void Tricore::Dmu::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - dmu_memory_start_address;
    switch (offset) {
    case reg_dmu_hf_id_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_id));
    } break;
    case reg_dmu_hf_status_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_STATUS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_status));
    } break;
    case reg_dmu_hf_control_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_CONTROL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_control));
    } break;
    case reg_dmu_hf_operation_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_OPERATION in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_operation));
    } break;
    case reg_dmu_hf_protect_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_PROTECT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_protect));
    } break;
    case reg_dmu_hf_confirm0_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_CONFIRM0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_confirm0));
    } break;
    case reg_dmu_hf_confirm1_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_CONFIRM1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_confirm1));
    } break;
    case reg_dmu_hf_confirm2_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_CONFIRM2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_confirm2));
    } break;
    case reg_dmu_hf_eer_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_EER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_eer));
    } break;
    case reg_dmu_hf_errsr_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_ERRSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_errsr));
    } break;
    case reg_dmu_hf_clre_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_CLRE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_clre));
    } break;
    case reg_dmu_hf_eccr_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_ECCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_eccr));
    } break;
    case reg_dmu_hf_eccs_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_ECCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_eccs));
    } break;
    case reg_dmu_hf_eccc_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_ECCC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_eccc));
    } break;
    case reg_dmu_hf_eccw_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_ECCW in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_eccw));
    } break;
    case reg_dmu_hf_ccontrol_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_CCONTROL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_ccontrol));
    } break;
    case reg_dmu_hf_pstatus_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_PSTATUS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_pstatus));
    } break;
    case reg_dmu_hf_pcontrol_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_PCONTROL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_pcontrol));
    } break;
    case reg_dmu_hf_pwait_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_PWAIT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_pwait));
    } break;
    case reg_dmu_hf_dwait_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_DWAIT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_dwait));
    } break;
    case reg_dmu_hf_proconusr_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_PROCONUSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_proconusr));
    } break;
    case reg_dmu_hf_proconpf_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_PROCONPF in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_proconpf));
    } break;
    case reg_dmu_hf_procontp_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_PROCONTP in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_procontp));
    } break;
    case reg_dmu_hf_procondf_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_PROCONDF in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_procondf));
    } break;
    case reg_dmu_hf_proconram_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_PROCONRAM in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_proconram));
    } break;
    case reg_dmu_hf_procondbg_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_PROCONDBG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_procondbg));
    } break;
    case reg_dmu_hf_suspend_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_SUSPEND in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_suspend));
    } break;
    case reg_dmu_hf_margin_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_MARGIN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_margin));
    } break;
    case reg_dmu_hf_accen1_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_accen1));
    } break;
    case reg_dmu_hf_accen0_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_HF_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_hf_accen0));
    } break;
    case reg_dmu_sf_status_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_STATUS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_status));
    } break;
    case reg_dmu_sf_control_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_CONTROL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_control));
    } break;
    case reg_dmu_sf_operation_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_OPERATION in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_operation));
    } break;
    case reg_dmu_sf_eer_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_EER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_eer));
    } break;
    case reg_dmu_sf_errsr_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_ERRSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_errsr));
    } break;
    case reg_dmu_sf_clre_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_CLRE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_clre));
    } break;
    case reg_dmu_sf_eccr_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_ECCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_eccr));
    } break;
    case reg_dmu_sf_eccs_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_ECCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_eccs));
    } break;
    case reg_dmu_sf_eccc_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_ECCC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_eccc));
    } break;
    case reg_dmu_sf_eccw_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_ECCW in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_eccw));
    } break;
    case reg_dmu_sf_proconusr_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_PROCONUSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_proconusr));
    } break;
    case reg_dmu_sf_suspend_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_SUSPEND in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_suspend));
    } break;
    case reg_dmu_sf_margin_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SF_MARGIN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sf_margin));
    } break;
    case reg_dmu_sp_proconhsmcfg_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSMCFG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sp_proconhsmcfg));
    } break;
    case reg_dmu_sp_proconhsmcbs_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSMCBS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sp_proconhsmcbs));
    } break;
    case reg_dmu_sp_proconhsmcx0_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSMCX0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sp_proconhsmcx0));
    } break;
    case reg_dmu_sp_proconhsmcx1_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSMCX1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sp_proconhsmcx1));
    } break;
    case reg_dmu_sp_proconhsmcotp0_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSMCOTP0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sp_proconhsmcotp0));
    } break;
    case reg_dmu_sp_proconhsmcotp1_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSMCOTP1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sp_proconhsmcotp1));
    } break;
    case reg_dmu_sp_proconhsm_offset: {
        spdlog::debug("DMU: accessing DMU.DMU_SP_PROCONHSM in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_dmu_sp_proconhsm));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Dmu peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
