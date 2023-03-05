cmake_minimum_required(VERSION 3.18.0)
project(tobot-engine VERSION 1.0.0 LANGUAGES CXX)

include(./cmake/tobot_detect_platform.cmake)
Tobot_Detect_Platform()
add_compile_definitions(
    LOGS_FOLDER_PATH="${PROJECT_SOURCE_DIR}/logs/"
)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(src)
add_subdirectory(deps/SDL)
add_subdirectory(deps/SDL_image)
add_subdirectory(deps/SDL_ttf)
add_subdirectory(deps/SDL_mixer)

add_subdirectory(example)