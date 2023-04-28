#pragma once

#include "SDL.h"
#include "imgui_impl_sdl2.h"

namespace Tobot::Editor {

void handleEvents(SDL_Event & event, bool & done, SDL_Window * window);

} // namespace Tobot::Editor