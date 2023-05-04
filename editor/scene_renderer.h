#pragma once

#include "SDL.h"
#include "imgui.h"

namespace Tobot::Editor {
    auto sceneRendererMain(SDL_Renderer * renderer, ImVec2 scenePosition, ImVec2 sceneWindowSize) -> void;
}