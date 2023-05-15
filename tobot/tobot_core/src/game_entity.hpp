#pragma once

#include "SDL.h"

#include "tobot_texture.hpp"
#include "transform2D.hpp"

namespace Tobot::Core {
    class GameEntity {

        protected:
            // Storing a unique id would be better, we could use the texture manager for that purpose
            char const * m_TexturePath;
            // TODO: we should move the texture to the game entity instead of the render object or create a designated
            // texture class that is used by the game entity. This texture object should be reusable for multiple game
            // entities. This texture object should be the inital state of the texture without any position, scaling or
            // rotation.
            TobotTexture * p_Texture;

            /// @brief The transform component of the object
            Transform2D m_transform;

        private:
            // These rectangles are for the inital size of the texture and the scaled version of our game entity
            // TODO: we should move the destination rectangle to our game Enitity instead of the render object
            SDL_Rect m_SrcRect, m_DstRect;

            /// @brief The id of the object
            char const * m_Id;

            /// @brief Determines if the object should be rendered
            bool m_Visible;

        public:
            GameEntity(char const * id, float x, float y, TobotTexture * texture, float scaleX = 1.0f,
                       float scaleY = 1.0f);
            GameEntity(char const * id, float x, float y, char const * texturePath = nullptr, float scaleX = 1.0f,
                       float scaleY = 1.0f);

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
