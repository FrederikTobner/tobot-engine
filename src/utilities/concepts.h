#pragma once

#include <iostream>

template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;
