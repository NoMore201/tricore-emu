#include "ParsedOptions.hpp"

#include <fmt/format.h>

bool ParsedOptions::contains(std::string_view name) const
{
    return m_options.contains(name);
}

std::optional<ParsedOptions::Value> ParsedOptions::get(std::string_view name) const
{
    if (auto it = m_options.find(name); it != m_options.end()) {
        return it->second;
    }
    return std::nullopt;
}

void ParsedOptions::add_option(std::string name, std::string value)
{
    auto [it, success] = m_options.try_emplace(std::move(name), Value { std::move(value) });
    if (!success) {
        throw Error{fmt::format("Option {} is already registered", name)};
    }
}
