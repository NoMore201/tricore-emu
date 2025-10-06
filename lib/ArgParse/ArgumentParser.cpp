#include "ArgumentParser.hpp"

#include <algorithm>
#include <cstdint>
#include <string_view>

#include <fmt/format.h>

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

struct InternalParser {

    struct StringHash {
        using is_transparent = void;

        std::size_t operator()(std::string_view sv) const
        {
            std::hash<std::string_view> hasher;
            return hasher(sv);
        }
    };

    struct Error : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };

    /// Options currently registered with ArgumentParser class
    const std::vector<Option>& registered_options;

    /// Representation of argv array using vector of string_view
    std::vector<std::string_view> arguments;

    ArgumentParser::ResultMap parsed_opt;

    int current_index { 1 };
    int current_positional_index { 0 };

    InternalParser(const std::vector<Option>& opts, int argc, char** argv)
        : registered_options(opts)
    {
        for (int index = 0; index < argc; index++) {
            arguments.emplace_back(argv[index]);
        }
    }

    [[nodiscard]] bool has_next_argument() const noexcept
    {
        return static_cast<std::size_t>(current_index) + 1 < arguments.size();
    }

    [[nodiscard]] std::string_view get() const
    {
        return arguments.at(current_index);
    }

    void next(int increment = 1) noexcept
    {
        current_index += increment;
    }

    std::string_view get_argument_value_for(const Option& opt)
    {
        using namespace std::literals;

        switch (opt.type) {
            using enum Option::Type;
        case Argument: {
            auto current_str = get();
            if (auto pos = current_str.find('='); pos != std::string_view::npos) {
                return current_str.substr(pos + 1);
            }
            if (!has_next_argument()) {
                throw Error { fmt::format("Option {} specified without an argument", current_str) };
            }
            next();
            return get();
        }
        case Boolean:
            return "1"sv;
        case Positional:
        default:
            throw Error { "Argument cannot be of type positional" };
        }
    }

    void parse_double_dash_argument(std::string_view arg)
    {
        auto stripped = arg.substr(2);
        std::string_view name;
        if (auto pos = stripped.find('='); pos != std::string_view::npos) {
            name = stripped.substr(0, pos);
        } else {
            name = stripped;
        }

        auto it = std::ranges::find_if(registered_options, [&name](const Option& opt) {
            return opt.long_name == name;
        });
        if (it != registered_options.end()) {
            auto value = get_argument_value_for(*it);
            auto [_, success] = parsed_opt.try_emplace(std::string { it->get_name() }, std::string { value });
            if (!success) {
                throw Error { fmt::format("Option {} specified multiple times", it->long_name) };
            }
        }
    }

    void parse_single_dash_argument(std::string_view arg)
    {
        auto stripped = arg.substr(1);
        if (!has_next_argument()) {
            throw Error { fmt::format("Option {} specified without an argument", arg) };
        }
        auto name = stripped;

        auto it = std::ranges::find_if(registered_options, [&name](const Option& opt) {
            return opt.short_name == name;
        });
        if (it != registered_options.end()) {
            auto value = get_argument_value_for(*it);

            auto [_, success] = parsed_opt.try_emplace(std::string { it->get_name() }, std::string { value });
            if (!success) {
                throw Error { fmt::format("Option {} specified multiple times", it->long_name) };
            }
        }
    }

    void parse_positional(std::string_view arg)
    {
        std::vector<Option>::const_iterator it;
        {
            int positional_index = 0;
            it = std::ranges::find_if(registered_options, [&positional_index, this](const Option& opt) {
                auto is_positional = opt.type == Option::Type::Positional;
                auto index_matches = positional_index == current_positional_index;
                if (is_positional) {
                    positional_index += 1;
                }
                return is_positional && index_matches;
            });
        }
        if (it != registered_options.end()) {
            auto [_, success] = parsed_opt.try_emplace(std::string { it->get_name() }, std::string { arg });
            if (!success) {
                throw Error { fmt::format("Option {} specified multiple times", it->long_name) };
            }
            current_positional_index += 1;
        }
    }

    void parse()
    {
        while (static_cast<std::size_t>(current_index) < arguments.size()) {
            if (auto current = get(); current.starts_with("--")) {
                parse_double_dash_argument(current);
            } else if (current.starts_with("-")) {
                parse_single_dash_argument(current);
            } else {
                parse_positional(current);
            }
            next();
        }
    }
};

}

OptionBuilder::OptionBuilder(ArgumentParser& parser)
    : m_parser(&parser)
{
}

OptionBuilder& OptionBuilder::with_short_name(std::string_view short_name)
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

ArgumentParser::ResultMap ArgumentParser::parse(int argc, char** argv)
{
    InternalParser parser { m_options, argc, argv };
    parser.parse();

    return std::move(parser.parsed_opt);
}
