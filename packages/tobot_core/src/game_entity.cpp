#include "game_entity.h"

using namespace Tobot::Core;

[[nodiscard]] GameEntity::GameEntity(char const * id, int x, int y, SDL_Texture * texture) : RenderObject(id, x, y) {
    this->p_Texture = texture;
}

GameEntity::GameEntity(char const * id, int x, int y) : RenderObject(id, x, y) {
}

auto GameEntity::setTexture(SDL_Surface * texture) -> void {
    this->p_TextureSurface = texture;
}

/// @brief Initializes the texture of the entity from the surface.
/// @param renderer The renderer that is used to create the texture.
auto GameEntity::initializeTexture(SDL_Renderer * renderer) -> void {
    if (this->p_TextureSurface) {
        this->p_Texture = SDL_CreateTextureFromSurface(renderer, this->p_TextureSurface);
        SDL_FreeSurface(this->p_TextureSurface);
    }
}

auto GameEntity::prepareRects() -> void {
    SDL_QueryTexture(this->p_Texture, NULL, NULL, &this->m_SrcRect.w, &this->m_SrcRect.h);
    m_SrcRect.x = 0;
    m_SrcRect.y = 0;

    m_DstRect.x = this->getPosition().x;
    m_DstRect.y = this->getPosition().y;
    m_DstRect.w = m_SrcRect.w;
    m_DstRect.h = m_SrcRect.h;
}

auto GameEntity::render(SDL_Renderer * renderer) -> void {
    this->prepareRects();
    SDL_RenderCopy(renderer, this->p_Texture, &this->m_SrcRect, &this->m_DstRect);
}

auto GameEntity::dispose() -> void {
    SDL_DestroyTexture(this->p_Texture);
}

GameEntity::~GameEntity() {
}
