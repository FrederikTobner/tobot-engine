#include <gtest/gtest.h>

#include "tree/red_black_tree.hpp"

#include <queue>

using namespace Tobot::DataStructures::Tree;

/*
 * Tests whether the RedBlackTree can be created
 */
TEST(RedBlackTree, CanBeCreated) {
    RedBlackTree<int> leTree;
}

/*
 * Tests whether the RedBlackTree can insert a single element
 */
TEST(RedBlackTree, CanInsert) {
    RedBlackTree<int> leTree;
    leTree.insert(1);
}

/*
 * Tests whether the RedBlackTree can insert multiple elements
 */
TEST(RedBlackTree, CanInsertMultiple) {
    RedBlackTree<int> leTree;
    leTree.insert(1);
    leTree.insert(2);
    leTree.insert(3);
}

/*
 * Tests whether the RedBlackTree can insert multiple elements and find them
 */
TEST(RedBlackTree, CanInsertMultipleAndFind) {
    RedBlackTree<int> leTree;
    leTree.insert(1);
    leTree.insert(2);
    leTree.insert(3);
    ASSERT_EQ(leTree.search(1)->value, 1);
    ASSERT_EQ(leTree.search(2)->value, 2);
    ASSERT_EQ(leTree.search(3)->value, 3);
}

/*
 * Tests whether the RedBlackTree can delete an element
 */
TEST(RedBlackTree, CanDelete) {
    RedBlackTree<int> leTree;
    leTree.insert(1);
    leTree.remove(1);
    ASSERT_FALSE(leTree.contains(1));
}

/*
 * Tests whether the RedBlackTree can traverse in order
 */
TEST(RedBlackTree, TraverseInOrder) {
    RedBlackTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::queue<int> result;
    leTree.traverseInOrder([&result](int value) { result.push(value); });

    for (size_t i = 0; i < 10; i++) {
        ASSERT_EQ(result.front(), i + 1);
        result.pop();
    }
}

/*
 * Tests whether the RedBlackTree can traverse in pre order
 */
TEST(RedBlackTree, TraversePreOrder) {
    RedBlackTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::queue<int> result;
    leTree.traversePreOrder([&result](int value) { result.push(value); });
    ASSERT_EQ(result.front(), 4);
    result.pop();
    ASSERT_EQ(result.front(), 2);
    result.pop();
    ASSERT_EQ(result.front(), 1);
    result.pop();
    ASSERT_EQ(result.front(), 3);
    result.pop();
    ASSERT_EQ(result.front(), 6);
    result.pop();
    ASSERT_EQ(result.front(), 5);
    result.pop();
    ASSERT_EQ(result.front(), 8);
    result.pop();
    ASSERT_EQ(result.front(), 7);
    result.pop();
    ASSERT_EQ(result.front(), 9);
    result.pop();
    ASSERT_EQ(result.front(), 10);
    result.pop();
}

/*
' * Tests whether the RedBlackTree can traverse in post order
*/
TEST(RedBlackTree, TraversePostOrder) {
    RedBlackTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::queue<int> result;
    leTree.traversePostOrder([&result](int value) { result.push(value); });

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
    ASSERT_EQ(result.front(), 10);
    result.pop();
    ASSERT_EQ(result.front(), 9);
    result.pop();
    ASSERT_EQ(result.front(), 8);
    result.pop();
    ASSERT_EQ(result.front(), 6);
    result.pop();
    ASSERT_EQ(result.front(), 4);
    result.pop();
}

/*
 * Tests whether the RedBlackTree can be cleared
 */
TEST(RedBlackTree, CanClear) {
    RedBlackTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    leTree.clear();
    ASSERT_EQ(leTree.getSize(), 0);
}

/*
 * Tests whether the RedBlackTree can be copied
 */
TEST(RedBlackTree, CanCopy) {
    RedBlackTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    RedBlackTree<int> leTree2 = leTree;
    ASSERT_EQ(leTree.getSize(), leTree2.getSize());
}

/*
 * Tests whether the RedBlackTree can be iterated over
 */
TEST(RedBlackTree, CanIterate) {
    RedBlackTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::queue<int> result;
    for (auto it = leTree.begin(); it != leTree.end(); it++) {
        result.push(*it);
    }

    for (size_t i = 0; i < 10; i++) {
        ASSERT_EQ(result.front(), i + 1);
        result.pop();
    }
}