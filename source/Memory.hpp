#ifndef TRICORE_EMU_MEMORY_HPP
#define TRICORE_EMU_MEMORY_HPP

#include "Types.hpp"

#include <initializer_list>
#include <optional>
#include <vector>

namespace Tricore {

class Memory {

public:
    struct Layout {
        usize size;
        u32 address;
    };

    enum class Error : u8 { InvalidAddress };

    explicit Memory(Layout layout, std::initializer_list<u32> aliases = {});

    std::optional<Error> read(std::byte *buffer_out, u32 address, usize length) const;

    std::optional<Error> write(const std::byte *buffer_in, u32 address,
                               usize length);

    usize size() const noexcept { return m_data.size(); }

    u32 address() const noexcept { return m_address; }

    bool is_address_valid(u32 address) const;

private:
    std::optional<u32> convert_address_to_offset(u32 address) const;

    u32 m_address{};
    std::vector<std::byte> m_data;
    std::vector<u32> m_aliases;
};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_MEMORY_HPP