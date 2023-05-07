set(TOBOT_MATH_HEADER_FILES
"concepts.hpp"
"dimension.hpp"
"gradient2D.hpp"
"matrix.hpp"
"plane.hpp"
"point2d.hpp"
"include/tobot_math.hpp"
"shape/circle.hpp"
"shape/polygon.hpp"
"shape/rectangle.hpp"
"shape/triangle.hpp"
"vector/vector.hpp"
"vector/vector2d.hpp"
"vector/vector3d.hpp"
"vector/vector4d.hpp"
)

add_library(tobot-math INTERFACE)
target_sources(tobot-math INTERFACE ${TOBOT_MATH_HEADER_FILES})
set_target_properties(tobot-math PROPERTIES LINKER_LANGUAGE CXX)

# Includes Libmath under unix-like systems
if(UNIX)
    target_link_libraries(tobot-math INTERFACE m)
endif()

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-math INTERFACE pre_compiled_header.hpp pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-math INTERFACE pre_compiled_header.hpp)
endif()
