#ifndef ARGPARSE_PARSED_OPTIONS_HPP_
#define ARGPARSE_PARSED_OPTIONS_HPP_

#include <charconv>
#include <optional>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>


class ParsedOptions {
public:
    friend class ArgumentParser;

    struct Value {
        std::string raw;

        template<typename T>
        std::optional<T> parse_as() const
        {
            if constexpr (std::is_same_v<T, std::string>) {
                return raw;
            } else if constexpr (std::is_same_v<T, std::string_view>) {
                return raw;
            } else if constexpr (std::is_integral_v<T> || std::is_floating_point_v<T>) {
                T result {};
                auto [ptr, ec] = std::from_chars(raw.data(), raw.data() + raw.size(), result);
                if (ec == std::errc {}) {
                    return result;
                }
            }
            return std::nullopt;
        }
    };

    bool contains(std::string_view name) const;

    std::optional<Value> get(std::string_view name) const;

private:
    void add_option(std::string_view name, std::string value);

    std::unordered_map<std::string_view, Value> m_options;
};

#endif // ARGPARSE_PARSED_OPTIONS_HPP_
