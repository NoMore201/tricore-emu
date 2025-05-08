
/**
 * @brief Module source for Can peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Can.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 can0_clc_reset_value = 0; // TODO: change according manual
constexpr u32 can0_id_reset_value = 0; // TODO: change according manual
constexpr u32 can0_mcr_reset_value = 0; // TODO: change according manual
constexpr u32 can0_bufadr_reset_value = 0; // TODO: change according manual
constexpr u32 can0_mecr_reset_value = 0; // TODO: change according manual
constexpr u32 can0_mestat_reset_value = 0; // TODO: change according manual
constexpr u32 can0_accenctr0_reset_value = 0; // TODO: change according manual
constexpr u32 can0_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 can0_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 can0_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 can0_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 can0_accen0_reset_value = 0; // TODO: change according manual
constexpr u32 can1_clc_reset_value = 0; // TODO: change according manual
constexpr u32 can1_id_reset_value = 0; // TODO: change according manual
constexpr u32 can1_mcr_reset_value = 0; // TODO: change according manual
constexpr u32 can1_accenctr0_reset_value = 0; // TODO: change according manual
constexpr u32 can1_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 can1_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 can1_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 can1_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 can1_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 can_memory_start_address = 0xf0200000U;
constexpr u32 can_memory_size = 0; // TODO: update according manual;
constexpr u32 can_memory_end_address = can_memory_start_address + can_memory_size;

constexpr u32 reg_can0_clc_address = 0xf0208000;
constexpr u32 reg_can0_clc_offset = reg_can0_clc_address - can_memory_start_address;
constexpr u32 reg_can0_id_address = 0xf0208008;
constexpr u32 reg_can0_id_offset = reg_can0_id_address - can_memory_start_address;
constexpr u32 reg_can0_mcr_address = 0xf0208030;
constexpr u32 reg_can0_mcr_offset = reg_can0_mcr_address - can_memory_start_address;
constexpr u32 reg_can0_bufadr_address = 0xf0208034;
constexpr u32 reg_can0_bufadr_offset = reg_can0_bufadr_address - can_memory_start_address;
constexpr u32 reg_can0_mecr_address = 0xf0208040;
constexpr u32 reg_can0_mecr_offset = reg_can0_mecr_address - can_memory_start_address;
constexpr u32 reg_can0_mestat_address = 0xf0208044;
constexpr u32 reg_can0_mestat_offset = reg_can0_mestat_address - can_memory_start_address;
constexpr u32 reg_can0_accenctr0_address = 0xf02080dc;
constexpr u32 reg_can0_accenctr0_offset = reg_can0_accenctr0_address - can_memory_start_address;
constexpr u32 reg_can0_ocs_address = 0xf02080e8;
constexpr u32 reg_can0_ocs_offset = reg_can0_ocs_address - can_memory_start_address;
constexpr u32 reg_can0_krstclr_address = 0xf02080ec;
constexpr u32 reg_can0_krstclr_offset = reg_can0_krstclr_address - can_memory_start_address;
constexpr u32 reg_can0_krst1_address = 0xf02080f0;
constexpr u32 reg_can0_krst1_offset = reg_can0_krst1_address - can_memory_start_address;
constexpr u32 reg_can0_krst0_address = 0xf02080f4;
constexpr u32 reg_can0_krst0_offset = reg_can0_krst0_address - can_memory_start_address;
constexpr u32 reg_can0_accen0_address = 0xf02080fc;
constexpr u32 reg_can0_accen0_offset = reg_can0_accen0_address - can_memory_start_address;
constexpr u32 reg_can1_clc_address = 0xf0218000;
constexpr u32 reg_can1_clc_offset = reg_can1_clc_address - can_memory_start_address;
constexpr u32 reg_can1_id_address = 0xf0218008;
constexpr u32 reg_can1_id_offset = reg_can1_id_address - can_memory_start_address;
constexpr u32 reg_can1_mcr_address = 0xf0218030;
constexpr u32 reg_can1_mcr_offset = reg_can1_mcr_address - can_memory_start_address;
constexpr u32 reg_can1_accenctr0_address = 0xf02180dc;
constexpr u32 reg_can1_accenctr0_offset = reg_can1_accenctr0_address - can_memory_start_address;
constexpr u32 reg_can1_ocs_address = 0xf02180e8;
constexpr u32 reg_can1_ocs_offset = reg_can1_ocs_address - can_memory_start_address;
constexpr u32 reg_can1_krstclr_address = 0xf02180ec;
constexpr u32 reg_can1_krstclr_offset = reg_can1_krstclr_address - can_memory_start_address;
constexpr u32 reg_can1_krst1_address = 0xf02180f0;
constexpr u32 reg_can1_krst1_offset = reg_can1_krst1_address - can_memory_start_address;
constexpr u32 reg_can1_krst0_address = 0xf02180f4;
constexpr u32 reg_can1_krst0_offset = reg_can1_krst0_address - can_memory_start_address;
constexpr u32 reg_can1_accen0_address = 0xf02180fc;
constexpr u32 reg_can1_accen0_offset = reg_can1_accen0_address - can_memory_start_address;

} // anonymous namespace


Tricore::Can::Can()
    : m_can0_clc(can0_clc_reset_value)
    , m_can0_id(can0_id_reset_value)
    , m_can0_mcr(can0_mcr_reset_value)
    , m_can0_bufadr(can0_bufadr_reset_value)
    , m_can0_mecr(can0_mecr_reset_value)
    , m_can0_mestat(can0_mestat_reset_value)
    , m_can0_accenctr0(can0_accenctr0_reset_value)
    , m_can0_ocs(can0_ocs_reset_value)
    , m_can0_krstclr(can0_krstclr_reset_value)
    , m_can0_krst1(can0_krst1_reset_value)
    , m_can0_krst0(can0_krst0_reset_value)
    , m_can0_accen0(can0_accen0_reset_value)
    , m_can1_clc(can1_clc_reset_value)
    , m_can1_id(can1_id_reset_value)
    , m_can1_mcr(can1_mcr_reset_value)
    , m_can1_accenctr0(can1_accenctr0_reset_value)
    , m_can1_ocs(can1_ocs_reset_value)
    , m_can1_krstclr(can1_krstclr_reset_value)
    , m_can1_krst1(can1_krst1_reset_value)
    , m_can1_krst0(can1_krst0_reset_value)
    , m_can1_accen0(can1_accen0_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Can::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - can_memory_start_address;
    switch (offset) {
    case reg_can0_clc_offset: {
            spdlog::debug("CAN: accessing CAN.CAN0_CLC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can0_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can0_id_offset: {
            spdlog::debug("CAN: accessing CAN.CAN0_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can0_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can0_mcr_offset: {
            spdlog::debug("CAN: accessing CAN.CAN0_MCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can0_mcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can0_bufadr_offset: {
            spdlog::debug("CAN: accessing CAN.CAN0_BUFADR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can0_bufadr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can0_mecr_offset: {
            spdlog::debug("CAN: accessing CAN.CAN0_MECR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can0_mecr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can0_mestat_offset: {
            spdlog::debug("CAN: accessing CAN.CAN0_MESTAT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can0_mestat);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can0_accenctr0_offset: {
            spdlog::debug("CAN: accessing CAN.CAN0_ACCENCTR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can0_accenctr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can0_ocs_offset: {
            spdlog::debug("CAN: accessing CAN.CAN0_OCS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can0_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can0_krstclr_offset: {
            spdlog::debug("CAN: accessing CAN.CAN0_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can0_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can0_krst1_offset: {
            spdlog::debug("CAN: accessing CAN.CAN0_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can0_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can0_krst0_offset: {
            spdlog::debug("CAN: accessing CAN.CAN0_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can0_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can0_accen0_offset: {
            spdlog::debug("CAN: accessing CAN.CAN0_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can0_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can1_clc_offset: {
            spdlog::debug("CAN: accessing CAN.CAN1_CLC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can1_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can1_id_offset: {
            spdlog::debug("CAN: accessing CAN.CAN1_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can1_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can1_mcr_offset: {
            spdlog::debug("CAN: accessing CAN.CAN1_MCR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can1_mcr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can1_accenctr0_offset: {
            spdlog::debug("CAN: accessing CAN.CAN1_ACCENCTR0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can1_accenctr0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can1_ocs_offset: {
            spdlog::debug("CAN: accessing CAN.CAN1_OCS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can1_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can1_krstclr_offset: {
            spdlog::debug("CAN: accessing CAN.CAN1_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can1_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can1_krst1_offset: {
            spdlog::debug("CAN: accessing CAN.CAN1_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can1_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can1_krst0_offset: {
            spdlog::debug("CAN: accessing CAN.CAN1_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can1_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_can1_accen0_offset: {
            spdlog::debug("CAN: accessing CAN.CAN1_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_can1_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Can peripheral", address)};
        break;
    }
}

void Tricore::Can::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - can_memory_start_address;
    switch (offset) {
    case reg_can0_clc_offset: {
        spdlog::debug("CAN: accessing CAN.CAN0_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can0_clc));
    } break;
    case reg_can0_id_offset: {
        spdlog::debug("CAN: accessing CAN.CAN0_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can0_id));
    } break;
    case reg_can0_mcr_offset: {
        spdlog::debug("CAN: accessing CAN.CAN0_MCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can0_mcr));
    } break;
    case reg_can0_bufadr_offset: {
        spdlog::debug("CAN: accessing CAN.CAN0_BUFADR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can0_bufadr));
    } break;
    case reg_can0_mecr_offset: {
        spdlog::debug("CAN: accessing CAN.CAN0_MECR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can0_mecr));
    } break;
    case reg_can0_mestat_offset: {
        spdlog::debug("CAN: accessing CAN.CAN0_MESTAT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can0_mestat));
    } break;
    case reg_can0_accenctr0_offset: {
        spdlog::debug("CAN: accessing CAN.CAN0_ACCENCTR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can0_accenctr0));
    } break;
    case reg_can0_ocs_offset: {
        spdlog::debug("CAN: accessing CAN.CAN0_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can0_ocs));
    } break;
    case reg_can0_krstclr_offset: {
        spdlog::debug("CAN: accessing CAN.CAN0_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can0_krstclr));
    } break;
    case reg_can0_krst1_offset: {
        spdlog::debug("CAN: accessing CAN.CAN0_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can0_krst1));
    } break;
    case reg_can0_krst0_offset: {
        spdlog::debug("CAN: accessing CAN.CAN0_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can0_krst0));
    } break;
    case reg_can0_accen0_offset: {
        spdlog::debug("CAN: accessing CAN.CAN0_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can0_accen0));
    } break;
    case reg_can1_clc_offset: {
        spdlog::debug("CAN: accessing CAN.CAN1_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can1_clc));
    } break;
    case reg_can1_id_offset: {
        spdlog::debug("CAN: accessing CAN.CAN1_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can1_id));
    } break;
    case reg_can1_mcr_offset: {
        spdlog::debug("CAN: accessing CAN.CAN1_MCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can1_mcr));
    } break;
    case reg_can1_accenctr0_offset: {
        spdlog::debug("CAN: accessing CAN.CAN1_ACCENCTR0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can1_accenctr0));
    } break;
    case reg_can1_ocs_offset: {
        spdlog::debug("CAN: accessing CAN.CAN1_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can1_ocs));
    } break;
    case reg_can1_krstclr_offset: {
        spdlog::debug("CAN: accessing CAN.CAN1_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can1_krstclr));
    } break;
    case reg_can1_krst1_offset: {
        spdlog::debug("CAN: accessing CAN.CAN1_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can1_krst1));
    } break;
    case reg_can1_krst0_offset: {
        spdlog::debug("CAN: accessing CAN.CAN1_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can1_krst0));
    } break;
    case reg_can1_accen0_offset: {
        spdlog::debug("CAN: accessing CAN.CAN1_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_can1_accen0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Can peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
