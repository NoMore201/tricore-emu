#ifndef TRICORE_EMU_BUS_HPP
#define TRICORE_EMU_BUS_HPP

#include "BusClient.hpp"
#include "Types.hpp"

#include <gsl/pointers>

#include <mutex>
#include <vector>

namespace Tricore {

class Bus : public BusClient {

public:
    class BusRegistrationHandler {
        friend class Bus;

    public:
        BusRegistrationHandler(Bus& parent, BusClient& device)
            : m_parent(&parent)
            , m_device(&device)
        {
        }

        BusRegistrationHandler(const BusRegistrationHandler&) = delete;
        BusRegistrationHandler& operator=(const BusRegistrationHandler&) = delete;

        BusRegistrationHandler(BusRegistrationHandler&&) = default;
        BusRegistrationHandler& operator=(BusRegistrationHandler&&) = default;

        ~BusRegistrationHandler()
        {
            std::lock_guard<std::mutex> lock { m_parent->m_mutex };
            std::erase(m_parent->m_bus_clients, m_device);
        }

    private:
        gsl::not_null<Bus*> m_parent;
        gsl::not_null<BusClient*> m_device;
    };

    Bus();

    BusRegistrationHandler register_device(BusClient& client)
    {
        std::lock_guard<std::mutex> lock { m_mutex };
        m_bus_clients.push_back(&client);
        return BusRegistrationHandler { *this, client };
    }

    void read(gsl::span<byte> buffer_out, u32 address) override;

    void write(gsl::span<const byte> buffer_in, u32 address) override;

private:
    std::vector<BusClient*> m_bus_clients;
    std::mutex m_mutex;
};

} // namespace Tricore

#endif
