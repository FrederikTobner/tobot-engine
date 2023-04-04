#pragma once

#include "../pre_compiled_header.h"

namespace Tobot::DataStructures::Tuple {

    /// @brief A triple containing three elements of different types
    /// @tparam T The type of the first element of the triple
    /// @tparam U The type of the second element of the triple
    /// @tparam V The type of the third element of the triple
    template <typename T, typename U, typename V>
    class Triple {
        public:
            Triple();
            Triple(T first, U second, V third);
            Triple(const Triple<T, U, V> & triple);
            bool operator==(const Triple<T, U, V> & triple) const;
            bool operator!=(const Triple<T, U, V> & triple) const;
            /// @brief Appends the triple to the ostream
            /// @param os The ostream to append the triple to
            /// @param triple The triple to append to the ostream
            /// @return std::ostream& The ostream with the triple appended
            friend std::ostream operator<<(std::ostream & os, const Triple<T, U, V> & triple) {
                os << "(" << triple.first << ", " << triple.second << ", " << triple.third << ")";
                return os;
            }
            T & GetFirst();
            U & GetSecond();
            V & GetThird();

        private:
            /// @brief The first element of the triple
            T first;
            /// @brief The second element of the triple
            U second;
            /// @brief The third element of the triple
            V third;

    }; // class Triple

    /// @brief Construct a new Triple object
    /// @tparam T The type of the first element of the triple
    /// @tparam U The type of the second element of the triple
    /// @tparam V The type of the third element of the triple
    template <typename T, typename U, typename V>
    Triple<T, U, V>::Triple() {
        this->first = T();
        this->second = U();
        this->third = V();
    }

    /// @brief Construct a new Triple object
    /// @tparam T The type of the first element of the triple
    /// @tparam U The type of the second element of the triple
    /// @tparam V The type of the third element of the triple
    /// @param first The first element of the triple
    /// @param second The second element of the triple
    /// @param third The third element of the triple
    template <typename T, typename U, typename V>
    Triple<T, U, V>::Triple(T first, U second, V third) {
        this->first = first;
        this->second = second;
        this->third = third;
    }

    /// @brief Construct a new Triple object
    /// @tparam T The type of the first element of the triple
    /// @tparam U The type of the second element of the triple
    /// @tparam V The type of the third element of the triple
    /// @param triple The triple to copy
    template <typename T, typename U, typename V>
    Triple<T, U, V>::Triple(const Triple<T, U, V> & triple) {
        this->first = triple.first;
        this->second = triple.second;
        this->third = triple.third;
    }

    /// @brief Compares two triples
    /// @tparam T The type of the first element of the triple
    /// @tparam U The type of the second element of the triple
    /// @tparam V The type of the third element of the triple
    /// @param triple The triple to compare to
    /// @return true If the triples are equal
    /// @return false If the triples are not equal
    template <typename T, typename U, typename V>
    bool Triple<T, U, V>::operator==(const Triple<T, U, V> & triple) const {
        return this->first == triple.first && this->second == triple.second && this->third == triple.third;
    }

    /// @brief Compares two triples
    /// @tparam T The type of the first element of the triple
    /// @tparam U The type of the second element of the triple
    /// @tparam V The type of the third element of the triple
    /// @param triple The triple to compare to
    /// @return true If the triples are not equal
    /// @return false If the triples are equal
    template <typename T, typename U, typename V>
    bool Triple<T, U, V>::operator!=(const Triple<T, U, V> & triple) const {
        return !(*this == triple);
    }

    /// @brief Gets the first element of the triple
    /// @tparam T The type of the first element of the triple
    /// @tparam U The type of the second element of the triple
    /// @tparam V The type of the third element of the triple
    /// @return T& The first element of the triple
    template <typename T, typename U, typename V>
    T & Triple<T, U, V>::GetFirst() {
        return this->first;
    }

    /// @brief Gets the second element of the triple
    /// @tparam T The type of the first element of the triple
    /// @tparam U The type of the second element of the triple
    /// @tparam V The type of the third element of the triple
    /// @return U& The second element of the triple
    template <typename T, typename U, typename V>
    U & Triple<T, U, V>::GetSecond() {
        return this->second;
    }

    /// @brief Gets the third element of the triple
    /// @tparam T The type of the first element of the triple
    /// @tparam U The type of the second element of the triple
    /// @tparam V The type of the third element of the triple
    /// @return V& The third element of the triple
    template <typename T, typename U, typename V>
    V & Triple<T, U, V>::GetThird() {
        return this->third;
    }

} // namespace Tobot::DataStructures::Tuple
