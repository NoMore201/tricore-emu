#ifndef TRICORE_EMU_TYPES_HPP
#define TRICORE_EMU_TYPES_HPP

#include <cstddef>
#include <cstdint>

// NOLINTBEGIN(readability-identifier-naming)

using u8   = std::uint8_t;
using u16  = std::uint16_t;
using u32  = std::uint32_t;
using u64  = std::uint64_t;

using i8   = std::int8_t;
using i16  = std::int16_t;
using i32  = std::int32_t;
using i64  = std::int64_t;

using usize = std::size_t;

static constexpr usize KiB = 1024ULL;
static constexpr usize MiB = 1024ULL * 1024ULL;

// NOLINTEND(readability-identifier-naming)

#endif // ifndef TRICORE_EMU_TYPES_HPP