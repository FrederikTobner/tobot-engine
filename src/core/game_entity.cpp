#include "game_entity.h"

using namespace Tobot::Core;

GameEntity::GameEntity(const char *id, int x, int y, SDL_Texture *texture) : RenderObject(id, x, y)
{
    this->p_Texture = texture;
}

GameEntity::GameEntity(const char *id, int x, int y) : RenderObject(id, x, y)
{
}

void GameEntity::setTexture(SDL_Surface *texture)
{
    this->p_TextureSurface = texture;
}

void GameEntity::initializeTexture(SDL_Renderer *renderer)
{
    this->p_Texture = SDL_CreateTextureFromSurface(renderer, this->p_TextureSurface);
    SDL_FreeSurface(this->p_TextureSurface);
}

void GameEntity::prepareRects()
{
    SDL_QueryTexture(this->p_Texture, NULL, NULL, &this->m_SrcRect.w, &this->m_SrcRect.h);
    m_SrcRect.x = 0;
    m_SrcRect.y = 0;

    m_DstRect.x = this->m_Position.x;
    m_DstRect.y = this->m_Position.y;
    m_DstRect.w = m_SrcRect.w;
    m_DstRect.h = m_SrcRect.h;
}

void GameEntity::render(SDL_Renderer *renderer)
{
    this->prepareRects();
    SDL_RenderCopy(renderer, this->p_Texture, &this->m_SrcRect, &this->m_DstRect);
}
