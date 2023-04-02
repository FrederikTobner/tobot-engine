#pragma once

#include "pre_compiled_header.h"

#include "tuple.h"

namespace Tobot::DataStructures {

    template <typename T>
    class Graph {
        public:
            Graph();
            Graph(const Graph<T> & graph);
            Graph(Graph<T> && graph);
            Graph<T> & operator=(const Graph<T> & graph);
            Graph<T> & operator=(Graph<T> && graph);
            ~Graph();
            void AddVertex(T vertex);
            void AddEdge(T vertex1, T vertex2);
            void AddVertices(std::vector<T> vertices);
            void AddEdges(std::vector<Tuple<T, T>> edges);
            void RemoveVertex(T vertex);
            void RemoveEdge(T vertex1, T vertex2);
            void RemoveVertices(std::vector<T> vertices);
            void RemoveEdges(std::vector<Tuple<T, T>> edges);
            void RemoveAllVertices();
            void RemoveAllEdges();
            void RemoveAllEdgesAndVertices();
            bool ContainsVertex(T vertex) const;
            bool ContainsEdge(T vertex1, T vertex2) const;
            bool ContainsCycle(std::vector<T> cycle) const;
            bool ContainsConnectedComponent(std::vector<T> connected_component) const;

            std::vector<T> GetVertices() const;
            std::vector<Tuple<T, T>> GetEdges() const;
            std::vector<std::vector<T>> GetConnectedComponents() const;
            std::vector<std::vector<T>> GetCycles() const;
            std::vector<T> GetNeighbors(T vertex) const;
            std::vector<T> GetNeighbors(T vertex, std::vector<T> vertices) const;
            std::vector<T> GetNeighbors(T vertex, std::vector<Tuple<T, T>> edges) const;
            std::vector<T> GetNeighbors(T vertex, std::vector<std::vector<T>> connected_components) const;
            std::vector<T> GetNeighbors(T vertex, std::vector<T> vertices, std::vector<Tuple<T, T>> edges) const;
            std::vector<T> GetNeighbors(T vertex, std::vector<T> vertices, std::vector<Tuple<T, T>> edges,
                                        std::vector<std::vector<T>> connected_components) const;
            std::vector<std::vector<T>> GetConnectedComponents(std::vector<T> vertices) const;
            std::vector<T> GetNeighbors(T vertex, std::vector<T> vertices, std::vector<T> visited_vertices) const;
            std::vector<T> GetNeighbors(T vertex, std::vector<T> vertices, std::vector<T> visited_vertices,
                                        std::vector<Tuple<T, T>> edges) const;

        private:
            std::vector<T> vertices;
            std::vector<Tuple<T, T>> edges;
            std::vector<std::vector<T>> connected_components;
            std::vector<std::vector<T>> cycles;
            void FindConnectedComponents();
            void FindCycles();
            void FindConnectedComponent(T vertex, std::vector<T> & visited_vertices,
                                        std::vector<T> & connected_component) const;
            void FindConnectedComponent(T vertex, std::vector<T> & visited_vertices,
                                        std::vector<T> & connected_component);
            void FindCycle(T vertex, std::vector<T> & visited_vertices, std::vector<T> & cycle);

    }; // class Graph

    template <typename T>
    Graph<T>::Graph() {
        vertices = std::vector<T>();
        edges = std::vector<Tuple<T, T>>();
        connected_components = std::vector<std::vector<T>>();
        cycles = std::vector<std::vector<T>>();
    }

    template <typename T>
    Graph<T>::Graph(const Graph<T> & graph) {
        vertices = graph.vertices;
        edges = graph.edges;
        connected_components = graph.connected_components;
        cycles = graph.cycles;
    }

    template <typename T>
    Graph<T>::Graph(Graph<T> && graph) {
        vertices = std::move(graph.vertices);
        edges = std::move(graph.edges);
        connected_components = std::move(graph.connected_components);
        cycles = std::move(graph.cycles);
    }

