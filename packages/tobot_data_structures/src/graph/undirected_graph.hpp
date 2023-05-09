#pragma once

#include "../pre_compiled_header.hpp"

namespace Tobot::DataStructures {
    /// @brief Models a graph
    /// @tparam T The type of the vertices
    /// @details The graph is represented as an adjacency list and is undirected and unweighted
    template <typename T>
    class UndirectedGraph {
        public:
            UndirectedGraph();
            UndirectedGraph(const UndirectedGraph<T>& graph);
            UndirectedGraph(UndirectedGraph<T>&& graph);
            UndirectedGraph(std::vector<T> vertices);
            UndirectedGraph(std::vector<T> vertices, std::vector<std::pair<T, T>> edges);
            UndirectedGraph(std::initializer_list<T> vertices);
            UndirectedGraph(std::initializer_list<T> vertices, std::initializer_list<std::pair<T, T>> edges);
            ~UndirectedGraph();

            auto operator=(const UndirectedGraph<T>& graph) -> UndirectedGraph<T>&;
            auto operator=(UndirectedGraph<T>&& graph) -> UndirectedGraph<T>&;
            auto operator==(const UndirectedGraph<T>& graph) const -> bool;
            auto operator!=(const UndirectedGraph<T>& graph) const -> bool;
            friend auto operator<<(std::ostream& os, const UndirectedGraph<T>& graph) -> std::ostream {
                os << "Vertices: " << graph.vertices << std::endl;
                os << "Edges: " << graph.edges << std::endl;
                os << "Connected Components: " << graph.connected_components << std::endl;
                os << "Cycles: " << graph.cycles << std::endl;
            }

            auto addCycle(T vertex1, T vertex2) -> void;
            auto addEdge(T vertex1, T vertex2) -> void;
            auto addEdges(std::vector<std::pair<T, T>> edges) -> void;
            auto addVertex(T vertex) -> void;
            auto addVertices(std::vector<T> vertices) -> void;
            auto containsVertex(T vertex) const -> bool;
            auto containsEdge(T vertex1, T vertex2) const -> bool;
            auto containsCycle(std::vector<T> cycle) const -> bool;
            auto containsConnectedComponent(std::vector<T> connected_component) const -> bool;
            auto getComponents() const -> std::vector<std::vector<T>>;
            auto getConnectedComponentCount() const -> std::size_t;
            auto getCycles() const -> std::vector<std::vector<T>>;
            auto getCycleCount() const -> std::size_t;
            auto getEdges() const -> std::vector<std::pair<T, T>>;
            auto getEdgeCount() const -> std::size_t;
            auto getVertices() const -> std::vector<T>;
            auto getVertexCount() const -> std::size_t;
            auto getConnectedComponent(T vertex) -> std::vector<T>;
            auto getNeighbors(T vertex) const -> std::vector<T>;
            auto getNeighbors(T vertex, std::vector<T> vertices) const -> std::vector<T>;
            auto getNeighbors(T vertex, std::vector<std::pair<T, T>> edges) const -> std::vector<T>;
            auto getNeighbors(T vertex, std::vector<std::vector<T>> connected_components) const -> std::vector<T>;
            auto getNeighbors(T vertex, std::vector<T> vertices, std::vector<std::pair<T, T>> edges) const
                -> std::vector<T>;
            auto getNeighbors(T vertex, std::vector<T> vertices, std::vector<std::pair<T, T>> edges,
                              std::vector<std::vector<T>> connected_components) const -> std::vector<T>;
            auto getNeighbors(T vertex, std::vector<T> vertices, std::vector<T> visited_vertices) const
                -> std::vector<T>;
            auto getNeighbors(T vertex, std::vector<T> vertices, std::vector<T> visited_vertices,
                              std::vector<std::pair<T, T>> edges) const -> std::vector<T>;
            auto isAcyclic() const -> bool;
            auto isConnected() const -> bool;
            auto isCyclic() const -> bool;
            auto isEmpty() const -> bool;
            auto removeConnectedComponent(T vertex) -> void;
            auto removeEdge(T vertex1, T vertex2) -> void;
            auto removeEdges(std::vector<std::pair<T, T>> edges) -> void;
            auto removeVertex(T vertex) -> void;
            auto removeVertices(std::vector<T> vertices) -> void;
            auto removeAllVertices() -> void;
            auto removeAllEdges() -> void;
            auto removeAllEdgesAndVertices() -> void;
            auto removeAllConnectedComponents() -> void;
            auto removeAllCycles() -> void;
            auto removeAll() -> void;

