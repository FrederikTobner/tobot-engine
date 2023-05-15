# We should probably declare a project, cmake minimum version, the C (if needed) and C++ standards and add some options here as well. 
# For the project declaration we dont need to refactor all uses of the previously defined project name if we are still calling the top project tobot-core.
# Maybe we could name the editor "tobot" instead of "tobot-editor", so we are still building a target with that name and then rename the top project to tobot.
# For now we could just ignore the project declaration because that will only emit a warning and not an error, if we are only building a sublibrary.
# If there are not defined already we can use the same defauult values as in the main CMakeLists.txt file. This can be done with if(DEFINED MY_OPTION)
# Otherwise we should use the values defined in the main CMakeLists.txt file.
# Additionally we should move our include-checks here as well and make sure the header file checks that we do are properly done. 
# By checking if all os-specifc dependencies the precompiled header file needs are available.
# E.g. checking for psapi.h and windows.h and so on
# We can further study the CMake setup of SDL, because they are not just a bunch of unexperienced idiots :)
add_subdirectory(src)
if(BUILD_TESTS)
    enable_testing()    
    add_subdirectory(test)
endif()