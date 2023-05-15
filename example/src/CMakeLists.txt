set(SOURCES
"example.cpp"
)

add_executable("${PROJECT_NAME}_Example" ${SOURCES})

target_link_libraries("${PROJECT_NAME}_Example" PUBLIC ${PROJECT_NAME})

target_include_directories("${PROJECT_NAME}_Example" PUBLIC ../../tobot/tobot_core/src/include ../../tobot/tobot_tooling/src/include ../../tobot/tobot_math/src/include)

# SDL dependencies
target_include_directories("${PROJECT_NAME}_Example" PUBLIC ../../deps/SDL/include ../../deps/SDL_image ../../deps/SDL_mixer/include ../../deps/SDL_ttf)

# Copies assets to the build dir
FILE(COPY ../assets/inspirational_picture.png DESTINATION "${CMAKE_BINARY_DIR}/example/src/assets")
FILE(COPY ../assets/main_menu_background.png DESTINATION "${CMAKE_BINARY_DIR}/example/src/assets")
FILE(COPY ../assets/Player_Gold.png DESTINATION "${CMAKE_BINARY_DIR}/example/src/assets")
FILE(COPY ../assets/Weapon_Parazoinium.png DESTINATION "${CMAKE_BINARY_DIR}/example/src/assets")
