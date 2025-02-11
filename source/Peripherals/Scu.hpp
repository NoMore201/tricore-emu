#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class Scu : public BusClient {

public:

    Scu();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

    u32 m_rststat;
    u32 m_lbistctrl0;
    u32 m_wdts_con0;

};

} // namespace Tricore