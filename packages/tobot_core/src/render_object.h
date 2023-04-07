#pragma once

#include "tobot_math.h"

#include "SDL.h"

namespace Tobot::Core {
    class RenderObject {
        private:
            const char * m_Id;
            Tobot::Math::Vector2D<float> m_Position;
            bool m_Visible;

        protected:
            void setVisible(bool visible);

            /// @brief Just for Testing purposes
            void incrementPosition();

        public:
            RenderObject(const char * id, int x, int y);
            virtual ~RenderObject() = 0;

            virtual void update() = 0;
            virtual void render(SDL_Renderer * renderer) = 0;
            virtual void dispose() = 0;

            const char * getId();
            Tobot::Math::Vector2D<float> getPosition();
            bool isVisible();
    };
} // namespace Tobot::Core
