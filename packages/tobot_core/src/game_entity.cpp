#include "game_entity.hpp"

#include "tobot_texture.hpp"

using namespace Tobot::Core;

GameEntity::GameEntity(char const * id, float x, float y, TobotTexture * texture, float scaleX, float scaleY)
    : m_Id(id), m_transform(Tobot::Math::Vector2D<float>(x, y), 0.0, Tobot::Math::Vector2D<float>(scaleX, scaleY)) {
    this->p_Texture = texture;
}

GameEntity::GameEntity(char const * id, float x, float y, float scaleX, float scaleY)
    : m_Id(id), m_transform(Tobot::Math::Vector2D<float>(x, y), 0.0, Tobot::Math::Vector2D<float>(scaleX, scaleY)) {
}

GameEntity::~GameEntity() {
}

auto Tobot::Core::GameEntity::setVisible(bool visible) -> void {
    this->m_Visible = visible;
}

auto Tobot::Core::GameEntity::incrementPosition() -> void {
    this->m_transform.translate(Tobot::Math::Vector2D<float>(1.0, 1.0));
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

auto GameEntity::setTexture(SDL_Surface * texture) -> void {
    this->p_TextureSurface = texture;
}

auto GameEntity::initializeTexture(SDL_Renderer * renderer) -> void {
    // We should not create a new texture every time we initialize the texture. We should create the texture once and
    // reuse it for every game entity that uses the same texture. We would need a texture manager for that.
    if (this->p_TextureSurface) {
        this->p_Texture = new TobotTexture(this->p_TextureSurface, renderer);
    }
    SDL_FreeSurface(this->p_TextureSurface);
}

auto GameEntity::prepareRects() -> void {
}

auto GameEntity::render(SDL_Renderer * renderer) -> void {
    // Creating the destination rectangle every time when the texture is rendered is not very efficient.
    SDL_Rect rect = {(int)this->getPosition().getX(), (int)this->getPosition().getY(),
                     (int)(this->p_Texture->getWidth() * this->getScale().getX()),
                     (int)(this->p_Texture->getHeight() * this->getScale().getY())};
    SDL_RenderCopy(renderer, this->p_Texture->getTexture(), NULL, &rect);
}

auto GameEntity::dispose() -> void {
    delete this->p_Texture;
}
