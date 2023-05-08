/// @file menu_bar.hpp
/// @brief Contains declarations regarding the menu bar for the editor

#pragma once

namespace Tobot::Editor {

    class MenuBar {
        public:
            MenuBar(bool & done, bool & show_tobot_about, bool & show_color_picker);

            auto render() -> void;

        private:
            // Determines if the user wants to quit
            bool & done;
            // Determines if the user wants to see the help for Tobot
            bool & show_tobot_about;
            // Determines if the user wants to see the color picker
            bool & show_color_picker;
    };
} // namespace Tobot::Editor