#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "pre_compiled_header.h"

#include "scene.h"

#include "tobot_math.h"

namespace Tobot::Core {

    class TobotApplication {
        private:
            SDL_Window * p_Window;
            SDL_Renderer * p_Renderer;

            Tobot::Core::Scene * p_CurrentScene;

            bool m_Running;

        protected:
            Tobot::Math::Dimension<int> m_DisplaySize = Tobot::Math::Dimension<int>(800, 600);
            char const * m_ApplicationName = "app";

            void setInitialScene(Scene * scene);

        public:
            TobotApplication(char const * name);
            virtual ~TobotApplication();
            void initialize();
            void run();

        private:
            void handleEvents();
            void update();
            void render();
            void quit();
    };
    TobotApplication * CreateApplication();
} // namespace Tobot::Core
