#include "tobot_application.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "utilities/logger.h"
#include "project_config.h"

using namespace Tobot::Core;

void TobotApplication::initialize()
{
    LOG_INFO("%s version %s.%s.%s", PROJECT_NAME, PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH);
    // Initialize SDL subsystems
    if (InitializeSDLSubsystems(SDL_CORE_INIT_EVERYTHING | SDL_IMAGE_INIT_PNG | SDL_TTF_INIT | SDL_MIXER_INIT_MP3)) {
        exit(70);
    }
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

int Tobot::Core::InitializeSDLSubsystems(uint32_t flags)
{
    uint32_t sdl_core_init_flags;
    if (flags & SDL_CORE_INIT_TIMER)
        sdl_core_init_flags &= SDL_INIT_TIMER;
    if (flags & SDL_CORE_INIT_AUDIO)
        sdl_core_init_flags &= SDL_INIT_AUDIO;     
    if (flags & SDL_CORE_INIT_VIDEO)
        sdl_core_init_flags &= SDL_INIT_VIDEO;
    if (flags & SDL_CORE_INIT_JOYSTICK)
        sdl_core_init_flags &= SDL_INIT_JOYSTICK;
    if (flags & SDL_CORE_INIT_HAPTIC)
        sdl_core_init_flags &= SDL_INIT_HAPTIC;    
    if (flags & SDL_CORE_INIT_GAMECONTROLLER)
        sdl_core_init_flags &= SDL_INIT_GAMECONTROLLER;
    if (flags & SDL_CORE_INIT_EVENTS)
        sdl_core_init_flags &= SDL_INIT_EVENTS;    
    if (flags & SDL_CORE_INIT_SENSOR)
        sdl_core_init_flags &= SDL_INIT_SENSOR;
    if (SDL_Init(sdl_core_init_flags) < 0)                                           
    {                                                                           
        LOG_CRITICAL("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());    
        return -1;                                                               
    }    
    
    uint32_t sdl_image_init_flags = 0;
    if (flags & SDL_IMAGE_INIT_JPG)
        sdl_image_init_flags |= IMG_INIT_JPG;
    if (flags & SDL_IMAGE_INIT_PNG)
        sdl_image_init_flags |= IMG_INIT_PNG;
    if (flags & SDL_IMAGE_INIT_TIF)
        sdl_image_init_flags |= IMG_INIT_PNG;
    if (flags & SDL_IMAGE_INIT_WEBP)
        sdl_image_init_flags |= IMG_INIT_WEBP;
    if (flags & SDL_IMAGE_INIT_JXL)
        sdl_image_init_flags |= IMG_INIT_JXL;
    if (flags & SDL_IMAGE_INIT_AVIF)
        sdl_image_init_flags |= IMG_INIT_AVIF;    
    if (IMG_Init(sdl_image_init_flags) < 0)                                           
    {                                                                           
        LOG_CRITICAL("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;                                                               
    }

    if (flags & SDL_TTF_INIT)
    {
        if (TTF_Init()) {
			LOG_CRITICAL("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
            IMG_Quit();
            SDL_Quit();
            return -1;
        }
	}

    uint32_t sdl_mixxer_init_flags = 0;
    if (flags & SDL_MIXER_INIT_FLAC)
        sdl_mixxer_init_flags |= MIX_INIT_FLAC;
    if (flags & SDL_MIXER_INIT_MID)
        sdl_mixxer_init_flags |= MIX_INIT_MID;
    if (flags & SDL_MIXER_INIT_MOD)
        sdl_mixxer_init_flags |= MIX_INIT_MOD;
    if (flags & SDL_MIXER_INIT_MP3)
        sdl_mixxer_init_flags |= MIX_INIT_MP3;
    if (flags & SDL_MIXER_INIT_OGG)
        sdl_mixxer_init_flags |= MIX_INIT_OGG;
    if (flags & SDL_MIXER_INIT_OPUS)
        sdl_mixxer_init_flags |= MIX_INIT_OPUS;
    if (flags & SDL_MIXER_INIT_WAVPACK)
        sdl_mixxer_init_flags |= MIX_INIT_WAVPACK;
    if (!Mix_Init(sdl_mixxer_init_flags)) {
        LOG_CRITICAL( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        if (flags & SDL_TTF_INIT)
            TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return -1;
    }
    return 0;
}
