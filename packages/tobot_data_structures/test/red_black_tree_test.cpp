#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

/*
 * Tests whether the RedBlackTree can be created
 */
TEST(redBlackTree, CanBeCreated) {
    RedBlackTree<int> tree;
}

/*
 * Tests whether the RedBlackTree can insert a single element
 */
TEST(redBlackTree, CanInsert) {
    RedBlackTree<int> tree;
    tree.Insert(1);
}

/*
 * Tests whether the RedBlackTree can insert multiple elements
 */
TEST(redBlackTree, CanInsertMultiple) {
    RedBlackTree<int> tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
}

/*
 * Tests whether the RedBlackTree can insert multiple elements and find them
 */
TEST(redBlackTree, CanInsertMultipleAndFind) {
    RedBlackTree<int> tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    ASSERT_EQ(tree.Search(1)->value, 1);
    ASSERT_EQ(tree.Search(2)->value, 2);
    ASSERT_EQ(tree.Search(3)->value, 3);
}

/*
 * Tests whether the RedBlackTree can delete an element
 */
TEST(redBlackTree, CanDelete) {
    RedBlackTree<int> tree;
    tree.Insert(1);
    tree.Delete(1);
    ASSERT_FALSE(tree.Contains(1));
}