#ifndef TRICORE_EMU_UTILS_HPP
#define TRICORE_EMU_UTILS_HPP

#include <concepts>

namespace Tricore::Utils {

template <std::unsigned_integral U> auto unsigned_abs_diff(U lhs, U rhs) {
    if (lhs > rhs) {
        return lhs - rhs;
    }

    return rhs - lhs;
}

} // namespace Tricore::Utils

#endif // ifndef TRICORE_EMU_UTILS_HPP