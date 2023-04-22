add_executable("${PROJECT_NAME}-editor" main.cpp)

target_link_libraries("${PROJECT_NAME}-editor" imgui SDL2::SDL2main SDL2::SDL2-static)

target_include_directories("${PROJECT_NAME}-editor" PUBLIC 
${PROJECT_SOURCE_DIR}/deps/imgui/imgui_dir 
${PROJECT_SOURCE_DIR}/deps/imgui/imgui_dir/backends 
${PROJECT_SOURCE_DIR}/deps/SDL/include)

# Copies window icon into the build folder
FILE(COPY assets/icon.bmp DESTINATION "${CMAKE_BINARY_DIR}/editor/assets")

# Copies font into the build folder
FILE(COPY fonts/Roboto-Medium.ttf DESTINATION "${CMAKE_BINARY_DIR}/editor/fonts")

if(NOT CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
    # Install destinations
    install(TARGETS ${PROJECT_NAME} DESTINATION editor)
    # Adding window icon
    install(FILES ${PROJECT_SOURCE_DIR}/assets/icon.bmp DESTINATION editor/assets)
    # Adding font
    install(FILES ${PROJECT_SOURCE_DIR}/fonts/Roboto-Medium.ttf DESTINATION editor/fonts)
endif()
