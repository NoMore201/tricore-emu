#include "Bus.hpp"
#include "Error.hpp"
#include "BusOps.hpp"

#include <fmt/format.h>
#include <mutex>

Tricore::Bus::Bus() = default;

void Tricore::Bus::register_device(BusOps& client)
{
    std::lock_guard<std::mutex> lock { m_mutex };
    m_bus_clients.push_back(&client);
}

void Tricore::Bus::read(Span<byte> buffer_out, u32 address)
{
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        for (auto* client : m_bus_clients) {
            try {
                client->read(buffer_out, address);
                return;
            } catch (InvalidMemoryAccess&) {
                continue;
            }
        }
    }

    throw InvalidMemoryAccess { fmt::format("Address 0x{:08X} is not registered on the bus", address) };
}

void Tricore::Bus::write(Span<const byte> buffer_in, u32 address)
{
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        for (auto* client : m_bus_clients) {
            try {
                client->write(buffer_in, address);
                return;
            } catch (InvalidMemoryAccess&) {
                continue;
            }
        }
    }

    throw InvalidMemoryAccess { fmt::format("Address 0x{:08X} is not registered on the bus", address) };
}
