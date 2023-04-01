#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

/*
 * Tests whether the AVLTree can be created
 */
TEST(AVLTree, CanBeCreated) {
    AVLTree<int> tree;
}

/*
 * Tests whether the AVLTree can insert a single element
 */
TEST(avlTree, CanInsert) {
    AVLTree<int> tree;
    tree.Insert(1);
}

/*
 * Tests whether the AVLTree can insert multiple elements
 */
TEST(AVLTree, CanInsertMultiple) {
    AVLTree<int> tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
}

/*
 * Tests whether the AVLTree can insert multiple elements and find them
 */
TEST(AVLTree, CanInsertMultipleAndFind) {
    AVLTree<int> tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    ASSERT_EQ(tree.Search(1)->value, 1);
    ASSERT_EQ(tree.Search(2)->value, 2);
    ASSERT_EQ(tree.Search(3)->value, 3);
}

/*
 * Tests whether the AVLTree can delete an element
 */
TEST(AVLTree, CanDelete) {
    AVLTree<int> tree;
    tree.Insert(1);
    tree.Delete(1);
    ASSERT_FALSE(tree.Contains(1));
}