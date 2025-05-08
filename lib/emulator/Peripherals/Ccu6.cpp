
/**
 * @brief Module source for Ccu6 peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Ccu6.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 ccu60_clc_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_mcfg_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_id_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_mosel_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_pisel0_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_pisel2_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_kscsr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_t12_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_t12pr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_t12dtc_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_t13_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_t13pr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_cc63r_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_cc63sr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_cmpstat_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_cmpmodif_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_t12msel_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_tctr0_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_tctr2_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_tctr4_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_modctr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_trpctr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_pslr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_mcmouts_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_mcmout_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_mcmctr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_imon_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_li_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_is_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_iss_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_isr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_inp_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_ien_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 ccu60_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_clc_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_mcfg_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_id_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_pisel0_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_pisel2_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_kscsr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_t12_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_t12pr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_t12dtc_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_t13_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_t13pr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_cc63r_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_cc63sr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_cmpstat_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_cmpmodif_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_t12msel_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_tctr0_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_tctr2_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_tctr4_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_modctr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_trpctr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_pslr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_mcmouts_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_mcmout_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_mcmctr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_imon_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_li_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_is_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_iss_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_isr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_inp_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_ien_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 ccu61_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 ccu6_memory_start_address = 0xf0002a00U;
constexpr u32 ccu6_memory_size = 0; // TODO: update according manual;
constexpr u32 ccu6_memory_end_address = ccu6_memory_start_address + ccu6_memory_size;

constexpr u32 reg_ccu60_clc_address = 0xf0002a00;
constexpr u32 reg_ccu60_clc_offset = reg_ccu60_clc_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_mcfg_address = 0xf0002a04;
constexpr u32 reg_ccu60_mcfg_offset = reg_ccu60_mcfg_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_id_address = 0xf0002a08;
constexpr u32 reg_ccu60_id_offset = reg_ccu60_id_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_mosel_address = 0xf0002a0c;
constexpr u32 reg_ccu60_mosel_offset = reg_ccu60_mosel_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_pisel0_address = 0xf0002a10;
constexpr u32 reg_ccu60_pisel0_offset = reg_ccu60_pisel0_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_pisel2_address = 0xf0002a14;
constexpr u32 reg_ccu60_pisel2_offset = reg_ccu60_pisel2_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_kscsr_address = 0xf0002a1c;
constexpr u32 reg_ccu60_kscsr_offset = reg_ccu60_kscsr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_t12_address = 0xf0002a20;
constexpr u32 reg_ccu60_t12_offset = reg_ccu60_t12_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_t12pr_address = 0xf0002a24;
constexpr u32 reg_ccu60_t12pr_offset = reg_ccu60_t12pr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_t12dtc_address = 0xf0002a28;
constexpr u32 reg_ccu60_t12dtc_offset = reg_ccu60_t12dtc_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_t13_address = 0xf0002a50;
constexpr u32 reg_ccu60_t13_offset = reg_ccu60_t13_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_t13pr_address = 0xf0002a54;
constexpr u32 reg_ccu60_t13pr_offset = reg_ccu60_t13pr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_cc63r_address = 0xf0002a58;
constexpr u32 reg_ccu60_cc63r_offset = reg_ccu60_cc63r_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_cc63sr_address = 0xf0002a5c;
constexpr u32 reg_ccu60_cc63sr_offset = reg_ccu60_cc63sr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_cmpstat_address = 0xf0002a60;
constexpr u32 reg_ccu60_cmpstat_offset = reg_ccu60_cmpstat_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_cmpmodif_address = 0xf0002a64;
constexpr u32 reg_ccu60_cmpmodif_offset = reg_ccu60_cmpmodif_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_t12msel_address = 0xf0002a68;
constexpr u32 reg_ccu60_t12msel_offset = reg_ccu60_t12msel_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_tctr0_address = 0xf0002a70;
constexpr u32 reg_ccu60_tctr0_offset = reg_ccu60_tctr0_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_tctr2_address = 0xf0002a74;
constexpr u32 reg_ccu60_tctr2_offset = reg_ccu60_tctr2_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_tctr4_address = 0xf0002a78;
constexpr u32 reg_ccu60_tctr4_offset = reg_ccu60_tctr4_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_modctr_address = 0xf0002a80;
constexpr u32 reg_ccu60_modctr_offset = reg_ccu60_modctr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_trpctr_address = 0xf0002a84;
constexpr u32 reg_ccu60_trpctr_offset = reg_ccu60_trpctr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_pslr_address = 0xf0002a88;
constexpr u32 reg_ccu60_pslr_offset = reg_ccu60_pslr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_mcmouts_address = 0xf0002a8c;
constexpr u32 reg_ccu60_mcmouts_offset = reg_ccu60_mcmouts_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_mcmout_address = 0xf0002a90;
constexpr u32 reg_ccu60_mcmout_offset = reg_ccu60_mcmout_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_mcmctr_address = 0xf0002a94;
constexpr u32 reg_ccu60_mcmctr_offset = reg_ccu60_mcmctr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_imon_address = 0xf0002a98;
constexpr u32 reg_ccu60_imon_offset = reg_ccu60_imon_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_li_address = 0xf0002a9c;
constexpr u32 reg_ccu60_li_offset = reg_ccu60_li_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_is_address = 0xf0002aa0;
constexpr u32 reg_ccu60_is_offset = reg_ccu60_is_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_iss_address = 0xf0002aa4;
constexpr u32 reg_ccu60_iss_offset = reg_ccu60_iss_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_isr_address = 0xf0002aa8;
constexpr u32 reg_ccu60_isr_offset = reg_ccu60_isr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_inp_address = 0xf0002aac;
constexpr u32 reg_ccu60_inp_offset = reg_ccu60_inp_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_ien_address = 0xf0002ab0;
constexpr u32 reg_ccu60_ien_offset = reg_ccu60_ien_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_ocs_address = 0xf0002ae8;
constexpr u32 reg_ccu60_ocs_offset = reg_ccu60_ocs_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_krstclr_address = 0xf0002aec;
constexpr u32 reg_ccu60_krstclr_offset = reg_ccu60_krstclr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_krst1_address = 0xf0002af0;
constexpr u32 reg_ccu60_krst1_offset = reg_ccu60_krst1_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_krst0_address = 0xf0002af4;
constexpr u32 reg_ccu60_krst0_offset = reg_ccu60_krst0_address - ccu6_memory_start_address;
constexpr u32 reg_ccu60_accen0_address = 0xf0002afc;
constexpr u32 reg_ccu60_accen0_offset = reg_ccu60_accen0_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_clc_address = 0xf0002b00;
constexpr u32 reg_ccu61_clc_offset = reg_ccu61_clc_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_mcfg_address = 0xf0002b04;
constexpr u32 reg_ccu61_mcfg_offset = reg_ccu61_mcfg_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_id_address = 0xf0002b08;
constexpr u32 reg_ccu61_id_offset = reg_ccu61_id_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_pisel0_address = 0xf0002b10;
constexpr u32 reg_ccu61_pisel0_offset = reg_ccu61_pisel0_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_pisel2_address = 0xf0002b14;
constexpr u32 reg_ccu61_pisel2_offset = reg_ccu61_pisel2_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_kscsr_address = 0xf0002b1c;
constexpr u32 reg_ccu61_kscsr_offset = reg_ccu61_kscsr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_t12_address = 0xf0002b20;
constexpr u32 reg_ccu61_t12_offset = reg_ccu61_t12_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_t12pr_address = 0xf0002b24;
constexpr u32 reg_ccu61_t12pr_offset = reg_ccu61_t12pr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_t12dtc_address = 0xf0002b28;
constexpr u32 reg_ccu61_t12dtc_offset = reg_ccu61_t12dtc_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_t13_address = 0xf0002b50;
constexpr u32 reg_ccu61_t13_offset = reg_ccu61_t13_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_t13pr_address = 0xf0002b54;
constexpr u32 reg_ccu61_t13pr_offset = reg_ccu61_t13pr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_cc63r_address = 0xf0002b58;
constexpr u32 reg_ccu61_cc63r_offset = reg_ccu61_cc63r_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_cc63sr_address = 0xf0002b5c;
constexpr u32 reg_ccu61_cc63sr_offset = reg_ccu61_cc63sr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_cmpstat_address = 0xf0002b60;
constexpr u32 reg_ccu61_cmpstat_offset = reg_ccu61_cmpstat_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_cmpmodif_address = 0xf0002b64;
constexpr u32 reg_ccu61_cmpmodif_offset = reg_ccu61_cmpmodif_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_t12msel_address = 0xf0002b68;
constexpr u32 reg_ccu61_t12msel_offset = reg_ccu61_t12msel_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_tctr0_address = 0xf0002b70;
constexpr u32 reg_ccu61_tctr0_offset = reg_ccu61_tctr0_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_tctr2_address = 0xf0002b74;
constexpr u32 reg_ccu61_tctr2_offset = reg_ccu61_tctr2_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_tctr4_address = 0xf0002b78;
constexpr u32 reg_ccu61_tctr4_offset = reg_ccu61_tctr4_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_modctr_address = 0xf0002b80;
constexpr u32 reg_ccu61_modctr_offset = reg_ccu61_modctr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_trpctr_address = 0xf0002b84;
constexpr u32 reg_ccu61_trpctr_offset = reg_ccu61_trpctr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_pslr_address = 0xf0002b88;
constexpr u32 reg_ccu61_pslr_offset = reg_ccu61_pslr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_mcmouts_address = 0xf0002b8c;
constexpr u32 reg_ccu61_mcmouts_offset = reg_ccu61_mcmouts_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_mcmout_address = 0xf0002b90;
constexpr u32 reg_ccu61_mcmout_offset = reg_ccu61_mcmout_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_mcmctr_address = 0xf0002b94;
constexpr u32 reg_ccu61_mcmctr_offset = reg_ccu61_mcmctr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_imon_address = 0xf0002b98;
constexpr u32 reg_ccu61_imon_offset = reg_ccu61_imon_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_li_address = 0xf0002b9c;
constexpr u32 reg_ccu61_li_offset = reg_ccu61_li_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_is_address = 0xf0002ba0;
constexpr u32 reg_ccu61_is_offset = reg_ccu61_is_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_iss_address = 0xf0002ba4;
constexpr u32 reg_ccu61_iss_offset = reg_ccu61_iss_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_isr_address = 0xf0002ba8;
constexpr u32 reg_ccu61_isr_offset = reg_ccu61_isr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_inp_address = 0xf0002bac;
constexpr u32 reg_ccu61_inp_offset = reg_ccu61_inp_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_ien_address = 0xf0002bb0;
constexpr u32 reg_ccu61_ien_offset = reg_ccu61_ien_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_ocs_address = 0xf0002be8;
constexpr u32 reg_ccu61_ocs_offset = reg_ccu61_ocs_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_krstclr_address = 0xf0002bec;
constexpr u32 reg_ccu61_krstclr_offset = reg_ccu61_krstclr_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_krst1_address = 0xf0002bf0;
constexpr u32 reg_ccu61_krst1_offset = reg_ccu61_krst1_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_krst0_address = 0xf0002bf4;
constexpr u32 reg_ccu61_krst0_offset = reg_ccu61_krst0_address - ccu6_memory_start_address;
constexpr u32 reg_ccu61_accen0_address = 0xf0002bfc;
constexpr u32 reg_ccu61_accen0_offset = reg_ccu61_accen0_address - ccu6_memory_start_address;

} // anonymous namespace


Tricore::Ccu6::Ccu6()
    : m_ccu60_clc(ccu60_clc_reset_value)
    , m_ccu60_mcfg(ccu60_mcfg_reset_value)
    , m_ccu60_id(ccu60_id_reset_value)
    , m_ccu60_mosel(ccu60_mosel_reset_value)
    , m_ccu60_pisel0(ccu60_pisel0_reset_value)
    , m_ccu60_pisel2(ccu60_pisel2_reset_value)
    , m_ccu60_kscsr(ccu60_kscsr_reset_value)
    , m_ccu60_t12(ccu60_t12_reset_value)
    , m_ccu60_t12pr(ccu60_t12pr_reset_value)
    , m_ccu60_t12dtc(ccu60_t12dtc_reset_value)
    , m_ccu60_t13(ccu60_t13_reset_value)
    , m_ccu60_t13pr(ccu60_t13pr_reset_value)
    , m_ccu60_cc63r(ccu60_cc63r_reset_value)
    , m_ccu60_cc63sr(ccu60_cc63sr_reset_value)
    , m_ccu60_cmpstat(ccu60_cmpstat_reset_value)
    , m_ccu60_cmpmodif(ccu60_cmpmodif_reset_value)
    , m_ccu60_t12msel(ccu60_t12msel_reset_value)
    , m_ccu60_tctr0(ccu60_tctr0_reset_value)
    , m_ccu60_tctr2(ccu60_tctr2_reset_value)
    , m_ccu60_tctr4(ccu60_tctr4_reset_value)
    , m_ccu60_modctr(ccu60_modctr_reset_value)
    , m_ccu60_trpctr(ccu60_trpctr_reset_value)
    , m_ccu60_pslr(ccu60_pslr_reset_value)
    , m_ccu60_mcmouts(ccu60_mcmouts_reset_value)
    , m_ccu60_mcmout(ccu60_mcmout_reset_value)
    , m_ccu60_mcmctr(ccu60_mcmctr_reset_value)
    , m_ccu60_imon(ccu60_imon_reset_value)
    , m_ccu60_li(ccu60_li_reset_value)
    , m_ccu60_is(ccu60_is_reset_value)
    , m_ccu60_iss(ccu60_iss_reset_value)
    , m_ccu60_isr(ccu60_isr_reset_value)
    , m_ccu60_inp(ccu60_inp_reset_value)
    , m_ccu60_ien(ccu60_ien_reset_value)
    , m_ccu60_ocs(ccu60_ocs_reset_value)
    , m_ccu60_krstclr(ccu60_krstclr_reset_value)
    , m_ccu60_krst1(ccu60_krst1_reset_value)
    , m_ccu60_krst0(ccu60_krst0_reset_value)
    , m_ccu60_accen0(ccu60_accen0_reset_value)
    , m_ccu61_clc(ccu61_clc_reset_value)
    , m_ccu61_mcfg(ccu61_mcfg_reset_value)
    , m_ccu61_id(ccu61_id_reset_value)
    , m_ccu61_pisel0(ccu61_pisel0_reset_value)
    , m_ccu61_pisel2(ccu61_pisel2_reset_value)
    , m_ccu61_kscsr(ccu61_kscsr_reset_value)
    , m_ccu61_t12(ccu61_t12_reset_value)
    , m_ccu61_t12pr(ccu61_t12pr_reset_value)
    , m_ccu61_t12dtc(ccu61_t12dtc_reset_value)
    , m_ccu61_t13(ccu61_t13_reset_value)
    , m_ccu61_t13pr(ccu61_t13pr_reset_value)
    , m_ccu61_cc63r(ccu61_cc63r_reset_value)
    , m_ccu61_cc63sr(ccu61_cc63sr_reset_value)
    , m_ccu61_cmpstat(ccu61_cmpstat_reset_value)
    , m_ccu61_cmpmodif(ccu61_cmpmodif_reset_value)
    , m_ccu61_t12msel(ccu61_t12msel_reset_value)
    , m_ccu61_tctr0(ccu61_tctr0_reset_value)
    , m_ccu61_tctr2(ccu61_tctr2_reset_value)
    , m_ccu61_tctr4(ccu61_tctr4_reset_value)
    , m_ccu61_modctr(ccu61_modctr_reset_value)
    , m_ccu61_trpctr(ccu61_trpctr_reset_value)
    , m_ccu61_pslr(ccu61_pslr_reset_value)
    , m_ccu61_mcmouts(ccu61_mcmouts_reset_value)
    , m_ccu61_mcmout(ccu61_mcmout_reset_value)
    , m_ccu61_mcmctr(ccu61_mcmctr_reset_value)
    , m_ccu61_imon(ccu61_imon_reset_value)
    , m_ccu61_li(ccu61_li_reset_value)
    , m_ccu61_is(ccu61_is_reset_value)
    , m_ccu61_iss(ccu61_iss_reset_value)
    , m_ccu61_isr(ccu61_isr_reset_value)
    , m_ccu61_inp(ccu61_inp_reset_value)
    , m_ccu61_ien(ccu61_ien_reset_value)
    , m_ccu61_ocs(ccu61_ocs_reset_value)
    , m_ccu61_krstclr(ccu61_krstclr_reset_value)
    , m_ccu61_krst1(ccu61_krst1_reset_value)
    , m_ccu61_krst0(ccu61_krst0_reset_value)
    , m_ccu61_accen0(ccu61_accen0_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Ccu6::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - ccu6_memory_start_address;
    switch (offset) {
    case reg_ccu60_clc_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_CLC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_mcfg_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_MCFG in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_mcfg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_id_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_mosel_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_MOSEL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_mosel);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_pisel0_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_PISEL0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_pisel0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_pisel2_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_PISEL2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_pisel2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_kscsr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_KSCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_kscsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_t12_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_T12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_t12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_t12pr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_T12PR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_t12pr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_t12dtc_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_T12DTC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_t12dtc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_t13_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_T13 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_t13);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_t13pr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_T13PR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_t13pr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_cc63r_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_CC63R in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_cc63r);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_cc63sr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_CC63SR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_cc63sr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_cmpstat_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_CMPSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_cmpstat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_cmpmodif_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_CMPMODIF in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_cmpmodif);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_t12msel_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_T12MSEL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_t12msel);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_tctr0_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_TCTR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_tctr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_tctr2_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_TCTR2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_tctr2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_tctr4_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_TCTR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_tctr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_modctr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_MODCTR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_modctr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_trpctr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_TRPCTR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_trpctr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_pslr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_PSLR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_pslr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_mcmouts_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_MCMOUTS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_mcmouts);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_mcmout_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_MCMOUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_mcmout);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_mcmctr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_MCMCTR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_mcmctr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_imon_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_IMON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_imon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_li_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_LI in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_li);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_is_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_IS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_is);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_iss_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_ISS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_iss);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_isr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_ISR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_isr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_inp_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_INP in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_inp);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_ien_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_IEN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_ien);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_ocs_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_OCS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_krstclr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_krst1_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_krst0_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu60_accen0_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU60_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu60_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_clc_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_CLC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_mcfg_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_MCFG in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_mcfg);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_id_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_pisel0_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_PISEL0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_pisel0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_pisel2_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_PISEL2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_pisel2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_kscsr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_KSCSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_kscsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_t12_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_T12 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_t12);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_t12pr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_T12PR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_t12pr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_t12dtc_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_T12DTC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_t12dtc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_t13_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_T13 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_t13);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_t13pr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_T13PR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_t13pr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_cc63r_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_CC63R in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_cc63r);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_cc63sr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_CC63SR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_cc63sr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_cmpstat_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_CMPSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_cmpstat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_cmpmodif_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_CMPMODIF in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_cmpmodif);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_t12msel_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_T12MSEL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_t12msel);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_tctr0_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_TCTR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_tctr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_tctr2_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_TCTR2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_tctr2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_tctr4_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_TCTR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_tctr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_modctr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_MODCTR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_modctr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_trpctr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_TRPCTR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_trpctr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_pslr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_PSLR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_pslr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_mcmouts_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_MCMOUTS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_mcmouts);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_mcmout_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_MCMOUT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_mcmout);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_mcmctr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_MCMCTR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_mcmctr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_imon_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_IMON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_imon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_li_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_LI in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_li);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_is_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_IS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_is);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_iss_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_ISS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_iss);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_isr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_ISR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_isr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_inp_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_INP in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_inp);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_ien_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_IEN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_ien);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_ocs_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_OCS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_krstclr_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_krst1_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_krst0_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_ccu61_accen0_offset: {
            spdlog::debug("CCU6: accessing CCU6.CCU61_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_ccu61_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Ccu6 peripheral", address)};
        break;
    }
}

void Tricore::Ccu6::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - ccu6_memory_start_address;
    switch (offset) {
    case reg_ccu60_clc_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_clc));
    } break;
    case reg_ccu60_mcfg_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_MCFG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_mcfg));
    } break;
    case reg_ccu60_id_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_id));
    } break;
    case reg_ccu60_mosel_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_MOSEL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_mosel));
    } break;
    case reg_ccu60_pisel0_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_PISEL0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_pisel0));
    } break;
    case reg_ccu60_pisel2_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_PISEL2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_pisel2));
    } break;
    case reg_ccu60_kscsr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_KSCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_kscsr));
    } break;
    case reg_ccu60_t12_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_T12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_t12));
    } break;
    case reg_ccu60_t12pr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_T12PR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_t12pr));
    } break;
    case reg_ccu60_t12dtc_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_T12DTC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_t12dtc));
    } break;
    case reg_ccu60_t13_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_T13 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_t13));
    } break;
    case reg_ccu60_t13pr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_T13PR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_t13pr));
    } break;
    case reg_ccu60_cc63r_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_CC63R in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_cc63r));
    } break;
    case reg_ccu60_cc63sr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_CC63SR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_cc63sr));
    } break;
    case reg_ccu60_cmpstat_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_CMPSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_cmpstat));
    } break;
    case reg_ccu60_cmpmodif_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_CMPMODIF in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_cmpmodif));
    } break;
    case reg_ccu60_t12msel_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_T12MSEL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_t12msel));
    } break;
    case reg_ccu60_tctr0_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_TCTR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_tctr0));
    } break;
    case reg_ccu60_tctr2_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_TCTR2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_tctr2));
    } break;
    case reg_ccu60_tctr4_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_TCTR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_tctr4));
    } break;
    case reg_ccu60_modctr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_MODCTR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_modctr));
    } break;
    case reg_ccu60_trpctr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_TRPCTR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_trpctr));
    } break;
    case reg_ccu60_pslr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_PSLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_pslr));
    } break;
    case reg_ccu60_mcmouts_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_MCMOUTS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_mcmouts));
    } break;
    case reg_ccu60_mcmout_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_MCMOUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_mcmout));
    } break;
    case reg_ccu60_mcmctr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_MCMCTR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_mcmctr));
    } break;
    case reg_ccu60_imon_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_IMON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_imon));
    } break;
    case reg_ccu60_li_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_LI in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_li));
    } break;
    case reg_ccu60_is_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_IS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_is));
    } break;
    case reg_ccu60_iss_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_ISS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_iss));
    } break;
    case reg_ccu60_isr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_ISR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_isr));
    } break;
    case reg_ccu60_inp_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_INP in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_inp));
    } break;
    case reg_ccu60_ien_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_IEN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_ien));
    } break;
    case reg_ccu60_ocs_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_ocs));
    } break;
    case reg_ccu60_krstclr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_krstclr));
    } break;
    case reg_ccu60_krst1_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_krst1));
    } break;
    case reg_ccu60_krst0_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_krst0));
    } break;
    case reg_ccu60_accen0_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU60_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu60_accen0));
    } break;
    case reg_ccu61_clc_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_clc));
    } break;
    case reg_ccu61_mcfg_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_MCFG in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_mcfg));
    } break;
    case reg_ccu61_id_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_id));
    } break;
    case reg_ccu61_pisel0_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_PISEL0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_pisel0));
    } break;
    case reg_ccu61_pisel2_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_PISEL2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_pisel2));
    } break;
    case reg_ccu61_kscsr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_KSCSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_kscsr));
    } break;
    case reg_ccu61_t12_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_T12 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_t12));
    } break;
    case reg_ccu61_t12pr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_T12PR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_t12pr));
    } break;
    case reg_ccu61_t12dtc_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_T12DTC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_t12dtc));
    } break;
    case reg_ccu61_t13_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_T13 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_t13));
    } break;
    case reg_ccu61_t13pr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_T13PR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_t13pr));
    } break;
    case reg_ccu61_cc63r_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_CC63R in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_cc63r));
    } break;
    case reg_ccu61_cc63sr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_CC63SR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_cc63sr));
    } break;
    case reg_ccu61_cmpstat_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_CMPSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_cmpstat));
    } break;
    case reg_ccu61_cmpmodif_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_CMPMODIF in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_cmpmodif));
    } break;
    case reg_ccu61_t12msel_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_T12MSEL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_t12msel));
    } break;
    case reg_ccu61_tctr0_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_TCTR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_tctr0));
    } break;
    case reg_ccu61_tctr2_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_TCTR2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_tctr2));
    } break;
    case reg_ccu61_tctr4_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_TCTR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_tctr4));
    } break;
    case reg_ccu61_modctr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_MODCTR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_modctr));
    } break;
    case reg_ccu61_trpctr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_TRPCTR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_trpctr));
    } break;
    case reg_ccu61_pslr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_PSLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_pslr));
    } break;
    case reg_ccu61_mcmouts_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_MCMOUTS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_mcmouts));
    } break;
    case reg_ccu61_mcmout_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_MCMOUT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_mcmout));
    } break;
    case reg_ccu61_mcmctr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_MCMCTR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_mcmctr));
    } break;
    case reg_ccu61_imon_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_IMON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_imon));
    } break;
    case reg_ccu61_li_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_LI in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_li));
    } break;
    case reg_ccu61_is_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_IS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_is));
    } break;
    case reg_ccu61_iss_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_ISS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_iss));
    } break;
    case reg_ccu61_isr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_ISR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_isr));
    } break;
    case reg_ccu61_inp_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_INP in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_inp));
    } break;
    case reg_ccu61_ien_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_IEN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_ien));
    } break;
    case reg_ccu61_ocs_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_ocs));
    } break;
    case reg_ccu61_krstclr_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_krstclr));
    } break;
    case reg_ccu61_krst1_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_krst1));
    } break;
    case reg_ccu61_krst0_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_krst0));
    } break;
    case reg_ccu61_accen0_offset: {
        spdlog::debug("CCU6: accessing CCU6.CCU61_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_ccu61_accen0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Ccu6 peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
