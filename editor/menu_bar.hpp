/// @file menu_bar.hpp
/// @brief Contains declarations regarding the menu bar for the editor

#pragma once

namespace Tobot::Editor {

    /// @brief Create the menu bar for the editor
    /// @param done Determines if the user wants to quit
    /// @param show_tobot_help Determines if the user wants to see the help for Tobot
    auto menuBarMain(bool & done, bool & show_tobot_help) -> void;
} // namespace Tobot::Editor