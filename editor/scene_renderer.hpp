/// @file scene_renderer.hpp
/// @brief Contains declarations regarding the scene renderer for the editor

#pragma once

#include "SDL.h"
#include "imgui.h"

namespace Tobot::Editor {

    class SceneRenderer {
        public:
            SceneRenderer(SDL_Renderer * renderer, ImVec2 & scenePosition, ImVec2 & sceneWindowSize);

            auto render(SDL_Texture * sceneTexture) -> void;

        private:
            // The renderer for the scene
            SDL_Renderer * renderer;
            // The position of the scene window
            ImVec2 & scenePosition;
            // The size of the scene window
            ImVec2 & sceneWindowSize;
    };
} // namespace Tobot::Editor