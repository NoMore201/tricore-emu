#ifndef TRICORE_EMU_INSTRUCTION_FORMAT_HPP
#define TRICORE_EMU_INSTRUCTION_FORMAT_HPP

#include "Cpu/Registers.hpp"

namespace Tricore::InstructionFormat {

struct Bol {
    RegValue a;
    RegValue b;
    RegValue off16;

    constexpr explicit Bol(u32 insn)
        : Bol(RegValue { insn })
    {
    }

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

    constexpr explicit Rr(u32 insn)
        : Rr(RegValue { insn })
    {
    }

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

    constexpr explicit Brn(u32 insn)
        : Brn(RegValue { insn })
    {
    }

    constexpr explicit Brn(const RegValue& value)
        : a(value.extract32(8_offset, 4))
        , n(value.extract32(12_offset, 4))
        , disp15(value.extract32(16_offset, 15))
    {
    }
};

struct Rc {
    RegValue a;
    RegValue c;
    RegValue const9;

    constexpr explicit Rc(u32 insn)
        : Rc(RegValue { insn })
    {
    }

    constexpr explicit Rc(const RegValue& value)
        : a(value.extract32(8_offset, 4))
        , c(value.extract32(28_offset, 4))
        , const9(value.extract32(12_offset, 9))
    {
    }
};

} // namespace Tricore::InstructionFormat

#endif // ifndef TRICORE_EMU_TYPES_HPP
