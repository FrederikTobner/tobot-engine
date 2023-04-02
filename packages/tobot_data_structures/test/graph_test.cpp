#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

/*
 * Tests whether the Graph can be created
 */
TEST(Graph, CanBeCreated) {
    Graph<int> graph;
}

/*
 * Tests whether the Graph can add a vertex
 */
TEST(Graph, CanAddVertex) {
    Graph<int> graph;
    graph.AddVertex(1);
}

/*
 * Tests whether the Graph can add multiple vertices
 */
TEST(Graph, CanAddMultipleVertices) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
}

/*
 * Tests whether the Graph can add an edge
 */
TEST(Graph, CanAddEdge) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddEdge(1, 2);
}

/*
 * Tests whether the Graph can add multiple edges
 */
TEST(Graph, CanAddMultipleEdges) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 1);
}

/*
 * Tests whether the Graph can add multiple edges and remove them
 */
TEST(Graph, CanAddMultipleEdgesAndRemove) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 1);
    graph.RemoveEdge(1, 2);
    graph.RemoveEdge(2, 3);
    graph.RemoveEdge(3, 1);
}

/*
 * Tests whether a edge can be found
 */
TEST(Graph, CanFindEdge) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 1);
    graph.AddEdge(4, 1);
    ASSERT_TRUE(graph.ContainsEdge(1, 2));
    ASSERT_TRUE(graph.ContainsEdge(2, 3));
    ASSERT_TRUE(graph.ContainsEdge(3, 1));
    ASSERT_TRUE(graph.ContainsEdge(4, 1));
    ASSERT_FALSE(graph.ContainsEdge(4, 2));
    ASSERT_FALSE(graph.ContainsEdge(4, 3));
}