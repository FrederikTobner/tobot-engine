#pragma once

namespace Tobot::DataStructures::Table {

    template <typename T, typename U>
    class HashTable {
        public:
            HashTable();
            virtual void Insert(T key, U value) = 0;
            virtual void Delete(T key) = 0;
            virtual bool Contains(T key) = 0;
            virtual U Get(T key) = 0;
            virtual void Print() = 0;
            virtual void Clear() = 0;
            virtual std::size_t GetSize() = 0;
    }; // class HashTable

    template <typename T, typename U>
    HashTable<T, U>::HashTable() {
    }
} // namespace Tobot::DataStructures::Table