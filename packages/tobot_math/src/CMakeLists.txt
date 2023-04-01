set(TOBOT_MATH_HEADER_FILES
"concepts.h"
"dimension.h"
"vector/vector.h"
"vector/vector2d.h"
"vector/vector3d.h"
"vector/vector4d.h"
"matrix.h"
"include/tobot_math.h"
)

add_library(tobot-math INTERFACE)
target_sources(tobot-math INTERFACE ${TOBOT_MATH_HEADER_FILES})
set_target_properties(tobot-math PROPERTIES LINKER_LANGUAGE CXX)

# Includes Libmath under unix-like systems
if(UNIX)
    target_link_libraries(tobot-math m)
endif()

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-math INTERFACE pre_compiled_header.h pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-math INTERFACE pre_compiled_header.h)
endif()
