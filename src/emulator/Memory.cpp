#include "Memory.hpp"

#include <algorithm>

#include <fmt/format.h>
#include <gsl/assert>

u32 Tricore::MemoryRegion::get_offset_into_buffer(u32 address)
{
    if (address >= m_start_address && address < m_start_address + static_cast<u32>(m_buffer.size())) {
        return address - m_start_address;
    }
    if (m_mirror_start_address && address >= m_mirror_start_address.value()
        && address < m_mirror_start_address.value() + static_cast<u32>(m_buffer.size())) {
        return address - m_mirror_start_address.value();
    }
    throw InvalidMemoryAccess {"Address not in range"};
}

void Tricore::MemoryRegion::read(Span<byte> buffer_out, u32 address)
{
    const auto offset_into_buffer = get_offset_into_buffer(address);
    const auto* range_start = m_buffer.data() + offset_into_buffer;
    std::ranges::copy(range_start, range_start + buffer_out.size(),
        buffer_out.begin());
}

void Tricore::MemoryRegion::write(Span<const byte> buffer_in, u32 address)
{

    const auto offset_into_buffer = get_offset_into_buffer(address);
    auto* range_start = m_buffer.data() + offset_into_buffer;
    std::ranges::copy(buffer_in.begin(), buffer_in.end(), range_start);
}

Tricore::MemoryRegion::MemoryRegion(u32 start_address, usize size, std::optional<u32> mirror_address)
    : m_start_address(start_address)
    , m_mirror_start_address(mirror_address)
    , m_buffer(size, 0)
{
}
