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
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 1);
    leGraph.addEdge(4, 1);
    UndirectedGraph<int> leGraph2 = leGraph;
    ASSERT_TRUE(leGraph2.containsVertex(1));
    ASSERT_TRUE(leGraph2.containsVertex(2));
    ASSERT_TRUE(leGraph2.containsVertex(3));
    ASSERT_TRUE(leGraph2.containsVertex(4));
    ASSERT_TRUE(leGraph2.containsEdge(1, 2));
    ASSERT_TRUE(leGraph2.containsEdge(2, 3));
    ASSERT_TRUE(leGraph2.containsEdge(3, 1));
    ASSERT_TRUE(leGraph2.containsEdge(4, 1));
}

/*
 * Tests whether the neighbors of a vertex can be retrieved
 */
TEST(UndirectedGraph, CanGetNeighbors) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 1);
    leGraph.addEdge(4, 1);
    std::vector<int> neighbors = leGraph.getNeighbors(1);
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
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 1);
    leGraph.addEdge(4, 1);
    ASSERT_TRUE(leGraph.containsVertex(1));
    ASSERT_TRUE(leGraph.containsVertex(2));
    ASSERT_TRUE(leGraph.containsVertex(3));
    ASSERT_TRUE(leGraph.containsVertex(4));
}

/*
 * Tests whether the UndirectedGraph can be moved
 */
TEST(UndirectedGraph, CanBeMoved) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 1);
    leGraph.addEdge(4, 1);
    UndirectedGraph<int> leGraph2 = std::move(leGraph);
    ASSERT_TRUE(leGraph2.containsVertex(1));
    ASSERT_TRUE(leGraph2.containsVertex(2));
    ASSERT_TRUE(leGraph2.containsVertex(3));
    ASSERT_TRUE(leGraph2.containsVertex(4));
    ASSERT_TRUE(leGraph2.containsEdge(1, 2));
    ASSERT_TRUE(leGraph2.containsEdge(2, 3));
    ASSERT_TRUE(leGraph2.containsEdge(3, 1));
    ASSERT_TRUE(leGraph2.containsEdge(4, 1));
}

/*
 * Tests whether the UndirectedGraph can add a vertex
 */
TEST(UndirectedGraph, CanAddVertex) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
}

/*
 * Tests whether the UndirectedGraph can add multiple vertices
 */
TEST(UndirectedGraph, CanAddMultipleVertices) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
}

/*
 * Tests whether the UndirectedGraph can add an edge
 */
TEST(UndirectedGraph, CanAddEdge) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addEdge(1, 2);
}

/*
 * Tests whether the UndirectedGraph can add multiple edges
 */
TEST(UndirectedGraph, CanAddMultipleEdges) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 1);
}

/*
 * Tests whether the UndirectedGraph can add multiple edges and remove them
 */
TEST(UndirectedGraph, CanAddMultipleEdgesAndRemove) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 1);
    leGraph.removeEdge(1, 2);
    leGraph.removeEdge(2, 3);
    leGraph.removeEdge(3, 1);
}

/*
 * Tests whether a edge can be found
 */
TEST(UndirectedGraph, CanFindEdge) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 1);
    leGraph.addEdge(4, 1);
    ASSERT_TRUE(leGraph.containsEdge(1, 2));
    ASSERT_TRUE(leGraph.containsEdge(2, 3));
    ASSERT_TRUE(leGraph.containsEdge(3, 1));
    ASSERT_TRUE(leGraph.containsEdge(4, 1));
    ASSERT_FALSE(leGraph.containsEdge(4, 2));
    ASSERT_FALSE(leGraph.containsEdge(4, 3));
}

/*
 * Tests whether a component can be found
 */
