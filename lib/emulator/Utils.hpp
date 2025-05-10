#ifndef TRICORE_EMU_UTILS_HPP
#define TRICORE_EMU_UTILS_HPP

#include "Types.hpp"

#include <gsl/assert>
#include <gsl/narrow>
#include <gsl/span>
#include <gsl/span_ext>

#include <concepts>

namespace Tricore::Utils {

// Integer utils

template<std::unsigned_integral U>
static constexpr U unsigned_abs_diff(U lhs, U rhs)
{
    if (lhs > rhs) {
        return lhs - rhs;
    }

    return rhs - lhs;
}

template<usize B>
static inline u32 sign_extend32(const u32 input)
{
    static_assert(B != 0 && B < 32);
    // clear uppermost bits
    u32 cleared_input = input & ((1U << B) - 1U);
    u32 sign_bit_mask = (1U << (B - 1U));
    return (cleared_input ^ sign_bit_mask) - sign_bit_mask;
}

static inline u32 extract32(u32 data, u32 offset, u32 length)
{
    constexpr u32 num_of_bits = 32;
    Expects(offset < num_of_bits && length <= num_of_bits - offset);
    return (data >> offset) & ((~0U) >> (num_of_bits - length));
}

static inline u16 extract16(u16 data, u32 offset, u32 length)
{
    constexpr u32 num_of_bits = 16;
    Expects(offset < num_of_bits && length <= num_of_bits - offset);
    return static_cast<u16>(extract32(data, offset, length));
}

static inline u32 deposit32(u32 field, u32 offset, u32 length,
    u32 destination)
{
    constexpr u32 num_of_bits = 32;
    Expects(offset < num_of_bits && length <= num_of_bits - offset);
    u32 mask = (~0U >> (num_of_bits - length)) << offset;
    return (destination & ~mask) | ((field << offset) & mask);
}

// Span helpers

static inline gsl::span<byte> to_span(auto* const buffer, usize length)
{
    return gsl::make_span(reinterpret_cast<byte*>(buffer), length);
}

static inline gsl::span<const byte> to_span(const auto* const buffer, usize length)
{
    return gsl::make_span(reinterpret_cast<const byte*>(buffer), length);
}

} // namespace Tricore::Utils

#endif // ifndef TRICORE_EMU_UTILS_HPP
