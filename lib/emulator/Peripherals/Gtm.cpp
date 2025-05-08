
/**
 * @brief Module source for Gtm peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Gtm.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 gtm_rev_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_rst_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_ctrl_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_irq_notify_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_irq_en_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_irq_forcint_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_irq_mode_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_eirq_en_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_hw_conf_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_cfg_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_bridge_mode_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_bridge_ptr1_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_bridge_ptr2_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_tbu_chen_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_mon_status_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_cmp_en_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_aru_access_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_aru_ctrl_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_aru_caddr_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_brc_rst_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_clc_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_reset_clr_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_reset1_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_reset2_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_ocds_otbu0t_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_ocds_otbu1t_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_ocds_otbu2t_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_ocds_otss_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_ocds_otsc0_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_ocds_oda_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_ocds_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_lcdcdcoutsel_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_dtmauxinsel_reset_value = 0; // TODO: change according manual
constexpr u32 gtm_canoutsel0_reset_value = 0; // TODO: change according manual

constexpr u32 gtm_memory_start_address = 0xf0100000U;
constexpr u32 gtm_memory_size = 0; // TODO: update according manual;
constexpr u32 gtm_memory_end_address = gtm_memory_start_address + gtm_memory_size;

constexpr u32 reg_gtm_rev_address = 0xf0100000;
constexpr u32 reg_gtm_rev_offset = reg_gtm_rev_address - gtm_memory_start_address;
constexpr u32 reg_gtm_rst_address = 0xf0100004;
constexpr u32 reg_gtm_rst_offset = reg_gtm_rst_address - gtm_memory_start_address;
constexpr u32 reg_gtm_ctrl_address = 0xf0100008;
constexpr u32 reg_gtm_ctrl_offset = reg_gtm_ctrl_address - gtm_memory_start_address;
constexpr u32 reg_gtm_irq_notify_address = 0xf0100010;
constexpr u32 reg_gtm_irq_notify_offset = reg_gtm_irq_notify_address - gtm_memory_start_address;
constexpr u32 reg_gtm_irq_en_address = 0xf0100014;
constexpr u32 reg_gtm_irq_en_offset = reg_gtm_irq_en_address - gtm_memory_start_address;
constexpr u32 reg_gtm_irq_forcint_address = 0xf0100018;
constexpr u32 reg_gtm_irq_forcint_offset = reg_gtm_irq_forcint_address - gtm_memory_start_address;
constexpr u32 reg_gtm_irq_mode_address = 0xf010001c;
constexpr u32 reg_gtm_irq_mode_offset = reg_gtm_irq_mode_address - gtm_memory_start_address;
constexpr u32 reg_gtm_eirq_en_address = 0xf0100020;
constexpr u32 reg_gtm_eirq_en_offset = reg_gtm_eirq_en_address - gtm_memory_start_address;
constexpr u32 reg_gtm_hw_conf_address = 0xf0100024;
constexpr u32 reg_gtm_hw_conf_offset = reg_gtm_hw_conf_address - gtm_memory_start_address;
constexpr u32 reg_gtm_cfg_address = 0xf0100028;
constexpr u32 reg_gtm_cfg_offset = reg_gtm_cfg_address - gtm_memory_start_address;
constexpr u32 reg_gtm_bridge_mode_address = 0xf0100030;
constexpr u32 reg_gtm_bridge_mode_offset = reg_gtm_bridge_mode_address - gtm_memory_start_address;
constexpr u32 reg_gtm_bridge_ptr1_address = 0xf0100034;
constexpr u32 reg_gtm_bridge_ptr1_offset = reg_gtm_bridge_ptr1_address - gtm_memory_start_address;
constexpr u32 reg_gtm_bridge_ptr2_address = 0xf0100038;
constexpr u32 reg_gtm_bridge_ptr2_offset = reg_gtm_bridge_ptr2_address - gtm_memory_start_address;
constexpr u32 reg_gtm_tbu_chen_address = 0xf0100100;
constexpr u32 reg_gtm_tbu_chen_offset = reg_gtm_tbu_chen_address - gtm_memory_start_address;
constexpr u32 reg_gtm_mon_status_address = 0xf0100180;
constexpr u32 reg_gtm_mon_status_offset = reg_gtm_mon_status_address - gtm_memory_start_address;
constexpr u32 reg_gtm_cmp_en_address = 0xf0100200;
constexpr u32 reg_gtm_cmp_en_offset = reg_gtm_cmp_en_address - gtm_memory_start_address;
constexpr u32 reg_gtm_aru_access_address = 0xf0100280;
constexpr u32 reg_gtm_aru_access_offset = reg_gtm_aru_access_address - gtm_memory_start_address;
constexpr u32 reg_gtm_aru_ctrl_address = 0xf01002bc;
constexpr u32 reg_gtm_aru_ctrl_offset = reg_gtm_aru_ctrl_address - gtm_memory_start_address;
constexpr u32 reg_gtm_aru_caddr_address = 0xf01002fc;
constexpr u32 reg_gtm_aru_caddr_offset = reg_gtm_aru_caddr_address - gtm_memory_start_address;
constexpr u32 reg_gtm_brc_rst_address = 0xf0100470;
constexpr u32 reg_gtm_brc_rst_offset = reg_gtm_brc_rst_address - gtm_memory_start_address;
constexpr u32 reg_gtm_clc_address = 0xf019fd00;
constexpr u32 reg_gtm_clc_offset = reg_gtm_clc_address - gtm_memory_start_address;
constexpr u32 reg_gtm_reset_clr_address = 0xf019fd04;
constexpr u32 reg_gtm_reset_clr_offset = reg_gtm_reset_clr_address - gtm_memory_start_address;
constexpr u32 reg_gtm_reset1_address = 0xf019fd08;
constexpr u32 reg_gtm_reset1_offset = reg_gtm_reset1_address - gtm_memory_start_address;
constexpr u32 reg_gtm_reset2_address = 0xf019fd0c;
constexpr u32 reg_gtm_reset2_offset = reg_gtm_reset2_address - gtm_memory_start_address;
constexpr u32 reg_gtm_accen0_address = 0xf019fd10;
constexpr u32 reg_gtm_accen0_offset = reg_gtm_accen0_address - gtm_memory_start_address;
constexpr u32 reg_gtm_accen1_address = 0xf019fd14;
constexpr u32 reg_gtm_accen1_offset = reg_gtm_accen1_address - gtm_memory_start_address;
constexpr u32 reg_gtm_ocds_otbu0t_address = 0xf019fd18;
constexpr u32 reg_gtm_ocds_otbu0t_offset = reg_gtm_ocds_otbu0t_address - gtm_memory_start_address;
constexpr u32 reg_gtm_ocds_otbu1t_address = 0xf019fd1c;
constexpr u32 reg_gtm_ocds_otbu1t_offset = reg_gtm_ocds_otbu1t_address - gtm_memory_start_address;
constexpr u32 reg_gtm_ocds_otbu2t_address = 0xf019fd20;
constexpr u32 reg_gtm_ocds_otbu2t_offset = reg_gtm_ocds_otbu2t_address - gtm_memory_start_address;
constexpr u32 reg_gtm_ocds_otss_address = 0xf019fd28;
constexpr u32 reg_gtm_ocds_otss_offset = reg_gtm_ocds_otss_address - gtm_memory_start_address;
constexpr u32 reg_gtm_ocds_otsc0_address = 0xf019fd2c;
constexpr u32 reg_gtm_ocds_otsc0_offset = reg_gtm_ocds_otsc0_address - gtm_memory_start_address;
constexpr u32 reg_gtm_ocds_oda_address = 0xf019fd34;
constexpr u32 reg_gtm_ocds_oda_offset = reg_gtm_ocds_oda_address - gtm_memory_start_address;
constexpr u32 reg_gtm_ocds_ocs_address = 0xf019fd38;
constexpr u32 reg_gtm_ocds_ocs_offset = reg_gtm_ocds_ocs_address - gtm_memory_start_address;
constexpr u32 reg_gtm_lcdcdcoutsel_address = 0xf019ffd4;
constexpr u32 reg_gtm_lcdcdcoutsel_offset = reg_gtm_lcdcdcoutsel_address - gtm_memory_start_address;
constexpr u32 reg_gtm_dtmauxinsel_address = 0xf019ffd8;
constexpr u32 reg_gtm_dtmauxinsel_offset = reg_gtm_dtmauxinsel_address - gtm_memory_start_address;
constexpr u32 reg_gtm_canoutsel0_address = 0xf019ffdc;
constexpr u32 reg_gtm_canoutsel0_offset = reg_gtm_canoutsel0_address - gtm_memory_start_address;

} // anonymous namespace


Tricore::Gtm::Gtm()
    : m_gtm_rev(gtm_rev_reset_value)
    , m_gtm_rst(gtm_rst_reset_value)
    , m_gtm_ctrl(gtm_ctrl_reset_value)
    , m_gtm_irq_notify(gtm_irq_notify_reset_value)
    , m_gtm_irq_en(gtm_irq_en_reset_value)
    , m_gtm_irq_forcint(gtm_irq_forcint_reset_value)
    , m_gtm_irq_mode(gtm_irq_mode_reset_value)
    , m_gtm_eirq_en(gtm_eirq_en_reset_value)
    , m_gtm_hw_conf(gtm_hw_conf_reset_value)
    , m_gtm_cfg(gtm_cfg_reset_value)
    , m_gtm_bridge_mode(gtm_bridge_mode_reset_value)
    , m_gtm_bridge_ptr1(gtm_bridge_ptr1_reset_value)
    , m_gtm_bridge_ptr2(gtm_bridge_ptr2_reset_value)
    , m_gtm_tbu_chen(gtm_tbu_chen_reset_value)
    , m_gtm_mon_status(gtm_mon_status_reset_value)
    , m_gtm_cmp_en(gtm_cmp_en_reset_value)
    , m_gtm_aru_access(gtm_aru_access_reset_value)
    , m_gtm_aru_ctrl(gtm_aru_ctrl_reset_value)
    , m_gtm_aru_caddr(gtm_aru_caddr_reset_value)
    , m_gtm_brc_rst(gtm_brc_rst_reset_value)
    , m_gtm_clc(gtm_clc_reset_value)
    , m_gtm_reset_clr(gtm_reset_clr_reset_value)
    , m_gtm_reset1(gtm_reset1_reset_value)
    , m_gtm_reset2(gtm_reset2_reset_value)
    , m_gtm_accen0(gtm_accen0_reset_value)
    , m_gtm_accen1(gtm_accen1_reset_value)
    , m_gtm_ocds_otbu0t(gtm_ocds_otbu0t_reset_value)
    , m_gtm_ocds_otbu1t(gtm_ocds_otbu1t_reset_value)
    , m_gtm_ocds_otbu2t(gtm_ocds_otbu2t_reset_value)
    , m_gtm_ocds_otss(gtm_ocds_otss_reset_value)
    , m_gtm_ocds_otsc0(gtm_ocds_otsc0_reset_value)
    , m_gtm_ocds_oda(gtm_ocds_oda_reset_value)
    , m_gtm_ocds_ocs(gtm_ocds_ocs_reset_value)
    , m_gtm_lcdcdcoutsel(gtm_lcdcdcoutsel_reset_value)
    , m_gtm_dtmauxinsel(gtm_dtmauxinsel_reset_value)
    , m_gtm_canoutsel0(gtm_canoutsel0_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Gtm::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - gtm_memory_start_address;
    switch (offset) {
    case reg_gtm_rev_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_REV in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_rev);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_rst_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_RST in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_rst);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_ctrl_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_CTRL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_ctrl);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_irq_notify_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_IRQ_NOTIFY in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_irq_notify);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_irq_en_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_IRQ_EN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_irq_en);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_irq_forcint_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_IRQ_FORCINT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_irq_forcint);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_irq_mode_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_IRQ_MODE in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_irq_mode);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_eirq_en_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_EIRQ_EN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_eirq_en);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_hw_conf_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_HW_CONF in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_hw_conf);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_cfg_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_CFG in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_cfg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_bridge_mode_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_BRIDGE_MODE in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_bridge_mode);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_bridge_ptr1_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_BRIDGE_PTR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_bridge_ptr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_bridge_ptr2_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_BRIDGE_PTR2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_bridge_ptr2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_tbu_chen_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_TBU_CHEN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_tbu_chen);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_mon_status_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_MON_STATUS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_mon_status);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_cmp_en_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_CMP_EN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_cmp_en);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_aru_access_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_ARU_ACCESS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_aru_access);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_aru_ctrl_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_ARU_CTRL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_aru_ctrl);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_aru_caddr_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_ARU_CADDR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_aru_caddr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_brc_rst_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_BRC_RST in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_brc_rst);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_clc_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_CLC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_reset_clr_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_RESET_CLR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_reset_clr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_reset1_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_RESET1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_reset1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_reset2_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_RESET2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_reset2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_accen0_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_accen1_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_ocds_otbu0t_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_OCDS_OTBU0T in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_ocds_otbu0t);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_ocds_otbu1t_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_OCDS_OTBU1T in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_ocds_otbu1t);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_ocds_otbu2t_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_OCDS_OTBU2T in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_ocds_otbu2t);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_ocds_otss_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_OCDS_OTSS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_ocds_otss);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_ocds_otsc0_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_OCDS_OTSC0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_ocds_otsc0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_ocds_oda_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_OCDS_ODA in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_ocds_oda);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_ocds_ocs_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_OCDS_OCS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_ocds_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_lcdcdcoutsel_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_LCDCDCOUTSEL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_lcdcdcoutsel);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_dtmauxinsel_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_DTMAUXINSEL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_dtmauxinsel);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_gtm_canoutsel0_offset: {
            spdlog::debug("GTM: accessing GTM.GTM_CANOUTSEL0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_gtm_canoutsel0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Gtm peripheral", address)};
        break;
    }
}

void Tricore::Gtm::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - gtm_memory_start_address;
    switch (offset) {
    case reg_gtm_rev_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_REV in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_rev));
    } break;
    case reg_gtm_rst_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_RST in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_rst));
    } break;
    case reg_gtm_ctrl_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_CTRL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_ctrl));
    } break;
    case reg_gtm_irq_notify_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_IRQ_NOTIFY in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_irq_notify));
    } break;
    case reg_gtm_irq_en_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_IRQ_EN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_irq_en));
    } break;
    case reg_gtm_irq_forcint_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_IRQ_FORCINT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_irq_forcint));
    } break;
    case reg_gtm_irq_mode_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_IRQ_MODE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_irq_mode));
    } break;
    case reg_gtm_eirq_en_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_EIRQ_EN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_eirq_en));
    } break;
    case reg_gtm_hw_conf_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_HW_CONF in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_hw_conf));
    } break;
    case reg_gtm_cfg_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_CFG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_cfg));
    } break;
    case reg_gtm_bridge_mode_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_BRIDGE_MODE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_bridge_mode));
    } break;
    case reg_gtm_bridge_ptr1_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_BRIDGE_PTR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_bridge_ptr1));
    } break;
    case reg_gtm_bridge_ptr2_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_BRIDGE_PTR2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_bridge_ptr2));
    } break;
    case reg_gtm_tbu_chen_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_TBU_CHEN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_tbu_chen));
    } break;
    case reg_gtm_mon_status_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_MON_STATUS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_mon_status));
    } break;
    case reg_gtm_cmp_en_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_CMP_EN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_cmp_en));
    } break;
    case reg_gtm_aru_access_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_ARU_ACCESS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_aru_access));
    } break;
    case reg_gtm_aru_ctrl_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_ARU_CTRL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_aru_ctrl));
    } break;
    case reg_gtm_aru_caddr_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_ARU_CADDR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_aru_caddr));
    } break;
    case reg_gtm_brc_rst_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_BRC_RST in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_brc_rst));
    } break;
    case reg_gtm_clc_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_clc));
    } break;
    case reg_gtm_reset_clr_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_RESET_CLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_reset_clr));
    } break;
    case reg_gtm_reset1_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_RESET1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_reset1));
    } break;
    case reg_gtm_reset2_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_RESET2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_reset2));
    } break;
    case reg_gtm_accen0_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_accen0));
    } break;
    case reg_gtm_accen1_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_accen1));
    } break;
    case reg_gtm_ocds_otbu0t_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_OCDS_OTBU0T in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_ocds_otbu0t));
    } break;
    case reg_gtm_ocds_otbu1t_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_OCDS_OTBU1T in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_ocds_otbu1t));
    } break;
    case reg_gtm_ocds_otbu2t_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_OCDS_OTBU2T in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_ocds_otbu2t));
    } break;
    case reg_gtm_ocds_otss_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_OCDS_OTSS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_ocds_otss));
    } break;
    case reg_gtm_ocds_otsc0_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_OCDS_OTSC0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_ocds_otsc0));
    } break;
    case reg_gtm_ocds_oda_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_OCDS_ODA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_ocds_oda));
    } break;
    case reg_gtm_ocds_ocs_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_OCDS_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_ocds_ocs));
    } break;
    case reg_gtm_lcdcdcoutsel_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_LCDCDCOUTSEL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_lcdcdcoutsel));
    } break;
    case reg_gtm_dtmauxinsel_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_DTMAUXINSEL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_dtmauxinsel));
    } break;
    case reg_gtm_canoutsel0_offset: {
        spdlog::debug("GTM: accessing GTM.GTM_CANOUTSEL0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_gtm_canoutsel0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Gtm peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
