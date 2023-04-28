set(SOURCES
"example.cpp"
)

add_executable("${PROJECT_NAME}_Example" ${SOURCES})

target_link_libraries("${PROJECT_NAME}_Example" PUBLIC ${PROJECT_NAME})

target_include_directories("${PROJECT_NAME}_Example" PUBLIC "${SOURCE_PATH_CORE}/include" "${SOURCE_PATH_TOOLING}/include/" "${SOURCE_PATH_MATH}/include/")

# SDL dependencies
target_include_directories("${PROJECT_NAME}_Example" PUBLIC ../../deps/SDL/include ../../deps/SDL_image ../../deps/SDL_mixer/include ../../deps/SDL_ttf)

# Copies assets to the build dir
FILE(COPY ../assets/inspirational_picture.png DESTINATION "${CMAKE_BINARY_DIR}/example/src/assets")
FILE(COPY ../assets/main_menu_background.png DESTINATION "${CMAKE_BINARY_DIR}/example/src/assets")
FILE(COPY ../assets/Player_Gold.png DESTINATION "${CMAKE_BINARY_DIR}/example/src/assets")
FILE(COPY ../assets/Weapon_Parazoinium.png DESTINATION "${CMAKE_BINARY_DIR}/example/src/assets")