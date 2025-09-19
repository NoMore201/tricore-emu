#ifndef TRICORE_EMU_INSTRUCTION_FORMAT_HPP
#define TRICORE_EMU_INSTRUCTION_FORMAT_HPP

#include "Types.hpp"

namespace Tricore::InstructionFormat {

struct Bol {
    u32 a;
    u32 b;
    u32 off16;

    explicit Bol(u32 insn);
};

struct Rr {
    u32 a;
    u32 b;
    u32 c;

    explicit Rr(u32 insn);
};

struct Brn {
    u32 a;
    u32 n;
    u32 disp15;

    explicit Brn(u32 insn);
};

struct Rc {
    u32 a;
    u32 c;
    u32 const9;

    explicit Rc(u32 insn);
};

struct Srr {
    u32 a;
    u32 b;

    explicit Srr(u32 insn);
};

using Ssr = Srr;

struct Src {
    u32 a;
    u32 const4;

    explicit Src(u32 insn);
};

} // namespace Tricore::InstructionFormat

#endif // ifndef TRICORE_EMU_TYPES_HPP
