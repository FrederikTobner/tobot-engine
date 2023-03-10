#pragma once

#include <iostream>

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template <typename Impl, typename Base>
concept BaseOf = std::is_base_of<Base, Impl>::value;
