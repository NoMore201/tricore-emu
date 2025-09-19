#include "ParsedOptions.hpp"

bool ParsedOptions::contains(std::string_view name) const
{
    return m_options.contains(name);
}

std::optional<ParsedOptions::Value> ParsedOptions::get(std::string_view name) const
{
    auto it = m_options.find(name);
    if (it != m_options.end()) {
        return Value { it->second };
    }
    return std::nullopt;
}
