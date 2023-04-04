#pragma once

#include "../pre_compiled_header.h"

namespace Tobot::DataStructures::Tuple {

    /// @brief A quadruple that contains four elements of different types
    /// @tparam T The type of the first element of the quadruple
    /// @tparam U The type of the second element of the quadruple
    /// @tparam V The type of the third element of the quadruple
    /// @tparam W The type of the fourth element of the quadruple
    template <typename T, typename U, typename V, typename W>
    class Quadruple {
        public:
            Quadruple();
            Quadruple(T first, U second, V third, W fourth);
            Quadruple(const Quadruple<T, U, V, W> & quadruple);
            bool operator==(const Quadruple<T, U, V, W> & quadruple) const;
            bool operator!=(const Quadruple<T, U, V, W> & quadruple) const;
            /// @brief Appends the quadruple to the ostream
            /// @param os The ostream to append the quadruple to
            /// @param quadruple The quadruple to append to the ostream
            /// @return std::ostream& The ostream with the quadruple appended
            friend std::ostream operator<<(std::ostream & os, const Quadruple<T, U, V, W> & quadruple) {
                os << "(" << quadruple.first << ", " << quadruple.second << ", " << quadruple.third << ", "
                   << quadruple.fourth << ")";
                return os;
            }
            T & GetFirst();
            U & GetSecond();
            V & GetThird();
            W & GetFourth();

        private:
            /// @brief The first element of the quadruple
            T first;
            /// @brief The second element of the quadruple
            U second;
            /// @brief The third element of the quadruple
            V third;
            /// @brief The fourth element of the quadruple
            W fourth;

    }; // class Quadruple

    /// @brief Construct a new Quadruple object
    /// @tparam T The type of the first element of the quadruple
    /// @tparam U The type of the second element of the quadruple
    /// @tparam V The type of the third element of the quadruple
    /// @tparam W The type of the fourth element of the quadruple
    template <typename T, typename U, typename V, typename W>
    Quadruple<T, U, V, W>::Quadruple() {
        this->first = T();
        this->second = U();
        this->third = V();
        this->fourth = W();
    }

    /// @brief Construct a new Quadruple object
    /// @tparam T The type of the first element of the quadruple
    /// @tparam U The type of the second element of the quadruple
    /// @tparam V The type of the third element of the quadruple
    /// @tparam W The type of the fourth element of the quadruple
    /// @param first The first element of the quadruple
    /// @param second The second element of the quadruple
    /// @param third The third element of the quadruple
    /// @param fourth The fourth element of the quadruple
    template <typename T, typename U, typename V, typename W>
    Quadruple<T, U, V, W>::Quadruple(T first, U second, V third, W fourth) {
        this->first = first;
        this->second = second;
        this->third = third;
        this->fourth = fourth;
    }

    /// @brief Construct a new Quadruple object
    /// @tparam T The type of the first element of the quadruple
    /// @tparam U The type of the second element of the quadruple
    /// @tparam V The type of the third element of the quadruple
    /// @tparam W The type of the fourth element of the quadruple
    /// @param quadruple The quadruple to copy
    template <typename T, typename U, typename V, typename W>
    Quadruple<T, U, V, W>::Quadruple(const Quadruple<T, U, V, W> & quadruple) {
        this->first = quadruple.first;
        this->second = quadruple.second;
        this->third = quadruple.third;
        this->fourth = quadruple.fourth;
    }

    /// @brief Compares two quadruples
    /// @tparam T The type of the first element of the quadruple
    /// @tparam U The type of the second element of the quadruple
    /// @tparam V The type of the third element of the quadruple
    /// @tparam W The type of the fourth element of the quadruple
    /// @param quadruple The quadruple to compare to
    /// @return true If the quadruples are equal
    template <typename T, typename U, typename V, typename W>
    bool Quadruple<T, U, V, W>::operator==(const Quadruple<T, U, V, W> & quadruple) const {
        return first == quadruple.first && second == quadruple.second && third == quadruple.third &&
               fourth == quadruple.fourth;
    }

    /// @brief Compares two quadruples
    /// @tparam T The type of the first element of the quadruple
    /// @tparam U The type of the second element of the quadruple
    /// @tparam V The type of the third element of the quadruple
    /// @tparam W The type of the fourth element of the quadruple
    /// @param quadruple The quadruple to compare to
    /// @return true If the quadruples are not equal
    template <typename T, typename U, typename V, typename W>
    bool Quadruple<T, U, V, W>::operator!=(const Quadruple<T, U, V, W> & quadruple) const {
        return !(*this == quadruple);
    }

    /// @brief Gets the first element of the quadruple
    /// @tparam T The type of the first element of the quadruple
    /// @tparam U The type of the second element of the quadruple
    /// @tparam V The type of the third element of the quadruple
    /// @tparam W The type of the fourth element of the quadruple
    /// @return T& The first element of the quadruple
    template <typename T, typename U, typename V, typename W>
    T & Quadruple<T, U, V, W>::GetFirst() {
        return this->first;
    }

    /// @brief Gets the second element of the quadruple
    /// @tparam T The type of the first element of the quadruple
    /// @tparam U The type of the second element of the quadruple
    /// @tparam V The type of the third element of the quadruple
    /// @tparam W The type of the fourth element of the quadruple
    /// @return U& The second element of the quadruple
    template <typename T, typename U, typename V, typename W>
    U & Quadruple<T, U, V, W>::GetSecond() {
        return this->second;
    }

    /// @brief Gets the third element of the quadruple
    /// @tparam T The type of the first element of the quadruple
    /// @tparam U The type of the second element of the quadruple
    /// @tparam V The type of the third element of the quadruple
    /// @tparam W The type of the fourth element of the quadruple
    /// @return V& The third element of the quadruple
    template <typename T, typename U, typename V, typename W>
    V & Quadruple<T, U, V, W>::GetThird() {
        return this->third;
    }

    /// @brief Gets the fourth element of the quadruple
    /// @tparam T The type of the first element of the quadruple
    /// @tparam U The type of the second element of the quadruple
    /// @tparam V The type of the third element of the quadruple
    /// @tparam W The type of the fourth element of the quadruple
    /// @return W& The fourth element of the quadruple
    template <typename T, typename U, typename V, typename W>
    W & Quadruple<T, U, V, W>::GetFourth() {
        return this->fourth;
    }

} // namespace Tobot::DataStructures::Tuple
