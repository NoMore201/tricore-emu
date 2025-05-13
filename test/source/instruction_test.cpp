#include <InstructionFormat.hpp>
#include <Types.hpp>

#include <gtest/gtest.h>

TEST(InstructionTest, BolTest)
{
    using namespace Tricore;

    // TODO: use a real instruction
    InstructionFormat::Bol insn{0xFFFF_regval};

    ASSERT_EQ(insn.a, 0xF_regval);
    ASSERT_EQ(insn.b, 0xF_regval);
    ASSERT_EQ(insn.off16, 0_regval);
}
