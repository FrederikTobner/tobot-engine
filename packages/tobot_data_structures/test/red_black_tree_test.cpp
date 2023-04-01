#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

TEST(redBlackTree, CanBeCreated) {
    RedBlackTree<int> tree;
}

TEST(redBlackTree, CanInsert) {
    RedBlackTree<int> tree;
    tree.Insert(1);
}

TEST(redBlackTree, CanInsertMultiple) {
    RedBlackTree<int> tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
}

TEST(redBlackTree, CanInsertMultipleAndFind) {
    RedBlackTree<int> tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    ASSERT_EQ(tree.Search(1)->value, 1);
    ASSERT_EQ(tree.Search(2)->value, 2);
    ASSERT_EQ(tree.Search(3)->value, 3);
}

TEST(redBlackTree, CanDelete) {
    RedBlackTree<int> tree;
    tree.Insert(1);
    tree.Delete(1);
    ASSERT_FALSE(tree.Contains(1));
}