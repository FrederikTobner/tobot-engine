# Adding compile definitions (used OS, compiler, build type and the logs folder path)
include(../cmake/tobot_detect.cmake)
Tobot_Detect_Platform()
Tobot_Detect_Compiler()

add_subdirectory(tobot_data_structures)

add_subdirectory(tobot_io)

add_subdirectory(tobot_lang)

add_subdirectory(tobot_math)

add_subdirectory(tobot_tooling)

add_subdirectory(tobot_test)

# building main project
if(BUILD_SDL)
add_subdirectory(tobot_core)
endif()
