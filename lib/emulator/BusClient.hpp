#ifndef TRICORE_EMU_BUSCLIENT_HPP
#define TRICORE_EMU_BUSCLIENT_HPP

#include "Types.hpp"

#include <gsl/span>

#include <stdexcept>

namespace Tricore {

struct InvalidMemoryAccess : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class BusClient {

public:
    virtual ~BusClient() = default;

    virtual void read(gsl::span<byte> buffer_out, u32 address) = 0;

    virtual void write(gsl::span<const byte> buffer_in, u32 address) = 0;

    virtual u8 read8(u32 address);
    virtual u16 read16(u32 address);
    virtual u32 read32(u32 address);

    virtual void write8(u8 value, u32 address);
    virtual void write16(u16 value, u32 address);
    virtual void write32(u32 value, u32 address);
};

} // namespace Tricore

#endif
