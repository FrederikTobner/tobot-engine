#pragma once

#include "tobot_math.h"

#include "SDL.h"

namespace Tobot::Core {
    class RenderObject {
        private:
            /// @brief The id of the object
            const char * m_Id;
            /// @brief The position of the object
            Tobot::Math::Vector2D<float> m_Position;
            /// @brief Determines if the object should be rendered
            bool m_Visible;

        protected:
            /// @brief Changes the visibility of the object
            /// @param visible The new visibility
            auto setVisible(bool visible) -> void;

            /// @brief Just for Testing purposes
            auto incrementPosition() -> void;

        public:
            RenderObject(char const * id, int x, int y);
            virtual ~RenderObject() = 0;

            virtual auto update() -> void = 0;
            virtual auto render(SDL_Renderer * renderer) -> void = 0;
            virtual auto dispose() -> void = 0;

            auto getId() -> const char *;
            auto getPosition() -> Tobot::Math::Vector2D<float>;
            auto isVisible() -> bool;
    };
} // namespace Tobot::Core
