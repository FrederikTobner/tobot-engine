#pragma once

#include "SDL.h"

namespace Tobot::Core {
    class AssetManager {
        public:
            static SDL_Surface * loadTextureScurface(char const * path);
            static SDL_Texture * loadTexture(char const * path, SDL_Renderer * renderer);
    };
} // namespace Tobot::Core
