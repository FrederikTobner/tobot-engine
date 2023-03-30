set(TOBOT_MATH_SOURCE_FILES
"dimension.cpp"
"vector2d.cpp"
)

set(TOBOT_MATH_HEADER_FILES
"concepts.h"
"dimension.h"
"vector2d.h"
"matrix.h"
"include/tobot_math.h"
)

add_library(tobot-math STATIC ${TOBOT_MATH_SOURCE_FILES} ${TOBOT_MATH_HEADER_FILES})
