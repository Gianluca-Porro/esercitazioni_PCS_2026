#pragma once

#include <iostream>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <vector>
#include "unidirected_edge.hpp"

template<typename T>
class unidirected_graph
{
private:
	std::map<T, std::set<T>> adiacenze;
	std::vector<unidirected_edge<T>> archi;
	
public:
	/* Costruttore di default */
	unidirected_graph() {}
	
	/* Costruttore di copia */
	unidirected_graph(const unidirected_graph& other)
		: adiacenze(other.adiacenze), archi(other.archi)
	{}
	
	/* Metodo neighours() */
	std::set<T> neighours(T nodo) const {
		if (adiacenze.count(nodo)) {
			return adiacenze.at(nodo);
		}
		else {
			return std::set<T>();
		}
	}
	
	/* Metodo add_edge() */
	void add_edge(T u, T v) {
		unidirected_edge<T> nuovo_arco(u, v);
		
		bool nodo_esistente = false;
		
		for (size_t i = 0; i < archi.size(); i++) {
			if (archi[i] == nuovo_arco) {
				nodo_esistente = true;
			}
		}
		
		if (nodo_esistente == false) {
			archi.push_back(nuovo_arco);
			
			adiacenze[u].insert(v);
			adiacenze[v].insert(u);
		}
	}
	
	/* Metodo all_edges() */
	std::vector<unidirected_edge<T>> all_edges() const {
		return archi;
	}
	
	/* Metodo all_nodes() */
	std::set<T> all_nodes() const {
		std::set<T> nodi;
		for (size_t i = 0; i < archi.size(); i++) {
			unidirected_edge<T> arco_in_esame = archi[i];
			
			nodi.insert(arco_in_esame.from());
			nodi.insert(arco_in_esame.to());
		}
		
		return nodi;
	}
	
	/* Metodo edge_number() */
	int edge_number(const unidirected_edge<T> arco) const {
		for (size_t i = 0; i < archi.size(); i++) {
			if (archi[i] == arco) {
				return i;
			}
		}
		
		return -1;
	}	
	
	/* Metodo edge_at() */
	unidirected_edge<T> edge_at(int i) const {
		return archi[i];
	}
};
	
/* Implementazione operator-() */
template<typename T>
inline std::vector<unidirected_edge<T>> operator-(const unidirected_graph<T> G1, const unidirected_graph<T> G2) {
	std::vector<unidirected_edge<T>> differenza_archi;
	
	std::vector<unidirected_edge<T>> archi_G1 = G1.all_edges();
	
	for(size_t i = 0; i < archi_G1.size(); i++) {
		unidirected_edge<T> controllo_arco = archi_G1[i];
		
		if (G2.edge_number(controllo_arco) == -1) {
			differenza_archi.push_back(controllo_arco);
		}
	}
	
	return differenza_archi;
}