    template <typename T>
    Graph<T> & Graph<T>::operator=(const Graph<T> & graph) {
        vertices = graph.vertices;
        edges = graph.edges;
        connected_components = graph.connected_components;
        cycles = graph.cycles;
        return *this;
    }

    template <typename T>
    Graph<T> & Graph<T>::operator=(Graph<T> && graph) {
        vertices = std::move(graph.vertices);
        edges = std::move(graph.edges);
        connected_components = std::move(graph.connected_components);
        cycles = std::move(graph.cycles);
        return *this;
    }

    template <typename T>
    Graph<T>::~Graph() {
        vertices.clear();
        edges.clear();
        connected_components.clear();
        cycles.clear();
    }

    template <typename T>
    void Graph<T>::AddVertex(T vertex) {
        if (!ContainsVertex(vertex)) {
            vertices.push_back(vertex);
        }
    }

    template <typename T>
    void Graph<T>::AddVertices(std::vector<T> vertices) {
        for (T vertex : vertices) {
            AddVertex(vertex);
        }
    }

    template <typename T>
    void Graph<T>::AddEdge(T vertex1, T vertex2) {
        if (!ContainsVertex(vertex1)) {
            AddVertex(vertex1);
        }
        if (!ContainsVertex(vertex2)) {
            AddVertex(vertex2);
        }
        if (!ContainsEdge(vertex1, vertex2)) {
            edges.push_back(Tuple<T, T>(vertex1, vertex2));
        }
    }

    template <typename T>
    void Graph<T>::AddEdges(std::vector<Tuple<T, T>> edges) {
        for (Tuple<T, T> edge : edges) {
            AddEdge(edge.GetFirst(), edge.GetSecond());
        }
    }

    template <typename T>
    void Graph<T>::RemoveVertex(T vertex) {
        if (ContainsVertex(vertex)) {
            vertices.erase(std::remove(vertices.begin(), vertices.end(), vertex), vertices.end());
            edges.erase(std::remove_if(edges.begin(), edges.end(),
                                       [vertex](Tuple<T, T> edge) {
                                           return edge.GetFirst() == vertex || edge.GetSecond() == vertex;
                                       }),
                        edges.end());
        }
    }

    template <typename T>
    void Graph<T>::RemoveVertices(std::vector<T> vertices) {
        for (T vertex : vertices) {
            RemoveVertex(vertex);
        }
    }

    template <typename T>
    void Graph<T>::RemoveEdge(T vertex1, T vertex2) {
        if (ContainsEdge(vertex1, vertex2)) {
            edges.erase(std::remove(edges.begin(), edges.end(), Tuple<T, T>(vertex1, vertex2)), edges.end());
        }
    }

    template <typename T>
    void Graph<T>::RemoveEdges(std::vector<Tuple<T, T>> edges) {
        for (Tuple<T, T> edge : edges) {
            RemoveEdge(edge.GetFirst(), edge.GetSecond());
        }
    }

    template <typename T>
    void Graph<T>::RemoveAllEdges() {
        edges.clear();
    }

    template <typename T>
    void Graph<T>::RemoveAllVertices() {
        vertices.clear();
    }

    template <typename T>
    void Graph<T>::RemoveAllEdgesAndVertices() {
        RemoveAllEdges();
        RemoveAllVertices();
    }

    template <typename T>
    bool Graph<T>::ContainsVertex(T vertex) const {
        return std::find(vertices.begin(), vertices.end(), vertex) != vertices.end();
    }

    template <typename T>
    bool Graph<T>::ContainsEdge(T vertex1, T vertex2) const {
        return std::find(edges.begin(), edges.end(), Tuple<T, T>(vertex1, vertex2)) != edges.end();
    }

    template <typename T>
    bool Graph<T>::ContainsCycle(std::vector<T> cycle) const {
        return std::find(cycles.begin(), cycles.end(), cycle) != cycles.end();
    }

    template <typename T>
    bool Graph<T>::ContainsConnectedComponent(std::vector<T> connected_component) const {
        return std::find(connected_components.begin(), connected_components.end(), connected_component) !=
               connected_components.end();
    }

