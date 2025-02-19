
/**
 * @brief Module source for Stm peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Stm.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 stm0_clc_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_id_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_tim0_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_tim1_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_tim2_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_tim3_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_tim4_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_tim5_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_tim6_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_cap_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_cmcon_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_icr_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_iscr_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_tim0sv_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_capsv_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_ocs_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_krstclr_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_krst1_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_krst0_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_accen1_reset_value = 0; // TODO: change according manual
constexpr u32 stm0_accen0_reset_value = 0; // TODO: change according manual

constexpr u32 stm_memory_start_address = 0xf0001000U;
constexpr u32 stm_memory_size = 0; // TODO: update according manual;
constexpr u32 stm_memory_end_address = stm_memory_start_address + stm_memory_size;

constexpr u32 reg_stm0_clc_address = 0xf0001000;
constexpr u32 reg_stm0_clc_offset = reg_stm0_clc_address - stm_memory_start_address;
constexpr u32 reg_stm0_id_address = 0xf0001008;
constexpr u32 reg_stm0_id_offset = reg_stm0_id_address - stm_memory_start_address;
constexpr u32 reg_stm0_tim0_address = 0xf0001010;
constexpr u32 reg_stm0_tim0_offset = reg_stm0_tim0_address - stm_memory_start_address;
constexpr u32 reg_stm0_tim1_address = 0xf0001014;
constexpr u32 reg_stm0_tim1_offset = reg_stm0_tim1_address - stm_memory_start_address;
constexpr u32 reg_stm0_tim2_address = 0xf0001018;
constexpr u32 reg_stm0_tim2_offset = reg_stm0_tim2_address - stm_memory_start_address;
constexpr u32 reg_stm0_tim3_address = 0xf000101c;
constexpr u32 reg_stm0_tim3_offset = reg_stm0_tim3_address - stm_memory_start_address;
constexpr u32 reg_stm0_tim4_address = 0xf0001020;
constexpr u32 reg_stm0_tim4_offset = reg_stm0_tim4_address - stm_memory_start_address;
constexpr u32 reg_stm0_tim5_address = 0xf0001024;
constexpr u32 reg_stm0_tim5_offset = reg_stm0_tim5_address - stm_memory_start_address;
constexpr u32 reg_stm0_tim6_address = 0xf0001028;
constexpr u32 reg_stm0_tim6_offset = reg_stm0_tim6_address - stm_memory_start_address;
constexpr u32 reg_stm0_cap_address = 0xf000102c;
constexpr u32 reg_stm0_cap_offset = reg_stm0_cap_address - stm_memory_start_address;
constexpr u32 reg_stm0_cmcon_address = 0xf0001038;
constexpr u32 reg_stm0_cmcon_offset = reg_stm0_cmcon_address - stm_memory_start_address;
constexpr u32 reg_stm0_icr_address = 0xf000103c;
constexpr u32 reg_stm0_icr_offset = reg_stm0_icr_address - stm_memory_start_address;
constexpr u32 reg_stm0_iscr_address = 0xf0001040;
constexpr u32 reg_stm0_iscr_offset = reg_stm0_iscr_address - stm_memory_start_address;
constexpr u32 reg_stm0_tim0sv_address = 0xf0001050;
constexpr u32 reg_stm0_tim0sv_offset = reg_stm0_tim0sv_address - stm_memory_start_address;
constexpr u32 reg_stm0_capsv_address = 0xf0001054;
constexpr u32 reg_stm0_capsv_offset = reg_stm0_capsv_address - stm_memory_start_address;
constexpr u32 reg_stm0_ocs_address = 0xf00010e8;
constexpr u32 reg_stm0_ocs_offset = reg_stm0_ocs_address - stm_memory_start_address;
constexpr u32 reg_stm0_krstclr_address = 0xf00010ec;
constexpr u32 reg_stm0_krstclr_offset = reg_stm0_krstclr_address - stm_memory_start_address;
constexpr u32 reg_stm0_krst1_address = 0xf00010f0;
constexpr u32 reg_stm0_krst1_offset = reg_stm0_krst1_address - stm_memory_start_address;
constexpr u32 reg_stm0_krst0_address = 0xf00010f4;
constexpr u32 reg_stm0_krst0_offset = reg_stm0_krst0_address - stm_memory_start_address;
constexpr u32 reg_stm0_accen1_address = 0xf00010f8;
constexpr u32 reg_stm0_accen1_offset = reg_stm0_accen1_address - stm_memory_start_address;
constexpr u32 reg_stm0_accen0_address = 0xf00010fc;
constexpr u32 reg_stm0_accen0_offset = reg_stm0_accen0_address - stm_memory_start_address;

} // anonymous namespace


Tricore::Stm::Stm()
    : m_stm0_clc(stm0_clc_reset_value)
    , m_stm0_id(stm0_id_reset_value)
    , m_stm0_tim0(stm0_tim0_reset_value)
    , m_stm0_tim1(stm0_tim1_reset_value)
    , m_stm0_tim2(stm0_tim2_reset_value)
    , m_stm0_tim3(stm0_tim3_reset_value)
    , m_stm0_tim4(stm0_tim4_reset_value)
    , m_stm0_tim5(stm0_tim5_reset_value)
    , m_stm0_tim6(stm0_tim6_reset_value)
    , m_stm0_cap(stm0_cap_reset_value)
    , m_stm0_cmcon(stm0_cmcon_reset_value)
    , m_stm0_icr(stm0_icr_reset_value)
    , m_stm0_iscr(stm0_iscr_reset_value)
    , m_stm0_tim0sv(stm0_tim0sv_reset_value)
    , m_stm0_capsv(stm0_capsv_reset_value)
    , m_stm0_ocs(stm0_ocs_reset_value)
    , m_stm0_krstclr(stm0_krstclr_reset_value)
    , m_stm0_krst1(stm0_krst1_reset_value)
    , m_stm0_krst0(stm0_krst0_reset_value)
    , m_stm0_accen1(stm0_accen1_reset_value)
    , m_stm0_accen0(stm0_accen0_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Stm::read(std::byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - stm_memory_start_address;
    switch (offset) {
    case reg_stm0_clc_offset: {
            spdlog::debug("STM: accessing STM.STM0_CLC in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_clc);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_id_offset: {
            spdlog::debug("STM: accessing STM.STM0_ID in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_tim0_offset: {
            spdlog::debug("STM: accessing STM.STM0_TIM0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_tim0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_tim1_offset: {
            spdlog::debug("STM: accessing STM.STM0_TIM1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_tim1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_tim2_offset: {
            spdlog::debug("STM: accessing STM.STM0_TIM2 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_tim2);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_tim3_offset: {
            spdlog::debug("STM: accessing STM.STM0_TIM3 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_tim3);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_tim4_offset: {
            spdlog::debug("STM: accessing STM.STM0_TIM4 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_tim4);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_tim5_offset: {
            spdlog::debug("STM: accessing STM.STM0_TIM5 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_tim5);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_tim6_offset: {
            spdlog::debug("STM: accessing STM.STM0_TIM6 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_tim6);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_cap_offset: {
            spdlog::debug("STM: accessing STM.STM0_CAP in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_cap);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_cmcon_offset: {
            spdlog::debug("STM: accessing STM.STM0_CMCON in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_cmcon);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_icr_offset: {
            spdlog::debug("STM: accessing STM.STM0_ICR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_icr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_iscr_offset: {
            spdlog::debug("STM: accessing STM.STM0_ISCR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_iscr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_tim0sv_offset: {
            spdlog::debug("STM: accessing STM.STM0_TIM0SV in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_tim0sv);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_capsv_offset: {
            spdlog::debug("STM: accessing STM.STM0_CAPSV in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_capsv);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_ocs_offset: {
            spdlog::debug("STM: accessing STM.STM0_OCS in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_ocs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_krstclr_offset: {
            spdlog::debug("STM: accessing STM.STM0_KRSTCLR in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_krstclr);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_krst1_offset: {
            spdlog::debug("STM: accessing STM.STM0_KRST1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_krst1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_krst0_offset: {
            spdlog::debug("STM: accessing STM.STM0_KRST0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_krst0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_accen1_offset: {
            spdlog::debug("STM: accessing STM.STM0_ACCEN1 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_accen1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_stm0_accen0_offset: {
            spdlog::debug("STM: accessing STM.STM0_ACCEN0 in read mode");
            const auto *range_start = reinterpret_cast<std::byte *>(&m_stm0_accen0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Stm peripheral", address)};
        break;
    }
}

void Tricore::Stm::write(const std::byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - stm_memory_start_address;
    switch (offset) {
    case reg_stm0_clc_offset: {
        spdlog::debug("STM: accessing STM.STM0_CLC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_clc));
    } break;
    case reg_stm0_id_offset: {
        spdlog::debug("STM: accessing STM.STM0_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_id));
    } break;
    case reg_stm0_tim0_offset: {
        spdlog::debug("STM: accessing STM.STM0_TIM0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_tim0));
    } break;
    case reg_stm0_tim1_offset: {
        spdlog::debug("STM: accessing STM.STM0_TIM1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_tim1));
    } break;
    case reg_stm0_tim2_offset: {
        spdlog::debug("STM: accessing STM.STM0_TIM2 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_tim2));
    } break;
    case reg_stm0_tim3_offset: {
        spdlog::debug("STM: accessing STM.STM0_TIM3 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_tim3));
    } break;
    case reg_stm0_tim4_offset: {
        spdlog::debug("STM: accessing STM.STM0_TIM4 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_tim4));
    } break;
    case reg_stm0_tim5_offset: {
        spdlog::debug("STM: accessing STM.STM0_TIM5 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_tim5));
    } break;
    case reg_stm0_tim6_offset: {
        spdlog::debug("STM: accessing STM.STM0_TIM6 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_tim6));
    } break;
    case reg_stm0_cap_offset: {
        spdlog::debug("STM: accessing STM.STM0_CAP in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_cap));
    } break;
    case reg_stm0_cmcon_offset: {
        spdlog::debug("STM: accessing STM.STM0_CMCON in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_cmcon));
    } break;
    case reg_stm0_icr_offset: {
        spdlog::debug("STM: accessing STM.STM0_ICR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_icr));
    } break;
    case reg_stm0_iscr_offset: {
        spdlog::debug("STM: accessing STM.STM0_ISCR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_iscr));
    } break;
    case reg_stm0_tim0sv_offset: {
        spdlog::debug("STM: accessing STM.STM0_TIM0SV in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_tim0sv));
    } break;
    case reg_stm0_capsv_offset: {
        spdlog::debug("STM: accessing STM.STM0_CAPSV in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_capsv));
    } break;
    case reg_stm0_ocs_offset: {
        spdlog::debug("STM: accessing STM.STM0_OCS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_ocs));
    } break;
    case reg_stm0_krstclr_offset: {
        spdlog::debug("STM: accessing STM.STM0_KRSTCLR in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_krstclr));
    } break;
    case reg_stm0_krst1_offset: {
        spdlog::debug("STM: accessing STM.STM0_KRST1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_krst1));
    } break;
    case reg_stm0_krst0_offset: {
        spdlog::debug("STM: accessing STM.STM0_KRST0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_krst0));
    } break;
    case reg_stm0_accen1_offset: {
        spdlog::debug("STM: accessing STM.STM0_ACCEN1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_accen1));
    } break;
    case reg_stm0_accen0_offset: {
        spdlog::debug("STM: accessing STM.STM0_ACCEN0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<std::byte *>(&m_stm0_accen0));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Stm peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
