#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "pre_compiled_header.hpp"

#include "scene.hpp"

#include "tobot_math.hpp"

namespace Tobot::Core {

    class TobotApplication {
        public:
            /// @brief Constructs a new application
            /// @param name The name of the application
            TobotApplication(char const * name);

            /// @brief Virtual destructor of the application
            virtual ~TobotApplication();

            /// @brief Initializes the application
            auto initialize() -> void;

            /// @brief Runs the application
            auto run() -> void;

        protected:
            // If the application is resized we should resize the gameObjects as well
            // This could be done with a scaling factor that is additionally applied to the gameObjects
            /// The size of the display
            Tobot::Math::Dimension<int> m_DisplaySize = Tobot::Math::Dimension<int>(800, 600);
            /// @brief The name of the application
            char const * m_ApplicationName = "app";

            // We should use a directed graph for the scenes instead
            /// @brief Sets the initial scene of the application
            /// @param scene The initial scene
            auto setInitialScene(Scene * scene) -> void;

        private:
            /// @brief The window used by the application
            SDL_Window * p_Window;
            /// @brief The renderer that is used to render the game
            SDL_Renderer * p_Renderer;
            Tobot::Core::Scene * p_CurrentScene;
            /// @brief Boolean that determines if the application is running or if we should quit
            bool m_Running;

            /// @brief Handles the events of the application
            auto handleEvents() -> void;

            /// @brief Updating the application - occurs every frame
            auto update() -> void;
            /// @brief Renders the application - occurs every frame
            auto render() -> void;
            /// @brief Quits the application
            auto quit() -> void;
    };
    /// @brief Creates a new application - this function is implemented by the user / editor
    auto CreateApplication() -> TobotApplication *;
} // namespace Tobot::Core