    template <typename T>
    std::vector<T> Graph<T>::GetVertices() const {
        return vertices;
    }

    template <typename T>
    std::vector<Tuple<T, T>> Graph<T>::GetEdges() const {
        return edges;
    }

    template <typename T>
    std::vector<std::vector<T>> Graph<T>::GetConnectedComponents() const {
        return connected_components;
    }

    template <typename T>
    std::vector<std::vector<T>> Graph<T>::GetCycles() const {
        return cycles;
    }

    template <typename T>
    void Graph<T>::FindConnectedComponents() {
        connected_components.clear();
        std::vector<T> visited_vertices;
        for (T vertex : vertices) {
            if (std::find(visited_vertices.begin(), visited_vertices.end(), vertex) == visited_vertices.end()) {
                std::vector<T> connected_component;
                FindConnectedComponent(vertex, visited_vertices, connected_component);
                connected_components.push_back(connected_component);
            }
        }
    }

    template <typename T>
    void Graph<T>::FindConnectedComponent(T vertex, std::vector<T> & visited_vertices,
                                          std::vector<T> & connected_component) {
        visited_vertices.push_back(vertex);
        connected_component.push_back(vertex);
        for (T neighbor : GetNeighbors(vertex)) {
            if (std::find(visited_vertices.begin(), visited_vertices.end(), neighbor) == visited_vertices.end()) {
                FindConnectedComponent(neighbor, visited_vertices, connected_component);
            }
        }
    }

    template <typename T>
    void Graph<T>::FindCycles() {
        cycles.clear();
        std::vector<T> visited_vertices;
        for (T vertex : vertices) {
            if (std::find(visited_vertices.begin(), visited_vertices.end(), vertex) == visited_vertices.end()) {
                std::vector<T> cycle;
                FindCycle(vertex, visited_vertices, cycle);
            }
        }
    }

    template <typename T>
    void Graph<T>::FindCycle(T vertex, std::vector<T> & visited_vertices, std::vector<T> & cycle) {
        visited_vertices.push_back(vertex);
        cycle.push_back(vertex);
        for (T neighbor : GetNeighbors(vertex)) {
            if (std::find(visited_vertices.begin(), visited_vertices.end(), neighbor) == visited_vertices.end()) {
                FindCycle(neighbor, visited_vertices, cycle);
            } else if (std::find(cycle.begin(), cycle.end(), neighbor) != cycle.end()) {
                std::vector<T> cycle_copy = cycle;
                cycle_copy.erase(cycle_copy.begin(), std::find(cycle_copy.begin(), cycle_copy.end(), neighbor));
                cycles.push_back(cycle_copy);
            }
        }
        cycle.pop_back();
    }

    template <typename T>
    std::vector<T> Graph<T>::GetNeighbors(T vertex) const {
        std::vector<T> neighbors;
        for (Tuple<T, T> edge : edges) {
            if (edge.GetFirst() == vertex) {
                neighbors.push_back(edge.GetSecond());
            } else if (edge.GetSecond() == vertex) {
                neighbors.push_back(edge.GetFirst());
            }
        }
        return neighbors;
    }

    template <typename T>
    std::vector<T> Graph<T>::GetNeighbors(T vertex, std::vector<Tuple<T, T>> edges) const {
        std::vector<T> neighbors;
        for (Tuple<T, T> edge : edges) {
            if (edge.GetFirst() == vertex) {
                neighbors.push_back(edge.GetSecond());
            } else if (edge.GetSecond() == vertex) {
                neighbors.push_back(edge.GetFirst());
            }
        }
        return neighbors;
    }

    template <typename T>
    std::vector<T> Graph<T>::GetNeighbors(T vertex, std::vector<T> vertices) const {
        std::vector<T> neighbors;
        for (Tuple<T, T> edge : edges) {
            if (edge.GetFirst() == vertex &&
                std::find(vertices.begin(), vertices.end(), edge.GetSecond()) != vertices.end()) {
                neighbors.push_back(edge.GetSecond());
            } else if (edge.GetSecond() == vertex &&
                       std::find(vertices.begin(), vertices.end(), edge.GetFirst()) != vertices.end()) {
                neighbors.push_back(edge.GetFirst());
            }
        }
        return neighbors;
    }

