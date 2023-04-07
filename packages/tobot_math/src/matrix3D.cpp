#include "matrix3D.h"
#include "vector/vector3d.h"
using namespace Tobot::Math;

Matrix3D::Matrix3D() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] = 0;
        }
    }
}

Matrix3D::Matrix3D(float fval, float sval, float tval, float foval, float fifval, float sixval, float seval,
                   float eightval, float nineval) {
    this->m_data[0][0] = fval;
    this->m_data[0][1] = sval;
    this->m_data[0][2] = tval;
    this->m_data[1][0] = foval;
    this->m_data[1][1] = fifval;
    this->m_data[1][2] = sixval;
    this->m_data[2][0] = seval;
    this->m_data[2][1] = eightval;
    this->m_data[2][2] = nineval;
}

Matrix3D::Matrix3D(float data[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] = data[i][j];
        }
    }
}

Matrix3D::Matrix3D(std::array<std::array<float, 3>, 3> data) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] = data[i][j];
        }
    }
}

Matrix3D::Matrix3D(std::initializer_list<float> list) {
    int i = 0;
    int j = 0;
    for (auto it = list.begin(); it != list.end(); it++) {
        this->m_data[i][j] = *it;
        j++;
        if (j == 3) {
            j = 0;
            i++;
        }
    }
}

Matrix3D::Matrix3D(const Matrix3D & matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] = matrix.m_data[i][j];
        }
    }
}

Matrix3D::Matrix3D(Matrix3D && matrix) noexcept {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] = matrix.m_data[i][j];
        }
    }
}

Matrix3D & Matrix3D::operator=(const Matrix3D & matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] = matrix.m_data[i][j];
        }
    }
    return *this;
}

Matrix3D & Matrix3D::operator=(Matrix3D && matrix) noexcept {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] = matrix.m_data[i][j];
        }
    }
    return *this;
}

Matrix3D Matrix3D::operator+(const Matrix3D & matrix) const {
    Matrix3D result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m_data[i][j] = this->m_data[i][j] + matrix.m_data[i][j];
        }
    }
    return result;
}

Matrix3D Matrix3D::operator-(const Matrix3D & matrix) const {
    Matrix3D result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m_data[i][j] = this->m_data[i][j] - matrix.m_data[i][j];
        }
    }
    return result;
}

Matrix3D Matrix3D::operator*(const Matrix3D & matrix) const {
    Matrix3D result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m_data[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result.m_data[i][j] += this->m_data[i][k] * matrix.m_data[k][j];
            }
        }
    }
    return result;
}

Matrix3D Matrix3D::operator*(const float & scalar) const {
    Matrix3D result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m_data[i][j] = this->m_data[i][j] * scalar;
        }
    }
    return result;
}

Matrix3D Matrix3D::operator/(const float & scalar) const {
    float factor = 1.0f / scalar;
    Matrix3D result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m_data[i][j] = this->m_data[i][j] * factor;
        }
    }
    return result;
}

Matrix3D & Matrix3D::operator+=(const Matrix3D & matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] += matrix.m_data[i][j];
        }
    }
    return *this;
}

Matrix3D & Matrix3D::operator-=(const Matrix3D & matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] -= matrix.m_data[i][j];
        }
    }
    return *this;
}

Matrix3D & Matrix3D::operator*=(const Matrix3D & matrix) {
    Matrix3D result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m_data[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result.m_data[i][j] += this->m_data[i][k] * matrix.m_data[k][j];
            }
        }
    }
    *this = result;
    return *this;
}

Matrix3D & Matrix3D::operator*=(const float & scalar) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] *= scalar;
        }
    }
    return *this;
}

Matrix3D & Matrix3D::operator/=(const float & scalar) {
    float factor = 1.0f / scalar;
    *this *= factor;
    return *this;
}

Matrix3D Matrix3D::operator!() const {
    Vector3D<float> a(this->m_data[0][0], this->m_data[0][1], this->m_data[0][2]);
    Vector3D<float> b(this->m_data[1][0], this->m_data[1][1], this->m_data[1][2]);
    Vector3D<float> c(this->m_data[2][0], this->m_data[2][1], this->m_data[2][2]);
    Vector3D<float> x = b.Cross(c);
    Vector3D<float> y = c.Cross(a);
    Vector3D<float> z = a.Cross(b);
    float det = z.Dot(c);
    if (det == 0) {
        throw std::runtime_error("Matrix3D::operator!(): determinant is zero");
    }
    float factor = 1.0f / det;
    return (Matrix3D(x.x * factor, y.x * factor, z.x * factor, x.y * factor, y.y * factor, z.y * factor, x.z * factor,
                     y.z * factor, z.z * factor));
}

