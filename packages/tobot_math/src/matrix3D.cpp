#include "matrix3D.h"

using namespace Tobot::Math;

Matrix3D::Matrix3D() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] = 0;
        }
    }
}

Matrix3D::Matrix3D(float matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] = matrix[i][j];
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
    Matrix3D result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m_data[i][j] = this->m_data[i][j] / scalar;
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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_data[i][j] /= scalar;
        }
    }
    return *this;
}

Matrix3D Matrix3D::operator!() const {
    Matrix3D result;
    float det = this->determinant();
    if (det == 0) {
        throw std::invalid_argument("Matrix is not invertible");
    }
    result.m_data[0][0] = this->m_data[1][1] * this->m_data[2][2] - this->m_data[1][2] * this->m_data[2][1];
    result.m_data[0][1] = this->m_data[0][2] * this->m_data[2][1] - this->m_data[0][1] * this->m_data[2][2];
    result.m_data[0][2] = this->m_data[0][1] * this->m_data[1][2] - this->m_data[0][2] * this->m_data[1][1];
    result.m_data[1][0] = this->m_data[1][2] * this->m_data[2][0] - this->m_data[1][0] * this->m_data[2][2];
    result.m_data[1][1] = this->m_data[0][0] * this->m_data[2][2] - this->m_data[0][2] * this->m_data[2][0];
    result.m_data[1][2] = this->m_data[0][2] * this->m_data[1][0] - this->m_data[0][0] * this->m_data[1][2];
    result.m_data[2][0] = this->m_data[1][0] * this->m_data[2][1] - this->m_data[1][1] * this->m_data[2][0];
    result.m_data[2][1] = this->m_data[0][1] * this->m_data[2][0] - this->m_data[0][0] * this->m_data[2][1];
    result.m_data[2][2] = this->m_data[0][0] * this->m_data[1][1] - this->m_data[0][1] * this->m_data[1][0];
    result /= det;
    return result;
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

Matrix3D Matrix3D::rotation(const float & angle, const Point2D & point) {
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

Matrix3D Matrix3D::scale(const float & x, const float & y, const Point2D & point) {
    Matrix3D result;
    result.m_data[0][0] = x;
    result.m_data[1][1] = y;
    result.m_data[2][2] = 1;
    result.m_data[2][0] = point.x() * (1 - x);
    result.m_data[2][1] = point.y() * (1 - y);
    return result;
}

Matrix3D Matrix3D::translation(const float & x, const float & y, const Point2D & point) {
    Matrix3D result;
    result.m_data[0][2] = x;
    result.m_data[1][2] = y;
    result.m_data[2][2] = 1;
    result.m_data[2][0] = point.x() - x;
    result.m_data[2][1] = point.y() - y;
    return result;
}

Matrix3D Matrix3D::shear(const float & x, const float & y, const Point2D & point) {
    Matrix3D result;
    result.m_data[0][1] = x;
    result.m_data[1][0] = y;
    result.m_data[2][2] = 1;
    result.m_data[2][0] = point.x() * y;
    result.m_data[2][1] = point.y() * x;
    return result;
}
