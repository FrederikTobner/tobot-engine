#include "render_object.h"

using namespace Tobot::Core;

auto Tobot::Core::RenderObject::setVisible(bool visible) -> void {
    this->m_Visible = visible;
}

auto Tobot::Core::RenderObject::incrementPosition() -> void {
    this->m_Position += Tobot::Math::Vector2D<float>(1.0, 1.0);
}

[[nodiscard]] RenderObject::RenderObject(char const * id, int x, int y) : m_Id(id), m_Position(x, y) {
}

[[nodiscard]] auto RenderObject::getId() -> const char * {
    return this->m_Id;
}

auto RenderObject::getPosition() -> Tobot::Math::Vector2D<float> {
    return this->m_Position;
}

[[nodiscard]] auto Tobot::Core::RenderObject::isVisible() -> bool {
    return this->m_Visible;
}

RenderObject::~RenderObject() {
}