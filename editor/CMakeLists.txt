set(TOBOT_EDITOR_SOURCE_FILES
dockspace.cpp
event_handler.cpp
main.cpp
menu_bar.cpp
scene_renderer.cpp
toolbar.cpp
)

set(TOBOT_EDITOR_HEADER_FILES
icons_material_design.h
dockspace.h
event_handler.h
menu_bar.h
scene_renderer.h
toolbar.h
)

add_executable("${PROJECT_NAME}-editor" ${TOBOT_EDITOR_SOURCE_FILES} ${TOBOT_EDITOR_HEADER_FILES})

target_link_libraries("${PROJECT_NAME}-editor" imgui ${PROJECT_NAME})

target_include_directories("${PROJECT_NAME}-editor" PUBLIC 
${PROJECT_SOURCE_DIR}/deps/imgui/imgui_dir 
${PROJECT_SOURCE_DIR}/deps/imgui/imgui_dir/backends 
${PROJECT_SOURCE_DIR}/deps/SDL/include
${PROJECT_SOURCE_DIR}/packages/tobot_core/src)

# Copies window icon into the build folder
FILE(COPY assets/icon.bmp DESTINATION "${CMAKE_BINARY_DIR}/editor/assets")

# Copies font into the build folder
FILE(COPY fonts/Roboto-Medium.ttf DESTINATION "${CMAKE_BINARY_DIR}/editor/fonts")
FILE(COPY fonts/MaterialIcons-Regular.ttf DESTINATION "${CMAKE_BINARY_DIR}/editor/fonts")

# Works only if we use the absolute path for some reason on the docking branch of imgui
add_compile_definitions(IMAGE_LOCATION="${CMAKE_BINARY_DIR}/editor/assets/icon.bmp" ROBOTO_FONT_LOCATION="${CMAKE_BINARY_DIR}/editor/fonts/Roboto-Medium.ttf" MATERIAL_ICONS_FONT_LOCATION="${CMAKE_BINARY_DIR}/editor/fonts/MaterialIcons-Regular.ttf")

if(NOT CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
    # Install destinations
    install(TARGETS "${PROJECT_NAME}-editor" DESTINATION editor)
    # Adding window icon
    install(FILES ${PROJECT_SOURCE_DIR}/assets/icon.bmp DESTINATION editor/assets)
    # Adding font
    install(FILES ${PROJECT_SOURCE_DIR}/fonts/Roboto-Medium.ttf DESTINATION editor/fonts)
endif()