TEST(UndirectedGraph, CanFindComponent) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 1);
    leGraph.addEdge(4, 1);
    std::vector<int> component = leGraph.getConnectedComponent(1);
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
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 1);
    leGraph.addEdge(4, 1);
    leGraph.removeAllEdgesAndVertices();
    ASSERT_FALSE(leGraph.containsVertex(1));
    ASSERT_FALSE(leGraph.containsVertex(2));
    ASSERT_FALSE(leGraph.containsVertex(3));
    ASSERT_FALSE(leGraph.containsVertex(4));
    ASSERT_FALSE(leGraph.containsEdge(1, 2));
    ASSERT_FALSE(leGraph.containsEdge(2, 3));
    ASSERT_FALSE(leGraph.containsEdge(3, 1));
    ASSERT_FALSE(leGraph.containsEdge(4, 1));
}

/*
 * Tests asyclic UndirectedGraph
 */
TEST(UndirectedGraph, CanDetectAcyclic) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(3, 4);
    ASSERT_TRUE(leGraph.isAcyclic());
}

/*
 * Tests whether the UndirectedGraph can detect a cycle
 */
TEST(UndirectedGraph, CanDetectCycle) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    ASSERT_TRUE(leGraph.isCyclic());
}

/*
 * Test equality operator
 */
TEST(UndirectedGraph, EqualityOperator) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    UndirectedGraph<int> leGraph2;
    leGraph2.addVertex(1);
    leGraph2.addVertex(2);
    leGraph2.addVertex(3);
    leGraph2.addVertex(4);
    leGraph2.addEdge(1, 2);
    leGraph2.addEdge(2, 3);
    leGraph2.addEdge(3, 4);
    leGraph2.addEdge(4, 1);
    ASSERT_TRUE(leGraph == leGraph2);
    UndirectedGraph<int> leGraph3;
    leGraph3.addVertex(1);
    leGraph3.addVertex(2);
    leGraph3.addVertex(3);
    leGraph3.addVertex(4);
    leGraph3.addEdge(1, 2);
    leGraph3.addEdge(2, 3);
    leGraph3.addEdge(3, 4);
    leGraph3.addEdge(4, 1);
    leGraph3.addEdge(1, 3);
    ASSERT_FALSE(leGraph == leGraph3);
}

/*
 * Test inequality operator
 */
TEST(UndirectedGraph, InequalityOperator) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    UndirectedGraph<int> leGraph2;
    leGraph2.addVertex(1);
    leGraph2.addVertex(2);
    leGraph2.addVertex(3);
    leGraph2.addVertex(4);
    leGraph2.addEdge(1, 2);
    leGraph2.addEdge(2, 3);
    leGraph2.addEdge(3, 4);
    leGraph2.addEdge(4, 1);
    leGraph2.addEdge(1, 3);
    ASSERT_TRUE(leGraph != leGraph2);
    UndirectedGraph<int> leGraph3;
    leGraph3.addVertex(1);
    leGraph3.addVertex(2);
    leGraph3.addVertex(3);
    leGraph3.addVertex(4);
    leGraph3.addEdge(1, 2);
    leGraph3.addEdge(2, 3);
    leGraph3.addEdge(3, 4);
    leGraph3.addEdge(4, 1);
    ASSERT_FALSE(leGraph != leGraph3);
}

/*
 * Can remove vertex
 */
TEST(UndirectedGraph, CanRemoveVertex) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    leGraph.removeVertex(1);
    ASSERT_FALSE(leGraph.containsVertex(1));
    ASSERT_FALSE(leGraph.containsEdge(1, 2));
    ASSERT_FALSE(leGraph.containsEdge(4, 1));
}

/*
 * Can remove edge
 */
TEST(UndirectedGraph, CanRemoveEdge) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    leGraph.removeEdge(1, 2);
    ASSERT_FALSE(leGraph.containsEdge(1, 2));
}

/*
 * Can remove multiple vertices
 */
