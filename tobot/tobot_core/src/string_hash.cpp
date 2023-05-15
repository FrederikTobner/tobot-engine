#include "string_hash.hpp"

using namespace Tobot::Core;

[[nodiscard]] auto StringHash::operator()(const char * str) const -> std::size_t {
    return hash_type{}(str);
}

[[nodiscard]] auto StringHash::operator()(std::string_view str) const -> std::size_t {
    return hash_type{}(str);
}

[[nodiscard]] auto StringHash::operator()(std::string const & str) const -> std::size_t {
    return hash_type{}(str);
}