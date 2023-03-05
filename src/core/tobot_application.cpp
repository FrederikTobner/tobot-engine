#include "tobot_application.h"

#include "utilities/logger.h"
#include "project_config.h"

using namespace Tobot::Core;

void TobotApplication::initialize()
{
    LOG_INFO("%s version %s.%s.%s", PROJECT_NAME, PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH);
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        LOG_CRITICAL("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());    
        exit(70);
    }
    if (!IMG_Init(IMG_INIT_PNG)) {
        LOG_CRITICAL("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        SDL_Quit();
        exit(70);
    }
    if (TTF_Init()) {
        LOG_CRITICAL("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        IMG_Quit();
        SDL_Quit();      
        exit(70);
    }
    if (!Mix_Init(MIX_INIT_MP3)) {
        LOG_CRITICAL("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();   
        exit(70);
    }
    this->p_Window = SDL_CreateWindow(applicationName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, displayWidth, displayHeight, SDL_WINDOW_SHOWN);
    this->p_Renderer = SDL_CreateRenderer(this->p_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    this->m_Running = true;
}

void TobotApplication::run()
{
    while (this->m_Running)
    {
        this->handleEvents();
        this->update();
        this->render();
    }
    delete this;
}

void TobotApplication::handleEvents()
{
    SDL_Event ev;
    while (SDL_PollEvent(&ev))
    {
        switch (ev.type)
        {
        case SDL_QUIT:
            this->m_Running = false;
            break;

        case SDL_KEYUP:
            if (SDL_SCANCODE_ESCAPE == ev.key.keysym.scancode)
            {
                this->m_Running = false;
            }
            break;

        // TODO: let client application handle some of the events
        default:
            break;
        }
    }
}

void TobotApplication::update()
{
}

// virtual constructor
TobotApplication::TobotApplication()
{
    this->initialize();
}

// virtual destructor
TobotApplication::~TobotApplication()
{
    this->quit();
}

void TobotApplication::render()
{
    SDL_SetRenderDrawColor(this->p_Renderer, 0, 0, 0, 0);
    SDL_RenderClear(this->p_Renderer);
    SDL_RenderPresent(this->p_Renderer);
}

void TobotApplication::quit()
{
    SDL_DestroyRenderer(this->p_Renderer);
    SDL_DestroyWindow(this->p_Window);
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}
