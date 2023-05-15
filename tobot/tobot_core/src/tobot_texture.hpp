#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

namespace Tobot::Core {
    class TobotTexture {
        private:
            SDL_Texture * p_Texture;
            int m_Width, m_Height;

        public:
            /// @brief Creating a texture from a surface is not very efficient
            /// @param surface The screen surface
            /// @param renderer The renderer that is used to create the texture
            TobotTexture(SDL_Surface * surface, SDL_Renderer * renderer);

            /// @brief Creates a texture from an existing SDL_Texture
            /// @param texture The SDL_Texture that should be used to create the texture
            TobotTexture(SDL_Texture * texture);

            /// @brief Creates a texture from a text
            /// @param textureText The text that should be rendered
            /// @param textColor The color of the text
            /// @param gFont The font that should be used to render the text
            /// @param renderer The renderer that is used to create the texture
            TobotTexture(char const * textureText, SDL_Color textColor, TTF_Font * gFont, SDL_Renderer * renderer);

            /// @brief Destroys the texture
            ~TobotTexture();

            /// @brief Gets the underlying SDL_Texture
            /// @return The underlying SDL_Texture
            auto getTexture() const -> SDL_Texture *;

            /// @brief Gets the width of the texture
            /// @return The width of the texture
            auto getWidth() const -> int;

            /// @brief Gets the height of the texture
            auto getHeight() const -> int;

            /// @brief Sets the blend mode of the texture
            /// @param blending The new blend mode
            auto setBlendMode(SDL_BlendMode blending) -> void;

            /// @brief Sets the color of the texture
            /// @param red The red color
            /// @param green The green color
            /// @param blue The blue color
            auto setColor(Uint8 red, Uint8 green, Uint8 blue) -> void;
    };
} // namespace Tobot::Core