    template <typename T>
    std::vector<T> Graph<T>::GetNeighbors(T vertex, std::vector<T> vertices, std::vector<Tuple<T, T>> edges) const {
        std::vector<T> neighbors;
        for (Tuple<T, T> edge : edges) {
            if (edge.GetFirst() == vertex &&
                std::find(vertices.begin(), vertices.end(), edge.GetSecond()) != vertices.end()) {
                neighbors.push_back(edge.GetSecond());
            } else if (edge.GetSecond() == vertex &&
                       std::find(vertices.begin(), vertices.end(), edge.GetFirst()) != vertices.end()) {
                neighbors.push_back(edge.GetFirst());
            }
        }
        return neighbors;
    }

    template <typename T>
    std::vector<T> Graph<T>::GetNeighbors(T vertex, std::vector<T> vertices, std::vector<T> visited_vertices) const {
        std::vector<T> neighbors;
        for (Tuple<T, T> edge : edges) {
            if (edge.GetFirst() == vertex &&
                std::find(vertices.begin(), vertices.end(), edge.GetSecond()) != vertices.end() &&
                std::find(visited_vertices.begin(), visited_vertices.end(), edge.GetSecond()) ==
                    visited_vertices.end()) {
                neighbors.push_back(edge.GetSecond());
            } else if (edge.GetSecond() == vertex &&
                       std::find(vertices.begin(), vertices.end(), edge.GetFirst()) != vertices.end() &&
                       std::find(visited_vertices.begin(), visited_vertices.end(), edge.GetFirst()) ==
                           visited_vertices.end()) {
                neighbors.push_back(edge.GetFirst());
            }
        }
        return neighbors;
    }

    template <typename T>
    std::vector<T> Graph<T>::GetNeighbors(T vertex, std::vector<T> vertices, std::vector<T> visited_vertices,
                                          std::vector<Tuple<T, T>> edges) const {
        std::vector<T> neighbors;
        for (Tuple<T, T> edge : edges) {
            if (edge.GetFirst() == vertex &&
                std::find(vertices.begin(), vertices.end(), edge.GetSecond()) != vertices.end() &&
                std::find(visited_vertices.begin(), visited_vertices.end(), edge.GetSecond()) ==
                    visited_vertices.end()) {
                neighbors.push_back(edge.GetSecond());
            } else if (edge.GetSecond() == vertex &&
                       std::find(vertices.begin(), vertices.end(), edge.GetFirst()) != vertices.end() &&
                       std::find(visited_vertices.begin(), visited_vertices.end(), edge.GetFirst()) ==
                           visited_vertices.end()) {
                neighbors.push_back(edge.GetFirst());
            }
        }
        return neighbors;
    }

    template <typename T>
    std::vector<std::vector<T>> Graph<T>::GetConnectedComponents(std::vector<T> vertices) const {
        std::vector<std::vector<T>> connected_components;
        std::vector<T> visited_vertices;
        for (T vertex : vertices) {
            if (std::find(visited_vertices.begin(), visited_vertices.end(), vertex) == visited_vertices.end()) {
                std::vector<T> connected_component;
                FindConnectedComponent(vertex, visited_vertices, connected_component);
                connected_components.push_back(connected_component);
            }
        }
        return connected_components;
    }

    template <typename T>
    void Graph<T>::FindConnectedComponent(T vertex, std::vector<T> & visited_vertices,
                                          std::vector<T> & connected_component) const {
        visited_vertices.push_back(vertex);
        connected_component.push_back(vertex);
        std::vector<T> neighbors = GetNeighbors(vertex, vertices, visited_vertices);
        for (T neighbor : neighbors) {
            if (std::find(visited_vertices.begin(), visited_vertices.end(), neighbor) == visited_vertices.end()) {
                FindConnectedComponent(neighbor, visited_vertices, connected_component);
            }
        }
    }

} // namespace Tobot::DataStructures