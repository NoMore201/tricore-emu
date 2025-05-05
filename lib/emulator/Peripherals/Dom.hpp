
/**
 * @brief Module header for Dom peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Dom : public BusClient {

public:

    Dom();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_dom0_id;
    u32 m_dom0_pestat;
    u32 m_dom0_tidstat;
    u32 m_dom0_tiden;
    u32 m_dom0_brcon;
    u32 m_dom0_accen0;
    u32 m_dom0_accen1;

};

} // namespace Tricore
