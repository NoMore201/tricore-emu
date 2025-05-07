
#include "Memory.hpp"
#include "Types.hpp"
#include "Utils.hpp"

#include <fmt/format.h>
#include <gsl/assert>

#include <algorithm>

u32 Tricore::Memory::MemBuffer::offset_into_buffer(u32 address) {
    if (address >= start_address &&
        address < start_address + static_cast<u32>(buffer.size())) {
        return Utils::unsigned_abs_diff(address, start_address);
    }
    if (mirror_start_address && address >= mirror_start_address.value() &&
        address <
            mirror_start_address.value() + static_cast<u32>(buffer.size())) {
        return Utils::unsigned_abs_diff(address, mirror_start_address.value());
    }
    throw InvalidMemoryAccess{"Address not in range"};
}

Tricore::Memory::Memory() = default;

void Tricore::Memory::read(std::byte *buffer_out, u32 address, usize length) {
    auto &memory = get_corresponding_buffer(address);
    const auto offset_into_buffer = memory.offset_into_buffer(address);
    const auto *range_start = memory.buffer.data() + offset_into_buffer;
    std::ranges::copy(range_start, range_start + length, buffer_out);
}

void Tricore::Memory::write(const std::byte *buffer_in, u32 address,
                            usize length) {

    auto &memory = get_corresponding_buffer(address);
    const auto offset_into_buffer = memory.offset_into_buffer(address);
    auto *range_start = memory.buffer.data() + offset_into_buffer;
    std::ranges::copy(buffer_in, buffer_in + length, range_start);
}

void Tricore::Memory::add_memory_region(Layout layout,
                                        std::optional<u32> mirror_address) {
    m_data.emplace_back(layout.address, mirror_address,
                        std::vector<std::byte>{layout.size, std::byte{0}});
}

std::byte Tricore::Memory::peek_at(u32 address) {
    auto &memory = get_corresponding_buffer(address);
    const auto offset = memory.offset_into_buffer(address);
    return memory.buffer.at(offset);
}

Tricore::Memory::MemBuffer &
Tricore::Memory::get_corresponding_buffer(u32 address) {
    for (auto &memory : m_data) {
        try {
            memory.offset_into_buffer(address);
            return memory;
        } catch (InvalidMemoryAccess &) {
        }
    }
    throw InvalidMemoryAccess{
        fmt::format("Address 0x{:08X} not mapped in memory layout", address)};
}
