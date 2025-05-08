
/**
 * @brief Module source for Int peripheral
 *
 * Automatically generated from regdump.py script and Infineon iLLD
 * iLLD_1_0_1_15_0__TC33A source code
 */

#include "Peripherals/Int.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

constexpr u32 int_id_reset_value = 0; // TODO: change according manual
constexpr u32 int_oobs_reset_value = 0; // TODO: change according manual
constexpr u32 int_ossic_reset_value = 0; // TODO: change according manual
constexpr u32 int_oixts_reset_value = 0; // TODO: change according manual
constexpr u32 int_oixms_reset_value = 0; // TODO: change according manual
constexpr u32 int_oixs0_reset_value = 0; // TODO: change according manual
constexpr u32 int_oixs1_reset_value = 0; // TODO: change according manual
constexpr u32 int_oit_reset_value = 0; // TODO: change according manual
constexpr u32 int_omisp_reset_value = 0; // TODO: change according manual
constexpr u32 int_omisn_reset_value = 0; // TODO: change according manual
constexpr u32 int_accen_config0_reset_value = 0; // TODO: change according manual
constexpr u32 int_accen_config1_reset_value = 0; // TODO: change according manual

constexpr u32 int_memory_start_address = 0xf0037000U;
constexpr u32 int_memory_size = 0; // TODO: update according manual;
constexpr u32 int_memory_end_address = int_memory_start_address + int_memory_size;

constexpr u32 reg_int_id_address = 0xf0037008;
constexpr u32 reg_int_id_offset = reg_int_id_address - int_memory_start_address;
constexpr u32 reg_int_oobs_address = 0xf0037080;
constexpr u32 reg_int_oobs_offset = reg_int_oobs_address - int_memory_start_address;
constexpr u32 reg_int_ossic_address = 0xf0037084;
constexpr u32 reg_int_ossic_offset = reg_int_ossic_address - int_memory_start_address;
constexpr u32 reg_int_oixts_address = 0xf0037088;
constexpr u32 reg_int_oixts_offset = reg_int_oixts_address - int_memory_start_address;
constexpr u32 reg_int_oixms_address = 0xf003708c;
constexpr u32 reg_int_oixms_offset = reg_int_oixms_address - int_memory_start_address;
constexpr u32 reg_int_oixs0_address = 0xf0037090;
constexpr u32 reg_int_oixs0_offset = reg_int_oixs0_address - int_memory_start_address;
constexpr u32 reg_int_oixs1_address = 0xf0037094;
constexpr u32 reg_int_oixs1_offset = reg_int_oixs1_address - int_memory_start_address;
constexpr u32 reg_int_oit_address = 0xf00370a0;
constexpr u32 reg_int_oit_offset = reg_int_oit_address - int_memory_start_address;
constexpr u32 reg_int_omisp_address = 0xf00370a4;
constexpr u32 reg_int_omisp_offset = reg_int_omisp_address - int_memory_start_address;
constexpr u32 reg_int_omisn_address = 0xf00370a8;
constexpr u32 reg_int_omisn_offset = reg_int_omisn_address - int_memory_start_address;
constexpr u32 reg_int_accen_config0_address = 0xf00370f0;
constexpr u32 reg_int_accen_config0_offset = reg_int_accen_config0_address - int_memory_start_address;
constexpr u32 reg_int_accen_config1_address = 0xf00370f4;
constexpr u32 reg_int_accen_config1_offset = reg_int_accen_config1_address - int_memory_start_address;

} // anonymous namespace


Tricore::Int::Int()
    : m_int_id(int_id_reset_value)
    , m_int_oobs(int_oobs_reset_value)
    , m_int_ossic(int_ossic_reset_value)
    , m_int_oixts(int_oixts_reset_value)
    , m_int_oixms(int_oixms_reset_value)
    , m_int_oixs0(int_oixs0_reset_value)
    , m_int_oixs1(int_oixs1_reset_value)
    , m_int_oit(int_oit_reset_value)
    , m_int_omisp(int_omisp_reset_value)
    , m_int_omisn(int_omisn_reset_value)
    , m_int_accen_config0(int_accen_config0_reset_value)
    , m_int_accen_config1(int_accen_config1_reset_value)
{}

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)

