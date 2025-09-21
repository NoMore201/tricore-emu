#include "ParsedOptions.hpp"

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

void ParsedOptions::add_option(std::string_view name, std::string value)
{
    m_options.emplace(name, Value { std::move(value) });
}
