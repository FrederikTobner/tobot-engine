#pragma once

#include "pre_compiled_header.h"

namespace Tobot::DataStructures {

    template <typename T, typename U>
    class Tuple {
        public:
            T first;
            U second;

            Tuple(T first, U second);
            /// @brief Appends the tuple to the ostream
            /// @param os The ostream to append the tuple to
            /// @param tuple The tuple to append to the ostream
            /// @return std::ostream& The ostream with the tuple appended
            friend std::ostream operator<<(std::ostream & os, const Tuple<T, U> & tuple) {
                os << "(" << tuple.first << ", " << tuple.second << ")";
                return os;
            }

    }; // class Tuple

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

} // namespace Tobot::DataStructures
