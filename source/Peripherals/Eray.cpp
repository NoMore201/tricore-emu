
/**
 * @brief Module source for Eray peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Eray.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 eray0_clc_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_cust1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_id_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_cust3_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_test1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_test2_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_lck_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_eir_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_sir_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_eils_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_sils_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_eies_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_eier_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_sies_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_sier_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ile_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_t0c_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_t1c_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_stpw1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_stpw2_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_succ1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_succ2_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_succ3_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_nemc_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_prtc1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_prtc2_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_mhdc_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_gtuc01_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_gtuc02_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_gtuc03_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_gtuc04_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_gtuc05_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_gtuc06_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_gtuc07_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_gtuc08_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_gtuc09_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_gtuc10_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_gtuc11_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ccsv_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ccev_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_scv_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_mtccv_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_rcv_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ocv_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_sfs_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_swnit_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_acs_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_mrc_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_frf_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_frfm_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_fcl_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_mhds_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ldts_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_fsr_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_mhdf_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_txrq1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_txrq2_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_txrq3_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_txrq4_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ndat1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ndat2_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ndat3_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ndat4_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_mbsc1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_mbsc2_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_mbsc3_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_mbsc4_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ndic1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ndic2_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ndic3_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ndic4_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_msic1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_msic2_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_msic3_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_msic4_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_crel_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_endn_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_wrhs1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_wrhs2_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_wrhs3_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ibcm_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ibcr_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_rdhs1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_rdhs2_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_rdhs3_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_mbs_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_obcm_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_obcr_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_otss_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 eray0_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 eray_memory_start_address = 0xf001c000U;
constexpr u32 eray_memory_size = 0; // TODO: update according manual;
constexpr u32 eray_memory_end_address = eray_memory_start_address + eray_memory_size;

constexpr u32 reg_eray0_clc_address = 0xf001c000;
constexpr u32 reg_eray0_clc_offset = reg_eray0_clc_address - eray_memory_start_address;
constexpr u32 reg_eray0_cust1_address = 0xf001c004;
constexpr u32 reg_eray0_cust1_offset = reg_eray0_cust1_address - eray_memory_start_address;
constexpr u32 reg_eray0_id_address = 0xf001c008;
constexpr u32 reg_eray0_id_offset = reg_eray0_id_address - eray_memory_start_address;
constexpr u32 reg_eray0_cust3_address = 0xf001c00c;
constexpr u32 reg_eray0_cust3_offset = reg_eray0_cust3_address - eray_memory_start_address;
constexpr u32 reg_eray0_test1_address = 0xf001c010;
constexpr u32 reg_eray0_test1_offset = reg_eray0_test1_address - eray_memory_start_address;
constexpr u32 reg_eray0_test2_address = 0xf001c014;
constexpr u32 reg_eray0_test2_offset = reg_eray0_test2_address - eray_memory_start_address;
constexpr u32 reg_eray0_lck_address = 0xf001c01c;
constexpr u32 reg_eray0_lck_offset = reg_eray0_lck_address - eray_memory_start_address;
constexpr u32 reg_eray0_eir_address = 0xf001c020;
constexpr u32 reg_eray0_eir_offset = reg_eray0_eir_address - eray_memory_start_address;
constexpr u32 reg_eray0_sir_address = 0xf001c024;
constexpr u32 reg_eray0_sir_offset = reg_eray0_sir_address - eray_memory_start_address;
constexpr u32 reg_eray0_eils_address = 0xf001c028;
constexpr u32 reg_eray0_eils_offset = reg_eray0_eils_address - eray_memory_start_address;
constexpr u32 reg_eray0_sils_address = 0xf001c02c;
constexpr u32 reg_eray0_sils_offset = reg_eray0_sils_address - eray_memory_start_address;
constexpr u32 reg_eray0_eies_address = 0xf001c030;
constexpr u32 reg_eray0_eies_offset = reg_eray0_eies_address - eray_memory_start_address;
constexpr u32 reg_eray0_eier_address = 0xf001c034;
constexpr u32 reg_eray0_eier_offset = reg_eray0_eier_address - eray_memory_start_address;
constexpr u32 reg_eray0_sies_address = 0xf001c038;
constexpr u32 reg_eray0_sies_offset = reg_eray0_sies_address - eray_memory_start_address;
constexpr u32 reg_eray0_sier_address = 0xf001c03c;
constexpr u32 reg_eray0_sier_offset = reg_eray0_sier_address - eray_memory_start_address;
constexpr u32 reg_eray0_ile_address = 0xf001c040;
constexpr u32 reg_eray0_ile_offset = reg_eray0_ile_address - eray_memory_start_address;
constexpr u32 reg_eray0_t0c_address = 0xf001c044;
constexpr u32 reg_eray0_t0c_offset = reg_eray0_t0c_address - eray_memory_start_address;
constexpr u32 reg_eray0_t1c_address = 0xf001c048;
constexpr u32 reg_eray0_t1c_offset = reg_eray0_t1c_address - eray_memory_start_address;
constexpr u32 reg_eray0_stpw1_address = 0xf001c04c;
constexpr u32 reg_eray0_stpw1_offset = reg_eray0_stpw1_address - eray_memory_start_address;
constexpr u32 reg_eray0_stpw2_address = 0xf001c050;
constexpr u32 reg_eray0_stpw2_offset = reg_eray0_stpw2_address - eray_memory_start_address;
constexpr u32 reg_eray0_succ1_address = 0xf001c080;
constexpr u32 reg_eray0_succ1_offset = reg_eray0_succ1_address - eray_memory_start_address;
constexpr u32 reg_eray0_succ2_address = 0xf001c084;
constexpr u32 reg_eray0_succ2_offset = reg_eray0_succ2_address - eray_memory_start_address;
constexpr u32 reg_eray0_succ3_address = 0xf001c088;
constexpr u32 reg_eray0_succ3_offset = reg_eray0_succ3_address - eray_memory_start_address;
constexpr u32 reg_eray0_nemc_address = 0xf001c08c;
constexpr u32 reg_eray0_nemc_offset = reg_eray0_nemc_address - eray_memory_start_address;
constexpr u32 reg_eray0_prtc1_address = 0xf001c090;
constexpr u32 reg_eray0_prtc1_offset = reg_eray0_prtc1_address - eray_memory_start_address;
constexpr u32 reg_eray0_prtc2_address = 0xf001c094;
constexpr u32 reg_eray0_prtc2_offset = reg_eray0_prtc2_address - eray_memory_start_address;
constexpr u32 reg_eray0_mhdc_address = 0xf001c098;
constexpr u32 reg_eray0_mhdc_offset = reg_eray0_mhdc_address - eray_memory_start_address;
constexpr u32 reg_eray0_gtuc01_address = 0xf001c0a0;
constexpr u32 reg_eray0_gtuc01_offset = reg_eray0_gtuc01_address - eray_memory_start_address;
constexpr u32 reg_eray0_gtuc02_address = 0xf001c0a4;
constexpr u32 reg_eray0_gtuc02_offset = reg_eray0_gtuc02_address - eray_memory_start_address;
constexpr u32 reg_eray0_gtuc03_address = 0xf001c0a8;
constexpr u32 reg_eray0_gtuc03_offset = reg_eray0_gtuc03_address - eray_memory_start_address;
constexpr u32 reg_eray0_gtuc04_address = 0xf001c0ac;
constexpr u32 reg_eray0_gtuc04_offset = reg_eray0_gtuc04_address - eray_memory_start_address;
constexpr u32 reg_eray0_gtuc05_address = 0xf001c0b0;
constexpr u32 reg_eray0_gtuc05_offset = reg_eray0_gtuc05_address - eray_memory_start_address;
constexpr u32 reg_eray0_gtuc06_address = 0xf001c0b4;
constexpr u32 reg_eray0_gtuc06_offset = reg_eray0_gtuc06_address - eray_memory_start_address;
constexpr u32 reg_eray0_gtuc07_address = 0xf001c0b8;
constexpr u32 reg_eray0_gtuc07_offset = reg_eray0_gtuc07_address - eray_memory_start_address;
constexpr u32 reg_eray0_gtuc08_address = 0xf001c0bc;
constexpr u32 reg_eray0_gtuc08_offset = reg_eray0_gtuc08_address - eray_memory_start_address;
constexpr u32 reg_eray0_gtuc09_address = 0xf001c0c0;
constexpr u32 reg_eray0_gtuc09_offset = reg_eray0_gtuc09_address - eray_memory_start_address;
constexpr u32 reg_eray0_gtuc10_address = 0xf001c0c4;
constexpr u32 reg_eray0_gtuc10_offset = reg_eray0_gtuc10_address - eray_memory_start_address;
constexpr u32 reg_eray0_gtuc11_address = 0xf001c0c8;
constexpr u32 reg_eray0_gtuc11_offset = reg_eray0_gtuc11_address - eray_memory_start_address;
constexpr u32 reg_eray0_ccsv_address = 0xf001c100;
constexpr u32 reg_eray0_ccsv_offset = reg_eray0_ccsv_address - eray_memory_start_address;
constexpr u32 reg_eray0_ccev_address = 0xf001c104;
constexpr u32 reg_eray0_ccev_offset = reg_eray0_ccev_address - eray_memory_start_address;
constexpr u32 reg_eray0_scv_address = 0xf001c110;
constexpr u32 reg_eray0_scv_offset = reg_eray0_scv_address - eray_memory_start_address;
constexpr u32 reg_eray0_mtccv_address = 0xf001c114;
constexpr u32 reg_eray0_mtccv_offset = reg_eray0_mtccv_address - eray_memory_start_address;
constexpr u32 reg_eray0_rcv_address = 0xf001c118;
constexpr u32 reg_eray0_rcv_offset = reg_eray0_rcv_address - eray_memory_start_address;
constexpr u32 reg_eray0_ocv_address = 0xf001c11c;
constexpr u32 reg_eray0_ocv_offset = reg_eray0_ocv_address - eray_memory_start_address;
constexpr u32 reg_eray0_sfs_address = 0xf001c120;
constexpr u32 reg_eray0_sfs_offset = reg_eray0_sfs_address - eray_memory_start_address;
constexpr u32 reg_eray0_swnit_address = 0xf001c124;
constexpr u32 reg_eray0_swnit_offset = reg_eray0_swnit_address - eray_memory_start_address;
constexpr u32 reg_eray0_acs_address = 0xf001c128;
constexpr u32 reg_eray0_acs_offset = reg_eray0_acs_address - eray_memory_start_address;
constexpr u32 reg_eray0_mrc_address = 0xf001c300;
constexpr u32 reg_eray0_mrc_offset = reg_eray0_mrc_address - eray_memory_start_address;
constexpr u32 reg_eray0_frf_address = 0xf001c304;
constexpr u32 reg_eray0_frf_offset = reg_eray0_frf_address - eray_memory_start_address;
constexpr u32 reg_eray0_frfm_address = 0xf001c308;
constexpr u32 reg_eray0_frfm_offset = reg_eray0_frfm_address - eray_memory_start_address;
constexpr u32 reg_eray0_fcl_address = 0xf001c30c;
constexpr u32 reg_eray0_fcl_offset = reg_eray0_fcl_address - eray_memory_start_address;
constexpr u32 reg_eray0_mhds_address = 0xf001c310;
constexpr u32 reg_eray0_mhds_offset = reg_eray0_mhds_address - eray_memory_start_address;
constexpr u32 reg_eray0_ldts_address = 0xf001c314;
constexpr u32 reg_eray0_ldts_offset = reg_eray0_ldts_address - eray_memory_start_address;
constexpr u32 reg_eray0_fsr_address = 0xf001c318;
constexpr u32 reg_eray0_fsr_offset = reg_eray0_fsr_address - eray_memory_start_address;
constexpr u32 reg_eray0_mhdf_address = 0xf001c31c;
constexpr u32 reg_eray0_mhdf_offset = reg_eray0_mhdf_address - eray_memory_start_address;
constexpr u32 reg_eray0_txrq1_address = 0xf001c320;
constexpr u32 reg_eray0_txrq1_offset = reg_eray0_txrq1_address - eray_memory_start_address;
constexpr u32 reg_eray0_txrq2_address = 0xf001c324;
constexpr u32 reg_eray0_txrq2_offset = reg_eray0_txrq2_address - eray_memory_start_address;
constexpr u32 reg_eray0_txrq3_address = 0xf001c328;
constexpr u32 reg_eray0_txrq3_offset = reg_eray0_txrq3_address - eray_memory_start_address;
constexpr u32 reg_eray0_txrq4_address = 0xf001c32c;
constexpr u32 reg_eray0_txrq4_offset = reg_eray0_txrq4_address - eray_memory_start_address;
constexpr u32 reg_eray0_ndat1_address = 0xf001c330;
constexpr u32 reg_eray0_ndat1_offset = reg_eray0_ndat1_address - eray_memory_start_address;
constexpr u32 reg_eray0_ndat2_address = 0xf001c334;
constexpr u32 reg_eray0_ndat2_offset = reg_eray0_ndat2_address - eray_memory_start_address;
constexpr u32 reg_eray0_ndat3_address = 0xf001c338;
constexpr u32 reg_eray0_ndat3_offset = reg_eray0_ndat3_address - eray_memory_start_address;
constexpr u32 reg_eray0_ndat4_address = 0xf001c33c;
constexpr u32 reg_eray0_ndat4_offset = reg_eray0_ndat4_address - eray_memory_start_address;
constexpr u32 reg_eray0_mbsc1_address = 0xf001c340;
constexpr u32 reg_eray0_mbsc1_offset = reg_eray0_mbsc1_address - eray_memory_start_address;
constexpr u32 reg_eray0_mbsc2_address = 0xf001c344;
constexpr u32 reg_eray0_mbsc2_offset = reg_eray0_mbsc2_address - eray_memory_start_address;
constexpr u32 reg_eray0_mbsc3_address = 0xf001c348;
constexpr u32 reg_eray0_mbsc3_offset = reg_eray0_mbsc3_address - eray_memory_start_address;
constexpr u32 reg_eray0_mbsc4_address = 0xf001c34c;
constexpr u32 reg_eray0_mbsc4_offset = reg_eray0_mbsc4_address - eray_memory_start_address;
constexpr u32 reg_eray0_ndic1_address = 0xf001c3a8;
constexpr u32 reg_eray0_ndic1_offset = reg_eray0_ndic1_address - eray_memory_start_address;
constexpr u32 reg_eray0_ndic2_address = 0xf001c3ac;
constexpr u32 reg_eray0_ndic2_offset = reg_eray0_ndic2_address - eray_memory_start_address;
constexpr u32 reg_eray0_ndic3_address = 0xf001c3b0;
constexpr u32 reg_eray0_ndic3_offset = reg_eray0_ndic3_address - eray_memory_start_address;
constexpr u32 reg_eray0_ndic4_address = 0xf001c3b4;
constexpr u32 reg_eray0_ndic4_offset = reg_eray0_ndic4_address - eray_memory_start_address;
constexpr u32 reg_eray0_msic1_address = 0xf001c3b8;
constexpr u32 reg_eray0_msic1_offset = reg_eray0_msic1_address - eray_memory_start_address;
constexpr u32 reg_eray0_msic2_address = 0xf001c3bc;
constexpr u32 reg_eray0_msic2_offset = reg_eray0_msic2_address - eray_memory_start_address;
constexpr u32 reg_eray0_msic3_address = 0xf001c3c0;
constexpr u32 reg_eray0_msic3_offset = reg_eray0_msic3_address - eray_memory_start_address;
constexpr u32 reg_eray0_msic4_address = 0xf001c3c4;
constexpr u32 reg_eray0_msic4_offset = reg_eray0_msic4_address - eray_memory_start_address;
constexpr u32 reg_eray0_crel_address = 0xf001c3f0;
constexpr u32 reg_eray0_crel_offset = reg_eray0_crel_address - eray_memory_start_address;
constexpr u32 reg_eray0_endn_address = 0xf001c3f4;
constexpr u32 reg_eray0_endn_offset = reg_eray0_endn_address - eray_memory_start_address;
constexpr u32 reg_eray0_wrhs1_address = 0xf001c500;
constexpr u32 reg_eray0_wrhs1_offset = reg_eray0_wrhs1_address - eray_memory_start_address;
constexpr u32 reg_eray0_wrhs2_address = 0xf001c504;
constexpr u32 reg_eray0_wrhs2_offset = reg_eray0_wrhs2_address - eray_memory_start_address;
constexpr u32 reg_eray0_wrhs3_address = 0xf001c508;
constexpr u32 reg_eray0_wrhs3_offset = reg_eray0_wrhs3_address - eray_memory_start_address;
constexpr u32 reg_eray0_ibcm_address = 0xf001c510;
constexpr u32 reg_eray0_ibcm_offset = reg_eray0_ibcm_address - eray_memory_start_address;
constexpr u32 reg_eray0_ibcr_address = 0xf001c514;
constexpr u32 reg_eray0_ibcr_offset = reg_eray0_ibcr_address - eray_memory_start_address;
constexpr u32 reg_eray0_rdhs1_address = 0xf001c700;
constexpr u32 reg_eray0_rdhs1_offset = reg_eray0_rdhs1_address - eray_memory_start_address;
constexpr u32 reg_eray0_rdhs2_address = 0xf001c704;
constexpr u32 reg_eray0_rdhs2_offset = reg_eray0_rdhs2_address - eray_memory_start_address;
constexpr u32 reg_eray0_rdhs3_address = 0xf001c708;
constexpr u32 reg_eray0_rdhs3_offset = reg_eray0_rdhs3_address - eray_memory_start_address;
constexpr u32 reg_eray0_mbs_address = 0xf001c70c;
constexpr u32 reg_eray0_mbs_offset = reg_eray0_mbs_address - eray_memory_start_address;
constexpr u32 reg_eray0_obcm_address = 0xf001c710;
constexpr u32 reg_eray0_obcm_offset = reg_eray0_obcm_address - eray_memory_start_address;
constexpr u32 reg_eray0_obcr_address = 0xf001c714;
constexpr u32 reg_eray0_obcr_offset = reg_eray0_obcr_address - eray_memory_start_address;
constexpr u32 reg_eray0_otss_address = 0xf001c870;
constexpr u32 reg_eray0_otss_offset = reg_eray0_otss_address - eray_memory_start_address;
constexpr u32 reg_eray0_ocs_address = 0xf001c8e8;
constexpr u32 reg_eray0_ocs_offset = reg_eray0_ocs_address - eray_memory_start_address;
constexpr u32 reg_eray0_krstclr_address = 0xf001c8ec;
constexpr u32 reg_eray0_krstclr_offset = reg_eray0_krstclr_address - eray_memory_start_address;
constexpr u32 reg_eray0_krst1_address = 0xf001c8f0;
constexpr u32 reg_eray0_krst1_offset = reg_eray0_krst1_address - eray_memory_start_address;
constexpr u32 reg_eray0_krst0_address = 0xf001c8f4;
constexpr u32 reg_eray0_krst0_offset = reg_eray0_krst0_address - eray_memory_start_address;
constexpr u32 reg_eray0_accen0_address = 0xf001c8fc;
constexpr u32 reg_eray0_accen0_offset = reg_eray0_accen0_address - eray_memory_start_address;

} // anonymous namespace


Tricore::Eray::Eray()
    : m_eray0_clc(eray0_clc_reset_value)
    , m_eray0_cust1(eray0_cust1_reset_value)
    , m_eray0_id(eray0_id_reset_value)
    , m_eray0_cust3(eray0_cust3_reset_value)
    , m_eray0_test1(eray0_test1_reset_value)
    , m_eray0_test2(eray0_test2_reset_value)
    , m_eray0_lck(eray0_lck_reset_value)
    , m_eray0_eir(eray0_eir_reset_value)
    , m_eray0_sir(eray0_sir_reset_value)
    , m_eray0_eils(eray0_eils_reset_value)
    , m_eray0_sils(eray0_sils_reset_value)
    , m_eray0_eies(eray0_eies_reset_value)
    , m_eray0_eier(eray0_eier_reset_value)
    , m_eray0_sies(eray0_sies_reset_value)
    , m_eray0_sier(eray0_sier_reset_value)
    , m_eray0_ile(eray0_ile_reset_value)
    , m_eray0_t0c(eray0_t0c_reset_value)
    , m_eray0_t1c(eray0_t1c_reset_value)
    , m_eray0_stpw1(eray0_stpw1_reset_value)
    , m_eray0_stpw2(eray0_stpw2_reset_value)
    , m_eray0_succ1(eray0_succ1_reset_value)
    , m_eray0_succ2(eray0_succ2_reset_value)
    , m_eray0_succ3(eray0_succ3_reset_value)
    , m_eray0_nemc(eray0_nemc_reset_value)
    , m_eray0_prtc1(eray0_prtc1_reset_value)
    , m_eray0_prtc2(eray0_prtc2_reset_value)
    , m_eray0_mhdc(eray0_mhdc_reset_value)
    , m_eray0_gtuc01(eray0_gtuc01_reset_value)
    , m_eray0_gtuc02(eray0_gtuc02_reset_value)
    , m_eray0_gtuc03(eray0_gtuc03_reset_value)
    , m_eray0_gtuc04(eray0_gtuc04_reset_value)
    , m_eray0_gtuc05(eray0_gtuc05_reset_value)
    , m_eray0_gtuc06(eray0_gtuc06_reset_value)
    , m_eray0_gtuc07(eray0_gtuc07_reset_value)
    , m_eray0_gtuc08(eray0_gtuc08_reset_value)
    , m_eray0_gtuc09(eray0_gtuc09_reset_value)
    , m_eray0_gtuc10(eray0_gtuc10_reset_value)
    , m_eray0_gtuc11(eray0_gtuc11_reset_value)
    , m_eray0_ccsv(eray0_ccsv_reset_value)
    , m_eray0_ccev(eray0_ccev_reset_value)
    , m_eray0_scv(eray0_scv_reset_value)
    , m_eray0_mtccv(eray0_mtccv_reset_value)
    , m_eray0_rcv(eray0_rcv_reset_value)
    , m_eray0_ocv(eray0_ocv_reset_value)
    , m_eray0_sfs(eray0_sfs_reset_value)
    , m_eray0_swnit(eray0_swnit_reset_value)
    , m_eray0_acs(eray0_acs_reset_value)
    , m_eray0_mrc(eray0_mrc_reset_value)
    , m_eray0_frf(eray0_frf_reset_value)
    , m_eray0_frfm(eray0_frfm_reset_value)
    , m_eray0_fcl(eray0_fcl_reset_value)
    , m_eray0_mhds(eray0_mhds_reset_value)
    , m_eray0_ldts(eray0_ldts_reset_value)
    , m_eray0_fsr(eray0_fsr_reset_value)
    , m_eray0_mhdf(eray0_mhdf_reset_value)
    , m_eray0_txrq1(eray0_txrq1_reset_value)
    , m_eray0_txrq2(eray0_txrq2_reset_value)
    , m_eray0_txrq3(eray0_txrq3_reset_value)
    , m_eray0_txrq4(eray0_txrq4_reset_value)
    , m_eray0_ndat1(eray0_ndat1_reset_value)
    , m_eray0_ndat2(eray0_ndat2_reset_value)
    , m_eray0_ndat3(eray0_ndat3_reset_value)
    , m_eray0_ndat4(eray0_ndat4_reset_value)
    , m_eray0_mbsc1(eray0_mbsc1_reset_value)
    , m_eray0_mbsc2(eray0_mbsc2_reset_value)
    , m_eray0_mbsc3(eray0_mbsc3_reset_value)
    , m_eray0_mbsc4(eray0_mbsc4_reset_value)
    , m_eray0_ndic1(eray0_ndic1_reset_value)
    , m_eray0_ndic2(eray0_ndic2_reset_value)
    , m_eray0_ndic3(eray0_ndic3_reset_value)
    , m_eray0_ndic4(eray0_ndic4_reset_value)
    , m_eray0_msic1(eray0_msic1_reset_value)
    , m_eray0_msic2(eray0_msic2_reset_value)
    , m_eray0_msic3(eray0_msic3_reset_value)
    , m_eray0_msic4(eray0_msic4_reset_value)
    , m_eray0_crel(eray0_crel_reset_value)
    , m_eray0_endn(eray0_endn_reset_value)
    , m_eray0_wrhs1(eray0_wrhs1_reset_value)
    , m_eray0_wrhs2(eray0_wrhs2_reset_value)
    , m_eray0_wrhs3(eray0_wrhs3_reset_value)
    , m_eray0_ibcm(eray0_ibcm_reset_value)
    , m_eray0_ibcr(eray0_ibcr_reset_value)
    , m_eray0_rdhs1(eray0_rdhs1_reset_value)
    , m_eray0_rdhs2(eray0_rdhs2_reset_value)
    , m_eray0_rdhs3(eray0_rdhs3_reset_value)
    , m_eray0_mbs(eray0_mbs_reset_value)
    , m_eray0_obcm(eray0_obcm_reset_value)
    , m_eray0_obcr(eray0_obcr_reset_value)
    , m_eray0_otss(eray0_otss_reset_value)
    , m_eray0_ocs(eray0_ocs_reset_value)
    , m_eray0_krstclr(eray0_krstclr_reset_value)
    , m_eray0_krst1(eray0_krst1_reset_value)
    , m_eray0_krst0(eray0_krst0_reset_value)
    , m_eray0_accen0(eray0_accen0_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Eray::read(std::byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - eray_memory_start_address;
    switch (offset) {
    case reg_eray0_clc_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_cust1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_CUST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_cust1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_id_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_cust3_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_CUST3 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_cust3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_test1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_TEST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_test1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_test2_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_TEST2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_test2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_lck_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_LCK in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_lck);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_eir_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_EIR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_eir);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_sir_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_SIR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_sir);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_eils_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_EILS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_eils);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_sils_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_SILS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_sils);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_eies_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_EIES in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_eies);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_eier_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_EIER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_eier);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_sies_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_SIES in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_sies);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_sier_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_SIER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_sier);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ile_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_ILE in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ile);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_t0c_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_T0C in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_t0c);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_t1c_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_T1C in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_t1c);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_stpw1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_STPW1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_stpw1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_stpw2_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_STPW2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_stpw2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_succ1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_SUCC1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_succ1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_succ2_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_SUCC2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_succ2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_succ3_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_SUCC3 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_succ3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_nemc_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_NEMC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_nemc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_prtc1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_PRTC1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_prtc1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_prtc2_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_PRTC2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_prtc2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_mhdc_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MHDC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_mhdc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_gtuc01_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC01 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_gtuc01);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_gtuc02_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC02 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_gtuc02);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_gtuc03_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC03 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_gtuc03);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_gtuc04_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC04 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_gtuc04);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_gtuc05_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC05 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_gtuc05);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_gtuc06_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC06 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_gtuc06);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_gtuc07_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC07 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_gtuc07);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_gtuc08_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC08 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_gtuc08);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_gtuc09_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC09 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_gtuc09);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_gtuc10_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC10 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_gtuc10);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_gtuc11_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC11 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_gtuc11);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ccsv_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_CCSV in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ccsv);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ccev_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_CCEV in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ccev);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_scv_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_SCV in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_scv);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_mtccv_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MTCCV in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_mtccv);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_rcv_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_RCV in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_rcv);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ocv_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_OCV in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ocv);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_sfs_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_SFS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_sfs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_swnit_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_SWNIT in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_swnit);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_acs_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_ACS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_acs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_mrc_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MRC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_mrc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_frf_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_FRF in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_frf);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_frfm_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_FRFM in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_frfm);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_fcl_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_FCL in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_fcl);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_mhds_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MHDS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_mhds);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ldts_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_LDTS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ldts);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_fsr_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_FSR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_fsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_mhdf_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MHDF in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_mhdf);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_txrq1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_TXRQ1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_txrq1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_txrq2_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_TXRQ2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_txrq2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_txrq3_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_TXRQ3 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_txrq3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_txrq4_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_TXRQ4 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_txrq4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ndat1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_NDAT1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ndat1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ndat2_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_NDAT2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ndat2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ndat3_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_NDAT3 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ndat3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ndat4_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_NDAT4 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ndat4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_mbsc1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MBSC1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_mbsc1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_mbsc2_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MBSC2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_mbsc2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_mbsc3_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MBSC3 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_mbsc3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_mbsc4_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MBSC4 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_mbsc4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ndic1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_NDIC1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ndic1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ndic2_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_NDIC2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ndic2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ndic3_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_NDIC3 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ndic3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ndic4_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_NDIC4 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ndic4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_msic1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MSIC1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_msic1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_msic2_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MSIC2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_msic2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_msic3_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MSIC3 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_msic3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_msic4_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MSIC4 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_msic4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_crel_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_CREL in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_crel);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_endn_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_ENDN in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_endn);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_wrhs1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_WRHS1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_wrhs1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_wrhs2_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_WRHS2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_wrhs2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_wrhs3_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_WRHS3 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_wrhs3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ibcm_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_IBCM in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ibcm);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ibcr_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_IBCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ibcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_rdhs1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_RDHS1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_rdhs1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_rdhs2_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_RDHS2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_rdhs2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_rdhs3_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_RDHS3 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_rdhs3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_mbs_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_MBS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_mbs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_obcm_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_OBCM in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_obcm);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_obcr_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_OBCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_obcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_otss_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_OTSS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_otss);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_ocs_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_krstclr_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_krst1_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_krst0_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_eray0_accen0_offset: {
            spdlog::debug("ERAY: accessing ERAY.ERAY0_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_eray0_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Eray peripheral", address)};
        break;
    }
}

void Tricore::Eray::write(const std::byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - eray_memory_start_address;
    switch (offset) {
    case reg_eray0_clc_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_clc));
    } break;
    case reg_eray0_cust1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_CUST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_cust1));
    } break;
    case reg_eray0_id_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_id));
    } break;
    case reg_eray0_cust3_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_CUST3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_cust3));
    } break;
    case reg_eray0_test1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_TEST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_test1));
    } break;
    case reg_eray0_test2_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_TEST2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_test2));
    } break;
    case reg_eray0_lck_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_LCK in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_lck));
    } break;
    case reg_eray0_eir_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_EIR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_eir));
    } break;
    case reg_eray0_sir_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_SIR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_sir));
    } break;
    case reg_eray0_eils_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_EILS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_eils));
    } break;
    case reg_eray0_sils_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_SILS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_sils));
    } break;
    case reg_eray0_eies_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_EIES in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_eies));
    } break;
    case reg_eray0_eier_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_EIER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_eier));
    } break;
    case reg_eray0_sies_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_SIES in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_sies));
    } break;
    case reg_eray0_sier_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_SIER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_sier));
    } break;
    case reg_eray0_ile_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_ILE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ile));
    } break;
    case reg_eray0_t0c_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_T0C in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_t0c));
    } break;
    case reg_eray0_t1c_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_T1C in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_t1c));
    } break;
    case reg_eray0_stpw1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_STPW1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_stpw1));
    } break;
    case reg_eray0_stpw2_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_STPW2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_stpw2));
    } break;
    case reg_eray0_succ1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_SUCC1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_succ1));
    } break;
    case reg_eray0_succ2_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_SUCC2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_succ2));
    } break;
    case reg_eray0_succ3_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_SUCC3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_succ3));
    } break;
    case reg_eray0_nemc_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_NEMC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_nemc));
    } break;
    case reg_eray0_prtc1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_PRTC1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_prtc1));
    } break;
    case reg_eray0_prtc2_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_PRTC2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_prtc2));
    } break;
    case reg_eray0_mhdc_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MHDC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_mhdc));
    } break;
    case reg_eray0_gtuc01_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC01 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_gtuc01));
    } break;
    case reg_eray0_gtuc02_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC02 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_gtuc02));
    } break;
    case reg_eray0_gtuc03_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC03 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_gtuc03));
    } break;
    case reg_eray0_gtuc04_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC04 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_gtuc04));
    } break;
    case reg_eray0_gtuc05_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC05 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_gtuc05));
    } break;
    case reg_eray0_gtuc06_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC06 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_gtuc06));
    } break;
    case reg_eray0_gtuc07_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC07 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_gtuc07));
    } break;
    case reg_eray0_gtuc08_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC08 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_gtuc08));
    } break;
    case reg_eray0_gtuc09_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC09 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_gtuc09));
    } break;
    case reg_eray0_gtuc10_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC10 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_gtuc10));
    } break;
    case reg_eray0_gtuc11_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_GTUC11 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_gtuc11));
    } break;
    case reg_eray0_ccsv_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_CCSV in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ccsv));
    } break;
    case reg_eray0_ccev_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_CCEV in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ccev));
    } break;
    case reg_eray0_scv_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_SCV in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_scv));
    } break;
    case reg_eray0_mtccv_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MTCCV in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_mtccv));
    } break;
    case reg_eray0_rcv_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_RCV in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_rcv));
    } break;
    case reg_eray0_ocv_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_OCV in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ocv));
    } break;
    case reg_eray0_sfs_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_SFS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_sfs));
    } break;
    case reg_eray0_swnit_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_SWNIT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_swnit));
    } break;
    case reg_eray0_acs_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_ACS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_acs));
    } break;
    case reg_eray0_mrc_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MRC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_mrc));
    } break;
    case reg_eray0_frf_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_FRF in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_frf));
    } break;
    case reg_eray0_frfm_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_FRFM in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_frfm));
    } break;
    case reg_eray0_fcl_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_FCL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_fcl));
    } break;
    case reg_eray0_mhds_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MHDS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_mhds));
    } break;
    case reg_eray0_ldts_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_LDTS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ldts));
    } break;
    case reg_eray0_fsr_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_FSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_fsr));
    } break;
    case reg_eray0_mhdf_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MHDF in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_mhdf));
    } break;
    case reg_eray0_txrq1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_TXRQ1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_txrq1));
    } break;
    case reg_eray0_txrq2_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_TXRQ2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_txrq2));
    } break;
    case reg_eray0_txrq3_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_TXRQ3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_txrq3));
    } break;
    case reg_eray0_txrq4_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_TXRQ4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_txrq4));
    } break;
    case reg_eray0_ndat1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_NDAT1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ndat1));
    } break;
    case reg_eray0_ndat2_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_NDAT2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ndat2));
    } break;
    case reg_eray0_ndat3_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_NDAT3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ndat3));
    } break;
    case reg_eray0_ndat4_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_NDAT4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ndat4));
    } break;
    case reg_eray0_mbsc1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MBSC1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_mbsc1));
    } break;
    case reg_eray0_mbsc2_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MBSC2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_mbsc2));
    } break;
    case reg_eray0_mbsc3_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MBSC3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_mbsc3));
    } break;
    case reg_eray0_mbsc4_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MBSC4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_mbsc4));
    } break;
    case reg_eray0_ndic1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_NDIC1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ndic1));
    } break;
    case reg_eray0_ndic2_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_NDIC2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ndic2));
    } break;
    case reg_eray0_ndic3_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_NDIC3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ndic3));
    } break;
    case reg_eray0_ndic4_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_NDIC4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ndic4));
    } break;
    case reg_eray0_msic1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MSIC1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_msic1));
    } break;
    case reg_eray0_msic2_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MSIC2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_msic2));
    } break;
    case reg_eray0_msic3_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MSIC3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_msic3));
    } break;
    case reg_eray0_msic4_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MSIC4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_msic4));
    } break;
    case reg_eray0_crel_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_CREL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_crel));
    } break;
    case reg_eray0_endn_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_ENDN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_endn));
    } break;
    case reg_eray0_wrhs1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_WRHS1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_wrhs1));
    } break;
    case reg_eray0_wrhs2_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_WRHS2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_wrhs2));
    } break;
    case reg_eray0_wrhs3_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_WRHS3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_wrhs3));
    } break;
    case reg_eray0_ibcm_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_IBCM in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ibcm));
    } break;
    case reg_eray0_ibcr_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_IBCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ibcr));
    } break;
    case reg_eray0_rdhs1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_RDHS1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_rdhs1));
    } break;
    case reg_eray0_rdhs2_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_RDHS2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_rdhs2));
    } break;
    case reg_eray0_rdhs3_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_RDHS3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_rdhs3));
    } break;
    case reg_eray0_mbs_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_MBS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_mbs));
    } break;
    case reg_eray0_obcm_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_OBCM in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_obcm));
    } break;
    case reg_eray0_obcr_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_OBCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_obcr));
    } break;
    case reg_eray0_otss_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_OTSS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_otss));
    } break;
    case reg_eray0_ocs_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_ocs));
    } break;
    case reg_eray0_krstclr_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_krstclr));
    } break;
    case reg_eray0_krst1_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_krst1));
    } break;
    case reg_eray0_krst0_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_krst0));
    } break;
    case reg_eray0_accen0_offset: {
        spdlog::debug("ERAY: accessing ERAY.ERAY0_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_eray0_accen0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Eray peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
