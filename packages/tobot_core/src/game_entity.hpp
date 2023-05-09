#pragma once

#include "SDL.h"

#include "tobot_texture.hpp"
#include "transform2D.hpp"

namespace Tobot::Core {
    class GameEntity {

        protected:
            auto setTexture(SDL_Surface * texture) -> void;

            SDL_Surface * p_TextureSurface;
            // TODO: we should move the texture to the game entity instead of the render object or create a designated
            // texture class that is used by the game entity. This texture object should be reusable for multiple game
            // entities. This texture object should be the inital state of the texture without any position, scaling or
            // rotation.
            TobotTexture * p_Texture;

        private:
            // These rectangles are for the inital size of the texture and the scaled version of our game entity
            // TODO: we should move the destination rectangle to our game Enitity instead of the render object
            SDL_Rect m_SrcRect, m_DstRect;

            /// @brief The id of the object
            char const * m_Id;

            /// @brief The transform component of the object
            Transform2D m_transform;

            /// @brief Determines if the object should be rendered
            bool m_Visible;

            auto prepareRects() -> void;

        protected:
            /// @brief Just for Testing purposes
            auto incrementPosition() -> void;

        public:
            GameEntity(char const * id, float x, float y, TobotTexture * texture, float scaleX = 1.0f,
                       float scaleY = 1.0f);
            GameEntity(char const * id, float x, float y, float scaleX = 1.0f, float scaleY = 1.0f);

            ~GameEntity();

            /// @brief Initializes the texture of the entity from the surface.
            /// @param renderer The renderer that is used to create the texture.
            auto initializeTexture(SDL_Renderer * renderer) -> void;

            virtual auto update() -> void = 0;
            auto render(SDL_Renderer * renderer) -> void;
            auto dispose() -> void;
            auto getId() -> const char *;
            auto getPosition() -> Tobot::Math::Vector2D<float>;
            auto getScale() -> Tobot::Math::Vector2D<float>;
            auto isVisible() -> bool;
            /// @brief Changes the visibility of the object
            /// @param visible The new visibility
            auto setVisible(bool visible) -> void;
    };
} // namespace Tobot::Core
