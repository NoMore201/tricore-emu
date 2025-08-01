
/**
 * @brief Module source for Qspi peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Qspi.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 qspi0_clc_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_pisel_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_id_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_globalcon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_globalcon1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_bacon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_status_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_status1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_ssoc_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_xxlcon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_mixentry_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_baconentry_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_rxexit_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_rxexitd_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_mc_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_mccon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi0_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_clc_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_pisel_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_id_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_globalcon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_globalcon1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_bacon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_status_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_status1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_ssoc_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_xxlcon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_mixentry_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_baconentry_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_rxexit_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_rxexitd_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_mc_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_mccon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi1_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_clc_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_pisel_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_id_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_globalcon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_globalcon1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_bacon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_status_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_status1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_ssoc_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_xxlcon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_mixentry_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_baconentry_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_rxexit_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_rxexitd_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_capcon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_mc_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_mccon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi2_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_clc_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_pisel_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_id_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_globalcon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_globalcon1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_bacon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_status_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_status1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_ssoc_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_xxlcon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_mixentry_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_baconentry_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_rxexit_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_rxexitd_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_capcon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_mc_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_mccon_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 qspi3_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 qspi_memory_start_address = 0xf0001c00U;
constexpr u32 qspi_memory_size = 0; // TODO: update according manual;
constexpr u32 qspi_memory_end_address = qspi_memory_start_address + qspi_memory_size;

constexpr u32 reg_qspi0_clc_address = 0xf0001c00;
constexpr u32 reg_qspi0_clc_offset = reg_qspi0_clc_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_pisel_address = 0xf0001c04;
constexpr u32 reg_qspi0_pisel_offset = reg_qspi0_pisel_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_id_address = 0xf0001c08;
constexpr u32 reg_qspi0_id_offset = reg_qspi0_id_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_globalcon_address = 0xf0001c10;
constexpr u32 reg_qspi0_globalcon_offset = reg_qspi0_globalcon_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_globalcon1_address = 0xf0001c14;
constexpr u32 reg_qspi0_globalcon1_offset = reg_qspi0_globalcon1_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_bacon_address = 0xf0001c18;
constexpr u32 reg_qspi0_bacon_offset = reg_qspi0_bacon_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_status_address = 0xf0001c40;
constexpr u32 reg_qspi0_status_offset = reg_qspi0_status_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_status1_address = 0xf0001c44;
constexpr u32 reg_qspi0_status1_offset = reg_qspi0_status1_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_ssoc_address = 0xf0001c48;
constexpr u32 reg_qspi0_ssoc_offset = reg_qspi0_ssoc_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_flagsclear_address = 0xf0001c54;
constexpr u32 reg_qspi0_flagsclear_offset = reg_qspi0_flagsclear_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_xxlcon_address = 0xf0001c58;
constexpr u32 reg_qspi0_xxlcon_offset = reg_qspi0_xxlcon_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_mixentry_address = 0xf0001c5c;
constexpr u32 reg_qspi0_mixentry_offset = reg_qspi0_mixentry_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_baconentry_address = 0xf0001c60;
constexpr u32 reg_qspi0_baconentry_offset = reg_qspi0_baconentry_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_rxexit_address = 0xf0001c90;
constexpr u32 reg_qspi0_rxexit_offset = reg_qspi0_rxexit_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_rxexitd_address = 0xf0001c94;
constexpr u32 reg_qspi0_rxexitd_offset = reg_qspi0_rxexitd_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_mc_address = 0xf0001ca4;
constexpr u32 reg_qspi0_mc_offset = reg_qspi0_mc_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_mccon_address = 0xf0001ca8;
constexpr u32 reg_qspi0_mccon_offset = reg_qspi0_mccon_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_ocs_address = 0xf0001ce8;
constexpr u32 reg_qspi0_ocs_offset = reg_qspi0_ocs_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_krstclr_address = 0xf0001cec;
constexpr u32 reg_qspi0_krstclr_offset = reg_qspi0_krstclr_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_krst1_address = 0xf0001cf0;
constexpr u32 reg_qspi0_krst1_offset = reg_qspi0_krst1_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_krst0_address = 0xf0001cf4;
constexpr u32 reg_qspi0_krst0_offset = reg_qspi0_krst0_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_accen1_address = 0xf0001cf8;
constexpr u32 reg_qspi0_accen1_offset = reg_qspi0_accen1_address - qspi_memory_start_address;
constexpr u32 reg_qspi0_accen0_address = 0xf0001cfc;
constexpr u32 reg_qspi0_accen0_offset = reg_qspi0_accen0_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_clc_address = 0xf0001d00;
constexpr u32 reg_qspi1_clc_offset = reg_qspi1_clc_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_pisel_address = 0xf0001d04;
constexpr u32 reg_qspi1_pisel_offset = reg_qspi1_pisel_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_id_address = 0xf0001d08;
constexpr u32 reg_qspi1_id_offset = reg_qspi1_id_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_globalcon_address = 0xf0001d10;
constexpr u32 reg_qspi1_globalcon_offset = reg_qspi1_globalcon_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_globalcon1_address = 0xf0001d14;
constexpr u32 reg_qspi1_globalcon1_offset = reg_qspi1_globalcon1_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_bacon_address = 0xf0001d18;
constexpr u32 reg_qspi1_bacon_offset = reg_qspi1_bacon_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_status_address = 0xf0001d40;
constexpr u32 reg_qspi1_status_offset = reg_qspi1_status_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_status1_address = 0xf0001d44;
constexpr u32 reg_qspi1_status1_offset = reg_qspi1_status1_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_ssoc_address = 0xf0001d48;
constexpr u32 reg_qspi1_ssoc_offset = reg_qspi1_ssoc_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_flagsclear_address = 0xf0001d54;
constexpr u32 reg_qspi1_flagsclear_offset = reg_qspi1_flagsclear_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_xxlcon_address = 0xf0001d58;
constexpr u32 reg_qspi1_xxlcon_offset = reg_qspi1_xxlcon_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_mixentry_address = 0xf0001d5c;
constexpr u32 reg_qspi1_mixentry_offset = reg_qspi1_mixentry_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_baconentry_address = 0xf0001d60;
constexpr u32 reg_qspi1_baconentry_offset = reg_qspi1_baconentry_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_rxexit_address = 0xf0001d90;
constexpr u32 reg_qspi1_rxexit_offset = reg_qspi1_rxexit_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_rxexitd_address = 0xf0001d94;
constexpr u32 reg_qspi1_rxexitd_offset = reg_qspi1_rxexitd_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_mc_address = 0xf0001da4;
constexpr u32 reg_qspi1_mc_offset = reg_qspi1_mc_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_mccon_address = 0xf0001da8;
constexpr u32 reg_qspi1_mccon_offset = reg_qspi1_mccon_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_ocs_address = 0xf0001de8;
constexpr u32 reg_qspi1_ocs_offset = reg_qspi1_ocs_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_krstclr_address = 0xf0001dec;
constexpr u32 reg_qspi1_krstclr_offset = reg_qspi1_krstclr_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_krst1_address = 0xf0001df0;
constexpr u32 reg_qspi1_krst1_offset = reg_qspi1_krst1_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_krst0_address = 0xf0001df4;
constexpr u32 reg_qspi1_krst0_offset = reg_qspi1_krst0_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_accen1_address = 0xf0001df8;
constexpr u32 reg_qspi1_accen1_offset = reg_qspi1_accen1_address - qspi_memory_start_address;
constexpr u32 reg_qspi1_accen0_address = 0xf0001dfc;
constexpr u32 reg_qspi1_accen0_offset = reg_qspi1_accen0_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_clc_address = 0xf0001e00;
constexpr u32 reg_qspi2_clc_offset = reg_qspi2_clc_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_pisel_address = 0xf0001e04;
constexpr u32 reg_qspi2_pisel_offset = reg_qspi2_pisel_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_id_address = 0xf0001e08;
constexpr u32 reg_qspi2_id_offset = reg_qspi2_id_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_globalcon_address = 0xf0001e10;
constexpr u32 reg_qspi2_globalcon_offset = reg_qspi2_globalcon_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_globalcon1_address = 0xf0001e14;
constexpr u32 reg_qspi2_globalcon1_offset = reg_qspi2_globalcon1_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_bacon_address = 0xf0001e18;
constexpr u32 reg_qspi2_bacon_offset = reg_qspi2_bacon_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_status_address = 0xf0001e40;
constexpr u32 reg_qspi2_status_offset = reg_qspi2_status_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_status1_address = 0xf0001e44;
constexpr u32 reg_qspi2_status1_offset = reg_qspi2_status1_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_ssoc_address = 0xf0001e48;
constexpr u32 reg_qspi2_ssoc_offset = reg_qspi2_ssoc_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_flagsclear_address = 0xf0001e54;
constexpr u32 reg_qspi2_flagsclear_offset = reg_qspi2_flagsclear_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_xxlcon_address = 0xf0001e58;
constexpr u32 reg_qspi2_xxlcon_offset = reg_qspi2_xxlcon_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_mixentry_address = 0xf0001e5c;
constexpr u32 reg_qspi2_mixentry_offset = reg_qspi2_mixentry_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_baconentry_address = 0xf0001e60;
constexpr u32 reg_qspi2_baconentry_offset = reg_qspi2_baconentry_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_rxexit_address = 0xf0001e90;
constexpr u32 reg_qspi2_rxexit_offset = reg_qspi2_rxexit_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_rxexitd_address = 0xf0001e94;
constexpr u32 reg_qspi2_rxexitd_offset = reg_qspi2_rxexitd_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_capcon_address = 0xf0001ea0;
constexpr u32 reg_qspi2_capcon_offset = reg_qspi2_capcon_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_mc_address = 0xf0001ea4;
constexpr u32 reg_qspi2_mc_offset = reg_qspi2_mc_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_mccon_address = 0xf0001ea8;
constexpr u32 reg_qspi2_mccon_offset = reg_qspi2_mccon_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_ocs_address = 0xf0001ee8;
constexpr u32 reg_qspi2_ocs_offset = reg_qspi2_ocs_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_krstclr_address = 0xf0001eec;
constexpr u32 reg_qspi2_krstclr_offset = reg_qspi2_krstclr_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_krst1_address = 0xf0001ef0;
constexpr u32 reg_qspi2_krst1_offset = reg_qspi2_krst1_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_krst0_address = 0xf0001ef4;
constexpr u32 reg_qspi2_krst0_offset = reg_qspi2_krst0_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_accen1_address = 0xf0001ef8;
constexpr u32 reg_qspi2_accen1_offset = reg_qspi2_accen1_address - qspi_memory_start_address;
constexpr u32 reg_qspi2_accen0_address = 0xf0001efc;
constexpr u32 reg_qspi2_accen0_offset = reg_qspi2_accen0_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_clc_address = 0xf0001f00;
constexpr u32 reg_qspi3_clc_offset = reg_qspi3_clc_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_pisel_address = 0xf0001f04;
constexpr u32 reg_qspi3_pisel_offset = reg_qspi3_pisel_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_id_address = 0xf0001f08;
constexpr u32 reg_qspi3_id_offset = reg_qspi3_id_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_globalcon_address = 0xf0001f10;
constexpr u32 reg_qspi3_globalcon_offset = reg_qspi3_globalcon_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_globalcon1_address = 0xf0001f14;
constexpr u32 reg_qspi3_globalcon1_offset = reg_qspi3_globalcon1_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_bacon_address = 0xf0001f18;
constexpr u32 reg_qspi3_bacon_offset = reg_qspi3_bacon_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_status_address = 0xf0001f40;
constexpr u32 reg_qspi3_status_offset = reg_qspi3_status_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_status1_address = 0xf0001f44;
constexpr u32 reg_qspi3_status1_offset = reg_qspi3_status1_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_ssoc_address = 0xf0001f48;
constexpr u32 reg_qspi3_ssoc_offset = reg_qspi3_ssoc_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_flagsclear_address = 0xf0001f54;
constexpr u32 reg_qspi3_flagsclear_offset = reg_qspi3_flagsclear_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_xxlcon_address = 0xf0001f58;
constexpr u32 reg_qspi3_xxlcon_offset = reg_qspi3_xxlcon_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_mixentry_address = 0xf0001f5c;
constexpr u32 reg_qspi3_mixentry_offset = reg_qspi3_mixentry_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_baconentry_address = 0xf0001f60;
constexpr u32 reg_qspi3_baconentry_offset = reg_qspi3_baconentry_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_rxexit_address = 0xf0001f90;
constexpr u32 reg_qspi3_rxexit_offset = reg_qspi3_rxexit_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_rxexitd_address = 0xf0001f94;
constexpr u32 reg_qspi3_rxexitd_offset = reg_qspi3_rxexitd_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_capcon_address = 0xf0001fa0;
constexpr u32 reg_qspi3_capcon_offset = reg_qspi3_capcon_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_mc_address = 0xf0001fa4;
constexpr u32 reg_qspi3_mc_offset = reg_qspi3_mc_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_mccon_address = 0xf0001fa8;
constexpr u32 reg_qspi3_mccon_offset = reg_qspi3_mccon_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_ocs_address = 0xf0001fe8;
constexpr u32 reg_qspi3_ocs_offset = reg_qspi3_ocs_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_krstclr_address = 0xf0001fec;
constexpr u32 reg_qspi3_krstclr_offset = reg_qspi3_krstclr_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_krst1_address = 0xf0001ff0;
constexpr u32 reg_qspi3_krst1_offset = reg_qspi3_krst1_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_krst0_address = 0xf0001ff4;
constexpr u32 reg_qspi3_krst0_offset = reg_qspi3_krst0_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_accen1_address = 0xf0001ff8;
constexpr u32 reg_qspi3_accen1_offset = reg_qspi3_accen1_address - qspi_memory_start_address;
constexpr u32 reg_qspi3_accen0_address = 0xf0001ffc;
constexpr u32 reg_qspi3_accen0_offset = reg_qspi3_accen0_address - qspi_memory_start_address;

} // anonymous namespace

Tricore::Qspi::Qspi()
    : m_qspi0_clc(qspi0_clc_reset_value)
    , m_qspi0_pisel(qspi0_pisel_reset_value)
    , m_qspi0_id(qspi0_id_reset_value)
    , m_qspi0_globalcon(qspi0_globalcon_reset_value)
    , m_qspi0_globalcon1(qspi0_globalcon1_reset_value)
    , m_qspi0_bacon(qspi0_bacon_reset_value)
    , m_qspi0_status(qspi0_status_reset_value)
    , m_qspi0_status1(qspi0_status1_reset_value)
    , m_qspi0_ssoc(qspi0_ssoc_reset_value)
    , m_qspi0_flagsclear(qspi0_flagsclear_reset_value)
    , m_qspi0_xxlcon(qspi0_xxlcon_reset_value)
    , m_qspi0_mixentry(qspi0_mixentry_reset_value)
    , m_qspi0_baconentry(qspi0_baconentry_reset_value)
    , m_qspi0_rxexit(qspi0_rxexit_reset_value)
    , m_qspi0_rxexitd(qspi0_rxexitd_reset_value)
    , m_qspi0_mc(qspi0_mc_reset_value)
    , m_qspi0_mccon(qspi0_mccon_reset_value)
    , m_qspi0_ocs(qspi0_ocs_reset_value)
    , m_qspi0_krstclr(qspi0_krstclr_reset_value)
    , m_qspi0_krst1(qspi0_krst1_reset_value)
    , m_qspi0_krst0(qspi0_krst0_reset_value)
    , m_qspi0_accen1(qspi0_accen1_reset_value)
    , m_qspi0_accen0(qspi0_accen0_reset_value)
    , m_qspi1_clc(qspi1_clc_reset_value)
    , m_qspi1_pisel(qspi1_pisel_reset_value)
    , m_qspi1_id(qspi1_id_reset_value)
    , m_qspi1_globalcon(qspi1_globalcon_reset_value)
    , m_qspi1_globalcon1(qspi1_globalcon1_reset_value)
    , m_qspi1_bacon(qspi1_bacon_reset_value)
    , m_qspi1_status(qspi1_status_reset_value)
    , m_qspi1_status1(qspi1_status1_reset_value)
    , m_qspi1_ssoc(qspi1_ssoc_reset_value)
    , m_qspi1_flagsclear(qspi1_flagsclear_reset_value)
    , m_qspi1_xxlcon(qspi1_xxlcon_reset_value)
    , m_qspi1_mixentry(qspi1_mixentry_reset_value)
    , m_qspi1_baconentry(qspi1_baconentry_reset_value)
    , m_qspi1_rxexit(qspi1_rxexit_reset_value)
    , m_qspi1_rxexitd(qspi1_rxexitd_reset_value)
    , m_qspi1_mc(qspi1_mc_reset_value)
    , m_qspi1_mccon(qspi1_mccon_reset_value)
    , m_qspi1_ocs(qspi1_ocs_reset_value)
    , m_qspi1_krstclr(qspi1_krstclr_reset_value)
    , m_qspi1_krst1(qspi1_krst1_reset_value)
    , m_qspi1_krst0(qspi1_krst0_reset_value)
    , m_qspi1_accen1(qspi1_accen1_reset_value)
    , m_qspi1_accen0(qspi1_accen0_reset_value)
    , m_qspi2_clc(qspi2_clc_reset_value)
    , m_qspi2_pisel(qspi2_pisel_reset_value)
    , m_qspi2_id(qspi2_id_reset_value)
    , m_qspi2_globalcon(qspi2_globalcon_reset_value)
    , m_qspi2_globalcon1(qspi2_globalcon1_reset_value)
    , m_qspi2_bacon(qspi2_bacon_reset_value)
    , m_qspi2_status(qspi2_status_reset_value)
    , m_qspi2_status1(qspi2_status1_reset_value)
    , m_qspi2_ssoc(qspi2_ssoc_reset_value)
    , m_qspi2_flagsclear(qspi2_flagsclear_reset_value)
    , m_qspi2_xxlcon(qspi2_xxlcon_reset_value)
    , m_qspi2_mixentry(qspi2_mixentry_reset_value)
    , m_qspi2_baconentry(qspi2_baconentry_reset_value)
    , m_qspi2_rxexit(qspi2_rxexit_reset_value)
    , m_qspi2_rxexitd(qspi2_rxexitd_reset_value)
    , m_qspi2_capcon(qspi2_capcon_reset_value)
    , m_qspi2_mc(qspi2_mc_reset_value)
    , m_qspi2_mccon(qspi2_mccon_reset_value)
    , m_qspi2_ocs(qspi2_ocs_reset_value)
    , m_qspi2_krstclr(qspi2_krstclr_reset_value)
    , m_qspi2_krst1(qspi2_krst1_reset_value)
    , m_qspi2_krst0(qspi2_krst0_reset_value)
    , m_qspi2_accen1(qspi2_accen1_reset_value)
    , m_qspi2_accen0(qspi2_accen0_reset_value)
    , m_qspi3_clc(qspi3_clc_reset_value)
    , m_qspi3_pisel(qspi3_pisel_reset_value)
    , m_qspi3_id(qspi3_id_reset_value)
    , m_qspi3_globalcon(qspi3_globalcon_reset_value)
    , m_qspi3_globalcon1(qspi3_globalcon1_reset_value)
    , m_qspi3_bacon(qspi3_bacon_reset_value)
    , m_qspi3_status(qspi3_status_reset_value)
    , m_qspi3_status1(qspi3_status1_reset_value)
    , m_qspi3_ssoc(qspi3_ssoc_reset_value)
    , m_qspi3_flagsclear(qspi3_flagsclear_reset_value)
    , m_qspi3_xxlcon(qspi3_xxlcon_reset_value)
    , m_qspi3_mixentry(qspi3_mixentry_reset_value)
    , m_qspi3_baconentry(qspi3_baconentry_reset_value)
    , m_qspi3_rxexit(qspi3_rxexit_reset_value)
    , m_qspi3_rxexitd(qspi3_rxexitd_reset_value)
    , m_qspi3_capcon(qspi3_capcon_reset_value)
    , m_qspi3_mc(qspi3_mc_reset_value)
    , m_qspi3_mccon(qspi3_mccon_reset_value)
    , m_qspi3_ocs(qspi3_ocs_reset_value)
    , m_qspi3_krstclr(qspi3_krstclr_reset_value)
    , m_qspi3_krst1(qspi3_krst1_reset_value)
    , m_qspi3_krst0(qspi3_krst0_reset_value)
    , m_qspi3_accen1(qspi3_accen1_reset_value)
    , m_qspi3_accen0(qspi3_accen0_reset_value)
{
}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Qspi::read(byte* buffer_out, u32 address, usize length)
{
    const u32 offset = address - qspi_memory_start_address;
    switch (offset) {
    case reg_qspi0_clc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_CLC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_clc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_pisel_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_PISEL in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_pisel);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_id_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_ID in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_id);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_globalcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_GLOBALCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_globalcon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_globalcon1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_GLOBALCON1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_globalcon1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_bacon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_BACON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_bacon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_status_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_STATUS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_status);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_status1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_STATUS1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_status1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_ssoc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_SSOC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_ssoc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_flagsclear_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_FLAGSCLEAR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_flagsclear);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_xxlcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_XXLCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_xxlcon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_mixentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_MIXENTRY in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_mixentry);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_baconentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_BACONENTRY in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_baconentry);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_rxexit_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_RXEXIT in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_rxexit);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_rxexitd_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_RXEXITD in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_rxexitd);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_mc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_MC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_mc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_mccon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_MCCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_mccon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_ocs_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_OCS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_ocs);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_krstclr_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_KRSTCLR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_krstclr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_krst1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_KRST1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_krst1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_krst0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_KRST0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_krst0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_accen1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_ACCEN1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_accen1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi0_accen0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_ACCEN0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi0_accen0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_clc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_CLC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_clc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_pisel_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_PISEL in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_pisel);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_id_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_ID in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_id);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_globalcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_GLOBALCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_globalcon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_globalcon1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_GLOBALCON1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_globalcon1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_bacon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_BACON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_bacon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_status_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_STATUS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_status);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_status1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_STATUS1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_status1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_ssoc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_SSOC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_ssoc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_flagsclear_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_FLAGSCLEAR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_flagsclear);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_xxlcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_XXLCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_xxlcon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_mixentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_MIXENTRY in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_mixentry);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_baconentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_BACONENTRY in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_baconentry);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_rxexit_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_RXEXIT in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_rxexit);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_rxexitd_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_RXEXITD in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_rxexitd);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_mc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_MC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_mc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_mccon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_MCCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_mccon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_ocs_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_OCS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_ocs);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_krstclr_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_KRSTCLR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_krstclr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_krst1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_KRST1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_krst1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_krst0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_KRST0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_krst0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_accen1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_ACCEN1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_accen1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi1_accen0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_ACCEN0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi1_accen0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_clc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_CLC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_clc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_pisel_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_PISEL in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_pisel);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_id_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_ID in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_id);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_globalcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_GLOBALCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_globalcon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_globalcon1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_GLOBALCON1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_globalcon1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_bacon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_BACON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_bacon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_status_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_STATUS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_status);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_status1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_STATUS1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_status1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_ssoc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_SSOC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_ssoc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_flagsclear_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_FLAGSCLEAR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_flagsclear);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_xxlcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_XXLCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_xxlcon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_mixentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_MIXENTRY in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_mixentry);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_baconentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_BACONENTRY in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_baconentry);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_rxexit_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_RXEXIT in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_rxexit);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_rxexitd_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_RXEXITD in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_rxexitd);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_capcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_CAPCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_capcon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_mc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_MC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_mc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_mccon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_MCCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_mccon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_ocs_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_OCS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_ocs);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_krstclr_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_KRSTCLR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_krstclr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_krst1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_KRST1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_krst1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_krst0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_KRST0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_krst0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_accen1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_ACCEN1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_accen1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi2_accen0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_ACCEN0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi2_accen0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_clc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_CLC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_clc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_pisel_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_PISEL in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_pisel);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_id_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_ID in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_id);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_globalcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_GLOBALCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_globalcon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_globalcon1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_GLOBALCON1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_globalcon1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_bacon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_BACON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_bacon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_status_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_STATUS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_status);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_status1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_STATUS1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_status1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_ssoc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_SSOC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_ssoc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_flagsclear_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_FLAGSCLEAR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_flagsclear);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_xxlcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_XXLCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_xxlcon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_mixentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_MIXENTRY in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_mixentry);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_baconentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_BACONENTRY in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_baconentry);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_rxexit_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_RXEXIT in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_rxexit);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_rxexitd_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_RXEXITD in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_rxexitd);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_capcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_CAPCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_capcon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_mc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_MC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_mc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_mccon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_MCCON in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_mccon);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_ocs_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_OCS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_ocs);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_krstclr_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_KRSTCLR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_krstclr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_krst1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_KRST1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_krst1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_krst0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_KRST0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_krst0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_accen1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_ACCEN1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_accen1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_qspi3_accen0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_ACCEN0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_qspi3_accen0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Qspi peripheral", address) };
        break;
    }
}

void Tricore::Qspi::write(const byte* buffer_in, u32 address,
    usize length)
{
    const u32 offset = address - qspi_memory_start_address;
    switch (offset) {
    case reg_qspi0_clc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_clc));
    } break;
    case reg_qspi0_pisel_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_PISEL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_pisel));
    } break;
    case reg_qspi0_id_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_id));
    } break;
    case reg_qspi0_globalcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_GLOBALCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_globalcon));
    } break;
    case reg_qspi0_globalcon1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_GLOBALCON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_globalcon1));
    } break;
    case reg_qspi0_bacon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_BACON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_bacon));
    } break;
    case reg_qspi0_status_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_STATUS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_status));
    } break;
    case reg_qspi0_status1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_STATUS1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_status1));
    } break;
    case reg_qspi0_ssoc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_SSOC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_ssoc));
    } break;
    case reg_qspi0_flagsclear_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_flagsclear));
    } break;
    case reg_qspi0_xxlcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_XXLCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_xxlcon));
    } break;
    case reg_qspi0_mixentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_MIXENTRY in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_mixentry));
    } break;
    case reg_qspi0_baconentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_BACONENTRY in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_baconentry));
    } break;
    case reg_qspi0_rxexit_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_RXEXIT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_rxexit));
    } break;
    case reg_qspi0_rxexitd_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_RXEXITD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_rxexitd));
    } break;
    case reg_qspi0_mc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_MC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_mc));
    } break;
    case reg_qspi0_mccon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_MCCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_mccon));
    } break;
    case reg_qspi0_ocs_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_ocs));
    } break;
    case reg_qspi0_krstclr_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_krstclr));
    } break;
    case reg_qspi0_krst1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_krst1));
    } break;
    case reg_qspi0_krst0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_krst0));
    } break;
    case reg_qspi0_accen1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_accen1));
    } break;
    case reg_qspi0_accen0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI0_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi0_accen0));
    } break;
    case reg_qspi1_clc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_clc));
    } break;
    case reg_qspi1_pisel_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_PISEL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_pisel));
    } break;
    case reg_qspi1_id_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_id));
    } break;
    case reg_qspi1_globalcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_GLOBALCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_globalcon));
    } break;
    case reg_qspi1_globalcon1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_GLOBALCON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_globalcon1));
    } break;
    case reg_qspi1_bacon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_BACON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_bacon));
    } break;
    case reg_qspi1_status_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_STATUS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_status));
    } break;
    case reg_qspi1_status1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_STATUS1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_status1));
    } break;
    case reg_qspi1_ssoc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_SSOC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_ssoc));
    } break;
    case reg_qspi1_flagsclear_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_flagsclear));
    } break;
    case reg_qspi1_xxlcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_XXLCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_xxlcon));
    } break;
    case reg_qspi1_mixentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_MIXENTRY in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_mixentry));
    } break;
    case reg_qspi1_baconentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_BACONENTRY in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_baconentry));
    } break;
    case reg_qspi1_rxexit_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_RXEXIT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_rxexit));
    } break;
    case reg_qspi1_rxexitd_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_RXEXITD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_rxexitd));
    } break;
    case reg_qspi1_mc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_MC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_mc));
    } break;
    case reg_qspi1_mccon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_MCCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_mccon));
    } break;
    case reg_qspi1_ocs_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_ocs));
    } break;
    case reg_qspi1_krstclr_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_krstclr));
    } break;
    case reg_qspi1_krst1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_krst1));
    } break;
    case reg_qspi1_krst0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_krst0));
    } break;
    case reg_qspi1_accen1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_accen1));
    } break;
    case reg_qspi1_accen0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI1_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi1_accen0));
    } break;
    case reg_qspi2_clc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_clc));
    } break;
    case reg_qspi2_pisel_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_PISEL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_pisel));
    } break;
    case reg_qspi2_id_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_id));
    } break;
    case reg_qspi2_globalcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_GLOBALCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_globalcon));
    } break;
    case reg_qspi2_globalcon1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_GLOBALCON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_globalcon1));
    } break;
    case reg_qspi2_bacon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_BACON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_bacon));
    } break;
    case reg_qspi2_status_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_STATUS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_status));
    } break;
    case reg_qspi2_status1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_STATUS1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_status1));
    } break;
    case reg_qspi2_ssoc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_SSOC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_ssoc));
    } break;
    case reg_qspi2_flagsclear_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_flagsclear));
    } break;
    case reg_qspi2_xxlcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_XXLCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_xxlcon));
    } break;
    case reg_qspi2_mixentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_MIXENTRY in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_mixentry));
    } break;
    case reg_qspi2_baconentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_BACONENTRY in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_baconentry));
    } break;
    case reg_qspi2_rxexit_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_RXEXIT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_rxexit));
    } break;
    case reg_qspi2_rxexitd_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_RXEXITD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_rxexitd));
    } break;
    case reg_qspi2_capcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_CAPCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_capcon));
    } break;
    case reg_qspi2_mc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_MC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_mc));
    } break;
    case reg_qspi2_mccon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_MCCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_mccon));
    } break;
    case reg_qspi2_ocs_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_ocs));
    } break;
    case reg_qspi2_krstclr_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_krstclr));
    } break;
    case reg_qspi2_krst1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_krst1));
    } break;
    case reg_qspi2_krst0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_krst0));
    } break;
    case reg_qspi2_accen1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_accen1));
    } break;
    case reg_qspi2_accen0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI2_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi2_accen0));
    } break;
    case reg_qspi3_clc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_clc));
    } break;
    case reg_qspi3_pisel_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_PISEL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_pisel));
    } break;
    case reg_qspi3_id_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_id));
    } break;
    case reg_qspi3_globalcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_GLOBALCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_globalcon));
    } break;
    case reg_qspi3_globalcon1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_GLOBALCON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_globalcon1));
    } break;
    case reg_qspi3_bacon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_BACON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_bacon));
    } break;
    case reg_qspi3_status_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_STATUS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_status));
    } break;
    case reg_qspi3_status1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_STATUS1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_status1));
    } break;
    case reg_qspi3_ssoc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_SSOC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_ssoc));
    } break;
    case reg_qspi3_flagsclear_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_flagsclear));
    } break;
    case reg_qspi3_xxlcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_XXLCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_xxlcon));
    } break;
    case reg_qspi3_mixentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_MIXENTRY in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_mixentry));
    } break;
    case reg_qspi3_baconentry_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_BACONENTRY in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_baconentry));
    } break;
    case reg_qspi3_rxexit_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_RXEXIT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_rxexit));
    } break;
    case reg_qspi3_rxexitd_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_RXEXITD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_rxexitd));
    } break;
    case reg_qspi3_capcon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_CAPCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_capcon));
    } break;
    case reg_qspi3_mc_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_MC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_mc));
    } break;
    case reg_qspi3_mccon_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_MCCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_mccon));
    } break;
    case reg_qspi3_ocs_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_ocs));
    } break;
    case reg_qspi3_krstclr_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_krstclr));
    } break;
    case reg_qspi3_krst1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_krst1));
    } break;
    case reg_qspi3_krst0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_krst0));
    } break;
    case reg_qspi3_accen1_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_accen1));
    } break;
    case reg_qspi3_accen0_offset: {
        spdlog::debug("QSPI: accessing QSPI.QSPI3_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_qspi3_accen0));
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Qspi peripheral", address) };
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
