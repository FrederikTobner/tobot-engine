/// @file scene_renderer.hpp
/// @brief Contains declarations regarding the scene renderer for the editor

#pragma once

#include "SDL.h"
#include "imgui.h"

namespace Tobot::Editor {
    auto sceneRendererMain(SDL_Renderer * renderer, ImVec2 scenePosition, ImVec2 sceneWindowSize,
                           SDL_Texture * sceneTexture) -> void;
}