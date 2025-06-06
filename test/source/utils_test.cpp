#include <gtest/gtest.h>

#include <Utils.hpp>

TEST(UtilsTest, Extract32)
{
    u32 input1 = 0xAAFFCC22U;
    EXPECT_EQ(0xFFU, Tricore::Utils::extract32(input1, 16U, 8U));
    EXPECT_EQ(0x1U, Tricore::Utils::extract32(0x80000000, 31U, 1U));

    EXPECT_DEATH(Tricore::Utils::extract32(0xFFFFFFFFU, 34U, 2U), "");
    EXPECT_DEATH(Tricore::Utils::extract32(0xFFFFFFFFU, 18U, 16U), "");
}

TEST(UtilsTest, Extract16)
{
    u16 input1 = 0xBEEFU;
    EXPECT_EQ(0xBU, Tricore::Utils::extract16(input1, 12, 4U));
    EXPECT_EQ(0xBCU, Tricore::Utils::extract16(0xABCDU, 4U, 8U));
    EXPECT_DEATH(Tricore::Utils::extract16(0xFFU, 15U, 2U), "");
    EXPECT_DEATH(Tricore::Utils::extract16(0xFFU, 24U, 8U), "");
}

TEST(UtilsTest, Deposit32)
{
    u32 input1 = 0xDEADBEEFU;
    EXPECT_EQ(0xABBABEEFU, Tricore::Utils::deposit32(0xABBAU, 16U, 16U, input1));
    EXPECT_EQ(0xFFFFEFFFU, Tricore::Utils::deposit32(0U, 12U, 1U, ~0U));
    // EXPECT_DEATH(Tricore::Utils::deposit32(0xFU, 34U, 2U, 0x12344321U), "");
    // EXPECT_DEATH(Tricore::Utils::deposit32(0xFU, 18U, 16U, 0x12344321U), "");
}

TEST(UtilsTest, SignExtend32)
{
    EXPECT_EQ(0xFFFFFFFFU, Tricore::Utils::sign_extend32<4>(0xFU));
    EXPECT_EQ(static_cast<u32>(-8), Tricore::Utils::sign_extend32<5>(0x18));
    EXPECT_EQ(0x1U, Tricore::Utils::sign_extend32<31>(0x1U));
    // EXPECT_DEATH(Tricore::Utils::sign_extend32<60>(0xFAFAFAFAU), "");
    // EXPECT_DEATH(Tricore::Utils::sign_extend32<0>(0xFAFAFAFAU), "");
}
