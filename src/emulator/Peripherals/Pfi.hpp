
/**
 * @brief Module header for Pfi peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Pfi : public BusClient {

public:
    Pfi();

    void read(byte* buffer_out, u32 address, usize length) override;

    void write(const byte* buffer_in, u32 address, usize length) override;

private:
    u32 m_pfi0_eccr;
    u32 m_pfi0_eccs;
};

} // namespace Tricore
