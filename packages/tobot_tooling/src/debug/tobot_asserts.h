/**
 * @file tobot_asserts.h
 * @brief Contains test macro's regarding assertions
 */

#pragma once
namespace Tobot::Tooling::Debug {
// Asserts are only defined for debug builds
#if BUILD_TYPE_DEBUG

#include <iostream>
#include <string.h>

// Filename macro - filename without the path
#define __PRETTY_FILE__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define TOBOT_ASSERT(condition)                                                                              \
    {                                                                                                        \
        if (!(condition)) {                                                                                  \
            std::cout << "Assertion Failed: " << #condition << "\n\tin file" << __PRETTY_FILE__ << ", line " \
                      << __LINE__ << "\n\tfunction: " << __PRETTY_FUNCTION__ << "\n";                        \
            __debugbreak();                                                                                  \
        }                                                                                                    \
    }
#else
#define TOBOT_ASSERT(x)
#endif
} // namespace Tobot::Tooling::Debug