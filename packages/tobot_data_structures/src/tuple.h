#pragma once

namespace Tobot::DataStructures {

    template <typename T, typename U>
    class Tuple {
        public:
            T first;
            U second;

            Tuple(T first, U second);
    }; // class Tuple

    template <typename T, typename U>
    Tuple<T, U>::Tuple(T first, U second) {
        this->first = first;
        this->second = second;
    }

} // namespace Tobot::DataStructures
