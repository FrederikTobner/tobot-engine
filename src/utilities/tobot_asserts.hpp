#pragma once

#include "logger.hpp"

// Asserts are only defined for debug builds
#ifdef _DEBUG
    #define TOBOT_ASSERT(x) { if(!(x)) { LOG_ERROR_AT("Assertion Failed: %s", #x); __debugbreak(); } }
#else
    #define TOBOT_ASSERT(x)
#endif