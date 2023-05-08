/// @file scene_renderer.cpp
/// @brief Contains definitions regarding the scene renderer for the editor

#include "scene_renderer.hpp"

using namespace Tobot::Editor;

SceneRenderer::SceneRenderer(SDL_Renderer * renderer, ImVec2 & scenePosition, ImVec2 & sceneWindowSize)
    : renderer(renderer), scenePosition(scenePosition), sceneWindowSize(sceneWindowSize) {
}

auto SceneRenderer::render(SDL_Texture * sceneTexture) -> void {
    // Drawing a texture in the scene window for testing - This texture should be the whole scene later

    // To place the texture in the center of the screen we need to know the position of the size of the scene window
    SDL_Rect rect = {(int)scenePosition.x, (int)scenePosition.y, (int)sceneWindowSize.x, (int)sceneWindowSize.y};
    SDL_RenderCopy(renderer, sceneTexture, NULL, &rect);
}