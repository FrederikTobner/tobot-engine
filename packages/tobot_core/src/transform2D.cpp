#include "transform2D.hpp"

using namespace Tobot::Core;

Transform2D::Transform2D() : m_Position(0.0, 0.0), m_Rotation(0.0), m_Scale(1.0, 1.0) {
}

Transform2D::Transform2D(const Math::Vector2D<float> & position, float rotation, const Math::Vector2D<float> & scale)
    : m_Position(position), m_Rotation(rotation), m_Scale(scale) {
}

Transform2D::~Transform2D() {
}

auto Transform2D::translate(const Math::Vector2D<float> & translate) -> void {
    m_Position += translate;
}

auto Transform2D::getPosition() const -> Math::Vector2D<float> {
    return m_Position;
}

auto Transform2D::getRotation() const -> float {
    return m_Rotation;
}

auto Transform2D::getScale() const -> Math::Vector2D<float> {
    return m_Scale;
}