#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

/*
 * Tests whether the Graph can be created
 */
TEST(Graph, CanBeCreated) {
    Graph<int> leGraph;
}

/*
 * Tests whether the Graph can be created with a vector of vertices
 */
TEST(Graph, CanBeCreatedWithVectorOfVertices) {
    Graph<int> leGraph = {std::vector<int>{1, 2, 3, 4}};
}

/*
 * Tests whether the Graph can be created with a initializer list of vertices
 */
TEST(Graph, CanBeCreatedWithInitializerListOfVertices) {
    Graph<int> leGraph = {1, 2, 3, 4};
}

/*
 * Tests whether the Graph can be created with initializer list
 */
TEST(Graph, CanBeCreatedWithInitializerList) {
    Graph<int> leGraph = {{1, 2, 3, 4}, {{1, 2}, {2, 3}, {3, 1}, {4, 1}}};
}

/*
 * Tests whether the Graph can be created with a vector of vertices and a vector of edges
 */
TEST(Graph, CanBeCreatedWithVectorOfVerticesAndVectorOfEdges) {
    Graph<int> leGraph = {std::vector<int>{1, 2, 3, 4},
                          std::vector<std::pair<int, int>>{{1, 2}, {2, 3}, {3, 1}, {4, 1}}};
}

/*
 * Tests whether the Graph can be copied
 */
TEST(Graph, CanBeCopied) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 1);
    leGraph.AddEdge(4, 1);
    Graph<int> leGraph2 = leGraph;
    ASSERT_TRUE(leGraph2.ContainsVertex(1));
    ASSERT_TRUE(leGraph2.ContainsVertex(2));
    ASSERT_TRUE(leGraph2.ContainsVertex(3));
    ASSERT_TRUE(leGraph2.ContainsVertex(4));
    ASSERT_TRUE(leGraph2.ContainsEdge(1, 2));
    ASSERT_TRUE(leGraph2.ContainsEdge(2, 3));
    ASSERT_TRUE(leGraph2.ContainsEdge(3, 1));
    ASSERT_TRUE(leGraph2.ContainsEdge(4, 1));
}

/*
 * Tests whether the neighbors of a vertex can be retrieved
 */
TEST(Graph, CanGetNeighbors) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 1);
    leGraph.AddEdge(4, 1);
    std::vector<int> neighbors = leGraph.GetNeighbors(1);
    ASSERT_EQ(3, neighbors.size());
    ASSERT_TRUE(std::find(neighbors.begin(), neighbors.end(), 2) != neighbors.end());
    ASSERT_TRUE(std::find(neighbors.begin(), neighbors.end(), 3) != neighbors.end());
    ASSERT_TRUE(std::find(neighbors.begin(), neighbors.end(), 4) != neighbors.end());
}

/*
 * Tests whether a vertex can be found
 */
TEST(Graph, CanFindVertex) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 1);
    leGraph.AddEdge(4, 1);
    ASSERT_TRUE(leGraph.ContainsVertex(1));
    ASSERT_TRUE(leGraph.ContainsVertex(2));
    ASSERT_TRUE(leGraph.ContainsVertex(3));
    ASSERT_TRUE(leGraph.ContainsVertex(4));
}

/*
 * Tests whether the Graph can be moved
 */
TEST(Graph, CanBeMoved) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 1);
    leGraph.AddEdge(4, 1);
    Graph<int> leGraph2 = std::move(leGraph);
    ASSERT_TRUE(leGraph2.ContainsVertex(1));
    ASSERT_TRUE(leGraph2.ContainsVertex(2));
    ASSERT_TRUE(leGraph2.ContainsVertex(3));
    ASSERT_TRUE(leGraph2.ContainsVertex(4));
    ASSERT_TRUE(leGraph2.ContainsEdge(1, 2));
    ASSERT_TRUE(leGraph2.ContainsEdge(2, 3));
    ASSERT_TRUE(leGraph2.ContainsEdge(3, 1));
    ASSERT_TRUE(leGraph2.ContainsEdge(4, 1));
}

/*
 * Tests whether the Graph can add a vertex
 */
TEST(Graph, CanAddVertex) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
}

/*
 * Tests whether the Graph can add multiple vertices
 */
TEST(Graph, CanAddMultipleVertices) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
}

/*
 * Tests whether the Graph can add an edge
 */
TEST(Graph, CanAddEdge) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddEdge(1, 2);
}

