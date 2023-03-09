#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include <iostream>
#include <unordered_map>

#include "scene.h"

namespace Tobot::Core
{
    class TobotApplication
    {
    private:
        inline static TobotApplication *sp_Instance = 0;

        SDL_Window *p_Window;
        SDL_Renderer *p_Renderer;

        Scene *p_CurrentScene;

        bool m_Running;

    protected:
        int m_DisplayWidth = 800;
        int m_DisplayHeight = 600;
        char const *m_ApplicationName = "app";

        void setInitialScene(Scene *scene);

    public:
        TobotApplication(const char *name);
        virtual ~TobotApplication();
        void initialize();
        void run();

    private:
        void handleEvents();
        void update();
        void render();
        void quit();
    };
    TobotApplication *CreateApplication();
} // namespace Fars
