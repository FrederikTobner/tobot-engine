#include "tobot_application.h"

#include "exitcode.h"
#include "project_config.h"
#include "scene_manager.h"
#include "sub_system_manager.h"
#include "tobot_tooling.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

using namespace Tobot::Core;
using namespace Tobot::Tooling::Logging;

// virtual constructor
TobotApplication::TobotApplication(char const * name) : m_ApplicationName(name) {
}

// virtual destructor
TobotApplication::~TobotApplication() {
    this->quit();
}

void TobotApplication::initialize() {
    LOG_INFO("%s version %s.%s.%s", PROJECT_NAME, PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH);
    LOG_INFO("\n  _______    _           _     ______             _            \n\
 |__   __|  | |         | |   |  ____|           (_)           \n\
    | | ___ | |__   ___ | |_  | |__   _ __   __ _ _ _ __   ___ \n\
    | |/ _ \\| '_ \\ / _ \\| __| |  __| | '_ \\ / _` | | '_ \\ / _ \\\n\
    | | (_) | |_) | (_) | |_  | |____| | | | (_| | | | | |  __/\n\
    |_|\\___/|_.__/ \\___/ \\__| |______|_| |_|\\__, |_|_| |_|\\___|\n\
                                             __/ |             \n\
                                            |___/              ");
    // Initialize SDL subsystems
    if (subSystemsInitialize(SDL_CORE_INIT_EVERYTHING | SDL_IMAGE_INIT_PNG | SDL_TTF_INIT | SDL_MIXER_INIT_MP3)) {
        exit(ExitCode::SOFTWARE.getCode());
    }
    this->p_Window = SDL_CreateWindow(this->m_ApplicationName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                      this->m_DisplaySize.width, this->m_DisplaySize.height, SDL_WINDOW_SHOWN);
    this->p_Renderer = SDL_CreateRenderer(this->p_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    this->m_Running = true;

    // TODO: Maybe call call this when onApplicationCreate will be a thing
    this->p_CurrentScene->onCreate();
    this->p_CurrentScene->prepareTextures(this->p_Renderer);
}

void TobotApplication::run() {
    while (this->m_Running) {
        this->handleEvents();
        this->update();
        this->render();
    }
}

void TobotApplication::handleEvents() {

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

void TobotApplication::update() {
    this->p_CurrentScene->update();
}

void Tobot::Core::TobotApplication::setInitialScene(Scene * scene) {
    this->p_CurrentScene = scene;
}

void TobotApplication::render() {
    /// TODO: Scene specific background color with enums, reusable in logger maybe?
    SDL_SetRenderDrawColor(this->p_Renderer, 0, 0, 0, 0);
    SDL_RenderClear(this->p_Renderer);

    this->p_CurrentScene->render(this->p_Renderer);

    SDL_RenderPresent(this->p_Renderer);
}

void TobotApplication::quit() {

    this->p_CurrentScene->onDestroy();

    SDL_DestroyRenderer(this->p_Renderer);
    SDL_DestroyWindow(this->p_Window);
    subSystemsQuit();
}