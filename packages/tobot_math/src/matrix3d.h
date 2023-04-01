#pragma once

#include "concepts.h"
#include "pre_compiled_header.h"
#include "vector3d.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Matrix3D {
        private:
            std::array<std::array<T, 3>, 3> m_matrix;

        public:
            Matrix3D();
            Matrix3D(const std::vector<T> values);

            inline T & operator()(std::size_t i, std::size_t j);
            inline T & operator()(std::size_t i, std::size_t j) const;
            inline Vector3D<T> & operator[](std::size_t i);
            inline Vector3D<T> & operator[](std::size_t i) const;
    };

    template <typename T>
        requires Arithmetic<T>
    Matrix3D<T>::Matrix3D() {
    }

    template <typename T>
        requires Arithmetic<T>
    Matrix3D<T>::Matrix3D(const std::vector<T> values) {
        if (values.empty()) {
            throw std::invalid_argument("The provided vector is empty");
        }

        if (9 != values.size()) {
            throw std::runtime_error("Total number of matrix values does not match the rows and coloumns provided");
        }
        for (std::size_t i = 0; i < 3; i++) {
            for (std::size_t j = 0; j < 3; j++) {
                this->m_matrix[i][j] = values[i * 3 + j];
            }
        }
    }

    template <typename T>
        requires Arithmetic<T>
    inline T & Matrix3D<T>::operator()(std::size_t i, std::size_t j) {
        assert(i < 3 && j < 3);
        return this->m_matrix[i][j];
    }

    template <typename T>
        requires Arithmetic<T>
    inline T & Matrix3D<T>::operator()(std::size_t i, std::size_t j) const {
        assert(i < 3 && j < 3);
        return this->m_matrix[i][j];
    }

    template <typename T>
        requires Arithmetic<T>
    inline Vector3D<T> & Matrix3D<T>::operator[](std::size_t i) {
        assert(i < 3);
        return Vector3D(this->m_matrix[i][0], this->m_matrix[i][1], this->m_matrix[i][2]);
    }

    template <typename T>
        requires Arithmetic<T>
    inline Vector3D<T> & Matrix3D<T>::operator[](std::size_t i) const {
        assert(i < 3);
        return Vector3D(this->m_matrix[i][0], this->m_matrix[i][1], this->m_matrix[i][2]);
    }
} // namespace Tobot::Math
