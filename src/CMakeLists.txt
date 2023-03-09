configure_file(project_config.h.in project_config.h)

set(TOBOT_ENGINE_SOURCES
"core/render_object.cpp"
"edl/edl_initializer.cpp"
"core/tobot_application.cpp"
"core/view.cpp"
"utilities/logger.cpp"
)

set(TOBOT_ENGINE_HEADERS
"entry_point.h"
"core/render_object.h"
"edl/edl_initializer.h"
"core/tobot_application.h"
"core/view.h"
"utilities/logger.h"
"utilities/tobot_asserts.h"
"math/vector2d.h"
"widget/text.h"
)

# Adding compile definitions (used OS, compiler, build type and the logs folder path)
include(../cmake/tobot_detect.cmake)
Tobot_Detect_Platform()
Tobot_Detect_Compiler()
if(CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
  add_compile_definitions(BUILD_TYPE_DEBUG)
endif()

add_library(${PROJECT_NAME} ${TOBOT_ENGINE_SOURCES} ${TOBOT_ENGINE_HEADERS})

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

target_include_directories(${PROJECT_NAME} PUBLIC ./)

target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2-static SDL2_image::SDL2_image-static SDL2_ttf::SDL2_ttf-static SDL2_mixer::SDL2_mixer-static)

# for including the project_config.h file
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR}/src)

if(NOT CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
    # Sets properties for the package created using cpack
    set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_NAME} A game engine")
    set(CPACK_BUILD_SOURCE_DIRS "${PROJECT_BINARY_DIR}/src")
    
    include(CPack)
    install(TARGETS ${PROJECT_NAME} DESTINATION bin)
endif()