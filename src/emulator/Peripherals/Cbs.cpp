
/**
 * @brief Module source for Cbs peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Cbs.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 cbs_jdpid_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_oifm_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tipr_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_topr_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_topps_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tcip_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_trhsm_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_trmc_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_trss_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_jtagid_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_comdata_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_iosr_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tls_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tctl_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_oec_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_ocntrl_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_ostate_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_intmod_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_ictsa_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_ictta_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tlc_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tl1st_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tlche_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tlchs_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_trigs_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_trigc_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tlt_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tltth_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tccb_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tcch_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tctgb_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_tcm_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_trmt_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_ifsa_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_ifsc_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 cbs_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 cbs_memory_start_address = 0xf0000400U;
constexpr u32 cbs_memory_size = 0; // TODO: update according manual;
constexpr u32 cbs_memory_end_address = cbs_memory_start_address + cbs_memory_size;

constexpr u32 reg_cbs_jdpid_address = 0xf0000408;
constexpr u32 reg_cbs_jdpid_offset = reg_cbs_jdpid_address - cbs_memory_start_address;
constexpr u32 reg_cbs_oifm_address = 0xf000040c;
constexpr u32 reg_cbs_oifm_offset = reg_cbs_oifm_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tipr_address = 0xf0000410;
constexpr u32 reg_cbs_tipr_offset = reg_cbs_tipr_address - cbs_memory_start_address;
constexpr u32 reg_cbs_topr_address = 0xf0000414;
constexpr u32 reg_cbs_topr_offset = reg_cbs_topr_address - cbs_memory_start_address;
constexpr u32 reg_cbs_topps_address = 0xf0000418;
constexpr u32 reg_cbs_topps_offset = reg_cbs_topps_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tcip_address = 0xf000041c;
constexpr u32 reg_cbs_tcip_offset = reg_cbs_tcip_address - cbs_memory_start_address;
constexpr u32 reg_cbs_trhsm_address = 0xf0000438;
constexpr u32 reg_cbs_trhsm_offset = reg_cbs_trhsm_address - cbs_memory_start_address;
constexpr u32 reg_cbs_trmc_address = 0xf000043c;
constexpr u32 reg_cbs_trmc_offset = reg_cbs_trmc_address - cbs_memory_start_address;
constexpr u32 reg_cbs_trss_address = 0xf0000460;
constexpr u32 reg_cbs_trss_offset = reg_cbs_trss_address - cbs_memory_start_address;
constexpr u32 reg_cbs_jtagid_address = 0xf0000464;
constexpr u32 reg_cbs_jtagid_offset = reg_cbs_jtagid_address - cbs_memory_start_address;
constexpr u32 reg_cbs_comdata_address = 0xf0000468;
constexpr u32 reg_cbs_comdata_offset = reg_cbs_comdata_address - cbs_memory_start_address;
constexpr u32 reg_cbs_iosr_address = 0xf000046c;
constexpr u32 reg_cbs_iosr_offset = reg_cbs_iosr_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tls_address = 0xf0000470;
constexpr u32 reg_cbs_tls_offset = reg_cbs_tls_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tctl_address = 0xf0000474;
constexpr u32 reg_cbs_tctl_offset = reg_cbs_tctl_address - cbs_memory_start_address;
constexpr u32 reg_cbs_oec_address = 0xf0000478;
constexpr u32 reg_cbs_oec_offset = reg_cbs_oec_address - cbs_memory_start_address;
constexpr u32 reg_cbs_ocntrl_address = 0xf000047c;
constexpr u32 reg_cbs_ocntrl_offset = reg_cbs_ocntrl_address - cbs_memory_start_address;
constexpr u32 reg_cbs_ostate_address = 0xf0000480;
constexpr u32 reg_cbs_ostate_offset = reg_cbs_ostate_address - cbs_memory_start_address;
constexpr u32 reg_cbs_intmod_address = 0xf0000484;
constexpr u32 reg_cbs_intmod_offset = reg_cbs_intmod_address - cbs_memory_start_address;
constexpr u32 reg_cbs_ictsa_address = 0xf0000488;
constexpr u32 reg_cbs_ictsa_offset = reg_cbs_ictsa_address - cbs_memory_start_address;
constexpr u32 reg_cbs_ictta_address = 0xf000048c;
constexpr u32 reg_cbs_ictta_offset = reg_cbs_ictta_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tlc_address = 0xf0000490;
constexpr u32 reg_cbs_tlc_offset = reg_cbs_tlc_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tl1st_address = 0xf0000494;
constexpr u32 reg_cbs_tl1st_offset = reg_cbs_tl1st_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tlche_address = 0xf0000498;
constexpr u32 reg_cbs_tlche_offset = reg_cbs_tlche_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tlchs_address = 0xf000049c;
constexpr u32 reg_cbs_tlchs_offset = reg_cbs_tlchs_address - cbs_memory_start_address;
constexpr u32 reg_cbs_trigs_address = 0xf00004a0;
constexpr u32 reg_cbs_trigs_offset = reg_cbs_trigs_address - cbs_memory_start_address;
constexpr u32 reg_cbs_trigc_address = 0xf00004a4;
constexpr u32 reg_cbs_trigc_offset = reg_cbs_trigc_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tlt_address = 0xf00004a8;
constexpr u32 reg_cbs_tlt_offset = reg_cbs_tlt_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tltth_address = 0xf00004ac;
constexpr u32 reg_cbs_tltth_offset = reg_cbs_tltth_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tccb_address = 0xf00004b0;
constexpr u32 reg_cbs_tccb_offset = reg_cbs_tccb_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tcch_address = 0xf00004b4;
constexpr u32 reg_cbs_tcch_offset = reg_cbs_tcch_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tctgb_address = 0xf00004b8;
constexpr u32 reg_cbs_tctgb_offset = reg_cbs_tctgb_address - cbs_memory_start_address;
constexpr u32 reg_cbs_tcm_address = 0xf00004bc;
constexpr u32 reg_cbs_tcm_offset = reg_cbs_tcm_address - cbs_memory_start_address;
constexpr u32 reg_cbs_trmt_address = 0xf00004dc;
constexpr u32 reg_cbs_trmt_offset = reg_cbs_trmt_address - cbs_memory_start_address;
constexpr u32 reg_cbs_ifsa_address = 0xf00004f0;
constexpr u32 reg_cbs_ifsa_offset = reg_cbs_ifsa_address - cbs_memory_start_address;
constexpr u32 reg_cbs_ifsc_address = 0xf00004f4;
constexpr u32 reg_cbs_ifsc_offset = reg_cbs_ifsc_address - cbs_memory_start_address;
constexpr u32 reg_cbs_accen1_address = 0xf00005f8;
constexpr u32 reg_cbs_accen1_offset = reg_cbs_accen1_address - cbs_memory_start_address;
constexpr u32 reg_cbs_accen0_address = 0xf00005fc;
constexpr u32 reg_cbs_accen0_offset = reg_cbs_accen0_address - cbs_memory_start_address;

} // anonymous namespace

Tricore::Cbs::Cbs()
    : m_cbs_jdpid(cbs_jdpid_reset_value)
    , m_cbs_oifm(cbs_oifm_reset_value)
    , m_cbs_tipr(cbs_tipr_reset_value)
    , m_cbs_topr(cbs_topr_reset_value)
    , m_cbs_topps(cbs_topps_reset_value)
    , m_cbs_tcip(cbs_tcip_reset_value)
    , m_cbs_trhsm(cbs_trhsm_reset_value)
    , m_cbs_trmc(cbs_trmc_reset_value)
    , m_cbs_trss(cbs_trss_reset_value)
    , m_cbs_jtagid(cbs_jtagid_reset_value)
    , m_cbs_comdata(cbs_comdata_reset_value)
    , m_cbs_iosr(cbs_iosr_reset_value)
    , m_cbs_tls(cbs_tls_reset_value)
    , m_cbs_tctl(cbs_tctl_reset_value)
    , m_cbs_oec(cbs_oec_reset_value)
    , m_cbs_ocntrl(cbs_ocntrl_reset_value)
    , m_cbs_ostate(cbs_ostate_reset_value)
    , m_cbs_intmod(cbs_intmod_reset_value)
    , m_cbs_ictsa(cbs_ictsa_reset_value)
    , m_cbs_ictta(cbs_ictta_reset_value)
    , m_cbs_tlc(cbs_tlc_reset_value)
    , m_cbs_tl1st(cbs_tl1st_reset_value)
    , m_cbs_tlche(cbs_tlche_reset_value)
    , m_cbs_tlchs(cbs_tlchs_reset_value)
    , m_cbs_trigs(cbs_trigs_reset_value)
    , m_cbs_trigc(cbs_trigc_reset_value)
    , m_cbs_tlt(cbs_tlt_reset_value)
    , m_cbs_tltth(cbs_tltth_reset_value)
    , m_cbs_tccb(cbs_tccb_reset_value)
    , m_cbs_tcch(cbs_tcch_reset_value)
    , m_cbs_tctgb(cbs_tctgb_reset_value)
    , m_cbs_tcm(cbs_tcm_reset_value)
    , m_cbs_trmt(cbs_trmt_reset_value)
    , m_cbs_ifsa(cbs_ifsa_reset_value)
    , m_cbs_ifsc(cbs_ifsc_reset_value)
    , m_cbs_accen1(cbs_accen1_reset_value)
    , m_cbs_accen0(cbs_accen0_reset_value)
{
}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Cbs::read(byte* buffer_out, u32 address, usize length)
{
    const u32 offset = address - cbs_memory_start_address;
    switch (offset) {
    case reg_cbs_jdpid_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_JDPID in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_jdpid);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_oifm_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_OIFM in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_oifm);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tipr_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TIPR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tipr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_topr_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TOPR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_topr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_topps_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TOPPS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_topps);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tcip_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TCIP in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tcip);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_trhsm_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TRHSM in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_trhsm);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_trmc_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TRMC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_trmc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_trss_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TRSS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_trss);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_jtagid_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_JTAGID in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_jtagid);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_comdata_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_COMDATA in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_comdata);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_iosr_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_IOSR in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_iosr);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tls_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TLS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tls);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tctl_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TCTL in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tctl);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_oec_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_OEC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_oec);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_ocntrl_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_OCNTRL in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_ocntrl);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_ostate_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_OSTATE in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_ostate);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_intmod_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_INTMOD in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_intmod);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_ictsa_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_ICTSA in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_ictsa);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_ictta_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_ICTTA in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_ictta);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tlc_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TLC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tlc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tl1st_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TL1ST in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tl1st);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tlche_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TLCHE in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tlche);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tlchs_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TLCHS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tlchs);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_trigs_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TRIGS in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_trigs);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_trigc_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TRIGC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_trigc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tlt_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TLT in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tlt);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tltth_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TLTTH in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tltth);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tccb_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TCCB in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tccb);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tcch_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TCCH in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tcch);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tctgb_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TCTGB in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tctgb);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_tcm_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TCM in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_tcm);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_trmt_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TRMT in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_trmt);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_ifsa_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_IFSA in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_ifsa);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_ifsc_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_IFSC in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_ifsc);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_accen1_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_ACCEN1 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_accen1);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    case reg_cbs_accen0_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_ACCEN0 in read mode");
        const auto* range_start = reinterpret_cast<byte*>(&m_cbs_accen0);
        std::ranges::copy(range_start, range_start + length, buffer_out);
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Cbs peripheral", address) };
        break;
    }
}

void Tricore::Cbs::write(const byte* buffer_in, u32 address,
    usize length)
{
    const u32 offset = address - cbs_memory_start_address;
    switch (offset) {
    case reg_cbs_jdpid_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_JDPID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_jdpid));
    } break;
    case reg_cbs_oifm_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_OIFM in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_oifm));
    } break;
    case reg_cbs_tipr_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TIPR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tipr));
    } break;
    case reg_cbs_topr_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TOPR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_topr));
    } break;
    case reg_cbs_topps_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TOPPS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_topps));
    } break;
    case reg_cbs_tcip_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TCIP in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tcip));
    } break;
    case reg_cbs_trhsm_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TRHSM in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_trhsm));
    } break;
    case reg_cbs_trmc_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TRMC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_trmc));
    } break;
    case reg_cbs_trss_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TRSS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_trss));
    } break;
    case reg_cbs_jtagid_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_JTAGID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_jtagid));
    } break;
    case reg_cbs_comdata_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_COMDATA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_comdata));
    } break;
    case reg_cbs_iosr_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_IOSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_iosr));
    } break;
    case reg_cbs_tls_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TLS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tls));
    } break;
    case reg_cbs_tctl_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TCTL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tctl));
    } break;
    case reg_cbs_oec_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_OEC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_oec));
    } break;
    case reg_cbs_ocntrl_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_OCNTRL in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_ocntrl));
    } break;
    case reg_cbs_ostate_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_OSTATE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_ostate));
    } break;
    case reg_cbs_intmod_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_INTMOD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_intmod));
    } break;
    case reg_cbs_ictsa_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_ICTSA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_ictsa));
    } break;
    case reg_cbs_ictta_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_ICTTA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_ictta));
    } break;
    case reg_cbs_tlc_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tlc));
    } break;
    case reg_cbs_tl1st_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TL1ST in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tl1st));
    } break;
    case reg_cbs_tlche_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TLCHE in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tlche));
    } break;
    case reg_cbs_tlchs_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TLCHS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tlchs));
    } break;
    case reg_cbs_trigs_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TRIGS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_trigs));
    } break;
    case reg_cbs_trigc_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TRIGC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_trigc));
    } break;
    case reg_cbs_tlt_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TLT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tlt));
    } break;
    case reg_cbs_tltth_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TLTTH in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tltth));
    } break;
    case reg_cbs_tccb_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TCCB in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tccb));
    } break;
    case reg_cbs_tcch_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TCCH in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tcch));
    } break;
    case reg_cbs_tctgb_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TCTGB in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tctgb));
    } break;
    case reg_cbs_tcm_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TCM in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_tcm));
    } break;
    case reg_cbs_trmt_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_TRMT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_trmt));
    } break;
    case reg_cbs_ifsa_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_IFSA in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_ifsa));
    } break;
    case reg_cbs_ifsc_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_IFSC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_ifsc));
    } break;
    case reg_cbs_accen1_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_accen1));
    } break;
    case reg_cbs_accen0_offset: {
        spdlog::debug("CBS: accessing CBS.CBS_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
            reinterpret_cast<byte*>(&m_cbs_accen0));
    } break;
    default:
        throw InvalidMemoryAccess { fmt::format(
            "Address 0x{:08X} not handled by Cbs peripheral", address) };
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
