
/**
 * @brief Module header for Int peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Int : public BusClient {

public:

    Int();

    void read(byte *buffer_out, u32 address, usize length) override;

    void write(const byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_int_id;
    u32 m_int_oobs;
    u32 m_int_ossic;
    u32 m_int_oixts;
    u32 m_int_oixms;
    u32 m_int_oixs0;
    u32 m_int_oixs1;
    u32 m_int_oit;
    u32 m_int_omisp;
    u32 m_int_omisn;
    u32 m_int_accen_config0;
    u32 m_int_accen_config1;

};

} // namespace Tricore
