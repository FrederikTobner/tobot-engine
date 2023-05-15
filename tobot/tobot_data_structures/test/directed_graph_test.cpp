#include <gtest/gtest.h>

#include "graph/directed_graph.hpp"

using namespace Tobot::DataStructures;

// Tests whether the DirectedGraph can add an edge
TEST(DirectedGraph, CanAddEdge) {
    DirectedGraph<int> graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2);
    EXPECT_TRUE(graph.containsEdge(1, 2));
}

// Tests whether the DirectedGraph can correctly check if it contains a vertex
TEST(DirectedGraph, CanCheckIfContainsVertex) {
    DirectedGraph<int> graph({{1, 2}, {2, 3}});
    EXPECT_TRUE(graph.containsVertex(1));
    EXPECT_TRUE(graph.containsVertex(2));
    EXPECT_TRUE(graph.containsVertex(3));
    EXPECT_FALSE(graph.containsVertex(4));
}

// Tests whether the DirectedGraph can correctly check if it contains an edge
TEST(DirectedGraph, CanCheckIfContainsEdge) {
    DirectedGraph<int> graph({{1, 2}, {2, 3}});
    EXPECT_TRUE(graph.containsEdge(1, 2));
    EXPECT_TRUE(graph.containsEdge(2, 3));
    EXPECT_FALSE(graph.containsEdge(1, 3));
    EXPECT_FALSE(graph.containsEdge(3, 2));
}

// Tests whether the DirectedGraph can correctly get neighbors of a vertex
TEST(DirectedGraph, CanGetNeighbors) {
    DirectedGraph<int> graph({{1, 2}, {2, 3}});
    std::vector<int> neighbors = graph.getNeighbors(2);
    EXPECT_EQ(neighbors.size(), 1);
    EXPECT_TRUE(std::find(neighbors.begin(), neighbors.end(), 3) != neighbors.end());
}

// Tests whether the DirectedGraph can be correctly initialized with an initializer_list
TEST(DirectedGraph, CanBeInitializedWithInitializerList) {
    DirectedGraph<int> graph({{1, 2}, {2, 3}});
    EXPECT_TRUE(graph.containsVertex(1));
    EXPECT_TRUE(graph.containsVertex(2));
    EXPECT_TRUE(graph.containsVertex(3));
    EXPECT_TRUE(graph.containsEdge(1, 2));
    EXPECT_TRUE(graph.containsEdge(2, 3));
    EXPECT_FALSE(graph.containsEdge(1, 3));
    EXPECT_FALSE(graph.containsEdge(3, 2));
}

// Tests whether the DirectedGraph can add a vertex
TEST(DirectedGraph, CanAddVertex) {
    DirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    EXPECT_TRUE(leGraph.containsVertex(1));
    EXPECT_TRUE(leGraph.containsVertex(2));
    EXPECT_TRUE(leGraph.containsVertex(3));
}

// Tests whether the DirectedGraph can return all vertices
TEST(DirectedGraph, CanGetVertices) {
    DirectedGraph<int> leGraph({{1, 2}, {2, 3}, {3, 1}});
    auto vertices = leGraph.getVertices();
    std::sort(vertices.begin(), vertices.end());
    EXPECT_EQ(vertices.size(), 3);
    EXPECT_EQ(vertices[0], 1);
    EXPECT_EQ(vertices[1], 2);
    EXPECT_EQ(vertices[2], 3);
}

// Tests whether the DirectedGraph can correctly detect existing edges
TEST(DirectedGraph, CanDetectExistingEdge) {
    DirectedGraph<int> leGraph({{1, 2}, {2, 3}, {3, 1}});
    EXPECT_TRUE(leGraph.containsEdge(1, 2));
    EXPECT_TRUE(leGraph.containsEdge(2, 3));
    EXPECT_TRUE(leGraph.containsEdge(3, 1));
}

// Tests whether the DirectedGraph can correctly detect non-existing edges
TEST(DirectedGraph, CanDetectNonExistingEdge) {
    DirectedGraph<int> leGraph({{1, 2}, {2, 3}, {3, 1}});
    EXPECT_FALSE(leGraph.containsEdge(2, 1));
    EXPECT_FALSE(leGraph.containsEdge(1, 3));
    EXPECT_FALSE(leGraph.containsEdge(3, 2));
}
