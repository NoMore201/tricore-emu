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
    None
};

struct MatchOption {
    bool success;
    MatchType type;
    std::string_view identifier;
};

MatchOption parse_option(std::string_view arg_str)
{
    if (arg_str.starts_with("--")) {
        return { true, MatchType::Long, arg_str.substr(2) };
    }
    if (arg_str.starts_with('-')) {
        return { true, MatchType::Short, arg_str.substr(1, 1) };
    }

    return { false, MatchType::None, {} };
}

}

void ArgumentParser::add_option(char short_name, std::string_view long_name, std::string_view description)
{
    m_options.emplace_back(short_name, long_name, description);
}

ParsedOptions ArgumentParser::parse(int argc, char** argv)
{
    ParsedOptions parsed_options;

    for (int index = 0; index < argc; index++) {
        std::string_view argument_str { argv[index] };
        bool has_next_argument = index + 1 < argc;

        printf("arg: %s\n", argument_str.data());
        auto match = parse_option(argument_str);
        if (match.success) {

            if (!has_next_argument) {
                printf("Option %s is missing an argument\n", argument_str.data());
                continue;
            }

            switch (match.type) {
            case MatchType::Short: {
                find_and_add_short(parsed_options, match.identifier, std::string{argv[index + 1]});
            } break;
            case MatchType::Long:
            case MatchType::None:
                continue;
            }
        }
    }

    return parsed_options;
}

void ArgumentParser::find_and_add_short(ParsedOptions& output, std::string_view short_opt, std::string value)
{
    auto it = std::ranges::find_if(m_options, [&short_opt](const Option& opt) {
        return short_opt[0] == opt.short_name;
    });
    if (it != m_options.end()) {
        output.add_option(short_opt, std::move(value));
    }
}
