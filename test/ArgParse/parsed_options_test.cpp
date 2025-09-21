#include <gtest/gtest.h>

#include <ParsedOptions.hpp>

TEST(ParsedOptionsTest, ParseAsStringView) {
    ParsedOptions::Value value{"example"};
    auto parsed = value.parse_as<std::string_view>();
    ASSERT_TRUE(parsed.has_value());
    EXPECT_EQ(parsed.value(), "example");
    EXPECT_EQ(parsed.value(), value.raw);
}

TEST(ParsedOptionsTest, ParseAsInt) {
    ParsedOptions::Value value{"123"};
    auto parsed = value.parse_as<int>();
    ASSERT_TRUE(parsed.has_value());
    EXPECT_EQ(parsed.value(), 123);
}

TEST(ParsedOptionsTest, ParseAsDouble) {
    ParsedOptions::Value value{"123.456"};
    auto parsed = value.parse_as<double>();
    ASSERT_TRUE(parsed.has_value());
    EXPECT_DOUBLE_EQ(parsed.value(), 123.456);
}