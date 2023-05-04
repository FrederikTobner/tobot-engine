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

get_filename_component(SOURCE_PATH_CORE ${PROJECT_SOURCE_DIR}/packages/tobot_core/src ABSOLUTE)
get_filename_component(SOURCE_PATH_DATA_STRUCTURES ${PROJECT_SOURCE_DIR}/packages/tobot_data_structures/src ABSOLUTE)
get_filename_component(SOURCE_PATH_IO ${PROJECT_SOURCE_DIR}/packages/tobot_io/src ABSOLUTE)
get_filename_component(SOURCE_PATH_LANG ${PROJECT_SOURCE_DIR}/packages/tobot_lang/src ABSOLUTE)
get_filename_component(SOURCE_PATH_MATH ${PROJECT_SOURCE_DIR}/packages/tobot_math/src ABSOLUTE)
get_filename_component(SOURCE_PATH_TEST ${PROJECT_SOURCE_DIR}/packages/tobot_test/src ABSOLUTE)
get_filename_component(SOURCE_PATH_TOOLING ${PROJECT_SOURCE_DIR}/packages/tobot_tooling/src ABSOLUTE)

# enabling tests
enable_testing()
# building packages
add_subdirectory(packages)

if(INCLUDE_DEPS)
    # SDL2 deps and imgui
   add_subdirectory(deps)
   # We can only build the editor if SDL and imgui have been built
   add_subdirectory(editor)
endif()



# Doesn't work if we build the lib as a dll for some reason
if(NOT BUILD_CORE_SHARED)
    # Tobot Engine Example
    add_subdirectory(example)
endif()
