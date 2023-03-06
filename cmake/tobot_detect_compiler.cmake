macro(Tobot_Detect_Compiler)
    if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
        add_compile_definitions(COMPILER_GCC)
    elseif(CMAKE_C_COMPILER_ID STREQUAL "Clang")
        add_compile_definitions(COMPILER_CLANG)
    elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
        add_compile_definitions(COMPILER_MSVC)
    elseif (CMAKE_C_COMPILER_ID STREQUAL "Intel")
        add_compile_definitions(COMPILER_INTEL)
    else()
        add_compile_definitions(COMPILER_UNKNOWN)
    endif()    
endmacro(Tobot_Detect_Compiler)