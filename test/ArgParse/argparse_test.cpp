#include <gtest/gtest.h>

#include <ArgumentParser.hpp>

class ArgumentParserTest : public ::testing::Test {

protected:
    void add_argument(std::string_view arg)
    {
        m_args[m_current_index] = const_cast<char*>(arg.data());
        m_current_index += 1;
    }

    void add_arguments(std::initializer_list<std::string_view> arg_list)
    {
        for (auto arg : arg_list) {
            m_args[m_current_index] = const_cast<char*>(arg.data());
            m_current_index += 1;
        }
    }

    char** get_argument_ptr() noexcept
    {
        return m_args;
    }

private:
    static constexpr std::size_t MAX_ARRAY_SIZE = 10;

    char* m_args[MAX_ARRAY_SIZE] {};
    std::size_t m_current_index {0};
};

TEST_F(ArgumentParserTest, ShortOptionWithArgument)
{
    ArgumentParser parser {};

    add_arguments({"./myprog",
        "-c",
        "cmd"});

    char** str_list = get_argument_ptr();
    parser.add_option()
        .with_short_name("c")
        .with_long_name("command")
        .with_description("Command to execute")
        .with_type(Option::Type::Argument)
        .build();
    auto arguments = parser.parse(3, str_list);
    auto cmd = arguments.at("command");
    ASSERT_EQ(cmd.raw, "cmd");
    ASSERT_EQ(cmd.parse_as<std::string_view>(), "cmd");
}

TEST_F(ArgumentParserTest, ShortOptionBoolean)
{
    ArgumentParser parser {};

    add_arguments({
        "./myprog",
        "-h",
    });

    char** str_list = get_argument_ptr();
    parser.add_option()
        .with_short_name("h")
        .with_long_name("help")
        .with_description("Show usage information")
        .with_type(Option::Type::Boolean)
        .build();
    auto arguments = parser.parse(2, str_list);
    auto cmd = arguments.at("help");
    ASSERT_EQ(cmd.parse_as<bool>(), true);
}

TEST_F(ArgumentParserTest, PositionalArgument)
{
    ArgumentParser parser {};

    add_arguments({"./myprog",
        "reboot",
        "now"});

    char** str_list = get_argument_ptr();
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
    auto cmd = arguments.at("command");
    auto when = arguments.at("time");
    ASSERT_EQ(cmd.raw, "reboot");
    ASSERT_EQ(when.raw, "now");
}
