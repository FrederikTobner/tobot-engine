#include "game_entity.hpp"

#include "asset_manager.hpp"
#include "tobot_texture.hpp"

#include <stdlib.h>
#include <string.h>

using namespace Tobot::Core;

GameEntity::GameEntity(char const * id, float x, float y, TobotTexture * texture, float scaleX, float scaleY)
    : m_Id(id), m_transform(Tobot::Math::Vector2D<float>(x, y), 0.0f, Tobot::Math::Vector2D<float>(scaleX, scaleY)) {
    this->p_Texture = texture;
}

GameEntity::GameEntity(char const * id, float x, float y, char const * texturePath, float scaleX, float scaleY)
    : m_Id(id), m_transform(Tobot::Math::Vector2D<float>(x, y), 0.0, Tobot::Math::Vector2D<float>(scaleX, scaleY)),
      m_TexturePath(texturePath) {
    this->p_Texture = nullptr;
}

GameEntity::~GameEntity() {
}

auto Tobot::Core::GameEntity::setVisible(bool visible) -> void {
    this->m_Visible = visible;
}

[[nodiscard]] auto GameEntity::getId() -> const char * {
    return this->m_Id;
}

[[nodiscard]] auto GameEntity::getPosition() -> Tobot::Math::Vector2D<float> {
    return this->m_transform.getPosition();
}

[[nodiscard]] auto GameEntity::getScale() -> Tobot::Math::Vector2D<float> {
    return this->m_transform.getScale();
}

[[nodiscard]] auto Tobot::Core::GameEntity::isVisible() -> bool {
    return this->m_Visible;
}

auto GameEntity::initializeTexture(SDL_Renderer * renderer) -> void {
    // We should not create a new texture every time we initialize the texture. We should create the texture once and
    // reuse it for every game entity that uses the same texture. We would need a texture manager for that.
    if (!this->p_Texture && this->m_TexturePath) {
        this->p_Texture = new TobotTexture(AssetManager::loadTextureScurface(this->m_TexturePath), renderer);
    }
}

auto GameEntity::render(SDL_Renderer * renderer) -> void {

    // Creating the destination rectangle every time when the texture is rendered is not very efficient.
    SDL_Rect rect = {(int)this->getPosition().getX(), (int)this->getPosition().getY(),
                     (int)(this->p_Texture->getWidth() * this->getScale().getX()),
                     (int)(this->p_Texture->getHeight() * this->getScale().getY())};
    if (this->m_transform.getRotation() != 0.0) {
        SDL_RenderCopyEx(renderer, this->p_Texture->getTexture(), NULL, &rect, this->m_transform.getRotation(), NULL,
                         SDL_FLIP_NONE);
    } else {
        SDL_RenderCopy(renderer, this->p_Texture->getTexture(), NULL, &rect);
    }
}

auto GameEntity::dispose() -> void {
    delete this->p_Texture;
}
