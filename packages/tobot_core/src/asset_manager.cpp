#include "asset_manager.h"
#include "tobot_tooling.h"

#include "SDL_image.h"

using namespace Tobot::Core;

SDL_Surface * Tobot::Core::AssetManager::loadTextureScurface(char const * path) {
    SDL_Surface * surface = IMG_Load(path);
    if (!surface) {
        LOG_CRITICAL("Failed to load Texture %s\n", IMG_GetError());
        return nullptr;
    }

    return surface;
}

SDL_Texture * Tobot::Core::AssetManager::loadTexture(char const * path, SDL_Renderer * renderer) {
    SDL_Surface * surface = IMG_Load(path);
    if (!surface) {
        LOG_CRITICAL("Failed to load Texture %s\n", IMG_GetError());
        return nullptr;
    }
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}