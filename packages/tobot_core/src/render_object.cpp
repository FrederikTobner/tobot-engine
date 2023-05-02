#include "render_object.h"

using namespace Tobot::Core;

auto Tobot::Core::RenderObject::setVisible(bool visible) -> void {
    this->m_Visible = visible;
}

auto Tobot::Core::RenderObject::incrementPosition() -> void {
    this->m_transform.translate(Tobot::Math::Vector2D<float>(1.0, 1.0));
}

// The scaling and rotation is not implemented yet
RenderObject::RenderObject(char const * id, float x, float y)
    : m_Id(id), m_transform(Tobot::Math::Vector2D<float>(x, y), 0.0, Tobot::Math::Vector2D<float>(0.0f, 0.0f)) {
}

[[nodiscard]] auto RenderObject::getId() -> const char * {
    return this->m_Id;
}

auto RenderObject::getPosition() -> Tobot::Math::Vector2D<float> {
    return this->m_transform.getPosition();
}

[[nodiscard]] auto Tobot::Core::RenderObject::isVisible() -> bool {
    return this->m_Visible;
}

RenderObject::~RenderObject() {
}