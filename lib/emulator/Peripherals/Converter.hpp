
/**
 * @brief Module header for Converter peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Converter : public BusClient {

public:

    Converter();

    void read(byte *buffer_out, u32 address, usize length) override;

    void write(const byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_converter_clc;
    u32 m_converter_id;
    u32 m_converter_ocs;
    u32 m_converter_krstclr;
    u32 m_converter_krst1;
    u32 m_converter_krst0;
    u32 m_converter_accen0;
    u32 m_converter_ccctrl;
    u32 m_converter_phscfg;
    u32 m_converter_phssfty;

};

} // namespace Tricore
