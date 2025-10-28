#ifndef TRICORE_EMU_BUS_HPP
#define TRICORE_EMU_BUS_HPP

#include "BusOps.hpp"
#include "Span.hpp"
#include "Types.hpp"

#include <gsl/pointers>

#include <mutex>
#include <vector>

namespace Tricore {

class Bus : public BusOps {

public:
    Bus();

    void read(Span<byte> buffer_out, u32 address) override;

    void write(Span<const byte> buffer_in, u32 address) override;

    void register_device(BusOps& client);

private:
    std::vector<BusOps*> m_bus_clients;
    std::mutex m_mutex;
};

} // namespace Tricore

#endif
