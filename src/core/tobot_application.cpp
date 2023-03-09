#include "tobot_application.h"

#include "utilities/logger.h"
#include "project_config.h"
#include "edl/edl_initializer.h"

using namespace Tobot::Core;

void TobotApplication::initialize()
{
    LOG_INFO("%s version %s.%s.%s", PROJECT_NAME, PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH);
    // Initialize SDL subsystems
    if (Tobot::EDL::EDLInitializerInitialize(Tobot::EDL::SDL_CORE_INIT_EVERYTHING | 
                                                Tobot::EDL::SDL_IMAGE_INIT_PNG | 
                                                Tobot::EDL::SDL_TTF_INIT | 
                                                Tobot::EDL::SDL_MIXER_INIT_MP3))
        exit(70);
    this->p_Window = SDL_CreateWindow(applicationName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, displayWidth, displayHeight, SDL_WINDOW_SHOWN);
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
