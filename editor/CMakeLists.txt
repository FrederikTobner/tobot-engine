add_executable(${PROJECT_NAME}-editor main.cpp)

target_link_libraries(${PROJECT_NAME}-editor imgui SDL2::SDL2main SDL2::SDL2-static)

target_include_directories(${PROJECT_NAME}-editor PUBLIC ${PROJECT_SOURCE_DIR}/deps/imgui/imgui_dir ${PROJECT_SOURCE_DIR}/deps/imgui/imgui_dir/backends ${PROJECT_SOURCE_DIR}/deps/SDL/include)