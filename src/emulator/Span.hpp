#ifndef UTILS_SPAN_HPP_
#define UTILS_SPAN_HPP_

#include <cstdint>

#include <gsl/span>

namespace Utils {

static constexpr gsl::span<uint8_t> to_span(auto* const buffer, std::size_t length)
{
    return gsl::make_span(reinterpret_cast<uint8_t*>(buffer), length);
}

static constexpr gsl::span<const uint8_t> to_span(const auto* const buffer, std::size_t length)
{
    return gsl::make_span(reinterpret_cast<const uint8_t*>(buffer), length);
}

} // namespace Utils


#endif // UTILS_SPAN_HPP_