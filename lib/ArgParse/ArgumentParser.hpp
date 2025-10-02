#ifndef ARGPARSE_ARGUMENT_PARSER_HPP_
#define ARGPARSE_ARGUMENT_PARSER_HPP_

#include <string_view>
#include <vector>

#include <gsl/pointers>

#include "ParsedOptions.hpp"

class ArgumentParser;

struct Option {
    enum class Type : uint8_t {
        Positional,
        Boolean,
        Argument
    };

    char short_name{'\0'};
    Type type{Type::Positional};
    std::string_view long_name;
    std::string_view description;
};

class OptionBuilder {

public:
    explicit OptionBuilder(ArgumentParser& parser);

    OptionBuilder& with_short_name(char short_name);
    OptionBuilder& with_long_name(std::string_view long_name);
    OptionBuilder& with_description(std::string_view description);
    OptionBuilder& with_type(Option::Type type);

    void build();

private:
    Option m_option;
    gsl::not_null<ArgumentParser*> m_parser;
};

class ArgumentParser {

public:
    OptionBuilder add_option();

    ParsedOptions parse(int argc, char** argv);

private:
    friend OptionBuilder;
    void find_and_add_short(ParsedOptions& output, std::string_view name, std::string_view value);
    void find_and_add_positional(ParsedOptions& output, std::string_view value, int index);

    std::vector<Option> m_options;
};

#endif // ARGPARSE_ARGUMENT_PARSER_HPP_