/*
 * Tests whether the Graph can add multiple edges
 */
TEST(Graph, CanAddMultipleEdges) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 1);
}

/*
 * Tests whether the Graph can add multiple edges and remove them
 */
TEST(Graph, CanAddMultipleEdgesAndRemove) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 1);
    leGraph.RemoveEdge(1, 2);
    leGraph.RemoveEdge(2, 3);
    leGraph.RemoveEdge(3, 1);
}

/*
 * Tests whether a edge can be found
 */
TEST(Graph, CanFindEdge) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 1);
    leGraph.AddEdge(4, 1);
    ASSERT_TRUE(leGraph.ContainsEdge(1, 2));
    ASSERT_TRUE(leGraph.ContainsEdge(2, 3));
    ASSERT_TRUE(leGraph.ContainsEdge(3, 1));
    ASSERT_TRUE(leGraph.ContainsEdge(4, 1));
    ASSERT_FALSE(leGraph.ContainsEdge(4, 2));
    ASSERT_FALSE(leGraph.ContainsEdge(4, 3));
}

/*
 * Tests whether a component can be found
 */
TEST(Graph, CanFindComponent) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 1);
    leGraph.AddEdge(4, 1);
    std::vector<int> component = leGraph.GetConnectedComponent(1);
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
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 1);
    leGraph.AddEdge(4, 1);
    leGraph.RemoveAllEdgesAndVertices();
    ASSERT_FALSE(leGraph.ContainsVertex(1));
    ASSERT_FALSE(leGraph.ContainsVertex(2));
    ASSERT_FALSE(leGraph.ContainsVertex(3));
    ASSERT_FALSE(leGraph.ContainsVertex(4));
    ASSERT_FALSE(leGraph.ContainsEdge(1, 2));
    ASSERT_FALSE(leGraph.ContainsEdge(2, 3));
    ASSERT_FALSE(leGraph.ContainsEdge(3, 1));
    ASSERT_FALSE(leGraph.ContainsEdge(4, 1));
}

/*
 * Tests asyclic Graph
 */
TEST(Graph, CanDetectAcyclic) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(3, 4);
    ASSERT_TRUE(leGraph.IsAcyclic());
}

/*
 * Tests whether the Graph can detect a cycle
 */
TEST(Graph, CanDetectCycle) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    ASSERT_TRUE(leGraph.IsCyclic());
}

/*
 * Test equality operator
 */
TEST(Graph, EqualityOperator) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    Graph<int> leGraph2;
    leGraph2.AddVertex(1);
    leGraph2.AddVertex(2);
    leGraph2.AddVertex(3);
    leGraph2.AddVertex(4);
    leGraph2.AddEdge(1, 2);
    leGraph2.AddEdge(2, 3);
    leGraph2.AddEdge(3, 4);
    leGraph2.AddEdge(4, 1);
    ASSERT_TRUE(leGraph == leGraph2);
    Graph<int> leGraph3;
    leGraph3.AddVertex(1);
    leGraph3.AddVertex(2);
    leGraph3.AddVertex(3);
    leGraph3.AddVertex(4);
    leGraph3.AddEdge(1, 2);
    leGraph3.AddEdge(2, 3);
    leGraph3.AddEdge(3, 4);
    leGraph3.AddEdge(4, 1);
    leGraph3.AddEdge(1, 3);
    ASSERT_FALSE(leGraph == leGraph3);
}

/*
 * Test inequality operator
 */
TEST(Graph, InequalityOperator) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    Graph<int> leGraph2;
    leGraph2.AddVertex(1);
    leGraph2.AddVertex(2);
    leGraph2.AddVertex(3);
    leGraph2.AddVertex(4);
    leGraph2.AddEdge(1, 2);
    leGraph2.AddEdge(2, 3);
    leGraph2.AddEdge(3, 4);
    leGraph2.AddEdge(4, 1);
    leGraph2.AddEdge(1, 3);
    ASSERT_TRUE(leGraph != leGraph2);
    Graph<int> leGraph3;
    leGraph3.AddVertex(1);
    leGraph3.AddVertex(2);
    leGraph3.AddVertex(3);
    leGraph3.AddVertex(4);
    leGraph3.AddEdge(1, 2);
    leGraph3.AddEdge(2, 3);
    leGraph3.AddEdge(3, 4);
    leGraph3.AddEdge(4, 1);
    ASSERT_FALSE(leGraph != leGraph3);
}

