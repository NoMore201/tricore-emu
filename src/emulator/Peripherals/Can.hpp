
/**
 * @brief Module header for Can peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Can : public BusClient {

public:

    Can();

    void read(byte *buffer_out, u32 address, usize length) override;

    void write(const byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_can0_clc;
    u32 m_can0_id;
    u32 m_can0_mcr;
    u32 m_can0_bufadr;
    u32 m_can0_mecr;
    u32 m_can0_mestat;
    u32 m_can0_accenctr0;
    u32 m_can0_ocs;
    u32 m_can0_krstclr;
    u32 m_can0_krst1;
    u32 m_can0_krst0;
    u32 m_can0_accen0;
    u32 m_can1_clc;
    u32 m_can1_id;
    u32 m_can1_mcr;
    u32 m_can1_accenctr0;
    u32 m_can1_ocs;
    u32 m_can1_krstclr;
    u32 m_can1_krst1;
    u32 m_can1_krst0;
    u32 m_can1_accen0;

};

} // namespace Tricore
