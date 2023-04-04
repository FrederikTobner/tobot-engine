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
 * Tests whether the Graph can be created with initializer list
 */
TEST(Graph, CanBeCreatedWithInitializerList) {
    Graph<int> graph = {{1, 2, 3, 4}, {{1, 2}, {2, 3}, {3, 1}, {4, 1}}};
}

/*
 * Tests whether the Graph can be created with a vector of vertices and a vector of edges
 */
TEST(Graph, CanBeCreatedWithVectorOfVerticesAndVectorOfEdges) {
    Graph<int> graph = {std::vector<int>{1, 2, 3, 4}, std::vector<Pair<int, int>>{{1, 2}, {2, 3}, {3, 1}, {4, 1}}};
}

/*
 * Tests whether the Graph can be copied
 */
TEST(Graph, CanBeCopied) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 1);
    graph.AddEdge(4, 1);
    Graph<int> graph2 = graph;
    ASSERT_TRUE(graph2.ContainsVertex(1));
    ASSERT_TRUE(graph2.ContainsVertex(2));
    ASSERT_TRUE(graph2.ContainsVertex(3));
    ASSERT_TRUE(graph2.ContainsVertex(4));
    ASSERT_TRUE(graph2.ContainsEdge(1, 2));
    ASSERT_TRUE(graph2.ContainsEdge(2, 3));
    ASSERT_TRUE(graph2.ContainsEdge(3, 1));
    ASSERT_TRUE(graph2.ContainsEdge(4, 1));
}

/*
 * Tests whether the neighbors of a vertex can be retrieved
 */
TEST(Graph, CanGetNeighbors) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 1);
    graph.AddEdge(4, 1);
    std::vector<int> neighbors = graph.GetNeighbors(1);
    ASSERT_EQ(3, neighbors.size());
    ASSERT_TRUE(std::find(neighbors.begin(), neighbors.end(), 2) != neighbors.end());
    ASSERT_TRUE(std::find(neighbors.begin(), neighbors.end(), 3) != neighbors.end());
    ASSERT_TRUE(std::find(neighbors.begin(), neighbors.end(), 4) != neighbors.end());
}

/*
 * Tests whether a vertex can be found
 */
TEST(Graph, CanFindVertex) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 1);
    graph.AddEdge(4, 1);
    ASSERT_TRUE(graph.ContainsVertex(1));
    ASSERT_TRUE(graph.ContainsVertex(2));
    ASSERT_TRUE(graph.ContainsVertex(3));
    ASSERT_TRUE(graph.ContainsVertex(4));
}

/*
 * Tests whether the Graph can be moved
 */
TEST(Graph, CanBeMoved) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 1);
    graph.AddEdge(4, 1);
    Graph<int> graph2 = std::move(graph);
    ASSERT_TRUE(graph2.ContainsVertex(1));
    ASSERT_TRUE(graph2.ContainsVertex(2));
    ASSERT_TRUE(graph2.ContainsVertex(3));
    ASSERT_TRUE(graph2.ContainsVertex(4));
    ASSERT_TRUE(graph2.ContainsEdge(1, 2));
    ASSERT_TRUE(graph2.ContainsEdge(2, 3));
    ASSERT_TRUE(graph2.ContainsEdge(3, 1));
    ASSERT_TRUE(graph2.ContainsEdge(4, 1));
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

/*
 * Tests whether a component can be found
 */
TEST(Graph, CanFindComponent) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 1);
    graph.AddEdge(4, 1);
    std::vector<int> component = graph.GetComponent(1);
    ASSERT_EQ(4, component.size());
    ASSERT_TRUE(std::find(component.begin(), component.end(), 1) != component.end());
    ASSERT_TRUE(std::find(component.begin(), component.end(), 2) != component.end());
    ASSERT_TRUE(std::find(component.begin(), component.end(), 3) != component.end());
    ASSERT_TRUE(std::find(component.begin(), component.end(), 4) != component.end());
}

/*
 * Tests whether the Graph can be cleared
 */
TEST(Graph, CanClear) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 1);
    graph.AddEdge(4, 1);
    graph.RemoveAllEdgesAndVertices();
    ASSERT_FALSE(graph.ContainsVertex(1));
    ASSERT_FALSE(graph.ContainsVertex(2));
    ASSERT_FALSE(graph.ContainsVertex(3));
    ASSERT_FALSE(graph.ContainsVertex(4));
    ASSERT_FALSE(graph.ContainsEdge(1, 2));
    ASSERT_FALSE(graph.ContainsEdge(2, 3));
    ASSERT_FALSE(graph.ContainsEdge(3, 1));
    ASSERT_FALSE(graph.ContainsEdge(4, 1));
}

