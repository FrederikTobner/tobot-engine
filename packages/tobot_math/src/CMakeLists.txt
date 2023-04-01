set(TOBOT_MATH_SOURCE_FILES
"dimension.cpp"
)

set(TOBOT_MATH_HEADER_FILES
"concepts.h"
"dimension.h"
"vector2d.h"
"vector3d.h"
"vector4d.h"
"matrix.h"
"include/tobot_math.h"
)

add_library(tobot-math STATIC ${TOBOT_MATH_SOURCE_FILES} ${TOBOT_MATH_HEADER_FILES})

# Includes Libmath under unix-like systems
if(UNIX)
    target_link_libraries(tobot-math m)
endif()

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-math PUBLIC pre_compiled_header.h pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-math PUBLIC pre_compiled_header.h)
endif()
