#ifndef TRICORE_EMU_MEMORY_HPP
#define TRICORE_EMU_MEMORY_HPP

#include "Tricore.hpp"
#include "Types.hpp"

#include <gsl/span>
#include <optional>
#include <vector>

namespace Tricore {

class Memory {

public:
    explicit Memory(CpuVariant variant);

    void read(gsl::span<byte> buffer_out, u32 address);

    void write(gsl::span<const byte> buffer_in, u32 address);

    u8 read8(u32 address);
    u16 read16(u32 address);
    u32 read32(u32 address);

    void write8(u8 value, u32 address);
    void write16(u16 value, u32 address);
    void write32(u32 value, u32 address);

private:
    struct MemBuffer {
        u32 start_address;
        std::optional<u32> mirror_start_address;
        std::vector<byte> buffer;

        u32 offset_into_buffer(u32 address);
    };

    MemBuffer& get_corresponding_buffer(u32 address);

    std::vector<MemBuffer> m_data;
};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_MEMORY_HPP
