#pragma once

#include "pre_compiled_header.h"

template <typename T>
concept IsBinarySearchTreeNode =
    std::is_member_pointer_v<decltype(&T::left)> && std::is_member_pointer_v<decltype(&T::right)> &&
    std::is_member_pointer_v<decltype(&T::value)>;

template <typename T1, typename T2>
concept IsValueInBinarySearchTreeNode = std::is_same<decltype(T1::value), T2>::value;
