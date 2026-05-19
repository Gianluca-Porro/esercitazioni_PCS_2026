#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "FIFO_LIFO.hpp"
#include "visit.hpp"
#include "Dijkstra.hpp"

int main() {
    unidirected_graph<int> G;
    G.add_edge(1, 2);
    G.add_edge(1, 3);
    G.add_edge(1, 4);
    G.add_edge(1, 6);
    G.add_edge(2, 4);
    G.add_edge(2, 5);
    G.add_edge(2, 7);
    G.add_edge(3, 6);
    G.add_edge(4, 6);
    G.add_edge(4, 7);
    G.add_edge(5, 7);
    G.add_edge(6, 7);
    G.add_edge(6, 8);
    G.add_edge(7, 9);
    G.add_edge(8, 9);

    /* Grafo originale per GraphViz */
    std::cout << "graph Grafo_originale {\n";
    for (const auto& edge : G.all_edges()) {
        std::cout << "  " << edge.from() << " -- " << edge.to() << ";\n";
    }
    std::cout << "}\n" << "\n";


    /* Test della visita con fifo */
    fifo q;
    auto bfsG = graph_visit(G, 1, q);

    /* Grafo bfs per GraphViz */
    std::cout << "graph Albero_BFS {\n";
    for (const auto& edge : bfsG.all_edges()) {
        std::cout << "  " << edge.from() << " -- " << edge.to() << ";\n";
    }
    std::cout << "}\n" << "\n";


    /* Test della visita con lifo */
    lifo s;
    auto dfsG = graph_visit(G, 1, s);

    /* Grafo dfs per GraphViz */
    std::cout << "graph Albero_DFS {\n";
    for (const auto& edge : dfsG.all_edges()) {
        std::cout << "  " << edge.from() << " -- " << edge.to() << ";\n";
    }
    std::cout << "}\n" << "\n";


    /* Test della visita con recursive_dfs */
    auto recDfsG = recursive_dfs(G, 1);

    /* Grafo recursive_dfs per GraphViz */
    std::cout << "graph Albero_recursive_dfs {\n";
    for (const auto& edge : recDfsG.all_edges()) {
        std::cout << "  " << edge.from() << " -- " << edge.to() << ";\n";
    }
    std::cout << "}\n" << "\n";

    /* Test della visita con Dijkstra */
    std::map<unidirected_edge<int>, int> W;
    int n = G.all_nodes().size();

    std::cout << "Dijkstra: \n";
    dijkstra(G, 1, W, n);

    return 0;
}