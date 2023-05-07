/**
 * @file pre_compiled_header.h
 * @brief Precompiled dependecies of the library
 */

#pragma once

// C standard library dependecies
#include <stdio.h>
#include <string.h>

// C++ standard library dependecies
#include <atomic>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>

// C++ standard library dependecies from the C library
#include <ctime>

// OS specific dependecies
#ifdef OS_WINDOWS
#include <windows.h>
#endif