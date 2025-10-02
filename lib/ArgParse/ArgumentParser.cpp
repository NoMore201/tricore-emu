#include "ArgumentParser.hpp"
#include "ParsedOptions.hpp"

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <string_view>

namespace {

enum class MatchType : uint8_t {
    Short,
    Long,
    Positional
};

struct MatchOption {
    bool success;
    MatchType type;
    std::string_view identifier;
};

MatchOption parse_option(std::string_view arg_str)
{
    using enum MatchType;
    if (arg_str.starts_with("--")) {
        return { .success = true, .type = Long, .identifier = arg_str.substr(2) };
    }
    if (arg_str.starts_with('-')) {
        return { .success = true, .type = Short, .identifier = arg_str.substr(1, 1) };
    }

    return { .success = true, .type = Positional, .identifier = arg_str };
}

}

OptionBuilder::OptionBuilder(ArgumentParser& parser)
    : m_parser(&parser)
{
}

OptionBuilder& OptionBuilder::with_short_name(char short_name)
{
    m_option.short_name = short_name;
    return *this;
}

OptionBuilder& OptionBuilder::with_long_name(std::string_view long_name)
{
    m_option.long_name = long_name;
    return *this;
}

OptionBuilder& OptionBuilder::with_description(std::string_view description)
{
    m_option.description = description;
    return *this;
}

OptionBuilder& OptionBuilder::with_type(Option::Type type)
{
    m_option.type = type;
    return *this;
}

void OptionBuilder::build()
{
    m_parser->m_options.push_back(m_option);
}

OptionBuilder ArgumentParser::add_option()
{
    return OptionBuilder { *this };
}

ParsedOptions ArgumentParser::parse(int argc, char** argv)
{
    ParsedOptions parsed_options;
    int positional_index = 0;

    // TODO: validate input in case we have some option with '=' like --build=missing

    for (int index = 1; index < argc;) {
        std::string_view argument_str { argv[index] };
        bool has_next_argument = index + 1 < argc;
        int next_index_increment = 1;

        if (auto match = parse_option(argument_str); match.success) {

            switch (match.type) {
            case MatchType::Short: {
                if (!has_next_argument) {
                    printf("Option %s is missing an argument\n", argument_str.data());
                    break;
                }
                find_and_add_short(parsed_options, match.identifier, argv[index + 1]);
                next_index_increment = 2;
            } break;
            case MatchType::Long:
                throw std::runtime_error { "not implemented" };
            case MatchType::Positional: {
                find_and_add_positional(parsed_options, match.identifier, positional_index);
                positional_index += 1;
                break;
            }
            }
        }
        index += next_index_increment;
    }

    return parsed_options;
}

void ArgumentParser::find_and_add_short(ParsedOptions& output, std::string_view name, std::string_view value)
{
    auto it = std::ranges::find_if(m_options, [&name](const Option& opt) {
        return name[0] == opt.short_name;
    });
    if (it != m_options.end()) {
        output.add_option(name, std::string { value });
    }
}

void ArgumentParser::find_and_add_positional(ParsedOptions& output, std::string_view value, int index)
{
    std::vector<Option>::iterator it;
    {
        int current_index = 0;
        it = std::ranges::find_if(m_options, [&current_index, index](const Option& opt) {
            auto is_positional = opt.type == Option::Type::Positional;
            auto index_matches = current_index == index;
            if (is_positional) {
                current_index += 1;
            }
            return is_positional && index_matches;
        });
    }
    if (it != m_options.end()) {
        output.add_option(it->long_name, std::string { value });
    }
}
