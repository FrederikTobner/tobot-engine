#pragma once

#include "SDL.h"

namespace Tobot::Editor {

    auto handleEvents(SDL_Event & event, bool & done, SDL_Window * window) -> void;

} // namespace Tobot::Editor