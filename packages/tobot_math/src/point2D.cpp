#include "point2D.h"

using namespace Tobot::Math;

Point2D::Point2D(const float & x, const float & y) {
    m_x = x;
    m_y = y;
}

Point2D::Point2D(const Point2D & point) {
    m_x = point.m_x;
    m_y = point.m_y;
}

Point2D::Point2D(Point2D && point) noexcept {
    m_x = point.m_x;
    m_y = point.m_y;
}

Point2D & Point2D::operator=(const Point2D & point) {
    m_x = point.m_x;
    m_y = point.m_y;
    return *this;
}

Point2D & Point2D::operator=(Point2D && point) noexcept {
    m_x = point.m_x;
    m_y = point.m_y;
    return *this;
}

bool Point2D::operator==(const Point2D & point) const {
    return (m_x == point.m_x) && (m_y == point.m_y);
}

bool Point2D::operator!=(const Point2D & point) const {
    return (m_x != point.m_x) || (m_y != point.m_y);
}

float Point2D::x() const {
    return m_x;
}

float Point2D::y() const {
    return m_y;
}

void Point2D::setX(const float & x) {
    m_x = x;
}

void Point2D::setY(const float & y) {
    m_y = y;
}

float Point2D::distance(const Point2D & point) const {
    return sqrt(pow(m_x - point.m_x, 2) + pow(m_y - point.m_y, 2));
}

float Point2D::distance(const float & x, const float & y) const {
    return sqrt(pow(m_x - x, 2) + pow(m_y - y, 2));
}

float Point2D::distanceSquared(const Point2D & point) const {
    return pow(m_x - point.m_x, 2) + pow(m_y - point.m_y, 2);
}

float Point2D::distanceSquared(const float & x, const float & y) const {
    return pow(m_x - x, 2) + pow(m_y - y, 2);
}
