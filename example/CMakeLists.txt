# Just for testing the core library
set(SOURCES
"example.cpp"
)

add_executable(tobot-core-example ${SOURCES})

target_link_libraries(tobot-core-example PUBLIC tobot-core)

target_include_directories(tobot-core-example PUBLIC ../tobot/tobot_core/src/include ../tobot/tobot_tooling/src/include ../tobot/tobot_math/src/include)

# SDL dependencies
target_include_directories(tobot-core-example PUBLIC ../deps/SDL/include ../deps/SDL_image ../deps/SDL_mixer/include ../deps/SDL_ttf)

# Copies assets to the build dir
FILE(COPY ./assets/inspirational_picture.png DESTINATION "${CMAKE_BINARY_DIR}/example/assets")
FILE(COPY ./assets/main_menu_background.png DESTINATION "${CMAKE_BINARY_DIR}/example/assets")
FILE(COPY ./assets/Player_Gold.png DESTINATION "${CMAKE_BINARY_DIR}/example/assets")
FILE(COPY ./assets/Weapon_Parazoinium.png DESTINATION "${CMAKE_BINARY_DIR}/example/assets")