/// @file event_handler.hpp
/// @brief Contains declarations regarding the event handler of the editor

#pragma once

#include "SDL.h"

namespace Tobot::Editor {

    class EventHandler {
        public:
            EventHandler(bool & done, SDL_Window * window);

            auto handleEvents() -> void;

        private:
            // Determines if the user wants to quit
            bool & done;
            SDL_Window * window;
    };

} // namespace Tobot::Editor