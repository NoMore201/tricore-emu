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

class Offset32 {
    uint32_t m_offset;

public:
    template<std::integral I>
    constexpr explicit Offset32(I value)
    {
        auto narrowed = gsl::narrow<uint32_t>(value);
        if (value >= 32) {
            throw std::runtime_error { "32 bit offset out of range" };
        }
        m_offset = narrowed;
    }

    [[nodiscard]] constexpr uint32_t value() const noexcept
    {
        return m_offset;
    }
};

class RegValue {
    uint32_t m_value;

public:
    template<std::integral I>
    constexpr explicit RegValue(I value)
        : m_value(gsl::narrow<uint32_t>(value))
    {
    }

    constexpr uint32_t value() const noexcept { return m_value; }

    // Operators

    /// Add that it's allowed to wrap-around
    [[nodiscard]] constexpr RegValue wrapping_add(const RegValue& other) const
    {
        return RegValue { m_value + other.value() };
    }

    /// Add that it's allowed to wrap-around
    [[nodiscard]] constexpr RegValue safe_add(const RegValue& other) const
    {
        auto result = m_value + other.value();
        if (result < m_value) {
            throw std::runtime_error { "RegValue: safe_add wrap-around detected" };
        }
        return RegValue { result };
    }

    /// Sub that it's allowed to wrap-around
    [[nodiscard]] constexpr RegValue wrapping_sub(const RegValue& other) const
    {
        return RegValue { m_value - other.value() };
    }

    /// Sub that it's allowed to wrap-around
    [[nodiscard]] constexpr RegValue safe_sub(const RegValue& other) const
    {
        auto result = m_value - other.value();
        if (result > m_value) {
            throw std::runtime_error { "RegValue: safe_sub wrap-around detected" };
        }
        return RegValue { result };
    }

    /// Mul that it's allowed to wrap-around
    [[nodiscard]] constexpr RegValue wrapping_mul(const RegValue& other) const
    {
        return RegValue { m_value * other.value() };
    }

    /// Mul that it's allowed to wrap-around
    [[nodiscard]] constexpr RegValue safe_mul(const RegValue& other) const
    {
        auto result = m_value * other.value();
        if (result < m_value) {
            throw std::runtime_error { "RegValue: safe_sub wrap-around detected" };
        }
        return RegValue { result };
    }

    // Bit manipulation

    [[nodiscard]] constexpr RegValue extract32(Offset32 offset, std::size_t length) const
    {
        if (length > 32 - offset.value()) {
            throw std::runtime_error { "RegValue: extract parameters out of range" };
        }
        return RegValue { (m_value >> offset.value()) & ((~0U) >> (32 - length)) };
    }

    [[nodiscard]] constexpr RegValue deposit32(const RegValue& value, Offset32 offset, std::size_t length) const
    {
        if (length > 32 - offset.value()) {
            throw std::runtime_error { "RegValue: extract parameters out of range" };
        }
        uint32_t mask = (~0U >> (32 - length)) << offset.value();
        return RegValue { (m_value & ~mask) | ((value.value() << offset.value()) & mask) };
    }
};

consteval Offset32 operator""_offset(unsigned long long int value)
{
    return Offset32 { value };
}

consteval RegValue operator""_regval(unsigned long long int value)
{
    return RegValue { value };
}

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

using Tricore::Utils::operator""_offset;
using Tricore::Utils::operator""_regval;

#endif // ifndef TRICORE_EMU_UTILS_HPP
