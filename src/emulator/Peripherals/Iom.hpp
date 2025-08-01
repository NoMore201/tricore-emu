
/**
 * @brief Module header for Iom peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Iom : public BusClient {

public:
    Iom();

    void read(byte* buffer_out, u32 address, usize length) override;

    void write(const byte* buffer_in, u32 address, usize length) override;

private:
    u32 m_iom_clc;
    u32 m_iom_id;
    u32 m_iom_krstclr;
    u32 m_iom_krst1;
    u32 m_iom_krst0;
    u32 m_iom_accen1;
    u32 m_iom_accen0;
    u32 m_iom_ecmccfg;
    u32 m_iom_ecmselr;
    u32 m_iom_ecmeth0;
    u32 m_iom_ecmeth1;
    u32 m_iom_gtmexr;
    u32 m_iom_fpcesr;
};

} // namespace Tricore
