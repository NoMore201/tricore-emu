
/**
 * @brief Module header for Stm peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore::Peripherals {

class Stm : public BusClient {

public:

    Stm();

    void read(byte *buffer_out, u32 address, usize length) override;

    void write(const byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_stm0_clc;
    u32 m_stm0_id;
    u32 m_stm0_tim0;
    u32 m_stm0_tim1;
    u32 m_stm0_tim2;
    u32 m_stm0_tim3;
    u32 m_stm0_tim4;
    u32 m_stm0_tim5;
    u32 m_stm0_tim6;
    u32 m_stm0_cap;
    u32 m_stm0_cmcon;
    u32 m_stm0_icr;
    u32 m_stm0_iscr;
    u32 m_stm0_tim0sv;
    u32 m_stm0_capsv;
    u32 m_stm0_ocs;
    u32 m_stm0_krstclr;
    u32 m_stm0_krst1;
    u32 m_stm0_krst0;
    u32 m_stm0_accen1;
    u32 m_stm0_accen0;

};

} // namespace Tricore
