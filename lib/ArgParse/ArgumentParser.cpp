#include "ArgumentParser.hpp"

void ArgumentParser::add_option(char short_name, std::string_view long_name, std::string_view description) {
    m_options.push_back(Option{short_name, long_name, description});
}

void ArgumentParser::parse(int argc, char** argv) {
    // Parsing logic to be implemented
}