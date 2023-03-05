configure_file(project_config.h.in project_config.h)

set(PROJECT_FARSCAPE_SOURCES
utilities/logger.cpp
core/render_object.cpp
core/farscape_application.cpp
core/view.cpp
main.cpp
)

set(PROJECT_FARSCAPE_HEADERS
utilities/logger.hpp
core/render_object.h
core/farscape_application.h
core/view.h
)

add_compile_definitions(
    LOGS_FOLDER_PATH="${PROJECT_SOURCE_DIR}/logs/"
)

include(../cmake/farscape_detect_platform.cmake)
Farscape_Detect_Platform()

add_executable(${PROJECT_NAME} ${PROJECT_FARSCAPE_SOURCES} ${PROJECT_FARSCAPE_HEADERS})

set(BUILD_SHARED_LIBS OFF)

target_include_directories(${PROJECT_NAME} PUBLIC ./)

target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2-static SDL2_image::SDL2_image-static SDL2_ttf::SDL2_ttf-static SDL2_mixer::SDL2_mixer-static)

# for including the project_config.h file
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR}/src)

if(NOT CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
    # Sets properties for the package created using cpack
    set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_NAME} A game made with SDL in space")
    set(CPACK_BUILD_SOURCE_DIRS "${PROJECT_BINARY_DIR}/src")
    
    include(CPack)
    install(TARGETS ${PROJECT_NAME} DESTINATION bin)
endif()