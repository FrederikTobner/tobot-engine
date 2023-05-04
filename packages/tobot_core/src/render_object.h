#pragma once

#include "transform2D.h"

#include "SDL.h"

namespace Tobot::Core {
    class RenderObject {
        private:
            /// @brief The id of the object
            char const * m_Id;

            /// @brief The transform component of the object
            Transform2D m_transform;

            /// @brief Determines if the object should be rendered
            bool m_Visible;

        protected:
            /// @brief Changes the visibility of the object
            /// @param visible The new visibility
            auto setVisible(bool visible) -> void;

            /// @brief Just for Testing purposes
            auto incrementPosition() -> void;

        public:
            RenderObject(char const * id, float x, float y);
            virtual ~RenderObject() = 0;

            virtual auto update() -> void = 0;
            virtual auto render(SDL_Renderer * renderer) -> void = 0;
            virtual auto dispose() -> void = 0;

            auto getId() -> const char *;
            auto getPosition() -> Tobot::Math::Vector2D<float>;
            auto isVisible() -> bool;
    };
} // namespace Tobot::Core
