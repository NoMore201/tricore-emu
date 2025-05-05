
/**
 * @brief Module header for Qspi peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Qspi : public BusClient {

public:

    Qspi();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_qspi0_clc;
    u32 m_qspi0_pisel;
    u32 m_qspi0_id;
    u32 m_qspi0_globalcon;
    u32 m_qspi0_globalcon1;
    u32 m_qspi0_bacon;
    u32 m_qspi0_status;
    u32 m_qspi0_status1;
    u32 m_qspi0_ssoc;
    u32 m_qspi0_flagsclear;
    u32 m_qspi0_xxlcon;
    u32 m_qspi0_mixentry;
    u32 m_qspi0_baconentry;
    u32 m_qspi0_rxexit;
    u32 m_qspi0_rxexitd;
    u32 m_qspi0_mc;
    u32 m_qspi0_mccon;
    u32 m_qspi0_ocs;
    u32 m_qspi0_krstclr;
    u32 m_qspi0_krst1;
    u32 m_qspi0_krst0;
    u32 m_qspi0_accen1;
    u32 m_qspi0_accen0;
    u32 m_qspi1_clc;
    u32 m_qspi1_pisel;
    u32 m_qspi1_id;
    u32 m_qspi1_globalcon;
    u32 m_qspi1_globalcon1;
    u32 m_qspi1_bacon;
    u32 m_qspi1_status;
    u32 m_qspi1_status1;
    u32 m_qspi1_ssoc;
    u32 m_qspi1_flagsclear;
    u32 m_qspi1_xxlcon;
    u32 m_qspi1_mixentry;
    u32 m_qspi1_baconentry;
    u32 m_qspi1_rxexit;
    u32 m_qspi1_rxexitd;
    u32 m_qspi1_mc;
    u32 m_qspi1_mccon;
    u32 m_qspi1_ocs;
    u32 m_qspi1_krstclr;
    u32 m_qspi1_krst1;
    u32 m_qspi1_krst0;
    u32 m_qspi1_accen1;
    u32 m_qspi1_accen0;
    u32 m_qspi2_clc;
    u32 m_qspi2_pisel;
    u32 m_qspi2_id;
    u32 m_qspi2_globalcon;
    u32 m_qspi2_globalcon1;
    u32 m_qspi2_bacon;
    u32 m_qspi2_status;
    u32 m_qspi2_status1;
    u32 m_qspi2_ssoc;
    u32 m_qspi2_flagsclear;
    u32 m_qspi2_xxlcon;
    u32 m_qspi2_mixentry;
    u32 m_qspi2_baconentry;
    u32 m_qspi2_rxexit;
    u32 m_qspi2_rxexitd;
    u32 m_qspi2_capcon;
    u32 m_qspi2_mc;
    u32 m_qspi2_mccon;
    u32 m_qspi2_ocs;
    u32 m_qspi2_krstclr;
    u32 m_qspi2_krst1;
    u32 m_qspi2_krst0;
    u32 m_qspi2_accen1;
    u32 m_qspi2_accen0;
    u32 m_qspi3_clc;
    u32 m_qspi3_pisel;
    u32 m_qspi3_id;
    u32 m_qspi3_globalcon;
    u32 m_qspi3_globalcon1;
    u32 m_qspi3_bacon;
    u32 m_qspi3_status;
    u32 m_qspi3_status1;
    u32 m_qspi3_ssoc;
    u32 m_qspi3_flagsclear;
    u32 m_qspi3_xxlcon;
    u32 m_qspi3_mixentry;
    u32 m_qspi3_baconentry;
    u32 m_qspi3_rxexit;
    u32 m_qspi3_rxexitd;
    u32 m_qspi3_capcon;
    u32 m_qspi3_mc;
    u32 m_qspi3_mccon;
    u32 m_qspi3_ocs;
    u32 m_qspi3_krstclr;
    u32 m_qspi3_krst1;
    u32 m_qspi3_krst0;
    u32 m_qspi3_accen1;
    u32 m_qspi3_accen0;

};

} // namespace Tricore
