cmake_minimum_required(VERSION 3.18.0)
project(tobot-engine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

get_filename_component(SOURCEPATH ${PROJECT_SOURCE_DIR}/src ABSOLUTE)

add_compile_definitions(LOGS_FOLDER_PATH="${PROJECT_SOURCE_DIR}/logs/")

add_subdirectory(src)

# googletest tests
add_subdirectory(tests)

# SDL2 deps
add_subdirectory(deps/SDL)
add_subdirectory(deps/SDL_image)
add_subdirectory(deps/SDL_ttf)
add_subdirectory(deps/SDL_mixer)

# Tobot Engine Example
add_subdirectory(example)