add_subdirectory(tobot_tooling)

add_subdirectory(tobot_math)

add_subdirectory(tobot_test)

# building main project
if(BUILD_SDL)
add_subdirectory(tobot_core)
endif()
