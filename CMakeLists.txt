cmake_minimum_required(VERSION 3.18.0)
# We need to build a target with name of the project i fear
project(tobot-core VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD 99)
set(C_STANDARD_REQUIRED TRUE)

option(BUILD_CORE_SHARED "Building the core library as DLL" OFF)
option(BUILD_SDL "Buidling SDL" ON)

get_filename_component(SOURCE_PATH_CORE ${PROJECT_SOURCE_DIR}/packages/tobot_core/src ABSOLUTE)
get_filename_component(SOURCE_PATH_MATH ${PROJECT_SOURCE_DIR}/packages/tobot_math/src ABSOLUTE)
get_filename_component(SOURCE_PATH_TEST ${PROJECT_SOURCE_DIR}/packages/tobot_test/src ABSOLUTE)
get_filename_component(SOURCE_PATH_TOOLING ${PROJECT_SOURCE_DIR}/packages/tobot_tooling/src ABSOLUTE)

add_compile_definitions(LOGS_FOLDER_PATH="${PROJECT_SOURCE_DIR}/logs/")

# enabling tests
enable_testing()
# building packages
add_subdirectory(packages)

if(BUILD_SDL)
    # SDL2 deps
    add_subdirectory(deps/SDL)
    add_subdirectory(deps/SDL_image)
    add_subdirectory(deps/SDL_ttf)
    add_subdirectory(deps/SDL_mixer)
endif()

# Doesn't work if we build the lib as a dll for some reason
if(NOT BUILD_CORE_SHARED)
    # Tobot Engine Example
    add_subdirectory(example)
endif()