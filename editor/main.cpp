/// @file main.cpp
/// @brief Contains the main entry point for the editor

#include "SDL.h"
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer.h"

#include <stdio.h>

// Tobot core dependencies
#include "exitcode.hpp"
#include "sub_system_manager.hpp"

// Internal dependencies
#include "color_picker.hpp"
#include "dockspace.hpp"
#include "event_handler.hpp"
#include "icons_material_design.hpp"
#include "menu_bar.hpp"
#include "scene_renderer.hpp"
#include "toolbar.hpp"

#if !SDL_VERSION_ATLEAST(2, 0, 17)
#error This backend requires SDL 2.0.17+ because of SDL_RenderGeometry() function
#endif

/// @brief Main entry point
/// @param argc The number of arguments
/// @param argv The arguments
/// @return 0 on success, -1 on failure
auto main(int argc, char ** argv) -> int {
    // Seting up SDL using the Tobot core
    if (Tobot::Core::subSystemsInitialize(Tobot::Core::SDL_CORE_INIT_VIDEO | Tobot::Core::SDL_CORE_INIT_TIMER |
                                          Tobot::Core::SDL_CORE_INIT_GAMECONTROLLER) != 0) {
        std::cout << "Error: " << SDL_GetError() << "\n";
        return Tobot::Core::ExitCode::SOFTWARE.getCode();
    }

    // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif

    // Create window with SDL_Renderer graphics context
    SDL_WindowFlags window_flags =
        (SDL_WindowFlags)(SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_VULKAN | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE);
    SDL_Window * window =
        SDL_CreateWindow("Tobot-Editor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, window_flags);
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
    // Loading the scene texture - This should be the whole scene later
    SDL_Surface * sceneSurface = SDL_LoadBMP(IMAGE_LOCATION);
    SDL_Texture * sceneTexture = SDL_CreateTextureFromSurface(renderer, sceneSurface);
    SDL_FreeSurface(sceneSurface);

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

    // Adding the roboto font as the default font
    io.Fonts->AddFontFromFileTTF(ROBOTO_FONT_LOCATION, 16.0f);

    // Adding the material icons font and merging it with the current font (Roboto)
    ImFontConfig config;
    config.MergeMode = true;
    const ImWchar icon_ranges[] = {(ImWchar)ICON_MIN_MD, (ImWchar)ICON_MAX_MD, (ImWchar)0};
    io.Fonts->AddFontFromFileTTF(MATERIAL_ICONS_FONT_LOCATION, 20.0f, &config, icon_ranges);

    // Our state
    bool show_tobot_about = false;
    bool show_color_picker = false;
    bool done = false;

    ImVec2 scenePosition, sceneWindowSize;
    // Creating the scene renderer
    Tobot::Editor::SceneRenderer sceneRenderer(renderer, scenePosition, sceneWindowSize);
    // Creating the toolbar
    Tobot::Editor::Toolbar toolbar;
    // Creating the menu bar
    Tobot::Editor::MenuBar menuBar(done, show_tobot_about, show_color_picker);
    // Creating the event handler
    Tobot::Editor::EventHandler eventHandler(done, window);

    Tobot::Editor::Dockspace dockspace(show_tobot_about, io, scenePosition, sceneWindowSize);

    Tobot::Editor::ColorPicker colorPicker(show_color_picker);

    // Main loop
    while (!done) {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use
        // your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or
        // clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or
        // clear/overwrite your copy of the keyboard data. Generally you may always pass all inputs to dear imgui,
        // and hide them from your application based on those two flags.
        eventHandler.handleEvents();

        // Start the Dear ImGui frame
        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        menuBar.render();
        toolbar.render();
        dockspace.render();
        colorPicker.render();

        // Rendering
        ImGui::Render();
        SDL_RenderSetScale(renderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());

        sceneRenderer.render(sceneTexture);

        SDL_RenderPresent(renderer);
    }

    // Cleanup
    ImGui_ImplSDLRenderer_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    // Destroying the scene texture - we should probably create a ressource pool later so we don't have to do this
    // manually for every texture
    SDL_DestroyTexture(sceneTexture);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return Tobot::Core::ExitCode::OK.getCode();
}