#pragma once

#include "pre_compiled_header.h"

template <typename Impl, typename Base>
concept BaseOf = std::is_base_of<Base, Impl>::value;
