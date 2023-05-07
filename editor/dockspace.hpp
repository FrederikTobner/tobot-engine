/// @file dockspace.hpp
/// @brief Contains declarations regarding the dockspace of the editor

#pragma once

#include "imgui.h"

namespace Tobot::Editor {

    class Dockspace {

        public:
            /// @brief Constructs a new dockspace
            /// @param show_demo_window Boolean that determines if the demo window should be shown
            /// @param show_tobot_about Boolean that determines if the about window should be shown
            /// @param show_another_window Boolean that determines if the another window should be shown
            /// @param io The ImGuiIO object
            /// @param scenePosition The position of the scene
            /// @param sceneWindowSize The size of the scene window
            Dockspace(bool & show_tobot_about, ImGuiIO & io, ImVec2 & scenePosition, ImVec2 & sceneWindowSize);
            /// @brief Renders the dockspace
            auto render() -> void;

        private:
            bool & show_tobot_about;
            ImGuiIO & io;
            ImVec2 & scenePosition;
            ImVec2 & sceneWindowSize;
            ImGuiViewport * viewport;
    };

} // namespace Tobot::Editor