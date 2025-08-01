
/**
 * @brief Module header for Src peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Src : public BusClient {

public:
    Src();

    void read(byte* buffer_out, u32 address, usize length) override;

    void write(const byte* buffer_in, u32 address, usize length) override;

private:
};

} // namespace Tricore
