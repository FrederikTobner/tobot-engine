/// @file dockspace.h
/// @brief Contains declarations regarding the dockspace of the editor

#pragma once

#include "imgui.h"

namespace Tobot::Editor {

    /// @brief The functionalty of the dockspace
    /// @param show_demo_window Boolean that determines if the demo window should be shown
    /// @param show_tobot_help Boolean that determines if the help window should be shown
    /// @param show_another_window Boolean that determines if the another window should be shown
    /// @param clear_color The color to clear the window with
    /// @param io The ImGuiIO object
    /// @param scenePosition The position of the scene
    /// @param sceneWindowSize The size of the scene window
    /// @return void
    auto dockSpaceMain(bool & show_demo_window, bool & show_tobot_help, bool & show_another_window, ImGuiIO & io,
                       ImVec2 & scenePosition, ImVec2 & sceneWindowSize) -> void;

} // namespace Tobot::Editor