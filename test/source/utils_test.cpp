#include <Registers.hpp>
#include <Utils.hpp>
#include <Types.hpp>

#include <cstdint>

#include <gtest/gtest.h>

using namespace Tricore;

static_assert(Tricore::Offset32 { 4ULL }.value() == 4);
static_assert(Tricore::Offset32 { 31 }.value() == 31);

TEST(UtilsTest, Offset32)
{
    for (int index = 0; index < 32; index++) {
        ASSERT_EQ(Tricore::Offset32 { index }.value(), index);
    }

    ASSERT_ANY_THROW(Tricore::Offset32 { 40 });
    ASSERT_ANY_THROW(Tricore::Offset32 { UINT32_MAX });
}

static_assert(Tricore::RegValue { 0xFF }.safe_add(1_regval).value() == 0x100);
static_assert(Tricore::RegValue { 0xFFFFFFFF }.wrapping_add(1_regval).value() == 0);

TEST(UtilsTest, RegValueInit)
{
    ASSERT_EQ(Tricore::RegValue { 0 }.value(), 0);
    ASSERT_EQ(Tricore::RegValue { 0xFFFFFFFF }.value(), 0xFFFFFFFF);

    EXPECT_ANY_THROW(Tricore::RegValue { UINT64_MAX });
}

TEST(UtilsTest, RegValueSafeArithmetic)
{
    EXPECT_ANY_THROW(Tricore::RegValue { UINT32_MAX }.safe_add(1_regval).value());
    EXPECT_ANY_THROW(Tricore::RegValue { UINT32_MAX }.safe_mul(2_regval).value());
    EXPECT_ANY_THROW(Tricore::RegValue { 1 }.safe_sub(0xFF_regval).value());

    ASSERT_EQ(Tricore::RegValue { 32 }.safe_add(32_regval).value(), 64);
    ASSERT_EQ(Tricore::RegValue { 32 }.safe_sub(32_regval).value(), 0);
    ASSERT_EQ(Tricore::RegValue { 32 }.safe_mul(32_regval).value(), 1024);
}

TEST(UtilsTest, RegValueUnsafeArithmetic)
{
    ASSERT_EQ(Tricore::RegValue { 0xF0000000 }.wrapping_add(0x10000000_regval).value(), 0);
    ASSERT_EQ(Tricore::RegValue { 0x10000000 }.wrapping_sub(0x20000000_regval).value(), 0xF0000000);
    ASSERT_EQ(Tricore::RegValue { 0x10000000 }.wrapping_mul(17_regval).value(), 0x10000000);
}

static_assert(RegValue{0xF0}.sign_extend32<8>().value() == 0xFFFFFFF0);
static_assert(RegValue{0x7F}.sign_extend32<8>().value() == 0x7F);

TEST(UtilsTest, RegValueSignExtend)
{
    ASSERT_EQ(Tricore::RegValue { 0x8FFF }.sign_extend32<16>().value(), 0xFFFF8FFF);
    ASSERT_EQ(Tricore::RegValue { 0xFFFFFFFF }.sign_extend32<31>().value(), 0xFFFFFFFF);
}
