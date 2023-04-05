#include <gtest/gtest.h>

#include "tobot_data_structures.h"

#include <queue>

using namespace Tobot::DataStructures::Tree;

/*
 * Tests whether the AVLTree can be created
 */
TEST(AVLTree, CanBeCreated) {
    AVLTree<int> leTree;
}

// Tests whehter the AVLTree can be copied
TEST(AVLTree, CanBeCopied) {
    AVLTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    AVLTree<int> copy = leTree;
    ASSERT_EQ(10, copy.GetSize());
}

/*
 * Tests whether the AVLTree can insert a single element
 */
TEST(AVLTree, CanInsert) {
    AVLTree<int> leTree;
    leTree.Insert(1);
}

/*
 * Tests whether the AVLTree can insert multiple elements
 */
TEST(AVLTree, CanInsertMultiple) {
    AVLTree<int> leTree;
    leTree.Insert(1);
    leTree.Insert(2);
    leTree.Insert(3);
}

/*
 * Tests whether the AVLTree can insert multiple elements and find them
 */
TEST(AVLTree, CanInsertMultipleAndFind) {
    AVLTree<int> leTree;
    leTree.Insert(1);
    leTree.Insert(2);
    leTree.Insert(3);
    ASSERT_EQ(leTree.Search(1)->value, 1);
    ASSERT_EQ(leTree.Search(2)->value, 2);
    ASSERT_EQ(leTree.Search(3)->value, 3);
}

/*
 * Tests whether the AVLTree can delete an element
 */
TEST(AVLTree, CanDelete) {
    AVLTree<int> leTree;
    leTree.Insert(1);
    leTree.Delete(1);
    ASSERT_FALSE(leTree.Contains(1));
}

/*
 * Tests whether the AVLTree can be traversed in order
 */
TEST(AVLTree, TraverseInOrder) {
    AVLTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::queue<int> result;
    leTree.TraverseInOrder([&result](int value) { result.push(value); });
    for (size_t i = 0; i < 10; i++) {
        ASSERT_EQ(result.front(), i + 1);
        result.pop();
    }
}

/*
 * Tests whether the AVLTree can be traversed in pre order
 */
TEST(AVLTree, TraversePreOrder) {
    AVLTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::queue<int> result;
    leTree.TraversePreOrder([&result](int value) { result.push(value); });
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

/*
 * Tests whether the AVLTree can be traversed in post order
 */
TEST(AVLTree, TraversePostOrder) {
    AVLTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::queue<int> result;
    leTree.TraversePostOrder([&result](int value) { result.push(value); });
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

/*
 * Tests whether the AVLTree can be cleared
 */
TEST(AVLTree, Clear) {
    AVLTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    leTree.Clear();
    ASSERT_EQ(leTree.GetSize(), 0);
}
