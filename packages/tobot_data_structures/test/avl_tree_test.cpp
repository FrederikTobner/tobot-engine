#include <gtest/gtest.h>

#include "tobot_data_structures.h"

#include <queue>

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

TEST(AVLTree, TraverseInOrder) {
    AVLTree<int> tree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::queue<int> result;
    tree.TraverseInOrder([&result](int value) { result.push(value); });
    for (size_t i = 0; i < 10; i++) {
        ASSERT_EQ(result.front(), i + 1);
        result.pop();
    }
}

TEST(AVLTree, TraversePreOrder) {
    AVLTree<int> tree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::queue<int> result;
    tree.TraversePreOrder([&result](int value) { result.push(value); });
    ASSERT_EQ(result.front(), 4);
    result.pop();
    ASSERT_EQ(result.front(), 2);
    result.pop();
    ASSERT_EQ(result.front(), 1);
    result.pop();
    ASSERT_EQ(result.front(), 3);
    result.pop();
    ASSERT_EQ(result.front(), 8);
    result.pop();
    ASSERT_EQ(result.front(), 6);
    result.pop();
    ASSERT_EQ(result.front(), 5);
    result.pop();
    ASSERT_EQ(result.front(), 7);
    result.pop();
    ASSERT_EQ(result.front(), 9);
    result.pop();
    ASSERT_EQ(result.front(), 10);
    result.pop();
}

TEST(AVLTree, TraversePostOrder) {
    AVLTree<int> tree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::queue<int> result;
    tree.TraversePostOrder([&result](int value) { result.push(value); });
    ASSERT_EQ(result.front(), 1);
    result.pop();
    ASSERT_EQ(result.front(), 3);
    result.pop();
    ASSERT_EQ(result.front(), 2);
    result.pop();
    ASSERT_EQ(result.front(), 5);
    result.pop();
    ASSERT_EQ(result.front(), 7);
    result.pop();
    ASSERT_EQ(result.front(), 6);
    result.pop();
    ASSERT_EQ(result.front(), 10);
    result.pop();
    ASSERT_EQ(result.front(), 9);
    result.pop();
    ASSERT_EQ(result.front(), 8);
    result.pop();
    ASSERT_EQ(result.front(), 4);
    result.pop();
}
