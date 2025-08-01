
/**
 * @brief Module source for Scu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Scu.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 scu_id_reset_value = 0xC4C0C1U;
constexpr u32 scu_osccon_reset_value = 0x10U;
constexpr u32 scu_syspllstat_reset_value = 0x2U;
constexpr u32 scu_syspllcon0_reset_value = 0x40003A00U;
constexpr u32 scu_syspllcon1_reset_value = 0x5U;
constexpr u32 scu_syspllcon2_reset_value = 0x6000U;
constexpr u32 scu_perpllstat_reset_value = 0x2U;
constexpr u32 scu_perpllcon0_reset_value = 0x3E00U;
constexpr u32 scu_perpllcon1_reset_value = 0x1U;
constexpr u32 scu_ccucon0_reset_value = 0x05120112U;
constexpr u32 scu_ccucon1_reset_value = 0x10100302U;
constexpr u32 scu_fdr_reset_value = 0;
constexpr u32 scu_extcon_reset_value = 0;
constexpr u32 scu_ccucon2_reset_value = 0x07000101U;
constexpr u32 scu_ccucon3_reset_value = 0;
constexpr u32 scu_ccucon4_reset_value = 0;
constexpr u32 scu_ccucon5_reset_value = 0x30U;
constexpr u32 scu_rststat_reset_value = 0x00010000U;
constexpr u32 scu_rstcon_reset_value = 0x0282U;
constexpr u32 scu_arstdis_reset_value = 0;
constexpr u32 scu_swrstcon_reset_value = 0;
constexpr u32 scu_rstcon2_reset_value = 0;
constexpr u32 scu_rstcon3_reset_value = 0x8FFF3400U;
constexpr u32 scu_esrocfg_reset_value = 0;
constexpr u32 scu_syscon_reset_value = 0;
constexpr u32 scu_ccucon6_reset_value = 0;
constexpr u32 scu_ccucon7_reset_value = 0;
constexpr u32 scu_pdr_reset_value = 0;
constexpr u32 scu_iocr_reset_value = 0xE0U;
constexpr u32 scu_out_reset_value = 0;
constexpr u32 scu_omr_reset_value = 0;
constexpr u32 scu_in_reset_value = 0;
constexpr u32 scu_ststat_reset_value = 0x8000U;
constexpr u32 scu_stcon_reset_value = 0;
constexpr u32 scu_pmcsr0_reset_value = 0x100U;
constexpr u32 scu_pmcsr1_reset_value = 0x100U;
constexpr u32 scu_pmcsr2_reset_value = 0x100U;
constexpr u32 scu_pmcsr3_reset_value = 0x100U;
constexpr u32 scu_pmcsr4_reset_value = 0x100U;
constexpr u32 scu_pmcsr5_reset_value = 0x100U;
constexpr u32 scu_pmstat0_reset_value = 0x1U;
constexpr u32 scu_pmswcr1_reset_value = 0x01000000U;
constexpr u32 scu_emsr_reset_value = 0x1U;
constexpr u32 scu_emssw_reset_value = 0;
constexpr u32 scu_dtscstat_reset_value = 0; // TODO: change according manual
constexpr u32 scu_dtsclim_reset_value = 0; // TODO: change according manual
constexpr u32 scu_trapdis1_reset_value = 0x0000FFFFU;
constexpr u32 scu_trapstat_reset_value = 0;
constexpr u32 scu_trapset_reset_value = 0;
constexpr u32 scu_trapclr_reset_value = 0;
constexpr u32 scu_trapdis0_reset_value = 0xFFFFFFFFU;
constexpr u32 scu_lclcon0_reset_value = 0x80018001U;
constexpr u32 scu_lclcon1_reset_value = 0x80018001U;
constexpr u32 scu_lcltest_reset_value = 0;
constexpr u32 scu_chipid_reset_value = 0x4003080U; // CHID set to tc-33x, fsize set to 2MB
constexpr u32 scu_manid_reset_value = 0x1820U;
constexpr u32 scu_swapctrl_reset_value = 0x1U;
constexpr u32 scu_lbistctrl0_reset_value = 0x10000000U; // LBISTDONE set to 1
constexpr u32 scu_lbistctrl1_reset_value = 0;
constexpr u32 scu_lbistctrl2_reset_value = 0;
constexpr u32 scu_lbistctrl3_reset_value = 0;
constexpr u32 scu_stmem1_reset_value = 0;
constexpr u32 scu_stmem2_reset_value = 0;
constexpr u32 scu_pdisc_reset_value = 0;
constexpr u32 scu_pmtrcsr0_reset_value = 0;
constexpr u32 scu_pmtrcsr1_reset_value = 0;
constexpr u32 scu_pmtrcsr2_reset_value = 0;
constexpr u32 scu_pmtrcsr3_reset_value = 0;
constexpr u32 scu_stmem3_reset_value = 0;
constexpr u32 scu_stmem4_reset_value = 0;
constexpr u32 scu_stmem5_reset_value = 0;
constexpr u32 scu_stmem6_reset_value = 0;
constexpr u32 scu_ovcenable_reset_value = 0;
constexpr u32 scu_ovccon_reset_value = 0;
constexpr u32 scu_eifilt_reset_value = 0;
constexpr u32 scu_eifr_reset_value = 0;
constexpr u32 scu_fmr_reset_value = 0;
constexpr u32 scu_pdrr_reset_value = 0xFFU;
constexpr u32 scu_wdtcpu0_con0_reset_value = 0xFFFC000EU;
constexpr u32 scu_eicon0_reset_value = 0xFFFC000EU;
constexpr u32 scu_eicon1_reset_value = 0;
constexpr u32 scu_eisr_reset_value = 0xFFFC0000U;
constexpr u32 scu_wdts_con0_reset_value = 0xFFFC000E;
constexpr u32 scu_wdts_con1_reset_value = 0;
constexpr u32 scu_wdts_sr_reset_value = 0xFFFC0010U;
constexpr u32 scu_seicon0_reset_value = 0xFFFC000E;
constexpr u32 scu_seicon1_reset_value = 0;
constexpr u32 scu_seisr_reset_value = 0xFFFC0000U;
constexpr u32 scu_accen11_reset_value = 0;
constexpr u32 scu_accen10_reset_value = 0xFFFFFFFFU;
constexpr u32 scu_accen01_reset_value = 0;
constexpr u32 scu_accen00_reset_value = 0xFFFFFFFFU;

constexpr u32 scu_memory_start_address = 0xf0036000U;
constexpr u32 scu_memory_size = 1U * KiB;
constexpr u32 scu_memory_end_address = scu_memory_start_address + scu_memory_size;

constexpr u32 reg_scu_id_address = 0xf0036008;
constexpr u32 reg_scu_id_offset = reg_scu_id_address - scu_memory_start_address;
constexpr u32 reg_scu_osccon_address = 0xf0036010;
constexpr u32 reg_scu_osccon_offset = reg_scu_osccon_address - scu_memory_start_address;
constexpr u32 reg_scu_syspllstat_address = 0xf0036014;
constexpr u32 reg_scu_syspllstat_offset = reg_scu_syspllstat_address - scu_memory_start_address;
constexpr u32 reg_scu_syspllcon0_address = 0xf0036018;
constexpr u32 reg_scu_syspllcon0_offset = reg_scu_syspllcon0_address - scu_memory_start_address;
constexpr u32 reg_scu_syspllcon1_address = 0xf003601c;
constexpr u32 reg_scu_syspllcon1_offset = reg_scu_syspllcon1_address - scu_memory_start_address;
constexpr u32 reg_scu_syspllcon2_address = 0xf0036020;
constexpr u32 reg_scu_syspllcon2_offset = reg_scu_syspllcon2_address - scu_memory_start_address;
constexpr u32 reg_scu_perpllstat_address = 0xf0036024;
constexpr u32 reg_scu_perpllstat_offset = reg_scu_perpllstat_address - scu_memory_start_address;
constexpr u32 reg_scu_perpllcon0_address = 0xf0036028;
constexpr u32 reg_scu_perpllcon0_offset = reg_scu_perpllcon0_address - scu_memory_start_address;
constexpr u32 reg_scu_perpllcon1_address = 0xf003602c;
constexpr u32 reg_scu_perpllcon1_offset = reg_scu_perpllcon1_address - scu_memory_start_address;
constexpr u32 reg_scu_ccucon0_address = 0xf0036030;
constexpr u32 reg_scu_ccucon0_offset = reg_scu_ccucon0_address - scu_memory_start_address;
constexpr u32 reg_scu_ccucon1_address = 0xf0036034;
constexpr u32 reg_scu_ccucon1_offset = reg_scu_ccucon1_address - scu_memory_start_address;
constexpr u32 reg_scu_fdr_address = 0xf0036038;
constexpr u32 reg_scu_fdr_offset = reg_scu_fdr_address - scu_memory_start_address;
constexpr u32 reg_scu_extcon_address = 0xf003603c;
constexpr u32 reg_scu_extcon_offset = reg_scu_extcon_address - scu_memory_start_address;
constexpr u32 reg_scu_ccucon2_address = 0xf0036040;
constexpr u32 reg_scu_ccucon2_offset = reg_scu_ccucon2_address - scu_memory_start_address;
constexpr u32 reg_scu_ccucon3_address = 0xf0036044;
constexpr u32 reg_scu_ccucon3_offset = reg_scu_ccucon3_address - scu_memory_start_address;
constexpr u32 reg_scu_ccucon4_address = 0xf0036048;
constexpr u32 reg_scu_ccucon4_offset = reg_scu_ccucon4_address - scu_memory_start_address;
constexpr u32 reg_scu_ccucon5_address = 0xf003604c;
constexpr u32 reg_scu_ccucon5_offset = reg_scu_ccucon5_address - scu_memory_start_address;
constexpr u32 reg_scu_rststat_address = 0xf0036050;
constexpr u32 reg_scu_rststat_offset = reg_scu_rststat_address - scu_memory_start_address;
constexpr u32 reg_scu_rstcon_address = 0xf0036058;
constexpr u32 reg_scu_rstcon_offset = reg_scu_rstcon_address - scu_memory_start_address;
constexpr u32 reg_scu_arstdis_address = 0xf003605c;
constexpr u32 reg_scu_arstdis_offset = reg_scu_arstdis_address - scu_memory_start_address;
constexpr u32 reg_scu_swrstcon_address = 0xf0036060;
constexpr u32 reg_scu_swrstcon_offset = reg_scu_swrstcon_address - scu_memory_start_address;
constexpr u32 reg_scu_rstcon2_address = 0xf0036064;
constexpr u32 reg_scu_rstcon2_offset = reg_scu_rstcon2_address - scu_memory_start_address;
constexpr u32 reg_scu_rstcon3_address = 0xf0036068;
constexpr u32 reg_scu_rstcon3_offset = reg_scu_rstcon3_address - scu_memory_start_address;
constexpr u32 reg_scu_esrocfg_address = 0xf0036078;
constexpr u32 reg_scu_esrocfg_offset = reg_scu_esrocfg_address - scu_memory_start_address;
constexpr u32 reg_scu_syscon_address = 0xf003607c;
constexpr u32 reg_scu_syscon_offset = reg_scu_syscon_address - scu_memory_start_address;
constexpr u32 reg_scu_ccucon6_address = 0xf0036080;
constexpr u32 reg_scu_ccucon6_offset = reg_scu_ccucon6_address - scu_memory_start_address;
constexpr u32 reg_scu_ccucon7_address = 0xf0036084;
constexpr u32 reg_scu_ccucon7_offset = reg_scu_ccucon7_address - scu_memory_start_address;
constexpr u32 reg_scu_pdr_address = 0xf003609c;
constexpr u32 reg_scu_pdr_offset = reg_scu_pdr_address - scu_memory_start_address;
constexpr u32 reg_scu_iocr_address = 0xf00360a0;
constexpr u32 reg_scu_iocr_offset = reg_scu_iocr_address - scu_memory_start_address;
constexpr u32 reg_scu_out_address = 0xf00360a4;
constexpr u32 reg_scu_out_offset = reg_scu_out_address - scu_memory_start_address;
constexpr u32 reg_scu_omr_address = 0xf00360a8;
constexpr u32 reg_scu_omr_offset = reg_scu_omr_address - scu_memory_start_address;
constexpr u32 reg_scu_in_address = 0xf00360ac;
constexpr u32 reg_scu_in_offset = reg_scu_in_address - scu_memory_start_address;
constexpr u32 reg_scu_ststat_address = 0xf00360c0;
constexpr u32 reg_scu_ststat_offset = reg_scu_ststat_address - scu_memory_start_address;
constexpr u32 reg_scu_stcon_address = 0xf00360c4;
constexpr u32 reg_scu_stcon_offset = reg_scu_stcon_address - scu_memory_start_address;
constexpr u32 reg_scu_pmcsr0_address = 0xf00360c8;
constexpr u32 reg_scu_pmcsr0_offset = reg_scu_pmcsr0_address - scu_memory_start_address;
constexpr u32 reg_scu_pmcsr1_address = 0xf00360cc;
constexpr u32 reg_scu_pmcsr1_offset = reg_scu_pmcsr1_address - scu_memory_start_address;
constexpr u32 reg_scu_pmcsr2_address = 0xf00360d0;
constexpr u32 reg_scu_pmcsr2_offset = reg_scu_pmcsr2_address - scu_memory_start_address;
constexpr u32 reg_scu_pmcsr3_address = 0xf00360d4;
constexpr u32 reg_scu_pmcsr3_offset = reg_scu_pmcsr3_address - scu_memory_start_address;
constexpr u32 reg_scu_pmcsr4_address = 0xf00360d8;
constexpr u32 reg_scu_pmcsr4_offset = reg_scu_pmcsr4_address - scu_memory_start_address;
constexpr u32 reg_scu_pmcsr5_address = 0xf00360dc;
constexpr u32 reg_scu_pmcsr5_offset = reg_scu_pmcsr5_address - scu_memory_start_address;
constexpr u32 reg_scu_pmstat0_address = 0xf00360e4;
constexpr u32 reg_scu_pmstat0_offset = reg_scu_pmstat0_address - scu_memory_start_address;
constexpr u32 reg_scu_pmswcr1_address = 0xf00360e8;
constexpr u32 reg_scu_pmswcr1_offset = reg_scu_pmswcr1_address - scu_memory_start_address;
constexpr u32 reg_scu_emsr_address = 0xf00360fc;
constexpr u32 reg_scu_emsr_offset = reg_scu_emsr_address - scu_memory_start_address;
constexpr u32 reg_scu_emssw_address = 0xf0036100;
constexpr u32 reg_scu_emssw_offset = reg_scu_emssw_address - scu_memory_start_address;
constexpr u32 reg_scu_dtscstat_address = 0xf0036104;
constexpr u32 reg_scu_dtscstat_offset = reg_scu_dtscstat_address - scu_memory_start_address;
constexpr u32 reg_scu_dtsclim_address = 0xf0036108;
constexpr u32 reg_scu_dtsclim_offset = reg_scu_dtsclim_address - scu_memory_start_address;
constexpr u32 reg_scu_trapdis1_address = 0xf0036120;
constexpr u32 reg_scu_trapdis1_offset = reg_scu_trapdis1_address - scu_memory_start_address;
constexpr u32 reg_scu_trapstat_address = 0xf0036124;
constexpr u32 reg_scu_trapstat_offset = reg_scu_trapstat_address - scu_memory_start_address;
constexpr u32 reg_scu_trapset_address = 0xf0036128;
constexpr u32 reg_scu_trapset_offset = reg_scu_trapset_address - scu_memory_start_address;
constexpr u32 reg_scu_trapclr_address = 0xf003612c;
constexpr u32 reg_scu_trapclr_offset = reg_scu_trapclr_address - scu_memory_start_address;
constexpr u32 reg_scu_trapdis0_address = 0xf0036130;
constexpr u32 reg_scu_trapdis0_offset = reg_scu_trapdis0_address - scu_memory_start_address;
constexpr u32 reg_scu_lclcon0_address = 0xf0036134;
constexpr u32 reg_scu_lclcon0_offset = reg_scu_lclcon0_address - scu_memory_start_address;
constexpr u32 reg_scu_lclcon1_address = 0xf0036138;
constexpr u32 reg_scu_lclcon1_offset = reg_scu_lclcon1_address - scu_memory_start_address;
constexpr u32 reg_scu_lcltest_address = 0xf003613c;
constexpr u32 reg_scu_lcltest_offset = reg_scu_lcltest_address - scu_memory_start_address;
constexpr u32 reg_scu_chipid_address = 0xf0036140;
constexpr u32 reg_scu_chipid_offset = reg_scu_chipid_address - scu_memory_start_address;
constexpr u32 reg_scu_manid_address = 0xf0036144;
constexpr u32 reg_scu_manid_offset = reg_scu_manid_address - scu_memory_start_address;
constexpr u32 reg_scu_swapctrl_address = 0xf003614c;
constexpr u32 reg_scu_swapctrl_offset = reg_scu_swapctrl_address - scu_memory_start_address;
constexpr u32 reg_scu_lbistctrl0_address = 0xf0036164;
constexpr u32 reg_scu_lbistctrl0_offset = reg_scu_lbistctrl0_address - scu_memory_start_address;
constexpr u32 reg_scu_lbistctrl1_address = 0xf0036168;
constexpr u32 reg_scu_lbistctrl1_offset = reg_scu_lbistctrl1_address - scu_memory_start_address;
constexpr u32 reg_scu_lbistctrl2_address = 0xf003616c;
constexpr u32 reg_scu_lbistctrl2_offset = reg_scu_lbistctrl2_address - scu_memory_start_address;
constexpr u32 reg_scu_lbistctrl3_address = 0xf0036170;
constexpr u32 reg_scu_lbistctrl3_offset = reg_scu_lbistctrl3_address - scu_memory_start_address;
constexpr u32 reg_scu_stmem1_address = 0xf0036184;
constexpr u32 reg_scu_stmem1_offset = reg_scu_stmem1_address - scu_memory_start_address;
constexpr u32 reg_scu_stmem2_address = 0xf0036188;
constexpr u32 reg_scu_stmem2_offset = reg_scu_stmem2_address - scu_memory_start_address;
constexpr u32 reg_scu_pdisc_address = 0xf003618c;
constexpr u32 reg_scu_pdisc_offset = reg_scu_pdisc_address - scu_memory_start_address;
constexpr u32 reg_scu_pmtrcsr0_address = 0xf0036198;
constexpr u32 reg_scu_pmtrcsr0_offset = reg_scu_pmtrcsr0_address - scu_memory_start_address;
constexpr u32 reg_scu_pmtrcsr1_address = 0xf003619c;
constexpr u32 reg_scu_pmtrcsr1_offset = reg_scu_pmtrcsr1_address - scu_memory_start_address;
constexpr u32 reg_scu_pmtrcsr2_address = 0xf00361a0;
constexpr u32 reg_scu_pmtrcsr2_offset = reg_scu_pmtrcsr2_address - scu_memory_start_address;
constexpr u32 reg_scu_pmtrcsr3_address = 0xf00361a4;
constexpr u32 reg_scu_pmtrcsr3_offset = reg_scu_pmtrcsr3_address - scu_memory_start_address;
constexpr u32 reg_scu_stmem3_address = 0xf00361c0;
constexpr u32 reg_scu_stmem3_offset = reg_scu_stmem3_address - scu_memory_start_address;
constexpr u32 reg_scu_stmem4_address = 0xf00361c4;
constexpr u32 reg_scu_stmem4_offset = reg_scu_stmem4_address - scu_memory_start_address;
constexpr u32 reg_scu_stmem5_address = 0xf00361c8;
constexpr u32 reg_scu_stmem5_offset = reg_scu_stmem5_address - scu_memory_start_address;
constexpr u32 reg_scu_stmem6_address = 0xf00361cc;
constexpr u32 reg_scu_stmem6_offset = reg_scu_stmem6_address - scu_memory_start_address;
constexpr u32 reg_scu_ovcenable_address = 0xf00361e0;
constexpr u32 reg_scu_ovcenable_offset = reg_scu_ovcenable_address - scu_memory_start_address;
constexpr u32 reg_scu_ovccon_address = 0xf00361e4;
constexpr u32 reg_scu_ovccon_offset = reg_scu_ovccon_address - scu_memory_start_address;
constexpr u32 reg_scu_eifilt_address = 0xf003620c;
constexpr u32 reg_scu_eifilt_offset = reg_scu_eifilt_address - scu_memory_start_address;
constexpr u32 reg_scu_eifr_address = 0xf0036220;
constexpr u32 reg_scu_eifr_offset = reg_scu_eifr_address - scu_memory_start_address;
constexpr u32 reg_scu_fmr_address = 0xf0036224;
constexpr u32 reg_scu_fmr_offset = reg_scu_fmr_address - scu_memory_start_address;
constexpr u32 reg_scu_pdrr_address = 0xf0036228;
constexpr u32 reg_scu_pdrr_offset = reg_scu_pdrr_address - scu_memory_start_address;
constexpr u32 reg_scu_wdtcpu0_con0_address = 0xf003624c;
constexpr u32 reg_scu_wdtcpu0_con0_offset = reg_scu_wdtcpu0_con0_address - scu_memory_start_address;
constexpr u32 reg_scu_eicon0_address = 0xf003629c;
constexpr u32 reg_scu_eicon0_offset = reg_scu_eicon0_address - scu_memory_start_address;
constexpr u32 reg_scu_eicon1_address = 0xf00362a0;
constexpr u32 reg_scu_eicon1_offset = reg_scu_eicon1_address - scu_memory_start_address;
constexpr u32 reg_scu_eisr_address = 0xf00362a4;
constexpr u32 reg_scu_eisr_offset = reg_scu_eisr_address - scu_memory_start_address;
constexpr u32 reg_scu_wdts_con0_address = 0xf00362a8;
constexpr u32 reg_scu_wdts_con0_offset = reg_scu_wdts_con0_address - scu_memory_start_address;
constexpr u32 reg_scu_wdts_con1_address = 0xf00362ac;
constexpr u32 reg_scu_wdts_con1_offset = reg_scu_wdts_con1_address - scu_memory_start_address;
constexpr u32 reg_scu_wdts_sr_address = 0xf00362b0;
constexpr u32 reg_scu_wdts_sr_offset = reg_scu_wdts_sr_address - scu_memory_start_address;
constexpr u32 reg_scu_seicon0_address = 0xf00362b4;
constexpr u32 reg_scu_seicon0_offset = reg_scu_seicon0_address - scu_memory_start_address;
constexpr u32 reg_scu_seicon1_address = 0xf00362b8;
constexpr u32 reg_scu_seicon1_offset = reg_scu_seicon1_address - scu_memory_start_address;
constexpr u32 reg_scu_seisr_address = 0xf00362bc;
constexpr u32 reg_scu_seisr_offset = reg_scu_seisr_address - scu_memory_start_address;
constexpr u32 reg_scu_accen11_address = 0xf00363f0;
constexpr u32 reg_scu_accen11_offset = reg_scu_accen11_address - scu_memory_start_address;
constexpr u32 reg_scu_accen10_address = 0xf00363f4;
constexpr u32 reg_scu_accen10_offset = reg_scu_accen10_address - scu_memory_start_address;
constexpr u32 reg_scu_accen01_address = 0xf00363f8;
constexpr u32 reg_scu_accen01_offset = reg_scu_accen01_address - scu_memory_start_address;
constexpr u32 reg_scu_accen00_address = 0xf00363fc;
constexpr u32 reg_scu_accen00_offset = reg_scu_accen00_address - scu_memory_start_address;

} // anonymous namespace


Tricore::Peripherals::Scu::Scu()
    : m_scu_id(scu_id_reset_value)
    , m_scu_osccon(scu_osccon_reset_value)
    , m_scu_syspllstat(scu_syspllstat_reset_value)
    , m_scu_syspllcon0(scu_syspllcon0_reset_value)
    , m_scu_syspllcon1(scu_syspllcon1_reset_value)
    , m_scu_syspllcon2(scu_syspllcon2_reset_value)
    , m_scu_perpllstat(scu_perpllstat_reset_value)
    , m_scu_perpllcon0(scu_perpllcon0_reset_value)
    , m_scu_perpllcon1(scu_perpllcon1_reset_value)
    , m_scu_ccucon0(scu_ccucon0_reset_value)
    , m_scu_ccucon1(scu_ccucon1_reset_value)
    , m_scu_fdr(scu_fdr_reset_value)
    , m_scu_extcon(scu_extcon_reset_value)
    , m_scu_ccucon2(scu_ccucon2_reset_value)
    , m_scu_ccucon3(scu_ccucon3_reset_value)
    , m_scu_ccucon4(scu_ccucon4_reset_value)
    , m_scu_ccucon5(scu_ccucon5_reset_value)
    , m_scu_rststat(scu_rststat_reset_value)
    , m_scu_rstcon(scu_rstcon_reset_value)
    , m_scu_arstdis(scu_arstdis_reset_value)
    , m_scu_swrstcon(scu_swrstcon_reset_value)
    , m_scu_rstcon2(scu_rstcon2_reset_value)
    , m_scu_rstcon3(scu_rstcon3_reset_value)
    , m_scu_esrocfg(scu_esrocfg_reset_value)
    , m_scu_syscon(scu_syscon_reset_value)
    , m_scu_ccucon6(scu_ccucon6_reset_value)
    , m_scu_ccucon7(scu_ccucon7_reset_value)
    , m_scu_pdr(scu_pdr_reset_value)
    , m_scu_iocr(scu_iocr_reset_value)
    , m_scu_out(scu_out_reset_value)
    , m_scu_omr(scu_omr_reset_value)
    , m_scu_in(scu_in_reset_value)
    , m_scu_ststat(scu_ststat_reset_value)
    , m_scu_stcon(scu_stcon_reset_value)
    , m_scu_pmcsr0(scu_pmcsr0_reset_value)
    , m_scu_pmcsr1(scu_pmcsr1_reset_value)
    , m_scu_pmcsr2(scu_pmcsr2_reset_value)
    , m_scu_pmcsr3(scu_pmcsr3_reset_value)
    , m_scu_pmcsr4(scu_pmcsr4_reset_value)
    , m_scu_pmcsr5(scu_pmcsr5_reset_value)
    , m_scu_pmstat0(scu_pmstat0_reset_value)
    , m_scu_pmswcr1(scu_pmswcr1_reset_value)
    , m_scu_emsr(scu_emsr_reset_value)
    , m_scu_emssw(scu_emssw_reset_value)
    , m_scu_dtscstat(scu_dtscstat_reset_value)
    , m_scu_dtsclim(scu_dtsclim_reset_value)
    , m_scu_trapdis1(scu_trapdis1_reset_value)
    , m_scu_trapstat(scu_trapstat_reset_value)
    , m_scu_trapset(scu_trapset_reset_value)
    , m_scu_trapclr(scu_trapclr_reset_value)
    , m_scu_trapdis0(scu_trapdis0_reset_value)
    , m_scu_lclcon0(scu_lclcon0_reset_value)
    , m_scu_lclcon1(scu_lclcon1_reset_value)
    , m_scu_lcltest(scu_lcltest_reset_value)
    , m_scu_chipid(scu_chipid_reset_value)
    , m_scu_manid(scu_manid_reset_value)
    , m_scu_swapctrl(scu_swapctrl_reset_value)
    , m_scu_lbistctrl0(scu_lbistctrl0_reset_value)
    , m_scu_lbistctrl1(scu_lbistctrl1_reset_value)
    , m_scu_lbistctrl2(scu_lbistctrl2_reset_value)
    , m_scu_lbistctrl3(scu_lbistctrl3_reset_value)
    , m_scu_stmem1(scu_stmem1_reset_value)
    , m_scu_stmem2(scu_stmem2_reset_value)
    , m_scu_pdisc(scu_pdisc_reset_value)
    , m_scu_pmtrcsr0(scu_pmtrcsr0_reset_value)
    , m_scu_pmtrcsr1(scu_pmtrcsr1_reset_value)
    , m_scu_pmtrcsr2(scu_pmtrcsr2_reset_value)
    , m_scu_pmtrcsr3(scu_pmtrcsr3_reset_value)
    , m_scu_stmem3(scu_stmem3_reset_value)
    , m_scu_stmem4(scu_stmem4_reset_value)
    , m_scu_stmem5(scu_stmem5_reset_value)
    , m_scu_stmem6(scu_stmem6_reset_value)
    , m_scu_ovcenable(scu_ovcenable_reset_value)
    , m_scu_ovccon(scu_ovccon_reset_value)
    , m_scu_eifilt(scu_eifilt_reset_value)
    , m_scu_eifr(scu_eifr_reset_value)
    , m_scu_fmr(scu_fmr_reset_value)
    , m_scu_pdrr(scu_pdrr_reset_value)
    , m_scu_wdtcpu0_con0(scu_wdtcpu0_con0_reset_value)
    , m_scu_eicon0(scu_eicon0_reset_value)
    , m_scu_eicon1(scu_eicon1_reset_value)
    , m_scu_eisr(scu_eisr_reset_value)
    , m_scu_wdts_con0(scu_wdts_con0_reset_value)
    , m_scu_wdts_con1(scu_wdts_con1_reset_value)
    , m_scu_wdts_sr(scu_wdts_sr_reset_value)
    , m_scu_seicon0(scu_seicon0_reset_value)
    , m_scu_seicon1(scu_seicon1_reset_value)
    , m_scu_seisr(scu_seisr_reset_value)
    , m_scu_accen11(scu_accen11_reset_value)
    , m_scu_accen10(scu_accen10_reset_value)
    , m_scu_accen01(scu_accen01_reset_value)
    , m_scu_accen00(scu_accen00_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Peripherals::Scu::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - scu_memory_start_address;
    switch (offset) {
    case reg_scu_id_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_osccon_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_OSCCON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_osccon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_syspllstat_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_SYSPLLSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_syspllstat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_syspllcon0_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_SYSPLLCON0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_syspllcon0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_syspllcon1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_SYSPLLCON1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_syspllcon1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_syspllcon2_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_SYSPLLCON2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_syspllcon2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_perpllstat_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PERPLLSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_perpllstat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_perpllcon0_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PERPLLCON0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_perpllcon0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_perpllcon1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PERPLLCON1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_perpllcon1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_ccucon0_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_CCUCON0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_ccucon0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_ccucon1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_CCUCON1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_ccucon1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_fdr_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_FDR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_fdr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_extcon_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_EXTCON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_extcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_ccucon2_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_CCUCON2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_ccucon2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_ccucon3_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_CCUCON3 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_ccucon3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_ccucon4_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_CCUCON4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_ccucon4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_ccucon5_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_CCUCON5 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_ccucon5);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_rststat_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_RSTSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_rststat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_rstcon_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_RSTCON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_rstcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_arstdis_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_ARSTDIS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_arstdis);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_swrstcon_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_SWRSTCON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_swrstcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_rstcon2_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_RSTCON2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_rstcon2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_rstcon3_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_RSTCON3 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_rstcon3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_esrocfg_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_ESROCFG in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_esrocfg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_syscon_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_SYSCON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_syscon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_ccucon6_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_CCUCON6 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_ccucon6);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_ccucon7_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_CCUCON7 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_ccucon7);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pdr_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PDR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pdr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_iocr_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_IOCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_iocr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_out_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_OUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_out);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_omr_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_OMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_omr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_in_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_IN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_in);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_ststat_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_STSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_ststat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_stcon_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_STCON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_stcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pmcsr0_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PMCSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pmcsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pmcsr1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PMCSR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pmcsr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pmcsr2_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PMCSR2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pmcsr2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pmcsr3_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PMCSR3 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pmcsr3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pmcsr4_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PMCSR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pmcsr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pmcsr5_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PMCSR5 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pmcsr5);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pmstat0_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PMSTAT0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pmstat0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pmswcr1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PMSWCR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pmswcr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_emsr_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_EMSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_emsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_emssw_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_EMSSW in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_emssw);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_dtscstat_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_DTSCSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_dtscstat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_dtsclim_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_DTSCLIM in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_dtsclim);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_trapdis1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_TRAPDIS1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_trapdis1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_trapstat_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_TRAPSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_trapstat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_trapset_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_TRAPSET in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_trapset);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_trapclr_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_TRAPCLR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_trapclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_trapdis0_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_TRAPDIS0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_trapdis0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_lclcon0_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_LCLCON0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_lclcon0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_lclcon1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_LCLCON1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_lclcon1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_lcltest_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_LCLTEST in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_lcltest);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_chipid_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_CHIPID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_chipid);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_manid_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_MANID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_manid);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_swapctrl_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_SWAPCTRL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_swapctrl);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_lbistctrl0_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_LBISTCTRL0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_lbistctrl0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_lbistctrl1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_LBISTCTRL1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_lbistctrl1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_lbistctrl2_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_LBISTCTRL2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_lbistctrl2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_lbistctrl3_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_LBISTCTRL3 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_lbistctrl3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_stmem1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_STMEM1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_stmem1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_stmem2_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_STMEM2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_stmem2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pdisc_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PDISC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pdisc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pmtrcsr0_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PMTRCSR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pmtrcsr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pmtrcsr1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PMTRCSR1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pmtrcsr1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pmtrcsr2_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PMTRCSR2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pmtrcsr2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pmtrcsr3_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PMTRCSR3 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pmtrcsr3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_stmem3_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_STMEM3 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_stmem3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_stmem4_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_STMEM4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_stmem4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_stmem5_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_STMEM5 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_stmem5);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_stmem6_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_STMEM6 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_stmem6);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_ovcenable_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_OVCENABLE in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_ovcenable);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_ovccon_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_OVCCON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_ovccon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_eifilt_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_EIFILT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_eifilt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_eifr_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_EIFR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_eifr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_fmr_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_FMR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_fmr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_pdrr_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_PDRR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_pdrr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_wdtcpu0_con0_offset: {
            spdlog::debug("SCU: accessing SCU.WDTCPU0_CON0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_wdtcpu0_con0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_eicon0_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_EICON0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_eicon0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_eicon1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_EICON1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_eicon1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_eisr_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_EISR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_eisr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_wdts_con0_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_WDTS_CON0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_wdts_con0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_wdts_con1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_WDTS_CON1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_wdts_con1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_wdts_sr_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_WDTS_SR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_wdts_sr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_seicon0_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_SEICON0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_seicon0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_seicon1_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_SEICON1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_seicon1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_seisr_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_SEISR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_seisr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_accen11_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_ACCEN11 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_accen11);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_accen10_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_ACCEN10 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_accen10);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_accen01_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_ACCEN01 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_accen01);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_scu_accen00_offset: {
            spdlog::debug("SCU: accessing SCU.SCU_ACCEN00 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_scu_accen00);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Scu peripheral", address)};
        break;
    }
}

void Tricore::Peripherals::Scu::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - scu_memory_start_address;
    switch (offset) {
    case reg_scu_id_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_id));
    } break;
    case reg_scu_osccon_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_OSCCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_osccon));
    } break;
    case reg_scu_syspllstat_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_SYSPLLSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_syspllstat));
    } break;
    case reg_scu_syspllcon0_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_SYSPLLCON0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_syspllcon0));
    } break;
    case reg_scu_syspllcon1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_SYSPLLCON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_syspllcon1));
    } break;
    case reg_scu_syspllcon2_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_SYSPLLCON2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_syspllcon2));
    } break;
    case reg_scu_perpllstat_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PERPLLSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_perpllstat));
    } break;
    case reg_scu_perpllcon0_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PERPLLCON0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_perpllcon0));
    } break;
    case reg_scu_perpllcon1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PERPLLCON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_perpllcon1));
    } break;
    case reg_scu_ccucon0_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_CCUCON0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_ccucon0));
    } break;
    case reg_scu_ccucon1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_CCUCON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_ccucon1));
    } break;
    case reg_scu_fdr_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_FDR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_fdr));
    } break;
    case reg_scu_extcon_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_EXTCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_extcon));
    } break;
    case reg_scu_ccucon2_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_CCUCON2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_ccucon2));
    } break;
    case reg_scu_ccucon3_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_CCUCON3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_ccucon3));
    } break;
    case reg_scu_ccucon4_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_CCUCON4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_ccucon4));
    } break;
    case reg_scu_ccucon5_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_CCUCON5 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_ccucon5));
    } break;
    case reg_scu_rststat_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_RSTSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_rststat));
    } break;
    case reg_scu_rstcon_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_RSTCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_rstcon));
    } break;
    case reg_scu_arstdis_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_ARSTDIS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_arstdis));
    } break;
    case reg_scu_swrstcon_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_SWRSTCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_swrstcon));
    } break;
    case reg_scu_rstcon2_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_RSTCON2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_rstcon2));
    } break;
    case reg_scu_rstcon3_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_RSTCON3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_rstcon3));
    } break;
    case reg_scu_esrocfg_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_ESROCFG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_esrocfg));
    } break;
    case reg_scu_syscon_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_SYSCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_syscon));
    } break;
    case reg_scu_ccucon6_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_CCUCON6 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_ccucon6));
    } break;
    case reg_scu_ccucon7_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_CCUCON7 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_ccucon7));
    } break;
    case reg_scu_pdr_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PDR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pdr));
    } break;
    case reg_scu_iocr_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_IOCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_iocr));
    } break;
    case reg_scu_out_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_OUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_out));
    } break;
    case reg_scu_omr_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_OMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_omr));
    } break;
    case reg_scu_in_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_IN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_in));
    } break;
    case reg_scu_ststat_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_STSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_ststat));
    } break;
    case reg_scu_stcon_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_STCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_stcon));
    } break;
    case reg_scu_pmcsr0_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PMCSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pmcsr0));
    } break;
    case reg_scu_pmcsr1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PMCSR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pmcsr1));
    } break;
    case reg_scu_pmcsr2_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PMCSR2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pmcsr2));
    } break;
    case reg_scu_pmcsr3_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PMCSR3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pmcsr3));
    } break;
    case reg_scu_pmcsr4_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PMCSR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pmcsr4));
    } break;
    case reg_scu_pmcsr5_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PMCSR5 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pmcsr5));
    } break;
    case reg_scu_pmstat0_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PMSTAT0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pmstat0));
    } break;
    case reg_scu_pmswcr1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PMSWCR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pmswcr1));
    } break;
    case reg_scu_emsr_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_EMSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_emsr));
    } break;
    case reg_scu_emssw_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_EMSSW in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_emssw));
    } break;
    case reg_scu_dtscstat_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_DTSCSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_dtscstat));
    } break;
    case reg_scu_dtsclim_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_DTSCLIM in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_dtsclim));
    } break;
    case reg_scu_trapdis1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_TRAPDIS1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_trapdis1));
    } break;
    case reg_scu_trapstat_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_TRAPSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_trapstat));
    } break;
    case reg_scu_trapset_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_TRAPSET in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_trapset));
    } break;
    case reg_scu_trapclr_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_TRAPCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_trapclr));
    } break;
    case reg_scu_trapdis0_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_TRAPDIS0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_trapdis0));
    } break;
    case reg_scu_lclcon0_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_LCLCON0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_lclcon0));
    } break;
    case reg_scu_lclcon1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_LCLCON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_lclcon1));
    } break;
    case reg_scu_lcltest_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_LCLTEST in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_lcltest));
    } break;
    case reg_scu_chipid_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_CHIPID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_chipid));
    } break;
    case reg_scu_manid_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_MANID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_manid));
    } break;
    case reg_scu_swapctrl_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_SWAPCTRL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_swapctrl));
    } break;
    case reg_scu_lbistctrl0_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_LBISTCTRL0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_lbistctrl0));
    } break;
    case reg_scu_lbistctrl1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_LBISTCTRL1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_lbistctrl1));
    } break;
    case reg_scu_lbistctrl2_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_LBISTCTRL2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_lbistctrl2));
    } break;
    case reg_scu_lbistctrl3_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_LBISTCTRL3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_lbistctrl3));
    } break;
    case reg_scu_stmem1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_STMEM1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_stmem1));
    } break;
    case reg_scu_stmem2_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_STMEM2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_stmem2));
    } break;
    case reg_scu_pdisc_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PDISC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pdisc));
    } break;
    case reg_scu_pmtrcsr0_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PMTRCSR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pmtrcsr0));
    } break;
    case reg_scu_pmtrcsr1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PMTRCSR1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pmtrcsr1));
    } break;
    case reg_scu_pmtrcsr2_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PMTRCSR2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pmtrcsr2));
    } break;
    case reg_scu_pmtrcsr3_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PMTRCSR3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pmtrcsr3));
    } break;
    case reg_scu_stmem3_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_STMEM3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_stmem3));
    } break;
    case reg_scu_stmem4_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_STMEM4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_stmem4));
    } break;
    case reg_scu_stmem5_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_STMEM5 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_stmem5));
    } break;
    case reg_scu_stmem6_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_STMEM6 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_stmem6));
    } break;
    case reg_scu_ovcenable_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_OVCENABLE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_ovcenable));
    } break;
    case reg_scu_ovccon_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_OVCCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_ovccon));
    } break;
    case reg_scu_eifilt_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_EIFILT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_eifilt));
    } break;
    case reg_scu_eifr_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_EIFR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_eifr));
    } break;
    case reg_scu_fmr_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_FMR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_fmr));
    } break;
    case reg_scu_pdrr_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_PDRR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_pdrr));
    } break;
    case reg_scu_wdtcpu0_con0_offset: {
        spdlog::debug("SCU: accessing SCU.WDTCPU0_CON' in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_wdtcpu0_con0));
    } break;
    case reg_scu_eicon0_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_EICON0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_eicon0));
    } break;
    case reg_scu_eicon1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_EICON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_eicon1));
    } break;
    case reg_scu_eisr_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_EISR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_eisr));
    } break;
    case reg_scu_wdts_con0_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_WDTS_CON0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_wdts_con0));
    } break;
    case reg_scu_wdts_con1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_WDTS_CON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_wdts_con1));
    } break;
    case reg_scu_wdts_sr_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_WDTS_SR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_wdts_sr));
    } break;
    case reg_scu_seicon0_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_SEICON0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_seicon0));
    } break;
    case reg_scu_seicon1_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_SEICON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_seicon1));
    } break;
    case reg_scu_seisr_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_SEISR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_seisr));
    } break;
    case reg_scu_accen11_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_ACCEN11 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_accen11));
    } break;
    case reg_scu_accen10_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_ACCEN10 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_accen10));
    } break;
    case reg_scu_accen01_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_ACCEN01 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_accen01));
    } break;
    case reg_scu_accen00_offset: {
        spdlog::debug("SCU: accessing SCU.SCU_ACCEN00 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_scu_accen00));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Scu peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
