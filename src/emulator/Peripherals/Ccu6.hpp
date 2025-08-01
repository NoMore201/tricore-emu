
/**
 * @brief Module header for Ccu6 peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Ccu6 : public BusClient {

public:

    Ccu6();

    void read(byte *buffer_out, u32 address, usize length) override;

    void write(const byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_ccu60_clc;
    u32 m_ccu60_mcfg;
    u32 m_ccu60_id;
    u32 m_ccu60_mosel;
    u32 m_ccu60_pisel0;
    u32 m_ccu60_pisel2;
    u32 m_ccu60_kscsr;
    u32 m_ccu60_t12;
    u32 m_ccu60_t12pr;
    u32 m_ccu60_t12dtc;
    u32 m_ccu60_t13;
    u32 m_ccu60_t13pr;
    u32 m_ccu60_cc63r;
    u32 m_ccu60_cc63sr;
    u32 m_ccu60_cmpstat;
    u32 m_ccu60_cmpmodif;
    u32 m_ccu60_t12msel;
    u32 m_ccu60_tctr0;
    u32 m_ccu60_tctr2;
    u32 m_ccu60_tctr4;
    u32 m_ccu60_modctr;
    u32 m_ccu60_trpctr;
    u32 m_ccu60_pslr;
    u32 m_ccu60_mcmouts;
    u32 m_ccu60_mcmout;
    u32 m_ccu60_mcmctr;
    u32 m_ccu60_imon;
    u32 m_ccu60_li;
    u32 m_ccu60_is;
    u32 m_ccu60_iss;
    u32 m_ccu60_isr;
    u32 m_ccu60_inp;
    u32 m_ccu60_ien;
    u32 m_ccu60_ocs;
    u32 m_ccu60_krstclr;
    u32 m_ccu60_krst1;
    u32 m_ccu60_krst0;
    u32 m_ccu60_accen0;
    u32 m_ccu61_clc;
    u32 m_ccu61_mcfg;
    u32 m_ccu61_id;
    u32 m_ccu61_pisel0;
    u32 m_ccu61_pisel2;
    u32 m_ccu61_kscsr;
    u32 m_ccu61_t12;
    u32 m_ccu61_t12pr;
    u32 m_ccu61_t12dtc;
    u32 m_ccu61_t13;
    u32 m_ccu61_t13pr;
    u32 m_ccu61_cc63r;
    u32 m_ccu61_cc63sr;
    u32 m_ccu61_cmpstat;
    u32 m_ccu61_cmpmodif;
    u32 m_ccu61_t12msel;
    u32 m_ccu61_tctr0;
    u32 m_ccu61_tctr2;
    u32 m_ccu61_tctr4;
    u32 m_ccu61_modctr;
    u32 m_ccu61_trpctr;
    u32 m_ccu61_pslr;
    u32 m_ccu61_mcmouts;
    u32 m_ccu61_mcmout;
    u32 m_ccu61_mcmctr;
    u32 m_ccu61_imon;
    u32 m_ccu61_li;
    u32 m_ccu61_is;
    u32 m_ccu61_iss;
    u32 m_ccu61_isr;
    u32 m_ccu61_inp;
    u32 m_ccu61_ien;
    u32 m_ccu61_ocs;
    u32 m_ccu61_krstclr;
    u32 m_ccu61_krst1;
    u32 m_ccu61_krst0;
    u32 m_ccu61_accen0;

};

} // namespace Tricore
