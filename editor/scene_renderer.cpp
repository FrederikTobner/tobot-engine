#include "scene_renderer.h"

auto Tobot::Editor::sceneRendererMain(SDL_Renderer * renderer, ImVec2 scenePosition, ImVec2 sceneWindowSize) -> void {
    // Drawing a texture in the scene window for testing - This texture should be the whole scene later
    SDL_Surface * window_icon_scurface = SDL_LoadBMP(IMAGE_LOCATION);
    SDL_Texture * texture1 = SDL_CreateTextureFromSurface(renderer, window_icon_scurface);
    SDL_FreeSurface(window_icon_scurface);
    // To place the texture in the center of the screen we need to know the position of the size of the scene window
    SDL_Rect rect = {(int)scenePosition.x, (int)scenePosition.y, (int)sceneWindowSize.x, (int)sceneWindowSize.y};
    SDL_RenderCopy(renderer, texture1, NULL, &rect);
}