
/**
 * @brief Module header for Eray peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Eray : public BusClient {

public:

    Eray();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_eray0_clc;
    u32 m_eray0_cust1;
    u32 m_eray0_id;
    u32 m_eray0_cust3;
    u32 m_eray0_test1;
    u32 m_eray0_test2;
    u32 m_eray0_lck;
    u32 m_eray0_eir;
    u32 m_eray0_sir;
    u32 m_eray0_eils;
    u32 m_eray0_sils;
    u32 m_eray0_eies;
    u32 m_eray0_eier;
    u32 m_eray0_sies;
    u32 m_eray0_sier;
    u32 m_eray0_ile;
    u32 m_eray0_t0c;
    u32 m_eray0_t1c;
    u32 m_eray0_stpw1;
    u32 m_eray0_stpw2;
    u32 m_eray0_succ1;
    u32 m_eray0_succ2;
    u32 m_eray0_succ3;
    u32 m_eray0_nemc;
    u32 m_eray0_prtc1;
    u32 m_eray0_prtc2;
    u32 m_eray0_mhdc;
    u32 m_eray0_gtuc01;
    u32 m_eray0_gtuc02;
    u32 m_eray0_gtuc03;
    u32 m_eray0_gtuc04;
    u32 m_eray0_gtuc05;
    u32 m_eray0_gtuc06;
    u32 m_eray0_gtuc07;
    u32 m_eray0_gtuc08;
    u32 m_eray0_gtuc09;
    u32 m_eray0_gtuc10;
    u32 m_eray0_gtuc11;
    u32 m_eray0_ccsv;
    u32 m_eray0_ccev;
    u32 m_eray0_scv;
    u32 m_eray0_mtccv;
    u32 m_eray0_rcv;
    u32 m_eray0_ocv;
    u32 m_eray0_sfs;
    u32 m_eray0_swnit;
    u32 m_eray0_acs;
    u32 m_eray0_mrc;
    u32 m_eray0_frf;
    u32 m_eray0_frfm;
    u32 m_eray0_fcl;
    u32 m_eray0_mhds;
    u32 m_eray0_ldts;
    u32 m_eray0_fsr;
    u32 m_eray0_mhdf;
    u32 m_eray0_txrq1;
    u32 m_eray0_txrq2;
    u32 m_eray0_txrq3;
    u32 m_eray0_txrq4;
    u32 m_eray0_ndat1;
    u32 m_eray0_ndat2;
    u32 m_eray0_ndat3;
    u32 m_eray0_ndat4;
    u32 m_eray0_mbsc1;
    u32 m_eray0_mbsc2;
    u32 m_eray0_mbsc3;
    u32 m_eray0_mbsc4;
    u32 m_eray0_ndic1;
    u32 m_eray0_ndic2;
    u32 m_eray0_ndic3;
    u32 m_eray0_ndic4;
    u32 m_eray0_msic1;
    u32 m_eray0_msic2;
    u32 m_eray0_msic3;
    u32 m_eray0_msic4;
    u32 m_eray0_crel;
    u32 m_eray0_endn;
    u32 m_eray0_wrhs1;
    u32 m_eray0_wrhs2;
    u32 m_eray0_wrhs3;
    u32 m_eray0_ibcm;
    u32 m_eray0_ibcr;
    u32 m_eray0_rdhs1;
    u32 m_eray0_rdhs2;
    u32 m_eray0_rdhs3;
    u32 m_eray0_mbs;
    u32 m_eray0_obcm;
    u32 m_eray0_obcr;
    u32 m_eray0_otss;
    u32 m_eray0_ocs;
    u32 m_eray0_krstclr;
    u32 m_eray0_krst1;
    u32 m_eray0_krst0;
    u32 m_eray0_accen0;

};

} // namespace Tricore
