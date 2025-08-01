
/**
 * @brief Module source for Sent peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Sent.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 sent_clc_reset_value = 0; // TODO: change according manual
constexpr u32 sent_id_reset_value = 0; // TODO: change according manual
constexpr u32 sent_fdr_reset_value = 0; // TODO: change according manual
constexpr u32 sent_intov_reset_value = 0; // TODO: change according manual
constexpr u32 sent_tsr_reset_value = 0; // TODO: change according manual
constexpr u32 sent_tpd_reset_value = 0; // TODO: change according manual
constexpr u32 sent_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 sent_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 sent_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 sent_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 sent_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 sent_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 sent_memory_start_address = 0xf0003000U;
constexpr u32 sent_memory_size = 0; // TODO: update according manual;
constexpr u32 sent_memory_end_address = sent_memory_start_address + sent_memory_size;

constexpr u32 reg_sent_clc_address = 0xf0003000;
constexpr u32 reg_sent_clc_offset = reg_sent_clc_address - sent_memory_start_address;
constexpr u32 reg_sent_id_address = 0xf0003008;
constexpr u32 reg_sent_id_offset = reg_sent_id_address - sent_memory_start_address;
constexpr u32 reg_sent_fdr_address = 0xf000300c;
constexpr u32 reg_sent_fdr_offset = reg_sent_fdr_address - sent_memory_start_address;
constexpr u32 reg_sent_intov_address = 0xf0003014;
constexpr u32 reg_sent_intov_offset = reg_sent_intov_address - sent_memory_start_address;
constexpr u32 reg_sent_tsr_address = 0xf0003018;
constexpr u32 reg_sent_tsr_offset = reg_sent_tsr_address - sent_memory_start_address;
constexpr u32 reg_sent_tpd_address = 0xf000301c;
constexpr u32 reg_sent_tpd_offset = reg_sent_tpd_address - sent_memory_start_address;
constexpr u32 reg_sent_ocs_address = 0xf00030e8;
constexpr u32 reg_sent_ocs_offset = reg_sent_ocs_address - sent_memory_start_address;
constexpr u32 reg_sent_krstclr_address = 0xf00030ec;
constexpr u32 reg_sent_krstclr_offset = reg_sent_krstclr_address - sent_memory_start_address;
constexpr u32 reg_sent_krst1_address = 0xf00030f0;
constexpr u32 reg_sent_krst1_offset = reg_sent_krst1_address - sent_memory_start_address;
constexpr u32 reg_sent_krst0_address = 0xf00030f4;
constexpr u32 reg_sent_krst0_offset = reg_sent_krst0_address - sent_memory_start_address;
constexpr u32 reg_sent_accen1_address = 0xf00030f8;
constexpr u32 reg_sent_accen1_offset = reg_sent_accen1_address - sent_memory_start_address;
constexpr u32 reg_sent_accen0_address = 0xf00030fc;
constexpr u32 reg_sent_accen0_offset = reg_sent_accen0_address - sent_memory_start_address;

} // anonymous namespace


Tricore::Sent::Sent()
    : m_sent_clc(sent_clc_reset_value)
    , m_sent_id(sent_id_reset_value)
    , m_sent_fdr(sent_fdr_reset_value)
    , m_sent_intov(sent_intov_reset_value)
    , m_sent_tsr(sent_tsr_reset_value)
    , m_sent_tpd(sent_tpd_reset_value)
    , m_sent_ocs(sent_ocs_reset_value)
    , m_sent_krstclr(sent_krstclr_reset_value)
    , m_sent_krst1(sent_krst1_reset_value)
    , m_sent_krst0(sent_krst0_reset_value)
    , m_sent_accen1(sent_accen1_reset_value)
    , m_sent_accen0(sent_accen0_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Sent::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - sent_memory_start_address;
    switch (offset) {
    case reg_sent_clc_offset: {
            spdlog::debug("SENT: accessing SENT.SENT_CLC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sent_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sent_id_offset: {
            spdlog::debug("SENT: accessing SENT.SENT_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sent_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sent_fdr_offset: {
            spdlog::debug("SENT: accessing SENT.SENT_FDR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sent_fdr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sent_intov_offset: {
            spdlog::debug("SENT: accessing SENT.SENT_INTOV in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sent_intov);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sent_tsr_offset: {
            spdlog::debug("SENT: accessing SENT.SENT_TSR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sent_tsr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sent_tpd_offset: {
            spdlog::debug("SENT: accessing SENT.SENT_TPD in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sent_tpd);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sent_ocs_offset: {
            spdlog::debug("SENT: accessing SENT.SENT_OCS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sent_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sent_krstclr_offset: {
            spdlog::debug("SENT: accessing SENT.SENT_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sent_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sent_krst1_offset: {
            spdlog::debug("SENT: accessing SENT.SENT_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sent_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sent_krst0_offset: {
            spdlog::debug("SENT: accessing SENT.SENT_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sent_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sent_accen1_offset: {
            spdlog::debug("SENT: accessing SENT.SENT_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sent_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_sent_accen0_offset: {
            spdlog::debug("SENT: accessing SENT.SENT_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_sent_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Sent peripheral", address)};
        break;
    }
}

void Tricore::Sent::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - sent_memory_start_address;
    switch (offset) {
    case reg_sent_clc_offset: {
        spdlog::debug("SENT: accessing SENT.SENT_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sent_clc));
    } break;
    case reg_sent_id_offset: {
        spdlog::debug("SENT: accessing SENT.SENT_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sent_id));
    } break;
    case reg_sent_fdr_offset: {
        spdlog::debug("SENT: accessing SENT.SENT_FDR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sent_fdr));
    } break;
    case reg_sent_intov_offset: {
        spdlog::debug("SENT: accessing SENT.SENT_INTOV in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sent_intov));
    } break;
    case reg_sent_tsr_offset: {
        spdlog::debug("SENT: accessing SENT.SENT_TSR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sent_tsr));
    } break;
    case reg_sent_tpd_offset: {
        spdlog::debug("SENT: accessing SENT.SENT_TPD in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sent_tpd));
    } break;
    case reg_sent_ocs_offset: {
        spdlog::debug("SENT: accessing SENT.SENT_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sent_ocs));
    } break;
    case reg_sent_krstclr_offset: {
        spdlog::debug("SENT: accessing SENT.SENT_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sent_krstclr));
    } break;
    case reg_sent_krst1_offset: {
        spdlog::debug("SENT: accessing SENT.SENT_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sent_krst1));
    } break;
    case reg_sent_krst0_offset: {
        spdlog::debug("SENT: accessing SENT.SENT_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sent_krst0));
    } break;
    case reg_sent_accen1_offset: {
        spdlog::debug("SENT: accessing SENT.SENT_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sent_accen1));
    } break;
    case reg_sent_accen0_offset: {
        spdlog::debug("SENT: accessing SENT.SENT_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_sent_accen0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Sent peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
