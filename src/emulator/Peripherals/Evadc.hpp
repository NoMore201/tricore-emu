
/**
 * @brief Module header for Evadc peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Evadc : public BusClient {

public:
    Evadc();

    void read(byte* buffer_out, u32 address, usize length) override;

    void write(const byte* buffer_in, u32 address, usize length) override;

private:
    u32 m_evadc_clc;
    u32 m_evadc_id;
    u32 m_evadc_ocs;
    u32 m_evadc_krstclr;
    u32 m_evadc_krst1;
    u32 m_evadc_krst0;
    u32 m_evadc_accen0;
    u32 m_evadc_globcfg;
    u32 m_evadc_accprot0;
    u32 m_evadc_accprot1;
    u32 m_evadc_accprot2;
    u32 m_evadc_glob_bound;
    u32 m_evadc_glob_eflag;
    u32 m_evadc_glob_evnp;
    u32 m_evadc_glob_tf;
    u32 m_evadc_glob_te;
    u32 m_evadc_glob_rcr;
    u32 m_evadc_glob_res;
    u32 m_evadc_glob_resd;
    u32 m_evadc_emuxsel;
};

} // namespace Tricore
