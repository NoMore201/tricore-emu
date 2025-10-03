#ifndef ARGPARSE_PARSED_OPTIONS_HPP_
#define ARGPARSE_PARSED_OPTIONS_HPP_

#include <charconv>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>

class ParsedOptions {
public:
    friend class ArgumentParser;

    struct Error : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };

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
    void add_option(std::string name, std::string value);

    struct StringHash {
        using is_transparent = void;

        std::size_t operator()(std::string_view sv) const
        {
            std::hash<std::string_view> hasher;
            return hasher(sv);
        }
    };

    std::unordered_map<std::string, Value, StringHash, std::equal_to<>> m_options;
};

#endif // ARGPARSE_PARSED_OPTIONS_HPP_
