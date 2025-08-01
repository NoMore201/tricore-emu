
/**
 * @brief Module header for Gpt12 peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Gpt12 : public BusClient {

public:

    Gpt12();

    void read(byte *buffer_out, u32 address, usize length) override;

    void write(const byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_gpt120_clc;
    u32 m_gpt120_pisel;
    u32 m_gpt120_id;
    u32 m_gpt120_t2con;
    u32 m_gpt120_t3con;
    u32 m_gpt120_t4con;
    u32 m_gpt120_t5con;
    u32 m_gpt120_t6con;
    u32 m_gpt120_caprel;
    u32 m_gpt120_t2;
    u32 m_gpt120_t3;
    u32 m_gpt120_t4;
    u32 m_gpt120_t5;
    u32 m_gpt120_t6;
    u32 m_gpt120_ocs;
    u32 m_gpt120_krstclr;
    u32 m_gpt120_krst1;
    u32 m_gpt120_krst0;
    u32 m_gpt120_accen0;

};

} // namespace Tricore
