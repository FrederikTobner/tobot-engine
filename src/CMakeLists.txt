configure_file(project_config.h.in project_config.h)

set(TOBOT_ENGINE_SOURCES
core/render_object.cpp
core/tobot_application.cpp
core/view.cpp
utilities/logger.cpp
)

set(TOBOT_ENGINE_HEADERS
entry_point.hpp
core/render_object.h
core/tobot_application.h
core/view.h
utilities/logger.hpp
utilities/tobot_asserts.hpp
math/vector2d.h
widget/text.h
)

add_library(${PROJECT_NAME} ${TOBOT_ENGINE_SOURCES} ${TOBOT_ENGINE_HEADERS})

set(BUILD_SHARED_LIBS OFF)

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