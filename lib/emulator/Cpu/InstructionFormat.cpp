#include "Cpu/InstructionFormat.hpp"

Tricore::InstructionFormat::Bol::Bol(const RegValue& value)
    : a(value.extract32(8_offset, 4))
    , b(value.extract32(12_offset, 4))
    , off16(value.extract32(16_offset, 6)
          | (value.extract32(28_offset, 4) << 6_regval)
          | (value.extract32(22_offset, 6) << 10_regval))
{
}

Tricore::InstructionFormat::Rr::Rr(const RegValue& value)
    : a(value.extract32(8_offset, 4))
    , b(value.extract32(12_offset, 4))
    , c(value.extract32(28_offset, 4))
{
}
