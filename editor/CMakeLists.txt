# The editor is what the user will use to create their game - therefore it is the main product of the project and simply called tobot-engine
set(TOBOT_EDITOR_SOURCE_FILES
color_picker.cpp
dockspace.cpp
event_handler.cpp
main.cpp
menu_bar.cpp
scene_renderer.cpp
toolbar.cpp
)

set(TOBOT_EDITOR_HEADER_FILES
color_picker.hpp
dockspace.hpp
event_handler.hpp
icons_material_design.hpp
menu_bar.hpp
scene_renderer.hpp
toolbar.hpp
)

add_executable(${PROJECT_NAME} ${TOBOT_EDITOR_SOURCE_FILES} ${TOBOT_EDITOR_HEADER_FILES})

target_link_libraries(${PROJECT_NAME} imgui tobot-core)

target_include_directories(${PROJECT_NAME} PUBLIC 
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

# Works only if we use the absolute path for some reason on the docking branch of imgui
add_compile_definitions(IMAGE_LOCATION="${CMAKE_BINARY_DIR}/editor/assets/icon.bmp" FONT_LOCATION="${CMAKE_BINARY_DIR}/editor/fonts/Roboto-Medium.ttf")

if(NOT CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
    include(CPack)
    # Setting the package name
    set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
    # Setting the package description
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_NAME} The tobot game engine")

    # Setting the build source directory
    set(CPACK_BUILD_SOURCE_DIRS "${PROJECT_BINARY_DIR}/editor")
    # Setting the project version
    set(CPACK_PACKAGE_VERSION "${tobot-engine_VERSION_MAJOR}.${tobot-engine_VERSION_MINOR}.${tobot-engine_VERSION_PATCH}")
    # Add our license as resouce
    set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")

    # Install destinations
    install(TARGETS ${PROJECT_NAME} DESTINATION bin)
    # Adding window icon
    install(FILES ${PROJECT_SOURCE_DIR}/assets/icon.bmp DESTINATION editor/assets)
    # Adding font
    install(FILES ${PROJECT_SOURCE_DIR}/fonts/Roboto-Medium.ttf DESTINATION editor/fonts)
endif()
