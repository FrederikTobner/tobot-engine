#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

/*
 * Tests whether the Stack can be created
 */
TEST(Stack, CanBeCreated) {
    Stack<int> stack;
}

/*
 * Tests whether the Stack can push an element
 */
TEST(Stack, CanPush) {
    Stack<int> stack;
    stack.Push(1);
}

/*
 * Tests whether the Stack can push multiple elements
 */
TEST(Stack, CanPushMultiple) {
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
}

/*
 * Tests whether the Stack can push multiple elements and pop them
 */
TEST(Stack, CanPushMultipleAndPop) {
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    ASSERT_EQ(stack.Pop(), 3);
    ASSERT_EQ(stack.Pop(), 2);
    ASSERT_EQ(stack.Pop(), 1);
}

/*
 * Tests whether the Stack can be cleared
 */
TEST(Stack, CanClear) {
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Clear();
    ASSERT_EQ(stack.GetSize(), 0);
}
