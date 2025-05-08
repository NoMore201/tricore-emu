
/**
 * @brief Module header for Sbcu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Sbcu : public BusClient {

public:

    Sbcu();

    void read(byte *buffer_out, u32 address, usize length) override;

    void write(const byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_sbcu_id;
    u32 m_sbcu_con;
    u32 m_sbcu_prioh;
    u32 m_sbcu_priol;
    u32 m_sbcu_econ;
    u32 m_sbcu_eadd;
    u32 m_sbcu_edat;
    u32 m_sbcu_dbcntl;
    u32 m_sbcu_dbgrnt;
    u32 m_sbcu_dbadr1;
    u32 m_sbcu_dbadr2;
    u32 m_sbcu_dbbos;
    u32 m_sbcu_dbgntt;
    u32 m_sbcu_dbadrt;
    u32 m_sbcu_dbbost;
    u32 m_sbcu_dbdat;
    u32 m_sbcu_alctrl;
    u32 m_sbcu_fegen;
    u32 m_sbcu_accen1;
    u32 m_sbcu_accen0;

};

} // namespace Tricore
