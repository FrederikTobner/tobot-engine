#include <gtest/gtest.h>

#include "tobot_data_structures.h"

#include <queue>

using namespace Tobot::DataStructures;

/*
 * Tests whether the Queue can be created
 */
TEST(Queue, CanBeCreated) {
    Queue<int> queue;
}

/*
 * Tests whether the Queue can enqueue an element
 */
TEST(Queue, CanEnqueue) {
    Queue<int> queue;
    queue.Enqueue(1);
}

/*
 * Tests whether the Queue can enqueue multiple elements
 */
TEST(Queue, CanEnqueueMultiple) {
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
}

/*
 * Tests whether the Queue can enqueue multiple elements and dequeue them
 */
TEST(Queue, CanEnqueueMultipleAndDequeue) {
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    ASSERT_EQ(queue.Dequeue(), 1);
    ASSERT_EQ(queue.Dequeue(), 2);
    ASSERT_EQ(queue.Dequeue(), 3);
}

/*
 * Tests whether the Queue can enqueue multiple elements and dequeue them
 */
TEST(Queue, CanEnqueueMultipleAndDequeueMultiple) {
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    ASSERT_EQ(queue.Dequeue(), 1);
    ASSERT_EQ(queue.Dequeue(), 2);
    queue.Enqueue(4);
    queue.Enqueue(5);
    ASSERT_EQ(queue.Dequeue(), 3);
    ASSERT_EQ(queue.Dequeue(), 4);
    ASSERT_EQ(queue.Dequeue(), 5);
}