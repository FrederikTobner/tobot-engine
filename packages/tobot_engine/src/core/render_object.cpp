#include "render_object.h"

using namespace Tobot::Core;

RenderObject::RenderObject(const char * id, int x, int y) : m_Id(id), m_Position(x, y) {
}

const char * RenderObject::getId() {
    return this->m_Id;
}

Tobot::Math::Vector2D<int> RenderObject::getPosition() {
    return this->m_Position;
}

RenderObject::~RenderObject() {
}