
/**
 * @brief Module header for Mtu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore::Peripherals {

class Mtu : public BusClient {

public:

    Mtu();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_mtu_clc;
    u32 m_mtu_id;
    u32 m_mtu_memtest0;
    u32 m_mtu_memtest1;
    u32 m_mtu_memtest2;
    u32 m_mtu_memmap;
    u32 m_mtu_memstat0;
    u32 m_mtu_memstat1;
    u32 m_mtu_memstat2;
    u32 m_mtu_memdone0;
    u32 m_mtu_memdone1;
    u32 m_mtu_memdone2;
    u32 m_mtu_memfda0;
    u32 m_mtu_memfda1;
    u32 m_mtu_memfda2;
    u32 m_mtu_accen1;
    u32 m_mtu_accen0;

};

} // namespace Tricore
