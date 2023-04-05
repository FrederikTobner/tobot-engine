#include <gtest/gtest.h>

#include "tobot_data_structures.h"

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
    leTree.Insert(1);
}

/*
 * Tests whether the RedBlackTree can insert multiple elements
 */
TEST(RedBlackTree, CanInsertMultiple) {
    RedBlackTree<int> leTree;
    leTree.Insert(1);
    leTree.Insert(2);
    leTree.Insert(3);
}

/*
 * Tests whether the RedBlackTree can insert multiple elements and find them
 */
TEST(RedBlackTree, CanInsertMultipleAndFind) {
    RedBlackTree<int> leTree;
    leTree.Insert(1);
    leTree.Insert(2);
    leTree.Insert(3);
    ASSERT_EQ(leTree.Search(1)->value, 1);
    ASSERT_EQ(leTree.Search(2)->value, 2);
    ASSERT_EQ(leTree.Search(3)->value, 3);
}

/*
 * Tests whether the RedBlackTree can delete an element
 */
TEST(RedBlackTree, CanDelete) {
    RedBlackTree<int> leTree;
    leTree.Insert(1);
    leTree.Delete(1);
    ASSERT_FALSE(leTree.Contains(1));
}

/*
 * Tests whether the RedBlackTree can traverse in order
 */
TEST(RedBlackTree, TraverseInOrder) {
    RedBlackTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::queue<int> result;
    leTree.TraverseInOrder([&result](int value) { result.push(value); });

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
    leTree.TraversePreOrder([&result](int value) { result.push(value); });
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
    leTree.Clear();
    ASSERT_EQ(leTree.GetSize(), 0);
}

/*
 * Tests whether the RedBlackTree can be copied
 */
TEST(RedBlackTree, CanCopy) {
    RedBlackTree<int> leTree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    RedBlackTree<int> leTree2 = leTree;
    ASSERT_EQ(leTree.GetSize(), leTree2.GetSize());
}
