#pragma once

#include "SDL.h"

namespace Tobot::Editor {

    void handleEvents(SDL_Event & event, bool & done, SDL_Window * window);

} // namespace Tobot::Editor