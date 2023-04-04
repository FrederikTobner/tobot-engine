#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures::Table;

static Tobot::DataStructures::fowler_noll_vo_hash_1a_32<int> fnv1a_32;

std::size_t hashFunWrapper(int i, std::size_t size) {
    return fnv1a_32(i, size);
}

std::size_t sizeFunWrapper(int i) {
    return sizeof(i);
}

/*
 * Testing whether the LinearProbingTable can be created
 */
TEST(LinearProbingTable, CanBeCreated) {
    LinearProbingHashTable<int, int, hashFunWrapper, sizeFunWrapper> table(1);
}

/*
 * Testing whether the LinearProbingTable can be created with initializer list
 */
TEST(LinearProbingTable, CanBeCreatedWithInitializerList) {
    LinearProbingHashTable<int, char, hashFunWrapper, sizeFunWrapper> table = {{1, 'A'}, {3, 'O'}};
}

/*
 * Testing to find a value in the LinearProbingTable
 */
TEST(LinearProbingTable, Find) {
    LinearProbingHashTable<int, char, hashFunWrapper, sizeFunWrapper> table = {{1, 'A'}, {3, 'O'}};
    ASSERT_EQ(table.Get(1), 'A');
    ASSERT_EQ(table.Get(3), 'O');
}

/*
 * Testing to remove a value in the LinearProbingTable
 */
TEST(LinearProbingTable, Remove) {
    LinearProbingHashTable<int, char, hashFunWrapper, sizeFunWrapper> table = {{1, 'A'}, {3, 'O'}};
    table.Delete(1);
    ASSERT_EQ(table.Get(1), 0);
    ASSERT_EQ(table.Get(3), 'O');
}

/*
 * Testing to clear the LinearProbingTable
 */
TEST(LinearProbingTable, Clear) {
    LinearProbingHashTable<int, char, hashFunWrapper, sizeFunWrapper> table = {{1, 'A'}, {3, 'O'}};
    table.Clear();
    ASSERT_EQ(table.Get(1), 0);
    ASSERT_EQ(table.Get(3), 0);
}