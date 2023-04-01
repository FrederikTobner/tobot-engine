#pragma once

// C standard library dependecies
#include <string.h>

// C++ standard library dependecies
#include <iostream>

// OS specific dependecies
#if defined(OS_WINDOWS)
#include <windows.h>
// Has to come after windows.h dependency
#include <psapi.h>
#elif defined(OS_UNIX_LIKE)
#include <unistd.h>
#endif
