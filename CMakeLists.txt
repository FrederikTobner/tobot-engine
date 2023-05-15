cmake_minimum_required(VERSION 3.18.0)
project(tobot-engine VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD 99)
set(C_STANDARD_REQUIRED TRUE)

option(INCLUDE_DEPS "Include external dependencies" ON)
option(BUILD_TESTS "Build the unit tests" ON)

# Forcing static linking of the libraries - dirty fix for building all SDL libraries as static libraries
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

include(CheckIncludeFile)

# Checking the dependencies of the project - we should do this for every library instead to make them a seperate entity. 
# But in general we should minimize the amount of os-specific code in the libraries by utilizing the c++ standard library more
# Therefor we can wait a little bit longer to do this
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

# Adding compile definitions (used OS and compiler) - we should do this for every library to make them a seperate entity 
# But then we would need to move cmake folder there as well :(
# So we should probably only do that if we really want to use compiler specific features and have to use os-specific code
include(cmake/tobot_detect.cmake)
Tobot_Detect_Platform()
Tobot_Detect_Compiler()

add_compile_definitions(LOGS_FOLDER_PATH="${PROJECT_SOURCE_DIR}/logs/")

# building tobot libraries
add_subdirectory(tobot)

# For testing the project we currently don't need the editor and the dependencies - at least not for now
if(INCLUDE_DEPS)
    # SDL2 deps and imgui
   add_subdirectory(deps)
   # We can only build the editor if SDL and imgui have been built
   add_subdirectory(editor)
   # We can only build the example if SDL and imgui have been built
   add_subdirectory(example)
endif()



