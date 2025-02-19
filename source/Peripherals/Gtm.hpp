
/**
 * @brief Module header for Gtm peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Gtm : public BusClient {

public:

    Gtm();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_gtm_rev;
    u32 m_gtm_rst;
    u32 m_gtm_ctrl;
    u32 m_gtm_irq_notify;
    u32 m_gtm_irq_en;
    u32 m_gtm_irq_forcint;
    u32 m_gtm_irq_mode;
    u32 m_gtm_eirq_en;
    u32 m_gtm_hw_conf;
    u32 m_gtm_cfg;
    u32 m_gtm_bridge_mode;
    u32 m_gtm_bridge_ptr1;
    u32 m_gtm_bridge_ptr2;
    u32 m_gtm_tbu_chen;
    u32 m_gtm_mon_status;
    u32 m_gtm_cmp_en;
    u32 m_gtm_aru_access;
    u32 m_gtm_aru_ctrl;
    u32 m_gtm_aru_caddr;
    u32 m_gtm_brc_rst;
    u32 m_gtm_clc;
    u32 m_gtm_reset_clr;
    u32 m_gtm_reset1;
    u32 m_gtm_reset2;
    u32 m_gtm_accen0;
    u32 m_gtm_accen1;
    u32 m_gtm_ocds_otbu0t;
    u32 m_gtm_ocds_otbu1t;
    u32 m_gtm_ocds_otbu2t;
    u32 m_gtm_ocds_otss;
    u32 m_gtm_ocds_otsc0;
    u32 m_gtm_ocds_oda;
    u32 m_gtm_ocds_ocs;
    u32 m_gtm_lcdcdcoutsel;
    u32 m_gtm_dtmauxinsel;
    u32 m_gtm_canoutsel0;

};

} // namespace Tricore
