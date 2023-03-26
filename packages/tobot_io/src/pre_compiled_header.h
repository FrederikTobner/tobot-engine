#pragma once

#if defined(OS_WINDOWS)
#include <windows.h>
// Has to come after windows.h dependency
#include <psapi.h>
#elif defined(OS_UNIX_LIKE)
#include <unistd.h>
#endif
#include <iostream>
#include <string.h>
