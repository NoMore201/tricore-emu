#ifndef TRICORE_EMU_INSTRUCTION_FORMAT_HPP
#define TRICORE_EMU_INSTRUCTION_FORMAT_HPP

#include "Cpu/Registers.hpp"

namespace Tricore::InstructionFormat {

struct Bol {
    RegValue a;
    RegValue b;
    RegValue off16;

    constexpr explicit Bol(const RegValue& value)
    : a(value.extract32(8_offset, 4))
    , b(value.extract32(12_offset, 4))
    , off16(value.extract32(16_offset, 6)
          | (value.extract32(28_offset, 4) << 6_regval)
          | (value.extract32(22_offset, 6) << 10_regval))
{
}
};

struct Rr {
    RegValue a;
    RegValue b;
    RegValue c;

    constexpr explicit Rr(const RegValue& value)
        : a(value.extract32(8_offset, 4))
        , b(value.extract32(12_offset, 4))
        , c(value.extract32(28_offset, 4))
    {
    }
};

struct Brn {
    RegValue a;
    RegValue n;
    RegValue disp15;

    constexpr explicit Brn(const RegValue& value)
        : a(value.extract32(8_offset, 4))
        , n(value.extract32(12_offset, 4))
        , disp15(value.extract32(16_offset, 15))
    {
    }
};

} // namespace Tricore::InstructionFormat

#endif // ifndef TRICORE_EMU_TYPES_HPP
