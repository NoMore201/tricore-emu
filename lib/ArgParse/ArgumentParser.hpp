#ifndef ARGPARSE_ARGUMENT_PARSER_HPP_
#define ARGPARSE_ARGUMENT_PARSER_HPP_

#include <charconv>
#include <optional>
#include <string_view>
#include <unordered_map>
#include <vector>

#include <gsl/pointers>

class ArgumentParser;

struct Option {
    enum class Type : uint8_t {
        Positional,
        Boolean,
        Argument
    };

    std::string_view short_name;
    Type type {Type::Positional};
    std::string_view long_name;
    std::string_view description;

    /**
     * Get default name for the option which is the
     * long name. If not available, return short name
     */
    [[nodiscard]] std::string_view get_name() const
    {
        if (!long_name.empty()) {
            return long_name;
        }
        return short_name;
    }
};

struct OptionValue {
    std::string raw;

    template<typename T>
    std::optional<T> parse_as() const
    {
        if constexpr (std::is_same_v<T, std::string> || std::is_same_v<T, std::string_view>) {
            return raw;
        } else if constexpr (std::is_same_v<T, bool>) {
            return raw == "1";
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

class OptionBuilder {

public:
    explicit OptionBuilder(ArgumentParser& parser);

    OptionBuilder& with_short_name(std::string_view short_name);
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
    struct StringHash {
        using is_transparent = void;

        std::size_t operator()(std::string_view sv) const
        {
            std::hash<std::string_view> hasher;
            return hasher(sv);
        }
    };

    using ResultMap = std::unordered_map<std::string, OptionValue, StringHash, std::equal_to<>>;

    OptionBuilder add_option();

    ResultMap parse(int argc, char** argv);

private:
    friend OptionBuilder;

    std::vector<Option> m_options;
};

#endif // ARGPARSE_ARGUMENT_PARSER_HPP_
