#ifndef TRICORE_EMU_BUS_HPP
#define TRICORE_EMU_BUS_HPP

#include "IBusClient.hpp"
#include "Types.hpp"

#include <gsl/pointers>

#include <mutex>
#include <vector>

namespace Tricore {

class Bus {

public:
    Bus();

    class RequestHandler : public IBusClient {

    public:
        void read(gsl::span<byte> buffer_out, u32 address) override;

        void write(gsl::span<const byte> buffer_in, u32 address) override;

    private:
        friend class Bus;

        explicit RequestHandler(Bus& parent)
            : m_bus(&parent)
        {
        }

        gsl::not_null<Bus*> m_bus;
    };

    void register_device(IBusClient& client);

    RequestHandler create_request_handler()
    {
        return RequestHandler(*this);
    }

private:
    std::vector<IBusClient*> m_bus_clients;
    std::mutex m_mutex;
};

} // namespace Tricore

#endif
