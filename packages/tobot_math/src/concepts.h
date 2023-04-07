#pragma once

#include "pre_compiled_header.h"

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template <typename T>
concept ArithmeticFloatingPoint = std::is_floating_point_v<T>;

template <typename T>
concept ArithmeticIntegral = std::is_integral_v<T>;

template <typename T>
concept ArithmeticSigned = std::is_signed_v<T>;

template <typename T>
concept ArithmeticUnsigned = std::is_unsigned_v<T>;