void Tricore::Int::read(byte *buffer_out, u32 address, usize length) {
    const u32 offset = address - int_memory_start_address;
    switch (offset) {
    case reg_int_id_offset: {
            spdlog::debug("INT: accessing INT.INT_ID in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_int_id);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_int_oobs_offset: {
            spdlog::debug("INT: accessing INT.INT_OOBS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_int_oobs);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_int_ossic_offset: {
            spdlog::debug("INT: accessing INT.INT_OSSIC in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_int_ossic);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_int_oixts_offset: {
            spdlog::debug("INT: accessing INT.INT_OIXTS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_int_oixts);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_int_oixms_offset: {
            spdlog::debug("INT: accessing INT.INT_OIXMS in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_int_oixms);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_int_oixs0_offset: {
            spdlog::debug("INT: accessing INT.INT_OIXS0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_int_oixs0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_int_oixs1_offset: {
            spdlog::debug("INT: accessing INT.INT_OIXS1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_int_oixs1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_int_oit_offset: {
            spdlog::debug("INT: accessing INT.INT_OIT in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_int_oit);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_int_omisp_offset: {
            spdlog::debug("INT: accessing INT.INT_OMISP in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_int_omisp);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_int_omisn_offset: {
            spdlog::debug("INT: accessing INT.INT_OMISN in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_int_omisn);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_int_accen_config0_offset: {
            spdlog::debug("INT: accessing INT.INT_ACCEN_CONFIG0 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_int_accen_config0);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    case reg_int_accen_config1_offset: {
            spdlog::debug("INT: accessing INT.INT_ACCEN_CONFIG1 in read mode");
            const auto *range_start = reinterpret_cast<byte *>(&m_int_accen_config1);
            std::ranges::copy(range_start, range_start + length, buffer_out);
        } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Int peripheral", address)};
        break;
    }
}

void Tricore::Int::write(const byte *buffer_in, u32 address,
                         usize length) {
    const u32 offset = address - int_memory_start_address;
    switch (offset) {
    case reg_int_id_offset: {
        spdlog::debug("INT: accessing INT.INT_ID in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_int_id));
    } break;
    case reg_int_oobs_offset: {
        spdlog::debug("INT: accessing INT.INT_OOBS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_int_oobs));
    } break;
    case reg_int_ossic_offset: {
        spdlog::debug("INT: accessing INT.INT_OSSIC in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_int_ossic));
    } break;
    case reg_int_oixts_offset: {
        spdlog::debug("INT: accessing INT.INT_OIXTS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_int_oixts));
    } break;
    case reg_int_oixms_offset: {
        spdlog::debug("INT: accessing INT.INT_OIXMS in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_int_oixms));
    } break;
    case reg_int_oixs0_offset: {
        spdlog::debug("INT: accessing INT.INT_OIXS0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_int_oixs0));
    } break;
    case reg_int_oixs1_offset: {
        spdlog::debug("INT: accessing INT.INT_OIXS1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_int_oixs1));
    } break;
    case reg_int_oit_offset: {
        spdlog::debug("INT: accessing INT.INT_OIT in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_int_oit));
    } break;
    case reg_int_omisp_offset: {
        spdlog::debug("INT: accessing INT.INT_OMISP in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_int_omisp));
    } break;
    case reg_int_omisn_offset: {
        spdlog::debug("INT: accessing INT.INT_OMISN in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_int_omisn));
    } break;
    case reg_int_accen_config0_offset: {
        spdlog::debug("INT: accessing INT.INT_ACCEN_CONFIG0 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_int_accen_config0));
    } break;
    case reg_int_accen_config1_offset: {
        spdlog::debug("INT: accessing INT.INT_ACCEN_CONFIG1 in write mode");
        std::ranges::copy(buffer_in, buffer_in + length,
                          reinterpret_cast<byte *>(&m_int_accen_config1));
    } break;
    default:
        throw InvalidMemoryAccess{fmt::format(
            "Address 0x{:08X} not handled by Int peripheral", address)};
        break;
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast, cppcoreguidelines-pro-bounds-pointer-arithmetic)
