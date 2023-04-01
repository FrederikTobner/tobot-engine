#pragma once

#include "pre_compiled_header.h"

namespace Tobot::DataStructures {

    template <typename T, typename U>
    class Tuple {
        public:
            T first;
            U second;

            Tuple(T first, U second);
            friend std::ostream operator<<(std::ostream & os, const Tuple<T, U> & tuple) {
                os << "(" << tuple.first << ", " << tuple.second << ")";
                return os;
            }

    }; // class Tuple

    template <typename T, typename U>
    Tuple<T, U>::Tuple(T first, U second) {
        this->first = first;
        this->second = second;
    }

} // namespace Tobot::DataStructures
