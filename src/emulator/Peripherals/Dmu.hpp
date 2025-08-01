
/**
 * @brief Module header for Dmu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Dmu : public BusClient {

public:

    Dmu();

    void read(byte *buffer_out, u32 address, usize length) override;

    void write(const byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_dmu_hf_id;
    u32 m_dmu_hf_status;
    u32 m_dmu_hf_control;
    u32 m_dmu_hf_operation;
    u32 m_dmu_hf_protect;
    u32 m_dmu_hf_confirm0;
    u32 m_dmu_hf_confirm1;
    u32 m_dmu_hf_confirm2;
    u32 m_dmu_hf_eer;
    u32 m_dmu_hf_errsr;
    u32 m_dmu_hf_clre;
    u32 m_dmu_hf_eccr;
    u32 m_dmu_hf_eccs;
    u32 m_dmu_hf_eccc;
    u32 m_dmu_hf_eccw;
    u32 m_dmu_hf_ccontrol;
    u32 m_dmu_hf_pstatus;
    u32 m_dmu_hf_pcontrol;
    u32 m_dmu_hf_pwait;
    u32 m_dmu_hf_dwait;
    u32 m_dmu_hf_proconusr;
    u32 m_dmu_hf_proconpf;
    u32 m_dmu_hf_procontp;
    u32 m_dmu_hf_procondf;
    u32 m_dmu_hf_proconram;
    u32 m_dmu_hf_procondbg;
    u32 m_dmu_hf_suspend;
    u32 m_dmu_hf_margin;
    u32 m_dmu_hf_accen1;
    u32 m_dmu_hf_accen0;
    u32 m_dmu_sf_status;
    u32 m_dmu_sf_control;
    u32 m_dmu_sf_operation;
    u32 m_dmu_sf_eer;
    u32 m_dmu_sf_errsr;
    u32 m_dmu_sf_clre;
    u32 m_dmu_sf_eccr;
    u32 m_dmu_sf_eccs;
    u32 m_dmu_sf_eccc;
    u32 m_dmu_sf_eccw;
    u32 m_dmu_sf_proconusr;
    u32 m_dmu_sf_suspend;
    u32 m_dmu_sf_margin;
    u32 m_dmu_sp_proconhsmcfg;
    u32 m_dmu_sp_proconhsmcbs;
    u32 m_dmu_sp_proconhsmcx0;
    u32 m_dmu_sp_proconhsmcx1;
    u32 m_dmu_sp_proconhsmcotp0;
    u32 m_dmu_sp_proconhsmcotp1;
    u32 m_dmu_sp_proconhsm;

};

} // namespace Tricore
