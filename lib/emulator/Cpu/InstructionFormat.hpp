#ifndef TRICORE_EMU_INSTRUCTION_FORMAT_HPP
#define TRICORE_EMU_INSTRUCTION_FORMAT_HPP

#include "Cpu/Registers.hpp"

namespace Tricore::InstructionFormat {

struct Bol {
    RegValue a;
    RegValue b;
    RegValue off16;

    explicit Bol(const RegValue& value)
        : a(value.extract32(8_offset, 4))
        , b(value.extract32(12_offset, 4))
        , off16(value.extract32(16_offset, 6)
              | (value.extract32(28_offset, 4) << 6_regval)
              | (value.extract32(22_offset, 6) << 10_regval))
    {
    }
};

} // namespace Tricore::InstructionFormat

#endif // ifndef TRICORE_EMU_TYPES_HPP
