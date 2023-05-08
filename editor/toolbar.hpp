/// @file toolbar.hpp
/// @brief Contains declarations regarding the toolbar for the editor

#pragma once

#include "imgui.h"

namespace Tobot::Editor {
    class Toolbar {
        public:
            Toolbar();

            auto render() -> void;

        private:
            // The viewport of the toolbar
            ImGuiViewport * viewport;
    };
} // namespace Tobot::Editor