#ifndef TRICORE_EMU_INSTRUCTION_FORMAT_HPP
#define TRICORE_EMU_INSTRUCTION_FORMAT_HPP

#include "Utils.hpp"

namespace Tricore::InstructionFormat {

struct Bol {
    u32 a;
    u32 b;
    u32 off16;

    constexpr explicit Bol(u32 insn)
        : a(Utils::extract32(insn, 8, 4))
        , b(Utils::extract32(insn, 12, 4))
        , off16(Utils::extract32(insn, 16, 6)
              | (Utils::extract32(insn, 28, 4) << 6)
              | (Utils::extract32(insn, 22, 6) << 10))
    {
    }
};

struct Rr {
    u32 a;
    u32 b;
    u32 c;

    constexpr explicit Rr(u32 insn)
        : a(Utils::extract32(insn, 8, 4))
        , b(Utils::extract32(insn, 12, 4))
        , c(Utils::extract32(insn, 28, 4))
    {
    }
};

struct Brn {
    u32 a;
    u32 n;
    u32 disp15;

    constexpr explicit Brn(u32 insn)
        : a(Utils::extract32(insn, 8, 4))
        , n(Utils::extract32(insn, 12, 4))
        , disp15(Utils::extract32(insn, 16, 15))
    {
    }
};

struct Rc {
    u32 a;
    u32 c;
    u32 const9;

    constexpr explicit Rc(u32 insn)
        : a(Utils::extract32(insn, 8, 4))
        , c(Utils::extract32(insn, 28, 4))
        , const9(Utils::extract32(insn, 12, 9))
    {
    }
};

} // namespace Tricore::InstructionFormat

#endif // ifndef TRICORE_EMU_TYPES_HPP
