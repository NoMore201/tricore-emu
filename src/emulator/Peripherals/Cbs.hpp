
/**
 * @brief Module header for Cbs peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Cbs : public BusClient {

public:

    Cbs();

    void read(byte *buffer_out, u32 address, usize length) override;

    void write(const byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_cbs_jdpid;
    u32 m_cbs_oifm;
    u32 m_cbs_tipr;
    u32 m_cbs_topr;
    u32 m_cbs_topps;
    u32 m_cbs_tcip;
    u32 m_cbs_trhsm;
    u32 m_cbs_trmc;
    u32 m_cbs_trss;
    u32 m_cbs_jtagid;
    u32 m_cbs_comdata;
    u32 m_cbs_iosr;
    u32 m_cbs_tls;
    u32 m_cbs_tctl;
    u32 m_cbs_oec;
    u32 m_cbs_ocntrl;
    u32 m_cbs_ostate;
    u32 m_cbs_intmod;
    u32 m_cbs_ictsa;
    u32 m_cbs_ictta;
    u32 m_cbs_tlc;
    u32 m_cbs_tl1st;
    u32 m_cbs_tlche;
    u32 m_cbs_tlchs;
    u32 m_cbs_trigs;
    u32 m_cbs_trigc;
    u32 m_cbs_tlt;
    u32 m_cbs_tltth;
    u32 m_cbs_tccb;
    u32 m_cbs_tcch;
    u32 m_cbs_tctgb;
    u32 m_cbs_tcm;
    u32 m_cbs_trmt;
    u32 m_cbs_ifsa;
    u32 m_cbs_ifsc;
    u32 m_cbs_accen1;
    u32 m_cbs_accen0;

};

} // namespace Tricore
