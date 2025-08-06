#include "Memory.hpp"
#include "Error.hpp"
#include "Tricore.hpp"
#include "Types.hpp"
#include "Utils.hpp"

#include <fmt/format.h>
#include <gsl/assert>

#include <algorithm>

u32 Tricore::Memory::MemBuffer::offset_into_buffer(u32 address)
{
    if (address >= start_address && address < start_address + static_cast<u32>(buffer.size())) {
        return Utils::unsigned_abs_diff(address, start_address);
    }
    if (mirror_start_address && address >= mirror_start_address.value() && address < mirror_start_address.value() + static_cast<u32>(buffer.size())) {
        return Utils::unsigned_abs_diff(address, mirror_start_address.value());
    }
    throw InvalidMemoryAccess { "Address not in range" };
}

void Tricore::Memory::read(gsl::span<byte> buffer_out, u32 address)
{
    auto& memory = get_corresponding_buffer(address);
    const auto offset_into_buffer = memory.offset_into_buffer(address);
    const auto* range_start = memory.buffer.data() + offset_into_buffer;
    std::ranges::copy(range_start, range_start + buffer_out.size(),
        buffer_out.begin());
}

void Tricore::Memory::write(gsl::span<const byte> buffer_in, u32 address)
{

    auto& memory = get_corresponding_buffer(address);
    const auto offset_into_buffer = memory.offset_into_buffer(address);
    auto* range_start = memory.buffer.data() + offset_into_buffer;
    std::ranges::copy(buffer_in.begin(), buffer_in.end(), range_start);
}

u8 Tricore::Memory::read8(u32 address)
{
    u8 result {};
    auto buffer = Utils::to_span(&result, 1);
    read(buffer, address);
    return result;
}

u16 Tricore::Memory::read16(u32 address)
{
    u16 result {};
    auto buffer = Utils::to_span(&result, 2);
    read(buffer, address);
    return result;
}

u32 Tricore::Memory::read32(u32 address)
{
    u32 result {};
    auto buffer = Utils::to_span(&result, 4);
    read(buffer, address);
    return result;
}

void Tricore::Memory::write8(u8 value, u32 address)
{
    auto buffer = Utils::to_span(&value, 1);
    write(buffer, address);
}

void Tricore::Memory::write16(u16 value, u32 address)
{
    auto buffer = Utils::to_span(&value, 2);
    write(buffer, address);
}

void Tricore::Memory::write32(u32 value, u32 address)
{
    auto buffer = Utils::to_span(&value, 4);
    write(buffer, address);
}

Tricore::Memory::Memory(Tricore::CpuVariant variant)
{

    switch (variant) {
    case Tricore::CpuVariant::TC33X: {
        // pflash0
        m_data.push_back(MemBuffer {
            0xA0000000U, { 0x80000000U }, std::vector<byte>(2ULL * MiB, byte {}) });
        // dflash0
        m_data.push_back(MemBuffer { 0xAF000000U, std::nullopt,
            std::vector(128ULL * KiB, byte {}) });
        // dsram0
        m_data.push_back(MemBuffer {
            0x70000000U, { 0xD0000000U }, std::vector(192ULL * KiB, byte {}) });
        // psram0
        m_data.push_back(
            MemBuffer { 0x70100000U, { 0xC0000000U }, std::vector(8ULL * KiB, byte {}) });
        // ucb
        m_data.push_back(
            MemBuffer { 0xAF400000U, std::nullopt, std::vector(24ULL * KiB, byte {}) });
        // xram
        m_data.push_back(
            MemBuffer { 0xF0240000U, std::nullopt, std::vector(8ULL * KiB, byte {}) });
    } break;
    }
}

Tricore::Memory::MemBuffer&
Tricore::Memory::get_corresponding_buffer(u32 address)
{
    for (auto& memory : m_data) {
        try {
            memory.offset_into_buffer(address);
            return memory;
        } catch (InvalidMemoryAccess&) {
        }
    }
    throw InvalidMemoryAccess {
        fmt::format("Address 0x{:08X} not mapped in memory layout", address)
    };
}
