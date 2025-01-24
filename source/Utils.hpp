#ifndef TRICORE_EMU_UTILS_HPP
#define TRICORE_EMU_UTILS_HPP

#include "Types.hpp"

#include <gsl/assert>

#include <concepts>

namespace Tricore::Utils {

template <std::unsigned_integral U> auto unsigned_abs_diff(U lhs, U rhs) {
    if (lhs > rhs) {
        return lhs - rhs;
    }

    return rhs - lhs;
}

static inline u32 extract32(u32 data, u32 offset, u32 length) {
    Expects(offset < 32U && length <= 32U - offset);
    return (data >> offset) & (~0U >> (32U - length));
}

} // namespace Tricore::Utils

#endif // ifndef TRICORE_EMU_UTILS_HPP