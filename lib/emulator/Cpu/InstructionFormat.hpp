#ifndef TRICORE_EMU_INSTRUCTION_FORMAT_HPP
#define TRICORE_EMU_INSTRUCTION_FORMAT_HPP

#include "Cpu/Registers.hpp"

namespace Tricore::InstructionFormat {

struct Bol {
    RegValue a;
    RegValue b;
    RegValue off16;

    explicit Bol(const RegValue& value);
};

struct Rr {
    RegValue a;
    RegValue b;
    RegValue c;

    explicit Rr(const RegValue& value);
};

struct Brn {
    RegValue a;
    RegValue n;
    RegValue disp15;

    explicit Brn(const RegValue& value);
};

} // namespace Tricore::InstructionFormat

#endif // ifndef TRICORE_EMU_TYPES_HPP
