add_executable(${PROJECT_NAME} main.cpp)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2-static SDL2_image::SDL2_image-static SDL2_ttf::SDL2_ttf-static)