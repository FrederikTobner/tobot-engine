#pragma once

#include "../pre_compiled_header.h"

namespace Tobot::DataStructures {

    template <typename T, typename U>
    class Pair {
        public:
            T first;
            U second;

            Pair();
            Pair(T first, U second);
            Pair(const Pair<T, U> & pair);
            bool operator==(const Pair<T, U> & pair) const;
            bool operator!=(const Pair<T, U> & pair) const;
            /// @brief Appends the pair to the ostream
            /// @param os The ostream to append the pair to
            /// @param pair The pair to append to the ostream
            /// @return std::ostream& The ostream with the pair appended
            friend std::ostream operator<<(std::ostream & os, const Pair<T, U> & pair) {
                os << "(" << pair.first << ", " << pair.second << ")";
                return os;
            }
            T & GetFirst();
            U & GetSecond();

    }; // class Pair

    /// @brief Construct a new Pair object
    /// @tparam T The type of the first element of the pair
    /// @tparam U The type of the second element of the pair
    template <typename T, typename U>
    Pair<T, U>::Pair() {
        this->first = T();
        this->second = U();
    }

    /// @brief Construct a new Pair object
    /// @tparam T The type of the first element of the pair
    /// @tparam U The type of the second element of the pair
    /// @param first The first element of the pair
    /// @param second The second element of the pair
    template <typename T, typename U>
    Pair<T, U>::Pair(T first, U second) {
        this->first = first;
        this->second = second;
    }

    /// @brief Construct a new Pair object
    /// @tparam T The type of the first element of the pair
    /// @tparam U The type of the second element of the pair
    /// @param pair The pair to copy
    template <typename T, typename U>
    Pair<T, U>::Pair(const Pair<T, U> & pair) {
        this->first = pair.first;
        this->second = pair.second;
    }

    /// @brief Compare two pair
    /// @tparam T The type of the first element of the pair
    /// @tparam U The type of the second element of the pair
    /// @param pair The pair to compare to
    /// @return true If the pair are equal
    /// @return false If the pair are not equal
    template <typename T, typename U>
    bool Pair<T, U>::operator==(const Pair<T, U> & pair) const {
        return this->first == pair.first && this->second == pair.second;
    }

    /// @brief Compare two pair
    /// @param pair The pair to compare to
    /// @return true If the pair are not equal
    template <typename T, typename U>
    bool Pair<T, U>::operator!=(const Pair<T, U> & pair) const {
        return !(*this == pair);
    }

    /// @brief Get the first element of the pair
    /// @tparam T The type of the first element of the pair
    /// @tparam U The type of the second element of the pair
    /// @return T& The first element of the pair
    template <typename T, typename U>
    T & Pair<T, U>::GetFirst() {
        return this->first;
    }

    /// @brief Get the second element of the pair
    /// @tparam T The type of the first element of the pair
    /// @tparam U The type of the second element of the pair
    /// @return U& The second element of the pair
    template <typename T, typename U>
    U & Pair<T, U>::GetSecond() {
        return this->second;
    }

} // namespace Tobot::DataStructures