float Matrix3D::operator()(const int & row, const int & column) const {
    return this->m_data[row][column];
}

float & Matrix3D::operator()(const int & row, const int & column) {
    return this->m_data[row][column];
}

float Matrix3D::determinant() const {
    return this->m_data[0][0] * this->m_data[1][1] * this->m_data[2][2] +
           this->m_data[0][1] * this->m_data[1][2] * this->m_data[2][0] +
           this->m_data[0][2] * this->m_data[1][0] * this->m_data[2][1] -
           this->m_data[0][2] * this->m_data[1][1] * this->m_data[2][0] -
           this->m_data[0][1] * this->m_data[1][0] * this->m_data[2][2] -
           this->m_data[0][0] * this->m_data[1][2] * this->m_data[2][1];
}

Matrix3D Matrix3D::rotation(const float & angle) {
    Matrix3D result;
    result.m_data[0][0] = cos(angle);
    result.m_data[0][1] = -sin(angle);
    result.m_data[1][0] = sin(angle);
    result.m_data[1][1] = cos(angle);
    result.m_data[2][2] = 1;
    return result;
}

Matrix3D Matrix3D::reflection(const float & angle) {
    Matrix3D result;
    result.m_data[0][0] = cos(2 * angle);
    result.m_data[0][1] = sin(2 * angle);
    result.m_data[1][0] = sin(2 * angle);
    result.m_data[1][1] = -cos(2 * angle);
    result.m_data[2][2] = 1;
    return result;
}

Matrix3D Matrix3D::rotation(const float & angle, const Point2D<float> & point) {
    Matrix3D result;
    result.m_data[0][0] = cos(angle);
    result.m_data[0][1] = -sin(angle);
    result.m_data[1][0] = sin(angle);
    result.m_data[1][1] = cos(angle);
    result.m_data[2][2] = 1;
    result.m_data[2][0] = point.x() * (1 - cos(angle)) + point.y() * sin(angle);
    result.m_data[2][1] = point.y() * (1 - cos(angle)) - point.x() * sin(angle);
    return result;
}

Matrix3D Matrix3D::makeRotationX(const float & angle) {
    float cosAngle = cos(angle);
    float sinAngle = sin(angle);
    return (Matrix3D(1, 0.0f, 0.0f, 0.0f, cosAngle, -sinAngle, 0.0f, sinAngle, cosAngle));
}

Matrix3D Matrix3D::makeRotationY(const float & angle) {
    float cosAngle = cos(angle);
    float sinAngle = sin(angle);
    return (Matrix3D(cosAngle, 0.0f, sinAngle, 0.0f, 1, 0.0f, -sinAngle, 0.0f, cosAngle));
}

Matrix3D Matrix3D::makeRotationZ(const float & angle) {
    float cosAngle = cos(angle);
    float sinAngle = sin(angle);
    return (Matrix3D(cosAngle, -sinAngle, 0.0f, sinAngle, cosAngle, 0.0f, 0.0f, 0.0f, 1));
}

Matrix3D Matrix3D::scale(const float & x, const float & y, const Point2D<float> & point) {
    Matrix3D result;
    result.m_data[0][0] = x;
    result.m_data[1][1] = y;
    result.m_data[2][2] = 1;
    result.m_data[2][0] = point.x() * (1 - x);
    result.m_data[2][1] = point.y() * (1 - y);
    return result;
}

Matrix3D Matrix3D::translation(const float & x, const float & y, const Point2D<float> & point) {
    Matrix3D result;
    result.m_data[0][2] = x;
    result.m_data[1][2] = y;
    result.m_data[2][2] = 1;
    result.m_data[2][0] = point.x() - x;
    result.m_data[2][1] = point.y() - y;
    return result;
}

Matrix3D Matrix3D::shear(const float & x, const float & y, const Point2D<float> & point) {
    Matrix3D result;
    result.m_data[0][1] = x;
    result.m_data[1][0] = y;
    result.m_data[2][2] = 1;
    result.m_data[2][0] = point.x() * y;
    result.m_data[2][1] = point.y() * x;
    return result;
}
