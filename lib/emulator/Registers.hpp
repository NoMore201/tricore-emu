#ifndef TRICORE_EMU_REGISTERS_HPP
#define TRICORE_EMU_REGISTERS_HPP

#include "Types.hpp"

#include <gsl/narrow>

#include <stdexcept>

namespace Tricore {

class Offset32 {
    u32 m_offset;

public:
    template<std::integral I>
    constexpr explicit Offset32(I value)
    {
        auto narrowed = gsl::narrow<u32>(value);
        if (value >= 32) {
            throw std::runtime_error { "32 bit offset out of range" };
        }
        m_offset = narrowed;
    }

    [[nodiscard]] constexpr u32 value() const noexcept
    {
        return m_offset;
    }
};

class RegValue {
    u32 m_value;

public:
    template<std::integral I>
    constexpr explicit RegValue(I value)
        : m_value(gsl::narrow<u32>(value))
    {
    }

    constexpr u32 value() const noexcept { return m_value; }

    // Operators

    /// Add that it's allowed to wrap-around
    [[nodiscard]] constexpr RegValue wrapping_add(const RegValue& other) const
    {
        return RegValue { value() + other.value() };
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

    constexpr RegValue operator+(const RegValue& other) const
    {
        return wrapping_add(other);
    }

    /// Sub that it's allowed to wrap-around
    [[nodiscard]] constexpr RegValue wrapping_sub(const RegValue& other) const
    {
        return RegValue { value() - other.value() };
    }

    [[nodiscard]] constexpr RegValue safe_sub(const RegValue& other) const
    {
        auto result = m_value - other.value();
        if (result > m_value) {
            throw std::runtime_error { "RegValue: safe_sub wrap-around detected" };
        }
        return RegValue { result };
    }

    constexpr RegValue operator-(const RegValue& other) const
    {
        return wrapping_sub(other);
    }

    /// Mul that it's allowed to wrap-around
    [[nodiscard]] constexpr RegValue wrapping_mul(const RegValue& other) const
    {
        return RegValue { value() * other.value() };
    }

    [[nodiscard]] constexpr RegValue safe_mul(const RegValue& other) const
    {
        auto result = m_value * other.value();
        if (result < m_value) {
            throw std::runtime_error { "RegValue: safe_sub wrap-around detected" };
        }
        return RegValue { result };
    }

    constexpr RegValue operator*(const RegValue& other) const
    {
        return wrapping_mul(other);
    }

    [[nodiscard]] constexpr RegValue wrapping_div(const RegValue& other) const
    {
        if (other.value() == 0) {
            throw std::runtime_error { "RegValue: attempting to perform division by zero" };
        }
        return RegValue { value() / other.value() };
    }

    // TODO: implement safe_div

    constexpr RegValue operator/(const RegValue& other) const
    {
        return wrapping_div(other);
    }

    // Relational

    constexpr bool operator==(const RegValue& other) const
    {
        return value() == other.value();
    }

    constexpr bool operator!=(const RegValue& other) const
    {
        return value() != other.value();
    }

    constexpr bool operator>(const RegValue& other) const
    {
        return value() > other.value();
    }

    constexpr bool operator<(const RegValue& other) const
    {
        return value() < other.value();
    }

    // Bit operations

    constexpr RegValue operator<<(const RegValue& other) const
    {
        Offset32 offset { other.value() };
        return RegValue { value() << offset.value() };
    }

    constexpr RegValue operator>>(const RegValue& other) const
    {
        Offset32 offset { other.value() };
        return RegValue { value() >> offset.value() };
    }

    constexpr RegValue operator~() const
    {
        return RegValue { ~value() };
    }

    constexpr RegValue operator&(const RegValue& other) const
    {
        return RegValue { value() & other.value() };
    }

    constexpr RegValue operator|(const RegValue& other) const
    {
        return RegValue { value() | other.value() };
    }

    constexpr RegValue operator^(const RegValue& other) const
    {
        return RegValue { value() ^ other.value() };
    }

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
        u32 mask = (~0U >> (32 - length)) << offset.value();
        return RegValue { (m_value & ~mask) | ((value.value() << offset.value()) & mask) };
    }

    template<usize B>
    [[nodiscard]] constexpr RegValue sign_extend32()
    {
        static_assert(B != 0 && B < 32);
        // clear uppermost bits
        u32 cleared_input = m_value & ((1U << B) - 1U);
        u32 sign_bit_mask = (1U << (B - 1U));
        return RegValue { (cleared_input ^ sign_bit_mask) - sign_bit_mask };
    }
};

} // namespace Tricore

consteval Tricore::Offset32 operator""_offset(unsigned long long int value)
{
    return Tricore::Offset32 { value };
}

consteval Tricore::RegValue operator""_regval(unsigned long long int value)
{
    return Tricore::RegValue { value };
}

#endif // TRICORE_EMU_REGISTERS_HPP
