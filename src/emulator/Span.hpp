#ifndef TRICORE_EMU_SPAN_HPP_
#define TRICORE_EMU_SPAN_HPP_

#include <cstdint>

#include <gsl/span>

template<typename T>
using Span = gsl::span<T>;

namespace Utils {

static constexpr Span<uint8_t> to_byte_span(auto* const buffer, std::size_t length)
{
    return gsl::make_span(reinterpret_cast<uint8_t*>(buffer), length);
}

static constexpr Span<const uint8_t> to_byte_span(const auto* const buffer, std::size_t length)
{
    return gsl::make_span(reinterpret_cast<const uint8_t*>(buffer), length);
}

} // namespace Utils

#endif // TRICORE_EMU_SPAN_HPP_
