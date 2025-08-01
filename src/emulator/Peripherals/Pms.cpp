
/**
 * @brief Module source for Pms peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Pms.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 pms_id_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrstat_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evradcstat_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrrstcon_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrrststat_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrtrim_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrtrimstat_reset_value = 0; // TODO: change according manual
constexpr u32 pms_monstat1_reset_value = 0; // TODO: change according manual
constexpr u32 pms_monstat2_reset_value = 0; // TODO: change according manual
constexpr u32 pms_monctrl_reset_value = 0; // TODO: change according manual
constexpr u32 pms_monfilt_reset_value = 0x300U;
constexpr u32 pms_pmsien_reset_value = 0; // TODO: change according manual
constexpr u32 pms_uvmon_reset_value = 0; // TODO: change according manual
constexpr u32 pms_ovmon_reset_value = 0; // TODO: change according manual
constexpr u32 pms_uvmon2_reset_value = 0; // TODO: change according manual
constexpr u32 pms_ovmon2_reset_value = 0; // TODO: change according manual
constexpr u32 pms_hsmuvmon_reset_value = 0; // TODO: change according manual
constexpr u32 pms_hsmovmon_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evr33con_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evroscctrl_reset_value = 0; // TODO: change according manual
constexpr u32 pms_pmswcr0_reset_value = 0; // TODO: change according manual
constexpr u32 pms_pmswcr2_reset_value = 0; // TODO: change according manual
constexpr u32 pms_pmswcr3_reset_value = 0; // TODO: change according manual
constexpr u32 pms_pmswcr4_reset_value = 0; // TODO: change according manual
constexpr u32 pms_pmswcr5_reset_value = 0; // TODO: change according manual
constexpr u32 pms_pmswstat_reset_value = 0; // TODO: change according manual
constexpr u32 pms_pmswstat2_reset_value = 0; // TODO: change according manual
constexpr u32 pms_pmswutcnt_reset_value = 0; // TODO: change according manual
constexpr u32 pms_pmswstatclr_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdstat0_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdctrl0_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdctrl1_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdctrl2_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdctrl3_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdctrl4_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdctrl5_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdctrl6_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdctrl7_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdctrl8_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdctrl9_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdctrl10_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdcoeff0_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdcoeff1_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdcoeff2_reset_value = 0; // TODO: change according manual
constexpr u32 pms_evrsdcoeff3_reset_value = 0; // TODO: change according manual
constexpr u32 pms_ag_stdby0_reset_value = 0; // TODO: change according manual
constexpr u32 pms_ag_stdby1_reset_value = 0; // TODO: change according manual
constexpr u32 pms_monbiststat_reset_value = 0;
constexpr u32 pms_monbistctrl_reset_value = 0;
constexpr u32 pms_cmd_stdby_reset_value = 0; // TODO: change according manual
constexpr u32 pms_agfsp_stdby0_reset_value = 0; // TODO: change according manual
constexpr u32 pms_agfsp_stdby1_reset_value = 0; // TODO: change according manual
constexpr u32 pms_dtsstat_reset_value = 0; // TODO: change according manual
constexpr u32 pms_dtslim_reset_value = 0; // TODO: change according manual
constexpr u32 pms_otss_reset_value = 0; // TODO: change according manual
constexpr u32 pms_otsc0_reset_value = 0; // TODO: change according manual
constexpr u32 pms_otsc1_reset_value = 0; // TODO: change according manual
constexpr u32 pms_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 pms_accen1_reset_value = 0; // TODO: change according manual

constexpr u32 pms_memory_start_address = 0xf0248000U;
constexpr u32 pms_memory_size = 512U; // TODO: update according manual;
constexpr u32 pms_memory_end_address = pms_memory_start_address + pms_memory_size;

constexpr u32 reg_pms_id_address = 0xf0248008;
constexpr u32 reg_pms_id_offset = reg_pms_id_address - pms_memory_start_address;
constexpr u32 reg_pms_evrstat_address = 0xf024802c;
constexpr u32 reg_pms_evrstat_offset = reg_pms_evrstat_address - pms_memory_start_address;
constexpr u32 reg_pms_evradcstat_address = 0xf0248034;
constexpr u32 reg_pms_evradcstat_offset = reg_pms_evradcstat_address - pms_memory_start_address;
constexpr u32 reg_pms_evrrstcon_address = 0xf024803c;
constexpr u32 reg_pms_evrrstcon_offset = reg_pms_evrrstcon_address - pms_memory_start_address;
constexpr u32 reg_pms_evrrststat_address = 0xf0248044;
constexpr u32 reg_pms_evrrststat_offset = reg_pms_evrrststat_address - pms_memory_start_address;
constexpr u32 reg_pms_evrtrim_address = 0xf024804c;
constexpr u32 reg_pms_evrtrim_offset = reg_pms_evrtrim_address - pms_memory_start_address;
constexpr u32 reg_pms_evrtrimstat_address = 0xf0248050;
constexpr u32 reg_pms_evrtrimstat_offset = reg_pms_evrtrimstat_address - pms_memory_start_address;
constexpr u32 reg_pms_monstat1_address = 0xf0248060;
constexpr u32 reg_pms_monstat1_offset = reg_pms_monstat1_address - pms_memory_start_address;
constexpr u32 reg_pms_monstat2_address = 0xf0248064;
constexpr u32 reg_pms_monstat2_offset = reg_pms_monstat2_address - pms_memory_start_address;
constexpr u32 reg_pms_monctrl_address = 0xf0248068;
constexpr u32 reg_pms_monctrl_offset = reg_pms_monctrl_address - pms_memory_start_address;
constexpr u32 reg_pms_monfilt_address = 0xf0248070;
constexpr u32 reg_pms_monfilt_offset = reg_pms_monfilt_address - pms_memory_start_address;
constexpr u32 reg_pms_pmsien_address = 0xf0248074;
constexpr u32 reg_pms_pmsien_offset = reg_pms_pmsien_address - pms_memory_start_address;
constexpr u32 reg_pms_uvmon_address = 0xf0248078;
constexpr u32 reg_pms_uvmon_offset = reg_pms_uvmon_address - pms_memory_start_address;
constexpr u32 reg_pms_ovmon_address = 0xf024807c;
constexpr u32 reg_pms_ovmon_offset = reg_pms_ovmon_address - pms_memory_start_address;
constexpr u32 reg_pms_uvmon2_address = 0xf0248080;
constexpr u32 reg_pms_uvmon2_offset = reg_pms_uvmon2_address - pms_memory_start_address;
constexpr u32 reg_pms_ovmon2_address = 0xf0248084;
constexpr u32 reg_pms_ovmon2_offset = reg_pms_ovmon2_address - pms_memory_start_address;
constexpr u32 reg_pms_hsmuvmon_address = 0xf0248088;
constexpr u32 reg_pms_hsmuvmon_offset = reg_pms_hsmuvmon_address - pms_memory_start_address;
constexpr u32 reg_pms_hsmovmon_address = 0xf024808c;
constexpr u32 reg_pms_hsmovmon_offset = reg_pms_hsmovmon_address - pms_memory_start_address;
constexpr u32 reg_pms_evr33con_address = 0xf0248090;
constexpr u32 reg_pms_evr33con_offset = reg_pms_evr33con_address - pms_memory_start_address;
constexpr u32 reg_pms_evroscctrl_address = 0xf02480a0;
constexpr u32 reg_pms_evroscctrl_offset = reg_pms_evroscctrl_address - pms_memory_start_address;
constexpr u32 reg_pms_pmswcr0_address = 0xf02480b4;
constexpr u32 reg_pms_pmswcr0_offset = reg_pms_pmswcr0_address - pms_memory_start_address;
constexpr u32 reg_pms_pmswcr2_address = 0xf02480b8;
constexpr u32 reg_pms_pmswcr2_offset = reg_pms_pmswcr2_address - pms_memory_start_address;
constexpr u32 reg_pms_pmswcr3_address = 0xf02480c0;
constexpr u32 reg_pms_pmswcr3_offset = reg_pms_pmswcr3_address - pms_memory_start_address;
constexpr u32 reg_pms_pmswcr4_address = 0xf02480c4;
constexpr u32 reg_pms_pmswcr4_offset = reg_pms_pmswcr4_address - pms_memory_start_address;
constexpr u32 reg_pms_pmswcr5_address = 0xf02480c8;
constexpr u32 reg_pms_pmswcr5_offset = reg_pms_pmswcr5_address - pms_memory_start_address;
constexpr u32 reg_pms_pmswstat_address = 0xf02480d4;
constexpr u32 reg_pms_pmswstat_offset = reg_pms_pmswstat_address - pms_memory_start_address;
constexpr u32 reg_pms_pmswstat2_address = 0xf02480d8;
constexpr u32 reg_pms_pmswstat2_offset = reg_pms_pmswstat2_address - pms_memory_start_address;
constexpr u32 reg_pms_pmswutcnt_address = 0xf02480dc;
constexpr u32 reg_pms_pmswutcnt_offset = reg_pms_pmswutcnt_address - pms_memory_start_address;
constexpr u32 reg_pms_pmswstatclr_address = 0xf02480e8;
constexpr u32 reg_pms_pmswstatclr_offset = reg_pms_pmswstatclr_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdstat0_address = 0xf02480fc;
constexpr u32 reg_pms_evrsdstat0_offset = reg_pms_evrsdstat0_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdctrl0_address = 0xf0248108;
constexpr u32 reg_pms_evrsdctrl0_offset = reg_pms_evrsdctrl0_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdctrl1_address = 0xf024810c;
constexpr u32 reg_pms_evrsdctrl1_offset = reg_pms_evrsdctrl1_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdctrl2_address = 0xf0248110;
constexpr u32 reg_pms_evrsdctrl2_offset = reg_pms_evrsdctrl2_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdctrl3_address = 0xf0248114;
constexpr u32 reg_pms_evrsdctrl3_offset = reg_pms_evrsdctrl3_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdctrl4_address = 0xf0248118;
constexpr u32 reg_pms_evrsdctrl4_offset = reg_pms_evrsdctrl4_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdctrl5_address = 0xf024811c;
constexpr u32 reg_pms_evrsdctrl5_offset = reg_pms_evrsdctrl5_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdctrl6_address = 0xf0248120;
constexpr u32 reg_pms_evrsdctrl6_offset = reg_pms_evrsdctrl6_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdctrl7_address = 0xf0248124;
constexpr u32 reg_pms_evrsdctrl7_offset = reg_pms_evrsdctrl7_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdctrl8_address = 0xf0248128;
constexpr u32 reg_pms_evrsdctrl8_offset = reg_pms_evrsdctrl8_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdctrl9_address = 0xf024812c;
constexpr u32 reg_pms_evrsdctrl9_offset = reg_pms_evrsdctrl9_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdctrl10_address = 0xf0248130;
constexpr u32 reg_pms_evrsdctrl10_offset = reg_pms_evrsdctrl10_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdcoeff0_address = 0xf0248148;
constexpr u32 reg_pms_evrsdcoeff0_offset = reg_pms_evrsdcoeff0_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdcoeff1_address = 0xf024814c;
constexpr u32 reg_pms_evrsdcoeff1_offset = reg_pms_evrsdcoeff1_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdcoeff2_address = 0xf0248150;
constexpr u32 reg_pms_evrsdcoeff2_offset = reg_pms_evrsdcoeff2_address - pms_memory_start_address;
constexpr u32 reg_pms_evrsdcoeff3_address = 0xf0248154;
constexpr u32 reg_pms_evrsdcoeff3_offset = reg_pms_evrsdcoeff3_address - pms_memory_start_address;
constexpr u32 reg_pms_ag_stdby0_address = 0xf0248188;
constexpr u32 reg_pms_ag_stdby0_offset = reg_pms_ag_stdby0_address - pms_memory_start_address;
constexpr u32 reg_pms_ag_stdby1_address = 0xf024818c;
constexpr u32 reg_pms_ag_stdby1_offset = reg_pms_ag_stdby1_address - pms_memory_start_address;
constexpr u32 reg_pms_monbiststat_address = 0xf0248190;
constexpr u32 reg_pms_monbiststat_offset = reg_pms_monbiststat_address - pms_memory_start_address;
constexpr u32 reg_pms_monbistctrl_address = 0xf0248198;
constexpr u32 reg_pms_monbistctrl_offset = reg_pms_monbistctrl_address - pms_memory_start_address;
constexpr u32 reg_pms_cmd_stdby_address = 0xf024819c;
constexpr u32 reg_pms_cmd_stdby_offset = reg_pms_cmd_stdby_address - pms_memory_start_address;
constexpr u32 reg_pms_agfsp_stdby0_address = 0xf02481a4;
constexpr u32 reg_pms_agfsp_stdby0_offset = reg_pms_agfsp_stdby0_address - pms_memory_start_address;
constexpr u32 reg_pms_agfsp_stdby1_address = 0xf02481a8;
constexpr u32 reg_pms_agfsp_stdby1_offset = reg_pms_agfsp_stdby1_address - pms_memory_start_address;
constexpr u32 reg_pms_dtsstat_address = 0xf02481c0;
constexpr u32 reg_pms_dtsstat_offset = reg_pms_dtsstat_address - pms_memory_start_address;
constexpr u32 reg_pms_dtslim_address = 0xf02481c8;
constexpr u32 reg_pms_dtslim_offset = reg_pms_dtslim_address - pms_memory_start_address;
constexpr u32 reg_pms_otss_address = 0xf02481e0;
constexpr u32 reg_pms_otss_offset = reg_pms_otss_address - pms_memory_start_address;
constexpr u32 reg_pms_otsc0_address = 0xf02481e4;
constexpr u32 reg_pms_otsc0_offset = reg_pms_otsc0_address - pms_memory_start_address;
constexpr u32 reg_pms_otsc1_address = 0xf02481e8;
constexpr u32 reg_pms_otsc1_offset = reg_pms_otsc1_address - pms_memory_start_address;
constexpr u32 reg_pms_accen0_address = 0xf02481f8;
constexpr u32 reg_pms_accen0_offset = reg_pms_accen0_address - pms_memory_start_address;
constexpr u32 reg_pms_accen1_address = 0xf02481fc;
constexpr u32 reg_pms_accen1_offset = reg_pms_accen1_address - pms_memory_start_address;

} // anonymous namespace


Tricore::Peripherals::Pms::Pms()
    : m_pms_id(pms_id_reset_value)
    , m_pms_evrstat(pms_evrstat_reset_value)
    , m_pms_evradcstat(pms_evradcstat_reset_value)
    , m_pms_evrrstcon(pms_evrrstcon_reset_value)
    , m_pms_evrrststat(pms_evrrststat_reset_value)
    , m_pms_evrtrim(pms_evrtrim_reset_value)
    , m_pms_evrtrimstat(pms_evrtrimstat_reset_value)
    , m_pms_monstat1(pms_monstat1_reset_value)
    , m_pms_monstat2(pms_monstat2_reset_value)
    , m_pms_monctrl(pms_monctrl_reset_value)
    , m_pms_monfilt(pms_monfilt_reset_value)
    , m_pms_pmsien(pms_pmsien_reset_value)
    , m_pms_uvmon(pms_uvmon_reset_value)
    , m_pms_ovmon(pms_ovmon_reset_value)
    , m_pms_uvmon2(pms_uvmon2_reset_value)
    , m_pms_ovmon2(pms_ovmon2_reset_value)
    , m_pms_hsmuvmon(pms_hsmuvmon_reset_value)
    , m_pms_hsmovmon(pms_hsmovmon_reset_value)
    , m_pms_evr33con(pms_evr33con_reset_value)
    , m_pms_evroscctrl(pms_evroscctrl_reset_value)
    , m_pms_pmswcr0(pms_pmswcr0_reset_value)
    , m_pms_pmswcr2(pms_pmswcr2_reset_value)
    , m_pms_pmswcr3(pms_pmswcr3_reset_value)
    , m_pms_pmswcr4(pms_pmswcr4_reset_value)
    , m_pms_pmswcr5(pms_pmswcr5_reset_value)
    , m_pms_pmswstat(pms_pmswstat_reset_value)
    , m_pms_pmswstat2(pms_pmswstat2_reset_value)
    , m_pms_pmswutcnt(pms_pmswutcnt_reset_value)
    , m_pms_pmswstatclr(pms_pmswstatclr_reset_value)
    , m_pms_evrsdstat0(pms_evrsdstat0_reset_value)
    , m_pms_evrsdctrl0(pms_evrsdctrl0_reset_value)
    , m_pms_evrsdctrl1(pms_evrsdctrl1_reset_value)
    , m_pms_evrsdctrl2(pms_evrsdctrl2_reset_value)
    , m_pms_evrsdctrl3(pms_evrsdctrl3_reset_value)
    , m_pms_evrsdctrl4(pms_evrsdctrl4_reset_value)
    , m_pms_evrsdctrl5(pms_evrsdctrl5_reset_value)
    , m_pms_evrsdctrl6(pms_evrsdctrl6_reset_value)
    , m_pms_evrsdctrl7(pms_evrsdctrl7_reset_value)
    , m_pms_evrsdctrl8(pms_evrsdctrl8_reset_value)
    , m_pms_evrsdctrl9(pms_evrsdctrl9_reset_value)
    , m_pms_evrsdctrl10(pms_evrsdctrl10_reset_value)
    , m_pms_evrsdcoeff0(pms_evrsdcoeff0_reset_value)
    , m_pms_evrsdcoeff1(pms_evrsdcoeff1_reset_value)
    , m_pms_evrsdcoeff2(pms_evrsdcoeff2_reset_value)
    , m_pms_evrsdcoeff3(pms_evrsdcoeff3_reset_value)
    , m_pms_ag_stdby0(pms_ag_stdby0_reset_value)
    , m_pms_ag_stdby1(pms_ag_stdby1_reset_value)
    , m_pms_monbiststat(pms_monbiststat_reset_value)
    , m_pms_monbistctrl(pms_monbistctrl_reset_value)
    , m_pms_cmd_stdby(pms_cmd_stdby_reset_value)
    , m_pms_agfsp_stdby0(pms_agfsp_stdby0_reset_value)
    , m_pms_agfsp_stdby1(pms_agfsp_stdby1_reset_value)
    , m_pms_dtsstat(pms_dtsstat_reset_value)
    , m_pms_dtslim(pms_dtslim_reset_value)
    , m_pms_otss(pms_otss_reset_value)
    , m_pms_otsc0(pms_otsc0_reset_value)
    , m_pms_otsc1(pms_otsc1_reset_value)
    , m_pms_accen0(pms_accen0_reset_value)
    , m_pms_accen1(pms_accen1_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Peripherals::Pms::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - pms_memory_start_address;
    switch (offset) {
    case reg_pms_id_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrstat_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrstat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evradcstat_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRADCSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evradcstat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrrstcon_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRRSTCON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrrstcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrrststat_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRRSTSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrrststat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrtrim_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRTRIM in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrtrim);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrtrimstat_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRTRIMSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrtrimstat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_monstat1_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_MONSTAT1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_monstat1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_monstat2_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_MONSTAT2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_monstat2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_monctrl_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_MONCTRL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_monctrl);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_monfilt_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_MONFILT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_monfilt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_pmsien_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_PMSIEN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_pmsien);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_uvmon_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_UVMON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_uvmon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_ovmon_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_OVMON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_ovmon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_uvmon2_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_UVMON2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_uvmon2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_ovmon2_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_OVMON2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_ovmon2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_hsmuvmon_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_HSMUVMON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_hsmuvmon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_hsmovmon_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_HSMOVMON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_hsmovmon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evr33con_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVR33CON in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evr33con);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evroscctrl_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVROSCCTRL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evroscctrl);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_pmswcr0_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_PMSWCR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_pmswcr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_pmswcr2_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_PMSWCR2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_pmswcr2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_pmswcr3_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_PMSWCR3 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_pmswcr3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_pmswcr4_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_PMSWCR4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_pmswcr4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_pmswcr5_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_PMSWCR5 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_pmswcr5);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_pmswstat_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_PMSWSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_pmswstat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_pmswstat2_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_PMSWSTAT2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_pmswstat2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_pmswutcnt_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_PMSWUTCNT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_pmswutcnt);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_pmswstatclr_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_PMSWSTATCLR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_pmswstatclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdstat0_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDSTAT0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdstat0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdctrl0_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdctrl0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdctrl1_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdctrl1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdctrl2_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdctrl2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdctrl3_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL3 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdctrl3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdctrl4_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL4 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdctrl4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdctrl5_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL5 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdctrl5);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdctrl6_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL6 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdctrl6);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdctrl7_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL7 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdctrl7);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdctrl8_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL8 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdctrl8);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdctrl9_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL9 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdctrl9);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdctrl10_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL10 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdctrl10);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdcoeff0_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCOEFF0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdcoeff0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdcoeff1_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCOEFF1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdcoeff1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdcoeff2_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCOEFF2 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdcoeff2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_evrsdcoeff3_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_EVRSDCOEFF3 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_evrsdcoeff3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_ag_stdby0_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_AG_STDBY0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_ag_stdby0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_ag_stdby1_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_AG_STDBY1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_ag_stdby1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_monbiststat_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_MONBISTSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_monbiststat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_monbistctrl_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_MONBISTCTRL in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_monbistctrl);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_cmd_stdby_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_CMD_STDBY in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_cmd_stdby);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_agfsp_stdby0_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_AGFSP_STDBY0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_agfsp_stdby0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_agfsp_stdby1_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_AGFSP_STDBY1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_agfsp_stdby1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_dtsstat_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_DTSSTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_dtsstat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_dtslim_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_DTSLIM in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_dtslim);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_otss_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_OTSS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_otss);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_otsc0_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_OTSC0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_otsc0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_otsc1_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_OTSC1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_otsc1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_accen0_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_pms_accen1_offset: {
            spdlog::debug("PMS: accessing PMS.PMS_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_pms_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Pms peripheral", address)};
        break;
    }
}

void Tricore::Peripherals::Pms::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - pms_memory_start_address;
    switch (offset) {
    case reg_pms_id_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_id));
    } break;
    case reg_pms_evrstat_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrstat));
    } break;
    case reg_pms_evradcstat_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRADCSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evradcstat));
    } break;
    case reg_pms_evrrstcon_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRRSTCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrrstcon));
    } break;
    case reg_pms_evrrststat_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRRSTSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrrststat));
    } break;
    case reg_pms_evrtrim_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRTRIM in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrtrim));
    } break;
    case reg_pms_evrtrimstat_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRTRIMSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrtrimstat));
    } break;
    case reg_pms_monstat1_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_MONSTAT1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_monstat1));
    } break;
    case reg_pms_monstat2_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_MONSTAT2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_monstat2));
    } break;
    case reg_pms_monctrl_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_MONCTRL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_monctrl));
    } break;
    case reg_pms_monfilt_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_MONFILT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_monfilt));
    } break;
    case reg_pms_pmsien_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_PMSIEN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_pmsien));
    } break;
    case reg_pms_uvmon_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_UVMON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_uvmon));
    } break;
    case reg_pms_ovmon_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_OVMON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_ovmon));
    } break;
    case reg_pms_uvmon2_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_UVMON2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_uvmon2));
    } break;
    case reg_pms_ovmon2_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_OVMON2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_ovmon2));
    } break;
    case reg_pms_hsmuvmon_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_HSMUVMON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_hsmuvmon));
    } break;
    case reg_pms_hsmovmon_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_HSMOVMON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_hsmovmon));
    } break;
    case reg_pms_evr33con_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVR33CON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evr33con));
    } break;
    case reg_pms_evroscctrl_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVROSCCTRL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evroscctrl));
    } break;
    case reg_pms_pmswcr0_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_PMSWCR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_pmswcr0));
    } break;
    case reg_pms_pmswcr2_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_PMSWCR2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_pmswcr2));
    } break;
    case reg_pms_pmswcr3_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_PMSWCR3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_pmswcr3));
    } break;
    case reg_pms_pmswcr4_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_PMSWCR4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_pmswcr4));
    } break;
    case reg_pms_pmswcr5_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_PMSWCR5 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_pmswcr5));
    } break;
    case reg_pms_pmswstat_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_PMSWSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_pmswstat));
    } break;
    case reg_pms_pmswstat2_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_PMSWSTAT2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_pmswstat2));
    } break;
    case reg_pms_pmswutcnt_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_PMSWUTCNT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_pmswutcnt));
    } break;
    case reg_pms_pmswstatclr_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_PMSWSTATCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_pmswstatclr));
    } break;
    case reg_pms_evrsdstat0_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDSTAT0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdstat0));
    } break;
    case reg_pms_evrsdctrl0_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdctrl0));
    } break;
    case reg_pms_evrsdctrl1_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdctrl1));
    } break;
    case reg_pms_evrsdctrl2_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdctrl2));
    } break;
    case reg_pms_evrsdctrl3_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdctrl3));
    } break;
    case reg_pms_evrsdctrl4_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdctrl4));
    } break;
    case reg_pms_evrsdctrl5_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL5 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdctrl5));
    } break;
    case reg_pms_evrsdctrl6_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL6 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdctrl6));
    } break;
    case reg_pms_evrsdctrl7_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL7 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdctrl7));
    } break;
    case reg_pms_evrsdctrl8_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL8 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdctrl8));
    } break;
    case reg_pms_evrsdctrl9_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL9 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdctrl9));
    } break;
    case reg_pms_evrsdctrl10_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCTRL10 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdctrl10));
    } break;
    case reg_pms_evrsdcoeff0_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCOEFF0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdcoeff0));
    } break;
    case reg_pms_evrsdcoeff1_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCOEFF1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdcoeff1));
    } break;
    case reg_pms_evrsdcoeff2_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCOEFF2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdcoeff2));
    } break;
    case reg_pms_evrsdcoeff3_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_EVRSDCOEFF3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_evrsdcoeff3));
    } break;
    case reg_pms_ag_stdby0_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_AG_STDBY0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_ag_stdby0));
    } break;
    case reg_pms_ag_stdby1_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_AG_STDBY1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_ag_stdby1));
    } break;
    case reg_pms_monbiststat_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_MONBISTSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_monbiststat));
    } break;
    case reg_pms_monbistctrl_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_MONBISTCTRL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_monbistctrl));
    } break;
    case reg_pms_cmd_stdby_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_CMD_STDBY in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_cmd_stdby));
    } break;
    case reg_pms_agfsp_stdby0_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_AGFSP_STDBY0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_agfsp_stdby0));
    } break;
    case reg_pms_agfsp_stdby1_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_AGFSP_STDBY1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_agfsp_stdby1));
    } break;
    case reg_pms_dtsstat_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_DTSSTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_dtsstat));
    } break;
    case reg_pms_dtslim_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_DTSLIM in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_dtslim));
    } break;
    case reg_pms_otss_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_OTSS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_otss));
    } break;
    case reg_pms_otsc0_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_OTSC0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_otsc0));
    } break;
    case reg_pms_otsc1_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_OTSC1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_otsc1));
    } break;
    case reg_pms_accen0_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_accen0));
    } break;
    case reg_pms_accen1_offset: {
        spdlog::debug("PMS: accessing PMS.PMS_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_pms_accen1));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Pms peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
