/**
 * @file pre_compiled_header.h
 * @brief Precompiled dependecies of the library
 */

#pragma once

// C standard library dependecies
#include <stdio.h>

// C++ standard library dependecies
#include <ctime>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>

// OS specific dependecies
#ifdef OS_WINDOWS
#include <windows.h>
#endif