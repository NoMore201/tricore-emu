
/**
 * @brief Module header for Cpu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore::Peripherals {

class Cpu : public BusClient {

public:

    Cpu();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_cpu0_flashcon0;
    u32 m_cpu0_flashcon1;
    u32 m_cpu0_flashcon2;
    u32 m_cpu0_flashcon3;
    u32 m_cpu0_flashcon4;
    u32 m_cpu0_krst0;
    u32 m_cpu0_krst1;
    u32 m_cpu0_krstclr;
    u32 m_cpu0_osel;
    u32 m_cpu0_segen;
    u32 m_cpu0_task_asi;
    u32 m_cpu0_pma0;
    u32 m_cpu0_pma1;
    u32 m_cpu0_pma2;
    u32 m_cpu0_dcon2;
    u32 m_cpu0_smacon;
    u32 m_cpu0_dstr;
    u32 m_cpu0_datr;
    u32 m_cpu0_deadd;
    u32 m_cpu0_diear;
    u32 m_cpu0_dietr;
    u32 m_cpu0_dcon0;
    u32 m_cpu0_pstr;
    u32 m_cpu0_pcon1;
    u32 m_cpu0_pcon2;
    u32 m_cpu0_pcon0;
    u32 m_cpu0_piear;
    u32 m_cpu0_pietr;
    u32 m_cpu0_compat;
    u32 m_cpu0_tps_con;
    u32 m_cpu0_cctrl;
    u32 m_cpu0_ccnt;
    u32 m_cpu0_icnt;
    u32 m_cpu0_m1cnt;
    u32 m_cpu0_m2cnt;
    u32 m_cpu0_m3cnt;
    u32 m_cpu0_dbgsr;
    u32 m_cpu0_exevt;
    u32 m_cpu0_crevt;
    u32 m_cpu0_swevt;
    u32 m_cpu0_trig_acc;
    u32 m_cpu0_dms;
    u32 m_cpu0_dcx;
    u32 m_cpu0_dbgtcr;
    u32 m_cpu0_pcxi;
    u32 m_cpu0_psw;
    u32 m_cpu0_pc;
    u32 m_cpu0_syscon;
    u32 m_cpu0_cpu_id;
    u32 m_cpu0_core_id;
    u32 m_cpu0_biv;
    u32 m_cpu0_btv;
    u32 m_cpu0_isp;
    u32 m_cpu0_icr;
    u32 m_cpu0_fcx;
    u32 m_cpu0_lcx;
    u32 m_cpu0_cus_id;

};

} // namespace Tricore
