#pragma once

#include "pre_compiled_header.hpp"

template <typename Impl, typename Base>
concept BaseOf = std::is_base_of<Base, Impl>::value;
