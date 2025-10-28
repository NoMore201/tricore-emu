#ifndef TRICORE_EMU_MEMORY_HPP
#define TRICORE_EMU_MEMORY_HPP

#include "BusOps.hpp"
#include "Span.hpp"
#include "Types.hpp"

#include <gsl/span>
#include <optional>
#include <vector>

namespace Tricore {

class MemoryRegion : public BusOps {

public:
    struct AddressRange {
        u32 start;
        u32 end;
    };

    explicit MemoryRegion(u32 start_address, usize size, std::optional<u32> mirror_address = std::nullopt);

    void read(Span<byte> buffer_out, u32 address) override;

    void write(Span<const byte> buffer_in, u32 address) override;

private:
    u32 get_offset_into_buffer(u32 address);

    u32 m_start_address;
    std::optional<u32> m_mirror_start_address;
    std::vector<byte> m_buffer;
};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_MEMORY_HPP
