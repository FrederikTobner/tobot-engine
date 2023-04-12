#pragma once

#include "SDL.h"

namespace Tobot::Core {
    class AssetManager {
        public:
            static SDL_Surface * loadTexture(char const * path);
    };
} // namespace Tobot::Core
