
/**
 * @brief Module header for Smu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */
#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore::Peripherals {

class Smu : public BusClient {

public:

    static constexpr usize AlarmConfigRegisterNumber = 12;

    Smu();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_smu_clc;
    u32 m_smu_id;
    u32 m_smu_cmd;
    u32 m_smu_sts;
    u32 m_smu_fsp;
    u32 m_smu_agc;
    u32 m_smu_rtc;
    u32 m_smu_keys;
    u32 m_smu_dbg;
    u32 m_smu_pctl;
    u32 m_smu_afcnt;
    u32 m_smu_rtac00;
    u32 m_smu_rtac01;
    u32 m_smu_rtac10;
    u32 m_smu_rtac11;
    u32 m_smu_aex;
    u32 m_smu_aexclr;
    u32 m_smu_rmctl;
    u32 m_smu_rmef;
    u32 m_smu_rmsts;
    u32 m_smu_ocs;
    u32 m_smu_accen1;
    u32 m_smu_accen0;
    u32 m_smu_agcf[AlarmConfigRegisterNumber][3];
    

};

} // namespace Tricore::Peripherals
