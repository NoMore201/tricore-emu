#ifndef ARGPARSE_ARGUMENT_PARSER_HPP_
#define ARGPARSE_ARGUMENT_PARSER_HPP_

#include <string_view>
#include <vector>

#include "ParsedOptions.hpp"

class ArgumentParser {

public:
    void add_option(char short_name, std::string_view long_name, std::string_view description);

    ParsedOptions parse(int argc, char** argv);

private:
    struct Option {
        char short_name;
        std::string_view long_name;
        std::string_view description;
    };

    void find_and_add_short(ParsedOptions& output, std::string_view short_opt, std::string value);

    std::vector<Option> m_options;
};

#endif // ARGPARSE_ARGUMENT_PARSER_HPP_
