#include "transform2D.h"

using namespace Tobot::Core;

Transform2D::Transform2D() : m_Position(0.0, 0.0), m_Rotation(0.0), m_Scale(1.0, 1.0) {
}

Transform2D::Transform2D(const Math::Vector2D<float> & position, float rotation, const Math::Vector2D<float> & scale)
    : m_Position(position), m_Rotation(rotation), m_Scale(scale) {
}

Tobot::Math::Vector2D<float> Transform2D::getPosition() const {
    return m_Position;
}

float Transform2D::getRotation() const {
    return m_Rotation;
}

Tobot::Math::Vector2D<float> Transform2D::getScale() const {
    return m_Scale;
}