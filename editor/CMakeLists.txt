set(TOBOT_EDITOR_SOURCE_FILES
event_handler.cpp
main.cpp
menu_bar.cpp
)

set(TOBOT_EDITOR_HEADER_FILES
event_handler.h
menu_bar.h
)

add_executable("${PROJECT_NAME}-editor" ${TOBOT_EDITOR_SOURCE_FILES} ${TOBOT_EDITOR_HEADER_FILES})

target_link_libraries("${PROJECT_NAME}-editor" imgui ${PROJECT_NAME})

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
    install(TARGETS "${PROJECT_NAME}-editor" DESTINATION editor)
    # Adding window icon
    install(FILES ${PROJECT_SOURCE_DIR}/assets/icon.bmp DESTINATION editor/assets)
    # Adding font
    install(FILES ${PROJECT_SOURCE_DIR}/fonts/Roboto-Medium.ttf DESTINATION editor/fonts)
endif()
