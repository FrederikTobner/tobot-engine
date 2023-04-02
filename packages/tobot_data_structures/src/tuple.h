#pragma once

#include "pre_compiled_header.h"

namespace Tobot::DataStructures {

    template <typename T, typename U>
    class Tuple {
        public:
            T first;
            U second;

            Tuple();
            Tuple(T first, U second);
            Tuple(const Tuple<T, U> & tuple);
            bool operator==(const Tuple<T, U> & tuple) const;
            bool operator!=(const Tuple<T, U> & tuple) const;
            /// @brief Appends the tuple to the ostream
            /// @param os The ostream to append the tuple to
            /// @param tuple The tuple to append to the ostream
            /// @return std::ostream& The ostream with the tuple appended
            friend std::ostream operator<<(std::ostream & os, const Tuple<T, U> & tuple) {
                os << "(" << tuple.first << ", " << tuple.second << ")";
                return os;
            }
            T & GetFirst();
            U & GetSecond();

    }; // class Tuple

    /// @brief Construct a new Tuple object
    /// @tparam T The type of the first element of the tuple
    /// @tparam U The type of the second element of the tuple
    template <typename T, typename U>
    Tuple<T, U>::Tuple() {
        this->first = T();
        this->second = U();
    }

    /// @brief Construct a new Tuple object
    /// @tparam T The type of the first element of the tuple
    /// @tparam U The type of the second element of the tuple
    /// @param first The first element of the tuple
    /// @param second The second element of the tuple
    template <typename T, typename U>
    Tuple<T, U>::Tuple(T first, U second) {
        this->first = first;
        this->second = second;
    }

    /// @brief Construct a new Tuple object
    /// @tparam T The type of the first element of the tuple
    /// @tparam U The type of the second element of the tuple
    /// @param tuple The tuple to copy
    template <typename T, typename U>
    Tuple<T, U>::Tuple(const Tuple<T, U> & tuple) {
        this->first = tuple.first;
        this->second = tuple.second;
    }

    /// @brief Compare two tuples
    /// @tparam T The type of the first element of the tuple
    /// @tparam U The type of the second element of the tuple
    /// @param tuple The tuple to compare to
    /// @return true If the tuples are equal
    /// @return false If the tuples are not equal
    template <typename T, typename U>
    bool Tuple<T, U>::operator==(const Tuple<T, U> & tuple) const {
        return this->first == tuple.first && this->second == tuple.second;
    }

    /// @brief Compare two tuples
    /// @param tuple The tuple to compare to
    /// @return true If the tuples are not equal
    template <typename T, typename U>
    bool Tuple<T, U>::operator!=(const Tuple<T, U> & tuple) const {
        return !(*this == tuple);
    }

    /// @brief Get the first element of the tuple
    /// @tparam T The type of the first element of the tuple
    /// @tparam U The type of the second element of the tuple
    /// @return T& The first element of the tuple
    template <typename T, typename U>
    T & Tuple<T, U>::GetFirst() {
        return this->first;
    }

    /// @brief Get the second element of the tuple
    /// @tparam T The type of the first element of the tuple
    /// @tparam U The type of the second element of the tuple
    /// @return U& The second element of the tuple
    template <typename T, typename U>
    U & Tuple<T, U>::GetSecond() {
        return this->second;
    }

} // namespace Tobot::DataStructures
