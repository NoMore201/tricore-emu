
/**
 * @brief Module source for Cpu peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Cpu.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 cpu0_flashcon0_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_flashcon1_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_flashcon2_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_flashcon3_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_flashcon4_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_osel_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_segen_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_task_asi_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_pma0_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_pma1_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_pma2_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_dcon2_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_smacon_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_dstr_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_datr_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_deadd_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_diear_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_dietr_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_dcon0_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_pstr_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_pcon1_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_pcon2_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_pcon0_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_piear_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_pietr_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_compat_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_tps_con_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_cctrl_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_ccnt_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_icnt_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_m1cnt_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_m2cnt_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_m3cnt_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_dbgsr_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_exevt_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_crevt_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_swevt_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_trig_acc_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_dms_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_dcx_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_dbgtcr_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_pcxi_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_psw_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_pc_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_syscon_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_cpu_id_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_core_id_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_biv_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_btv_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_isp_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_icr_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_fcx_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_lcx_reset_value = 0; // TODO: change according manual
constexpr u32 cpu0_cus_id_reset_value = 0; // TODO: change according manual

constexpr u32 cpu_memory_start_address = 0xf8800000U;
constexpr u32 cpu_memory_size = 0; // TODO: update according manual;
constexpr u32 cpu_memory_end_address = cpu_memory_start_address + cpu_memory_size;

constexpr u32 reg_cpu0_flashcon0_address = 0xf8801100;
constexpr u32 reg_cpu0_flashcon0_offset = reg_cpu0_flashcon0_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_flashcon1_address = 0xf8801104;
constexpr u32 reg_cpu0_flashcon1_offset = reg_cpu0_flashcon1_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_flashcon2_address = 0xf8801108;
constexpr u32 reg_cpu0_flashcon2_offset = reg_cpu0_flashcon2_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_flashcon3_address = 0xf880110c;
constexpr u32 reg_cpu0_flashcon3_offset = reg_cpu0_flashcon3_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_flashcon4_address = 0xf8801110;
constexpr u32 reg_cpu0_flashcon4_offset = reg_cpu0_flashcon4_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_krst0_address = 0xf880d000;
constexpr u32 reg_cpu0_krst0_offset = reg_cpu0_krst0_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_krst1_address = 0xf880d004;
constexpr u32 reg_cpu0_krst1_offset = reg_cpu0_krst1_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_krstclr_address = 0xf880d008;
constexpr u32 reg_cpu0_krstclr_offset = reg_cpu0_krstclr_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_osel_address = 0xf880fb00;
constexpr u32 reg_cpu0_osel_offset = reg_cpu0_osel_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_segen_address = 0xf8811030;
constexpr u32 reg_cpu0_segen_offset = reg_cpu0_segen_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_task_asi_address = 0xf8818004;
constexpr u32 reg_cpu0_task_asi_offset = reg_cpu0_task_asi_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_pma0_address = 0xf8818100;
constexpr u32 reg_cpu0_pma0_offset = reg_cpu0_pma0_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_pma1_address = 0xf8818104;
constexpr u32 reg_cpu0_pma1_offset = reg_cpu0_pma1_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_pma2_address = 0xf8818108;
constexpr u32 reg_cpu0_pma2_offset = reg_cpu0_pma2_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_dcon2_address = 0xf8819000;
constexpr u32 reg_cpu0_dcon2_offset = reg_cpu0_dcon2_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_smacon_address = 0xf881900c;
constexpr u32 reg_cpu0_smacon_offset = reg_cpu0_smacon_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_dstr_address = 0xf8819010;
constexpr u32 reg_cpu0_dstr_offset = reg_cpu0_dstr_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_datr_address = 0xf8819018;
constexpr u32 reg_cpu0_datr_offset = reg_cpu0_datr_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_deadd_address = 0xf881901c;
constexpr u32 reg_cpu0_deadd_offset = reg_cpu0_deadd_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_diear_address = 0xf8819020;
constexpr u32 reg_cpu0_diear_offset = reg_cpu0_diear_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_dietr_address = 0xf8819024;
constexpr u32 reg_cpu0_dietr_offset = reg_cpu0_dietr_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_dcon0_address = 0xf8819040;
constexpr u32 reg_cpu0_dcon0_offset = reg_cpu0_dcon0_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_pstr_address = 0xf8819200;
constexpr u32 reg_cpu0_pstr_offset = reg_cpu0_pstr_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_pcon1_address = 0xf8819204;
constexpr u32 reg_cpu0_pcon1_offset = reg_cpu0_pcon1_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_pcon2_address = 0xf8819208;
constexpr u32 reg_cpu0_pcon2_offset = reg_cpu0_pcon2_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_pcon0_address = 0xf881920c;
constexpr u32 reg_cpu0_pcon0_offset = reg_cpu0_pcon0_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_piear_address = 0xf8819210;
constexpr u32 reg_cpu0_piear_offset = reg_cpu0_piear_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_pietr_address = 0xf8819214;
constexpr u32 reg_cpu0_pietr_offset = reg_cpu0_pietr_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_compat_address = 0xf8819400;
constexpr u32 reg_cpu0_compat_offset = reg_cpu0_compat_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_tps_con_address = 0xf881e400;
constexpr u32 reg_cpu0_tps_con_offset = reg_cpu0_tps_con_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_cctrl_address = 0xf881fc00;
constexpr u32 reg_cpu0_cctrl_offset = reg_cpu0_cctrl_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_ccnt_address = 0xf881fc04;
constexpr u32 reg_cpu0_ccnt_offset = reg_cpu0_ccnt_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_icnt_address = 0xf881fc08;
constexpr u32 reg_cpu0_icnt_offset = reg_cpu0_icnt_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_m1cnt_address = 0xf881fc0c;
constexpr u32 reg_cpu0_m1cnt_offset = reg_cpu0_m1cnt_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_m2cnt_address = 0xf881fc10;
constexpr u32 reg_cpu0_m2cnt_offset = reg_cpu0_m2cnt_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_m3cnt_address = 0xf881fc14;
constexpr u32 reg_cpu0_m3cnt_offset = reg_cpu0_m3cnt_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_dbgsr_address = 0xf881fd00;
constexpr u32 reg_cpu0_dbgsr_offset = reg_cpu0_dbgsr_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_exevt_address = 0xf881fd08;
constexpr u32 reg_cpu0_exevt_offset = reg_cpu0_exevt_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_crevt_address = 0xf881fd0c;
constexpr u32 reg_cpu0_crevt_offset = reg_cpu0_crevt_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_swevt_address = 0xf881fd10;
constexpr u32 reg_cpu0_swevt_offset = reg_cpu0_swevt_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_trig_acc_address = 0xf881fd30;
constexpr u32 reg_cpu0_trig_acc_offset = reg_cpu0_trig_acc_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_dms_address = 0xf881fd40;
constexpr u32 reg_cpu0_dms_offset = reg_cpu0_dms_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_dcx_address = 0xf881fd44;
constexpr u32 reg_cpu0_dcx_offset = reg_cpu0_dcx_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_dbgtcr_address = 0xf881fd48;
constexpr u32 reg_cpu0_dbgtcr_offset = reg_cpu0_dbgtcr_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_pcxi_address = 0xf881fe00;
constexpr u32 reg_cpu0_pcxi_offset = reg_cpu0_pcxi_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_psw_address = 0xf881fe04;
constexpr u32 reg_cpu0_psw_offset = reg_cpu0_psw_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_pc_address = 0xf881fe08;
constexpr u32 reg_cpu0_pc_offset = reg_cpu0_pc_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_syscon_address = 0xf881fe14;
constexpr u32 reg_cpu0_syscon_offset = reg_cpu0_syscon_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_cpu_id_address = 0xf881fe18;
constexpr u32 reg_cpu0_cpu_id_offset = reg_cpu0_cpu_id_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_core_id_address = 0xf881fe1c;
constexpr u32 reg_cpu0_core_id_offset = reg_cpu0_core_id_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_biv_address = 0xf881fe20;
constexpr u32 reg_cpu0_biv_offset = reg_cpu0_biv_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_btv_address = 0xf881fe24;
constexpr u32 reg_cpu0_btv_offset = reg_cpu0_btv_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_isp_address = 0xf881fe28;
constexpr u32 reg_cpu0_isp_offset = reg_cpu0_isp_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_icr_address = 0xf881fe2c;
constexpr u32 reg_cpu0_icr_offset = reg_cpu0_icr_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_fcx_address = 0xf881fe38;
constexpr u32 reg_cpu0_fcx_offset = reg_cpu0_fcx_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_lcx_address = 0xf881fe3c;
constexpr u32 reg_cpu0_lcx_offset = reg_cpu0_lcx_address - cpu_memory_start_address;
constexpr u32 reg_cpu0_cus_id_address = 0xf881fe50;
constexpr u32 reg_cpu0_cus_id_offset = reg_cpu0_cus_id_address - cpu_memory_start_address;

} // anonymous namespace


Tricore::Peripherals::Cpu::Cpu()
    : m_cpu0_flashcon0(cpu0_flashcon0_reset_value)
    , m_cpu0_flashcon1(cpu0_flashcon1_reset_value)
    , m_cpu0_flashcon2(cpu0_flashcon2_reset_value)
    , m_cpu0_flashcon3(cpu0_flashcon3_reset_value)
    , m_cpu0_flashcon4(cpu0_flashcon4_reset_value)
    , m_cpu0_krst0(cpu0_krst0_reset_value)
    , m_cpu0_krst1(cpu0_krst1_reset_value)
    , m_cpu0_krstclr(cpu0_krstclr_reset_value)
    , m_cpu0_osel(cpu0_osel_reset_value)
    , m_cpu0_segen(cpu0_segen_reset_value)
    , m_cpu0_task_asi(cpu0_task_asi_reset_value)
    , m_cpu0_pma0(cpu0_pma0_reset_value)
    , m_cpu0_pma1(cpu0_pma1_reset_value)
    , m_cpu0_pma2(cpu0_pma2_reset_value)
    , m_cpu0_dcon2(cpu0_dcon2_reset_value)
    , m_cpu0_smacon(cpu0_smacon_reset_value)
    , m_cpu0_dstr(cpu0_dstr_reset_value)
    , m_cpu0_datr(cpu0_datr_reset_value)
    , m_cpu0_deadd(cpu0_deadd_reset_value)
    , m_cpu0_diear(cpu0_diear_reset_value)
    , m_cpu0_dietr(cpu0_dietr_reset_value)
    , m_cpu0_dcon0(cpu0_dcon0_reset_value)
    , m_cpu0_pstr(cpu0_pstr_reset_value)
    , m_cpu0_pcon1(cpu0_pcon1_reset_value)
    , m_cpu0_pcon2(cpu0_pcon2_reset_value)
    , m_cpu0_pcon0(cpu0_pcon0_reset_value)
    , m_cpu0_piear(cpu0_piear_reset_value)
    , m_cpu0_pietr(cpu0_pietr_reset_value)
    , m_cpu0_compat(cpu0_compat_reset_value)
    , m_cpu0_tps_con(cpu0_tps_con_reset_value)
    , m_cpu0_cctrl(cpu0_cctrl_reset_value)
    , m_cpu0_ccnt(cpu0_ccnt_reset_value)
    , m_cpu0_icnt(cpu0_icnt_reset_value)
    , m_cpu0_m1cnt(cpu0_m1cnt_reset_value)
    , m_cpu0_m2cnt(cpu0_m2cnt_reset_value)
    , m_cpu0_m3cnt(cpu0_m3cnt_reset_value)
    , m_cpu0_dbgsr(cpu0_dbgsr_reset_value)
    , m_cpu0_exevt(cpu0_exevt_reset_value)
    , m_cpu0_crevt(cpu0_crevt_reset_value)
    , m_cpu0_swevt(cpu0_swevt_reset_value)
    , m_cpu0_trig_acc(cpu0_trig_acc_reset_value)
    , m_cpu0_dms(cpu0_dms_reset_value)
    , m_cpu0_dcx(cpu0_dcx_reset_value)
    , m_cpu0_dbgtcr(cpu0_dbgtcr_reset_value)
    , m_cpu0_pcxi(cpu0_pcxi_reset_value)
    , m_cpu0_psw(cpu0_psw_reset_value)
    , m_cpu0_pc(cpu0_pc_reset_value)
    , m_cpu0_syscon(cpu0_syscon_reset_value)
    , m_cpu0_cpu_id(cpu0_cpu_id_reset_value)
    , m_cpu0_core_id(cpu0_core_id_reset_value)
    , m_cpu0_biv(cpu0_biv_reset_value)
    , m_cpu0_btv(cpu0_btv_reset_value)
    , m_cpu0_isp(cpu0_isp_reset_value)
    , m_cpu0_icr(cpu0_icr_reset_value)
    , m_cpu0_fcx(cpu0_fcx_reset_value)
    , m_cpu0_lcx(cpu0_lcx_reset_value)
    , m_cpu0_cus_id(cpu0_cus_id_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Peripherals::Cpu::read(std::byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - cpu_memory_start_address;
    switch (offset) {
    case reg_cpu0_flashcon0_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_FLASHCON0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_flashcon0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_flashcon1_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_FLASHCON1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_flashcon1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_flashcon2_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_FLASHCON2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_flashcon2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_flashcon3_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_FLASHCON3 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_flashcon3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_flashcon4_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_FLASHCON4 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_flashcon4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_krst0_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_krst1_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_krstclr_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_osel_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_OSEL in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_osel);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_segen_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_SEGEN in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_segen);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_task_asi_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_TASK_ASI in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_task_asi);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_pma0_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_PMA0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_pma0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_pma1_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_PMA1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_pma1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_pma2_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_PMA2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_pma2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_dcon2_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_DCON2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_dcon2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_smacon_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_SMACON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_smacon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_dstr_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_DSTR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_dstr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_datr_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_DATR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_datr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_deadd_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_DEADD in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_deadd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_diear_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_DIEAR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_diear);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_dietr_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_DIETR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_dietr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_dcon0_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_DCON0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_dcon0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_pstr_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_PSTR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_pstr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_pcon1_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_PCON1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_pcon1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_pcon2_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_PCON2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_pcon2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_pcon0_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_PCON0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_pcon0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_piear_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_PIEAR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_piear);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_pietr_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_PIETR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_pietr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_compat_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_COMPAT in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_compat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_tps_con_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_TPS_CON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_tps_con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_cctrl_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_CCTRL in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_cctrl);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_ccnt_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_CCNT in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_ccnt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_icnt_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_ICNT in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_icnt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_m1cnt_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_M1CNT in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_m1cnt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_m2cnt_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_M2CNT in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_m2cnt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_m3cnt_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_M3CNT in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_m3cnt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_dbgsr_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_DBGSR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_dbgsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_exevt_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_EXEVT in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_exevt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_crevt_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_CREVT in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_crevt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_swevt_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_SWEVT in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_swevt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_trig_acc_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_TRIG_ACC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_trig_acc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_dms_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_DMS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_dms);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_dcx_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_DCX in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_dcx);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_dbgtcr_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_DBGTCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_dbgtcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_pcxi_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_PCXI in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_pcxi);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_psw_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_PSW in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_psw);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_pc_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_PC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_pc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_syscon_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_SYSCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_syscon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_cpu_id_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_CPU_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_cpu_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_core_id_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_CORE_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_core_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_biv_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_BIV in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_biv);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_btv_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_BTV in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_btv);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_isp_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_ISP in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_isp);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_icr_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_ICR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_icr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_fcx_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_FCX in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_fcx);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_lcx_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_LCX in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_lcx);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_cpu0_cus_id_offset: {
            spdlog::debug("CPU: accessing CPU.CPU0_CUS_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_cpu0_cus_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Cpu peripheral", address)};
        break;
    }
}

void Tricore::Peripherals::Cpu::write(const std::byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - cpu_memory_start_address;
    switch (offset) {
    case reg_cpu0_flashcon0_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_FLASHCON0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_flashcon0));
    } break;
    case reg_cpu0_flashcon1_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_FLASHCON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_flashcon1));
    } break;
    case reg_cpu0_flashcon2_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_FLASHCON2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_flashcon2));
    } break;
    case reg_cpu0_flashcon3_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_FLASHCON3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_flashcon3));
    } break;
    case reg_cpu0_flashcon4_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_FLASHCON4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_flashcon4));
    } break;
    case reg_cpu0_krst0_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_krst0));
    } break;
    case reg_cpu0_krst1_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_krst1));
    } break;
    case reg_cpu0_krstclr_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_krstclr));
    } break;
    case reg_cpu0_osel_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_OSEL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_osel));
    } break;
    case reg_cpu0_segen_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_SEGEN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_segen));
    } break;
    case reg_cpu0_task_asi_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_TASK_ASI in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_task_asi));
    } break;
    case reg_cpu0_pma0_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_PMA0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_pma0));
    } break;
    case reg_cpu0_pma1_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_PMA1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_pma1));
    } break;
    case reg_cpu0_pma2_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_PMA2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_pma2));
    } break;
    case reg_cpu0_dcon2_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_DCON2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_dcon2));
    } break;
    case reg_cpu0_smacon_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_SMACON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_smacon));
    } break;
    case reg_cpu0_dstr_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_DSTR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_dstr));
    } break;
    case reg_cpu0_datr_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_DATR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_datr));
    } break;
    case reg_cpu0_deadd_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_DEADD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_deadd));
    } break;
    case reg_cpu0_diear_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_DIEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_diear));
    } break;
    case reg_cpu0_dietr_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_DIETR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_dietr));
    } break;
    case reg_cpu0_dcon0_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_DCON0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_dcon0));
    } break;
    case reg_cpu0_pstr_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_PSTR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_pstr));
    } break;
    case reg_cpu0_pcon1_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_PCON1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_pcon1));
    } break;
    case reg_cpu0_pcon2_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_PCON2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_pcon2));
    } break;
    case reg_cpu0_pcon0_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_PCON0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_pcon0));
    } break;
    case reg_cpu0_piear_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_PIEAR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_piear));
    } break;
    case reg_cpu0_pietr_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_PIETR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_pietr));
    } break;
    case reg_cpu0_compat_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_COMPAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_compat));
    } break;
    case reg_cpu0_tps_con_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_TPS_CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_tps_con));
    } break;
    case reg_cpu0_cctrl_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_CCTRL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_cctrl));
    } break;
    case reg_cpu0_ccnt_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_CCNT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_ccnt));
    } break;
    case reg_cpu0_icnt_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_ICNT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_icnt));
    } break;
    case reg_cpu0_m1cnt_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_M1CNT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_m1cnt));
    } break;
    case reg_cpu0_m2cnt_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_M2CNT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_m2cnt));
    } break;
    case reg_cpu0_m3cnt_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_M3CNT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_m3cnt));
    } break;
    case reg_cpu0_dbgsr_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_DBGSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_dbgsr));
    } break;
    case reg_cpu0_exevt_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_EXEVT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_exevt));
    } break;
    case reg_cpu0_crevt_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_CREVT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_crevt));
    } break;
    case reg_cpu0_swevt_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_SWEVT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_swevt));
    } break;
    case reg_cpu0_trig_acc_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_TRIG_ACC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_trig_acc));
    } break;
    case reg_cpu0_dms_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_DMS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_dms));
    } break;
    case reg_cpu0_dcx_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_DCX in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_dcx));
    } break;
    case reg_cpu0_dbgtcr_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_DBGTCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_dbgtcr));
    } break;
    case reg_cpu0_pcxi_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_PCXI in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_pcxi));
    } break;
    case reg_cpu0_psw_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_PSW in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_psw));
    } break;
    case reg_cpu0_pc_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_PC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_pc));
    } break;
    case reg_cpu0_syscon_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_SYSCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_syscon));
    } break;
    case reg_cpu0_cpu_id_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_CPU_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_cpu_id));
    } break;
    case reg_cpu0_core_id_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_CORE_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_core_id));
    } break;
    case reg_cpu0_biv_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_BIV in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_biv));
    } break;
    case reg_cpu0_btv_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_BTV in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_btv));
    } break;
    case reg_cpu0_isp_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_ISP in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_isp));
    } break;
    case reg_cpu0_icr_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_ICR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_icr));
    } break;
    case reg_cpu0_fcx_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_FCX in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_fcx));
    } break;
    case reg_cpu0_lcx_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_LCX in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_lcx));
    } break;
    case reg_cpu0_cus_id_offset: {
        spdlog::debug("CPU: accessing CPU.CPU0_CUS_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_cpu0_cus_id));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Cpu peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
