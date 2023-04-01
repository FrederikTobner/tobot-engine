#pragma once

#include "pre_compiled_header.h"

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;
