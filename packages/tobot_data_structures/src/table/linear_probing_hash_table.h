#pragma once

#include "../pre_compiled_header.h"

#include "../tuple/pair.h"
#include "hash_table.h"

namespace Tobot::DataStructures::Table {
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    class LinearProbingHashTable : HashTable<T, U> {
        public:
            LinearProbingHashTable();
            LinearProbingHashTable(std::size_t size);
            LinearProbingHashTable(const LinearProbingHashTable<T, U, hashFun, getSize> & hashTable);
            LinearProbingHashTable(std::initializer_list<Tobot::DataStructures::Tuple::Pair<T, U>> list);
            LinearProbingHashTable<T, U, hashFun, getSize> &
            operator=(const LinearProbingHashTable<T, U, hashFun, getSize> & hashTable);
            ~LinearProbingHashTable();
            void Insert(T key, U value);
            void Delete(T key);
            bool Contains(T key);
            U Get(T key);
            void Print();
            void Clear();
            std::size_t GetSize();
            std::size_t GetCapacity();

        private:
            std::size_t size;
            std::size_t capacity;
            std::size_t (*hashFunction)(T key, std::size_t size);
            std::size_t (*sizeFunction)(T key);
            Tobot::DataStructures::Tuple::Pair<T, U> * table;

            std::size_t Hash(T key);
            std::size_t Find(T key);
            void Resize();
            void Copy(const LinearProbingHashTable<T, U, hashFun, getSize> & hashTable);
            void DeleteTable();

    }; // class LinearProbingHashTable

