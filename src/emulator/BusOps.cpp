#include "BusOps.hpp"

#include <Span.hpp>

u8 Tricore::BusOps::read8(u32 address)
{
    u8 result {};
    auto buffer = Utils::to_byte_span(&result, 1);
    read(buffer, address);
    return result;
}

u16 Tricore::BusOps::read16(u32 address)
{
    u16 result {};
    auto buffer = Utils::to_byte_span(&result, 2);
    read(buffer, address);
    return result;
}

u32 Tricore::BusOps::read32(u32 address)
{
    u32 result {};
    auto buffer = Utils::to_byte_span(&result, 4);
    read(buffer, address);
    return result;
}

void Tricore::BusOps::write8(u8 value, u32 address)
{
    auto buffer = Utils::to_byte_span(&value, 1);
    write(buffer, address);
}

void Tricore::BusOps::write16(u16 value, u32 address)
{
    auto buffer = Utils::to_byte_span(&value, 2);
    write(buffer, address);
}

void Tricore::BusOps::write32(u32 value, u32 address)
{
    auto buffer = Utils::to_byte_span(&value, 4);
    write(buffer, address);
}
