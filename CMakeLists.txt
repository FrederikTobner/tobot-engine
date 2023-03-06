cmake_minimum_required(VERSION 3.18.0)
project(tobot-engine VERSION 1.0.0 LANGUAGES CXX)

# Adding compile definitions (used OS, compiler, build type and the logs folder path)
include(./cmake/tobot_detect.cmake)
Tobot_Detect_Platform()
Tobot_Detect_Compiler()
if(CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
  add_compile_definitions(BUILD_TYPE_DEBUG)
endif()
add_compile_definitions(LOGS_FOLDER_PATH="${PROJECT_SOURCE_DIR}/logs/")

set(CMAKE_CXX_STANDARD 17)

get_filename_component(SOURCEPATH ${PROJECT_SOURCE_DIR}/src ABSOLUTE)

add_subdirectory(src)

# include google test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# googletest tests
add_subdirectory(tests)

# SDL2 deps
add_subdirectory(deps/SDL)
add_subdirectory(deps/SDL_image)
add_subdirectory(deps/SDL_ttf)
add_subdirectory(deps/SDL_mixer)

# Tobot Engine Example
add_subdirectory(example)