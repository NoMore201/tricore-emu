#ifndef ARGPARSE_ARGUMENT_PARSER_HPP_
#define ARGPARSE_ARGUMENT_PARSER_HPP_

#include <string_view>
#include <vector>

class ArgumentParser {

public:
    void add_option(char short_name, std::string_view long_name, std::string_view description);

    void parse(int argc, char** argv);

private:
    struct Option {
        char short_name;
        std::string_view long_name;
        std::string_view description;
    };

    std::vector<Option> m_options;
};

#endif // ARGPARSE_ARGUMENT_PARSER_HPP_
