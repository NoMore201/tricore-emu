#include "Cpu/InstructionFormat.hpp"

#include <BitOps.hpp>

Tricore::InstructionFormat::Bol::Bol(u32 insn)
    : a(Utils::extract32(insn, 8, 4))
    , b(Utils::extract32(insn, 12, 4))
    , off16(Utils::extract32(insn, 16, 6)
          | (Utils::extract32(insn, 28, 4) << 6)
          | (Utils::extract32(insn, 22, 6) << 10))
{
}

Tricore::InstructionFormat::Rr::Rr(u32 insn)
    : a(Utils::extract32(insn, 8, 4))
    , b(Utils::extract32(insn, 12, 4))
    , c(Utils::extract32(insn, 28, 4))
{
}

Tricore::InstructionFormat::Brn::Brn(u32 insn)
    : a(Utils::extract32(insn, 8, 4))
    , n(Utils::extract32(insn, 12, 4))
    , disp15(Utils::extract32(insn, 16, 15))
{
}

Tricore::InstructionFormat::Rc::Rc(u32 insn)
    : a(Utils::extract32(insn, 8, 4))
    , c(Utils::extract32(insn, 28, 4))
    , const9(Utils::extract32(insn, 12, 9))
{
}

Tricore::InstructionFormat::Srr::Srr(u32 insn)
    : a(Utils::extract32(insn, 8, 4))
    , b(Utils::extract32(insn, 12, 4))
{
}

Tricore::InstructionFormat::Src::Src(u32 insn)
    : a(Utils::extract32(insn, 8, 4))
    , const4(Utils::extract32(insn, 12, 4))
{
}