TEST(UndirectedGraph, CanRemoveMultipleVertices) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    leGraph.removeVertices({1, 2, 3});
    ASSERT_FALSE(leGraph.containsVertex(1));
    ASSERT_FALSE(leGraph.containsVertex(2));
    ASSERT_FALSE(leGraph.containsVertex(3));
    ASSERT_TRUE(leGraph.containsVertex(4));
}

/*
 * Can remove multiple edges
 */
TEST(UndirectedGraph, CanRemoveMultipleEdges) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    leGraph.removeEdges({{1, 2}, {2, 3}, {3, 4}});
    ASSERT_FALSE(leGraph.containsEdge(1, 2));
    ASSERT_FALSE(leGraph.containsEdge(2, 3));
    ASSERT_FALSE(leGraph.containsEdge(3, 4));
    ASSERT_TRUE(leGraph.containsEdge(4, 1));
}

/*
 * Can remove all vertices
 */
TEST(UndirectedGraph, CanRemoveAllVertices) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    leGraph.removeAllVertices();
    ASSERT_FALSE(leGraph.containsVertex(1));
    ASSERT_FALSE(leGraph.containsVertex(2));
    ASSERT_FALSE(leGraph.containsVertex(3));
    ASSERT_FALSE(leGraph.containsVertex(4));
}

/*
 * Can remove all edges
 */
TEST(UndirectedGraph, CanRemoveAllEdges) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    leGraph.removeAllEdges();
    ASSERT_FALSE(leGraph.containsEdge(1, 2));
    ASSERT_FALSE(leGraph.containsEdge(2, 3));
    ASSERT_FALSE(leGraph.containsEdge(3, 4));
    ASSERT_FALSE(leGraph.containsEdge(4, 1));
}

/*
 * Can Remove All Edges And Vertices
 */
TEST(UndirectedGraph, CanRemoveAllEdgesAndVertices) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    leGraph.removeAllEdgesAndVertices();
    ASSERT_FALSE(leGraph.containsVertex(1));
    ASSERT_FALSE(leGraph.containsVertex(2));
    ASSERT_FALSE(leGraph.containsVertex(3));
    ASSERT_FALSE(leGraph.containsVertex(4));
    ASSERT_FALSE(leGraph.containsEdge(1, 2));
    ASSERT_FALSE(leGraph.containsEdge(2, 3));
    ASSERT_FALSE(leGraph.containsEdge(3, 4));
    ASSERT_FALSE(leGraph.containsEdge(4, 1));
}

/*
 * Can remove all cycles
 */
TEST(UndirectedGraph, CanRemoveAllCycles) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    leGraph.addEdge(1, 3);
    ASSERT_TRUE(leGraph.isCyclic());
    leGraph.removeAllCycles();
    ASSERT_FALSE(leGraph.isCyclic());
}

/*
 * Cam remove all connected components
 */
TEST(UndirectedGraph, CanRemoveAllConnectedComponents) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    leGraph.addEdge(1, 3);
    ASSERT_EQ(leGraph.getComponents().size(), 1);
    leGraph.removeAllConnectedComponents();
    ASSERT_EQ(leGraph.getComponents().size(), 0);
}

/*
 * Can remove everything
 */
TEST(UndirectedGraph, CanRemoveEverything) {
    UndirectedGraph<int> leGraph;
    leGraph.addVertex(1);
    leGraph.addVertex(2);
    leGraph.addVertex(3);
    leGraph.addVertex(4);
    leGraph.addEdge(1, 2);
    leGraph.addEdge(2, 3);
    leGraph.addEdge(3, 4);
    leGraph.addEdge(4, 1);
    leGraph.addEdge(1, 3);
    ASSERT_EQ(leGraph.getComponents().size(), 1);
    ASSERT_TRUE(leGraph.isCyclic());
    leGraph.removeAll();
    ASSERT_EQ(leGraph.getVertexCount(), 0);
    ASSERT_EQ(leGraph.getConnectedComponentCount(), 0);
    ASSERT_FALSE(leGraph.isCyclic());
}