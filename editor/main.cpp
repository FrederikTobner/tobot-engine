#include "SDL.h"
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer.h"

#include <stdio.h>

// Tobot core dependencies
#include "exitcode.h"
#include "sub_system_manager.h"

// Internal dependencies
#include "dockspace.h"
#include "event_handler.h"
#include "menu_bar.h"
#include "toolbar.h"

#if !SDL_VERSION_ATLEAST(2, 0, 17)
#error This backend requires SDL 2.0.17+ because of SDL_RenderGeometry() function
#endif

using namespace Tobot::Core;

/// @brief Main entry point
/// @param argc The number of arguments
/// @param argv The arguments
/// @return 0 on success, -1 on failure
auto main(int argc, char ** argv) -> int {
    // Seting up SDL using the Tobot core
    if (subSystemsInitialize(SDL_CORE_INIT_VIDEO | SDL_CORE_INIT_TIMER | SDL_CORE_INIT_GAMECONTROLLER) != 0) {
        std::cout << "Error: " << SDL_GetError() << "\n";
        return ExitCode::SOFTWARE.getCode();
    }

    // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif

    // Create window with SDL_Renderer graphics context
    SDL_WindowFlags window_flags =
        (SDL_WindowFlags)(SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_VULKAN | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE);
    SDL_Window * window =
        SDL_CreateWindow("Tobot-Editor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1800, 1000, window_flags);
    SDL_Surface * window_icon_scurface = SDL_LoadBMP(IMAGE_LOCATION);
    if (!window_icon_scurface) {
        std::cout << "Failed to load window icon " << SDL_GetError() << " from " << IMAGE_LOCATION << "\n";
        return Tobot::Core::ExitCode::SOFTWARE.getCode();
    }
    // Setting the icon of the window
    SDL_SetWindowIcon(window, window_icon_scurface);
    SDL_FreeSurface(window_icon_scurface);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Error creating SDL_Renderer!");
        return Tobot::Core::ExitCode::OK.getCode();
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO & io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // Enable Multi-Viewport / Platform Windows

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer_Init(renderer);
    io.Fonts->AddFontFromFileTTF(FONT_LOCATION, 16.0f);

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    bool show_tobot_help = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    ImVec2 scenePosition, sceneWindowSize;

    // Main loop
    bool done = false;
    while (!done) {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use
        // your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or
        // clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or
        // clear/overwrite your copy of the keyboard data. Generally you may always pass all inputs to dear imgui,
        // and hide them from your application based on those two flags.
        SDL_Event event;
        Tobot::Editor::handleEvents(event, done, window);

        // Start the Dear ImGui frame
        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        Tobot::Editor::menuBarMain(done, show_tobot_help);

        // 1. Toolbar
        { Tobot::Editor::toolBarMain(); }

        // 2. DockSpace
        {
            Tobot::Editor::dockSpaceMain(show_demo_window, show_tobot_help, show_another_window, clear_color, io,
                                         scenePosition, sceneWindowSize);
        }

        // Rendering
        ImGui::Render();
        SDL_RenderSetScale(renderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
        SDL_SetRenderDrawColor(renderer, (uint8_t)(clear_color.x * 255), (uint8_t)(clear_color.y * 255),
                               (uint8_t)(clear_color.z * 255), (uint8_t)(clear_color.w * 255));

        SDL_RenderClear(renderer);
        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());

        // Drawing a texture in the scene window for testing - This texture should be the whole scene later
        SDL_Surface * window_icon_scurface = SDL_LoadBMP(IMAGE_LOCATION);
        SDL_Texture * texture1 = SDL_CreateTextureFromSurface(renderer, window_icon_scurface);
        SDL_FreeSurface(window_icon_scurface);
        // To place the texture in the center of the screen we need to know the position of the size of the scene window
        SDL_Rect rect = {(int)scenePosition.x, (int)scenePosition.y, (int)sceneWindowSize.x, (int)sceneWindowSize.y};
        SDL_RenderCopy(renderer, texture1, NULL, &rect);

        SDL_RenderPresent(renderer);
    }

    // Cleanup
    ImGui_ImplSDLRenderer_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return ExitCode::OK.getCode();
}