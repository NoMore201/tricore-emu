#include <gtest/gtest.h>

#include <ArgumentParser.hpp>

TEST(ArgumentParserTest, ShortOption) {
    ArgumentParser parser{};

    char arg1[] = {'.', '/', 'm', 'y', 'p', 'r', 'o', 'g', '\0'};
    char arg2[] = {'-', 'c', '\0'};
    char arg3[] = {'c', 'm', 'd', '\0'};

    char* str_list[] = {
        arg1,
        arg2,
        arg3
    };
    parser.add_option()
        .with_short_name("c")
        .with_long_name("command")
        .with_description("Command to execute")
        .with_type(Option::Type::Argument)
        .build();
    auto arguments = parser.parse(3, str_list);
    auto cmd = arguments.get("command");
    ASSERT_TRUE(cmd.has_value());
    ASSERT_EQ(cmd.value().raw, "cmd");
}

TEST(ArgumentParserTest, PositionalArgument) {
    ArgumentParser parser{};

    char arg1[] = {'.', '/', 'm', 'y', 'p', 'r', 'o', 'g', '\0'};
    char arg2[] = {'r', 'e', 'b', 'o', 'o', 't', '\0'};
    char arg3[] = {'n', 'o', 'w', '\0'};

    char* str_list[] = {
        arg1,
        arg2,
        arg3
    };
    parser.add_option()
        .with_long_name("command")
        .with_description("Command to execute")
        .with_type(Option::Type::Positional)
        .build();
    parser.add_option()
        .with_long_name("time")
        .with_description("When command should be executed")
        .with_type(Option::Type::Positional)
        .build();
    auto arguments = parser.parse(3, str_list);
    auto cmd = arguments.get("command");
    auto when = arguments.get("time");
    ASSERT_TRUE(cmd.has_value());
    ASSERT_EQ(cmd.value().raw, "reboot");
    ASSERT_TRUE(when.has_value());
    ASSERT_EQ(when.value().raw, "now");
}