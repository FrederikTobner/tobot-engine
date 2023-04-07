/**
 * @file tobot_asserts.h
 * @brief Contains test macro's regarding assertions
 */

#pragma once

#include "../logging/logger.h"
namespace Tobot::Tooling::Debug {
// Asserts are only defined for debug builds
#ifdef BUILD_TYPE_DEBUG
#define TOBOT_ASSERT(condition)                                                                                   \
    {                                                                                                             \
        if (!(condition)) {                                                                                       \
            printf("Assertion Failed: %s\n\tin file %s, line %i\n\tfunction: %s", #condition, __FILE__, __LINE__, \
                   __PRETTY_FUNCTION__);                                                                          \
            __debugbreak();                                                                                       \
        }                                                                                                         \
    }
#else
#define TOBOT_ASSERT(x)
#endif
} // namespace Tobot::Tooling::Debug