#include "asset_manager.h"
#include "utilities/logger.h"

#include "SDL_image.h"

using namespace Tobot::Core;

SDL_Surface * Tobot::Core::AssetManager::loadTexture(const char * path) {
    SDL_Surface * surface = IMG_Load(path);
    if (!surface) {
        LOG_CRITICAL("Failed to load Texture %s\n", IMG_GetError());
        return nullptr;
    }

    return surface;
}
