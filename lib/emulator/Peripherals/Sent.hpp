
/**
 * @brief Module header for Sent peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Sent : public BusClient {

public:

    Sent();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_sent_clc;
    u32 m_sent_id;
    u32 m_sent_fdr;
    u32 m_sent_intov;
    u32 m_sent_tsr;
    u32 m_sent_tpd;
    u32 m_sent_ocs;
    u32 m_sent_krstclr;
    u32 m_sent_krst1;
    u32 m_sent_krst0;
    u32 m_sent_accen1;
    u32 m_sent_accen0;

};

} // namespace Tricore
