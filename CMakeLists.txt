cmake_minimum_required(VERSION 3.18.0)
# We need to build a target with name of the project i fear
project(tobot-core VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD 99)
set(C_STANDARD_REQUIRED TRUE)

option(BUILD_CORE_SHARED "Building the core library as DLL" OFF)
option(INCLUDE_DEPS "Include external dependencies" ON)
option(BUILD_TESTS "Build the unit tests" ON)

include(CheckIncludeFile)

# Checking the dependencies of the project - we should do this for every library instead to make them a seperate entity
if(UNIX)
    # Check dependecies under unix-like systems   
    CHECK_INCLUDE_FILE("unistd.h" UNISTD_AVAILABLE)    
    if(NOT ${UNISTD_AVAILABLE})
        message(FATAL_ERROR "unistd.h is required to build the project under unix-like systems. Please make sure it is available to the compiler and try again after that")
    endif() # unistd.h
elseif(WIN32)
    # Check dependecies under windows
    CHECK_INCLUDE_FILE("windows.h" WINDOWS_AVAILABLE)
    CHECK_INCLUDE_FILE("psapi.h" PSAPI_AVAILABLE)
    if(NOT ${WINDOWS_AVAILABLE})
        message(FATAL_ERROR "windows.h is required to build the project under windows. Please make sure it is available to the compiler and try again after that")
    endif() # windows.h
    if(NOT ${PSAPI_AVAILABLE})
        message(FATAL_ERROR "psapi.h is required to build the project under windows. Please make sure it is available to the compiler and try again after that")
    endif() # psapi.h
endif()

add_compile_definitions(LOGS_FOLDER_PATH="${PROJECT_SOURCE_DIR}/logs/")

# enabling tests - should probably be done for every library as well so we can test them seperately
if(BUILD_TESTS)
    enable_testing()
endif()
# building tobot libraries
add_subdirectory(tobot)

# For testing the project we currently don't need the editor and the dependencies - at least not for now
if(INCLUDE_DEPS)
    # SDL2 deps and imgui
   add_subdirectory(deps)
   # We can only build the editor if SDL and imgui have been built
   add_subdirectory(editor)
endif()



# Doesn't work if we build the library as a dll for some reason - probably because we forced to use static linking before
if(NOT BUILD_CORE_SHARED)
    # Tobot Engine Example
    add_subdirectory(example)
endif()