    /// @brief Creates a new hash table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    LinearProbingHashTable<T, U, hashFun, getSize>::LinearProbingHashTable() {
        this->size = 0;
        this->capacity = 10;
        this->hashFunction = hashFun;
        this->sizeFunction = getSize;
        this->table = new Tobot::DataStructures::Tuple::Pair<T, U>[this->capacity];
    }

    /// @brief Creates a new hash table with the given size.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @param size The size of the hash table.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    LinearProbingHashTable<T, U, hashFun, getSize>::LinearProbingHashTable(std::size_t size) {
        this->size = 0;
        this->capacity = size > 4 ? size : 4;
        this->hashFunction = hashFun;
        this->sizeFunction = getSize;
        this->table = new Tobot::DataStructures::Tuple::Pair<T, U>[this->capacity];
    }

    /// @brief Deletes the hash table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @param hashTable The hash table to copy.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    LinearProbingHashTable<T, U, hashFun, getSize>::LinearProbingHashTable(
        const LinearProbingHashTable<T, U, hashFun, getSize> & hashTable) {
        this->Copy(hashTable);
    }

    /// @brief Creates a new hash table with the given list.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @param list The list to create the hash table from.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    LinearProbingHashTable<T, U, hashFun, getSize>::LinearProbingHashTable(
        std::initializer_list<Tobot::DataStructures::Tuple::Pair<T, U>> list) {
        this->size = 0;
        this->capacity = list.size();
        this->hashFunction = hashFun;
        this->sizeFunction = getSize;
        this->table = new Tobot::DataStructures::Tuple::Pair<T, U>[this->capacity];
        for (auto & item : list) {
            this->Insert(item.first, item.second);
        }
    }

    /// @brief Copies the given hash table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @param hashTable The hash table to copy.
    /// @return void
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    LinearProbingHashTable<T, U, hashFun, getSize> & LinearProbingHashTable<T, U, hashFun, getSize>::operator=(
        const LinearProbingHashTable<T, U, hashFun, getSize> & hashTable) {
        if (this != &hashTable) {
            this->DeleteTable();
            this->Copy(hashTable);
        }
        return *this;
    }

    /// @brief Deletes the hash table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    LinearProbingHashTable<T, U, hashFun, getSize>::~LinearProbingHashTable() {
        this->DeleteTable();
    }

    /// @brief Inserts the given key and value into the hash table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @param key The key.
    /// @param value The value.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    void LinearProbingHashTable<T, U, hashFun, getSize>::Insert(T key, U value) {
        if (this->size * 0.75 == this->capacity) {
            this->Resize();
        }
        std::size_t index = this->Hash(key);
        while (this->table[index].GetFirst() != key && this->table[index].GetFirst() != T()) {
            index = (index + 1) % this->capacity;
        }
        if (this->table[index].GetFirst() == T()) {
            this->size++;
        }
        this->table[index] = Tobot::DataStructures::Tuple::Pair<T, U>(key, value);
    }

    /// @brief Deletes the given key from the hash table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @param key The key.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    void LinearProbingHashTable<T, U, hashFun, getSize>::Delete(T key) {
        std::size_t index = this->Find(key);
        if (index == this->capacity) {
            return;
        }
        this->table[index] = Tobot::DataStructures::Tuple::Pair<T, U>();
        index = (index + 1) % this->capacity;
        while (this->table[index].GetFirst() != T()) {
            Tobot::DataStructures::Tuple::Pair<T, U> temp = this->table[index];
            this->table[index] = Tobot::DataStructures::Tuple::Pair<T, U>();
            this->size--;
            this->Insert(temp.first, temp.second);
            index = (index + 1) % this->capacity;
        }
        this->size--;
    }

    /// @brief Returns true if the hash table contains the given key.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @param key The key.
    /// @return True if the hash table contains the given key.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    bool LinearProbingHashTable<T, U, hashFun, getSize>::Contains(T key) {
        return this->Find(key) != this->capacity;
    }

    /// @brief Returns the value of the given key.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @param key The key.
    /// @return The value of the given key.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    U LinearProbingHashTable<T, U, hashFun, getSize>::Get(T key) {
        std::size_t index = this->Find(key);
        if (index == this->capacity) {
            return U();
        }
        return this->table[index].GetSecond();
    }

    /// @brief Prints the hash table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    void LinearProbingHashTable<T, U, hashFun, getSize>::Print() {
        for (std::size_t i = 0; i < this->capacity; i++) {
            std::cout << i << ": " << this->table[i].GetFirst() << " " << this->table[i].GetSecond() << std::endl;
        }
    }

    /// @brief Clears the hash table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    void LinearProbingHashTable<T, U, hashFun, getSize>::Clear() {
        this->DeleteTable();
        this->size = 0;
        this->capacity = 10;
        this->table = new Tobot::DataStructures::Tuple::Pair<T, U>[this->capacity];
    }

    /// @brief Returns the size of the hash table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @return The size of the hash table.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    std::size_t LinearProbingHashTable<T, U, hashFun, getSize>::GetSize() {
        return this->size;
    }

    /// @brief Returns the capacity of the hash table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @return The capacity of the hash table.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    std::size_t LinearProbingHashTable<T, U, hashFun, getSize>::GetCapacity() {
        return this->capacity;
    }

    /// @brief Hashes the key.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @param key The key to be hashed.
    /// @return The hashed key.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    std::size_t LinearProbingHashTable<T, U, hashFun, getSize>::Hash(T key) {
        return this->hashFunction(key, this->sizeFunction(key)) % this->capacity;
    }

    /// @brief Finds the index of the key in the hash table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @param key The key to be found.
    /// @return The index of the key in the hash table.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    std::size_t LinearProbingHashTable<T, U, hashFun, getSize>::Find(T key) {
        std::size_t index = this->Hash(key);
        while (this->table[index].GetFirst() != key && this->table[index].GetFirst() != T()) {
            index = (index + 1) % this->capacity;
        }
        if (this->table[index].GetFirst() == T()) {
            return this->capacity;
        }
        return index;
    }

    /// @brief Copies the hash table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    void LinearProbingHashTable<T, U, hashFun, getSize>::Resize() {
        LinearProbingHashTable<T, U, hashFun, getSize> temp(this->capacity * 2);
        for (std::size_t i = 0; i < this->capacity; i++) {
            if (this->table[i].GetFirst() != T()) {
                temp.Insert(this->table[i].GetFirst(), this->table[i].GetSecond());
            }
        }
        this->DeleteTable();
        this->Copy(temp);
    }

    /// @brief Deletes the table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    /// @param hashTable The hash table to copy.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    void LinearProbingHashTable<T, U, hashFun, getSize>::Copy(
        const LinearProbingHashTable<T, U, hashFun, getSize> & hashTable) {
        this->size = hashTable.size;
        this->capacity = hashTable.capacity;
        this->hashFunction = hashTable.hashFunction;
        this->table = new Tobot::DataStructures::Tuple::Pair<T, U>[this->capacity];
        for (std::size_t i = 0; i < this->capacity; i++) {
            this->table[i] = hashTable.table[i];
        }
    }

    /// @brief Deletes the table.
    /// @tparam T The type of the key.
    /// @tparam U The type of the value.
    /// @tparam hashFun The used hash function.
    template <typename T, typename U, std::size_t (*hashFun)(T val, std::size_t size), std::size_t (*getSize)(T val)>
    void LinearProbingHashTable<T, U, hashFun, getSize>::DeleteTable() {
        delete[] this->table;
    }

} // namespace Tobot::DataStructures::Table