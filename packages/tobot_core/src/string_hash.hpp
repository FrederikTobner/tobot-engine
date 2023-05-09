#pragma once

namespace Tobot::Core {

    /// @brief Hashing for strings and char pointers that can be used in unordered_map.
    struct StringHash {
            using hash_type = std::hash<std::string_view>;
            using is_transparent = void;

            auto operator()(const char * str) const -> std::size_t;
            auto operator()(std::string_view str) const -> std::size_t;
            auto operator()(std::string const & str) const -> std::size_t;
    };
} // namespace Tobot::Core