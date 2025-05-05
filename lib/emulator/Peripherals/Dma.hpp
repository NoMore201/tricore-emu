
/**
 * @brief Module header for Dma peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Dma : public BusClient {

public:

    Dma();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_dma_clc;
    u32 m_dma_id;
    u32 m_dma_otss;
    u32 m_dma_prr0;
    u32 m_dma_prr1;
    u32 m_dma_time;

};

} // namespace Tricore
