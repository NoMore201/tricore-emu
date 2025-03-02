
/**
 * @brief Module header for Fsi peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Fsi : public BusClient {

public:

    Fsi();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_fsi_comm_1;
    u32 m_fsi_comm_2;
    u32 m_fsi_hsmcomm_1;
    u32 m_fsi_hsmcomm_2;

};

} // namespace Tricore
