#ifndef TRICORE_EMU_UTILS_HPP
#define TRICORE_EMU_UTILS_HPP

#include "Types.hpp"

#include <gsl/assert>

#include <concepts>

namespace Tricore::Utils {

template <std::unsigned_integral U>
static constexpr U unsigned_abs_diff(U lhs, U rhs) {
    if (lhs > rhs) {
        return lhs - rhs;
    }

    return rhs - lhs;
}

template <std::signed_integral T, usize B>
static constexpr inline T sign_extend(const T input) {
    constexpr auto number_of_bits = sizeof(T) * 8;
    static_assert(B <= number_of_bits);
    constexpr auto remaining_bits = number_of_bits - B;
    return (input << remaining_bits) >> remaining_bits;
}

static inline u32 extract32(u32 data, u32 offset, u32 length) {
    constexpr u32 num_of_bits = 32;
    Expects(offset < num_of_bits && length <= num_of_bits - offset);
    return (data >> offset) & ((~0U) >> (num_of_bits - length));
}

static inline u16 extract16(u16 data, u32 offset, u32 length) {
    constexpr u32 num_of_bits = 16;
    Expects(offset < num_of_bits && length <= num_of_bits - offset);
    return static_cast<u16>(extract32(data, offset, length));
}

template <std::unsigned_integral T>
static constexpr inline T deposit(T value, T offset, T length, T data) {
    constexpr T num_of_bits = sizeof(T) * 8;
    Expects(offset < num_of_bits && length <= num_of_bits - offset);
    T mask = (~0U >> (32 - length)) << offset;
    return (data & ~mask) | ((value << offset) & mask);

}

} // namespace Tricore::Utils

#endif // ifndef TRICORE_EMU_UTILS_HPP