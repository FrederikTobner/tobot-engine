set(TOBOT_MATH_SOURCE_FILES
"vector2d.cpp"
"dimension.cpp"
)

set(TOBOT_MATH_HEADER_FILES
"vector2d.h"
"dimension.h"
"concepts.h"
"include/tobot_math.h"
)

add_library(tobot-math STATIC ${TOBOT_MATH_SOURCE_FILES} ${TOBOT_MATH_HEADER_FILES})
