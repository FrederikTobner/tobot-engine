#include "event_handler.h"

#include "imgui_impl_sdl2.h"

/// @brief Handle events from SDL
/// @param event The event to handle
/// @param done The boolean to set to true if the user wants to quit
/// @param window The window to handle events for
void Tobot::Editor::handleEvents(SDL_Event & event, bool & done, SDL_Window * window) {
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);
        if (event.type == SDL_QUIT) {
            done = true;
        }
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE &&
            event.window.windowID == SDL_GetWindowID(window)) {
            done = true;
        }
    }
}