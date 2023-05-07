/// @file event_handler.cpp
/// @brief Contains definitions regarding the event handler of the editor

#include "event_handler.hpp"

#include "imgui_impl_sdl2.h"

using namespace Tobot::Editor;

/// @brief Constructs a new event handler
/// @param done The boolean to set to true if the user wants to quit
/// @param window The window to handle events for
EventHandler::EventHandler(bool & done, SDL_Window * window) : done(done), window(window) {
}

/// @brief Handle events from SDL
/// @param event The event to handle
/// @param done The boolean to set to true if the user wants to quit
/// @param window The window to handle events for
auto EventHandler::handleEvents() -> void {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);
        if (event.type == SDL_QUIT) {
            done = true;
        } else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE &&
                   event.window.windowID == SDL_GetWindowID(window)) {
            done = true;
        }
    }
}