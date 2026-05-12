#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cstdlib>
#include "unidirected_graph.hpp"

/* Test per la struttura dati implementata */
int main() {
	/* TEST PER NUMERI INTERI */
	
	/* unidirected_edge */
	unidirected_edge<int> e1(1, 2);
	unidirected_edge<int> e2(2, 1);
	unidirected_edge<int> e3(1, 3);
	
	/* Test from() e to() */
	if (e1.from() != 1 || e1.to() != 2) {
		return EXIT_FAILURE;
	}
	
	/* Test operator< */
	if ((e1 < e3) == false) {
		return EXIT_FAILURE;
	}
	
	/* Test operator== */
	if ((e1 == e2) == false) {
		return EXIT_FAILURE;
	}
	
	/* Test operator<< */
	std::cout << "Arco 1: " << e1 << "\n";
	
	/* unidirected_graph */
	unidirected_graph<int> G1;
	unidirected_graph<int> G2;
	
	/* Test add_edge */
	G1.add_edge(1, 2);
	G1.add_edge(2, 3);
	G2.add_edge(2, 3);
	
	/* Test edge_number */
	unidirected_edge<int> arco_intero(1, 2);
	if (G1.edge_number(arco_intero) != 0) {
		return EXIT_FAILURE;
	}
	
	/* Test edge_at */
	if ((G1.edge_at(1) == unidirected_edge<int>(2, 3)) == false) {
		return EXIT_FAILURE;
	}
	
	/* Test neighours */
	std::set<int> vicini_a_2 = G1.neighours(2);
	if (vicini_a_2.count(1) == 0 || vicini_a_2.count(3) == 0) {
		return EXIT_FAILURE;
	}
	
	/* Test all_edges */
	if (G1.all_edges().size() != 2) {
		return EXIT_FAILURE;
	}
	
	/* Test all_nodes */
	std::set<int> nodi_intero = G1.all_nodes();
	if (nodi_intero.size() != 3) {
		return EXIT_FAILURE;
	}
	
	/* Test operator- */
	std::vector<unidirected_edge<int>> differenza_intero = G1 - G2;
	if (differenza_intero.size() != 1) {
		return EXIT_FAILURE;
	}
	if ((differenza_intero[0] == unidirected_edge<int>(1, 2)) == false) {
		return EXIT_FAILURE;
	}
	
	
	/* TEST PER STRINGHE */
	
	/* unidirected_edge */
	unidirected_edge<std::string> e4("Casa", "Politecnico");
	unidirected_edge<std::string> e5("Politecnico", "Casa");
	unidirected_edge<std::string> e6("Casa", "Lavoro");
	
	/* Test from() e to() */
	if (e4.from() != "Casa" || e4.to() != "Politecnico") {
		return EXIT_FAILURE;
	}
	
	/* Test operator< */
	if ((e6 < e4) == false) {
		return EXIT_FAILURE;
	}
	
	/* Test operator== */
	if ((e4 == e5) == false) {
		return EXIT_FAILURE;
	}
	
	/* Test operator<< */
	std::cout << "Arco 4: " << e4 << "\n";
	
	/* unidirected_graph */
	unidirected_graph<std::string> G3;
	unidirected_graph<std::string> G4;
	
	/* Test add_edge */
	G3.add_edge("Casa", "Politecnico");
	G3.add_edge("Politecnico", "Lavoro");
	G4.add_edge("Politecnico", "Lavoro");
	
	/* Test edge_number */
	unidirected_edge<std::string> arco_stringa("Casa", "Politecnico");
	if (G3.edge_number(arco_stringa) != 0) {
		return EXIT_FAILURE;
	}
	
	/* Test edge_at */
	if ((G3.edge_at(1) == unidirected_edge<std::string>("Politecnico", "Lavoro")) == false) {
		return EXIT_FAILURE;
	}
	
	/* Test neighours */
	std::set<std::string> vicini_a_Politecnico = G3.neighours("Politecnico");
	if (vicini_a_Politecnico.count("Casa") == 0 || vicini_a_Politecnico.count("Lavoro") == 0) {
		return EXIT_FAILURE;
	}
	
	/* Test all_edges */
	if (G3.all_edges().size() != 2) {
		return EXIT_FAILURE;
	}
	
	/* Test all_nodes */
	std::set<std::string> nodi_stringa = G3.all_nodes();
	if (nodi_stringa.size() != 3) {
		return EXIT_FAILURE;
	}
	
	/* Test operator- */
	std::vector<unidirected_edge<std::string>> differenza_stringa = G3 - G4;
	if (differenza_stringa.size() != 1) {
		return EXIT_FAILURE;
	}
	if ((differenza_stringa[0] == unidirected_edge<std::string>("Casa", "Politecnico")) == false) {
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}