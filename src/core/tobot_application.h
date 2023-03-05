#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include "view.h"

#include <iostream>
#include <unordered_map>

namespace Tobot::Core
{
    class TobotApplication
    {
    private:
        inline static TobotApplication *sp_Instance = 0;

        SDL_Window *p_Window;
        SDL_Renderer *p_Renderer;

        std::unordered_map<const char *, std::unique_ptr<Tobot::Core::View>> p_Views;

        bool m_Running;

    public:
        TobotApplication();
        virtual ~TobotApplication();
        void initialize();
        void run();
        int displayWidth = 800;
        int displayHeight = 600;
        char const * applicationName = "app"; 

    private:
        void handleEvents();
        void update();
        void render();
        void quit();
    };
    TobotApplication * CreateApplication();
} // namespace Fars
