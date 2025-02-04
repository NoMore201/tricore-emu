#pragma once

#include "Types.hpp"

#include <stdexcept>

namespace Tricore {

struct InvalidMemoryAccess : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class BusClient {

public:

    virtual ~BusClient() = default;

    virtual void read(std::byte *buffer_out, u32 address, usize length) = 0;

    virtual void write(const std::byte *buffer_in, u32 address, usize length) = 0;

};

} // namespace Tricore