#ifndef TRICORE_EMU_ERROR_HPP
#define TRICORE_EMU_ERROR_HPP

#include <stdexcept>

namespace Tricore {

struct Exception : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct InvalidMemoryAccess : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_ERROR_HPP
