#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures::Tree;

/*
 * Tests whether the node in a tree can be created
 */
TEST(TreeNode, CanBeCreated) {
    TreeNode<int> leNode(1);
}

/*
 * Tests whether the node in a tree can be created with a value
 */
TEST(TreeNode, CanBeCreatedWithValue) {
    TreeNode<int> leNode(1);
    ASSERT_EQ(leNode.getValue(), 1);
}

/*
 * Tests whether another node can be added as a child
 */
TEST(TreeNode, CanBeCreatedWithValueAndChild) {

    TreeNode<int> * leChild = new TreeNode<int>(2);
    TreeNode<int> * leNode = new TreeNode<int>(1, {leChild});
    ASSERT_EQ(leNode->getChildren()[0]->getValue(), 2);
    delete leNode;
}

/*
 * Tests whether a node can be removed
 */
TEST(TreeNode, CanBeDeleted) {
    TreeNode<int> * leChild = new TreeNode<int>(2);
    TreeNode<int> * leNode = new TreeNode<int>(1, {leChild});
    leNode->removeChild(leChild);
    ASSERT_EQ(leNode->getChildren().size(), 0);
    delete leChild;
    delete leNode;
}

/*
 * Tests whether a node can be removed by index
 */
TEST(TreeNode, CanBeDeletedByIndex) {
    TreeNode<int> * leChild = new TreeNode<int>(2);
    TreeNode<int> * leNode = new TreeNode<int>(1, {leChild});
    leNode->removeChildByIndex(0);
    ASSERT_EQ(leNode->getChildren().size(), 0);
    delete leChild;
    delete leNode;
}