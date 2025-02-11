
#include "gtest/gtest.h"
#include <gtest/gtest.h>

#include <Utils.hpp>


TEST(UtilsTest, Extract32) {
    u32 input1 = 0xAAFFCC22U;
    EXPECT_EQ(0xFFU, Tricore::Utils::extract32(input1, 16U, 8U));
    EXPECT_EQ(0x1U, Tricore::Utils::extract32(0x80000000, 31U, 1U));

    EXPECT_DEATH(Tricore::Utils::extract32(0xFFFFFFFFU, 34U, 2U), "");
    EXPECT_DEATH(Tricore::Utils::extract32(0xFFFFFFFFU, 18U, 16U), "");
}

TEST(UtilsTest, Extract16) {
    u16 input1 = 0xBEEFU;
    EXPECT_EQ(0xBU, Tricore::Utils::extract16(input1, 12, 4U));
    EXPECT_EQ(0xBCU, Tricore::Utils::extract16(0xABCDU, 4U, 8U));
    EXPECT_DEATH(Tricore::Utils::extract16(0xFFU, 15U, 2U), "");
    EXPECT_DEATH(Tricore::Utils::extract16(0xFFU, 24U, 8U), "");
}
