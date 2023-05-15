cmake_minimum_required(VERSION 3.18.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(NOT DEFINED BUILD_TESTS)
option(BUILD_TESTS "Build the unit tests" ON)
endif()

add_subdirectory(src)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()