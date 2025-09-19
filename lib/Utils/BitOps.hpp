#ifndef UTILS_BIT_OPS_HPP_
#define UTILS_BIT_OPS_HPP_

#include <gsl/assert>
#include <gsl/narrow>
#include <gsl/span>
#include <gsl/span_ext>

#include <cstdint>

namespace Utils {

template<std::size_t B>
static constexpr uint32_t sign_extend32(const uint32_t input)
{
    static_assert(B != 0 && B < 32);
    // clear uppermost bits
    uint32_t cleared_input = input & ((1U << B) - 1U);
    uint32_t sign_bit_mask = (1U << (B - 1U));
    return (cleared_input ^ sign_bit_mask) - sign_bit_mask;
}

static constexpr uint32_t extract32(uint32_t data, uint32_t offset, uint32_t length)
{
    constexpr uint32_t num_of_bits = 32;
    Expects(offset < num_of_bits && length <= num_of_bits - offset);
    return (data >> offset) & ((~0U) >> (num_of_bits - length));
}

static constexpr uint16_t extract16(uint16_t data, uint32_t offset, uint32_t length)
{
    constexpr uint32_t num_of_bits = 16;
    Expects(offset < num_of_bits && length <= num_of_bits - offset);
    return static_cast<uint16_t>(extract32(data, offset, length));
}

static constexpr uint32_t deposit32(uint32_t field, uint32_t offset, uint32_t length, uint32_t destination)
{
    constexpr uint32_t num_of_bits = 32;
    Expects(offset < num_of_bits && length <= num_of_bits - offset);
    uint32_t mask = (~0U >> (num_of_bits - length)) << offset;
    return (destination & ~mask) | ((field << offset) & mask);
}

} // namespace Utils

#endif // UTILS_BIT_OPS_HPP_
