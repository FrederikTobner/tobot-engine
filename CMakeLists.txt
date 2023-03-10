cmake_minimum_required(VERSION 3.18.0)
project(tobot-engine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

get_filename_component(SOURCEPATH ${PROJECT_SOURCE_DIR}/tobot_engine/src ABSOLUTE)

add_compile_definitions(LOGS_FOLDER_PATH="${PROJECT_SOURCE_DIR}/logs/")

# enabling tests
enable_testing()
# building tooiling project
add_subdirectory(tobot_tooling)
# building main project
add_subdirectory(tobot_engine)

# SDL2 deps
add_subdirectory(deps/SDL)
add_subdirectory(deps/SDL_image)
add_subdirectory(deps/SDL_ttf)
add_subdirectory(deps/SDL_mixer)

# Tobot Engine Example
add_subdirectory(example)