#include "tobot_application.hpp"

// Tobot dependencies
#include "exitcode.hpp"
#include "project_config.hpp"
#include "scene_manager.hpp"
#include "sub_system_manager.hpp"

#include "tobot_tooling.hpp"

// SDL dependencies
#include "SDL.h"

using namespace Tobot::Core;
using namespace Tobot::Tooling;

TobotApplication::TobotApplication(char const * name) : m_ApplicationName(name) {
}

// virtual destructor
TobotApplication::~TobotApplication() {
    this->quit();
}

auto TobotApplication::initialize() -> void {
    LOG_INFO("%s version %s.%s.%s", PROJECT_NAME, PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH);
    LOG_INFO("\n  _______    _           _     ______             _            \n\
 |__   __|  | |         | |   |  ____|           (_)           \n\
    | | ___ | |__   ___ | |_  | |__   _ __   __ _ _ _ __   ___ \n\
    | |/ _ \\| '_ \\ / _ \\| __| |  __| | '_ \\ / _` | | '_ \\ / _ \\\n\
    | | (_) | |_) | (_) | |_  | |____| | | | (_| | | | | |  __/\n\
    |_|\\___/|_.__/ \\___/ \\__| |______|_| |_|\\__, |_|_| |_|\\___|\n\
                                             __/ |             \n\
                                            |___/");
    // Initialize SDL subsystems - we need to adapt this so we initialize all the subsystems that are needed without any
    // unnecassary subsystems. For now we could just initialize all of them. But this would increase the startup time of
    // the application.
    if (subSystemsInitialize(SDL_CORE_INIT_VIDEO | SDL_IMAGE_INIT_PNG | SDL_TTF_INIT | SDL_MIXER_INIT_MP3)) {
        exit(ExitCode::SOFTWARE.getCode());
    }
    this->p_Window = SDL_CreateWindow(this->m_ApplicationName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                      this->m_DisplaySize.width, this->m_DisplaySize.height, SDL_WINDOW_SHOWN);
    // The framerate should be configurable - vsync should be an option not the default
    // Additionally we let SDL guess which driver to use for the renderer (e.g. direct3d, direct3d11, direct3d12,
    // opengl or software)
    this->p_Renderer = SDL_CreateRenderer(this->p_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    this->m_Running = true;

    // TODO: Maybe call this when onApplicationCreate will be a thing
    this->p_CurrentScene->onCreate();
    this->p_CurrentScene->prepareTextures(this->p_Renderer);
}

auto TobotApplication::run() -> void {
    while (this->m_Running) {
        this->handleEvents();
        this->update();
        this->render();
    }
}

auto TobotApplication::handleEvents() -> void {

    /// If a scene was loaded by the user prepare it for rendering
    if (!Tobot::Core::SceneManager::sp_SceneStack.empty()) {

        // Destroy the previous scene for now: Configurable caching should be the future
        this->p_CurrentScene->onDestroy();

        // Pop the latest scene create it
        this->p_CurrentScene = Tobot::Core::SceneManager::sp_SceneStack.top();
        this->p_CurrentScene->onCreate();
        this->p_CurrentScene->prepareTextures(this->p_Renderer);

        Tobot::Core::SceneManager::sp_SceneStack.pop();
    }

    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
        case SDL_QUIT:
            this->m_Running = false;
            break;

        case SDL_KEYUP:
            if (SDL_SCANCODE_ESCAPE == sdlEvent.key.keysym.scancode) {
                this->m_Running = false;
            }
            break;

        // TODO: let client application handle some of the events
        default:
            break;
        }
    }
}

auto TobotApplication::update() -> void {
    this->p_CurrentScene->update();
}

auto Tobot::Core::TobotApplication::setInitialScene(Scene * scene) -> void {
    this->p_CurrentScene = scene;
}

auto TobotApplication::render() -> void {
    /// TODO: Scene specific background color with enums, reusable in logger maybe?
    SDL_SetRenderDrawColor(this->p_Renderer, 0, 0, 0, 0);
    SDL_RenderClear(this->p_Renderer);

    this->p_CurrentScene->render(this->p_Renderer);
    SDL_RenderPresent(this->p_Renderer);
}

auto TobotApplication::quit() -> void {

    this->p_CurrentScene->onDestroy();

    SDL_DestroyRenderer(this->p_Renderer);
    SDL_DestroyWindow(this->p_Window);
    subSystemsQuit();
}