/*
 * Can remove vertex
 */
TEST(Graph, CanRemoveVertex) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    leGraph.RemoveVertex(1);
    ASSERT_FALSE(leGraph.ContainsVertex(1));
    ASSERT_FALSE(leGraph.ContainsEdge(1, 2));
    ASSERT_FALSE(leGraph.ContainsEdge(4, 1));
}

/*
 * Can remove edge
 */
TEST(Graph, CanRemoveEdge) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    leGraph.RemoveEdge(1, 2);
    ASSERT_FALSE(leGraph.ContainsEdge(1, 2));
}

/*
 * Can remove multiple vertices
 */
TEST(Graph, CanRemoveMultipleVertices) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    leGraph.RemoveVertices({1, 2, 3});
    ASSERT_FALSE(leGraph.ContainsVertex(1));
    ASSERT_FALSE(leGraph.ContainsVertex(2));
    ASSERT_FALSE(leGraph.ContainsVertex(3));
    ASSERT_TRUE(leGraph.ContainsVertex(4));
}

/*
 * Can remove multiple edges
 */
TEST(Graph, CanRemoveMultipleEdges) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    leGraph.RemoveEdges({{1, 2}, {2, 3}, {3, 4}});
    ASSERT_FALSE(leGraph.ContainsEdge(1, 2));
    ASSERT_FALSE(leGraph.ContainsEdge(2, 3));
    ASSERT_FALSE(leGraph.ContainsEdge(3, 4));
    ASSERT_TRUE(leGraph.ContainsEdge(4, 1));
}

/*
 * Can remove all vertices
 */
TEST(Graph, CanRemoveAllVertices) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    leGraph.RemoveAllVertices();
    ASSERT_FALSE(leGraph.ContainsVertex(1));
    ASSERT_FALSE(leGraph.ContainsVertex(2));
    ASSERT_FALSE(leGraph.ContainsVertex(3));
    ASSERT_FALSE(leGraph.ContainsVertex(4));
}

/*
 * Can remove all edges
 */
TEST(Graph, CanRemoveAllEdges) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    leGraph.RemoveAllEdges();
    ASSERT_FALSE(leGraph.ContainsEdge(1, 2));
    ASSERT_FALSE(leGraph.ContainsEdge(2, 3));
    ASSERT_FALSE(leGraph.ContainsEdge(3, 4));
    ASSERT_FALSE(leGraph.ContainsEdge(4, 1));
}

/*
 * Can Remove All Edges And Vertices
 */
TEST(Graph, CanRemoveAllEdgesAndVertices) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    leGraph.RemoveAllEdgesAndVertices();
    ASSERT_FALSE(leGraph.ContainsVertex(1));
    ASSERT_FALSE(leGraph.ContainsVertex(2));
    ASSERT_FALSE(leGraph.ContainsVertex(3));
    ASSERT_FALSE(leGraph.ContainsVertex(4));
    ASSERT_FALSE(leGraph.ContainsEdge(1, 2));
    ASSERT_FALSE(leGraph.ContainsEdge(2, 3));
    ASSERT_FALSE(leGraph.ContainsEdge(3, 4));
    ASSERT_FALSE(leGraph.ContainsEdge(4, 1));
}

/*
 * Can remove all cycles
 */
TEST(Graph, CanRemoveAllCycles) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    leGraph.AddEdge(1, 3);
    ASSERT_TRUE(leGraph.IsCyclic());
    leGraph.RemoveAllCycles();
    ASSERT_FALSE(leGraph.IsCyclic());
}

/*
 * Cam remove all connected components
 */
TEST(Graph, CanRemoveAllConnectedComponents) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    leGraph.AddEdge(1, 3);
    ASSERT_EQ(leGraph.GetComponents().size(), 1);
    leGraph.RemoveAllConnectedComponents();
    ASSERT_EQ(leGraph.GetComponents().size(), 0);
}

/*
 * Can remove everything
 */
TEST(Graph, CanRemoveEverything) {
    Graph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    leGraph.AddEdge(1, 3);
    ASSERT_EQ(leGraph.GetComponents().size(), 1);
    ASSERT_TRUE(leGraph.IsCyclic());
    leGraph.RemoveAll();
    ASSERT_EQ(leGraph.GetVertexCount(), 0);
    ASSERT_EQ(leGraph.GetConnectedComponentCount(), 0);
    ASSERT_FALSE(leGraph.IsCyclic());
}