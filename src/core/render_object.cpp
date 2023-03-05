#include "render_object.h"

using namespace Tobot::Core;

const char* RenderObject::getId() {
    return this->m_Id;
}

Tobot::Math::Vector2D<int> RenderObject::getPosition() {
    return this->m_Position;
}