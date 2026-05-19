#pragma once

#include <set>
#include <vector>
#include "unidirected_graph.hpp"

/* Implemento la funzione graph_visit */
template <typename T, typename R>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& G, T nodo_sorg, R cont) {
	/* Creo albero e set di visite dei nodi */
	unidirected_graph<T> albero;
	std::set<T> visite;
	
	/* Inizializzo il contenitore e il set di visite dal nodo sorgente*/
	cont.put(nodo_sorg);
	visite.insert(nodo_sorg);
	
	while (cont.empty() == false) {
		T u = cont.get();
		
		std::set<T> vicini = G.neighours(u);
		
		/* Per ogni vicino controllo e inserisco l'arco nell'albero */
		for (const T& v : vicini) {
			if (visite.find(v) == visite.end()) {
				visite.insert(v);
				albero.add_edge(u, v);
				cont.put(v);
			}
		}
	}
	
	return albero;
}

template <typename T>
void dfs(const unidirected_graph<T>& G, T u, unidirected_graph<T>& albero) {
	std::set<T> nodi_vicini = G.neighours(u);
	
	for (const T& v : nodi_vicini) {
		/* Controllo quali sono i nodi già visti */
		std::set<T> nodi_visti = albero.all_nodes();
		
		if (nodi_visti.find(v) == nodi_visti.end()) {
			albero.add_edge(u, v);
			
			dfs(G, v, albero);
		}
	}
}

template <typename T>
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& G, T nodo_sorgente) {
	unidirected_graph<T> albero;
	
	/* Grafo vuoto */
	if (G.neighours(nodo_sorgente).empty()) {
		return albero;
	}
	
	dfs(G, nodo_sorgente, albero);
	
	return albero;
}