/*
 * Tests asyclic Graph
 */
TEST(Graph, IsAcyclic) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(3, 4);
    ASSERT_TRUE(graph.IsAcyclic());
}

/*
 * Tests whether the Graph can detect a cycle
 */
TEST(Graph, CanDetectCycle) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 1);
    ASSERT_TRUE(graph.IsCyclic());
}

/*
 * Test equality operator
 */
TEST(Graph, EqualityOperator) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 1);
    Graph<int> graph2;
    graph2.AddVertex(1);
    graph2.AddVertex(2);
    graph2.AddVertex(3);
    graph2.AddVertex(4);
    graph2.AddEdge(1, 2);
    graph2.AddEdge(2, 3);
    graph2.AddEdge(3, 4);
    graph2.AddEdge(4, 1);
    ASSERT_TRUE(graph == graph2);
}

/*
 * Test inequality operator
 */
TEST(Graph, InequalityOperator) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 1);
    Graph<int> graph2;
    graph2.AddVertex(1);
    graph2.AddVertex(2);
    graph2.AddVertex(3);
    graph2.AddVertex(4);
    graph2.AddEdge(1, 2);
    graph2.AddEdge(2, 3);
    graph2.AddEdge(3, 4);
    graph2.AddEdge(4, 1);
    graph2.AddEdge(1, 3);
    ASSERT_TRUE(graph != graph2);
}

/*
 * Can remove vertex
 */
TEST(Graph, CanRemoveVertex) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 1);
    graph.RemoveVertex(1);
    ASSERT_FALSE(graph.ContainsVertex(1));
    ASSERT_FALSE(graph.ContainsEdge(1, 2));
    ASSERT_FALSE(graph.ContainsEdge(4, 1));
}

/*
 * Can remove edge
 */
TEST(Graph, CanRemoveEdge) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 1);
    graph.RemoveEdge(1, 2);
    ASSERT_FALSE(graph.ContainsEdge(1, 2));
}

/*
 * Can remove multiple vertices
 */
TEST(Graph, CanRemoveMultipleVertices) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 1);
    graph.RemoveVertices({1, 2, 3});
    ASSERT_FALSE(graph.ContainsVertex(1));
    ASSERT_FALSE(graph.ContainsVertex(2));
    ASSERT_FALSE(graph.ContainsVertex(3));
    ASSERT_TRUE(graph.ContainsVertex(4));
}

/*
 * Can remove multiple edges
 */
TEST(Graph, CanRemoveMultipleEdges) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 1);
    graph.RemoveEdges({{1, 2}, {2, 3}, {3, 4}});
    ASSERT_FALSE(graph.ContainsEdge(1, 2));
    ASSERT_FALSE(graph.ContainsEdge(2, 3));
    ASSERT_FALSE(graph.ContainsEdge(3, 4));
    ASSERT_TRUE(graph.ContainsEdge(4, 1));
}

/*
 * Can remove all vertices
 */
TEST(Graph, CanRemoveAllVertices) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 1);
    graph.RemoveAllVertices();
    ASSERT_FALSE(graph.ContainsVertex(1));
    ASSERT_FALSE(graph.ContainsVertex(2));
    ASSERT_FALSE(graph.ContainsVertex(3));
    ASSERT_FALSE(graph.ContainsVertex(4));
}

/*
 * Can remove all edges
 */
TEST(Graph, CanRemoveAllEdges) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 1);
    graph.RemoveAllEdges();
    ASSERT_FALSE(graph.ContainsEdge(1, 2));
    ASSERT_FALSE(graph.ContainsEdge(2, 3));
    ASSERT_FALSE(graph.ContainsEdge(3, 4));
    ASSERT_FALSE(graph.ContainsEdge(4, 1));
}

/*
 * Can Remove All Edges And Vertices
 */
TEST(Graph, CanRemoveAllEdgesAndVertices) {
    Graph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 1);
    graph.RemoveAllEdgesAndVertices();
    ASSERT_FALSE(graph.ContainsVertex(1));
    ASSERT_FALSE(graph.ContainsVertex(2));
    ASSERT_FALSE(graph.ContainsVertex(3));
    ASSERT_FALSE(graph.ContainsVertex(4));
    ASSERT_FALSE(graph.ContainsEdge(1, 2));
    ASSERT_FALSE(graph.ContainsEdge(2, 3));
    ASSERT_FALSE(graph.ContainsEdge(3, 4));
    ASSERT_FALSE(graph.ContainsEdge(4, 1));
}
