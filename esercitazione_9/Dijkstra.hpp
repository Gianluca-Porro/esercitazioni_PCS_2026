#pragma once

#include <iostream>
#include <map>
#include <set>
#include "unidirected_graph.hpp"

template <typename T>
void dijkstra (const unidirected_graph<T>& LA, T s, const std::map<unidirected_edge<T>, int>& W, int n) {
	std::set<T> nodi = LA.all_nodes();
	std::set<T> nodi_visitati;
	std::map<T, bool> visto;
	std::map<T, int> dist;
	std::map<T, T> pred;
	
	for (auto itor = nodi.begin(); itor != nodi.end(); itor++) {
		T nodo = *itor;
		
		pred[nodo] = T();
		dist[nodo] = 0;
		visto[nodo] = false;
	}
	
	pred[s] = s;
	dist[s] = 0;
	visto[s] = true;
	
	for (int i = 0; i < n; i++) {
		T u = T();
		bool cerca_nodo = false;
		
		for (auto itor = nodi.begin(); itor != nodi.end(); itor++) {
			T nodo = *itor;
		
			if (nodi_visitati.count(nodo) == 0 && visto[nodo] == true) {
				if (cerca_nodo == false || dist[nodo] < dist[u]) {
					u = nodo;
					cerca_nodo = true;
				}
			}
		}
		
		if (cerca_nodo == false) {
			break;
		}
		
		nodi_visitati.insert(u);
		
		std::set<T> vicini = LA.neighours(u);
		
		for (auto itor = vicini.begin(); itor != vicini.end(); itor++) {
			T v = *itor;
			
			if (nodi_visitati.count(v) == 0) {
				int peso_arco = 1;
					
				if (visto[v] == false || dist[v] > dist[u] + peso_arco) {
					dist[v] = dist[u] + peso_arco;
					pred[v] = u;
					visto[v] = true;
				}
			}
		}
	}

	
	for (auto itor = nodi.begin(); itor != nodi.end(); itor++) {
		T nodo = *itor;
		
		std::cout << "Nodo: " << nodo << "\n"
		          << " Dist: " << dist[nodo] << "\n"
		          << " Pred: " << pred[nodo] << "\n";
	}
}		  