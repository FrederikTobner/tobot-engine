#include "transform2D.hpp"

#include <cmath>

using namespace Tobot::Core;

Transform2D::Transform2D(const Math::Vector2D<float> & position, float rotation, const Math::Vector2D<float> & scale)
    : m_Position(position), m_Rotation(rotation), m_Scale(scale) {
}

Transform2D::~Transform2D() {
}

auto Transform2D::translate(const Math::Vector2D<float> & translate) -> void {
    m_Position += translate;
}

[[nodiscard]] auto Transform2D::getPosition() const -> Math::Vector2D<float> {
    return m_Position;
}

[[nodiscard]] auto Transform2D::getRotation() const -> float {
    return m_Rotation;
}

[[nodiscard]] auto Transform2D::getScale() const -> Math::Vector2D<float> {
    return m_Scale;
}

auto Transform2D::rotate(float rotation) -> void {
    m_Rotation += rotation;
    // Maybe we should only do that in the editor because SDL wont care about that
    if (m_Rotation > 360.0f) {
        // Modulo using floats
        m_Rotation = fmodf(m_Rotation, 360.0f);
    }
}