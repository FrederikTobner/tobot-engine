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

            /// @brief Creates a texture from a text
            /// @param textureText The text that should be rendered
            /// @param textColor The color of the text
            /// @param gFont The font that should be used to render the text
            /// @param renderer The renderer that is used to create the texture
            TobotTexture(char const * textureText, SDL_Color textColor, TTF_Font * gFont, SDL_Renderer * renderer);
            ~TobotTexture();

            auto getTexture() -> SDL_Texture *;
            auto getWidth() -> int;
            auto getHeight() -> int;
            auto setBlendMode(SDL_BlendMode blending) -> void;
            auto setColor(Uint8 red, Uint8 green, Uint8 blue) -> void;
    };
} // namespace Tobot::Core