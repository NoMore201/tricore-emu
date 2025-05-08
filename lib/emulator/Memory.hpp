#ifndef TRICORE_EMU_MEMORY_HPP
#define TRICORE_EMU_MEMORY_HPP

#include "BusClient.hpp"
#include "Tricore.hpp"
#include "Types.hpp"

#include <gsl/span>
#include <optional>
#include <vector>

namespace Tricore {

class Memory : public BusClient {

public:
    struct Layout {
        usize size;
        u32 address;
    };

    explicit Memory(CpuVariant variant);

    void read(gsl::span<byte> buffer_out, u32 address) override;

    void write(gsl::span<const byte> buffer_in, u32 address) override;

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
