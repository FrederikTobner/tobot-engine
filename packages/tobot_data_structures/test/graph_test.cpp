#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

/*
 * Tests whether the UndirectedGraph can be created
 */
TEST(UndirectedGraph, CanBeCreated) {
    UndirectedGraph<int> leGraph;
}

/*
 * Tests whether the UndirectedGraph can be created with a vector of vertices
 */
TEST(UndirectedGraph, CanBeCreatedWithVectorOfVertices) {
    UndirectedGraph<int> leGraph = {std::vector<int>{1, 2, 3, 4}};
}

/*
 * Tests whether the UndirectedGraph can be created with a initializer list of vertices
 */
TEST(UndirectedGraph, CanBeCreatedWithInitializerListOfVertices) {
    UndirectedGraph<int> leGraph = {1, 2, 3, 4};
}

/*
 * Tests whether the UndirectedGraph can be created with initializer list
 */
TEST(UndirectedGraph, CanBeCreatedWithInitializerList) {
    UndirectedGraph<int> leGraph = {{1, 2, 3, 4}, {{1, 2}, {2, 3}, {3, 1}, {4, 1}}};
}

/*
 * Tests whether the UndirectedGraph can be created with a vector of vertices and a vector of edges
 */
TEST(UndirectedGraph, CanBeCreatedWithVectorOfVerticesAndVectorOfEdges) {
    UndirectedGraph<int> leGraph = {std::vector<int>{1, 2, 3, 4},
                                    std::vector<std::pair<int, int>>{{1, 2}, {2, 3}, {3, 1}, {4, 1}}};
}

/*
 * Tests whether the UndirectedGraph can be copied
 */
TEST(UndirectedGraph, CanBeCopied) {
    UndirectedGraph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 1);
    leGraph.AddEdge(4, 1);
    UndirectedGraph<int> leGraph2 = leGraph;
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
TEST(UndirectedGraph, CanGetNeighbors) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, CanFindVertex) {
    UndirectedGraph<int> leGraph;
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
 * Tests whether the UndirectedGraph can be moved
 */
TEST(UndirectedGraph, CanBeMoved) {
    UndirectedGraph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 1);
    leGraph.AddEdge(4, 1);
    UndirectedGraph<int> leGraph2 = std::move(leGraph);
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
 * Tests whether the UndirectedGraph can add a vertex
 */
TEST(UndirectedGraph, CanAddVertex) {
    UndirectedGraph<int> leGraph;
    leGraph.AddVertex(1);
}

/*
 * Tests whether the UndirectedGraph can add multiple vertices
 */
TEST(UndirectedGraph, CanAddMultipleVertices) {
    UndirectedGraph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
}

/*
 * Tests whether the UndirectedGraph can add an edge
 */
TEST(UndirectedGraph, CanAddEdge) {
    UndirectedGraph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddEdge(1, 2);
}

/*
 * Tests whether the UndirectedGraph can add multiple edges
 */
TEST(UndirectedGraph, CanAddMultipleEdges) {
    UndirectedGraph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 1);
}

/*
 * Tests whether the UndirectedGraph can add multiple edges and remove them
 */
TEST(UndirectedGraph, CanAddMultipleEdgesAndRemove) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, CanFindEdge) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, CanFindComponent) {
    UndirectedGraph<int> leGraph;
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
 * Tests whether the UndirectedGraph can be cleared
 */
TEST(UndirectedGraph, CanClear) {
    UndirectedGraph<int> leGraph;
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
 * Tests asyclic UndirectedGraph
 */
TEST(UndirectedGraph, CanDetectAcyclic) {
    UndirectedGraph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(3, 4);
    ASSERT_TRUE(leGraph.IsAcyclic());
}

/*
 * Tests whether the UndirectedGraph can detect a cycle
 */
TEST(UndirectedGraph, CanDetectCycle) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, EqualityOperator) {
    UndirectedGraph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    UndirectedGraph<int> leGraph2;
    leGraph2.AddVertex(1);
    leGraph2.AddVertex(2);
    leGraph2.AddVertex(3);
    leGraph2.AddVertex(4);
    leGraph2.AddEdge(1, 2);
    leGraph2.AddEdge(2, 3);
    leGraph2.AddEdge(3, 4);
    leGraph2.AddEdge(4, 1);
    ASSERT_TRUE(leGraph == leGraph2);
    UndirectedGraph<int> leGraph3;
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
TEST(UndirectedGraph, InequalityOperator) {
    UndirectedGraph<int> leGraph;
    leGraph.AddVertex(1);
    leGraph.AddVertex(2);
    leGraph.AddVertex(3);
    leGraph.AddVertex(4);
    leGraph.AddEdge(1, 2);
    leGraph.AddEdge(2, 3);
    leGraph.AddEdge(3, 4);
    leGraph.AddEdge(4, 1);
    UndirectedGraph<int> leGraph2;
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
    UndirectedGraph<int> leGraph3;
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
TEST(UndirectedGraph, CanRemoveVertex) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, CanRemoveEdge) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, CanRemoveMultipleVertices) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, CanRemoveMultipleEdges) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, CanRemoveAllVertices) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, CanRemoveAllEdges) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, CanRemoveAllEdgesAndVertices) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, CanRemoveAllCycles) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, CanRemoveAllConnectedComponents) {
    UndirectedGraph<int> leGraph;
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
TEST(UndirectedGraph, CanRemoveEverything) {
    UndirectedGraph<int> leGraph;
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