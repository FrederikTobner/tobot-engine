#include "circle.h"

using namespace Tobot::Math;

Circle::Circle(const Point2D & center, const float & radius) {
    m_center = center;
    m_radius = radius;
}

Circle::Circle(const Circle & circle) {
    m_center = circle.m_center;
    m_radius = circle.m_radius;
}

Circle::Circle(Circle && circle) noexcept {
    m_center = circle.m_center;
    m_radius = circle.m_radius;
}

Circle & Circle::operator=(const Circle & circle) {
    m_center = circle.m_center;
    m_radius = circle.m_radius;
    return *this;
}

Circle & Circle::operator=(Circle && circle) noexcept {
    m_center = circle.m_center;
    m_radius = circle.m_radius;
    return *this;
}

bool Circle::operator==(const Circle & circle) const {
    return (m_center == circle.m_center) && (m_radius == circle.m_radius);
}

bool Circle::operator!=(const Circle & circle) const {
    return (m_center != circle.m_center) || (m_radius != circle.m_radius);
}

bool Circle::operator<(const Circle & circle) const {
    return m_radius < circle.m_radius;
}

bool Circle::operator>(const Circle & circle) const {
    return m_radius > circle.m_radius;
}

bool Circle::operator<=(const Circle & circle) const {
    return m_radius <= circle.m_radius;
}

bool Circle::operator>=(const Circle & circle) const {
    return m_radius >= circle.m_radius;
}

Point2D Circle::center() const {
    return m_center;
}

float Circle::radius() const {
    return m_radius;
}

void Circle::setCenter(const Point2D & center) {
    m_center = center;
}

void Circle::setRadius(const float & radius) {
    m_radius = radius;
}

float Circle::getArea() const {
    return MATH_PI * pow(m_radius, 2);
}
