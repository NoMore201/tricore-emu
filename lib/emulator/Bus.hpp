
#ifndef TRICORE_EMU_BUS_HPP
#define TRICORE_EMU_BUS_HPP

#include "BusClient.hpp"
#include "Types.hpp"
#include <vector>

namespace Tricore {

class Bus : public BusClient {

public:
    Bus();

    void register_device(BusClient& client)
    {
        m_bus_clients.push_back(&client);
    }

    void read(gsl::span<byte> buffer_out, u32 address) override;

    void write(gsl::span<const byte> buffer_in, u32 address) override;

private:
    std::vector<BusClient*> m_bus_clients;
};

} // namespace Tricore

#endif
