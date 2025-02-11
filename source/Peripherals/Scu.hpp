#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Scu : public BusClient {

public:

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_rststat{0x40010000U};
    u32 m_lbistctrl0{0x10000000U};

};

} // namespace Tricore