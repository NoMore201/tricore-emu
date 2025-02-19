
/**
 * @brief Module source for Asclin peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Asclin.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 asclin0_clc_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_iocr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_id_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_txfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_rxfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_bitcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_framecon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_datcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_brg_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_brd_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_lin_con_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_lin_btimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_lin_htimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_flags_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_flagsset_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_flagsenable_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_txdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_rxdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_csr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_rxdatad_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin0_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_clc_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_iocr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_id_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_txfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_rxfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_bitcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_framecon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_datcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_brg_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_brd_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_lin_con_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_lin_btimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_lin_htimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_flags_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_flagsset_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_flagsenable_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_txdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_rxdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_csr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_rxdatad_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin1_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_clc_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_iocr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_id_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_txfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_rxfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_bitcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_framecon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_datcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_brg_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_brd_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_lin_con_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_lin_btimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_lin_htimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_flags_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_flagsset_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_flagsenable_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_txdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_rxdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_csr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_rxdatad_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin2_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_clc_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_iocr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_id_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_txfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_rxfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_bitcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_framecon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_datcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_brg_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_brd_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_lin_con_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_lin_btimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_lin_htimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_flags_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_flagsset_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_flagsenable_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_txdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_rxdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_csr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_rxdatad_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin3_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_clc_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_iocr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_id_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_txfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_rxfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_bitcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_framecon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_datcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_brg_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_brd_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_lin_con_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_lin_btimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_lin_htimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_flags_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_flagsset_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_flagsenable_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_txdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_rxdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_csr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_rxdatad_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin4_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_clc_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_iocr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_id_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_txfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_rxfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_bitcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_framecon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_datcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_brg_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_brd_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_lin_con_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_lin_btimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_lin_htimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_flags_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_flagsset_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_flagsenable_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_txdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_rxdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_csr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_rxdatad_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin5_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_clc_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_iocr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_id_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_txfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_rxfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_bitcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_framecon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_datcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_brg_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_brd_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_lin_con_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_lin_btimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_lin_htimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_flags_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_flagsset_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_flagsenable_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_txdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_rxdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_csr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_rxdatad_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin6_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_clc_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_iocr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_id_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_txfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_rxfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_bitcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_framecon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_datcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_brg_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_brd_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_lin_con_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_lin_btimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_lin_htimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_flags_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_flagsset_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_flagsenable_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_txdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_rxdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_csr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_rxdatad_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin7_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_clc_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_iocr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_id_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_txfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_rxfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_bitcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_framecon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_datcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_brg_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_brd_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_lin_con_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_lin_btimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_lin_htimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_flags_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_flagsset_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_flagsenable_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_txdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_rxdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_csr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_rxdatad_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin8_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_clc_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_iocr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_id_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_txfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_rxfifocon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_bitcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_framecon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_datcon_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_brg_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_brd_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_lin_con_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_lin_btimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_lin_htimer_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_flags_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_flagsset_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_flagsclear_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_flagsenable_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_txdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_rxdata_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_csr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_rxdatad_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 asclin9_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 asclin_memory_start_address = 0xf0000600U;
constexpr u32 asclin_memory_size = 0; // TODO: update according manual;
constexpr u32 asclin_memory_end_address = asclin_memory_start_address + asclin_memory_size;

constexpr u32 reg_asclin0_clc_address = 0xf0000600;
constexpr u32 reg_asclin0_clc_offset = reg_asclin0_clc_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_iocr_address = 0xf0000604;
constexpr u32 reg_asclin0_iocr_offset = reg_asclin0_iocr_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_id_address = 0xf0000608;
constexpr u32 reg_asclin0_id_offset = reg_asclin0_id_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_txfifocon_address = 0xf000060c;
constexpr u32 reg_asclin0_txfifocon_offset = reg_asclin0_txfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_rxfifocon_address = 0xf0000610;
constexpr u32 reg_asclin0_rxfifocon_offset = reg_asclin0_rxfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_bitcon_address = 0xf0000614;
constexpr u32 reg_asclin0_bitcon_offset = reg_asclin0_bitcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_framecon_address = 0xf0000618;
constexpr u32 reg_asclin0_framecon_offset = reg_asclin0_framecon_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_datcon_address = 0xf000061c;
constexpr u32 reg_asclin0_datcon_offset = reg_asclin0_datcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_brg_address = 0xf0000620;
constexpr u32 reg_asclin0_brg_offset = reg_asclin0_brg_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_brd_address = 0xf0000624;
constexpr u32 reg_asclin0_brd_offset = reg_asclin0_brd_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_lin_con_address = 0xf0000628;
constexpr u32 reg_asclin0_lin_con_offset = reg_asclin0_lin_con_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_lin_btimer_address = 0xf000062c;
constexpr u32 reg_asclin0_lin_btimer_offset = reg_asclin0_lin_btimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_lin_htimer_address = 0xf0000630;
constexpr u32 reg_asclin0_lin_htimer_offset = reg_asclin0_lin_htimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_flags_address = 0xf0000634;
constexpr u32 reg_asclin0_flags_offset = reg_asclin0_flags_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_flagsset_address = 0xf0000638;
constexpr u32 reg_asclin0_flagsset_offset = reg_asclin0_flagsset_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_flagsclear_address = 0xf000063c;
constexpr u32 reg_asclin0_flagsclear_offset = reg_asclin0_flagsclear_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_flagsenable_address = 0xf0000640;
constexpr u32 reg_asclin0_flagsenable_offset = reg_asclin0_flagsenable_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_txdata_address = 0xf0000644;
constexpr u32 reg_asclin0_txdata_offset = reg_asclin0_txdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_rxdata_address = 0xf0000648;
constexpr u32 reg_asclin0_rxdata_offset = reg_asclin0_rxdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_csr_address = 0xf000064c;
constexpr u32 reg_asclin0_csr_offset = reg_asclin0_csr_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_rxdatad_address = 0xf0000650;
constexpr u32 reg_asclin0_rxdatad_offset = reg_asclin0_rxdatad_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_ocs_address = 0xf00006e8;
constexpr u32 reg_asclin0_ocs_offset = reg_asclin0_ocs_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_krstclr_address = 0xf00006ec;
constexpr u32 reg_asclin0_krstclr_offset = reg_asclin0_krstclr_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_krst1_address = 0xf00006f0;
constexpr u32 reg_asclin0_krst1_offset = reg_asclin0_krst1_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_krst0_address = 0xf00006f4;
constexpr u32 reg_asclin0_krst0_offset = reg_asclin0_krst0_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_accen1_address = 0xf00006f8;
constexpr u32 reg_asclin0_accen1_offset = reg_asclin0_accen1_address - asclin_memory_start_address;
constexpr u32 reg_asclin0_accen0_address = 0xf00006fc;
constexpr u32 reg_asclin0_accen0_offset = reg_asclin0_accen0_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_clc_address = 0xf0000700;
constexpr u32 reg_asclin1_clc_offset = reg_asclin1_clc_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_iocr_address = 0xf0000704;
constexpr u32 reg_asclin1_iocr_offset = reg_asclin1_iocr_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_id_address = 0xf0000708;
constexpr u32 reg_asclin1_id_offset = reg_asclin1_id_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_txfifocon_address = 0xf000070c;
constexpr u32 reg_asclin1_txfifocon_offset = reg_asclin1_txfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_rxfifocon_address = 0xf0000710;
constexpr u32 reg_asclin1_rxfifocon_offset = reg_asclin1_rxfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_bitcon_address = 0xf0000714;
constexpr u32 reg_asclin1_bitcon_offset = reg_asclin1_bitcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_framecon_address = 0xf0000718;
constexpr u32 reg_asclin1_framecon_offset = reg_asclin1_framecon_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_datcon_address = 0xf000071c;
constexpr u32 reg_asclin1_datcon_offset = reg_asclin1_datcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_brg_address = 0xf0000720;
constexpr u32 reg_asclin1_brg_offset = reg_asclin1_brg_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_brd_address = 0xf0000724;
constexpr u32 reg_asclin1_brd_offset = reg_asclin1_brd_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_lin_con_address = 0xf0000728;
constexpr u32 reg_asclin1_lin_con_offset = reg_asclin1_lin_con_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_lin_btimer_address = 0xf000072c;
constexpr u32 reg_asclin1_lin_btimer_offset = reg_asclin1_lin_btimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_lin_htimer_address = 0xf0000730;
constexpr u32 reg_asclin1_lin_htimer_offset = reg_asclin1_lin_htimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_flags_address = 0xf0000734;
constexpr u32 reg_asclin1_flags_offset = reg_asclin1_flags_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_flagsset_address = 0xf0000738;
constexpr u32 reg_asclin1_flagsset_offset = reg_asclin1_flagsset_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_flagsclear_address = 0xf000073c;
constexpr u32 reg_asclin1_flagsclear_offset = reg_asclin1_flagsclear_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_flagsenable_address = 0xf0000740;
constexpr u32 reg_asclin1_flagsenable_offset = reg_asclin1_flagsenable_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_txdata_address = 0xf0000744;
constexpr u32 reg_asclin1_txdata_offset = reg_asclin1_txdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_rxdata_address = 0xf0000748;
constexpr u32 reg_asclin1_rxdata_offset = reg_asclin1_rxdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_csr_address = 0xf000074c;
constexpr u32 reg_asclin1_csr_offset = reg_asclin1_csr_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_rxdatad_address = 0xf0000750;
constexpr u32 reg_asclin1_rxdatad_offset = reg_asclin1_rxdatad_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_ocs_address = 0xf00007e8;
constexpr u32 reg_asclin1_ocs_offset = reg_asclin1_ocs_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_krstclr_address = 0xf00007ec;
constexpr u32 reg_asclin1_krstclr_offset = reg_asclin1_krstclr_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_krst1_address = 0xf00007f0;
constexpr u32 reg_asclin1_krst1_offset = reg_asclin1_krst1_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_krst0_address = 0xf00007f4;
constexpr u32 reg_asclin1_krst0_offset = reg_asclin1_krst0_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_accen1_address = 0xf00007f8;
constexpr u32 reg_asclin1_accen1_offset = reg_asclin1_accen1_address - asclin_memory_start_address;
constexpr u32 reg_asclin1_accen0_address = 0xf00007fc;
constexpr u32 reg_asclin1_accen0_offset = reg_asclin1_accen0_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_clc_address = 0xf0000800;
constexpr u32 reg_asclin2_clc_offset = reg_asclin2_clc_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_iocr_address = 0xf0000804;
constexpr u32 reg_asclin2_iocr_offset = reg_asclin2_iocr_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_id_address = 0xf0000808;
constexpr u32 reg_asclin2_id_offset = reg_asclin2_id_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_txfifocon_address = 0xf000080c;
constexpr u32 reg_asclin2_txfifocon_offset = reg_asclin2_txfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_rxfifocon_address = 0xf0000810;
constexpr u32 reg_asclin2_rxfifocon_offset = reg_asclin2_rxfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_bitcon_address = 0xf0000814;
constexpr u32 reg_asclin2_bitcon_offset = reg_asclin2_bitcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_framecon_address = 0xf0000818;
constexpr u32 reg_asclin2_framecon_offset = reg_asclin2_framecon_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_datcon_address = 0xf000081c;
constexpr u32 reg_asclin2_datcon_offset = reg_asclin2_datcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_brg_address = 0xf0000820;
constexpr u32 reg_asclin2_brg_offset = reg_asclin2_brg_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_brd_address = 0xf0000824;
constexpr u32 reg_asclin2_brd_offset = reg_asclin2_brd_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_lin_con_address = 0xf0000828;
constexpr u32 reg_asclin2_lin_con_offset = reg_asclin2_lin_con_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_lin_btimer_address = 0xf000082c;
constexpr u32 reg_asclin2_lin_btimer_offset = reg_asclin2_lin_btimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_lin_htimer_address = 0xf0000830;
constexpr u32 reg_asclin2_lin_htimer_offset = reg_asclin2_lin_htimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_flags_address = 0xf0000834;
constexpr u32 reg_asclin2_flags_offset = reg_asclin2_flags_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_flagsset_address = 0xf0000838;
constexpr u32 reg_asclin2_flagsset_offset = reg_asclin2_flagsset_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_flagsclear_address = 0xf000083c;
constexpr u32 reg_asclin2_flagsclear_offset = reg_asclin2_flagsclear_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_flagsenable_address = 0xf0000840;
constexpr u32 reg_asclin2_flagsenable_offset = reg_asclin2_flagsenable_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_txdata_address = 0xf0000844;
constexpr u32 reg_asclin2_txdata_offset = reg_asclin2_txdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_rxdata_address = 0xf0000848;
constexpr u32 reg_asclin2_rxdata_offset = reg_asclin2_rxdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_csr_address = 0xf000084c;
constexpr u32 reg_asclin2_csr_offset = reg_asclin2_csr_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_rxdatad_address = 0xf0000850;
constexpr u32 reg_asclin2_rxdatad_offset = reg_asclin2_rxdatad_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_ocs_address = 0xf00008e8;
constexpr u32 reg_asclin2_ocs_offset = reg_asclin2_ocs_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_krstclr_address = 0xf00008ec;
constexpr u32 reg_asclin2_krstclr_offset = reg_asclin2_krstclr_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_krst1_address = 0xf00008f0;
constexpr u32 reg_asclin2_krst1_offset = reg_asclin2_krst1_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_krst0_address = 0xf00008f4;
constexpr u32 reg_asclin2_krst0_offset = reg_asclin2_krst0_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_accen1_address = 0xf00008f8;
constexpr u32 reg_asclin2_accen1_offset = reg_asclin2_accen1_address - asclin_memory_start_address;
constexpr u32 reg_asclin2_accen0_address = 0xf00008fc;
constexpr u32 reg_asclin2_accen0_offset = reg_asclin2_accen0_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_clc_address = 0xf0000900;
constexpr u32 reg_asclin3_clc_offset = reg_asclin3_clc_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_iocr_address = 0xf0000904;
constexpr u32 reg_asclin3_iocr_offset = reg_asclin3_iocr_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_id_address = 0xf0000908;
constexpr u32 reg_asclin3_id_offset = reg_asclin3_id_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_txfifocon_address = 0xf000090c;
constexpr u32 reg_asclin3_txfifocon_offset = reg_asclin3_txfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_rxfifocon_address = 0xf0000910;
constexpr u32 reg_asclin3_rxfifocon_offset = reg_asclin3_rxfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_bitcon_address = 0xf0000914;
constexpr u32 reg_asclin3_bitcon_offset = reg_asclin3_bitcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_framecon_address = 0xf0000918;
constexpr u32 reg_asclin3_framecon_offset = reg_asclin3_framecon_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_datcon_address = 0xf000091c;
constexpr u32 reg_asclin3_datcon_offset = reg_asclin3_datcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_brg_address = 0xf0000920;
constexpr u32 reg_asclin3_brg_offset = reg_asclin3_brg_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_brd_address = 0xf0000924;
constexpr u32 reg_asclin3_brd_offset = reg_asclin3_brd_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_lin_con_address = 0xf0000928;
constexpr u32 reg_asclin3_lin_con_offset = reg_asclin3_lin_con_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_lin_btimer_address = 0xf000092c;
constexpr u32 reg_asclin3_lin_btimer_offset = reg_asclin3_lin_btimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_lin_htimer_address = 0xf0000930;
constexpr u32 reg_asclin3_lin_htimer_offset = reg_asclin3_lin_htimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_flags_address = 0xf0000934;
constexpr u32 reg_asclin3_flags_offset = reg_asclin3_flags_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_flagsset_address = 0xf0000938;
constexpr u32 reg_asclin3_flagsset_offset = reg_asclin3_flagsset_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_flagsclear_address = 0xf000093c;
constexpr u32 reg_asclin3_flagsclear_offset = reg_asclin3_flagsclear_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_flagsenable_address = 0xf0000940;
constexpr u32 reg_asclin3_flagsenable_offset = reg_asclin3_flagsenable_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_txdata_address = 0xf0000944;
constexpr u32 reg_asclin3_txdata_offset = reg_asclin3_txdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_rxdata_address = 0xf0000948;
constexpr u32 reg_asclin3_rxdata_offset = reg_asclin3_rxdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_csr_address = 0xf000094c;
constexpr u32 reg_asclin3_csr_offset = reg_asclin3_csr_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_rxdatad_address = 0xf0000950;
constexpr u32 reg_asclin3_rxdatad_offset = reg_asclin3_rxdatad_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_ocs_address = 0xf00009e8;
constexpr u32 reg_asclin3_ocs_offset = reg_asclin3_ocs_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_krstclr_address = 0xf00009ec;
constexpr u32 reg_asclin3_krstclr_offset = reg_asclin3_krstclr_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_krst1_address = 0xf00009f0;
constexpr u32 reg_asclin3_krst1_offset = reg_asclin3_krst1_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_krst0_address = 0xf00009f4;
constexpr u32 reg_asclin3_krst0_offset = reg_asclin3_krst0_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_accen1_address = 0xf00009f8;
constexpr u32 reg_asclin3_accen1_offset = reg_asclin3_accen1_address - asclin_memory_start_address;
constexpr u32 reg_asclin3_accen0_address = 0xf00009fc;
constexpr u32 reg_asclin3_accen0_offset = reg_asclin3_accen0_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_clc_address = 0xf0000a00;
constexpr u32 reg_asclin4_clc_offset = reg_asclin4_clc_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_iocr_address = 0xf0000a04;
constexpr u32 reg_asclin4_iocr_offset = reg_asclin4_iocr_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_id_address = 0xf0000a08;
constexpr u32 reg_asclin4_id_offset = reg_asclin4_id_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_txfifocon_address = 0xf0000a0c;
constexpr u32 reg_asclin4_txfifocon_offset = reg_asclin4_txfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_rxfifocon_address = 0xf0000a10;
constexpr u32 reg_asclin4_rxfifocon_offset = reg_asclin4_rxfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_bitcon_address = 0xf0000a14;
constexpr u32 reg_asclin4_bitcon_offset = reg_asclin4_bitcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_framecon_address = 0xf0000a18;
constexpr u32 reg_asclin4_framecon_offset = reg_asclin4_framecon_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_datcon_address = 0xf0000a1c;
constexpr u32 reg_asclin4_datcon_offset = reg_asclin4_datcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_brg_address = 0xf0000a20;
constexpr u32 reg_asclin4_brg_offset = reg_asclin4_brg_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_brd_address = 0xf0000a24;
constexpr u32 reg_asclin4_brd_offset = reg_asclin4_brd_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_lin_con_address = 0xf0000a28;
constexpr u32 reg_asclin4_lin_con_offset = reg_asclin4_lin_con_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_lin_btimer_address = 0xf0000a2c;
constexpr u32 reg_asclin4_lin_btimer_offset = reg_asclin4_lin_btimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_lin_htimer_address = 0xf0000a30;
constexpr u32 reg_asclin4_lin_htimer_offset = reg_asclin4_lin_htimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_flags_address = 0xf0000a34;
constexpr u32 reg_asclin4_flags_offset = reg_asclin4_flags_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_flagsset_address = 0xf0000a38;
constexpr u32 reg_asclin4_flagsset_offset = reg_asclin4_flagsset_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_flagsclear_address = 0xf0000a3c;
constexpr u32 reg_asclin4_flagsclear_offset = reg_asclin4_flagsclear_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_flagsenable_address = 0xf0000a40;
constexpr u32 reg_asclin4_flagsenable_offset = reg_asclin4_flagsenable_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_txdata_address = 0xf0000a44;
constexpr u32 reg_asclin4_txdata_offset = reg_asclin4_txdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_rxdata_address = 0xf0000a48;
constexpr u32 reg_asclin4_rxdata_offset = reg_asclin4_rxdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_csr_address = 0xf0000a4c;
constexpr u32 reg_asclin4_csr_offset = reg_asclin4_csr_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_rxdatad_address = 0xf0000a50;
constexpr u32 reg_asclin4_rxdatad_offset = reg_asclin4_rxdatad_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_ocs_address = 0xf0000ae8;
constexpr u32 reg_asclin4_ocs_offset = reg_asclin4_ocs_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_krstclr_address = 0xf0000aec;
constexpr u32 reg_asclin4_krstclr_offset = reg_asclin4_krstclr_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_krst1_address = 0xf0000af0;
constexpr u32 reg_asclin4_krst1_offset = reg_asclin4_krst1_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_krst0_address = 0xf0000af4;
constexpr u32 reg_asclin4_krst0_offset = reg_asclin4_krst0_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_accen1_address = 0xf0000af8;
constexpr u32 reg_asclin4_accen1_offset = reg_asclin4_accen1_address - asclin_memory_start_address;
constexpr u32 reg_asclin4_accen0_address = 0xf0000afc;
constexpr u32 reg_asclin4_accen0_offset = reg_asclin4_accen0_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_clc_address = 0xf0000b00;
constexpr u32 reg_asclin5_clc_offset = reg_asclin5_clc_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_iocr_address = 0xf0000b04;
constexpr u32 reg_asclin5_iocr_offset = reg_asclin5_iocr_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_id_address = 0xf0000b08;
constexpr u32 reg_asclin5_id_offset = reg_asclin5_id_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_txfifocon_address = 0xf0000b0c;
constexpr u32 reg_asclin5_txfifocon_offset = reg_asclin5_txfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_rxfifocon_address = 0xf0000b10;
constexpr u32 reg_asclin5_rxfifocon_offset = reg_asclin5_rxfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_bitcon_address = 0xf0000b14;
constexpr u32 reg_asclin5_bitcon_offset = reg_asclin5_bitcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_framecon_address = 0xf0000b18;
constexpr u32 reg_asclin5_framecon_offset = reg_asclin5_framecon_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_datcon_address = 0xf0000b1c;
constexpr u32 reg_asclin5_datcon_offset = reg_asclin5_datcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_brg_address = 0xf0000b20;
constexpr u32 reg_asclin5_brg_offset = reg_asclin5_brg_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_brd_address = 0xf0000b24;
constexpr u32 reg_asclin5_brd_offset = reg_asclin5_brd_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_lin_con_address = 0xf0000b28;
constexpr u32 reg_asclin5_lin_con_offset = reg_asclin5_lin_con_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_lin_btimer_address = 0xf0000b2c;
constexpr u32 reg_asclin5_lin_btimer_offset = reg_asclin5_lin_btimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_lin_htimer_address = 0xf0000b30;
constexpr u32 reg_asclin5_lin_htimer_offset = reg_asclin5_lin_htimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_flags_address = 0xf0000b34;
constexpr u32 reg_asclin5_flags_offset = reg_asclin5_flags_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_flagsset_address = 0xf0000b38;
constexpr u32 reg_asclin5_flagsset_offset = reg_asclin5_flagsset_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_flagsclear_address = 0xf0000b3c;
constexpr u32 reg_asclin5_flagsclear_offset = reg_asclin5_flagsclear_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_flagsenable_address = 0xf0000b40;
constexpr u32 reg_asclin5_flagsenable_offset = reg_asclin5_flagsenable_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_txdata_address = 0xf0000b44;
constexpr u32 reg_asclin5_txdata_offset = reg_asclin5_txdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_rxdata_address = 0xf0000b48;
constexpr u32 reg_asclin5_rxdata_offset = reg_asclin5_rxdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_csr_address = 0xf0000b4c;
constexpr u32 reg_asclin5_csr_offset = reg_asclin5_csr_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_rxdatad_address = 0xf0000b50;
constexpr u32 reg_asclin5_rxdatad_offset = reg_asclin5_rxdatad_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_ocs_address = 0xf0000be8;
constexpr u32 reg_asclin5_ocs_offset = reg_asclin5_ocs_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_krstclr_address = 0xf0000bec;
constexpr u32 reg_asclin5_krstclr_offset = reg_asclin5_krstclr_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_krst1_address = 0xf0000bf0;
constexpr u32 reg_asclin5_krst1_offset = reg_asclin5_krst1_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_krst0_address = 0xf0000bf4;
constexpr u32 reg_asclin5_krst0_offset = reg_asclin5_krst0_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_accen1_address = 0xf0000bf8;
constexpr u32 reg_asclin5_accen1_offset = reg_asclin5_accen1_address - asclin_memory_start_address;
constexpr u32 reg_asclin5_accen0_address = 0xf0000bfc;
constexpr u32 reg_asclin5_accen0_offset = reg_asclin5_accen0_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_clc_address = 0xf0000c00;
constexpr u32 reg_asclin6_clc_offset = reg_asclin6_clc_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_iocr_address = 0xf0000c04;
constexpr u32 reg_asclin6_iocr_offset = reg_asclin6_iocr_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_id_address = 0xf0000c08;
constexpr u32 reg_asclin6_id_offset = reg_asclin6_id_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_txfifocon_address = 0xf0000c0c;
constexpr u32 reg_asclin6_txfifocon_offset = reg_asclin6_txfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_rxfifocon_address = 0xf0000c10;
constexpr u32 reg_asclin6_rxfifocon_offset = reg_asclin6_rxfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_bitcon_address = 0xf0000c14;
constexpr u32 reg_asclin6_bitcon_offset = reg_asclin6_bitcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_framecon_address = 0xf0000c18;
constexpr u32 reg_asclin6_framecon_offset = reg_asclin6_framecon_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_datcon_address = 0xf0000c1c;
constexpr u32 reg_asclin6_datcon_offset = reg_asclin6_datcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_brg_address = 0xf0000c20;
constexpr u32 reg_asclin6_brg_offset = reg_asclin6_brg_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_brd_address = 0xf0000c24;
constexpr u32 reg_asclin6_brd_offset = reg_asclin6_brd_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_lin_con_address = 0xf0000c28;
constexpr u32 reg_asclin6_lin_con_offset = reg_asclin6_lin_con_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_lin_btimer_address = 0xf0000c2c;
constexpr u32 reg_asclin6_lin_btimer_offset = reg_asclin6_lin_btimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_lin_htimer_address = 0xf0000c30;
constexpr u32 reg_asclin6_lin_htimer_offset = reg_asclin6_lin_htimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_flags_address = 0xf0000c34;
constexpr u32 reg_asclin6_flags_offset = reg_asclin6_flags_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_flagsset_address = 0xf0000c38;
constexpr u32 reg_asclin6_flagsset_offset = reg_asclin6_flagsset_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_flagsclear_address = 0xf0000c3c;
constexpr u32 reg_asclin6_flagsclear_offset = reg_asclin6_flagsclear_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_flagsenable_address = 0xf0000c40;
constexpr u32 reg_asclin6_flagsenable_offset = reg_asclin6_flagsenable_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_txdata_address = 0xf0000c44;
constexpr u32 reg_asclin6_txdata_offset = reg_asclin6_txdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_rxdata_address = 0xf0000c48;
constexpr u32 reg_asclin6_rxdata_offset = reg_asclin6_rxdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_csr_address = 0xf0000c4c;
constexpr u32 reg_asclin6_csr_offset = reg_asclin6_csr_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_rxdatad_address = 0xf0000c50;
constexpr u32 reg_asclin6_rxdatad_offset = reg_asclin6_rxdatad_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_ocs_address = 0xf0000ce8;
constexpr u32 reg_asclin6_ocs_offset = reg_asclin6_ocs_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_krstclr_address = 0xf0000cec;
constexpr u32 reg_asclin6_krstclr_offset = reg_asclin6_krstclr_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_krst1_address = 0xf0000cf0;
constexpr u32 reg_asclin6_krst1_offset = reg_asclin6_krst1_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_krst0_address = 0xf0000cf4;
constexpr u32 reg_asclin6_krst0_offset = reg_asclin6_krst0_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_accen1_address = 0xf0000cf8;
constexpr u32 reg_asclin6_accen1_offset = reg_asclin6_accen1_address - asclin_memory_start_address;
constexpr u32 reg_asclin6_accen0_address = 0xf0000cfc;
constexpr u32 reg_asclin6_accen0_offset = reg_asclin6_accen0_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_clc_address = 0xf0000d00;
constexpr u32 reg_asclin7_clc_offset = reg_asclin7_clc_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_iocr_address = 0xf0000d04;
constexpr u32 reg_asclin7_iocr_offset = reg_asclin7_iocr_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_id_address = 0xf0000d08;
constexpr u32 reg_asclin7_id_offset = reg_asclin7_id_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_txfifocon_address = 0xf0000d0c;
constexpr u32 reg_asclin7_txfifocon_offset = reg_asclin7_txfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_rxfifocon_address = 0xf0000d10;
constexpr u32 reg_asclin7_rxfifocon_offset = reg_asclin7_rxfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_bitcon_address = 0xf0000d14;
constexpr u32 reg_asclin7_bitcon_offset = reg_asclin7_bitcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_framecon_address = 0xf0000d18;
constexpr u32 reg_asclin7_framecon_offset = reg_asclin7_framecon_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_datcon_address = 0xf0000d1c;
constexpr u32 reg_asclin7_datcon_offset = reg_asclin7_datcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_brg_address = 0xf0000d20;
constexpr u32 reg_asclin7_brg_offset = reg_asclin7_brg_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_brd_address = 0xf0000d24;
constexpr u32 reg_asclin7_brd_offset = reg_asclin7_brd_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_lin_con_address = 0xf0000d28;
constexpr u32 reg_asclin7_lin_con_offset = reg_asclin7_lin_con_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_lin_btimer_address = 0xf0000d2c;
constexpr u32 reg_asclin7_lin_btimer_offset = reg_asclin7_lin_btimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_lin_htimer_address = 0xf0000d30;
constexpr u32 reg_asclin7_lin_htimer_offset = reg_asclin7_lin_htimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_flags_address = 0xf0000d34;
constexpr u32 reg_asclin7_flags_offset = reg_asclin7_flags_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_flagsset_address = 0xf0000d38;
constexpr u32 reg_asclin7_flagsset_offset = reg_asclin7_flagsset_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_flagsclear_address = 0xf0000d3c;
constexpr u32 reg_asclin7_flagsclear_offset = reg_asclin7_flagsclear_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_flagsenable_address = 0xf0000d40;
constexpr u32 reg_asclin7_flagsenable_offset = reg_asclin7_flagsenable_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_txdata_address = 0xf0000d44;
constexpr u32 reg_asclin7_txdata_offset = reg_asclin7_txdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_rxdata_address = 0xf0000d48;
constexpr u32 reg_asclin7_rxdata_offset = reg_asclin7_rxdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_csr_address = 0xf0000d4c;
constexpr u32 reg_asclin7_csr_offset = reg_asclin7_csr_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_rxdatad_address = 0xf0000d50;
constexpr u32 reg_asclin7_rxdatad_offset = reg_asclin7_rxdatad_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_ocs_address = 0xf0000de8;
constexpr u32 reg_asclin7_ocs_offset = reg_asclin7_ocs_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_krstclr_address = 0xf0000dec;
constexpr u32 reg_asclin7_krstclr_offset = reg_asclin7_krstclr_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_krst1_address = 0xf0000df0;
constexpr u32 reg_asclin7_krst1_offset = reg_asclin7_krst1_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_krst0_address = 0xf0000df4;
constexpr u32 reg_asclin7_krst0_offset = reg_asclin7_krst0_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_accen1_address = 0xf0000df8;
constexpr u32 reg_asclin7_accen1_offset = reg_asclin7_accen1_address - asclin_memory_start_address;
constexpr u32 reg_asclin7_accen0_address = 0xf0000dfc;
constexpr u32 reg_asclin7_accen0_offset = reg_asclin7_accen0_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_clc_address = 0xf0000e00;
constexpr u32 reg_asclin8_clc_offset = reg_asclin8_clc_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_iocr_address = 0xf0000e04;
constexpr u32 reg_asclin8_iocr_offset = reg_asclin8_iocr_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_id_address = 0xf0000e08;
constexpr u32 reg_asclin8_id_offset = reg_asclin8_id_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_txfifocon_address = 0xf0000e0c;
constexpr u32 reg_asclin8_txfifocon_offset = reg_asclin8_txfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_rxfifocon_address = 0xf0000e10;
constexpr u32 reg_asclin8_rxfifocon_offset = reg_asclin8_rxfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_bitcon_address = 0xf0000e14;
constexpr u32 reg_asclin8_bitcon_offset = reg_asclin8_bitcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_framecon_address = 0xf0000e18;
constexpr u32 reg_asclin8_framecon_offset = reg_asclin8_framecon_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_datcon_address = 0xf0000e1c;
constexpr u32 reg_asclin8_datcon_offset = reg_asclin8_datcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_brg_address = 0xf0000e20;
constexpr u32 reg_asclin8_brg_offset = reg_asclin8_brg_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_brd_address = 0xf0000e24;
constexpr u32 reg_asclin8_brd_offset = reg_asclin8_brd_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_lin_con_address = 0xf0000e28;
constexpr u32 reg_asclin8_lin_con_offset = reg_asclin8_lin_con_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_lin_btimer_address = 0xf0000e2c;
constexpr u32 reg_asclin8_lin_btimer_offset = reg_asclin8_lin_btimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_lin_htimer_address = 0xf0000e30;
constexpr u32 reg_asclin8_lin_htimer_offset = reg_asclin8_lin_htimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_flags_address = 0xf0000e34;
constexpr u32 reg_asclin8_flags_offset = reg_asclin8_flags_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_flagsset_address = 0xf0000e38;
constexpr u32 reg_asclin8_flagsset_offset = reg_asclin8_flagsset_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_flagsclear_address = 0xf0000e3c;
constexpr u32 reg_asclin8_flagsclear_offset = reg_asclin8_flagsclear_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_flagsenable_address = 0xf0000e40;
constexpr u32 reg_asclin8_flagsenable_offset = reg_asclin8_flagsenable_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_txdata_address = 0xf0000e44;
constexpr u32 reg_asclin8_txdata_offset = reg_asclin8_txdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_rxdata_address = 0xf0000e48;
constexpr u32 reg_asclin8_rxdata_offset = reg_asclin8_rxdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_csr_address = 0xf0000e4c;
constexpr u32 reg_asclin8_csr_offset = reg_asclin8_csr_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_rxdatad_address = 0xf0000e50;
constexpr u32 reg_asclin8_rxdatad_offset = reg_asclin8_rxdatad_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_ocs_address = 0xf0000ee8;
constexpr u32 reg_asclin8_ocs_offset = reg_asclin8_ocs_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_krstclr_address = 0xf0000eec;
constexpr u32 reg_asclin8_krstclr_offset = reg_asclin8_krstclr_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_krst1_address = 0xf0000ef0;
constexpr u32 reg_asclin8_krst1_offset = reg_asclin8_krst1_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_krst0_address = 0xf0000ef4;
constexpr u32 reg_asclin8_krst0_offset = reg_asclin8_krst0_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_accen1_address = 0xf0000ef8;
constexpr u32 reg_asclin8_accen1_offset = reg_asclin8_accen1_address - asclin_memory_start_address;
constexpr u32 reg_asclin8_accen0_address = 0xf0000efc;
constexpr u32 reg_asclin8_accen0_offset = reg_asclin8_accen0_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_clc_address = 0xf0000f00;
constexpr u32 reg_asclin9_clc_offset = reg_asclin9_clc_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_iocr_address = 0xf0000f04;
constexpr u32 reg_asclin9_iocr_offset = reg_asclin9_iocr_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_id_address = 0xf0000f08;
constexpr u32 reg_asclin9_id_offset = reg_asclin9_id_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_txfifocon_address = 0xf0000f0c;
constexpr u32 reg_asclin9_txfifocon_offset = reg_asclin9_txfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_rxfifocon_address = 0xf0000f10;
constexpr u32 reg_asclin9_rxfifocon_offset = reg_asclin9_rxfifocon_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_bitcon_address = 0xf0000f14;
constexpr u32 reg_asclin9_bitcon_offset = reg_asclin9_bitcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_framecon_address = 0xf0000f18;
constexpr u32 reg_asclin9_framecon_offset = reg_asclin9_framecon_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_datcon_address = 0xf0000f1c;
constexpr u32 reg_asclin9_datcon_offset = reg_asclin9_datcon_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_brg_address = 0xf0000f20;
constexpr u32 reg_asclin9_brg_offset = reg_asclin9_brg_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_brd_address = 0xf0000f24;
constexpr u32 reg_asclin9_brd_offset = reg_asclin9_brd_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_lin_con_address = 0xf0000f28;
constexpr u32 reg_asclin9_lin_con_offset = reg_asclin9_lin_con_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_lin_btimer_address = 0xf0000f2c;
constexpr u32 reg_asclin9_lin_btimer_offset = reg_asclin9_lin_btimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_lin_htimer_address = 0xf0000f30;
constexpr u32 reg_asclin9_lin_htimer_offset = reg_asclin9_lin_htimer_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_flags_address = 0xf0000f34;
constexpr u32 reg_asclin9_flags_offset = reg_asclin9_flags_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_flagsset_address = 0xf0000f38;
constexpr u32 reg_asclin9_flagsset_offset = reg_asclin9_flagsset_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_flagsclear_address = 0xf0000f3c;
constexpr u32 reg_asclin9_flagsclear_offset = reg_asclin9_flagsclear_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_flagsenable_address = 0xf0000f40;
constexpr u32 reg_asclin9_flagsenable_offset = reg_asclin9_flagsenable_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_txdata_address = 0xf0000f44;
constexpr u32 reg_asclin9_txdata_offset = reg_asclin9_txdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_rxdata_address = 0xf0000f48;
constexpr u32 reg_asclin9_rxdata_offset = reg_asclin9_rxdata_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_csr_address = 0xf0000f4c;
constexpr u32 reg_asclin9_csr_offset = reg_asclin9_csr_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_rxdatad_address = 0xf0000f50;
constexpr u32 reg_asclin9_rxdatad_offset = reg_asclin9_rxdatad_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_ocs_address = 0xf0000fe8;
constexpr u32 reg_asclin9_ocs_offset = reg_asclin9_ocs_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_krstclr_address = 0xf0000fec;
constexpr u32 reg_asclin9_krstclr_offset = reg_asclin9_krstclr_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_krst1_address = 0xf0000ff0;
constexpr u32 reg_asclin9_krst1_offset = reg_asclin9_krst1_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_krst0_address = 0xf0000ff4;
constexpr u32 reg_asclin9_krst0_offset = reg_asclin9_krst0_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_accen1_address = 0xf0000ff8;
constexpr u32 reg_asclin9_accen1_offset = reg_asclin9_accen1_address - asclin_memory_start_address;
constexpr u32 reg_asclin9_accen0_address = 0xf0000ffc;
constexpr u32 reg_asclin9_accen0_offset = reg_asclin9_accen0_address - asclin_memory_start_address;

} // anonymous namespace


Tricore::Asclin::Asclin()
    : m_asclin0_clc(asclin0_clc_reset_value)
    , m_asclin0_iocr(asclin0_iocr_reset_value)
    , m_asclin0_id(asclin0_id_reset_value)
    , m_asclin0_txfifocon(asclin0_txfifocon_reset_value)
    , m_asclin0_rxfifocon(asclin0_rxfifocon_reset_value)
    , m_asclin0_bitcon(asclin0_bitcon_reset_value)
    , m_asclin0_framecon(asclin0_framecon_reset_value)
    , m_asclin0_datcon(asclin0_datcon_reset_value)
    , m_asclin0_brg(asclin0_brg_reset_value)
    , m_asclin0_brd(asclin0_brd_reset_value)
    , m_asclin0_lin_con(asclin0_lin_con_reset_value)
    , m_asclin0_lin_btimer(asclin0_lin_btimer_reset_value)
    , m_asclin0_lin_htimer(asclin0_lin_htimer_reset_value)
    , m_asclin0_flags(asclin0_flags_reset_value)
    , m_asclin0_flagsset(asclin0_flagsset_reset_value)
    , m_asclin0_flagsclear(asclin0_flagsclear_reset_value)
    , m_asclin0_flagsenable(asclin0_flagsenable_reset_value)
    , m_asclin0_txdata(asclin0_txdata_reset_value)
    , m_asclin0_rxdata(asclin0_rxdata_reset_value)
    , m_asclin0_csr(asclin0_csr_reset_value)
    , m_asclin0_rxdatad(asclin0_rxdatad_reset_value)
    , m_asclin0_ocs(asclin0_ocs_reset_value)
    , m_asclin0_krstclr(asclin0_krstclr_reset_value)
    , m_asclin0_krst1(asclin0_krst1_reset_value)
    , m_asclin0_krst0(asclin0_krst0_reset_value)
    , m_asclin0_accen1(asclin0_accen1_reset_value)
    , m_asclin0_accen0(asclin0_accen0_reset_value)
    , m_asclin1_clc(asclin1_clc_reset_value)
    , m_asclin1_iocr(asclin1_iocr_reset_value)
    , m_asclin1_id(asclin1_id_reset_value)
    , m_asclin1_txfifocon(asclin1_txfifocon_reset_value)
    , m_asclin1_rxfifocon(asclin1_rxfifocon_reset_value)
    , m_asclin1_bitcon(asclin1_bitcon_reset_value)
    , m_asclin1_framecon(asclin1_framecon_reset_value)
    , m_asclin1_datcon(asclin1_datcon_reset_value)
    , m_asclin1_brg(asclin1_brg_reset_value)
    , m_asclin1_brd(asclin1_brd_reset_value)
    , m_asclin1_lin_con(asclin1_lin_con_reset_value)
    , m_asclin1_lin_btimer(asclin1_lin_btimer_reset_value)
    , m_asclin1_lin_htimer(asclin1_lin_htimer_reset_value)
    , m_asclin1_flags(asclin1_flags_reset_value)
    , m_asclin1_flagsset(asclin1_flagsset_reset_value)
    , m_asclin1_flagsclear(asclin1_flagsclear_reset_value)
    , m_asclin1_flagsenable(asclin1_flagsenable_reset_value)
    , m_asclin1_txdata(asclin1_txdata_reset_value)
    , m_asclin1_rxdata(asclin1_rxdata_reset_value)
    , m_asclin1_csr(asclin1_csr_reset_value)
    , m_asclin1_rxdatad(asclin1_rxdatad_reset_value)
    , m_asclin1_ocs(asclin1_ocs_reset_value)
    , m_asclin1_krstclr(asclin1_krstclr_reset_value)
    , m_asclin1_krst1(asclin1_krst1_reset_value)
    , m_asclin1_krst0(asclin1_krst0_reset_value)
    , m_asclin1_accen1(asclin1_accen1_reset_value)
    , m_asclin1_accen0(asclin1_accen0_reset_value)
    , m_asclin2_clc(asclin2_clc_reset_value)
    , m_asclin2_iocr(asclin2_iocr_reset_value)
    , m_asclin2_id(asclin2_id_reset_value)
    , m_asclin2_txfifocon(asclin2_txfifocon_reset_value)
    , m_asclin2_rxfifocon(asclin2_rxfifocon_reset_value)
    , m_asclin2_bitcon(asclin2_bitcon_reset_value)
    , m_asclin2_framecon(asclin2_framecon_reset_value)
    , m_asclin2_datcon(asclin2_datcon_reset_value)
    , m_asclin2_brg(asclin2_brg_reset_value)
    , m_asclin2_brd(asclin2_brd_reset_value)
    , m_asclin2_lin_con(asclin2_lin_con_reset_value)
    , m_asclin2_lin_btimer(asclin2_lin_btimer_reset_value)
    , m_asclin2_lin_htimer(asclin2_lin_htimer_reset_value)
    , m_asclin2_flags(asclin2_flags_reset_value)
    , m_asclin2_flagsset(asclin2_flagsset_reset_value)
    , m_asclin2_flagsclear(asclin2_flagsclear_reset_value)
    , m_asclin2_flagsenable(asclin2_flagsenable_reset_value)
    , m_asclin2_txdata(asclin2_txdata_reset_value)
    , m_asclin2_rxdata(asclin2_rxdata_reset_value)
    , m_asclin2_csr(asclin2_csr_reset_value)
    , m_asclin2_rxdatad(asclin2_rxdatad_reset_value)
    , m_asclin2_ocs(asclin2_ocs_reset_value)
    , m_asclin2_krstclr(asclin2_krstclr_reset_value)
    , m_asclin2_krst1(asclin2_krst1_reset_value)
    , m_asclin2_krst0(asclin2_krst0_reset_value)
    , m_asclin2_accen1(asclin2_accen1_reset_value)
    , m_asclin2_accen0(asclin2_accen0_reset_value)
    , m_asclin3_clc(asclin3_clc_reset_value)
    , m_asclin3_iocr(asclin3_iocr_reset_value)
    , m_asclin3_id(asclin3_id_reset_value)
    , m_asclin3_txfifocon(asclin3_txfifocon_reset_value)
    , m_asclin3_rxfifocon(asclin3_rxfifocon_reset_value)
    , m_asclin3_bitcon(asclin3_bitcon_reset_value)
    , m_asclin3_framecon(asclin3_framecon_reset_value)
    , m_asclin3_datcon(asclin3_datcon_reset_value)
    , m_asclin3_brg(asclin3_brg_reset_value)
    , m_asclin3_brd(asclin3_brd_reset_value)
    , m_asclin3_lin_con(asclin3_lin_con_reset_value)
    , m_asclin3_lin_btimer(asclin3_lin_btimer_reset_value)
    , m_asclin3_lin_htimer(asclin3_lin_htimer_reset_value)
    , m_asclin3_flags(asclin3_flags_reset_value)
    , m_asclin3_flagsset(asclin3_flagsset_reset_value)
    , m_asclin3_flagsclear(asclin3_flagsclear_reset_value)
    , m_asclin3_flagsenable(asclin3_flagsenable_reset_value)
    , m_asclin3_txdata(asclin3_txdata_reset_value)
    , m_asclin3_rxdata(asclin3_rxdata_reset_value)
    , m_asclin3_csr(asclin3_csr_reset_value)
    , m_asclin3_rxdatad(asclin3_rxdatad_reset_value)
    , m_asclin3_ocs(asclin3_ocs_reset_value)
    , m_asclin3_krstclr(asclin3_krstclr_reset_value)
    , m_asclin3_krst1(asclin3_krst1_reset_value)
    , m_asclin3_krst0(asclin3_krst0_reset_value)
    , m_asclin3_accen1(asclin3_accen1_reset_value)
    , m_asclin3_accen0(asclin3_accen0_reset_value)
    , m_asclin4_clc(asclin4_clc_reset_value)
    , m_asclin4_iocr(asclin4_iocr_reset_value)
    , m_asclin4_id(asclin4_id_reset_value)
    , m_asclin4_txfifocon(asclin4_txfifocon_reset_value)
    , m_asclin4_rxfifocon(asclin4_rxfifocon_reset_value)
    , m_asclin4_bitcon(asclin4_bitcon_reset_value)
    , m_asclin4_framecon(asclin4_framecon_reset_value)
    , m_asclin4_datcon(asclin4_datcon_reset_value)
    , m_asclin4_brg(asclin4_brg_reset_value)
    , m_asclin4_brd(asclin4_brd_reset_value)
    , m_asclin4_lin_con(asclin4_lin_con_reset_value)
    , m_asclin4_lin_btimer(asclin4_lin_btimer_reset_value)
    , m_asclin4_lin_htimer(asclin4_lin_htimer_reset_value)
    , m_asclin4_flags(asclin4_flags_reset_value)
    , m_asclin4_flagsset(asclin4_flagsset_reset_value)
    , m_asclin4_flagsclear(asclin4_flagsclear_reset_value)
    , m_asclin4_flagsenable(asclin4_flagsenable_reset_value)
    , m_asclin4_txdata(asclin4_txdata_reset_value)
    , m_asclin4_rxdata(asclin4_rxdata_reset_value)
    , m_asclin4_csr(asclin4_csr_reset_value)
    , m_asclin4_rxdatad(asclin4_rxdatad_reset_value)
    , m_asclin4_ocs(asclin4_ocs_reset_value)
    , m_asclin4_krstclr(asclin4_krstclr_reset_value)
    , m_asclin4_krst1(asclin4_krst1_reset_value)
    , m_asclin4_krst0(asclin4_krst0_reset_value)
    , m_asclin4_accen1(asclin4_accen1_reset_value)
    , m_asclin4_accen0(asclin4_accen0_reset_value)
    , m_asclin5_clc(asclin5_clc_reset_value)
    , m_asclin5_iocr(asclin5_iocr_reset_value)
    , m_asclin5_id(asclin5_id_reset_value)
    , m_asclin5_txfifocon(asclin5_txfifocon_reset_value)
    , m_asclin5_rxfifocon(asclin5_rxfifocon_reset_value)
    , m_asclin5_bitcon(asclin5_bitcon_reset_value)
    , m_asclin5_framecon(asclin5_framecon_reset_value)
    , m_asclin5_datcon(asclin5_datcon_reset_value)
    , m_asclin5_brg(asclin5_brg_reset_value)
    , m_asclin5_brd(asclin5_brd_reset_value)
    , m_asclin5_lin_con(asclin5_lin_con_reset_value)
    , m_asclin5_lin_btimer(asclin5_lin_btimer_reset_value)
    , m_asclin5_lin_htimer(asclin5_lin_htimer_reset_value)
    , m_asclin5_flags(asclin5_flags_reset_value)
    , m_asclin5_flagsset(asclin5_flagsset_reset_value)
    , m_asclin5_flagsclear(asclin5_flagsclear_reset_value)
    , m_asclin5_flagsenable(asclin5_flagsenable_reset_value)
    , m_asclin5_txdata(asclin5_txdata_reset_value)
    , m_asclin5_rxdata(asclin5_rxdata_reset_value)
    , m_asclin5_csr(asclin5_csr_reset_value)
    , m_asclin5_rxdatad(asclin5_rxdatad_reset_value)
    , m_asclin5_ocs(asclin5_ocs_reset_value)
    , m_asclin5_krstclr(asclin5_krstclr_reset_value)
    , m_asclin5_krst1(asclin5_krst1_reset_value)
    , m_asclin5_krst0(asclin5_krst0_reset_value)
    , m_asclin5_accen1(asclin5_accen1_reset_value)
    , m_asclin5_accen0(asclin5_accen0_reset_value)
    , m_asclin6_clc(asclin6_clc_reset_value)
    , m_asclin6_iocr(asclin6_iocr_reset_value)
    , m_asclin6_id(asclin6_id_reset_value)
    , m_asclin6_txfifocon(asclin6_txfifocon_reset_value)
    , m_asclin6_rxfifocon(asclin6_rxfifocon_reset_value)
    , m_asclin6_bitcon(asclin6_bitcon_reset_value)
    , m_asclin6_framecon(asclin6_framecon_reset_value)
    , m_asclin6_datcon(asclin6_datcon_reset_value)
    , m_asclin6_brg(asclin6_brg_reset_value)
    , m_asclin6_brd(asclin6_brd_reset_value)
    , m_asclin6_lin_con(asclin6_lin_con_reset_value)
    , m_asclin6_lin_btimer(asclin6_lin_btimer_reset_value)
    , m_asclin6_lin_htimer(asclin6_lin_htimer_reset_value)
    , m_asclin6_flags(asclin6_flags_reset_value)
    , m_asclin6_flagsset(asclin6_flagsset_reset_value)
    , m_asclin6_flagsclear(asclin6_flagsclear_reset_value)
    , m_asclin6_flagsenable(asclin6_flagsenable_reset_value)
    , m_asclin6_txdata(asclin6_txdata_reset_value)
    , m_asclin6_rxdata(asclin6_rxdata_reset_value)
    , m_asclin6_csr(asclin6_csr_reset_value)
    , m_asclin6_rxdatad(asclin6_rxdatad_reset_value)
    , m_asclin6_ocs(asclin6_ocs_reset_value)
    , m_asclin6_krstclr(asclin6_krstclr_reset_value)
    , m_asclin6_krst1(asclin6_krst1_reset_value)
    , m_asclin6_krst0(asclin6_krst0_reset_value)
    , m_asclin6_accen1(asclin6_accen1_reset_value)
    , m_asclin6_accen0(asclin6_accen0_reset_value)
    , m_asclin7_clc(asclin7_clc_reset_value)
    , m_asclin7_iocr(asclin7_iocr_reset_value)
    , m_asclin7_id(asclin7_id_reset_value)
    , m_asclin7_txfifocon(asclin7_txfifocon_reset_value)
    , m_asclin7_rxfifocon(asclin7_rxfifocon_reset_value)
    , m_asclin7_bitcon(asclin7_bitcon_reset_value)
    , m_asclin7_framecon(asclin7_framecon_reset_value)
    , m_asclin7_datcon(asclin7_datcon_reset_value)
    , m_asclin7_brg(asclin7_brg_reset_value)
    , m_asclin7_brd(asclin7_brd_reset_value)
    , m_asclin7_lin_con(asclin7_lin_con_reset_value)
    , m_asclin7_lin_btimer(asclin7_lin_btimer_reset_value)
    , m_asclin7_lin_htimer(asclin7_lin_htimer_reset_value)
    , m_asclin7_flags(asclin7_flags_reset_value)
    , m_asclin7_flagsset(asclin7_flagsset_reset_value)
    , m_asclin7_flagsclear(asclin7_flagsclear_reset_value)
    , m_asclin7_flagsenable(asclin7_flagsenable_reset_value)
    , m_asclin7_txdata(asclin7_txdata_reset_value)
    , m_asclin7_rxdata(asclin7_rxdata_reset_value)
    , m_asclin7_csr(asclin7_csr_reset_value)
    , m_asclin7_rxdatad(asclin7_rxdatad_reset_value)
    , m_asclin7_ocs(asclin7_ocs_reset_value)
    , m_asclin7_krstclr(asclin7_krstclr_reset_value)
    , m_asclin7_krst1(asclin7_krst1_reset_value)
    , m_asclin7_krst0(asclin7_krst0_reset_value)
    , m_asclin7_accen1(asclin7_accen1_reset_value)
    , m_asclin7_accen0(asclin7_accen0_reset_value)
    , m_asclin8_clc(asclin8_clc_reset_value)
    , m_asclin8_iocr(asclin8_iocr_reset_value)
    , m_asclin8_id(asclin8_id_reset_value)
    , m_asclin8_txfifocon(asclin8_txfifocon_reset_value)
    , m_asclin8_rxfifocon(asclin8_rxfifocon_reset_value)
    , m_asclin8_bitcon(asclin8_bitcon_reset_value)
    , m_asclin8_framecon(asclin8_framecon_reset_value)
    , m_asclin8_datcon(asclin8_datcon_reset_value)
    , m_asclin8_brg(asclin8_brg_reset_value)
    , m_asclin8_brd(asclin8_brd_reset_value)
    , m_asclin8_lin_con(asclin8_lin_con_reset_value)
    , m_asclin8_lin_btimer(asclin8_lin_btimer_reset_value)
    , m_asclin8_lin_htimer(asclin8_lin_htimer_reset_value)
    , m_asclin8_flags(asclin8_flags_reset_value)
    , m_asclin8_flagsset(asclin8_flagsset_reset_value)
    , m_asclin8_flagsclear(asclin8_flagsclear_reset_value)
    , m_asclin8_flagsenable(asclin8_flagsenable_reset_value)
    , m_asclin8_txdata(asclin8_txdata_reset_value)
    , m_asclin8_rxdata(asclin8_rxdata_reset_value)
    , m_asclin8_csr(asclin8_csr_reset_value)
    , m_asclin8_rxdatad(asclin8_rxdatad_reset_value)
    , m_asclin8_ocs(asclin8_ocs_reset_value)
    , m_asclin8_krstclr(asclin8_krstclr_reset_value)
    , m_asclin8_krst1(asclin8_krst1_reset_value)
    , m_asclin8_krst0(asclin8_krst0_reset_value)
    , m_asclin8_accen1(asclin8_accen1_reset_value)
    , m_asclin8_accen0(asclin8_accen0_reset_value)
    , m_asclin9_clc(asclin9_clc_reset_value)
    , m_asclin9_iocr(asclin9_iocr_reset_value)
    , m_asclin9_id(asclin9_id_reset_value)
    , m_asclin9_txfifocon(asclin9_txfifocon_reset_value)
    , m_asclin9_rxfifocon(asclin9_rxfifocon_reset_value)
    , m_asclin9_bitcon(asclin9_bitcon_reset_value)
    , m_asclin9_framecon(asclin9_framecon_reset_value)
    , m_asclin9_datcon(asclin9_datcon_reset_value)
    , m_asclin9_brg(asclin9_brg_reset_value)
    , m_asclin9_brd(asclin9_brd_reset_value)
    , m_asclin9_lin_con(asclin9_lin_con_reset_value)
    , m_asclin9_lin_btimer(asclin9_lin_btimer_reset_value)
    , m_asclin9_lin_htimer(asclin9_lin_htimer_reset_value)
    , m_asclin9_flags(asclin9_flags_reset_value)
    , m_asclin9_flagsset(asclin9_flagsset_reset_value)
    , m_asclin9_flagsclear(asclin9_flagsclear_reset_value)
    , m_asclin9_flagsenable(asclin9_flagsenable_reset_value)
    , m_asclin9_txdata(asclin9_txdata_reset_value)
    , m_asclin9_rxdata(asclin9_rxdata_reset_value)
    , m_asclin9_csr(asclin9_csr_reset_value)
    , m_asclin9_rxdatad(asclin9_rxdatad_reset_value)
    , m_asclin9_ocs(asclin9_ocs_reset_value)
    , m_asclin9_krstclr(asclin9_krstclr_reset_value)
    , m_asclin9_krst1(asclin9_krst1_reset_value)
    , m_asclin9_krst0(asclin9_krst0_reset_value)
    , m_asclin9_accen1(asclin9_accen1_reset_value)
    , m_asclin9_accen0(asclin9_accen0_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Asclin::read(std::byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - asclin_memory_start_address;
    switch (offset) {
    case reg_asclin0_clc_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_iocr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_IOCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_iocr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_id_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_txfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_TXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_txfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_rxfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_RXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_rxfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_bitcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_BITCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_bitcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_framecon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_FRAMECON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_framecon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_datcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_DATCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_datcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_brg_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_BRG in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_brg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_brd_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_BRD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_brd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_lin_con_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_LIN_CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_lin_con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_lin_btimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_LIN_BTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_lin_btimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_lin_htimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_LIN_HTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_lin_htimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_flags_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_FLAGS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_flags);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_flagsset_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_FLAGSSET in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_flagsset);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_flagsclear_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_FLAGSCLEAR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_flagsclear);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_flagsenable_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_FLAGSENABLE in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_flagsenable);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_txdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_TXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_txdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_rxdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_RXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_rxdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_csr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_CSR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_csr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_rxdatad_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_RXDATAD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_rxdatad);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_ocs_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_krstclr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_krst1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_krst0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_accen1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin0_accen0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin0_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_clc_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_iocr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_IOCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_iocr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_id_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_txfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_TXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_txfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_rxfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_RXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_rxfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_bitcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_BITCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_bitcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_framecon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_FRAMECON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_framecon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_datcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_DATCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_datcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_brg_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_BRG in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_brg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_brd_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_BRD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_brd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_lin_con_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_LIN_CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_lin_con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_lin_btimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_LIN_BTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_lin_btimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_lin_htimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_LIN_HTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_lin_htimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_flags_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_FLAGS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_flags);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_flagsset_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_FLAGSSET in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_flagsset);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_flagsclear_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_FLAGSCLEAR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_flagsclear);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_flagsenable_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_FLAGSENABLE in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_flagsenable);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_txdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_TXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_txdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_rxdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_RXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_rxdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_csr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_CSR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_csr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_rxdatad_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_RXDATAD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_rxdatad);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_ocs_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_krstclr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_krst1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_krst0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_accen1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin1_accen0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin1_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_clc_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_iocr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_IOCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_iocr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_id_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_txfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_TXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_txfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_rxfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_RXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_rxfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_bitcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_BITCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_bitcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_framecon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_FRAMECON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_framecon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_datcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_DATCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_datcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_brg_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_BRG in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_brg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_brd_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_BRD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_brd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_lin_con_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_LIN_CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_lin_con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_lin_btimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_LIN_BTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_lin_btimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_lin_htimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_LIN_HTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_lin_htimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_flags_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_FLAGS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_flags);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_flagsset_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_FLAGSSET in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_flagsset);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_flagsclear_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_FLAGSCLEAR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_flagsclear);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_flagsenable_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_FLAGSENABLE in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_flagsenable);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_txdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_TXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_txdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_rxdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_RXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_rxdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_csr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_CSR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_csr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_rxdatad_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_RXDATAD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_rxdatad);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_ocs_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_krstclr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_krst1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_krst0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_accen1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin2_accen0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin2_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_clc_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_iocr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_IOCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_iocr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_id_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_txfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_TXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_txfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_rxfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_RXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_rxfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_bitcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_BITCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_bitcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_framecon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_FRAMECON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_framecon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_datcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_DATCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_datcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_brg_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_BRG in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_brg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_brd_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_BRD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_brd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_lin_con_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_LIN_CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_lin_con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_lin_btimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_LIN_BTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_lin_btimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_lin_htimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_LIN_HTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_lin_htimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_flags_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_FLAGS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_flags);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_flagsset_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_FLAGSSET in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_flagsset);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_flagsclear_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_FLAGSCLEAR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_flagsclear);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_flagsenable_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_FLAGSENABLE in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_flagsenable);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_txdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_TXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_txdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_rxdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_RXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_rxdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_csr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_CSR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_csr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_rxdatad_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_RXDATAD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_rxdatad);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_ocs_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_krstclr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_krst1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_krst0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_accen1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin3_accen0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin3_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_clc_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_iocr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_IOCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_iocr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_id_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_txfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_TXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_txfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_rxfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_RXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_rxfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_bitcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_BITCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_bitcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_framecon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_FRAMECON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_framecon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_datcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_DATCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_datcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_brg_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_BRG in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_brg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_brd_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_BRD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_brd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_lin_con_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_LIN_CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_lin_con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_lin_btimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_LIN_BTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_lin_btimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_lin_htimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_LIN_HTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_lin_htimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_flags_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_FLAGS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_flags);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_flagsset_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_FLAGSSET in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_flagsset);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_flagsclear_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_FLAGSCLEAR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_flagsclear);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_flagsenable_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_FLAGSENABLE in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_flagsenable);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_txdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_TXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_txdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_rxdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_RXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_rxdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_csr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_CSR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_csr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_rxdatad_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_RXDATAD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_rxdatad);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_ocs_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_krstclr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_krst1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_krst0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_accen1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin4_accen0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin4_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_clc_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_iocr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_IOCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_iocr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_id_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_txfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_TXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_txfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_rxfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_RXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_rxfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_bitcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_BITCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_bitcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_framecon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_FRAMECON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_framecon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_datcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_DATCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_datcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_brg_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_BRG in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_brg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_brd_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_BRD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_brd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_lin_con_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_LIN_CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_lin_con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_lin_btimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_LIN_BTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_lin_btimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_lin_htimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_LIN_HTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_lin_htimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_flags_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_FLAGS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_flags);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_flagsset_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_FLAGSSET in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_flagsset);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_flagsclear_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_FLAGSCLEAR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_flagsclear);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_flagsenable_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_FLAGSENABLE in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_flagsenable);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_txdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_TXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_txdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_rxdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_RXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_rxdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_csr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_CSR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_csr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_rxdatad_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_RXDATAD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_rxdatad);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_ocs_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_krstclr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_krst1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_krst0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_accen1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin5_accen0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin5_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_clc_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_iocr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_IOCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_iocr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_id_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_txfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_TXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_txfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_rxfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_RXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_rxfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_bitcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_BITCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_bitcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_framecon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_FRAMECON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_framecon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_datcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_DATCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_datcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_brg_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_BRG in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_brg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_brd_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_BRD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_brd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_lin_con_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_LIN_CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_lin_con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_lin_btimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_LIN_BTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_lin_btimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_lin_htimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_LIN_HTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_lin_htimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_flags_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_FLAGS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_flags);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_flagsset_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_FLAGSSET in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_flagsset);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_flagsclear_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_FLAGSCLEAR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_flagsclear);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_flagsenable_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_FLAGSENABLE in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_flagsenable);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_txdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_TXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_txdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_rxdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_RXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_rxdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_csr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_CSR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_csr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_rxdatad_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_RXDATAD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_rxdatad);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_ocs_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_krstclr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_krst1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_krst0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_accen1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin6_accen0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin6_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_clc_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_iocr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_IOCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_iocr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_id_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_txfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_TXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_txfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_rxfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_RXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_rxfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_bitcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_BITCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_bitcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_framecon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_FRAMECON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_framecon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_datcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_DATCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_datcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_brg_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_BRG in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_brg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_brd_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_BRD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_brd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_lin_con_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_LIN_CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_lin_con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_lin_btimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_LIN_BTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_lin_btimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_lin_htimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_LIN_HTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_lin_htimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_flags_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_FLAGS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_flags);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_flagsset_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_FLAGSSET in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_flagsset);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_flagsclear_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_FLAGSCLEAR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_flagsclear);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_flagsenable_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_FLAGSENABLE in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_flagsenable);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_txdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_TXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_txdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_rxdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_RXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_rxdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_csr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_CSR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_csr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_rxdatad_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_RXDATAD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_rxdatad);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_ocs_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_krstclr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_krst1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_krst0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_accen1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin7_accen0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin7_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_clc_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_iocr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_IOCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_iocr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_id_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_txfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_TXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_txfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_rxfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_RXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_rxfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_bitcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_BITCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_bitcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_framecon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_FRAMECON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_framecon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_datcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_DATCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_datcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_brg_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_BRG in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_brg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_brd_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_BRD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_brd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_lin_con_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_LIN_CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_lin_con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_lin_btimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_LIN_BTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_lin_btimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_lin_htimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_LIN_HTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_lin_htimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_flags_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_FLAGS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_flags);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_flagsset_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_FLAGSSET in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_flagsset);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_flagsclear_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_FLAGSCLEAR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_flagsclear);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_flagsenable_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_FLAGSENABLE in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_flagsenable);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_txdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_TXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_txdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_rxdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_RXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_rxdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_csr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_CSR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_csr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_rxdatad_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_RXDATAD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_rxdatad);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_ocs_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_krstclr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_krst1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_krst0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_accen1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin8_accen0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin8_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_clc_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_iocr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_IOCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_iocr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_id_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_txfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_TXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_txfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_rxfifocon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_RXFIFOCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_rxfifocon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_bitcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_BITCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_bitcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_framecon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_FRAMECON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_framecon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_datcon_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_DATCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_datcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_brg_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_BRG in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_brg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_brd_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_BRD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_brd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_lin_con_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_LIN_CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_lin_con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_lin_btimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_LIN_BTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_lin_btimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_lin_htimer_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_LIN_HTIMER in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_lin_htimer);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_flags_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_FLAGS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_flags);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_flagsset_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_FLAGSSET in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_flagsset);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_flagsclear_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_FLAGSCLEAR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_flagsclear);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_flagsenable_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_FLAGSENABLE in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_flagsenable);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_txdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_TXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_txdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_rxdata_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_RXDATA in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_rxdata);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_csr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_CSR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_csr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_rxdatad_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_RXDATAD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_rxdatad);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_ocs_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_krstclr_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_krst1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_krst0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_accen1_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_asclin9_accen0_offset: {
            spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_asclin9_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Asclin peripheral", address)};
        break;
    }
}

void Tricore::Asclin::write(const std::byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - asclin_memory_start_address;
    switch (offset) {
    case reg_asclin0_clc_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_clc));
    } break;
    case reg_asclin0_iocr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_IOCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_iocr));
    } break;
    case reg_asclin0_id_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_id));
    } break;
    case reg_asclin0_txfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_TXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_txfifocon));
    } break;
    case reg_asclin0_rxfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_RXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_rxfifocon));
    } break;
    case reg_asclin0_bitcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_BITCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_bitcon));
    } break;
    case reg_asclin0_framecon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_FRAMECON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_framecon));
    } break;
    case reg_asclin0_datcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_DATCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_datcon));
    } break;
    case reg_asclin0_brg_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_BRG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_brg));
    } break;
    case reg_asclin0_brd_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_BRD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_brd));
    } break;
    case reg_asclin0_lin_con_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_LIN_CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_lin_con));
    } break;
    case reg_asclin0_lin_btimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_LIN_BTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_lin_btimer));
    } break;
    case reg_asclin0_lin_htimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_LIN_HTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_lin_htimer));
    } break;
    case reg_asclin0_flags_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_FLAGS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_flags));
    } break;
    case reg_asclin0_flagsset_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_FLAGSSET in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_flagsset));
    } break;
    case reg_asclin0_flagsclear_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_flagsclear));
    } break;
    case reg_asclin0_flagsenable_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_FLAGSENABLE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_flagsenable));
    } break;
    case reg_asclin0_txdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_TXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_txdata));
    } break;
    case reg_asclin0_rxdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_RXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_rxdata));
    } break;
    case reg_asclin0_csr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_CSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_csr));
    } break;
    case reg_asclin0_rxdatad_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_RXDATAD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_rxdatad));
    } break;
    case reg_asclin0_ocs_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_ocs));
    } break;
    case reg_asclin0_krstclr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_krstclr));
    } break;
    case reg_asclin0_krst1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_krst1));
    } break;
    case reg_asclin0_krst0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_krst0));
    } break;
    case reg_asclin0_accen1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_accen1));
    } break;
    case reg_asclin0_accen0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN0_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin0_accen0));
    } break;
    case reg_asclin1_clc_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_clc));
    } break;
    case reg_asclin1_iocr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_IOCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_iocr));
    } break;
    case reg_asclin1_id_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_id));
    } break;
    case reg_asclin1_txfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_TXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_txfifocon));
    } break;
    case reg_asclin1_rxfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_RXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_rxfifocon));
    } break;
    case reg_asclin1_bitcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_BITCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_bitcon));
    } break;
    case reg_asclin1_framecon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_FRAMECON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_framecon));
    } break;
    case reg_asclin1_datcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_DATCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_datcon));
    } break;
    case reg_asclin1_brg_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_BRG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_brg));
    } break;
    case reg_asclin1_brd_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_BRD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_brd));
    } break;
    case reg_asclin1_lin_con_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_LIN_CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_lin_con));
    } break;
    case reg_asclin1_lin_btimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_LIN_BTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_lin_btimer));
    } break;
    case reg_asclin1_lin_htimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_LIN_HTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_lin_htimer));
    } break;
    case reg_asclin1_flags_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_FLAGS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_flags));
    } break;
    case reg_asclin1_flagsset_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_FLAGSSET in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_flagsset));
    } break;
    case reg_asclin1_flagsclear_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_flagsclear));
    } break;
    case reg_asclin1_flagsenable_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_FLAGSENABLE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_flagsenable));
    } break;
    case reg_asclin1_txdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_TXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_txdata));
    } break;
    case reg_asclin1_rxdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_RXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_rxdata));
    } break;
    case reg_asclin1_csr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_CSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_csr));
    } break;
    case reg_asclin1_rxdatad_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_RXDATAD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_rxdatad));
    } break;
    case reg_asclin1_ocs_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_ocs));
    } break;
    case reg_asclin1_krstclr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_krstclr));
    } break;
    case reg_asclin1_krst1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_krst1));
    } break;
    case reg_asclin1_krst0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_krst0));
    } break;
    case reg_asclin1_accen1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_accen1));
    } break;
    case reg_asclin1_accen0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN1_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin1_accen0));
    } break;
    case reg_asclin2_clc_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_clc));
    } break;
    case reg_asclin2_iocr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_IOCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_iocr));
    } break;
    case reg_asclin2_id_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_id));
    } break;
    case reg_asclin2_txfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_TXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_txfifocon));
    } break;
    case reg_asclin2_rxfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_RXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_rxfifocon));
    } break;
    case reg_asclin2_bitcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_BITCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_bitcon));
    } break;
    case reg_asclin2_framecon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_FRAMECON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_framecon));
    } break;
    case reg_asclin2_datcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_DATCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_datcon));
    } break;
    case reg_asclin2_brg_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_BRG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_brg));
    } break;
    case reg_asclin2_brd_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_BRD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_brd));
    } break;
    case reg_asclin2_lin_con_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_LIN_CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_lin_con));
    } break;
    case reg_asclin2_lin_btimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_LIN_BTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_lin_btimer));
    } break;
    case reg_asclin2_lin_htimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_LIN_HTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_lin_htimer));
    } break;
    case reg_asclin2_flags_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_FLAGS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_flags));
    } break;
    case reg_asclin2_flagsset_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_FLAGSSET in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_flagsset));
    } break;
    case reg_asclin2_flagsclear_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_flagsclear));
    } break;
    case reg_asclin2_flagsenable_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_FLAGSENABLE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_flagsenable));
    } break;
    case reg_asclin2_txdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_TXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_txdata));
    } break;
    case reg_asclin2_rxdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_RXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_rxdata));
    } break;
    case reg_asclin2_csr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_CSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_csr));
    } break;
    case reg_asclin2_rxdatad_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_RXDATAD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_rxdatad));
    } break;
    case reg_asclin2_ocs_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_ocs));
    } break;
    case reg_asclin2_krstclr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_krstclr));
    } break;
    case reg_asclin2_krst1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_krst1));
    } break;
    case reg_asclin2_krst0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_krst0));
    } break;
    case reg_asclin2_accen1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_accen1));
    } break;
    case reg_asclin2_accen0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN2_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin2_accen0));
    } break;
    case reg_asclin3_clc_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_clc));
    } break;
    case reg_asclin3_iocr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_IOCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_iocr));
    } break;
    case reg_asclin3_id_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_id));
    } break;
    case reg_asclin3_txfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_TXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_txfifocon));
    } break;
    case reg_asclin3_rxfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_RXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_rxfifocon));
    } break;
    case reg_asclin3_bitcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_BITCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_bitcon));
    } break;
    case reg_asclin3_framecon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_FRAMECON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_framecon));
    } break;
    case reg_asclin3_datcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_DATCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_datcon));
    } break;
    case reg_asclin3_brg_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_BRG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_brg));
    } break;
    case reg_asclin3_brd_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_BRD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_brd));
    } break;
    case reg_asclin3_lin_con_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_LIN_CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_lin_con));
    } break;
    case reg_asclin3_lin_btimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_LIN_BTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_lin_btimer));
    } break;
    case reg_asclin3_lin_htimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_LIN_HTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_lin_htimer));
    } break;
    case reg_asclin3_flags_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_FLAGS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_flags));
    } break;
    case reg_asclin3_flagsset_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_FLAGSSET in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_flagsset));
    } break;
    case reg_asclin3_flagsclear_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_flagsclear));
    } break;
    case reg_asclin3_flagsenable_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_FLAGSENABLE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_flagsenable));
    } break;
    case reg_asclin3_txdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_TXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_txdata));
    } break;
    case reg_asclin3_rxdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_RXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_rxdata));
    } break;
    case reg_asclin3_csr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_CSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_csr));
    } break;
    case reg_asclin3_rxdatad_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_RXDATAD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_rxdatad));
    } break;
    case reg_asclin3_ocs_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_ocs));
    } break;
    case reg_asclin3_krstclr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_krstclr));
    } break;
    case reg_asclin3_krst1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_krst1));
    } break;
    case reg_asclin3_krst0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_krst0));
    } break;
    case reg_asclin3_accen1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_accen1));
    } break;
    case reg_asclin3_accen0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN3_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin3_accen0));
    } break;
    case reg_asclin4_clc_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_clc));
    } break;
    case reg_asclin4_iocr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_IOCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_iocr));
    } break;
    case reg_asclin4_id_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_id));
    } break;
    case reg_asclin4_txfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_TXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_txfifocon));
    } break;
    case reg_asclin4_rxfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_RXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_rxfifocon));
    } break;
    case reg_asclin4_bitcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_BITCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_bitcon));
    } break;
    case reg_asclin4_framecon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_FRAMECON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_framecon));
    } break;
    case reg_asclin4_datcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_DATCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_datcon));
    } break;
    case reg_asclin4_brg_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_BRG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_brg));
    } break;
    case reg_asclin4_brd_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_BRD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_brd));
    } break;
    case reg_asclin4_lin_con_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_LIN_CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_lin_con));
    } break;
    case reg_asclin4_lin_btimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_LIN_BTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_lin_btimer));
    } break;
    case reg_asclin4_lin_htimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_LIN_HTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_lin_htimer));
    } break;
    case reg_asclin4_flags_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_FLAGS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_flags));
    } break;
    case reg_asclin4_flagsset_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_FLAGSSET in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_flagsset));
    } break;
    case reg_asclin4_flagsclear_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_flagsclear));
    } break;
    case reg_asclin4_flagsenable_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_FLAGSENABLE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_flagsenable));
    } break;
    case reg_asclin4_txdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_TXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_txdata));
    } break;
    case reg_asclin4_rxdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_RXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_rxdata));
    } break;
    case reg_asclin4_csr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_CSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_csr));
    } break;
    case reg_asclin4_rxdatad_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_RXDATAD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_rxdatad));
    } break;
    case reg_asclin4_ocs_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_ocs));
    } break;
    case reg_asclin4_krstclr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_krstclr));
    } break;
    case reg_asclin4_krst1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_krst1));
    } break;
    case reg_asclin4_krst0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_krst0));
    } break;
    case reg_asclin4_accen1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_accen1));
    } break;
    case reg_asclin4_accen0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN4_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin4_accen0));
    } break;
    case reg_asclin5_clc_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_clc));
    } break;
    case reg_asclin5_iocr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_IOCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_iocr));
    } break;
    case reg_asclin5_id_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_id));
    } break;
    case reg_asclin5_txfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_TXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_txfifocon));
    } break;
    case reg_asclin5_rxfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_RXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_rxfifocon));
    } break;
    case reg_asclin5_bitcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_BITCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_bitcon));
    } break;
    case reg_asclin5_framecon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_FRAMECON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_framecon));
    } break;
    case reg_asclin5_datcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_DATCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_datcon));
    } break;
    case reg_asclin5_brg_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_BRG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_brg));
    } break;
    case reg_asclin5_brd_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_BRD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_brd));
    } break;
    case reg_asclin5_lin_con_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_LIN_CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_lin_con));
    } break;
    case reg_asclin5_lin_btimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_LIN_BTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_lin_btimer));
    } break;
    case reg_asclin5_lin_htimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_LIN_HTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_lin_htimer));
    } break;
    case reg_asclin5_flags_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_FLAGS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_flags));
    } break;
    case reg_asclin5_flagsset_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_FLAGSSET in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_flagsset));
    } break;
    case reg_asclin5_flagsclear_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_flagsclear));
    } break;
    case reg_asclin5_flagsenable_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_FLAGSENABLE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_flagsenable));
    } break;
    case reg_asclin5_txdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_TXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_txdata));
    } break;
    case reg_asclin5_rxdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_RXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_rxdata));
    } break;
    case reg_asclin5_csr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_CSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_csr));
    } break;
    case reg_asclin5_rxdatad_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_RXDATAD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_rxdatad));
    } break;
    case reg_asclin5_ocs_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_ocs));
    } break;
    case reg_asclin5_krstclr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_krstclr));
    } break;
    case reg_asclin5_krst1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_krst1));
    } break;
    case reg_asclin5_krst0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_krst0));
    } break;
    case reg_asclin5_accen1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_accen1));
    } break;
    case reg_asclin5_accen0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN5_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin5_accen0));
    } break;
    case reg_asclin6_clc_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_clc));
    } break;
    case reg_asclin6_iocr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_IOCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_iocr));
    } break;
    case reg_asclin6_id_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_id));
    } break;
    case reg_asclin6_txfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_TXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_txfifocon));
    } break;
    case reg_asclin6_rxfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_RXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_rxfifocon));
    } break;
    case reg_asclin6_bitcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_BITCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_bitcon));
    } break;
    case reg_asclin6_framecon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_FRAMECON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_framecon));
    } break;
    case reg_asclin6_datcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_DATCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_datcon));
    } break;
    case reg_asclin6_brg_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_BRG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_brg));
    } break;
    case reg_asclin6_brd_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_BRD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_brd));
    } break;
    case reg_asclin6_lin_con_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_LIN_CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_lin_con));
    } break;
    case reg_asclin6_lin_btimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_LIN_BTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_lin_btimer));
    } break;
    case reg_asclin6_lin_htimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_LIN_HTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_lin_htimer));
    } break;
    case reg_asclin6_flags_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_FLAGS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_flags));
    } break;
    case reg_asclin6_flagsset_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_FLAGSSET in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_flagsset));
    } break;
    case reg_asclin6_flagsclear_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_flagsclear));
    } break;
    case reg_asclin6_flagsenable_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_FLAGSENABLE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_flagsenable));
    } break;
    case reg_asclin6_txdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_TXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_txdata));
    } break;
    case reg_asclin6_rxdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_RXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_rxdata));
    } break;
    case reg_asclin6_csr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_CSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_csr));
    } break;
    case reg_asclin6_rxdatad_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_RXDATAD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_rxdatad));
    } break;
    case reg_asclin6_ocs_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_ocs));
    } break;
    case reg_asclin6_krstclr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_krstclr));
    } break;
    case reg_asclin6_krst1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_krst1));
    } break;
    case reg_asclin6_krst0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_krst0));
    } break;
    case reg_asclin6_accen1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_accen1));
    } break;
    case reg_asclin6_accen0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN6_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin6_accen0));
    } break;
    case reg_asclin7_clc_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_clc));
    } break;
    case reg_asclin7_iocr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_IOCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_iocr));
    } break;
    case reg_asclin7_id_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_id));
    } break;
    case reg_asclin7_txfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_TXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_txfifocon));
    } break;
    case reg_asclin7_rxfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_RXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_rxfifocon));
    } break;
    case reg_asclin7_bitcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_BITCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_bitcon));
    } break;
    case reg_asclin7_framecon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_FRAMECON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_framecon));
    } break;
    case reg_asclin7_datcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_DATCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_datcon));
    } break;
    case reg_asclin7_brg_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_BRG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_brg));
    } break;
    case reg_asclin7_brd_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_BRD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_brd));
    } break;
    case reg_asclin7_lin_con_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_LIN_CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_lin_con));
    } break;
    case reg_asclin7_lin_btimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_LIN_BTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_lin_btimer));
    } break;
    case reg_asclin7_lin_htimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_LIN_HTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_lin_htimer));
    } break;
    case reg_asclin7_flags_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_FLAGS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_flags));
    } break;
    case reg_asclin7_flagsset_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_FLAGSSET in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_flagsset));
    } break;
    case reg_asclin7_flagsclear_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_flagsclear));
    } break;
    case reg_asclin7_flagsenable_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_FLAGSENABLE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_flagsenable));
    } break;
    case reg_asclin7_txdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_TXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_txdata));
    } break;
    case reg_asclin7_rxdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_RXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_rxdata));
    } break;
    case reg_asclin7_csr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_CSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_csr));
    } break;
    case reg_asclin7_rxdatad_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_RXDATAD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_rxdatad));
    } break;
    case reg_asclin7_ocs_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_ocs));
    } break;
    case reg_asclin7_krstclr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_krstclr));
    } break;
    case reg_asclin7_krst1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_krst1));
    } break;
    case reg_asclin7_krst0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_krst0));
    } break;
    case reg_asclin7_accen1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_accen1));
    } break;
    case reg_asclin7_accen0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN7_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin7_accen0));
    } break;
    case reg_asclin8_clc_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_clc));
    } break;
    case reg_asclin8_iocr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_IOCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_iocr));
    } break;
    case reg_asclin8_id_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_id));
    } break;
    case reg_asclin8_txfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_TXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_txfifocon));
    } break;
    case reg_asclin8_rxfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_RXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_rxfifocon));
    } break;
    case reg_asclin8_bitcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_BITCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_bitcon));
    } break;
    case reg_asclin8_framecon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_FRAMECON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_framecon));
    } break;
    case reg_asclin8_datcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_DATCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_datcon));
    } break;
    case reg_asclin8_brg_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_BRG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_brg));
    } break;
    case reg_asclin8_brd_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_BRD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_brd));
    } break;
    case reg_asclin8_lin_con_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_LIN_CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_lin_con));
    } break;
    case reg_asclin8_lin_btimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_LIN_BTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_lin_btimer));
    } break;
    case reg_asclin8_lin_htimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_LIN_HTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_lin_htimer));
    } break;
    case reg_asclin8_flags_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_FLAGS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_flags));
    } break;
    case reg_asclin8_flagsset_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_FLAGSSET in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_flagsset));
    } break;
    case reg_asclin8_flagsclear_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_flagsclear));
    } break;
    case reg_asclin8_flagsenable_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_FLAGSENABLE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_flagsenable));
    } break;
    case reg_asclin8_txdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_TXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_txdata));
    } break;
    case reg_asclin8_rxdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_RXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_rxdata));
    } break;
    case reg_asclin8_csr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_CSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_csr));
    } break;
    case reg_asclin8_rxdatad_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_RXDATAD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_rxdatad));
    } break;
    case reg_asclin8_ocs_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_ocs));
    } break;
    case reg_asclin8_krstclr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_krstclr));
    } break;
    case reg_asclin8_krst1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_krst1));
    } break;
    case reg_asclin8_krst0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_krst0));
    } break;
    case reg_asclin8_accen1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_accen1));
    } break;
    case reg_asclin8_accen0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN8_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin8_accen0));
    } break;
    case reg_asclin9_clc_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_clc));
    } break;
    case reg_asclin9_iocr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_IOCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_iocr));
    } break;
    case reg_asclin9_id_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_id));
    } break;
    case reg_asclin9_txfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_TXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_txfifocon));
    } break;
    case reg_asclin9_rxfifocon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_RXFIFOCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_rxfifocon));
    } break;
    case reg_asclin9_bitcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_BITCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_bitcon));
    } break;
    case reg_asclin9_framecon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_FRAMECON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_framecon));
    } break;
    case reg_asclin9_datcon_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_DATCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_datcon));
    } break;
    case reg_asclin9_brg_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_BRG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_brg));
    } break;
    case reg_asclin9_brd_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_BRD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_brd));
    } break;
    case reg_asclin9_lin_con_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_LIN_CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_lin_con));
    } break;
    case reg_asclin9_lin_btimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_LIN_BTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_lin_btimer));
    } break;
    case reg_asclin9_lin_htimer_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_LIN_HTIMER in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_lin_htimer));
    } break;
    case reg_asclin9_flags_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_FLAGS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_flags));
    } break;
    case reg_asclin9_flagsset_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_FLAGSSET in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_flagsset));
    } break;
    case reg_asclin9_flagsclear_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_FLAGSCLEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_flagsclear));
    } break;
    case reg_asclin9_flagsenable_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_FLAGSENABLE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_flagsenable));
    } break;
    case reg_asclin9_txdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_TXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_txdata));
    } break;
    case reg_asclin9_rxdata_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_RXDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_rxdata));
    } break;
    case reg_asclin9_csr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_CSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_csr));
    } break;
    case reg_asclin9_rxdatad_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_RXDATAD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_rxdatad));
    } break;
    case reg_asclin9_ocs_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_ocs));
    } break;
    case reg_asclin9_krstclr_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_krstclr));
    } break;
    case reg_asclin9_krst1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_krst1));
    } break;
    case reg_asclin9_krst0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_krst0));
    } break;
    case reg_asclin9_accen1_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_accen1));
    } break;
    case reg_asclin9_accen0_offset: {
        spdlog::debug("ASCLIN: accessing ASCLIN.ASCLIN9_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_asclin9_accen0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Asclin peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
