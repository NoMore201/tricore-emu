
#include "Memory.hpp"
#include "Utils.hpp"

#include <gsl/assert>

#include <algorithm>
#include <stdexcept>

Tricore::Memory::Memory(Layout layout, std::initializer_list<u32> aliases)
    : m_address(layout.address), m_data(layout.size, std::byte{0}),
      m_aliases(aliases) {}

std::optional<u32> Tricore::Memory::convert_address_to_offset(u32 address) const {
    if (address >= m_address && address < m_address + m_data.size()) {
        return Utils::unsigned_abs_diff(address, m_address);
    }
    for (const u32 address_alias : m_aliases) {
        if (address >= address_alias &&
            address < address_alias + m_data.size()) {
            return Utils::unsigned_abs_diff(address_alias, address);
        }
    }
    return {};
}

bool Tricore::Memory::is_address_valid(u32 address) const {
    return convert_address_to_offset(address).has_value();
}

std::optional<Tricore::Memory::Error>
Tricore::Memory::read(std::byte *buffer_out, u32 address, usize length) const {
    Ensures(buffer_out != nullptr);
    const auto offset = convert_address_to_offset(address);
    if (offset) {
        const auto *range_start = m_data.data() + offset.value();
        std::ranges::copy(range_start, range_start + length, buffer_out);
        return {};
    }
    return Error::InvalidAddress;
}

std::optional<Tricore::Memory::Error>
Tricore::Memory::write(const std::byte *buffer_in, u32 address, usize length) {
    Ensures(buffer_in != nullptr);
    const auto offset = convert_address_to_offset(address);
    if (offset) {
        auto *range_start = m_data.data() + offset.value();
        std::ranges::copy(buffer_in, buffer_in + length, range_start);
        return {};
    }
    return Error::InvalidAddress;
}
