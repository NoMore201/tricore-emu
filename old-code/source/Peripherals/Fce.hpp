
/**
 * @brief Module header for Fce peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Fce : public BusClient {

public:

    Fce();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_fce_clc;
    u32 m_fce_id;
    u32 m_fce_chsts;
    u32 m_fce_krstclr;
    u32 m_fce_krst1;
    u32 m_fce_krst0;
    u32 m_fce_accen1;
    u32 m_fce_accen0;

};

} // namespace Tricore
