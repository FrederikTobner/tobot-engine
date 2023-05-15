#pragma once

#include "../pre_compiled_header.hpp"

namespace Tobot::DataStructures {

    template <typename T>
    class DirectedGraph {
        public:
            DirectedGraph();
            DirectedGraph(std::initializer_list<std::pair<T, T>> edges);

            ~DirectedGraph();

            void addVertex(T vertex);
            void addEdge(T source, T destination);
            bool containsVertex(T vertex) const;
            bool containsEdge(T source, T destination) const;
            std::vector<T> getVertices() const;
            std::vector<T> getNeighbors(T vertex) const;

        private:
            std::map<T, std::vector<T>> adjacencyList;
    };

    template <typename T>
    DirectedGraph<T>::DirectedGraph() {
    }

    template <typename T>
    DirectedGraph<T>::DirectedGraph(std::initializer_list<std::pair<T, T>> edges) {
        for (const auto & edge : edges) {
            addVertex(edge.first);
            addVertex(edge.second);
            addEdge(edge.first, edge.second);
        }
    }

    template <typename T>
    DirectedGraph<T>::~DirectedGraph() {
    }

    /// @brief Adds a node to the graph
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex the vertex to add
    template <typename T>
    void DirectedGraph<T>::addVertex(T vertex) {
        if (!containsVertex(vertex)) {
            adjacencyList[vertex] = std::vector<T>();
        }
    }

    /// @brief Adds an edge to the directed graph
    /// @tparam T The type of the vertices in the graph.
    /// @param source The source node of the edge.
    /// @param destination The destination node of the edge.
    template <typename T>
    void DirectedGraph<T>::addEdge(T source, T destination) {
        adjacencyList[source].push_back(destination);
    }

    /// @brief Checks if the directed graph contains the given vertex
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to be checked for presence.
    /// @return True if the vertex is present, False otherwise.
    template <typename T>
    bool DirectedGraph<T>::containsVertex(T vertex) const {
        return adjacencyList.find(vertex) != adjacencyList.end();
    }

    /// @brief Checks if the directed graph contains the given edge
    /// @tparam T The type of the vertices in the graph.
    /// @param source The source node of the edge.
    /// @param destination The destination node of the edge.
    /// @return True if the edge is present, False otherwise.
    template <typename T>
    bool DirectedGraph<T>::containsEdge(T source, T destination) const {
        auto iter = adjacencyList.find(source);
        if (iter != adjacencyList.end()) {
            auto & neighbors = iter->second;
            return std::find(neighbors.begin(), neighbors.end(), destination) != neighbors.end();
        }
        return false;
    }

    /// @brief Gets the list of vertices in the directed graph
    /// @tparam T The type of the vertices in the graph.
    /// @return The list of vertices in the graph.
    template <typename T>
    std::vector<T> DirectedGraph<T>::getVertices() const {
        std::vector<T> vertices;
        for (auto & kvp : adjacencyList) {
            vertices.push_back(kvp.first);
        }
        return vertices;
    }

    /// @brief Gets the list of neighbors of the given vertex in the directed graph
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex whose neighbors are to be found.
    /// @return The list of neighbors of the given vertex.
    template <typename T>
    std::vector<T> DirectedGraph<T>::getNeighbors(T vertex) const {
        auto iter = adjacencyList.find(vertex);
        if (iter != adjacencyList.end()) {
            return iter->second;
        }
        return std::vector<T>();
    }

} // namespace Tobot::DataStructures
