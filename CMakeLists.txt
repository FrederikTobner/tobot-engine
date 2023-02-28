cmake_minimum_required(VERSION 3.18.0)
project(project-farscape VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "" FORCE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "" FORCE)

add_subdirectory(src)
add_subdirectory(deps/SDL)
add_subdirectory(deps/SDL_image)