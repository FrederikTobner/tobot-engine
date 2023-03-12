#include "render_object.h"

using namespace Tobot::Core;

void Tobot::Core::RenderObject::setVisible(bool visible) {
    this->m_Visible = visible;
}

void Tobot::Core::RenderObject::incrementPosition() {
    this->m_Position += Tobot::Math::Vector2D<int>(1, 1);
}

RenderObject::RenderObject(const char * id, int x, int y) : m_Id(id), m_Position(x, y) {
}

const char * RenderObject::getId() {
    return this->m_Id;
}

Tobot::Math::Vector2D<int> RenderObject::getPosition() {
    return this->m_Position;
}

bool Tobot::Core::RenderObject::isVisible() {
    return this->m_Visible;
}

RenderObject::~RenderObject() {
}