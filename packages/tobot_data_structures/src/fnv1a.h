#pragma once

#include "pre_compiled_header.h"

namespace Tobot::DataStructures {

    template <typename T>
    class fowler_noll_vo_hash_1a_32 {
        public:
            fowler_noll_vo_hash_1a_32();
            std::size_t operator()(T key, std::size_t size) const;
    }; // class fowler_noll_vo_hash32

    template <typename T>
    class fowler_noll_vo_hash_1a_64 {
        public:
            fowler_noll_vo_hash_1a_64();
            std::size_t operator()(T key, std::size_t size) const;
    }; // class fowler_noll_vo_hash64

    template <typename T>
    fowler_noll_vo_hash_1a_32<T>::fowler_noll_vo_hash_1a_32() {
    }

    template <typename T>
    std::size_t fowler_noll_vo_hash_1a_32<T>::operator()(T key, std::size_t size) const {
        std::size_t hash = 0x811c9dc5;
        std::size_t prime = 0x01000193;
        for (std::size_t i = 0; i < size; i++) {
            hash *= prime;
            hash ^= *(((char *)&key) + i);
        }
        return hash;
    }

    template <typename T>
    fowler_noll_vo_hash_1a_64<T>::fowler_noll_vo_hash_1a_64() {
    }

    template <typename T>
    std::size_t fowler_noll_vo_hash_1a_64<T>::operator()(T key, std::size_t size) const {
        std::size_t hash = 0xcbf29ce484222325;
        std::size_t prime = 0x100000001b3;
        for (std::size_t i = 0; i < size; i++) {
            hash *= prime;
            hash ^= *(((char *)&key) + i);
        }
        return hash;
    }

} // namespace Tobot::DataStructures