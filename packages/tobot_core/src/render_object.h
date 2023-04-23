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
            void setVisible(bool visible);

            /// @brief Just for Testing purposes
            void incrementPosition();

        public:
            RenderObject(char const * id, int x, int y);
            virtual ~RenderObject() = 0;

            virtual void update() = 0;
            virtual void render(SDL_Renderer * renderer) = 0;
            virtual void dispose() = 0;

            const char * getId();
            Tobot::Math::Vector2D<float> getPosition();
            bool isVisible();
    };
} // namespace Tobot::Core
