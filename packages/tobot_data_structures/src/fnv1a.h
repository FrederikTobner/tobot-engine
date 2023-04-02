#pragma once

#include "pre_compiled_header.h"

namespace Tobot::DataStructures {

    template <typename T>
    class fowler_noll_vo_hash32 {
        public:
            fowler_noll_vo_hash32();
            std::size_t operator()(T key, std::size_t size) const;
            std::size_t Hash(T key, std::size_t size) const;

    }; // class fowler_noll_vo_hash32

    template <typename T>
    class fowler_noll_vo_hash64 {
        public:
            fowler_noll_vo_hash64();
            std::size_t operator()(T key, std::size_t size) const;
            std::size_t Hash(T key, std::size_t size) const;

    }; // class fowler_noll_vo_hash64

    template <typename T>
    fowler_noll_vo_hash32<T>::fowler_noll_vo_hash32() {
    }

    template <typename T>
    std::size_t fowler_noll_vo_hash32<T>::operator()(T key, std::size_t size) const {
        std::size_t hash = 0x811c9dc5;
        std::size_t prime = 0x01000193;
        for (std::size_t i = 0; i < size; i++) {
            hash = hash ^ *(((char *)&key) + i);
            hash = hash * prime;
        }
        return hash;
    }

    template <typename T>
    std::size_t fowler_noll_vo_hash32<T>::Hash(T key, std::size_t size) const {
        return this->operator()(key, size);
    }

    template <typename T>
    fowler_noll_vo_hash64<T>::fowler_noll_vo_hash64() {
    }

    template <typename T>
    std::size_t fowler_noll_vo_hash64<T>::operator()(T key, std::size_t size) const {
        std::size_t hash = 0xcbf29ce484222325;
        std::size_t prime = 0x100000001b3;
        for (std::size_t i = 0; i < size; i++) {
            hash = hash ^ *(((char *)&key) + i);
            hash = hash * prime;
        }
        return hash;
    }

    template <typename T>
    std::size_t fowler_noll_vo_hash64<T>::Hash(T key, std::size_t size) const {
        return this->operator()(key, size);
    }

} // namespace Tobot::DataStructures