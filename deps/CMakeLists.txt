# Saving the original value of the BUILD_SHARED_LIBS variable
set(SHARED_LIBS_ORIGINAL ${BUILD_SHARED_LIBS})
# Forcing static linking of the libraries - dirty fix for building all SDL libraries as static libraries
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

# SDL2 dependencies
add_subdirectory(SDL)
add_subdirectory(SDL_image)
add_subdirectory(SDL_mixer)
add_subdirectory(SDL_net)
add_subdirectory(SDL_ttf)

# Resetting the BUILD_SHARED_LIBS variable
set(BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS})

# ImGui
add_subdirectory(imgui)
