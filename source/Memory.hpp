#ifndef TRICORE_EMU_MEMORY_HPP
#define TRICORE_EMU_MEMORY_HPP

#include "Types.hpp"

#include <optional>
#include <stdexcept>
#include <vector>

namespace Tricore {

struct InvalidMemoryAccess : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class Memory {

public:
    struct Layout {
        usize size;
        u32 address;
    };

    Memory();

    void read(std::byte *buffer_out, u32 address, usize length);

    void write(const std::byte *buffer_in, u32 address, usize length);

    void add_memory_region(Layout layout,
                           std::optional<u32> mirror_address = {});

    std::byte peek_at(u32 address);

private:
    struct MemBuffer {
        u32 start_address;
        std::optional<u32> mirror_start_address;
        std::vector<std::byte> buffer;

        u32 offset_into_buffer(u32 address);
    };

    MemBuffer &get_corresponding_buffer(u32 address);

    std::vector<MemBuffer> m_data;
};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_MEMORY_HPP