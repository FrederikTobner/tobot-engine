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
            Graph(std::vector<T> vertices, std::vector<Tuple<T, T>> edges);
            Graph(std::initializer_list<T> vertices, std::initializer_list<Tuple<T, T>> edges);
            Graph<T> & operator=(const Graph<T> & graph);
            Graph<T> & operator=(Graph<T> && graph);
            bool operator==(const Graph<T> & graph) const;
            bool operator!=(const Graph<T> & graph) const;
            ~Graph();
            void AddVertex(T vertex);
            void AddEdge(T vertex1, T vertex2);
            void AddVertices(std::vector<T> vertices);
            void AddEdges(std::vector<Tuple<T, T>> edges);
            void AddCycle(T vertex1, T vertex2);
            void AddEdgeToConnectedComponents(T vertex1, T vertex2);
            bool ContainsVertex(T vertex) const;
            bool ContainsEdge(T vertex1, T vertex2) const;
            bool ContainsCycle(std::vector<T> cycle) const;
            bool ContainsConnectedComponent(std::vector<T> connected_component) const;
            void FindConnectedComponents();
            void FindCycles();
            void FindConnectedComponent(T vertex, std::vector<T> & visited_vertices,
                                        std::vector<T> & connected_component) const;
            void FindConnectedComponent(T vertex, std::vector<T> & visited_vertices,
                                        std::vector<T> & connected_component);
            void FindCycle(T vertex, std::vector<T> & visited_vertices, std::vector<T> & cycle);
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
            bool IsConnected() const;
            bool IsCyclic() const;
            bool IsAcyclic() const;
            bool IsEmpty() const;
            void RemoveVertex(T vertex);
            void RemoveEdge(T vertex1, T vertex2);
            void RemoveVertices(std::vector<T> vertices);
            void RemoveEdges(std::vector<Tuple<T, T>> edges);
            void RemoveAllVertices();
            void RemoveAllEdges();
            void RemoveAllEdgesAndVertices();
            friend std::ostream operator<<(std::ostream & os, const Graph<T> & graph) {
                os << "Vertices: " << graph.vertices << std::endl;
                os << "Edges: " << graph.edges << std::endl;
                os << "Connected Components: " << graph.connected_components << std::endl;
                os << "Cycles: " << graph.cycles << std::endl;
                return os;
            }

        private:
            std::vector<T> vertices;
            std::vector<Tuple<T, T>> edges;
            std::vector<std::vector<T>> connected_components;
            std::vector<std::vector<T>> cycles;

    }; // class Graph

    /// @brief Default constructor for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    Graph<T>::Graph() {
        vertices = std::vector<T>();
        edges = std::vector<Tuple<T, T>>();
        connected_components = std::vector<std::vector<T>>();
        cycles = std::vector<std::vector<T>>();
    }

    /// @brief Copy constructor for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param graph The graph to copy.
    template <typename T>
    Graph<T>::Graph(const Graph<T> & graph) {
        vertices = std::vector<T>();
        edges = std::vector<Tuple<T, T>>();
        connected_components = std::vector<std::vector<T>>();
        cycles = std::vector<std::vector<T>>();
        vertices.insert(vertices.end(), graph.vertices.begin(), graph.vertices.end());
        edges.insert(edges.end(), graph.edges.begin(), graph.edges.end());
        connected_components.insert(connected_components.end(), graph.connected_components.begin(),
                                    graph.connected_components.end());
        cycles.insert(cycles.end(), graph.cycles.begin(), graph.cycles.end());
    }

    /// @brief Move constructor for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param graph The graph to move.
    template <typename T>
    Graph<T>::Graph(Graph<T> && graph) {
        vertices = std::move(graph.vertices);
        edges = std::move(graph.edges);
        connected_components = std::move(graph.connected_components);
        cycles = std::move(graph.cycles);
    }

    /// @brief Constructor for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertices The vertices in the graph.
    /// @param edges The edges in the graph.
    template <typename T>
    Graph<T>::Graph(std::vector<T> vertices, std::vector<Tuple<T, T>> edges) {
        this->vertices = vertices;
        this->edges = edges;
        connected_components = std::vector<std::vector<T>>();
        cycles = std::vector<std::vector<T>>();
    }

    /// Constructs a graph from a list of vertices and a list of edges.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertices The vertices in the graph.
    /// @param edges The edges in the graph.
    template <typename T>
    Graph<T>::Graph(std::initializer_list<T> vertices, std::initializer_list<Tuple<T, T>> edges) {
        this->vertices = std::vector<T>(vertices);
        this->edges = std::vector<Tuple<T, T>>(edges);
        connected_components = std::vector<std::vector<T>>();
        cycles = std::vector<std::vector<T>>();
    }

    /// @brief Copy assignment operator for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param graph The graph to copy.
    /// @return A reference to the graph.
    template <typename T>
    Graph<T> & Graph<T>::operator=(const Graph<T> & graph) {
        vertices = graph.vertices;
        edges = graph.edges;
        connected_components = graph.connected_components;
        cycles = graph.cycles;
        return *this;
    }

    /// @brief Move assignment operator for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param graph The graph to move.
    /// @return A reference to the graph.
    template <typename T>
    Graph<T> & Graph<T>::operator=(Graph<T> && graph) {
        vertices = std::move(graph.vertices);
        edges = std::move(graph.edges);
        connected_components = std::move(graph.connected_components);
        cycles = std::move(graph.cycles);
        return *this;
    }

    template <typename T>
    bool Graph<T>::operator==(const Graph<T> & graph) const {
        return vertices == graph.vertices && edges == graph.edges;
    }

    template <typename T>
    bool Graph<T>::operator!=(const Graph<T> & graph) const {
        return !(*this == graph);
    }

    /// @brief Destructor for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    Graph<T>::~Graph() {
        vertices.clear();
        edges.clear();
        connected_components.clear();
        cycles.clear();
    }

    /// @brief Adds a vertex to the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to add.
    template <typename T>
    void Graph<T>::AddVertex(T vertex) {
        if (!ContainsVertex(vertex)) {
            vertices.push_back(vertex);
        }
    }

    /// @brief Adds multiple vertices to the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertices The vertices to add.
    template <typename T>
    void Graph<T>::AddVertices(std::vector<T> vertices) {
        for (T vertex : vertices) {
            AddVertex(vertex);
        }
    }

    /// @brief Connects two vertices with an edge.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex1 The first vertex to connect.
    /// @param vertex2 The second vertex to connect.
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

            AddEdgeToConnectedComponents(vertex1, vertex2);
        }
    }

    /// @brief Adds an edge to the connected components.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex1 The first vertex to connect.
    /// @param vertex2 The second vertex to connect.
    template <typename T>
    void Graph<T>::AddEdgeToConnectedComponents(T vertex1, T vertex2) {
        // If the edge connects two vertices that are already in the same connected component, then it has created a
        // cycle.
        for (std::vector<T> connected_component : connected_components) {
            if (std::find(connected_component.begin(), connected_component.end(), vertex1) !=
                    connected_component.end() &&
                std::find(connected_component.begin(), connected_component.end(), vertex2) !=
                    connected_component.end()) {
                AddCycle(vertex1, vertex2);
                return;
            }
        }
        // If the edge connects two vertices that are not in the same connected component, then add the edge to the
        // connected components.
        bool vertex1_found = false;
        bool vertex2_found = false;
        for (std::vector<T> & connected_component : connected_components) {
            if (std::find(connected_component.begin(), connected_component.end(), vertex1) !=
                connected_component.end()) {
                connected_component.push_back(vertex2);
                vertex1_found = true;
            }
            if (std::find(connected_component.begin(), connected_component.end(), vertex2) !=
                connected_component.end()) {
                connected_component.push_back(vertex1);
                vertex2_found = true;
            }
        }
        if (!vertex1_found && !vertex2_found) {
            std::vector<T> connected_component;
            connected_component.push_back(vertex1);
            connected_component.push_back(vertex2);
            connected_components.push_back(connected_component);
        }
    }

    /// Adds a cycle to the list of cycles.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex1 The first vertex in the cycle.
    /// @param vertex2 The second vertex in the cycle.
    template <typename T>
    void Graph<T>::AddCycle(T vertex1, T vertex2) {
        std::vector<T> cycle;
        cycle.push_back(vertex1);
        cycle.push_back(vertex2);
        cycles.push_back(cycle);
    }

    /// @brief Connects multiple vertices with edges.
    /// @tparam T The type of the vertices in the graph.
    /// @param edges The edges to add.
    template <typename T>
    void Graph<T>::AddEdges(std::vector<Tuple<T, T>> edges) {
        for (Tuple<T, T> edge : edges) {
            AddEdge(edge.GetFirst(), edge.GetSecond());
        }
    }

    /// @brief Removes a vertex from the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to remove.
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

    /// @brief Removes multiple vertices from the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertices The vertices to remove.
    template <typename T>
    void Graph<T>::RemoveVertices(std::vector<T> vertices) {
        for (T vertex : vertices) {
            RemoveVertex(vertex);
        }
    }

    /// @brief Removes an edge from the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex1 The first vertex of the edge to remove.
    /// @param vertex2 The second vertex of the edge to remove.
    template <typename T>
    void Graph<T>::RemoveEdge(T vertex1, T vertex2) {
        if (ContainsEdge(vertex1, vertex2)) {
            edges.erase(std::remove(edges.begin(), edges.end(), Tuple<T, T>(vertex1, vertex2)), edges.end());
        }
    }

    /// @brief Removes multiple edges from the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param edges The edges to remove.
    template <typename T>
    void Graph<T>::RemoveEdges(std::vector<Tuple<T, T>> edges) {
        for (Tuple<T, T> edge : edges) {
            RemoveEdge(edge.GetFirst(), edge.GetSecond());
        }
    }

    /// @brief Removes all edges from the graph.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    void Graph<T>::RemoveAllEdges() {
        edges.clear();
    }

    /// @brief Removes all vertices from the graph.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    void Graph<T>::RemoveAllVertices() {
        vertices.clear();
    }

    /// @brief Removes all edges and vertices from the graph.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    void Graph<T>::RemoveAllEdgesAndVertices() {
        RemoveAllEdges();
        RemoveAllVertices();
    }

    /// @brief Gets the vertices of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to get the neighbors of.
    /// @return The neighbors of the vertex.
    template <typename T>
    bool Graph<T>::ContainsVertex(T vertex) const {
        return std::find(vertices.begin(), vertices.end(), vertex) != vertices.end();
    }

    /// @brief Checks if an edge exists in the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex1 The first vertex of the edge to get.
    /// @param vertex2 The second vertex of the edge to get.
    /// @return True if the edge exists, false otherwise.
    template <typename T>
    bool Graph<T>::ContainsEdge(T vertex1, T vertex2) const {
        return std::find(edges.begin(), edges.end(), Tuple<T, T>(vertex1, vertex2)) != edges.end();
    }

    /// @brief Checks if a cycle exists in the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param cycle The cycle to check for.
    /// @return True if the cycle exists, false otherwise.
    template <typename T>
    bool Graph<T>::ContainsCycle(std::vector<T> cycle) const {
        return std::find(cycles.begin(), cycles.end(), cycle) != cycles.end();
    }

    /// @brief Checks if a connected component exists in the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param connected_component The connected component to check for.
    /// @return True if the connected component exists, false otherwise.
    template <typename T>
    bool Graph<T>::ContainsConnectedComponent(std::vector<T> connected_component) const {
        return std::find(connected_components.begin(), connected_components.end(), connected_component) !=
               connected_components.end();
    }

    /// @brief Gets the vertices of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @return The vertices of the graph.
    template <typename T>
    bool Graph<T>::IsConnected() const {
        return connected_components.size() == 1;
    }

    /// @brief Checks if the graph is cyclic.
    /// @tparam T The type of the vertices in the graph.
    /// @return True if the graph is cyclic, false otherwise.
    template <typename T>
    bool Graph<T>::IsCyclic() const {
        return cycles.size() > 0;
    }

    /// @brief Checks if the graph is acyclic.
    /// @tparam T The type of the vertices in the graph.
    /// @return True if the graph is acyclic, false otherwise.
    template <typename T>
    bool Graph<T>::IsAcyclic() const {
        return !IsCyclic();
    }

    /// @brief Checks if the graph is empty.
    /// @tparam T The type of the vertices in the graph.
    /// @return True if the graph is empty, false otherwise.
    template <typename T>
    bool Graph<T>::IsEmpty() const {
        return vertices.size() == 0;
    }

    /// @brief Checks if the graph is not empty.
    /// @tparam T The type of the vertices in the graph.
    /// @return True if the graph is not empty, false otherwise.
    template <typename T>
    std::vector<T> Graph<T>::GetVertices() const {
        return vertices;
    }

    /// @brief Gets the edges of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @return The edges of the graph.
    template <typename T>
    std::vector<Tuple<T, T>> Graph<T>::GetEdges() const {
        return edges;
    }

    /// @brief Gets the neighbors of a vertex.
    /// @tparam T The type of the vertices in the graph.
    /// @return The neighbors of the vertex.
    template <typename T>
    std::vector<std::vector<T>> Graph<T>::GetConnectedComponents() const {
        return connected_components;
    }

    /// @brief Gets the cycles of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @return The cycles of the graph.
    template <typename T>
    std::vector<std::vector<T>> Graph<T>::GetCycles() const {
        return cycles;
    }

    /// @brief Gets the neighbors of a vertex.
    /// @tparam T The type of the vertices in the graph.
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

    /// @brief Finds a connected component of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to start the search from.
    /// @param visited_vertices The vertices that have been visited.
    /// @param connected_component The connected component that has been found.
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

    /// @brief Finds the cycles of the graph.
    /// @tparam T The type of the vertices in the graph.
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

    /// @brief Finds a cycle of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to start the search from.
    /// @param visited_vertices The vertices that have been visited.
    /// @param cycle The cycle that has been found.
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

    /// @brief Gets the neighbors of a vertex.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to get the neighbors of.
    /// @return The neighbors of the vertex.
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

    /// @brief Gets the neighbors of a vertex.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to get the neighbors of.
    /// @param edges The edges to consider.
    /// @return The neighbors of the vertex.
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

    /// @brief Gets the neighbors of a vertex.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to get the neighbors of.
    /// @param vertices The vertices to consider.
    /// @return The neighbors of the vertex.
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

    /// @brief Gets the neighbors of a vertex.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to get the neighbors of.
    /// @param vertices The vertices to consider.
    /// @param edges The edges to consider.
    /// @return The neighbors of the vertex.
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

    /// @brief Gets the neighbors of a vertex.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to get the neighbors of.
    /// @param vertices The vertices to consider.
    /// @param visited_vertices The vertices that have been visited.
    /// @return The neighbors of the vertex.
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

    /// @brief Gets the neighbors of a vertex.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to get the neighbors of.
    /// @param vertices The vertices to consider.
    /// @param visited_vertices The vertices that have been visited.
    /// @param edges The edges to consider.
    /// @return The neighbors of the vertex.
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

    /// @brief Gets the connected components of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertices The vertices to consider.
    /// @return The connected components of the graph.
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

    /// @brief Gets the connected components of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to start the search from.
    /// @param visited_vertices The vertices that have been visited.
    /// @param connected_component The connected component that has been found.
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