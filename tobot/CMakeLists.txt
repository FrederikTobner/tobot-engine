add_subdirectory(tobot_data_structures)

add_subdirectory(tobot_lang)

add_subdirectory(tobot_math)

add_subdirectory(tobot_tooling)

# building main project - because it does not include any tests we dont build it when we are testing the project (speeds up github workflow)
if(INCLUDE_DEPS)
    add_subdirectory(tobot_core)
endif()
