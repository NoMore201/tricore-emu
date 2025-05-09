
#include "Types.hpp"
#include <cstdint>
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

static_assert(Tricore::Utils::Offset32 { 4ULL }.value() == 4);
static_assert(Tricore::Utils::Offset32 { 31 }.value() == 31);

TEST(UtilsTest, Offset32)
{
    for (int index = 0; index < 32; index++) {
        ASSERT_EQ(Tricore::Utils::Offset32 { index }.value(), index);
    }

    ASSERT_ANY_THROW(Tricore::Utils::Offset32 { 40 });
    ASSERT_ANY_THROW(Tricore::Utils::Offset32 { UINT32_MAX });
}

static_assert(Tricore::Utils::RegValue { 0xFF }.safe_add(1_regval).value() == 0x100);
static_assert(Tricore::Utils::RegValue { 0xFFFFFFFF }.wrapping_add(1_regval).value() == 0);

TEST(UtilsTest, RegValueInit)
{
    ASSERT_EQ(Tricore::Utils::RegValue { 0 }.value(), 0);
    ASSERT_EQ(Tricore::Utils::RegValue { 0xFFFFFFFF }.value(), 0xFFFFFFFF);

    EXPECT_ANY_THROW(Tricore::Utils::RegValue { UINT64_MAX });
}

TEST(UtilsTest, RegValueSafeArithmetic)
{
    EXPECT_ANY_THROW(Tricore::Utils::RegValue { UINT32_MAX }.safe_add(1_regval).value());
    EXPECT_ANY_THROW(Tricore::Utils::RegValue { UINT32_MAX }.safe_mul(2_regval).value());
    EXPECT_ANY_THROW(Tricore::Utils::RegValue { 1 }.safe_sub(0xFF_regval).value());

    ASSERT_EQ(Tricore::Utils::RegValue { 32 }.safe_add(32_regval).value(), 64);
    ASSERT_EQ(Tricore::Utils::RegValue { 32 }.safe_sub(32_regval).value(), 0);
    ASSERT_EQ(Tricore::Utils::RegValue { 32 }.safe_mul(32_regval).value(), 1024);
}

TEST(UtilsTest, RegValueUnsafeArithmetic)
{
    ASSERT_EQ(Tricore::Utils::RegValue { 0xF0000000 }.wrapping_add(0x10000000_regval).value(), 0);
    ASSERT_EQ(Tricore::Utils::RegValue { 0x10000000 }.wrapping_sub(0x20000000_regval).value(), 0xF0000000);
    ASSERT_EQ(Tricore::Utils::RegValue { 0x10000000 }.wrapping_mul(17_regval).value(), 0x10000000);
}
