
/**
 * @brief Module source for Port peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Port.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 p00_out_reset_value = 0; // TODO: change according manual
constexpr u32 p00_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p00_id_reset_value = 0; // TODO: change according manual
constexpr u32 p00_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p00_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p00_iocr8_reset_value = 0; // TODO: change according manual
constexpr u32 p00_iocr12_reset_value = 0; // TODO: change according manual
constexpr u32 p00_in_reset_value = 0; // TODO: change according manual
constexpr u32 p00_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p00_pdr1_reset_value = 0; // TODO: change according manual
constexpr u32 p00_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p00_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p00_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p00_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p00_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p00_omsr8_reset_value = 0; // TODO: change according manual
constexpr u32 p00_omsr12_reset_value = 0; // TODO: change according manual
constexpr u32 p00_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p00_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p00_omcr8_reset_value = 0; // TODO: change according manual
constexpr u32 p00_omcr12_reset_value = 0; // TODO: change according manual
constexpr u32 p00_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p00_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p00_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p00_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p02_out_reset_value = 0; // TODO: change according manual
constexpr u32 p02_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p02_id_reset_value = 0; // TODO: change according manual
constexpr u32 p02_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p02_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p02_iocr8_reset_value = 0; // TODO: change according manual
constexpr u32 p02_in_reset_value = 0; // TODO: change according manual
constexpr u32 p02_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p02_pdr1_reset_value = 0; // TODO: change according manual
constexpr u32 p02_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p02_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p02_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p02_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p02_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p02_omsr8_reset_value = 0; // TODO: change according manual
constexpr u32 p02_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p02_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p02_omcr8_reset_value = 0; // TODO: change according manual
constexpr u32 p02_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p02_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p02_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p02_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p10_out_reset_value = 0; // TODO: change according manual
constexpr u32 p10_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p10_id_reset_value = 0; // TODO: change according manual
constexpr u32 p10_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p10_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p10_iocr8_reset_value = 0; // TODO: change according manual
constexpr u32 p10_in_reset_value = 0; // TODO: change according manual
constexpr u32 p10_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p10_pdr1_reset_value = 0; // TODO: change according manual
constexpr u32 p10_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p10_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p10_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p10_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p10_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p10_omsr8_reset_value = 0; // TODO: change according manual
constexpr u32 p10_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p10_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p10_omcr8_reset_value = 0; // TODO: change according manual
constexpr u32 p10_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p10_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p10_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p10_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p11_out_reset_value = 0; // TODO: change according manual
constexpr u32 p11_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p11_id_reset_value = 0; // TODO: change according manual
constexpr u32 p11_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p11_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p11_iocr8_reset_value = 0; // TODO: change according manual
constexpr u32 p11_iocr12_reset_value = 0; // TODO: change according manual
constexpr u32 p11_in_reset_value = 0; // TODO: change according manual
constexpr u32 p11_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p11_pdr1_reset_value = 0; // TODO: change according manual
constexpr u32 p11_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p11_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p11_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p11_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p11_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p11_omsr8_reset_value = 0; // TODO: change according manual
constexpr u32 p11_omsr12_reset_value = 0; // TODO: change according manual
constexpr u32 p11_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p11_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p11_omcr8_reset_value = 0; // TODO: change according manual
constexpr u32 p11_omcr12_reset_value = 0; // TODO: change according manual
constexpr u32 p11_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p11_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p11_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p11_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p13_out_reset_value = 0; // TODO: change according manual
constexpr u32 p13_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p13_id_reset_value = 0; // TODO: change according manual
constexpr u32 p13_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p13_in_reset_value = 0; // TODO: change according manual
constexpr u32 p13_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p13_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p13_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p13_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p13_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p13_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p13_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p13_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p13_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p13_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p14_out_reset_value = 0; // TODO: change according manual
constexpr u32 p14_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p14_id_reset_value = 0; // TODO: change according manual
constexpr u32 p14_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p14_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p14_iocr8_reset_value = 0; // TODO: change according manual
constexpr u32 p14_in_reset_value = 0; // TODO: change according manual
constexpr u32 p14_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p14_pdr1_reset_value = 0; // TODO: change according manual
constexpr u32 p14_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p14_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p14_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p14_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p14_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p14_omsr8_reset_value = 0; // TODO: change according manual
constexpr u32 p14_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p14_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p14_omcr8_reset_value = 0; // TODO: change according manual
constexpr u32 p14_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p14_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p14_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p14_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p15_out_reset_value = 0; // TODO: change according manual
constexpr u32 p15_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p15_id_reset_value = 0; // TODO: change according manual
constexpr u32 p15_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p15_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p15_iocr8_reset_value = 0; // TODO: change according manual
constexpr u32 p15_in_reset_value = 0; // TODO: change according manual
constexpr u32 p15_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p15_pdr1_reset_value = 0; // TODO: change according manual
constexpr u32 p15_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p15_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p15_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p15_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p15_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p15_omsr8_reset_value = 0; // TODO: change according manual
constexpr u32 p15_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p15_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p15_omcr8_reset_value = 0; // TODO: change according manual
constexpr u32 p15_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p15_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p15_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p15_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p20_out_reset_value = 0; // TODO: change according manual
constexpr u32 p20_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p20_id_reset_value = 0; // TODO: change according manual
constexpr u32 p20_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p20_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p20_iocr8_reset_value = 0; // TODO: change according manual
constexpr u32 p20_iocr12_reset_value = 0; // TODO: change according manual
constexpr u32 p20_in_reset_value = 0; // TODO: change according manual
constexpr u32 p20_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p20_pdr1_reset_value = 0; // TODO: change according manual
constexpr u32 p20_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p20_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p20_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p20_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p20_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p20_omsr8_reset_value = 0; // TODO: change according manual
constexpr u32 p20_omsr12_reset_value = 0; // TODO: change according manual
constexpr u32 p20_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p20_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p20_omcr8_reset_value = 0; // TODO: change according manual
constexpr u32 p20_omcr12_reset_value = 0; // TODO: change according manual
constexpr u32 p20_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p20_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p20_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p20_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p21_out_reset_value = 0; // TODO: change according manual
constexpr u32 p21_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p21_id_reset_value = 0; // TODO: change according manual
constexpr u32 p21_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p21_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p21_in_reset_value = 0; // TODO: change according manual
constexpr u32 p21_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p21_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p21_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p21_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p21_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p21_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p21_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p21_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p21_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p21_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p21_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p21_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p22_out_reset_value = 0; // TODO: change according manual
constexpr u32 p22_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p22_id_reset_value = 0; // TODO: change according manual
constexpr u32 p22_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p22_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p22_in_reset_value = 0; // TODO: change according manual
constexpr u32 p22_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p22_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p22_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p22_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p22_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p22_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p22_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p22_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p22_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p22_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p22_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p22_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p23_out_reset_value = 0; // TODO: change according manual
constexpr u32 p23_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p23_id_reset_value = 0; // TODO: change according manual
constexpr u32 p23_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p23_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p23_in_reset_value = 0; // TODO: change according manual
constexpr u32 p23_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p23_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p23_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p23_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p23_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p23_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p23_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p23_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p23_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p23_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p23_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p23_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p32_out_reset_value = 0; // TODO: change according manual
constexpr u32 p32_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p32_id_reset_value = 0; // TODO: change according manual
constexpr u32 p32_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p32_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p32_in_reset_value = 0; // TODO: change according manual
constexpr u32 p32_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p32_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p32_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p32_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p32_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p32_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p32_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p32_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p32_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p32_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p32_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p32_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p33_out_reset_value = 0; // TODO: change according manual
constexpr u32 p33_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p33_id_reset_value = 0; // TODO: change according manual
constexpr u32 p33_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p33_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p33_iocr8_reset_value = 0; // TODO: change according manual
constexpr u32 p33_iocr12_reset_value = 0; // TODO: change according manual
constexpr u32 p33_in_reset_value = 0; // TODO: change according manual
constexpr u32 p33_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p33_pdr1_reset_value = 0; // TODO: change according manual
constexpr u32 p33_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p33_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p33_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p33_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p33_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p33_omsr8_reset_value = 0; // TODO: change according manual
constexpr u32 p33_omsr12_reset_value = 0; // TODO: change according manual
constexpr u32 p33_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p33_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p33_omcr8_reset_value = 0; // TODO: change according manual
constexpr u32 p33_omcr12_reset_value = 0; // TODO: change according manual
constexpr u32 p33_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p33_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p33_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p33_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p34_out_reset_value = 0; // TODO: change according manual
constexpr u32 p34_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p34_id_reset_value = 0; // TODO: change according manual
constexpr u32 p34_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p34_in_reset_value = 0; // TODO: change according manual
constexpr u32 p34_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p34_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p34_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p34_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p34_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p34_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p34_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p34_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p34_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p34_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 p40_out_reset_value = 0; // TODO: change according manual
constexpr u32 p40_omr_reset_value = 0; // TODO: change according manual
constexpr u32 p40_id_reset_value = 0; // TODO: change according manual
constexpr u32 p40_iocr0_reset_value = 0; // TODO: change according manual
constexpr u32 p40_iocr4_reset_value = 0; // TODO: change according manual
constexpr u32 p40_iocr8_reset_value = 0; // TODO: change according manual
constexpr u32 p40_in_reset_value = 0; // TODO: change according manual
constexpr u32 p40_pdr0_reset_value = 0; // TODO: change according manual
constexpr u32 p40_pdr1_reset_value = 0; // TODO: change according manual
constexpr u32 p40_esr_reset_value = 0; // TODO: change according manual
constexpr u32 p40_pdisc_reset_value = 0; // TODO: change according manual
constexpr u32 p40_pcsr_reset_value = 0; // TODO: change according manual
constexpr u32 p40_omsr0_reset_value = 0; // TODO: change according manual
constexpr u32 p40_omsr4_reset_value = 0; // TODO: change according manual
constexpr u32 p40_omsr8_reset_value = 0; // TODO: change according manual
constexpr u32 p40_omcr0_reset_value = 0; // TODO: change according manual
constexpr u32 p40_omcr4_reset_value = 0; // TODO: change according manual
constexpr u32 p40_omcr8_reset_value = 0; // TODO: change according manual
constexpr u32 p40_omsr_reset_value = 0; // TODO: change according manual
constexpr u32 p40_omcr_reset_value = 0; // TODO: change according manual
constexpr u32 p40_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 p40_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 port_memory_start_address = 0xf003a000U;
constexpr u32 port_memory_size = 0; // TODO: update according manual;
constexpr u32 port_memory_end_address = port_memory_start_address + port_memory_size;

constexpr u32 reg_p00_out_address = 0xf003a000;
constexpr u32 reg_p00_out_offset = reg_p00_out_address - port_memory_start_address;
constexpr u32 reg_p00_omr_address = 0xf003a004;
constexpr u32 reg_p00_omr_offset = reg_p00_omr_address - port_memory_start_address;
constexpr u32 reg_p00_id_address = 0xf003a008;
constexpr u32 reg_p00_id_offset = reg_p00_id_address - port_memory_start_address;
constexpr u32 reg_p00_iocr0_address = 0xf003a010;
constexpr u32 reg_p00_iocr0_offset = reg_p00_iocr0_address - port_memory_start_address;
constexpr u32 reg_p00_iocr4_address = 0xf003a014;
constexpr u32 reg_p00_iocr4_offset = reg_p00_iocr4_address - port_memory_start_address;
constexpr u32 reg_p00_iocr8_address = 0xf003a018;
constexpr u32 reg_p00_iocr8_offset = reg_p00_iocr8_address - port_memory_start_address;
constexpr u32 reg_p00_iocr12_address = 0xf003a01c;
constexpr u32 reg_p00_iocr12_offset = reg_p00_iocr12_address - port_memory_start_address;
constexpr u32 reg_p00_in_address = 0xf003a024;
constexpr u32 reg_p00_in_offset = reg_p00_in_address - port_memory_start_address;
constexpr u32 reg_p00_pdr0_address = 0xf003a040;
constexpr u32 reg_p00_pdr0_offset = reg_p00_pdr0_address - port_memory_start_address;
constexpr u32 reg_p00_pdr1_address = 0xf003a044;
constexpr u32 reg_p00_pdr1_offset = reg_p00_pdr1_address - port_memory_start_address;
constexpr u32 reg_p00_esr_address = 0xf003a050;
constexpr u32 reg_p00_esr_offset = reg_p00_esr_address - port_memory_start_address;
constexpr u32 reg_p00_pdisc_address = 0xf003a060;
constexpr u32 reg_p00_pdisc_offset = reg_p00_pdisc_address - port_memory_start_address;
constexpr u32 reg_p00_pcsr_address = 0xf003a064;
constexpr u32 reg_p00_pcsr_offset = reg_p00_pcsr_address - port_memory_start_address;
constexpr u32 reg_p00_omsr0_address = 0xf003a070;
constexpr u32 reg_p00_omsr0_offset = reg_p00_omsr0_address - port_memory_start_address;
constexpr u32 reg_p00_omsr4_address = 0xf003a074;
constexpr u32 reg_p00_omsr4_offset = reg_p00_omsr4_address - port_memory_start_address;
constexpr u32 reg_p00_omsr8_address = 0xf003a078;
constexpr u32 reg_p00_omsr8_offset = reg_p00_omsr8_address - port_memory_start_address;
constexpr u32 reg_p00_omsr12_address = 0xf003a07c;
constexpr u32 reg_p00_omsr12_offset = reg_p00_omsr12_address - port_memory_start_address;
constexpr u32 reg_p00_omcr0_address = 0xf003a080;
constexpr u32 reg_p00_omcr0_offset = reg_p00_omcr0_address - port_memory_start_address;
constexpr u32 reg_p00_omcr4_address = 0xf003a084;
constexpr u32 reg_p00_omcr4_offset = reg_p00_omcr4_address - port_memory_start_address;
constexpr u32 reg_p00_omcr8_address = 0xf003a088;
constexpr u32 reg_p00_omcr8_offset = reg_p00_omcr8_address - port_memory_start_address;
constexpr u32 reg_p00_omcr12_address = 0xf003a08c;
constexpr u32 reg_p00_omcr12_offset = reg_p00_omcr12_address - port_memory_start_address;
constexpr u32 reg_p00_omsr_address = 0xf003a090;
constexpr u32 reg_p00_omsr_offset = reg_p00_omsr_address - port_memory_start_address;
constexpr u32 reg_p00_omcr_address = 0xf003a094;
constexpr u32 reg_p00_omcr_offset = reg_p00_omcr_address - port_memory_start_address;
constexpr u32 reg_p00_accen1_address = 0xf003a0f8;
constexpr u32 reg_p00_accen1_offset = reg_p00_accen1_address - port_memory_start_address;
constexpr u32 reg_p00_accen0_address = 0xf003a0fc;
constexpr u32 reg_p00_accen0_offset = reg_p00_accen0_address - port_memory_start_address;
constexpr u32 reg_p02_out_address = 0xf003a200;
constexpr u32 reg_p02_out_offset = reg_p02_out_address - port_memory_start_address;
constexpr u32 reg_p02_omr_address = 0xf003a204;
constexpr u32 reg_p02_omr_offset = reg_p02_omr_address - port_memory_start_address;
constexpr u32 reg_p02_id_address = 0xf003a208;
constexpr u32 reg_p02_id_offset = reg_p02_id_address - port_memory_start_address;
constexpr u32 reg_p02_iocr0_address = 0xf003a210;
constexpr u32 reg_p02_iocr0_offset = reg_p02_iocr0_address - port_memory_start_address;
constexpr u32 reg_p02_iocr4_address = 0xf003a214;
constexpr u32 reg_p02_iocr4_offset = reg_p02_iocr4_address - port_memory_start_address;
constexpr u32 reg_p02_iocr8_address = 0xf003a218;
constexpr u32 reg_p02_iocr8_offset = reg_p02_iocr8_address - port_memory_start_address;
constexpr u32 reg_p02_in_address = 0xf003a224;
constexpr u32 reg_p02_in_offset = reg_p02_in_address - port_memory_start_address;
constexpr u32 reg_p02_pdr0_address = 0xf003a240;
constexpr u32 reg_p02_pdr0_offset = reg_p02_pdr0_address - port_memory_start_address;
constexpr u32 reg_p02_pdr1_address = 0xf003a244;
constexpr u32 reg_p02_pdr1_offset = reg_p02_pdr1_address - port_memory_start_address;
constexpr u32 reg_p02_esr_address = 0xf003a250;
constexpr u32 reg_p02_esr_offset = reg_p02_esr_address - port_memory_start_address;
constexpr u32 reg_p02_pdisc_address = 0xf003a260;
constexpr u32 reg_p02_pdisc_offset = reg_p02_pdisc_address - port_memory_start_address;
constexpr u32 reg_p02_pcsr_address = 0xf003a264;
constexpr u32 reg_p02_pcsr_offset = reg_p02_pcsr_address - port_memory_start_address;
constexpr u32 reg_p02_omsr0_address = 0xf003a270;
constexpr u32 reg_p02_omsr0_offset = reg_p02_omsr0_address - port_memory_start_address;
constexpr u32 reg_p02_omsr4_address = 0xf003a274;
constexpr u32 reg_p02_omsr4_offset = reg_p02_omsr4_address - port_memory_start_address;
constexpr u32 reg_p02_omsr8_address = 0xf003a278;
constexpr u32 reg_p02_omsr8_offset = reg_p02_omsr8_address - port_memory_start_address;
constexpr u32 reg_p02_omcr0_address = 0xf003a280;
constexpr u32 reg_p02_omcr0_offset = reg_p02_omcr0_address - port_memory_start_address;
constexpr u32 reg_p02_omcr4_address = 0xf003a284;
constexpr u32 reg_p02_omcr4_offset = reg_p02_omcr4_address - port_memory_start_address;
constexpr u32 reg_p02_omcr8_address = 0xf003a288;
constexpr u32 reg_p02_omcr8_offset = reg_p02_omcr8_address - port_memory_start_address;
constexpr u32 reg_p02_omsr_address = 0xf003a290;
constexpr u32 reg_p02_omsr_offset = reg_p02_omsr_address - port_memory_start_address;
constexpr u32 reg_p02_omcr_address = 0xf003a294;
constexpr u32 reg_p02_omcr_offset = reg_p02_omcr_address - port_memory_start_address;
constexpr u32 reg_p02_accen1_address = 0xf003a2f8;
constexpr u32 reg_p02_accen1_offset = reg_p02_accen1_address - port_memory_start_address;
constexpr u32 reg_p02_accen0_address = 0xf003a2fc;
constexpr u32 reg_p02_accen0_offset = reg_p02_accen0_address - port_memory_start_address;
constexpr u32 reg_p10_out_address = 0xf003aa00;
constexpr u32 reg_p10_out_offset = reg_p10_out_address - port_memory_start_address;
constexpr u32 reg_p10_omr_address = 0xf003aa04;
constexpr u32 reg_p10_omr_offset = reg_p10_omr_address - port_memory_start_address;
constexpr u32 reg_p10_id_address = 0xf003aa08;
constexpr u32 reg_p10_id_offset = reg_p10_id_address - port_memory_start_address;
constexpr u32 reg_p10_iocr0_address = 0xf003aa10;
constexpr u32 reg_p10_iocr0_offset = reg_p10_iocr0_address - port_memory_start_address;
constexpr u32 reg_p10_iocr4_address = 0xf003aa14;
constexpr u32 reg_p10_iocr4_offset = reg_p10_iocr4_address - port_memory_start_address;
constexpr u32 reg_p10_iocr8_address = 0xf003aa18;
constexpr u32 reg_p10_iocr8_offset = reg_p10_iocr8_address - port_memory_start_address;
constexpr u32 reg_p10_in_address = 0xf003aa24;
constexpr u32 reg_p10_in_offset = reg_p10_in_address - port_memory_start_address;
constexpr u32 reg_p10_pdr0_address = 0xf003aa40;
constexpr u32 reg_p10_pdr0_offset = reg_p10_pdr0_address - port_memory_start_address;
constexpr u32 reg_p10_pdr1_address = 0xf003aa44;
constexpr u32 reg_p10_pdr1_offset = reg_p10_pdr1_address - port_memory_start_address;
constexpr u32 reg_p10_esr_address = 0xf003aa50;
constexpr u32 reg_p10_esr_offset = reg_p10_esr_address - port_memory_start_address;
constexpr u32 reg_p10_pdisc_address = 0xf003aa60;
constexpr u32 reg_p10_pdisc_offset = reg_p10_pdisc_address - port_memory_start_address;
constexpr u32 reg_p10_pcsr_address = 0xf003aa64;
constexpr u32 reg_p10_pcsr_offset = reg_p10_pcsr_address - port_memory_start_address;
constexpr u32 reg_p10_omsr0_address = 0xf003aa70;
constexpr u32 reg_p10_omsr0_offset = reg_p10_omsr0_address - port_memory_start_address;
constexpr u32 reg_p10_omsr4_address = 0xf003aa74;
constexpr u32 reg_p10_omsr4_offset = reg_p10_omsr4_address - port_memory_start_address;
constexpr u32 reg_p10_omsr8_address = 0xf003aa78;
constexpr u32 reg_p10_omsr8_offset = reg_p10_omsr8_address - port_memory_start_address;
constexpr u32 reg_p10_omcr0_address = 0xf003aa80;
constexpr u32 reg_p10_omcr0_offset = reg_p10_omcr0_address - port_memory_start_address;
constexpr u32 reg_p10_omcr4_address = 0xf003aa84;
constexpr u32 reg_p10_omcr4_offset = reg_p10_omcr4_address - port_memory_start_address;
constexpr u32 reg_p10_omcr8_address = 0xf003aa88;
constexpr u32 reg_p10_omcr8_offset = reg_p10_omcr8_address - port_memory_start_address;
constexpr u32 reg_p10_omsr_address = 0xf003aa90;
constexpr u32 reg_p10_omsr_offset = reg_p10_omsr_address - port_memory_start_address;
constexpr u32 reg_p10_omcr_address = 0xf003aa94;
constexpr u32 reg_p10_omcr_offset = reg_p10_omcr_address - port_memory_start_address;
constexpr u32 reg_p10_accen1_address = 0xf003aaf8;
constexpr u32 reg_p10_accen1_offset = reg_p10_accen1_address - port_memory_start_address;
constexpr u32 reg_p10_accen0_address = 0xf003aafc;
constexpr u32 reg_p10_accen0_offset = reg_p10_accen0_address - port_memory_start_address;
constexpr u32 reg_p11_out_address = 0xf003ab00;
constexpr u32 reg_p11_out_offset = reg_p11_out_address - port_memory_start_address;
constexpr u32 reg_p11_omr_address = 0xf003ab04;
constexpr u32 reg_p11_omr_offset = reg_p11_omr_address - port_memory_start_address;
constexpr u32 reg_p11_id_address = 0xf003ab08;
constexpr u32 reg_p11_id_offset = reg_p11_id_address - port_memory_start_address;
constexpr u32 reg_p11_iocr0_address = 0xf003ab10;
constexpr u32 reg_p11_iocr0_offset = reg_p11_iocr0_address - port_memory_start_address;
constexpr u32 reg_p11_iocr4_address = 0xf003ab14;
constexpr u32 reg_p11_iocr4_offset = reg_p11_iocr4_address - port_memory_start_address;
constexpr u32 reg_p11_iocr8_address = 0xf003ab18;
constexpr u32 reg_p11_iocr8_offset = reg_p11_iocr8_address - port_memory_start_address;
constexpr u32 reg_p11_iocr12_address = 0xf003ab1c;
constexpr u32 reg_p11_iocr12_offset = reg_p11_iocr12_address - port_memory_start_address;
constexpr u32 reg_p11_in_address = 0xf003ab24;
constexpr u32 reg_p11_in_offset = reg_p11_in_address - port_memory_start_address;
constexpr u32 reg_p11_pdr0_address = 0xf003ab40;
constexpr u32 reg_p11_pdr0_offset = reg_p11_pdr0_address - port_memory_start_address;
constexpr u32 reg_p11_pdr1_address = 0xf003ab44;
constexpr u32 reg_p11_pdr1_offset = reg_p11_pdr1_address - port_memory_start_address;
constexpr u32 reg_p11_esr_address = 0xf003ab50;
constexpr u32 reg_p11_esr_offset = reg_p11_esr_address - port_memory_start_address;
constexpr u32 reg_p11_pdisc_address = 0xf003ab60;
constexpr u32 reg_p11_pdisc_offset = reg_p11_pdisc_address - port_memory_start_address;
constexpr u32 reg_p11_pcsr_address = 0xf003ab64;
constexpr u32 reg_p11_pcsr_offset = reg_p11_pcsr_address - port_memory_start_address;
constexpr u32 reg_p11_omsr0_address = 0xf003ab70;
constexpr u32 reg_p11_omsr0_offset = reg_p11_omsr0_address - port_memory_start_address;
constexpr u32 reg_p11_omsr4_address = 0xf003ab74;
constexpr u32 reg_p11_omsr4_offset = reg_p11_omsr4_address - port_memory_start_address;
constexpr u32 reg_p11_omsr8_address = 0xf003ab78;
constexpr u32 reg_p11_omsr8_offset = reg_p11_omsr8_address - port_memory_start_address;
constexpr u32 reg_p11_omsr12_address = 0xf003ab7c;
constexpr u32 reg_p11_omsr12_offset = reg_p11_omsr12_address - port_memory_start_address;
constexpr u32 reg_p11_omcr0_address = 0xf003ab80;
constexpr u32 reg_p11_omcr0_offset = reg_p11_omcr0_address - port_memory_start_address;
constexpr u32 reg_p11_omcr4_address = 0xf003ab84;
constexpr u32 reg_p11_omcr4_offset = reg_p11_omcr4_address - port_memory_start_address;
constexpr u32 reg_p11_omcr8_address = 0xf003ab88;
constexpr u32 reg_p11_omcr8_offset = reg_p11_omcr8_address - port_memory_start_address;
constexpr u32 reg_p11_omcr12_address = 0xf003ab8c;
constexpr u32 reg_p11_omcr12_offset = reg_p11_omcr12_address - port_memory_start_address;
constexpr u32 reg_p11_omsr_address = 0xf003ab90;
constexpr u32 reg_p11_omsr_offset = reg_p11_omsr_address - port_memory_start_address;
constexpr u32 reg_p11_omcr_address = 0xf003ab94;
constexpr u32 reg_p11_omcr_offset = reg_p11_omcr_address - port_memory_start_address;
constexpr u32 reg_p11_accen1_address = 0xf003abf8;
constexpr u32 reg_p11_accen1_offset = reg_p11_accen1_address - port_memory_start_address;
constexpr u32 reg_p11_accen0_address = 0xf003abfc;
constexpr u32 reg_p11_accen0_offset = reg_p11_accen0_address - port_memory_start_address;
constexpr u32 reg_p13_out_address = 0xf003ad00;
constexpr u32 reg_p13_out_offset = reg_p13_out_address - port_memory_start_address;
constexpr u32 reg_p13_omr_address = 0xf003ad04;
constexpr u32 reg_p13_omr_offset = reg_p13_omr_address - port_memory_start_address;
constexpr u32 reg_p13_id_address = 0xf003ad08;
constexpr u32 reg_p13_id_offset = reg_p13_id_address - port_memory_start_address;
constexpr u32 reg_p13_iocr0_address = 0xf003ad10;
constexpr u32 reg_p13_iocr0_offset = reg_p13_iocr0_address - port_memory_start_address;
constexpr u32 reg_p13_in_address = 0xf003ad24;
constexpr u32 reg_p13_in_offset = reg_p13_in_address - port_memory_start_address;
constexpr u32 reg_p13_pdr0_address = 0xf003ad40;
constexpr u32 reg_p13_pdr0_offset = reg_p13_pdr0_address - port_memory_start_address;
constexpr u32 reg_p13_esr_address = 0xf003ad50;
constexpr u32 reg_p13_esr_offset = reg_p13_esr_address - port_memory_start_address;
constexpr u32 reg_p13_pdisc_address = 0xf003ad60;
constexpr u32 reg_p13_pdisc_offset = reg_p13_pdisc_address - port_memory_start_address;
constexpr u32 reg_p13_pcsr_address = 0xf003ad64;
constexpr u32 reg_p13_pcsr_offset = reg_p13_pcsr_address - port_memory_start_address;
constexpr u32 reg_p13_omsr0_address = 0xf003ad70;
constexpr u32 reg_p13_omsr0_offset = reg_p13_omsr0_address - port_memory_start_address;
constexpr u32 reg_p13_omcr0_address = 0xf003ad80;
constexpr u32 reg_p13_omcr0_offset = reg_p13_omcr0_address - port_memory_start_address;
constexpr u32 reg_p13_omsr_address = 0xf003ad90;
constexpr u32 reg_p13_omsr_offset = reg_p13_omsr_address - port_memory_start_address;
constexpr u32 reg_p13_omcr_address = 0xf003ad94;
constexpr u32 reg_p13_omcr_offset = reg_p13_omcr_address - port_memory_start_address;
constexpr u32 reg_p13_accen1_address = 0xf003adf8;
constexpr u32 reg_p13_accen1_offset = reg_p13_accen1_address - port_memory_start_address;
constexpr u32 reg_p13_accen0_address = 0xf003adfc;
constexpr u32 reg_p13_accen0_offset = reg_p13_accen0_address - port_memory_start_address;
constexpr u32 reg_p14_out_address = 0xf003ae00;
constexpr u32 reg_p14_out_offset = reg_p14_out_address - port_memory_start_address;
constexpr u32 reg_p14_omr_address = 0xf003ae04;
constexpr u32 reg_p14_omr_offset = reg_p14_omr_address - port_memory_start_address;
constexpr u32 reg_p14_id_address = 0xf003ae08;
constexpr u32 reg_p14_id_offset = reg_p14_id_address - port_memory_start_address;
constexpr u32 reg_p14_iocr0_address = 0xf003ae10;
constexpr u32 reg_p14_iocr0_offset = reg_p14_iocr0_address - port_memory_start_address;
constexpr u32 reg_p14_iocr4_address = 0xf003ae14;
constexpr u32 reg_p14_iocr4_offset = reg_p14_iocr4_address - port_memory_start_address;
constexpr u32 reg_p14_iocr8_address = 0xf003ae18;
constexpr u32 reg_p14_iocr8_offset = reg_p14_iocr8_address - port_memory_start_address;
constexpr u32 reg_p14_in_address = 0xf003ae24;
constexpr u32 reg_p14_in_offset = reg_p14_in_address - port_memory_start_address;
constexpr u32 reg_p14_pdr0_address = 0xf003ae40;
constexpr u32 reg_p14_pdr0_offset = reg_p14_pdr0_address - port_memory_start_address;
constexpr u32 reg_p14_pdr1_address = 0xf003ae44;
constexpr u32 reg_p14_pdr1_offset = reg_p14_pdr1_address - port_memory_start_address;
constexpr u32 reg_p14_esr_address = 0xf003ae50;
constexpr u32 reg_p14_esr_offset = reg_p14_esr_address - port_memory_start_address;
constexpr u32 reg_p14_pdisc_address = 0xf003ae60;
constexpr u32 reg_p14_pdisc_offset = reg_p14_pdisc_address - port_memory_start_address;
constexpr u32 reg_p14_pcsr_address = 0xf003ae64;
constexpr u32 reg_p14_pcsr_offset = reg_p14_pcsr_address - port_memory_start_address;
constexpr u32 reg_p14_omsr0_address = 0xf003ae70;
constexpr u32 reg_p14_omsr0_offset = reg_p14_omsr0_address - port_memory_start_address;
constexpr u32 reg_p14_omsr4_address = 0xf003ae74;
constexpr u32 reg_p14_omsr4_offset = reg_p14_omsr4_address - port_memory_start_address;
constexpr u32 reg_p14_omsr8_address = 0xf003ae78;
constexpr u32 reg_p14_omsr8_offset = reg_p14_omsr8_address - port_memory_start_address;
constexpr u32 reg_p14_omcr0_address = 0xf003ae80;
constexpr u32 reg_p14_omcr0_offset = reg_p14_omcr0_address - port_memory_start_address;
constexpr u32 reg_p14_omcr4_address = 0xf003ae84;
constexpr u32 reg_p14_omcr4_offset = reg_p14_omcr4_address - port_memory_start_address;
constexpr u32 reg_p14_omcr8_address = 0xf003ae88;
constexpr u32 reg_p14_omcr8_offset = reg_p14_omcr8_address - port_memory_start_address;
constexpr u32 reg_p14_omsr_address = 0xf003ae90;
constexpr u32 reg_p14_omsr_offset = reg_p14_omsr_address - port_memory_start_address;
constexpr u32 reg_p14_omcr_address = 0xf003ae94;
constexpr u32 reg_p14_omcr_offset = reg_p14_omcr_address - port_memory_start_address;
constexpr u32 reg_p14_accen1_address = 0xf003aef8;
constexpr u32 reg_p14_accen1_offset = reg_p14_accen1_address - port_memory_start_address;
constexpr u32 reg_p14_accen0_address = 0xf003aefc;
constexpr u32 reg_p14_accen0_offset = reg_p14_accen0_address - port_memory_start_address;
constexpr u32 reg_p15_out_address = 0xf003af00;
constexpr u32 reg_p15_out_offset = reg_p15_out_address - port_memory_start_address;
constexpr u32 reg_p15_omr_address = 0xf003af04;
constexpr u32 reg_p15_omr_offset = reg_p15_omr_address - port_memory_start_address;
constexpr u32 reg_p15_id_address = 0xf003af08;
constexpr u32 reg_p15_id_offset = reg_p15_id_address - port_memory_start_address;
constexpr u32 reg_p15_iocr0_address = 0xf003af10;
constexpr u32 reg_p15_iocr0_offset = reg_p15_iocr0_address - port_memory_start_address;
constexpr u32 reg_p15_iocr4_address = 0xf003af14;
constexpr u32 reg_p15_iocr4_offset = reg_p15_iocr4_address - port_memory_start_address;
constexpr u32 reg_p15_iocr8_address = 0xf003af18;
constexpr u32 reg_p15_iocr8_offset = reg_p15_iocr8_address - port_memory_start_address;
constexpr u32 reg_p15_in_address = 0xf003af24;
constexpr u32 reg_p15_in_offset = reg_p15_in_address - port_memory_start_address;
constexpr u32 reg_p15_pdr0_address = 0xf003af40;
constexpr u32 reg_p15_pdr0_offset = reg_p15_pdr0_address - port_memory_start_address;
constexpr u32 reg_p15_pdr1_address = 0xf003af44;
constexpr u32 reg_p15_pdr1_offset = reg_p15_pdr1_address - port_memory_start_address;
constexpr u32 reg_p15_esr_address = 0xf003af50;
constexpr u32 reg_p15_esr_offset = reg_p15_esr_address - port_memory_start_address;
constexpr u32 reg_p15_pdisc_address = 0xf003af60;
constexpr u32 reg_p15_pdisc_offset = reg_p15_pdisc_address - port_memory_start_address;
constexpr u32 reg_p15_pcsr_address = 0xf003af64;
constexpr u32 reg_p15_pcsr_offset = reg_p15_pcsr_address - port_memory_start_address;
constexpr u32 reg_p15_omsr0_address = 0xf003af70;
constexpr u32 reg_p15_omsr0_offset = reg_p15_omsr0_address - port_memory_start_address;
constexpr u32 reg_p15_omsr4_address = 0xf003af74;
constexpr u32 reg_p15_omsr4_offset = reg_p15_omsr4_address - port_memory_start_address;
constexpr u32 reg_p15_omsr8_address = 0xf003af78;
constexpr u32 reg_p15_omsr8_offset = reg_p15_omsr8_address - port_memory_start_address;
constexpr u32 reg_p15_omcr0_address = 0xf003af80;
constexpr u32 reg_p15_omcr0_offset = reg_p15_omcr0_address - port_memory_start_address;
constexpr u32 reg_p15_omcr4_address = 0xf003af84;
constexpr u32 reg_p15_omcr4_offset = reg_p15_omcr4_address - port_memory_start_address;
constexpr u32 reg_p15_omcr8_address = 0xf003af88;
constexpr u32 reg_p15_omcr8_offset = reg_p15_omcr8_address - port_memory_start_address;
constexpr u32 reg_p15_omsr_address = 0xf003af90;
constexpr u32 reg_p15_omsr_offset = reg_p15_omsr_address - port_memory_start_address;
constexpr u32 reg_p15_omcr_address = 0xf003af94;
constexpr u32 reg_p15_omcr_offset = reg_p15_omcr_address - port_memory_start_address;
constexpr u32 reg_p15_accen1_address = 0xf003aff8;
constexpr u32 reg_p15_accen1_offset = reg_p15_accen1_address - port_memory_start_address;
constexpr u32 reg_p15_accen0_address = 0xf003affc;
constexpr u32 reg_p15_accen0_offset = reg_p15_accen0_address - port_memory_start_address;
constexpr u32 reg_p20_out_address = 0xf003b400;
constexpr u32 reg_p20_out_offset = reg_p20_out_address - port_memory_start_address;
constexpr u32 reg_p20_omr_address = 0xf003b404;
constexpr u32 reg_p20_omr_offset = reg_p20_omr_address - port_memory_start_address;
constexpr u32 reg_p20_id_address = 0xf003b408;
constexpr u32 reg_p20_id_offset = reg_p20_id_address - port_memory_start_address;
constexpr u32 reg_p20_iocr0_address = 0xf003b410;
constexpr u32 reg_p20_iocr0_offset = reg_p20_iocr0_address - port_memory_start_address;
constexpr u32 reg_p20_iocr4_address = 0xf003b414;
constexpr u32 reg_p20_iocr4_offset = reg_p20_iocr4_address - port_memory_start_address;
constexpr u32 reg_p20_iocr8_address = 0xf003b418;
constexpr u32 reg_p20_iocr8_offset = reg_p20_iocr8_address - port_memory_start_address;
constexpr u32 reg_p20_iocr12_address = 0xf003b41c;
constexpr u32 reg_p20_iocr12_offset = reg_p20_iocr12_address - port_memory_start_address;
constexpr u32 reg_p20_in_address = 0xf003b424;
constexpr u32 reg_p20_in_offset = reg_p20_in_address - port_memory_start_address;
constexpr u32 reg_p20_pdr0_address = 0xf003b440;
constexpr u32 reg_p20_pdr0_offset = reg_p20_pdr0_address - port_memory_start_address;
constexpr u32 reg_p20_pdr1_address = 0xf003b444;
constexpr u32 reg_p20_pdr1_offset = reg_p20_pdr1_address - port_memory_start_address;
constexpr u32 reg_p20_esr_address = 0xf003b450;
constexpr u32 reg_p20_esr_offset = reg_p20_esr_address - port_memory_start_address;
constexpr u32 reg_p20_pdisc_address = 0xf003b460;
constexpr u32 reg_p20_pdisc_offset = reg_p20_pdisc_address - port_memory_start_address;
constexpr u32 reg_p20_pcsr_address = 0xf003b464;
constexpr u32 reg_p20_pcsr_offset = reg_p20_pcsr_address - port_memory_start_address;
constexpr u32 reg_p20_omsr0_address = 0xf003b470;
constexpr u32 reg_p20_omsr0_offset = reg_p20_omsr0_address - port_memory_start_address;
constexpr u32 reg_p20_omsr4_address = 0xf003b474;
constexpr u32 reg_p20_omsr4_offset = reg_p20_omsr4_address - port_memory_start_address;
constexpr u32 reg_p20_omsr8_address = 0xf003b478;
constexpr u32 reg_p20_omsr8_offset = reg_p20_omsr8_address - port_memory_start_address;
constexpr u32 reg_p20_omsr12_address = 0xf003b47c;
constexpr u32 reg_p20_omsr12_offset = reg_p20_omsr12_address - port_memory_start_address;
constexpr u32 reg_p20_omcr0_address = 0xf003b480;
constexpr u32 reg_p20_omcr0_offset = reg_p20_omcr0_address - port_memory_start_address;
constexpr u32 reg_p20_omcr4_address = 0xf003b484;
constexpr u32 reg_p20_omcr4_offset = reg_p20_omcr4_address - port_memory_start_address;
constexpr u32 reg_p20_omcr8_address = 0xf003b488;
constexpr u32 reg_p20_omcr8_offset = reg_p20_omcr8_address - port_memory_start_address;
constexpr u32 reg_p20_omcr12_address = 0xf003b48c;
constexpr u32 reg_p20_omcr12_offset = reg_p20_omcr12_address - port_memory_start_address;
constexpr u32 reg_p20_omsr_address = 0xf003b490;
constexpr u32 reg_p20_omsr_offset = reg_p20_omsr_address - port_memory_start_address;
constexpr u32 reg_p20_omcr_address = 0xf003b494;
constexpr u32 reg_p20_omcr_offset = reg_p20_omcr_address - port_memory_start_address;
constexpr u32 reg_p20_accen1_address = 0xf003b4f8;
constexpr u32 reg_p20_accen1_offset = reg_p20_accen1_address - port_memory_start_address;
constexpr u32 reg_p20_accen0_address = 0xf003b4fc;
constexpr u32 reg_p20_accen0_offset = reg_p20_accen0_address - port_memory_start_address;
constexpr u32 reg_p21_out_address = 0xf003b500;
constexpr u32 reg_p21_out_offset = reg_p21_out_address - port_memory_start_address;
constexpr u32 reg_p21_omr_address = 0xf003b504;
constexpr u32 reg_p21_omr_offset = reg_p21_omr_address - port_memory_start_address;
constexpr u32 reg_p21_id_address = 0xf003b508;
constexpr u32 reg_p21_id_offset = reg_p21_id_address - port_memory_start_address;
constexpr u32 reg_p21_iocr0_address = 0xf003b510;
constexpr u32 reg_p21_iocr0_offset = reg_p21_iocr0_address - port_memory_start_address;
constexpr u32 reg_p21_iocr4_address = 0xf003b514;
constexpr u32 reg_p21_iocr4_offset = reg_p21_iocr4_address - port_memory_start_address;
constexpr u32 reg_p21_in_address = 0xf003b524;
constexpr u32 reg_p21_in_offset = reg_p21_in_address - port_memory_start_address;
constexpr u32 reg_p21_pdr0_address = 0xf003b540;
constexpr u32 reg_p21_pdr0_offset = reg_p21_pdr0_address - port_memory_start_address;
constexpr u32 reg_p21_esr_address = 0xf003b550;
constexpr u32 reg_p21_esr_offset = reg_p21_esr_address - port_memory_start_address;
constexpr u32 reg_p21_pdisc_address = 0xf003b560;
constexpr u32 reg_p21_pdisc_offset = reg_p21_pdisc_address - port_memory_start_address;
constexpr u32 reg_p21_pcsr_address = 0xf003b564;
constexpr u32 reg_p21_pcsr_offset = reg_p21_pcsr_address - port_memory_start_address;
constexpr u32 reg_p21_omsr0_address = 0xf003b570;
constexpr u32 reg_p21_omsr0_offset = reg_p21_omsr0_address - port_memory_start_address;
constexpr u32 reg_p21_omsr4_address = 0xf003b574;
constexpr u32 reg_p21_omsr4_offset = reg_p21_omsr4_address - port_memory_start_address;
constexpr u32 reg_p21_omcr0_address = 0xf003b580;
constexpr u32 reg_p21_omcr0_offset = reg_p21_omcr0_address - port_memory_start_address;
constexpr u32 reg_p21_omcr4_address = 0xf003b584;
constexpr u32 reg_p21_omcr4_offset = reg_p21_omcr4_address - port_memory_start_address;
constexpr u32 reg_p21_omsr_address = 0xf003b590;
constexpr u32 reg_p21_omsr_offset = reg_p21_omsr_address - port_memory_start_address;
constexpr u32 reg_p21_omcr_address = 0xf003b594;
constexpr u32 reg_p21_omcr_offset = reg_p21_omcr_address - port_memory_start_address;
constexpr u32 reg_p21_accen1_address = 0xf003b5f8;
constexpr u32 reg_p21_accen1_offset = reg_p21_accen1_address - port_memory_start_address;
constexpr u32 reg_p21_accen0_address = 0xf003b5fc;
constexpr u32 reg_p21_accen0_offset = reg_p21_accen0_address - port_memory_start_address;
constexpr u32 reg_p22_out_address = 0xf003b600;
constexpr u32 reg_p22_out_offset = reg_p22_out_address - port_memory_start_address;
constexpr u32 reg_p22_omr_address = 0xf003b604;
constexpr u32 reg_p22_omr_offset = reg_p22_omr_address - port_memory_start_address;
constexpr u32 reg_p22_id_address = 0xf003b608;
constexpr u32 reg_p22_id_offset = reg_p22_id_address - port_memory_start_address;
constexpr u32 reg_p22_iocr0_address = 0xf003b610;
constexpr u32 reg_p22_iocr0_offset = reg_p22_iocr0_address - port_memory_start_address;
constexpr u32 reg_p22_iocr4_address = 0xf003b614;
constexpr u32 reg_p22_iocr4_offset = reg_p22_iocr4_address - port_memory_start_address;
constexpr u32 reg_p22_in_address = 0xf003b624;
constexpr u32 reg_p22_in_offset = reg_p22_in_address - port_memory_start_address;
constexpr u32 reg_p22_pdr0_address = 0xf003b640;
constexpr u32 reg_p22_pdr0_offset = reg_p22_pdr0_address - port_memory_start_address;
constexpr u32 reg_p22_esr_address = 0xf003b650;
constexpr u32 reg_p22_esr_offset = reg_p22_esr_address - port_memory_start_address;
constexpr u32 reg_p22_pdisc_address = 0xf003b660;
constexpr u32 reg_p22_pdisc_offset = reg_p22_pdisc_address - port_memory_start_address;
constexpr u32 reg_p22_pcsr_address = 0xf003b664;
constexpr u32 reg_p22_pcsr_offset = reg_p22_pcsr_address - port_memory_start_address;
constexpr u32 reg_p22_omsr0_address = 0xf003b670;
constexpr u32 reg_p22_omsr0_offset = reg_p22_omsr0_address - port_memory_start_address;
constexpr u32 reg_p22_omsr4_address = 0xf003b674;
constexpr u32 reg_p22_omsr4_offset = reg_p22_omsr4_address - port_memory_start_address;
constexpr u32 reg_p22_omcr0_address = 0xf003b680;
constexpr u32 reg_p22_omcr0_offset = reg_p22_omcr0_address - port_memory_start_address;
constexpr u32 reg_p22_omcr4_address = 0xf003b684;
constexpr u32 reg_p22_omcr4_offset = reg_p22_omcr4_address - port_memory_start_address;
constexpr u32 reg_p22_omsr_address = 0xf003b690;
constexpr u32 reg_p22_omsr_offset = reg_p22_omsr_address - port_memory_start_address;
constexpr u32 reg_p22_omcr_address = 0xf003b694;
constexpr u32 reg_p22_omcr_offset = reg_p22_omcr_address - port_memory_start_address;
constexpr u32 reg_p22_accen1_address = 0xf003b6f8;
constexpr u32 reg_p22_accen1_offset = reg_p22_accen1_address - port_memory_start_address;
constexpr u32 reg_p22_accen0_address = 0xf003b6fc;
constexpr u32 reg_p22_accen0_offset = reg_p22_accen0_address - port_memory_start_address;
constexpr u32 reg_p23_out_address = 0xf003b700;
constexpr u32 reg_p23_out_offset = reg_p23_out_address - port_memory_start_address;
constexpr u32 reg_p23_omr_address = 0xf003b704;
constexpr u32 reg_p23_omr_offset = reg_p23_omr_address - port_memory_start_address;
constexpr u32 reg_p23_id_address = 0xf003b708;
constexpr u32 reg_p23_id_offset = reg_p23_id_address - port_memory_start_address;
constexpr u32 reg_p23_iocr0_address = 0xf003b710;
constexpr u32 reg_p23_iocr0_offset = reg_p23_iocr0_address - port_memory_start_address;
constexpr u32 reg_p23_iocr4_address = 0xf003b714;
constexpr u32 reg_p23_iocr4_offset = reg_p23_iocr4_address - port_memory_start_address;
constexpr u32 reg_p23_in_address = 0xf003b724;
constexpr u32 reg_p23_in_offset = reg_p23_in_address - port_memory_start_address;
constexpr u32 reg_p23_pdr0_address = 0xf003b740;
constexpr u32 reg_p23_pdr0_offset = reg_p23_pdr0_address - port_memory_start_address;
constexpr u32 reg_p23_esr_address = 0xf003b750;
constexpr u32 reg_p23_esr_offset = reg_p23_esr_address - port_memory_start_address;
constexpr u32 reg_p23_pdisc_address = 0xf003b760;
constexpr u32 reg_p23_pdisc_offset = reg_p23_pdisc_address - port_memory_start_address;
constexpr u32 reg_p23_pcsr_address = 0xf003b764;
constexpr u32 reg_p23_pcsr_offset = reg_p23_pcsr_address - port_memory_start_address;
constexpr u32 reg_p23_omsr0_address = 0xf003b770;
constexpr u32 reg_p23_omsr0_offset = reg_p23_omsr0_address - port_memory_start_address;
constexpr u32 reg_p23_omsr4_address = 0xf003b774;
constexpr u32 reg_p23_omsr4_offset = reg_p23_omsr4_address - port_memory_start_address;
constexpr u32 reg_p23_omcr0_address = 0xf003b780;
constexpr u32 reg_p23_omcr0_offset = reg_p23_omcr0_address - port_memory_start_address;
constexpr u32 reg_p23_omcr4_address = 0xf003b784;
constexpr u32 reg_p23_omcr4_offset = reg_p23_omcr4_address - port_memory_start_address;
constexpr u32 reg_p23_omsr_address = 0xf003b790;
constexpr u32 reg_p23_omsr_offset = reg_p23_omsr_address - port_memory_start_address;
constexpr u32 reg_p23_omcr_address = 0xf003b794;
constexpr u32 reg_p23_omcr_offset = reg_p23_omcr_address - port_memory_start_address;
constexpr u32 reg_p23_accen1_address = 0xf003b7f8;
constexpr u32 reg_p23_accen1_offset = reg_p23_accen1_address - port_memory_start_address;
constexpr u32 reg_p23_accen0_address = 0xf003b7fc;
constexpr u32 reg_p23_accen0_offset = reg_p23_accen0_address - port_memory_start_address;
constexpr u32 reg_p32_out_address = 0xf003c000;
constexpr u32 reg_p32_out_offset = reg_p32_out_address - port_memory_start_address;
constexpr u32 reg_p32_omr_address = 0xf003c004;
constexpr u32 reg_p32_omr_offset = reg_p32_omr_address - port_memory_start_address;
constexpr u32 reg_p32_id_address = 0xf003c008;
constexpr u32 reg_p32_id_offset = reg_p32_id_address - port_memory_start_address;
constexpr u32 reg_p32_iocr0_address = 0xf003c010;
constexpr u32 reg_p32_iocr0_offset = reg_p32_iocr0_address - port_memory_start_address;
constexpr u32 reg_p32_iocr4_address = 0xf003c014;
constexpr u32 reg_p32_iocr4_offset = reg_p32_iocr4_address - port_memory_start_address;
constexpr u32 reg_p32_in_address = 0xf003c024;
constexpr u32 reg_p32_in_offset = reg_p32_in_address - port_memory_start_address;
constexpr u32 reg_p32_pdr0_address = 0xf003c040;
constexpr u32 reg_p32_pdr0_offset = reg_p32_pdr0_address - port_memory_start_address;
constexpr u32 reg_p32_esr_address = 0xf003c050;
constexpr u32 reg_p32_esr_offset = reg_p32_esr_address - port_memory_start_address;
constexpr u32 reg_p32_pdisc_address = 0xf003c060;
constexpr u32 reg_p32_pdisc_offset = reg_p32_pdisc_address - port_memory_start_address;
constexpr u32 reg_p32_pcsr_address = 0xf003c064;
constexpr u32 reg_p32_pcsr_offset = reg_p32_pcsr_address - port_memory_start_address;
constexpr u32 reg_p32_omsr0_address = 0xf003c070;
constexpr u32 reg_p32_omsr0_offset = reg_p32_omsr0_address - port_memory_start_address;
constexpr u32 reg_p32_omsr4_address = 0xf003c074;
constexpr u32 reg_p32_omsr4_offset = reg_p32_omsr4_address - port_memory_start_address;
constexpr u32 reg_p32_omcr0_address = 0xf003c080;
constexpr u32 reg_p32_omcr0_offset = reg_p32_omcr0_address - port_memory_start_address;
constexpr u32 reg_p32_omcr4_address = 0xf003c084;
constexpr u32 reg_p32_omcr4_offset = reg_p32_omcr4_address - port_memory_start_address;
constexpr u32 reg_p32_omsr_address = 0xf003c090;
constexpr u32 reg_p32_omsr_offset = reg_p32_omsr_address - port_memory_start_address;
constexpr u32 reg_p32_omcr_address = 0xf003c094;
constexpr u32 reg_p32_omcr_offset = reg_p32_omcr_address - port_memory_start_address;
constexpr u32 reg_p32_accen1_address = 0xf003c0f8;
constexpr u32 reg_p32_accen1_offset = reg_p32_accen1_address - port_memory_start_address;
constexpr u32 reg_p32_accen0_address = 0xf003c0fc;
constexpr u32 reg_p32_accen0_offset = reg_p32_accen0_address - port_memory_start_address;
constexpr u32 reg_p33_out_address = 0xf003c100;
constexpr u32 reg_p33_out_offset = reg_p33_out_address - port_memory_start_address;
constexpr u32 reg_p33_omr_address = 0xf003c104;
constexpr u32 reg_p33_omr_offset = reg_p33_omr_address - port_memory_start_address;
constexpr u32 reg_p33_id_address = 0xf003c108;
constexpr u32 reg_p33_id_offset = reg_p33_id_address - port_memory_start_address;
constexpr u32 reg_p33_iocr0_address = 0xf003c110;
constexpr u32 reg_p33_iocr0_offset = reg_p33_iocr0_address - port_memory_start_address;
constexpr u32 reg_p33_iocr4_address = 0xf003c114;
constexpr u32 reg_p33_iocr4_offset = reg_p33_iocr4_address - port_memory_start_address;
constexpr u32 reg_p33_iocr8_address = 0xf003c118;
constexpr u32 reg_p33_iocr8_offset = reg_p33_iocr8_address - port_memory_start_address;
constexpr u32 reg_p33_iocr12_address = 0xf003c11c;
constexpr u32 reg_p33_iocr12_offset = reg_p33_iocr12_address - port_memory_start_address;
constexpr u32 reg_p33_in_address = 0xf003c124;
constexpr u32 reg_p33_in_offset = reg_p33_in_address - port_memory_start_address;
constexpr u32 reg_p33_pdr0_address = 0xf003c140;
constexpr u32 reg_p33_pdr0_offset = reg_p33_pdr0_address - port_memory_start_address;
constexpr u32 reg_p33_pdr1_address = 0xf003c144;
constexpr u32 reg_p33_pdr1_offset = reg_p33_pdr1_address - port_memory_start_address;
constexpr u32 reg_p33_esr_address = 0xf003c150;
constexpr u32 reg_p33_esr_offset = reg_p33_esr_address - port_memory_start_address;
constexpr u32 reg_p33_pdisc_address = 0xf003c160;
constexpr u32 reg_p33_pdisc_offset = reg_p33_pdisc_address - port_memory_start_address;
constexpr u32 reg_p33_pcsr_address = 0xf003c164;
constexpr u32 reg_p33_pcsr_offset = reg_p33_pcsr_address - port_memory_start_address;
constexpr u32 reg_p33_omsr0_address = 0xf003c170;
constexpr u32 reg_p33_omsr0_offset = reg_p33_omsr0_address - port_memory_start_address;
constexpr u32 reg_p33_omsr4_address = 0xf003c174;
constexpr u32 reg_p33_omsr4_offset = reg_p33_omsr4_address - port_memory_start_address;
constexpr u32 reg_p33_omsr8_address = 0xf003c178;
constexpr u32 reg_p33_omsr8_offset = reg_p33_omsr8_address - port_memory_start_address;
constexpr u32 reg_p33_omsr12_address = 0xf003c17c;
constexpr u32 reg_p33_omsr12_offset = reg_p33_omsr12_address - port_memory_start_address;
constexpr u32 reg_p33_omcr0_address = 0xf003c180;
constexpr u32 reg_p33_omcr0_offset = reg_p33_omcr0_address - port_memory_start_address;
constexpr u32 reg_p33_omcr4_address = 0xf003c184;
constexpr u32 reg_p33_omcr4_offset = reg_p33_omcr4_address - port_memory_start_address;
constexpr u32 reg_p33_omcr8_address = 0xf003c188;
constexpr u32 reg_p33_omcr8_offset = reg_p33_omcr8_address - port_memory_start_address;
constexpr u32 reg_p33_omcr12_address = 0xf003c18c;
constexpr u32 reg_p33_omcr12_offset = reg_p33_omcr12_address - port_memory_start_address;
constexpr u32 reg_p33_omsr_address = 0xf003c190;
constexpr u32 reg_p33_omsr_offset = reg_p33_omsr_address - port_memory_start_address;
constexpr u32 reg_p33_omcr_address = 0xf003c194;
constexpr u32 reg_p33_omcr_offset = reg_p33_omcr_address - port_memory_start_address;
constexpr u32 reg_p33_accen1_address = 0xf003c1f8;
constexpr u32 reg_p33_accen1_offset = reg_p33_accen1_address - port_memory_start_address;
constexpr u32 reg_p33_accen0_address = 0xf003c1fc;
constexpr u32 reg_p33_accen0_offset = reg_p33_accen0_address - port_memory_start_address;
constexpr u32 reg_p34_out_address = 0xf003c200;
constexpr u32 reg_p34_out_offset = reg_p34_out_address - port_memory_start_address;
constexpr u32 reg_p34_omr_address = 0xf003c204;
constexpr u32 reg_p34_omr_offset = reg_p34_omr_address - port_memory_start_address;
constexpr u32 reg_p34_id_address = 0xf003c208;
constexpr u32 reg_p34_id_offset = reg_p34_id_address - port_memory_start_address;
constexpr u32 reg_p34_iocr0_address = 0xf003c210;
constexpr u32 reg_p34_iocr0_offset = reg_p34_iocr0_address - port_memory_start_address;
constexpr u32 reg_p34_in_address = 0xf003c224;
constexpr u32 reg_p34_in_offset = reg_p34_in_address - port_memory_start_address;
constexpr u32 reg_p34_pdr0_address = 0xf003c240;
constexpr u32 reg_p34_pdr0_offset = reg_p34_pdr0_address - port_memory_start_address;
constexpr u32 reg_p34_esr_address = 0xf003c250;
constexpr u32 reg_p34_esr_offset = reg_p34_esr_address - port_memory_start_address;
constexpr u32 reg_p34_pdisc_address = 0xf003c260;
constexpr u32 reg_p34_pdisc_offset = reg_p34_pdisc_address - port_memory_start_address;
constexpr u32 reg_p34_pcsr_address = 0xf003c264;
constexpr u32 reg_p34_pcsr_offset = reg_p34_pcsr_address - port_memory_start_address;
constexpr u32 reg_p34_omsr0_address = 0xf003c270;
constexpr u32 reg_p34_omsr0_offset = reg_p34_omsr0_address - port_memory_start_address;
constexpr u32 reg_p34_omcr0_address = 0xf003c280;
constexpr u32 reg_p34_omcr0_offset = reg_p34_omcr0_address - port_memory_start_address;
constexpr u32 reg_p34_omsr_address = 0xf003c290;
constexpr u32 reg_p34_omsr_offset = reg_p34_omsr_address - port_memory_start_address;
constexpr u32 reg_p34_omcr_address = 0xf003c294;
constexpr u32 reg_p34_omcr_offset = reg_p34_omcr_address - port_memory_start_address;
constexpr u32 reg_p34_accen1_address = 0xf003c2f8;
constexpr u32 reg_p34_accen1_offset = reg_p34_accen1_address - port_memory_start_address;
constexpr u32 reg_p34_accen0_address = 0xf003c2fc;
constexpr u32 reg_p34_accen0_offset = reg_p34_accen0_address - port_memory_start_address;
constexpr u32 reg_p40_out_address = 0xf003c800;
constexpr u32 reg_p40_out_offset = reg_p40_out_address - port_memory_start_address;
constexpr u32 reg_p40_omr_address = 0xf003c804;
constexpr u32 reg_p40_omr_offset = reg_p40_omr_address - port_memory_start_address;
constexpr u32 reg_p40_id_address = 0xf003c808;
constexpr u32 reg_p40_id_offset = reg_p40_id_address - port_memory_start_address;
constexpr u32 reg_p40_iocr0_address = 0xf003c810;
constexpr u32 reg_p40_iocr0_offset = reg_p40_iocr0_address - port_memory_start_address;
constexpr u32 reg_p40_iocr4_address = 0xf003c814;
constexpr u32 reg_p40_iocr4_offset = reg_p40_iocr4_address - port_memory_start_address;
constexpr u32 reg_p40_iocr8_address = 0xf003c818;
constexpr u32 reg_p40_iocr8_offset = reg_p40_iocr8_address - port_memory_start_address;
constexpr u32 reg_p40_in_address = 0xf003c824;
constexpr u32 reg_p40_in_offset = reg_p40_in_address - port_memory_start_address;
constexpr u32 reg_p40_pdr0_address = 0xf003c840;
constexpr u32 reg_p40_pdr0_offset = reg_p40_pdr0_address - port_memory_start_address;
constexpr u32 reg_p40_pdr1_address = 0xf003c844;
constexpr u32 reg_p40_pdr1_offset = reg_p40_pdr1_address - port_memory_start_address;
constexpr u32 reg_p40_esr_address = 0xf003c850;
constexpr u32 reg_p40_esr_offset = reg_p40_esr_address - port_memory_start_address;
constexpr u32 reg_p40_pdisc_address = 0xf003c860;
constexpr u32 reg_p40_pdisc_offset = reg_p40_pdisc_address - port_memory_start_address;
constexpr u32 reg_p40_pcsr_address = 0xf003c864;
constexpr u32 reg_p40_pcsr_offset = reg_p40_pcsr_address - port_memory_start_address;
constexpr u32 reg_p40_omsr0_address = 0xf003c870;
constexpr u32 reg_p40_omsr0_offset = reg_p40_omsr0_address - port_memory_start_address;
constexpr u32 reg_p40_omsr4_address = 0xf003c874;
constexpr u32 reg_p40_omsr4_offset = reg_p40_omsr4_address - port_memory_start_address;
constexpr u32 reg_p40_omsr8_address = 0xf003c878;
constexpr u32 reg_p40_omsr8_offset = reg_p40_omsr8_address - port_memory_start_address;
constexpr u32 reg_p40_omcr0_address = 0xf003c880;
constexpr u32 reg_p40_omcr0_offset = reg_p40_omcr0_address - port_memory_start_address;
constexpr u32 reg_p40_omcr4_address = 0xf003c884;
constexpr u32 reg_p40_omcr4_offset = reg_p40_omcr4_address - port_memory_start_address;
constexpr u32 reg_p40_omcr8_address = 0xf003c888;
constexpr u32 reg_p40_omcr8_offset = reg_p40_omcr8_address - port_memory_start_address;
constexpr u32 reg_p40_omsr_address = 0xf003c890;
constexpr u32 reg_p40_omsr_offset = reg_p40_omsr_address - port_memory_start_address;
constexpr u32 reg_p40_omcr_address = 0xf003c894;
constexpr u32 reg_p40_omcr_offset = reg_p40_omcr_address - port_memory_start_address;
constexpr u32 reg_p40_accen1_address = 0xf003c8f8;
constexpr u32 reg_p40_accen1_offset = reg_p40_accen1_address - port_memory_start_address;
constexpr u32 reg_p40_accen0_address = 0xf003c8fc;
constexpr u32 reg_p40_accen0_offset = reg_p40_accen0_address - port_memory_start_address;

} // anonymous namespace


Tricore::Port::Port()
    : m_p00_out(p00_out_reset_value)
    , m_p00_omr(p00_omr_reset_value)
    , m_p00_id(p00_id_reset_value)
    , m_p00_iocr0(p00_iocr0_reset_value)
    , m_p00_iocr4(p00_iocr4_reset_value)
    , m_p00_iocr8(p00_iocr8_reset_value)
    , m_p00_iocr12(p00_iocr12_reset_value)
    , m_p00_in(p00_in_reset_value)
    , m_p00_pdr0(p00_pdr0_reset_value)
    , m_p00_pdr1(p00_pdr1_reset_value)
    , m_p00_esr(p00_esr_reset_value)
    , m_p00_pdisc(p00_pdisc_reset_value)
    , m_p00_pcsr(p00_pcsr_reset_value)
    , m_p00_omsr0(p00_omsr0_reset_value)
    , m_p00_omsr4(p00_omsr4_reset_value)
    , m_p00_omsr8(p00_omsr8_reset_value)
    , m_p00_omsr12(p00_omsr12_reset_value)
    , m_p00_omcr0(p00_omcr0_reset_value)
    , m_p00_omcr4(p00_omcr4_reset_value)
    , m_p00_omcr8(p00_omcr8_reset_value)
    , m_p00_omcr12(p00_omcr12_reset_value)
    , m_p00_omsr(p00_omsr_reset_value)
    , m_p00_omcr(p00_omcr_reset_value)
    , m_p00_accen1(p00_accen1_reset_value)
    , m_p00_accen0(p00_accen0_reset_value)
    , m_p02_out(p02_out_reset_value)
    , m_p02_omr(p02_omr_reset_value)
    , m_p02_id(p02_id_reset_value)
    , m_p02_iocr0(p02_iocr0_reset_value)
    , m_p02_iocr4(p02_iocr4_reset_value)
    , m_p02_iocr8(p02_iocr8_reset_value)
    , m_p02_in(p02_in_reset_value)
    , m_p02_pdr0(p02_pdr0_reset_value)
    , m_p02_pdr1(p02_pdr1_reset_value)
    , m_p02_esr(p02_esr_reset_value)
    , m_p02_pdisc(p02_pdisc_reset_value)
    , m_p02_pcsr(p02_pcsr_reset_value)
    , m_p02_omsr0(p02_omsr0_reset_value)
    , m_p02_omsr4(p02_omsr4_reset_value)
    , m_p02_omsr8(p02_omsr8_reset_value)
    , m_p02_omcr0(p02_omcr0_reset_value)
    , m_p02_omcr4(p02_omcr4_reset_value)
    , m_p02_omcr8(p02_omcr8_reset_value)
    , m_p02_omsr(p02_omsr_reset_value)
    , m_p02_omcr(p02_omcr_reset_value)
    , m_p02_accen1(p02_accen1_reset_value)
    , m_p02_accen0(p02_accen0_reset_value)
    , m_p10_out(p10_out_reset_value)
    , m_p10_omr(p10_omr_reset_value)
    , m_p10_id(p10_id_reset_value)
    , m_p10_iocr0(p10_iocr0_reset_value)
    , m_p10_iocr4(p10_iocr4_reset_value)
    , m_p10_iocr8(p10_iocr8_reset_value)
    , m_p10_in(p10_in_reset_value)
    , m_p10_pdr0(p10_pdr0_reset_value)
    , m_p10_pdr1(p10_pdr1_reset_value)
    , m_p10_esr(p10_esr_reset_value)
    , m_p10_pdisc(p10_pdisc_reset_value)
    , m_p10_pcsr(p10_pcsr_reset_value)
    , m_p10_omsr0(p10_omsr0_reset_value)
    , m_p10_omsr4(p10_omsr4_reset_value)
    , m_p10_omsr8(p10_omsr8_reset_value)
    , m_p10_omcr0(p10_omcr0_reset_value)
    , m_p10_omcr4(p10_omcr4_reset_value)
    , m_p10_omcr8(p10_omcr8_reset_value)
    , m_p10_omsr(p10_omsr_reset_value)
    , m_p10_omcr(p10_omcr_reset_value)
    , m_p10_accen1(p10_accen1_reset_value)
    , m_p10_accen0(p10_accen0_reset_value)
    , m_p11_out(p11_out_reset_value)
    , m_p11_omr(p11_omr_reset_value)
    , m_p11_id(p11_id_reset_value)
    , m_p11_iocr0(p11_iocr0_reset_value)
    , m_p11_iocr4(p11_iocr4_reset_value)
    , m_p11_iocr8(p11_iocr8_reset_value)
    , m_p11_iocr12(p11_iocr12_reset_value)
    , m_p11_in(p11_in_reset_value)
    , m_p11_pdr0(p11_pdr0_reset_value)
    , m_p11_pdr1(p11_pdr1_reset_value)
    , m_p11_esr(p11_esr_reset_value)
    , m_p11_pdisc(p11_pdisc_reset_value)
    , m_p11_pcsr(p11_pcsr_reset_value)
    , m_p11_omsr0(p11_omsr0_reset_value)
    , m_p11_omsr4(p11_omsr4_reset_value)
    , m_p11_omsr8(p11_omsr8_reset_value)
    , m_p11_omsr12(p11_omsr12_reset_value)
    , m_p11_omcr0(p11_omcr0_reset_value)
    , m_p11_omcr4(p11_omcr4_reset_value)
    , m_p11_omcr8(p11_omcr8_reset_value)
    , m_p11_omcr12(p11_omcr12_reset_value)
    , m_p11_omsr(p11_omsr_reset_value)
    , m_p11_omcr(p11_omcr_reset_value)
    , m_p11_accen1(p11_accen1_reset_value)
    , m_p11_accen0(p11_accen0_reset_value)
    , m_p13_out(p13_out_reset_value)
    , m_p13_omr(p13_omr_reset_value)
    , m_p13_id(p13_id_reset_value)
    , m_p13_iocr0(p13_iocr0_reset_value)
    , m_p13_in(p13_in_reset_value)
    , m_p13_pdr0(p13_pdr0_reset_value)
    , m_p13_esr(p13_esr_reset_value)
    , m_p13_pdisc(p13_pdisc_reset_value)
    , m_p13_pcsr(p13_pcsr_reset_value)
    , m_p13_omsr0(p13_omsr0_reset_value)
    , m_p13_omcr0(p13_omcr0_reset_value)
    , m_p13_omsr(p13_omsr_reset_value)
    , m_p13_omcr(p13_omcr_reset_value)
    , m_p13_accen1(p13_accen1_reset_value)
    , m_p13_accen0(p13_accen0_reset_value)
    , m_p14_out(p14_out_reset_value)
    , m_p14_omr(p14_omr_reset_value)
    , m_p14_id(p14_id_reset_value)
    , m_p14_iocr0(p14_iocr0_reset_value)
    , m_p14_iocr4(p14_iocr4_reset_value)
    , m_p14_iocr8(p14_iocr8_reset_value)
    , m_p14_in(p14_in_reset_value)
    , m_p14_pdr0(p14_pdr0_reset_value)
    , m_p14_pdr1(p14_pdr1_reset_value)
    , m_p14_esr(p14_esr_reset_value)
    , m_p14_pdisc(p14_pdisc_reset_value)
    , m_p14_pcsr(p14_pcsr_reset_value)
    , m_p14_omsr0(p14_omsr0_reset_value)
    , m_p14_omsr4(p14_omsr4_reset_value)
    , m_p14_omsr8(p14_omsr8_reset_value)
    , m_p14_omcr0(p14_omcr0_reset_value)
    , m_p14_omcr4(p14_omcr4_reset_value)
    , m_p14_omcr8(p14_omcr8_reset_value)
    , m_p14_omsr(p14_omsr_reset_value)
    , m_p14_omcr(p14_omcr_reset_value)
    , m_p14_accen1(p14_accen1_reset_value)
    , m_p14_accen0(p14_accen0_reset_value)
    , m_p15_out(p15_out_reset_value)
    , m_p15_omr(p15_omr_reset_value)
    , m_p15_id(p15_id_reset_value)
    , m_p15_iocr0(p15_iocr0_reset_value)
    , m_p15_iocr4(p15_iocr4_reset_value)
    , m_p15_iocr8(p15_iocr8_reset_value)
    , m_p15_in(p15_in_reset_value)
    , m_p15_pdr0(p15_pdr0_reset_value)
    , m_p15_pdr1(p15_pdr1_reset_value)
    , m_p15_esr(p15_esr_reset_value)
    , m_p15_pdisc(p15_pdisc_reset_value)
    , m_p15_pcsr(p15_pcsr_reset_value)
    , m_p15_omsr0(p15_omsr0_reset_value)
    , m_p15_omsr4(p15_omsr4_reset_value)
    , m_p15_omsr8(p15_omsr8_reset_value)
    , m_p15_omcr0(p15_omcr0_reset_value)
    , m_p15_omcr4(p15_omcr4_reset_value)
    , m_p15_omcr8(p15_omcr8_reset_value)
    , m_p15_omsr(p15_omsr_reset_value)
    , m_p15_omcr(p15_omcr_reset_value)
    , m_p15_accen1(p15_accen1_reset_value)
    , m_p15_accen0(p15_accen0_reset_value)
    , m_p20_out(p20_out_reset_value)
    , m_p20_omr(p20_omr_reset_value)
    , m_p20_id(p20_id_reset_value)
    , m_p20_iocr0(p20_iocr0_reset_value)
    , m_p20_iocr4(p20_iocr4_reset_value)
    , m_p20_iocr8(p20_iocr8_reset_value)
    , m_p20_iocr12(p20_iocr12_reset_value)
    , m_p20_in(p20_in_reset_value)
    , m_p20_pdr0(p20_pdr0_reset_value)
    , m_p20_pdr1(p20_pdr1_reset_value)
    , m_p20_esr(p20_esr_reset_value)
    , m_p20_pdisc(p20_pdisc_reset_value)
    , m_p20_pcsr(p20_pcsr_reset_value)
    , m_p20_omsr0(p20_omsr0_reset_value)
    , m_p20_omsr4(p20_omsr4_reset_value)
    , m_p20_omsr8(p20_omsr8_reset_value)
    , m_p20_omsr12(p20_omsr12_reset_value)
    , m_p20_omcr0(p20_omcr0_reset_value)
    , m_p20_omcr4(p20_omcr4_reset_value)
    , m_p20_omcr8(p20_omcr8_reset_value)
    , m_p20_omcr12(p20_omcr12_reset_value)
    , m_p20_omsr(p20_omsr_reset_value)
    , m_p20_omcr(p20_omcr_reset_value)
    , m_p20_accen1(p20_accen1_reset_value)
    , m_p20_accen0(p20_accen0_reset_value)
    , m_p21_out(p21_out_reset_value)
    , m_p21_omr(p21_omr_reset_value)
    , m_p21_id(p21_id_reset_value)
    , m_p21_iocr0(p21_iocr0_reset_value)
    , m_p21_iocr4(p21_iocr4_reset_value)
    , m_p21_in(p21_in_reset_value)
    , m_p21_pdr0(p21_pdr0_reset_value)
    , m_p21_esr(p21_esr_reset_value)
    , m_p21_pdisc(p21_pdisc_reset_value)
    , m_p21_pcsr(p21_pcsr_reset_value)
    , m_p21_omsr0(p21_omsr0_reset_value)
    , m_p21_omsr4(p21_omsr4_reset_value)
    , m_p21_omcr0(p21_omcr0_reset_value)
    , m_p21_omcr4(p21_omcr4_reset_value)
    , m_p21_omsr(p21_omsr_reset_value)
    , m_p21_omcr(p21_omcr_reset_value)
    , m_p21_accen1(p21_accen1_reset_value)
    , m_p21_accen0(p21_accen0_reset_value)
    , m_p22_out(p22_out_reset_value)
    , m_p22_omr(p22_omr_reset_value)
    , m_p22_id(p22_id_reset_value)
    , m_p22_iocr0(p22_iocr0_reset_value)
    , m_p22_iocr4(p22_iocr4_reset_value)
    , m_p22_in(p22_in_reset_value)
    , m_p22_pdr0(p22_pdr0_reset_value)
    , m_p22_esr(p22_esr_reset_value)
    , m_p22_pdisc(p22_pdisc_reset_value)
    , m_p22_pcsr(p22_pcsr_reset_value)
    , m_p22_omsr0(p22_omsr0_reset_value)
    , m_p22_omsr4(p22_omsr4_reset_value)
    , m_p22_omcr0(p22_omcr0_reset_value)
    , m_p22_omcr4(p22_omcr4_reset_value)
    , m_p22_omsr(p22_omsr_reset_value)
    , m_p22_omcr(p22_omcr_reset_value)
    , m_p22_accen1(p22_accen1_reset_value)
    , m_p22_accen0(p22_accen0_reset_value)
    , m_p23_out(p23_out_reset_value)
    , m_p23_omr(p23_omr_reset_value)
    , m_p23_id(p23_id_reset_value)
    , m_p23_iocr0(p23_iocr0_reset_value)
    , m_p23_iocr4(p23_iocr4_reset_value)
    , m_p23_in(p23_in_reset_value)
    , m_p23_pdr0(p23_pdr0_reset_value)
    , m_p23_esr(p23_esr_reset_value)
    , m_p23_pdisc(p23_pdisc_reset_value)
    , m_p23_pcsr(p23_pcsr_reset_value)
    , m_p23_omsr0(p23_omsr0_reset_value)
    , m_p23_omsr4(p23_omsr4_reset_value)
    , m_p23_omcr0(p23_omcr0_reset_value)
    , m_p23_omcr4(p23_omcr4_reset_value)
    , m_p23_omsr(p23_omsr_reset_value)
    , m_p23_omcr(p23_omcr_reset_value)
    , m_p23_accen1(p23_accen1_reset_value)
    , m_p23_accen0(p23_accen0_reset_value)
    , m_p32_out(p32_out_reset_value)
    , m_p32_omr(p32_omr_reset_value)
    , m_p32_id(p32_id_reset_value)
    , m_p32_iocr0(p32_iocr0_reset_value)
    , m_p32_iocr4(p32_iocr4_reset_value)
    , m_p32_in(p32_in_reset_value)
    , m_p32_pdr0(p32_pdr0_reset_value)
    , m_p32_esr(p32_esr_reset_value)
    , m_p32_pdisc(p32_pdisc_reset_value)
    , m_p32_pcsr(p32_pcsr_reset_value)
    , m_p32_omsr0(p32_omsr0_reset_value)
    , m_p32_omsr4(p32_omsr4_reset_value)
    , m_p32_omcr0(p32_omcr0_reset_value)
    , m_p32_omcr4(p32_omcr4_reset_value)
    , m_p32_omsr(p32_omsr_reset_value)
    , m_p32_omcr(p32_omcr_reset_value)
    , m_p32_accen1(p32_accen1_reset_value)
    , m_p32_accen0(p32_accen0_reset_value)
    , m_p33_out(p33_out_reset_value)
    , m_p33_omr(p33_omr_reset_value)
    , m_p33_id(p33_id_reset_value)
    , m_p33_iocr0(p33_iocr0_reset_value)
    , m_p33_iocr4(p33_iocr4_reset_value)
    , m_p33_iocr8(p33_iocr8_reset_value)
    , m_p33_iocr12(p33_iocr12_reset_value)
    , m_p33_in(p33_in_reset_value)
    , m_p33_pdr0(p33_pdr0_reset_value)
    , m_p33_pdr1(p33_pdr1_reset_value)
    , m_p33_esr(p33_esr_reset_value)
    , m_p33_pdisc(p33_pdisc_reset_value)
    , m_p33_pcsr(p33_pcsr_reset_value)
    , m_p33_omsr0(p33_omsr0_reset_value)
    , m_p33_omsr4(p33_omsr4_reset_value)
    , m_p33_omsr8(p33_omsr8_reset_value)
    , m_p33_omsr12(p33_omsr12_reset_value)
    , m_p33_omcr0(p33_omcr0_reset_value)
    , m_p33_omcr4(p33_omcr4_reset_value)
    , m_p33_omcr8(p33_omcr8_reset_value)
    , m_p33_omcr12(p33_omcr12_reset_value)
    , m_p33_omsr(p33_omsr_reset_value)
    , m_p33_omcr(p33_omcr_reset_value)
    , m_p33_accen1(p33_accen1_reset_value)
    , m_p33_accen0(p33_accen0_reset_value)
    , m_p34_out(p34_out_reset_value)
    , m_p34_omr(p34_omr_reset_value)
    , m_p34_id(p34_id_reset_value)
    , m_p34_iocr0(p34_iocr0_reset_value)
    , m_p34_in(p34_in_reset_value)
    , m_p34_pdr0(p34_pdr0_reset_value)
    , m_p34_esr(p34_esr_reset_value)
    , m_p34_pdisc(p34_pdisc_reset_value)
    , m_p34_pcsr(p34_pcsr_reset_value)
    , m_p34_omsr0(p34_omsr0_reset_value)
    , m_p34_omcr0(p34_omcr0_reset_value)
    , m_p34_omsr(p34_omsr_reset_value)
    , m_p34_omcr(p34_omcr_reset_value)
    , m_p34_accen1(p34_accen1_reset_value)
    , m_p34_accen0(p34_accen0_reset_value)
    , m_p40_out(p40_out_reset_value)
    , m_p40_omr(p40_omr_reset_value)
    , m_p40_id(p40_id_reset_value)
    , m_p40_iocr0(p40_iocr0_reset_value)
    , m_p40_iocr4(p40_iocr4_reset_value)
    , m_p40_iocr8(p40_iocr8_reset_value)
    , m_p40_in(p40_in_reset_value)
    , m_p40_pdr0(p40_pdr0_reset_value)
    , m_p40_pdr1(p40_pdr1_reset_value)
    , m_p40_esr(p40_esr_reset_value)
    , m_p40_pdisc(p40_pdisc_reset_value)
    , m_p40_pcsr(p40_pcsr_reset_value)
    , m_p40_omsr0(p40_omsr0_reset_value)
    , m_p40_omsr4(p40_omsr4_reset_value)
    , m_p40_omsr8(p40_omsr8_reset_value)
    , m_p40_omcr0(p40_omcr0_reset_value)
    , m_p40_omcr4(p40_omcr4_reset_value)
    , m_p40_omcr8(p40_omcr8_reset_value)
    , m_p40_omsr(p40_omsr_reset_value)
    , m_p40_omcr(p40_omcr_reset_value)
    , m_p40_accen1(p40_accen1_reset_value)
    , m_p40_accen0(p40_accen0_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Port::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - port_memory_start_address;
    switch (offset) {
    case reg_p00_out_offset: {
            spdlog::debug("PORT: accessing PORT.P00_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P00_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_id_offset: {
            spdlog::debug("PORT: accessing PORT.P00_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P00_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P00_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_iocr8_offset: {
            spdlog::debug("PORT: accessing PORT.P00_IOCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_iocr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_iocr12_offset: {
            spdlog::debug("PORT: accessing PORT.P00_IOCR12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_iocr12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_in_offset: {
            spdlog::debug("PORT: accessing PORT.P00_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P00_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_pdr1_offset: {
            spdlog::debug("PORT: accessing PORT.P00_PDR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_pdr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P00_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P00_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P00_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P00_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P00_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_omsr8_offset: {
            spdlog::debug("PORT: accessing PORT.P00_OMSR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_omsr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_omsr12_offset: {
            spdlog::debug("PORT: accessing PORT.P00_OMSR12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_omsr12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P00_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P00_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_omcr8_offset: {
            spdlog::debug("PORT: accessing PORT.P00_OMCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_omcr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_omcr12_offset: {
            spdlog::debug("PORT: accessing PORT.P00_OMCR12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_omcr12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P00_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P00_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P00_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p00_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P00_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p00_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_out_offset: {
            spdlog::debug("PORT: accessing PORT.P02_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P02_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_id_offset: {
            spdlog::debug("PORT: accessing PORT.P02_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P02_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P02_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_iocr8_offset: {
            spdlog::debug("PORT: accessing PORT.P02_IOCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_iocr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_in_offset: {
            spdlog::debug("PORT: accessing PORT.P02_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P02_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_pdr1_offset: {
            spdlog::debug("PORT: accessing PORT.P02_PDR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_pdr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P02_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P02_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P02_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P02_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P02_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_omsr8_offset: {
            spdlog::debug("PORT: accessing PORT.P02_OMSR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_omsr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P02_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P02_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_omcr8_offset: {
            spdlog::debug("PORT: accessing PORT.P02_OMCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_omcr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P02_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P02_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P02_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p02_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P02_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p02_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_out_offset: {
            spdlog::debug("PORT: accessing PORT.P10_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P10_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_id_offset: {
            spdlog::debug("PORT: accessing PORT.P10_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P10_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P10_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_iocr8_offset: {
            spdlog::debug("PORT: accessing PORT.P10_IOCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_iocr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_in_offset: {
            spdlog::debug("PORT: accessing PORT.P10_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P10_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_pdr1_offset: {
            spdlog::debug("PORT: accessing PORT.P10_PDR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_pdr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P10_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P10_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P10_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P10_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P10_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_omsr8_offset: {
            spdlog::debug("PORT: accessing PORT.P10_OMSR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_omsr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P10_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P10_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_omcr8_offset: {
            spdlog::debug("PORT: accessing PORT.P10_OMCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_omcr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P10_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P10_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P10_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p10_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P10_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p10_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_out_offset: {
            spdlog::debug("PORT: accessing PORT.P11_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P11_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_id_offset: {
            spdlog::debug("PORT: accessing PORT.P11_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P11_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P11_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_iocr8_offset: {
            spdlog::debug("PORT: accessing PORT.P11_IOCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_iocr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_iocr12_offset: {
            spdlog::debug("PORT: accessing PORT.P11_IOCR12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_iocr12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_in_offset: {
            spdlog::debug("PORT: accessing PORT.P11_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P11_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_pdr1_offset: {
            spdlog::debug("PORT: accessing PORT.P11_PDR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_pdr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P11_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P11_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P11_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P11_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P11_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_omsr8_offset: {
            spdlog::debug("PORT: accessing PORT.P11_OMSR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_omsr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_omsr12_offset: {
            spdlog::debug("PORT: accessing PORT.P11_OMSR12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_omsr12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P11_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P11_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_omcr8_offset: {
            spdlog::debug("PORT: accessing PORT.P11_OMCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_omcr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_omcr12_offset: {
            spdlog::debug("PORT: accessing PORT.P11_OMCR12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_omcr12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P11_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P11_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P11_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p11_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P11_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p11_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_out_offset: {
            spdlog::debug("PORT: accessing PORT.P13_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P13_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_id_offset: {
            spdlog::debug("PORT: accessing PORT.P13_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P13_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_in_offset: {
            spdlog::debug("PORT: accessing PORT.P13_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P13_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P13_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P13_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P13_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P13_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P13_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P13_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P13_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P13_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p13_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P13_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p13_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_out_offset: {
            spdlog::debug("PORT: accessing PORT.P14_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P14_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_id_offset: {
            spdlog::debug("PORT: accessing PORT.P14_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P14_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P14_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_iocr8_offset: {
            spdlog::debug("PORT: accessing PORT.P14_IOCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_iocr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_in_offset: {
            spdlog::debug("PORT: accessing PORT.P14_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P14_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_pdr1_offset: {
            spdlog::debug("PORT: accessing PORT.P14_PDR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_pdr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P14_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P14_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P14_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P14_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P14_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_omsr8_offset: {
            spdlog::debug("PORT: accessing PORT.P14_OMSR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_omsr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P14_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P14_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_omcr8_offset: {
            spdlog::debug("PORT: accessing PORT.P14_OMCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_omcr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P14_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P14_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P14_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p14_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P14_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p14_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_out_offset: {
            spdlog::debug("PORT: accessing PORT.P15_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P15_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_id_offset: {
            spdlog::debug("PORT: accessing PORT.P15_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P15_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P15_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_iocr8_offset: {
            spdlog::debug("PORT: accessing PORT.P15_IOCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_iocr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_in_offset: {
            spdlog::debug("PORT: accessing PORT.P15_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P15_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_pdr1_offset: {
            spdlog::debug("PORT: accessing PORT.P15_PDR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_pdr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P15_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P15_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P15_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P15_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P15_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_omsr8_offset: {
            spdlog::debug("PORT: accessing PORT.P15_OMSR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_omsr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P15_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P15_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_omcr8_offset: {
            spdlog::debug("PORT: accessing PORT.P15_OMCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_omcr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P15_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P15_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P15_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p15_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P15_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p15_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_out_offset: {
            spdlog::debug("PORT: accessing PORT.P20_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P20_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_id_offset: {
            spdlog::debug("PORT: accessing PORT.P20_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P20_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P20_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_iocr8_offset: {
            spdlog::debug("PORT: accessing PORT.P20_IOCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_iocr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_iocr12_offset: {
            spdlog::debug("PORT: accessing PORT.P20_IOCR12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_iocr12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_in_offset: {
            spdlog::debug("PORT: accessing PORT.P20_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P20_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_pdr1_offset: {
            spdlog::debug("PORT: accessing PORT.P20_PDR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_pdr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P20_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P20_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P20_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P20_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P20_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_omsr8_offset: {
            spdlog::debug("PORT: accessing PORT.P20_OMSR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_omsr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_omsr12_offset: {
            spdlog::debug("PORT: accessing PORT.P20_OMSR12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_omsr12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P20_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P20_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_omcr8_offset: {
            spdlog::debug("PORT: accessing PORT.P20_OMCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_omcr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_omcr12_offset: {
            spdlog::debug("PORT: accessing PORT.P20_OMCR12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_omcr12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P20_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P20_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P20_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p20_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P20_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p20_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_out_offset: {
            spdlog::debug("PORT: accessing PORT.P21_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P21_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_id_offset: {
            spdlog::debug("PORT: accessing PORT.P21_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P21_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P21_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_in_offset: {
            spdlog::debug("PORT: accessing PORT.P21_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P21_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P21_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P21_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P21_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P21_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P21_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P21_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P21_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P21_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P21_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P21_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p21_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P21_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p21_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_out_offset: {
            spdlog::debug("PORT: accessing PORT.P22_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P22_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_id_offset: {
            spdlog::debug("PORT: accessing PORT.P22_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P22_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P22_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_in_offset: {
            spdlog::debug("PORT: accessing PORT.P22_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P22_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P22_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P22_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P22_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P22_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P22_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P22_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P22_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P22_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P22_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P22_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p22_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P22_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p22_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_out_offset: {
            spdlog::debug("PORT: accessing PORT.P23_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P23_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_id_offset: {
            spdlog::debug("PORT: accessing PORT.P23_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P23_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P23_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_in_offset: {
            spdlog::debug("PORT: accessing PORT.P23_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P23_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P23_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P23_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P23_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P23_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P23_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P23_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P23_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P23_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P23_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P23_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p23_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P23_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p23_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_out_offset: {
            spdlog::debug("PORT: accessing PORT.P32_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P32_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_id_offset: {
            spdlog::debug("PORT: accessing PORT.P32_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P32_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P32_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_in_offset: {
            spdlog::debug("PORT: accessing PORT.P32_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P32_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P32_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P32_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P32_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P32_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P32_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P32_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P32_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P32_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P32_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P32_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p32_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P32_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p32_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_out_offset: {
            spdlog::debug("PORT: accessing PORT.P33_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P33_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_id_offset: {
            spdlog::debug("PORT: accessing PORT.P33_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P33_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P33_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_iocr8_offset: {
            spdlog::debug("PORT: accessing PORT.P33_IOCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_iocr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_iocr12_offset: {
            spdlog::debug("PORT: accessing PORT.P33_IOCR12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_iocr12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_in_offset: {
            spdlog::debug("PORT: accessing PORT.P33_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P33_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_pdr1_offset: {
            spdlog::debug("PORT: accessing PORT.P33_PDR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_pdr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P33_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P33_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P33_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P33_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P33_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_omsr8_offset: {
            spdlog::debug("PORT: accessing PORT.P33_OMSR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_omsr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_omsr12_offset: {
            spdlog::debug("PORT: accessing PORT.P33_OMSR12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_omsr12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P33_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P33_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_omcr8_offset: {
            spdlog::debug("PORT: accessing PORT.P33_OMCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_omcr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_omcr12_offset: {
            spdlog::debug("PORT: accessing PORT.P33_OMCR12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_omcr12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P33_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P33_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P33_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p33_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P33_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p33_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_out_offset: {
            spdlog::debug("PORT: accessing PORT.P34_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P34_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_id_offset: {
            spdlog::debug("PORT: accessing PORT.P34_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P34_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_in_offset: {
            spdlog::debug("PORT: accessing PORT.P34_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P34_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P34_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P34_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P34_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P34_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P34_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P34_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P34_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P34_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p34_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P34_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p34_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_out_offset: {
            spdlog::debug("PORT: accessing PORT.P40_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_omr_offset: {
            spdlog::debug("PORT: accessing PORT.P40_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_id_offset: {
            spdlog::debug("PORT: accessing PORT.P40_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_iocr0_offset: {
            spdlog::debug("PORT: accessing PORT.P40_IOCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_iocr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_iocr4_offset: {
            spdlog::debug("PORT: accessing PORT.P40_IOCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_iocr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_iocr8_offset: {
            spdlog::debug("PORT: accessing PORT.P40_IOCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_iocr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_in_offset: {
            spdlog::debug("PORT: accessing PORT.P40_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_pdr0_offset: {
            spdlog::debug("PORT: accessing PORT.P40_PDR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_pdr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_pdr1_offset: {
            spdlog::debug("PORT: accessing PORT.P40_PDR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_pdr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_esr_offset: {
            spdlog::debug("PORT: accessing PORT.P40_ESR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_esr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_pdisc_offset: {
            spdlog::debug("PORT: accessing PORT.P40_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_pcsr_offset: {
            spdlog::debug("PORT: accessing PORT.P40_PCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_pcsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_omsr0_offset: {
            spdlog::debug("PORT: accessing PORT.P40_OMSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_omsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_omsr4_offset: {
            spdlog::debug("PORT: accessing PORT.P40_OMSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_omsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_omsr8_offset: {
            spdlog::debug("PORT: accessing PORT.P40_OMSR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_omsr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_omcr0_offset: {
            spdlog::debug("PORT: accessing PORT.P40_OMCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_omcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_omcr4_offset: {
            spdlog::debug("PORT: accessing PORT.P40_OMCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_omcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_omcr8_offset: {
            spdlog::debug("PORT: accessing PORT.P40_OMCR8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_omcr8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_omsr_offset: {
            spdlog::debug("PORT: accessing PORT.P40_OMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_omsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_omcr_offset: {
            spdlog::debug("PORT: accessing PORT.P40_OMCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_omcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_accen1_offset: {
            spdlog::debug("PORT: accessing PORT.P40_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_p40_accen0_offset: {
            spdlog::debug("PORT: accessing PORT.P40_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_p40_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Port peripheral", address)};
        break;
    }
}

void Tricore::Port::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - port_memory_start_address;
    switch (offset) {
    case reg_p00_out_offset: {
        spdlog::debug("PORT: accessing PORT.P00_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_out));
    } break;
    case reg_p00_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P00_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_omr));
    } break;
    case reg_p00_id_offset: {
        spdlog::debug("PORT: accessing PORT.P00_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_id));
    } break;
    case reg_p00_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P00_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_iocr0));
    } break;
    case reg_p00_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P00_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_iocr4));
    } break;
    case reg_p00_iocr8_offset: {
        spdlog::debug("PORT: accessing PORT.P00_IOCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_iocr8));
    } break;
    case reg_p00_iocr12_offset: {
        spdlog::debug("PORT: accessing PORT.P00_IOCR12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_iocr12));
    } break;
    case reg_p00_in_offset: {
        spdlog::debug("PORT: accessing PORT.P00_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_in));
    } break;
    case reg_p00_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P00_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_pdr0));
    } break;
    case reg_p00_pdr1_offset: {
        spdlog::debug("PORT: accessing PORT.P00_PDR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_pdr1));
    } break;
    case reg_p00_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P00_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_esr));
    } break;
    case reg_p00_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P00_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_pdisc));
    } break;
    case reg_p00_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P00_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_pcsr));
    } break;
    case reg_p00_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P00_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_omsr0));
    } break;
    case reg_p00_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P00_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_omsr4));
    } break;
    case reg_p00_omsr8_offset: {
        spdlog::debug("PORT: accessing PORT.P00_OMSR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_omsr8));
    } break;
    case reg_p00_omsr12_offset: {
        spdlog::debug("PORT: accessing PORT.P00_OMSR12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_omsr12));
    } break;
    case reg_p00_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P00_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_omcr0));
    } break;
    case reg_p00_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P00_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_omcr4));
    } break;
    case reg_p00_omcr8_offset: {
        spdlog::debug("PORT: accessing PORT.P00_OMCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_omcr8));
    } break;
    case reg_p00_omcr12_offset: {
        spdlog::debug("PORT: accessing PORT.P00_OMCR12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_omcr12));
    } break;
    case reg_p00_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P00_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_omsr));
    } break;
    case reg_p00_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P00_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_omcr));
    } break;
    case reg_p00_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P00_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_accen1));
    } break;
    case reg_p00_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P00_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p00_accen0));
    } break;
    case reg_p02_out_offset: {
        spdlog::debug("PORT: accessing PORT.P02_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_out));
    } break;
    case reg_p02_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P02_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_omr));
    } break;
    case reg_p02_id_offset: {
        spdlog::debug("PORT: accessing PORT.P02_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_id));
    } break;
    case reg_p02_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P02_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_iocr0));
    } break;
    case reg_p02_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P02_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_iocr4));
    } break;
    case reg_p02_iocr8_offset: {
        spdlog::debug("PORT: accessing PORT.P02_IOCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_iocr8));
    } break;
    case reg_p02_in_offset: {
        spdlog::debug("PORT: accessing PORT.P02_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_in));
    } break;
    case reg_p02_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P02_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_pdr0));
    } break;
    case reg_p02_pdr1_offset: {
        spdlog::debug("PORT: accessing PORT.P02_PDR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_pdr1));
    } break;
    case reg_p02_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P02_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_esr));
    } break;
    case reg_p02_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P02_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_pdisc));
    } break;
    case reg_p02_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P02_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_pcsr));
    } break;
    case reg_p02_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P02_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_omsr0));
    } break;
    case reg_p02_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P02_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_omsr4));
    } break;
    case reg_p02_omsr8_offset: {
        spdlog::debug("PORT: accessing PORT.P02_OMSR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_omsr8));
    } break;
    case reg_p02_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P02_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_omcr0));
    } break;
    case reg_p02_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P02_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_omcr4));
    } break;
    case reg_p02_omcr8_offset: {
        spdlog::debug("PORT: accessing PORT.P02_OMCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_omcr8));
    } break;
    case reg_p02_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P02_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_omsr));
    } break;
    case reg_p02_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P02_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_omcr));
    } break;
    case reg_p02_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P02_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_accen1));
    } break;
    case reg_p02_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P02_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p02_accen0));
    } break;
    case reg_p10_out_offset: {
        spdlog::debug("PORT: accessing PORT.P10_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_out));
    } break;
    case reg_p10_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P10_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_omr));
    } break;
    case reg_p10_id_offset: {
        spdlog::debug("PORT: accessing PORT.P10_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_id));
    } break;
    case reg_p10_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P10_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_iocr0));
    } break;
    case reg_p10_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P10_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_iocr4));
    } break;
    case reg_p10_iocr8_offset: {
        spdlog::debug("PORT: accessing PORT.P10_IOCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_iocr8));
    } break;
    case reg_p10_in_offset: {
        spdlog::debug("PORT: accessing PORT.P10_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_in));
    } break;
    case reg_p10_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P10_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_pdr0));
    } break;
    case reg_p10_pdr1_offset: {
        spdlog::debug("PORT: accessing PORT.P10_PDR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_pdr1));
    } break;
    case reg_p10_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P10_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_esr));
    } break;
    case reg_p10_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P10_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_pdisc));
    } break;
    case reg_p10_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P10_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_pcsr));
    } break;
    case reg_p10_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P10_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_omsr0));
    } break;
    case reg_p10_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P10_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_omsr4));
    } break;
    case reg_p10_omsr8_offset: {
        spdlog::debug("PORT: accessing PORT.P10_OMSR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_omsr8));
    } break;
    case reg_p10_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P10_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_omcr0));
    } break;
    case reg_p10_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P10_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_omcr4));
    } break;
    case reg_p10_omcr8_offset: {
        spdlog::debug("PORT: accessing PORT.P10_OMCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_omcr8));
    } break;
    case reg_p10_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P10_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_omsr));
    } break;
    case reg_p10_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P10_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_omcr));
    } break;
    case reg_p10_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P10_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_accen1));
    } break;
    case reg_p10_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P10_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p10_accen0));
    } break;
    case reg_p11_out_offset: {
        spdlog::debug("PORT: accessing PORT.P11_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_out));
    } break;
    case reg_p11_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P11_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_omr));
    } break;
    case reg_p11_id_offset: {
        spdlog::debug("PORT: accessing PORT.P11_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_id));
    } break;
    case reg_p11_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P11_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_iocr0));
    } break;
    case reg_p11_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P11_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_iocr4));
    } break;
    case reg_p11_iocr8_offset: {
        spdlog::debug("PORT: accessing PORT.P11_IOCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_iocr8));
    } break;
    case reg_p11_iocr12_offset: {
        spdlog::debug("PORT: accessing PORT.P11_IOCR12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_iocr12));
    } break;
    case reg_p11_in_offset: {
        spdlog::debug("PORT: accessing PORT.P11_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_in));
    } break;
    case reg_p11_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P11_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_pdr0));
    } break;
    case reg_p11_pdr1_offset: {
        spdlog::debug("PORT: accessing PORT.P11_PDR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_pdr1));
    } break;
    case reg_p11_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P11_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_esr));
    } break;
    case reg_p11_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P11_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_pdisc));
    } break;
    case reg_p11_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P11_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_pcsr));
    } break;
    case reg_p11_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P11_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_omsr0));
    } break;
    case reg_p11_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P11_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_omsr4));
    } break;
    case reg_p11_omsr8_offset: {
        spdlog::debug("PORT: accessing PORT.P11_OMSR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_omsr8));
    } break;
    case reg_p11_omsr12_offset: {
        spdlog::debug("PORT: accessing PORT.P11_OMSR12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_omsr12));
    } break;
    case reg_p11_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P11_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_omcr0));
    } break;
    case reg_p11_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P11_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_omcr4));
    } break;
    case reg_p11_omcr8_offset: {
        spdlog::debug("PORT: accessing PORT.P11_OMCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_omcr8));
    } break;
    case reg_p11_omcr12_offset: {
        spdlog::debug("PORT: accessing PORT.P11_OMCR12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_omcr12));
    } break;
    case reg_p11_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P11_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_omsr));
    } break;
    case reg_p11_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P11_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_omcr));
    } break;
    case reg_p11_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P11_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_accen1));
    } break;
    case reg_p11_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P11_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p11_accen0));
    } break;
    case reg_p13_out_offset: {
        spdlog::debug("PORT: accessing PORT.P13_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_out));
    } break;
    case reg_p13_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P13_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_omr));
    } break;
    case reg_p13_id_offset: {
        spdlog::debug("PORT: accessing PORT.P13_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_id));
    } break;
    case reg_p13_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P13_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_iocr0));
    } break;
    case reg_p13_in_offset: {
        spdlog::debug("PORT: accessing PORT.P13_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_in));
    } break;
    case reg_p13_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P13_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_pdr0));
    } break;
    case reg_p13_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P13_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_esr));
    } break;
    case reg_p13_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P13_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_pdisc));
    } break;
    case reg_p13_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P13_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_pcsr));
    } break;
    case reg_p13_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P13_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_omsr0));
    } break;
    case reg_p13_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P13_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_omcr0));
    } break;
    case reg_p13_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P13_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_omsr));
    } break;
    case reg_p13_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P13_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_omcr));
    } break;
    case reg_p13_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P13_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_accen1));
    } break;
    case reg_p13_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P13_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p13_accen0));
    } break;
    case reg_p14_out_offset: {
        spdlog::debug("PORT: accessing PORT.P14_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_out));
    } break;
    case reg_p14_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P14_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_omr));
    } break;
    case reg_p14_id_offset: {
        spdlog::debug("PORT: accessing PORT.P14_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_id));
    } break;
    case reg_p14_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P14_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_iocr0));
    } break;
    case reg_p14_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P14_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_iocr4));
    } break;
    case reg_p14_iocr8_offset: {
        spdlog::debug("PORT: accessing PORT.P14_IOCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_iocr8));
    } break;
    case reg_p14_in_offset: {
        spdlog::debug("PORT: accessing PORT.P14_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_in));
    } break;
    case reg_p14_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P14_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_pdr0));
    } break;
    case reg_p14_pdr1_offset: {
        spdlog::debug("PORT: accessing PORT.P14_PDR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_pdr1));
    } break;
    case reg_p14_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P14_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_esr));
    } break;
    case reg_p14_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P14_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_pdisc));
    } break;
    case reg_p14_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P14_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_pcsr));
    } break;
    case reg_p14_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P14_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_omsr0));
    } break;
    case reg_p14_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P14_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_omsr4));
    } break;
    case reg_p14_omsr8_offset: {
        spdlog::debug("PORT: accessing PORT.P14_OMSR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_omsr8));
    } break;
    case reg_p14_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P14_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_omcr0));
    } break;
    case reg_p14_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P14_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_omcr4));
    } break;
    case reg_p14_omcr8_offset: {
        spdlog::debug("PORT: accessing PORT.P14_OMCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_omcr8));
    } break;
    case reg_p14_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P14_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_omsr));
    } break;
    case reg_p14_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P14_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_omcr));
    } break;
    case reg_p14_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P14_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_accen1));
    } break;
    case reg_p14_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P14_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p14_accen0));
    } break;
    case reg_p15_out_offset: {
        spdlog::debug("PORT: accessing PORT.P15_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_out));
    } break;
    case reg_p15_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P15_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_omr));
    } break;
    case reg_p15_id_offset: {
        spdlog::debug("PORT: accessing PORT.P15_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_id));
    } break;
    case reg_p15_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P15_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_iocr0));
    } break;
    case reg_p15_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P15_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_iocr4));
    } break;
    case reg_p15_iocr8_offset: {
        spdlog::debug("PORT: accessing PORT.P15_IOCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_iocr8));
    } break;
    case reg_p15_in_offset: {
        spdlog::debug("PORT: accessing PORT.P15_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_in));
    } break;
    case reg_p15_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P15_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_pdr0));
    } break;
    case reg_p15_pdr1_offset: {
        spdlog::debug("PORT: accessing PORT.P15_PDR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_pdr1));
    } break;
    case reg_p15_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P15_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_esr));
    } break;
    case reg_p15_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P15_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_pdisc));
    } break;
    case reg_p15_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P15_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_pcsr));
    } break;
    case reg_p15_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P15_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_omsr0));
    } break;
    case reg_p15_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P15_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_omsr4));
    } break;
    case reg_p15_omsr8_offset: {
        spdlog::debug("PORT: accessing PORT.P15_OMSR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_omsr8));
    } break;
    case reg_p15_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P15_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_omcr0));
    } break;
    case reg_p15_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P15_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_omcr4));
    } break;
    case reg_p15_omcr8_offset: {
        spdlog::debug("PORT: accessing PORT.P15_OMCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_omcr8));
    } break;
    case reg_p15_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P15_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_omsr));
    } break;
    case reg_p15_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P15_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_omcr));
    } break;
    case reg_p15_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P15_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_accen1));
    } break;
    case reg_p15_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P15_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p15_accen0));
    } break;
    case reg_p20_out_offset: {
        spdlog::debug("PORT: accessing PORT.P20_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_out));
    } break;
    case reg_p20_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P20_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_omr));
    } break;
    case reg_p20_id_offset: {
        spdlog::debug("PORT: accessing PORT.P20_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_id));
    } break;
    case reg_p20_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P20_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_iocr0));
    } break;
    case reg_p20_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P20_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_iocr4));
    } break;
    case reg_p20_iocr8_offset: {
        spdlog::debug("PORT: accessing PORT.P20_IOCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_iocr8));
    } break;
    case reg_p20_iocr12_offset: {
        spdlog::debug("PORT: accessing PORT.P20_IOCR12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_iocr12));
    } break;
    case reg_p20_in_offset: {
        spdlog::debug("PORT: accessing PORT.P20_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_in));
    } break;
    case reg_p20_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P20_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_pdr0));
    } break;
    case reg_p20_pdr1_offset: {
        spdlog::debug("PORT: accessing PORT.P20_PDR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_pdr1));
    } break;
    case reg_p20_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P20_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_esr));
    } break;
    case reg_p20_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P20_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_pdisc));
    } break;
    case reg_p20_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P20_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_pcsr));
    } break;
    case reg_p20_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P20_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_omsr0));
    } break;
    case reg_p20_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P20_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_omsr4));
    } break;
    case reg_p20_omsr8_offset: {
        spdlog::debug("PORT: accessing PORT.P20_OMSR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_omsr8));
    } break;
    case reg_p20_omsr12_offset: {
        spdlog::debug("PORT: accessing PORT.P20_OMSR12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_omsr12));
    } break;
    case reg_p20_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P20_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_omcr0));
    } break;
    case reg_p20_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P20_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_omcr4));
    } break;
    case reg_p20_omcr8_offset: {
        spdlog::debug("PORT: accessing PORT.P20_OMCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_omcr8));
    } break;
    case reg_p20_omcr12_offset: {
        spdlog::debug("PORT: accessing PORT.P20_OMCR12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_omcr12));
    } break;
    case reg_p20_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P20_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_omsr));
    } break;
    case reg_p20_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P20_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_omcr));
    } break;
    case reg_p20_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P20_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_accen1));
    } break;
    case reg_p20_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P20_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p20_accen0));
    } break;
    case reg_p21_out_offset: {
        spdlog::debug("PORT: accessing PORT.P21_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_out));
    } break;
    case reg_p21_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P21_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_omr));
    } break;
    case reg_p21_id_offset: {
        spdlog::debug("PORT: accessing PORT.P21_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_id));
    } break;
    case reg_p21_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P21_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_iocr0));
    } break;
    case reg_p21_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P21_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_iocr4));
    } break;
    case reg_p21_in_offset: {
        spdlog::debug("PORT: accessing PORT.P21_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_in));
    } break;
    case reg_p21_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P21_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_pdr0));
    } break;
    case reg_p21_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P21_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_esr));
    } break;
    case reg_p21_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P21_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_pdisc));
    } break;
    case reg_p21_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P21_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_pcsr));
    } break;
    case reg_p21_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P21_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_omsr0));
    } break;
    case reg_p21_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P21_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_omsr4));
    } break;
    case reg_p21_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P21_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_omcr0));
    } break;
    case reg_p21_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P21_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_omcr4));
    } break;
    case reg_p21_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P21_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_omsr));
    } break;
    case reg_p21_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P21_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_omcr));
    } break;
    case reg_p21_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P21_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_accen1));
    } break;
    case reg_p21_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P21_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p21_accen0));
    } break;
    case reg_p22_out_offset: {
        spdlog::debug("PORT: accessing PORT.P22_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_out));
    } break;
    case reg_p22_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P22_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_omr));
    } break;
    case reg_p22_id_offset: {
        spdlog::debug("PORT: accessing PORT.P22_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_id));
    } break;
    case reg_p22_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P22_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_iocr0));
    } break;
    case reg_p22_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P22_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_iocr4));
    } break;
    case reg_p22_in_offset: {
        spdlog::debug("PORT: accessing PORT.P22_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_in));
    } break;
    case reg_p22_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P22_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_pdr0));
    } break;
    case reg_p22_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P22_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_esr));
    } break;
    case reg_p22_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P22_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_pdisc));
    } break;
    case reg_p22_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P22_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_pcsr));
    } break;
    case reg_p22_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P22_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_omsr0));
    } break;
    case reg_p22_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P22_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_omsr4));
    } break;
    case reg_p22_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P22_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_omcr0));
    } break;
    case reg_p22_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P22_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_omcr4));
    } break;
    case reg_p22_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P22_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_omsr));
    } break;
    case reg_p22_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P22_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_omcr));
    } break;
    case reg_p22_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P22_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_accen1));
    } break;
    case reg_p22_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P22_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p22_accen0));
    } break;
    case reg_p23_out_offset: {
        spdlog::debug("PORT: accessing PORT.P23_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_out));
    } break;
    case reg_p23_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P23_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_omr));
    } break;
    case reg_p23_id_offset: {
        spdlog::debug("PORT: accessing PORT.P23_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_id));
    } break;
    case reg_p23_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P23_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_iocr0));
    } break;
    case reg_p23_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P23_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_iocr4));
    } break;
    case reg_p23_in_offset: {
        spdlog::debug("PORT: accessing PORT.P23_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_in));
    } break;
    case reg_p23_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P23_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_pdr0));
    } break;
    case reg_p23_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P23_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_esr));
    } break;
    case reg_p23_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P23_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_pdisc));
    } break;
    case reg_p23_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P23_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_pcsr));
    } break;
    case reg_p23_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P23_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_omsr0));
    } break;
    case reg_p23_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P23_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_omsr4));
    } break;
    case reg_p23_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P23_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_omcr0));
    } break;
    case reg_p23_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P23_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_omcr4));
    } break;
    case reg_p23_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P23_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_omsr));
    } break;
    case reg_p23_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P23_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_omcr));
    } break;
    case reg_p23_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P23_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_accen1));
    } break;
    case reg_p23_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P23_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p23_accen0));
    } break;
    case reg_p32_out_offset: {
        spdlog::debug("PORT: accessing PORT.P32_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_out));
    } break;
    case reg_p32_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P32_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_omr));
    } break;
    case reg_p32_id_offset: {
        spdlog::debug("PORT: accessing PORT.P32_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_id));
    } break;
    case reg_p32_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P32_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_iocr0));
    } break;
    case reg_p32_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P32_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_iocr4));
    } break;
    case reg_p32_in_offset: {
        spdlog::debug("PORT: accessing PORT.P32_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_in));
    } break;
    case reg_p32_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P32_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_pdr0));
    } break;
    case reg_p32_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P32_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_esr));
    } break;
    case reg_p32_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P32_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_pdisc));
    } break;
    case reg_p32_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P32_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_pcsr));
    } break;
    case reg_p32_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P32_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_omsr0));
    } break;
    case reg_p32_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P32_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_omsr4));
    } break;
    case reg_p32_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P32_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_omcr0));
    } break;
    case reg_p32_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P32_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_omcr4));
    } break;
    case reg_p32_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P32_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_omsr));
    } break;
    case reg_p32_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P32_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_omcr));
    } break;
    case reg_p32_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P32_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_accen1));
    } break;
    case reg_p32_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P32_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p32_accen0));
    } break;
    case reg_p33_out_offset: {
        spdlog::debug("PORT: accessing PORT.P33_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_out));
    } break;
    case reg_p33_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P33_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_omr));
    } break;
    case reg_p33_id_offset: {
        spdlog::debug("PORT: accessing PORT.P33_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_id));
    } break;
    case reg_p33_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P33_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_iocr0));
    } break;
    case reg_p33_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P33_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_iocr4));
    } break;
    case reg_p33_iocr8_offset: {
        spdlog::debug("PORT: accessing PORT.P33_IOCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_iocr8));
    } break;
    case reg_p33_iocr12_offset: {
        spdlog::debug("PORT: accessing PORT.P33_IOCR12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_iocr12));
    } break;
    case reg_p33_in_offset: {
        spdlog::debug("PORT: accessing PORT.P33_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_in));
    } break;
    case reg_p33_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P33_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_pdr0));
    } break;
    case reg_p33_pdr1_offset: {
        spdlog::debug("PORT: accessing PORT.P33_PDR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_pdr1));
    } break;
    case reg_p33_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P33_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_esr));
    } break;
    case reg_p33_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P33_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_pdisc));
    } break;
    case reg_p33_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P33_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_pcsr));
    } break;
    case reg_p33_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P33_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_omsr0));
    } break;
    case reg_p33_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P33_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_omsr4));
    } break;
    case reg_p33_omsr8_offset: {
        spdlog::debug("PORT: accessing PORT.P33_OMSR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_omsr8));
    } break;
    case reg_p33_omsr12_offset: {
        spdlog::debug("PORT: accessing PORT.P33_OMSR12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_omsr12));
    } break;
    case reg_p33_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P33_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_omcr0));
    } break;
    case reg_p33_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P33_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_omcr4));
    } break;
    case reg_p33_omcr8_offset: {
        spdlog::debug("PORT: accessing PORT.P33_OMCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_omcr8));
    } break;
    case reg_p33_omcr12_offset: {
        spdlog::debug("PORT: accessing PORT.P33_OMCR12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_omcr12));
    } break;
    case reg_p33_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P33_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_omsr));
    } break;
    case reg_p33_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P33_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_omcr));
    } break;
    case reg_p33_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P33_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_accen1));
    } break;
    case reg_p33_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P33_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p33_accen0));
    } break;
    case reg_p34_out_offset: {
        spdlog::debug("PORT: accessing PORT.P34_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_out));
    } break;
    case reg_p34_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P34_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_omr));
    } break;
    case reg_p34_id_offset: {
        spdlog::debug("PORT: accessing PORT.P34_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_id));
    } break;
    case reg_p34_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P34_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_iocr0));
    } break;
    case reg_p34_in_offset: {
        spdlog::debug("PORT: accessing PORT.P34_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_in));
    } break;
    case reg_p34_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P34_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_pdr0));
    } break;
    case reg_p34_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P34_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_esr));
    } break;
    case reg_p34_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P34_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_pdisc));
    } break;
    case reg_p34_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P34_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_pcsr));
    } break;
    case reg_p34_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P34_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_omsr0));
    } break;
    case reg_p34_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P34_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_omcr0));
    } break;
    case reg_p34_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P34_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_omsr));
    } break;
    case reg_p34_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P34_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_omcr));
    } break;
    case reg_p34_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P34_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_accen1));
    } break;
    case reg_p34_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P34_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p34_accen0));
    } break;
    case reg_p40_out_offset: {
        spdlog::debug("PORT: accessing PORT.P40_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_out));
    } break;
    case reg_p40_omr_offset: {
        spdlog::debug("PORT: accessing PORT.P40_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_omr));
    } break;
    case reg_p40_id_offset: {
        spdlog::debug("PORT: accessing PORT.P40_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_id));
    } break;
    case reg_p40_iocr0_offset: {
        spdlog::debug("PORT: accessing PORT.P40_IOCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_iocr0));
    } break;
    case reg_p40_iocr4_offset: {
        spdlog::debug("PORT: accessing PORT.P40_IOCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_iocr4));
    } break;
    case reg_p40_iocr8_offset: {
        spdlog::debug("PORT: accessing PORT.P40_IOCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_iocr8));
    } break;
    case reg_p40_in_offset: {
        spdlog::debug("PORT: accessing PORT.P40_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_in));
    } break;
    case reg_p40_pdr0_offset: {
        spdlog::debug("PORT: accessing PORT.P40_PDR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_pdr0));
    } break;
    case reg_p40_pdr1_offset: {
        spdlog::debug("PORT: accessing PORT.P40_PDR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_pdr1));
    } break;
    case reg_p40_esr_offset: {
        spdlog::debug("PORT: accessing PORT.P40_ESR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_esr));
    } break;
    case reg_p40_pdisc_offset: {
        spdlog::debug("PORT: accessing PORT.P40_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_pdisc));
    } break;
    case reg_p40_pcsr_offset: {
        spdlog::debug("PORT: accessing PORT.P40_PCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_pcsr));
    } break;
    case reg_p40_omsr0_offset: {
        spdlog::debug("PORT: accessing PORT.P40_OMSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_omsr0));
    } break;
    case reg_p40_omsr4_offset: {
        spdlog::debug("PORT: accessing PORT.P40_OMSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_omsr4));
    } break;
    case reg_p40_omsr8_offset: {
        spdlog::debug("PORT: accessing PORT.P40_OMSR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_omsr8));
    } break;
    case reg_p40_omcr0_offset: {
        spdlog::debug("PORT: accessing PORT.P40_OMCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_omcr0));
    } break;
    case reg_p40_omcr4_offset: {
        spdlog::debug("PORT: accessing PORT.P40_OMCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_omcr4));
    } break;
    case reg_p40_omcr8_offset: {
        spdlog::debug("PORT: accessing PORT.P40_OMCR8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_omcr8));
    } break;
    case reg_p40_omsr_offset: {
        spdlog::debug("PORT: accessing PORT.P40_OMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_omsr));
    } break;
    case reg_p40_omcr_offset: {
        spdlog::debug("PORT: accessing PORT.P40_OMCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_omcr));
    } break;
    case reg_p40_accen1_offset: {
        spdlog::debug("PORT: accessing PORT.P40_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_accen1));
    } break;
    case reg_p40_accen0_offset: {
        spdlog::debug("PORT: accessing PORT.P40_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_p40_accen0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Port peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
