#include "tobot_texture.hpp"

using namespace Tobot::Core;

TobotTexture::TobotTexture(SDL_Surface * surface, SDL_Renderer * renderer) {
    this->p_Texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->m_Height = surface->h;
    this->m_Width = surface->w;
}

TobotTexture::TobotTexture(char const * textureText, SDL_Color textColor, TTF_Font * gFont, SDL_Renderer * renderer) {
    // Render text surface
    SDL_Surface * textSurface = TTF_RenderText_Solid(gFont, textureText, textColor);
    if (textSurface != NULL) {
        // Create texture from surface pixels
        this->p_Texture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (this->p_Texture == NULL) {
        } else {
            // Get image dimensions
            this->m_Width = textSurface->w;
            this->m_Height = textSurface->h;
        }

        // Get rid of old surface
        SDL_FreeSurface(textSurface);
    }
}

TobotTexture::TobotTexture(SDL_Texture * texture) {
    this->p_Texture = texture;
    // Getting the width and height of the texture -> This is needed because the SDL_Texture is a opaque type (We can't
    // access the width and height of the texture)
    SDL_QueryTexture(this->p_Texture, NULL, NULL, &this->m_Width, &this->m_Height);
}

TobotTexture::~TobotTexture() {
    SDL_DestroyTexture(this->p_Texture);
}

[[nodiscard]] auto TobotTexture::getTexture() const -> SDL_Texture * {
    return this->p_Texture;
}

[[nodiscard]] auto TobotTexture::getWidth() const -> int {
    return this->m_Width;
}

[[nodiscard]] auto TobotTexture::getHeight() const -> int {
    return this->m_Height;
}

auto TobotTexture::setBlendMode(SDL_BlendMode blending) -> void {
    SDL_SetTextureBlendMode(this->p_Texture, blending);
}

auto TobotTexture::setColor(Uint8 red, Uint8 green, Uint8 blue) -> void {
    SDL_SetTextureColorMod(this->p_Texture, red, green, blue);
}