
/**
 * @brief Module header for Pms peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore::Peripherals {

class Pms : public BusClient {

public:
    Pms();

    void read(byte* buffer_out, u32 address, usize length) override;

    void write(const byte* buffer_in, u32 address, usize length) override;

private:
    u32 m_pms_id;
    u32 m_pms_evrstat;
    u32 m_pms_evradcstat;
    u32 m_pms_evrrstcon;
    u32 m_pms_evrrststat;
    u32 m_pms_evrtrim;
    u32 m_pms_evrtrimstat;
    u32 m_pms_monstat1;
    u32 m_pms_monstat2;
    u32 m_pms_monctrl;
    u32 m_pms_monfilt;
    u32 m_pms_pmsien;
    u32 m_pms_uvmon;
    u32 m_pms_ovmon;
    u32 m_pms_uvmon2;
    u32 m_pms_ovmon2;
    u32 m_pms_hsmuvmon;
    u32 m_pms_hsmovmon;
    u32 m_pms_evr33con;
    u32 m_pms_evroscctrl;
    u32 m_pms_pmswcr0;
    u32 m_pms_pmswcr2;
    u32 m_pms_pmswcr3;
    u32 m_pms_pmswcr4;
    u32 m_pms_pmswcr5;
    u32 m_pms_pmswstat;
    u32 m_pms_pmswstat2;
    u32 m_pms_pmswutcnt;
    u32 m_pms_pmswstatclr;
    u32 m_pms_evrsdstat0;
    u32 m_pms_evrsdctrl0;
    u32 m_pms_evrsdctrl1;
    u32 m_pms_evrsdctrl2;
    u32 m_pms_evrsdctrl3;
    u32 m_pms_evrsdctrl4;
    u32 m_pms_evrsdctrl5;
    u32 m_pms_evrsdctrl6;
    u32 m_pms_evrsdctrl7;
    u32 m_pms_evrsdctrl8;
    u32 m_pms_evrsdctrl9;
    u32 m_pms_evrsdctrl10;
    u32 m_pms_evrsdcoeff0;
    u32 m_pms_evrsdcoeff1;
    u32 m_pms_evrsdcoeff2;
    u32 m_pms_evrsdcoeff3;
    u32 m_pms_ag_stdby0;
    u32 m_pms_ag_stdby1;
    u32 m_pms_monbiststat;
    u32 m_pms_monbistctrl;
    u32 m_pms_cmd_stdby;
    u32 m_pms_agfsp_stdby0;
    u32 m_pms_agfsp_stdby1;
    u32 m_pms_dtsstat;
    u32 m_pms_dtslim;
    u32 m_pms_otss;
    u32 m_pms_otsc0;
    u32 m_pms_otsc1;
    u32 m_pms_accen0;
    u32 m_pms_accen1;
};

} // namespace Tricore
