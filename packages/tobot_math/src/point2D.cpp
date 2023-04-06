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

Point2D Point2D::operator+(const Point2D & point) const {
    Point2D result;
    result.m_x = m_x + point.m_x;
    result.m_y = m_y + point.m_y;
    return result;
}

Point2D Point2D::operator-(const Point2D & point) const {
    Point2D result;
    result.m_x = m_x - point.m_x;
    result.m_y = m_y - point.m_y;
    return result;
}

Point2D Point2D::operator*(const float & value) const {
    Point2D result;
    result.m_x = m_x * value;
    result.m_y = m_y * value;
    return result;
}

Point2D Point2D::operator/(const float & value) const {
    Point2D result;
    result.m_x = m_x / value;
    result.m_y = m_y / value;
    return result;
}

Point2D & Point2D::operator+=(const Point2D & point) {
    m_x += point.m_x;
    m_y += point.m_y;
    return *this;
}

Point2D & Point2D::operator-=(const Point2D & point) {
    m_x -= point.m_x;
    m_y -= point.m_y;
    return *this;
}

Point2D & Point2D::operator*=(const float & value) {
    m_x *= value;
    m_y *= value;
    return *this;
}

Point2D & Point2D::operator/=(const float & value) {
    m_x /= value;
    m_y /= value;
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

float Point2D::dot(const Point2D & point) const {
    return m_x * point.m_x + m_y * point.m_y;
}

float Point2D::dot(const float & x, const float & y) const {
    return m_x * x + m_y * y;
}

float Point2D::length() const {
    return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

float Point2D::lengthSquared() const {
    return pow(m_x, 2) + pow(m_y, 2);
}

Point2D Point2D::normalize() {
    Point2D result;
    float length = this->length();
    if (length > 0) {
        result.m_x = m_x / length;
        result.m_y = m_y / length;
    }
    return result;
}

Point2D Point2D::normalize() const {
    Point2D result;
    float length = this->length();
    if (length > 0) {
        result.m_x = m_x / length;
        result.m_y = m_y / length;
    }
    return result;
}
