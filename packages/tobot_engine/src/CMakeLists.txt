configure_file(project_config.h.in project_config.h)

set(TOBOT_ENGINE_SOURCES
"core/asset_manager.cpp"
"core/exitcode.cpp"
"core/game_entity.cpp"
"core/render_object.cpp"
"core/scene.cpp"
"core/tobot_application.cpp"
)

set(TOBOT_ENGINE_HEADERS
"entry_point.h"
"core/asset_manager.h"
"core/exitcode.h"
"core/game_entity.h"
"core/render_object.h"
"core/scene.h"
"core/scene_manager.h"
"core/tobot_application.h"
"utilities/concepts.h"
"widget/text.h"
)

# Adding compile definitions (used OS, compiler, build type and the logs folder path)
include(../../../cmake/tobot_detect.cmake)
Tobot_Detect_Platform()
Tobot_Detect_Compiler()
if(CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
  add_compile_definitions(BUILD_TYPE_DEBUG)
endif()

add_library(${PROJECT_NAME} ${TOBOT_ENGINE_SOURCES} ${TOBOT_ENGINE_HEADERS})

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

target_include_directories(${PROJECT_NAME} PUBLIC ./)

target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2-static SDL2_image::SDL2_image-static SDL2_ttf::SDL2_ttf-static SDL2_mixer::SDL2_mixer-static tobot-tooling tobot-math)

# for including the project_config.h file
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR}/packages/tobot_engine/src ${PROJECT_SOURCE_DIR}/packages/tobot_tooling/src/include ${PROJECT_SOURCE_DIR}/packages/tobot_math/src/include)

if(NOT CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
    # Sets properties for the package created using cpack
    set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_NAME} The tobot game engine")

    # Can we specify the packages here?
    set(CPACK_BUILD_SOURCE_DIRS "${PROJECT_BINARY_DIR}/tobot_engine/src")
    # Setting the project version
    set(CPACK_PACKAGE_VERSION "${tobot-engine_VERSION_MAJOR}.${tobot-engine_VERSION_MINOR}.${tobot-engine_VERSION_PATCH}")
    # Add our license as resouce
    set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")
    
    include(CPack)
    install(TARGETS ${PROJECT_NAME} DESTINATION lib)
endif()