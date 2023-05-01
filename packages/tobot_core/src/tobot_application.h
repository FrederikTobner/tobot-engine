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
        public:
            TobotApplication(char const * name);
            virtual ~TobotApplication();
            auto initialize() -> void;
            auto run() -> void;

        protected:
            Tobot::Math::Dimension<int> m_DisplaySize = Tobot::Math::Dimension<int>(800, 600);
            char const * m_ApplicationName = "app";

            auto setInitialScene(Scene * scene) -> void;

        private:
            SDL_Window * p_Window;
            SDL_Renderer * p_Renderer;
            Tobot::Core::Scene * p_CurrentScene;
            bool m_Running;

            auto handleEvents() -> void;
            auto update() -> void;
            auto render() -> void;
            auto quit() -> void;
    };
    auto CreateApplication() -> TobotApplication *;
} // namespace Tobot::Core
