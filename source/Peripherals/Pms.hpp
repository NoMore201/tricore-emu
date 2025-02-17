#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Pms : public BusClient {

public:

    Pms();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_cmd_stdby;
    u32 m_monbistctrl;
    u32 m_monfilt;

};

} // namespace Tricore