#pragma once

#include <iostream>

template <typename Impl, typename Base>
concept BaseOf = std::is_base_of<Base, Impl>::value;