        private:
            /// @brief The vertices in the graph.
            std::vector<T> vertices;
            /// @brief The edges in the graph.
            std::vector<std::pair<T, T>> edges;
            /// @brief The connected components in the graph.
            std::vector<std::vector<T>> connected_components;
            /// @brief The cycles in the graph.
            std::vector<std::vector<T>> cycles;
            auto addEdgeToConnectedComponents(T vertex1, T vertex2) -> void;
            auto findConnectedComponents() -> void;
            auto findCycles() -> void;
            auto findConnectedComponent(T vertex, std::vector<T>& visited_vertices,
                                        std::vector<T>& connected_component) const -> void;
            auto findConnectedComponent(T vertex, std::vector<T>& visited_vertices, std::vector<T>& connected_component)
                -> void;
            auto findCycle(T vertex, std::vector<T>& visited_vertices, std::vector<T>& cycle) -> void;

    }; // class Graph

    /// @brief Default constructor for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    [[nodiscard]] UndirectedGraph<T>::UndirectedGraph() {
        vertices = std::vector<T>();
        edges = std::vector<std::pair<T, T>>();
        connected_components = std::vector<std::vector<T>>();
        cycles = std::vector<std::vector<T>>();
    }

    /// @brief Copy constructor for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param graph The graph to copy.
    template <typename T>
    [[nodiscard]] UndirectedGraph<T>::UndirectedGraph(const UndirectedGraph<T>& graph) {
        vertices = std::vector<T>(graph.vertices);         // deep copy of the vertices
        edges = std::vector<std::pair<T, T>>(graph.edges); // deep copy of the edges
        connected_components = graph.connected_components; // shallow copy of the connected_components
        cycles = graph.cycles;                             // shallow copy of the cycles
    }

    /// @brief Move constructor for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param graph The graph to move.
    template <typename T>
    [[nodiscard]] UndirectedGraph<T>::UndirectedGraph(UndirectedGraph<T>&& graph) {
        vertices = std::move(graph.vertices);
        edges = std::move(graph.edges);
        connected_components = std::move(graph.connected_components);
        cycles = std::move(graph.cycles);
    }

    /// Constructor for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertices The vertices in the graph.
    template <typename T>
    [[nodiscard]] UndirectedGraph<T>::UndirectedGraph(std::vector<T> vertices) {
        this->vertices = vertices;
        this->edges = std::vector<std::pair<T, T>>();
        connected_components = std::vector<std::vector<T>>();
        cycles = std::vector<std::vector<T>>();
    }

    /// @brief Constructor for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertices The vertices in the graph.
    /// @param edges The edges in the graph.
    template <typename T>
    [[nodiscard]] UndirectedGraph<T>::UndirectedGraph(std::vector<T> vertices, std::vector<std::pair<T, T>> edges) {
        this->vertices = vertices;
        this->edges = edges;
        connected_components = std::vector<std::vector<T>>();
        cycles = std::vector<std::vector<T>>();
    }

    /// @brief Constructor for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertices The vertices in the graph.
    template <typename T>
    [[nodiscard]] UndirectedGraph<T>::UndirectedGraph(std::initializer_list<T> vertices) {
        this->vertices = std::vector<T>(vertices);
        this->edges = std::vector<std::pair<T, T>>();
        connected_components = std::vector<std::vector<T>>();
        cycles = std::vector<std::vector<T>>();
    }

    /// Constructs a graph from a list of vertices and a list of edges.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertices The vertices in the graph.
    /// @param edges The edges in the graph.
    template <typename T>
    [[nodiscard]] UndirectedGraph<T>::UndirectedGraph(std::initializer_list<T> vertices,
                                                      std::initializer_list<std::pair<T, T>> edges) {
        this->vertices = std::vector<T>(vertices);
        this->edges = std::vector<std::pair<T, T>>(edges);
        connected_components = std::vector<std::vector<T>>();
        cycles = std::vector<std::vector<T>>();
    }

    /// @brief Destructor for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    UndirectedGraph<T>::~UndirectedGraph() {
        vertices.clear();
        edges.clear();
        connected_components.clear();
        cycles.clear();
    }

    /// @brief Copy assignment operator for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param graph The graph to copy.
    /// @return A reference to the graph.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::operator=(const UndirectedGraph<T>& graph) -> UndirectedGraph<T>& {
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
    [[nodiscard]] auto UndirectedGraph<T>::operator=(UndirectedGraph<T>&& graph) -> UndirectedGraph<T>& {
        vertices = std::move(graph.vertices);
        edges = std::move(graph.edges);
        connected_components = std::move(graph.connected_components);
        cycles = std::move(graph.cycles);
        return *this;
    }

    /// @brief Equality operator for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param graph The graph to compare to.
    /// @return True if the graphs are equal, false otherwise.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::operator==(const UndirectedGraph<T>& graph) const -> bool {
        return vertices == graph.vertices && edges == graph.edges;
    }

    /// @brief Inequality operator for the Graph class.
    /// @tparam T The type of the vertices in the graph.
    /// @param graph The graph to compare to.
    /// @return True if the graphs are not equal, false otherwise.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::operator!=(const UndirectedGraph<T>& graph) const -> bool {
        return !(*this == graph);
    }

    /// @brief Adds a vertex to the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to add.
    template <typename T>
    auto UndirectedGraph<T>::addVertex(T vertex) -> void {
        if (!containsVertex(vertex)) {
            vertices.push_back(vertex);
        }
    }

    /// @brief Adds multiple vertices to the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertices The vertices to add.
    template <typename T>
    auto UndirectedGraph<T>::addVertices(std::vector<T> vertices) -> void {
        for (T vertex : vertices) {
            addVertex(vertex);
        }
    }

    /// @brief Connects two vertices with an edge.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex1 The first vertex to connect.
    /// @param vertex2 The second vertex to connect.
    template <typename T>
    auto UndirectedGraph<T>::addEdge(T vertex1, T vertex2) -> void {
        if (!containsVertex(vertex1)) {
            addVertex(vertex1);
        }
        if (!containsVertex(vertex2)) {
            addVertex(vertex2);
        }
        if (!containsEdge(vertex1, vertex2)) {
            edges.push_back(std::pair<T, T>(vertex1, vertex2));

            addEdgeToConnectedComponents(vertex1, vertex2);
        }
    }

    /// @brief Adds an edge to the connected components.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex1 The first vertex to connect.
    /// @param vertex2 The second vertex to connect.
    template <typename T>
    auto UndirectedGraph<T>::addEdgeToConnectedComponents(T vertex1, T vertex2) -> void {
        // If the edge connects two vertices that are already in the same connected component, then it has created a
        // cycle.
        for (std::vector<T> connected_component : connected_components) {
            if (std::find(connected_component.begin(), connected_component.end(), vertex1) !=
                    connected_component.end() &&
                std::find(connected_component.begin(), connected_component.end(), vertex2) !=
                    connected_component.end()) {
                addCycle(vertex1, vertex2);
                return;
            }
        }
        // If the edge connects two vertices that are not in the same connected component, then add the edge to the
        // connected components.
        bool vertex1_found = false;
        bool vertex2_found = false;
        for (std::vector<T>& connected_component : connected_components) {
            if (std::find(connected_component.begin(), connected_component.end(), vertex1) !=
                connected_component.end()) {
                if (std::find(connected_component.begin(), connected_component.end(), vertex2) ==
                    connected_component.end()) {
                    connected_component.push_back(vertex2);
                }
                vertex1_found = true;
            }
            if (std::find(connected_component.begin(), connected_component.end(), vertex2) !=
                connected_component.end()) {
                if (std::find(connected_component.begin(), connected_component.end(), vertex1) ==
                    connected_component.end()) {
                    connected_component.push_back(vertex1);
                }
                vertex2_found = true;
            }
        }
        // If the edge connects two vertices that are not in any connected component, then create a new connected
        // component
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
    auto UndirectedGraph<T>::addCycle(T vertex1, T vertex2) -> void {
        std::vector<T> cycle;
        cycle.push_back(vertex1);
        cycle.push_back(vertex2);
        cycles.push_back(cycle);
    }

    /// @brief Connects multiple vertices with edges.
    /// @tparam T The type of the vertices in the graph.
    /// @param edges The edges to add.
    template <typename T>
    auto UndirectedGraph<T>::addEdges(std::vector<std::pair<T, T>> edges) -> void {
        for (std::pair<T, T> edge : edges) {
            addEdge(edge.GetFirst(), edge.GetSecond());
        }
    }

    /// @brief Removes a vertex from the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to remove.
    template <typename T>
    auto UndirectedGraph<T>::removeVertex(T vertex) -> void {
        if (containsVertex(vertex)) {
            vertices.erase(std::remove(vertices.begin(), vertices.end(), vertex), vertices.end());
            edges.erase(std::remove_if(
                            edges.begin(), edges.end(),
                            [vertex](std::pair<T, T> edge) { return edge.first == vertex || edge.second == vertex; }),
                        edges.end());
        }
    }

    /// @brief Removes multiple vertices from the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertices The vertices to remove.
    template <typename T>
    auto UndirectedGraph<T>::removeVertices(std::vector<T> vertices) -> void {
        for (T vertex : vertices) {
            removeVertex(vertex);
        }
    }

    /// @brief Removes a connected component from the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex in the connected component to remove.
    template <typename T>
    auto UndirectedGraph<T>::removeConnectedComponent(T vertex) -> void {
        if (containsVertex(vertex)) {
            for (std::vector<T> connected_component : connected_components) {
                if (std::find(connected_component.begin(), connected_component.end(), vertex) !=
                    connected_component.end()) {
                    for (T vertex : connected_component) {
                        removeVertex(vertex);
                    }
                }
            }
        }
    }

    /// @brief Removes an edge from the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex1 The first vertex of the edge to remove.
    /// @param vertex2 The second vertex of the edge to remove.
    template <typename T>
    auto UndirectedGraph<T>::removeEdge(T vertex1, T vertex2) -> void {
        if (containsEdge(vertex1, vertex2)) {
            edges.erase(std::remove(edges.begin(), edges.end(), std::pair<T, T>(vertex1, vertex2)), edges.end());
        }
    }

    /// @brief Removes multiple edges from the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param edges The edges to remove.
    template <typename T>
    auto UndirectedGraph<T>::removeEdges(std::vector<std::pair<T, T>> edges) -> void {
        for (auto [firstVertex, secondVertex] : edges) {
            removeEdge(firstVertex, secondVertex);
        }
    }

    /// @brief Removes all edges from the graph.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    auto UndirectedGraph<T>::removeAllEdges() -> void {
        edges.clear();
    }

    /// @brief Removes all vertices from the graph.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    auto UndirectedGraph<T>::removeAllVertices() -> void {
        vertices.clear();
    }

    /// @brief Removes all edges and vertices from the graph.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    auto UndirectedGraph<T>::removeAllEdgesAndVertices() -> void {
        removeAllEdges();
        removeAllVertices();
    }

    /// Removes all the connected components from the graph.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    auto UndirectedGraph<T>::removeAllConnectedComponents() -> void {
        connected_components.clear();
    }

    /// Removes all the cycles from the graph.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    auto UndirectedGraph<T>::removeAllCycles() -> void {
        cycles.clear();
    }

    /// Removes everything from the graph.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    auto UndirectedGraph<T>::removeAll() -> void {
        removeAllEdgesAndVertices();
        removeAllConnectedComponents();
        removeAllCycles();
    }

    /// @brief Gets the vertices of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to get the neighbors of.
    /// @return The neighbors of the vertex.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::containsVertex(T vertex) const -> bool {
        return std::find(vertices.begin(), vertices.end(), vertex) != vertices.end();
    }

    /// @brief Checks if an edge exists in the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex1 The first vertex of the edge to get.
    /// @param vertex2 The second vertex of the edge to get.
    /// @return True if the edge exists, false otherwise.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::containsEdge(T vertex1, T vertex2) const -> bool {
        return std::find(edges.begin(), edges.end(), std::pair<T, T>(vertex1, vertex2)) != edges.end();
    }

    /// @brief Checks if a cycle exists in the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param cycle The cycle to check for.
    /// @return True if the cycle exists, false otherwise.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::containsCycle(std::vector<T> cycle) const -> bool {
        return std::find(cycles.begin(), cycles.end(), cycle) != cycles.end();
    }

    /// @brief Checks if a connected component exists in the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param connected_component The connected component to check for.
    /// @return True if the connected component exists, false otherwise.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::containsConnectedComponent(std::vector<T> connected_component) const
        -> bool {
        return std::find(connected_components.begin(), connected_components.end(), connected_component) !=
               connected_components.end();
    }

    /// @brief Gets the vertices of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @return The vertices of the graph.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::isConnected() const -> bool {
        return connected_components.size() == 1;
    }

    /// @brief Checks if the graph is cyclic.
    /// @tparam T The type of the vertices in the graph.
    /// @return True if the graph is cyclic, false otherwise.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::isCyclic() const -> bool {
        return cycles.size() > 0;
    }

    /// @brief Checks if the graph is acyclic.
    /// @tparam T The type of the vertices in the graph.
    /// @return True if the graph is acyclic, false otherwise.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::isAcyclic() const -> bool {
        return !isCyclic();
    }

    /// @brief Checks if the graph is empty.
    /// @tparam T The type of the vertices in the graph.
    /// @return True if the graph is empty, false otherwise.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::isEmpty() const -> bool {
        return vertices.size() == 0;
    }

    /// @brief Checks if the graph is not empty.
    /// @tparam T The type of the vertices in the graph.
    /// @return True if the graph is not empty, false otherwise.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::getVertices() const -> std::vector<T> {
        return vertices;
    }

    /// @brief Gets the edges of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @return The edges of the graph.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::getEdges() const -> std::vector<std::pair<T, T>> {
        return edges;
    }

    /// @brief Gets the neighbors of a vertex.
    /// @tparam T The type of the vertices in the graph.
    /// @return The neighbors of the vertex.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::getComponents() const -> std::vector<std::vector<T>> {
        return connected_components;
    }

    /// @brief Gets the cycles of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @return The cycles of the graph.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::getCycles() const -> std::vector<std::vector<T>> {
        return cycles;
    }

    /// @brief Gets the connected component of a vertex.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to get the connected component of.
    /// @return The connected component of the vertex.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::getConnectedComponent(T vertex) -> std::vector<T> {
        for (std::vector<T> component : connected_components) {
            if (std::find(component.begin(), component.end(), vertex) != component.end()) {
                return component;
            }
        }
        return std::vector<T>();
    }

    /// @brief Gets the neighbors of a vertex.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    auto UndirectedGraph<T>::findConnectedComponents() -> void {
        connected_components.clear();
        std::vector<T> visited_vertices;
        for (T vertex : vertices) {
            if (std::find(visited_vertices.begin(), visited_vertices.end(), vertex) == visited_vertices.end()) {
                std::vector<T> connected_component;
                findConnectedComponent(vertex, visited_vertices, connected_component);
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
    auto UndirectedGraph<T>::findConnectedComponent(T vertex, std::vector<T>& visited_vertices,
                                                    std::vector<T>& connected_component) -> void {
        visited_vertices.push_back(vertex);
        connected_component.push_back(vertex);
        for (T neighbor : getNeighbors(vertex)) {
            if (std::find(visited_vertices.begin(), visited_vertices.end(), neighbor) == visited_vertices.end()) {
                findConnectedComponent(neighbor, visited_vertices, connected_component);
            }
        }
    }

    /// @brief Finds the cycles of the graph.
    /// @tparam T The type of the vertices in the graph.
    template <typename T>
    auto UndirectedGraph<T>::findCycles() -> void {
        cycles.clear();
        std::vector<T> visited_vertices;
        for (T vertex : vertices) {
            if (std::find(visited_vertices.begin(), visited_vertices.end(), vertex) == visited_vertices.end()) {
                std::vector<T> cycle;
                findCycle(vertex, visited_vertices, cycle);
            }
        }
    }

    /// @brief Finds a cycle of the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @param vertex The vertex to start the search from.
    /// @param visited_vertices The vertices that have been visited.
    /// @param cycle The cycle that has been found.
    template <typename T>
    auto UndirectedGraph<T>::findCycle(T vertex, std::vector<T>& visited_vertices, std::vector<T>& cycle) -> void {
        visited_vertices.push_back(vertex);
        cycle.push_back(vertex);
        for (T neighbor : getNeighbors(vertex)) {
            if (std::find(visited_vertices.begin(), visited_vertices.end(), neighbor) == visited_vertices.end()) {
                findCycle(neighbor, visited_vertices, cycle);
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
    [[nodiscard]] auto UndirectedGraph<T>::getNeighbors(T vertex) const -> std::vector<T> {
        std::vector<T> neighbors;
        for (auto [firstVertex, secondVertex] : edges) {
            if (firstVertex == vertex) {
                neighbors.push_back(secondVertex);
            } else if (secondVertex == vertex) {
                neighbors.push_back(firstVertex);
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
    [[nodiscard]] auto UndirectedGraph<T>::getNeighbors(T vertex, std::vector<std::pair<T, T>> edges) const
        -> std::vector<T> {
        std::vector<T> neighbors;
        for (std::pair<T, T> edge : edges) {
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
    [[nodiscard]] auto UndirectedGraph<T>::getNeighbors(T vertex, std::vector<T> vertices) const -> std::vector<T> {
        std::vector<T> neighbors;
        for (std::pair<T, T> edge : edges) {
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
    [[nodiscard]] auto UndirectedGraph<T>::getNeighbors(T vertex, std::vector<T> vertices,
                                                        std::vector<std::pair<T, T>> edges) const -> std::vector<T> {
        std::vector<T> neighbors;
        for (std::pair<T, T> edge : edges) {
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
    [[nodiscard]] auto UndirectedGraph<T>::getNeighbors(T vertex, std::vector<T> vertices,
                                                        std::vector<T> visited_vertices) const -> std::vector<T> {
        std::vector<T> neighbors;
        for (std::pair<T, T> edge : edges) {
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
    [[nodiscard]] auto UndirectedGraph<T>::getNeighbors(T vertex, std::vector<T> vertices,
                                                        std::vector<T> visited_vertices,
                                                        std::vector<std::pair<T, T>> edges) const -> std::vector<T> {
        // Create an empty vector to store the neighbors of the input vertex.
        std::vector<T> neighbors;
        // loop through all edges to find the neighbors of the input vertex.
        for (std::pair<T, T> edge : edges) {
            // If the first vertex of the edge is equal to the input vertex and the second vertex of the edge is within
            // the input vertices and not included in the visited vertices, add it to the vector of neighbors.
            if (edge.GetFirst() == vertex &&
                std::find(vertices.begin(), vertices.end(), edge.GetSecond()) != vertices.end() &&
                std::find(visited_vertices.begin(), visited_vertices.end(), edge.GetSecond()) ==
                    visited_vertices.end()) {
                neighbors.push_back(edge.GetSecond());
            } // If the second vertex of the edge is equal to the input vertex and the first vertex of the edge is
              // within
              // the input vertices and not included in the visited vertices, add it to the vector of neighbors.
            else if (edge.GetSecond() == vertex &&
                     std::find(vertices.begin(), vertices.end(), edge.GetFirst()) != vertices.end() &&
                     std::find(visited_vertices.begin(), visited_vertices.end(), edge.GetFirst()) ==
                         visited_vertices.end()) {
                neighbors.push_back(edge.GetFirst());
            }
        }
        // Return the vector of neighbors.
        return neighbors;
    }

    /// Gets the amount of vertices in the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @return The amount of vertices in the graph.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::getVertexCount() const -> std::size_t {
        return vertices.size();
    }

    /// @brief Gets amount of edges in the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @return The amount of edges in the graph.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::getEdgeCount() const -> std::size_t {
        return edges.size();
    }

    /// @brief Gets the amount of connected components in the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @return The amount of connected components in the graph.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::getConnectedComponentCount() const -> std::size_t {
        return connected_components.size();
    }

    /// Gets the amount of cycles in the graph.
    /// @tparam T The type of the vertices in the graph.
    /// @return The amount of cycles in the graph.
    template <typename T>
    [[nodiscard]] auto UndirectedGraph<T>::getCycleCount() const -> std::size_t {
        return cycles.size();
    }

    /**
     * The 'findConnectedComponent' function searches all neighbors of a given vertex recursively
     * and finds all the vertices that the given vertex is connected to.
     *
     * @tparam T (typename) The data type of the vertices
     * @param vertex (T) The initial vertex in the graph
     * @param visited_vertices (std::vector<T> &) A vector of visited vertices (passed as reference)
     * @param connected_component (std::vector<T> &) A vector of vertices that all belong to the same connected
     * component (passed as reference)
     */
    template <typename T>
    auto UndirectedGraph<T>::findConnectedComponent(T vertex, std::vector<T>& visited_vertices,
                                                    std::vector<T>& connected_component) const -> void {
        // Adds the initial vertex as visited and part of the connected component
        visited_vertices.push_back(vertex);
        connected_component.push_back(vertex);

        // Finds and visits all unvisited neighbors of the vertex
        std::vector<T> neighbors = getNeighbors(vertex, vertices, visited_vertices);
        for (T neighbor : neighbors) {
            if (std::find(visited_vertices.begin(), visited_vertices.end(), neighbor) == visited_vertices.end()) {
                findConnectedComponent(neighbor, visited_vertices, connected_component);
            }
        }
    }

} // namespace Tobot::DataStructures