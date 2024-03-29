configure_file(project_config.hpp.in project_config.hpp)

set(TOBOT_CORE_SOURCES
"asset_manager.cpp"
"exitcode.cpp"
"game_entity.cpp"
"layer.cpp"
"scene.cpp"
"scene_manager.cpp"
"string_hash.cpp"
"sub_system_manager.cpp"
"tobot_application.cpp"
"tobot_texture.cpp"
"transform2D.cpp"
)

set(TOBOT_CORE_HEADERS
"asset_manager.hpp"
"concepts.hpp"
"entry_point.hpp"
"exitcode.hpp"
"layer.hpp"
"game_entity.hpp"
"scene.hpp"
"scene_manager.hpp"
"string_hash.hpp"
"sub_system_manager.hpp"
"tobot_application.hpp"
"tobot_texture.hpp"
"transform2D.hpp"
)

if(CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
  add_compile_definitions(BUILD_TYPE_DEBUG)
endif()

if(BUILD_CORE_SHARED)
  add_library(tobot-core SHARED ${TOBOT_CORE_SOURCES} ${TOBOT_CORE_HEADERS})
else()
  add_library(tobot-core STATIC ${TOBOT_CORE_SOURCES} ${TOBOT_CORE_HEADERS})
endif()

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

target_include_directories(tobot-core PUBLIC ./ ../../../deps/SDL/include ../../../deps/SDL_image/ ../../../deps/SDL_mixer/include ../../../deps/SDL_ttf/ ../../../deps/SDL_net/)

target_link_libraries(tobot-core SDL2::SDL2main SDL2::SDL2-static SDL2_image::SDL2_image-static SDL2_ttf::SDL2_ttf-static SDL2_net::SDL2_net-static SDL2_mixer::SDL2_mixer-static tobot-tooling tobot-math tobot-data-structures)

# for including the project_config.h file
target_include_directories(tobot-core PUBLIC ${PROJECT_BINARY_DIR}/packages/tobot_core/src ${SOURCE_PATH_TOOLING}/include ${SOURCE_PATH_MATH}/include ${SOURCE_PATH_DATA_STRUCTURES}/include)

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-core PUBLIC pre_compiled_header.hpp pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-core PUBLIC pre_compiled_header.hpp)
endif()

if(NOT CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
    # Sets properties for the package created using cpack
    set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_NAME} The tobot game engine")

    # Can we specify the packages here?
    set(CPACK_BUILD_SOURCE_DIRS "${PROJECT_BINARY_DIR}/tobot_engine/src")
    # Setting the project version
    set(CPACK_PACKAGE_VERSION "${tobot-engine_VERSION_MAJOR}.${tobot-engine_VERSION_MINOR}.${tobot-engine_VERSION_PATCH}")
    # Add our license as resouce
    set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")
    
    include(CPack)
    install(TARGETS ${PROJECT_NAME} DESTINATION lib)
endif()