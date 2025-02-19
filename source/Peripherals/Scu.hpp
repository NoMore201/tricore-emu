
/**
 * @brief Module header for Scu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore::Peripherals {

class Scu : public BusClient {

public:

    Scu();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_scu_id;
    u32 m_scu_osccon;
    u32 m_scu_syspllstat;
    u32 m_scu_syspllcon0;
    u32 m_scu_syspllcon1;
    u32 m_scu_syspllcon2;
    u32 m_scu_perpllstat;
    u32 m_scu_perpllcon0;
    u32 m_scu_perpllcon1;
    u32 m_scu_ccucon0;
    u32 m_scu_ccucon1;
    u32 m_scu_fdr;
    u32 m_scu_extcon;
    u32 m_scu_ccucon2;
    u32 m_scu_ccucon3;
    u32 m_scu_ccucon4;
    u32 m_scu_ccucon5;
    u32 m_scu_rststat;
    u32 m_scu_rstcon;
    u32 m_scu_arstdis;
    u32 m_scu_swrstcon;
    u32 m_scu_rstcon2;
    u32 m_scu_rstcon3;
    u32 m_scu_esrocfg;
    u32 m_scu_syscon;
    u32 m_scu_ccucon6;
    u32 m_scu_ccucon7;
    u32 m_scu_pdr;
    u32 m_scu_iocr;
    u32 m_scu_out;
    u32 m_scu_omr;
    u32 m_scu_in;
    u32 m_scu_ststat;
    u32 m_scu_stcon;
    u32 m_scu_pmcsr0;
    u32 m_scu_pmcsr1;
    u32 m_scu_pmcsr2;
    u32 m_scu_pmcsr3;
    u32 m_scu_pmcsr4;
    u32 m_scu_pmcsr5;
    u32 m_scu_pmstat0;
    u32 m_scu_pmswcr1;
    u32 m_scu_emsr;
    u32 m_scu_emssw;
    u32 m_scu_dtscstat;
    u32 m_scu_dtsclim;
    u32 m_scu_trapdis1;
    u32 m_scu_trapstat;
    u32 m_scu_trapset;
    u32 m_scu_trapclr;
    u32 m_scu_trapdis0;
    u32 m_scu_lclcon0;
    u32 m_scu_lclcon1;
    u32 m_scu_lcltest;
    u32 m_scu_chipid;
    u32 m_scu_manid;
    u32 m_scu_swapctrl;
    u32 m_scu_lbistctrl0;
    u32 m_scu_lbistctrl1;
    u32 m_scu_lbistctrl2;
    u32 m_scu_lbistctrl3;
    u32 m_scu_stmem1;
    u32 m_scu_stmem2;
    u32 m_scu_pdisc;
    u32 m_scu_pmtrcsr0;
    u32 m_scu_pmtrcsr1;
    u32 m_scu_pmtrcsr2;
    u32 m_scu_pmtrcsr3;
    u32 m_scu_stmem3;
    u32 m_scu_stmem4;
    u32 m_scu_stmem5;
    u32 m_scu_stmem6;
    u32 m_scu_ovcenable;
    u32 m_scu_ovccon;
    u32 m_scu_eifilt;
    u32 m_scu_eifr;
    u32 m_scu_fmr;
    u32 m_scu_pdrr;
    u32 m_scu_eicon0;
    u32 m_scu_eicon1;
    u32 m_scu_eisr;
    u32 m_scu_wdts_con0;
    u32 m_scu_wdts_con1;
    u32 m_scu_wdts_sr;
    u32 m_scu_seicon0;
    u32 m_scu_seicon1;
    u32 m_scu_seisr;
    u32 m_scu_accen11;
    u32 m_scu_accen10;
    u32 m_scu_accen01;
    u32 m_scu_accen00;

};

} // namespace Tricore
