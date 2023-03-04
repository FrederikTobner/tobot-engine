#include "farscape_application.h"

using namespace Farscape::Core;

void FarscapeApplication::initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3);
    this->p_Window = SDL_CreateWindow("Farscape", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    this->p_Renderer = SDL_CreateRenderer(this->p_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    this->m_Running = true;
}

void FarscapeApplication::run()
{
    while (this->m_Running)
    {
        this->handleEvents();
        this->update();
        this->render();
    }
    this->quit();
}

void FarscapeApplication::handleEvents()
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

        default:
            break;
        }
    }
}

void FarscapeApplication::update()
{
}

void FarscapeApplication::render()
{
    SDL_SetRenderDrawColor(this->p_Renderer, 0, 0, 0, 0);
    SDL_RenderClear(this->p_Renderer);

    SDL_RenderPresent(this->p_Renderer);
}

void FarscapeApplication::quit()
{
    SDL_DestroyRenderer(this->p_Renderer);
    SDL_DestroyWindow(this->p_Window);
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}

FarscapeApplication *FarscapeApplication::getInstance()
{
    if (sp_Instance == 0)
    {
        sp_Instance = new FarscapeApplication();
    }

    return sp_Instance;
}
