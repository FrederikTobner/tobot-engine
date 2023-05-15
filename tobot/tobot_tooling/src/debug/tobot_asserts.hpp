/**
 * @file tobot_asserts.h
 * @brief Contains test macro's regarding assertions
 */

#pragma once

#include "../pre_compiled_header.hpp"

namespace Tobot::Tooling::Debug {
    // Asserts are only defined for debug builds

#if defined(COMPILER_MSVC)
/* MSVC does not include the path by default */ /**Filename macro - filename without the path */ \
#define __PRETTY_FILE__                                                                          \
    __FILE__
#else
/* Clang and GCC display the full path by default */ /**Filename macro - filename without the path */                  \
#define __PRETTY_FILE__ \
    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

/*
 * Check if the compiler supports a given builtin.
 * Supported by virtually all clang versions and recent gcc.
 */
#ifdef __has_builtin
/** Macro that checks for a builtin if the compiler supports it */ \
#define TOBOT_HAS_BUILTIN(x)                                       \
    __has_builtin(x)
#else
/** Macro that checks for a builtin if the compiler supports it */                       \
#define TOBOT_HAS_BUILTIN(x) \
    0
#endif

/*
 * Determine the compiler or architecture in order to find a way to trigger a breakpoint.
 */
#if defined(COMPILER_MSVC)
/* Breakpoints using MSVC */ /**Custom breakpoint macro*/ \
#define TOBOT_Breakpoint()                                \
    __debugbreak()
#elif TOBOT_HAS_BUILTIN(__builtin_debugtrap)
/* Breakpoints using recent versions of clang and gcc */ /**Custom breakpoint macro*/ \
#define TOBOT_Breakpoint()                    \
    __builtin_debugtrap()
#elif ((!defined(__NACL__)) &&                                                                              \
       ((defined(COMPILER_GCC) || defined(COMPILER_CLANG)) && (defined(__i386__) || defined(__x86_64__))))
/* Breakpoints on x86 architecture */ /**Custom breakpoint macro*/ \
#define TOBOT_Breakpoint()                                                                                  \
    __asm__ __volatile__("int $3\n\t")
#elif (defined(__APPLE__) && (defined(__arm64__) || defined(__aarch64__)))
/* Breakpoints on ARM64-bit architecture */ /**Custom breakpoint macro*/ \
#define TOBOT_Breakpoint()                                                  \
    __asm__ __volatile__("brk #22\n\t")
#elif defined(__APPLE__) && defined(__arm__)
/* Breakpoints on ARM32-bit architecture */ /**Custom breakpoint macro*/ \
#define TOBOT_Breakpoint()                    \
    __asm__ __volatile__("bkpt #22\n\t")
#elif defined(__386__) && defined(__WATCOMC__)
/* Breakpoints on older x86 Architecture or on the Watcom C/C++ compiler */ /**Custom breakpoint macro*/ \
#define TOBOT_Breakpoint()                      \
    {                                           \
        _asm { int 0x03 }                       \
    }
#else
/* No breakpoints possible under this architecture and compiler at the moment*/ /**Custom breakpoint macro*/ \
#define TOBOT_Breakpoint()
#endif

/*
 *Breakpoints are only defined for debug builds
 */
#if BUILD_TYPE_DEBUG
/** Custom assert macro */                                                                                   \
#define TOBOT_ASSERT(condition)                                                                              \
    {                                                                                                        \
        static_assert(sizeof(#condition) > 1, "A condition needs to be specified");                          \
        if (!(condition)) {                                                                                  \
            std::cout << "Assertion Failed: " << #condition << "\n\tin file" << __PRETTY_FILE__ << ", line " \
                      << __LINE__ << "\n\tfunction: " << __PRETTY_FUNCTION__ << "\n";                        \
            /* Trigger a breakpoint */                                                                       \
            TOBOT_Breakpoint();                                                                              \
        }                                                                                                    \
    }
#else
                                                         /** Custom assert macro */ \
#define TOBOT_ASSERT(condition)
#endif
} // namespace Tobot::Tooling::Debug