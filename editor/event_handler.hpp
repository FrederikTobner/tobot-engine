/// @file event_handler.hpp
/// @brief Contains declarations regarding the event handler of the editor

#pragma once

#include "SDL.h"

namespace Tobot::Editor {

    auto handleEvents(SDL_Event & event, bool & done, SDL_Window * window) -> void;

} // namespace Tobot::Editor