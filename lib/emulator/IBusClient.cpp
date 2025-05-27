#include "IBusClient.hpp"

#include "Utils.hpp"

u8 Tricore::IBusClient::read8(u32 address)
{
    u8 result {};
    auto buffer = Utils::to_span(&result, 1);
    read(buffer, address);
    return result;
}

u16 Tricore::IBusClient::read16(u32 address)
{
    u16 result {};
    auto buffer = Utils::to_span(&result, 2);
    read(buffer, address);
    return result;
}

u32 Tricore::IBusClient::read32(u32 address)
{
    u32 result {};
    auto buffer = Utils::to_span(&result, 4);
    read(buffer, address);
    return result;
}

void Tricore::IBusClient::write8(u8 value, u32 address)
{
    auto buffer = Utils::to_span(&value, 1);
    write(buffer, address);
}

void Tricore::IBusClient::write16(u16 value, u32 address)
{
    auto buffer = Utils::to_span(&value, 2);
    write(buffer, address);
}

void Tricore::IBusClient::write32(u32 value, u32 address)
{
    auto buffer = Utils::to_span(&value, 4);
    write(buffer, address);
}
