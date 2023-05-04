#pragma once

// C standard library dependecies
#include <stdint.h>
#include <stdio.h>
#include <string.h>


// C++ standard library dependecies
#include <iostream>

// OS specific dependecies
#if defined(OS_WINDOWS)
#include <windows.h>
// Has to come after windows.h dependency
#include <psapi.h>
#elif defined(OS_UNIX_LIKE)
#include <dirent.h>
#include <unistd.h>
#endif

// Linux specific dependencies
#ifdef OS_LINUX
#include <sys/stat.h>
#include <sys/types.h>

#endif
