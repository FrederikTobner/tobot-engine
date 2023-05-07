#include <gtest/gtest.h>

#include "tobot_data_structures.hpp"

using namespace Tobot::DataStructures::Tree;

/*
 * Tests whether the Tree can be created
 */
TEST(Tree, CanBeCreated) {
    Tree<int> leTree;
}

/*
 * Tests whether the Tree can insert a single element
 */
TEST(Tree, CanInsert) {
    Tree<int> leTree(new TreeNode<int>(1));
    ASSERT_EQ(leTree.getRoot()->getValue(), 1);
}

/*
 * Tests whether the Tree can insert multiple elements
 */
TEST(Tree, CanInsertMultiple) {
    Tree<int> leTree(new TreeNode<int>(1));
    leTree.getRoot()->addChild(new TreeNode<int>(2));
    leTree.getRoot()->addChild(new TreeNode<int>(3));
    ASSERT_EQ(leTree.getRoot()->getChildren()[0]->getValue(), 2);
    ASSERT_EQ(leTree.getRoot()->getChildren()[1]->getValue(), 3);
}

/*
 * Tests whether the Tree walked in order
 */
TEST(Tree, walkParentsFirst) {
    Tree<int> leTree(new TreeNode<int>(1));
    leTree.getRoot()->addChild(new TreeNode<int>(2));
    leTree.getRoot()->addChild(new TreeNode<int>(3));
    std::vector<int> leValues;
    leTree.visitParentsFirst([&leValues](TreeNode<int> * node) { leValues.push_back(node->getValue()); });
    ASSERT_EQ(leValues[0], 1);
    ASSERT_EQ(leValues[1], 2);
    ASSERT_EQ(leValues[2], 3);
}

/*
 * Tests whether the nodes at a certain depth can be found
 */
TEST(Tree, findNodesAtDepth) {
    Tree<int> leTree(new TreeNode<int>(1));
    leTree.getRoot()->addChild(new TreeNode<int>(2));
    leTree.getRoot()->addChild(new TreeNode<int>(3));
    leTree.getRoot()->getChildren()[0]->addChild(new TreeNode<int>(4));
    leTree.getRoot()->getChildren()[0]->addChild(new TreeNode<int>(5));
    leTree.getRoot()->getChildren()[1]->addChild(new TreeNode<int>(6));
    leTree.getRoot()->getChildren()[1]->addChild(new TreeNode<int>(7));
    std::vector<int> leValues;
    std::vector<TreeNode<int> *> nodes = leTree.getNodesAtDepth(2);
    ASSERT_EQ(nodes.size(), 4);
    for (int i = 0; i < nodes.size(); i++) {
        ASSERT_EQ(nodes[i]->getValue(), i + 4);
    }
}
