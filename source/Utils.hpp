#ifndef TRICORE_EMU_UTILS_HPP
#define TRICORE_EMU_UTILS_HPP

#include "Types.hpp"

#include <gsl/assert>

#include <concepts>

namespace Tricore::Utils {

template <std::unsigned_integral U>
static constexpr auto unsigned_abs_diff(U lhs, U rhs) {
    if (lhs > rhs) {
        return lhs - rhs;
    }

    return rhs - lhs;
}

template <std::signed_integral T, usize B>
static constexpr inline T sign_extend(const T input) {
    static_assert(B <= 64);
    struct {
        T x : B;
    } to_extend = {.x = input};
    return to_extend.x;
}

template <std::unsigned_integral T>
static constexpr inline T extract(T data, T offset, T length) {
    constexpr T num_of_bits = sizeof(T) * 8;
    Expects(offset < num_of_bits && length <= num_of_bits - offset);
    return (data >> offset) & (static_cast<T>(~0U) >> (num_of_bits - length));
}

} // namespace Tricore::Utils

#endif // ifndef TRICORE_EMU_UTILS_HPP