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
    parser.add_option('c', "command", "Test command");
    auto arguments = parser.parse(3, str_list);
    auto cmd = arguments.get("c");
    ASSERT_TRUE(cmd.has_value());
    ASSERT_EQ(cmd.value().raw, "cmd");
}