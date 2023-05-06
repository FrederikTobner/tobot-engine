/// @file asset_manager.hpp
/// @brief Contains declarations regarding the asset manager of the engine

#pragma once

#include "SDL.h"

namespace Tobot::Core {
    class AssetManager {
        public:
            static auto loadTextureScurface(char const * path) -> SDL_Surface *;
            static auto loadTexture(char const * path, SDL_Renderer * renderer) -> SDL_Texture *;
    };
} // namespace Tobot::Core
