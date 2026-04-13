/* File TEST per l'algoritmo SELECTION SORT */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include "sorts.hpp"
#include "randfiller.h"

/* Costruzione della funzione template is_sorted() */
template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
	int n = vec.size();
	for (int i = 0; i <= n-2; i++) {
		if (vec[i] > vec[i+1]) {
			return false;
		}
	}
	
	return true;
}

/* Main che controlla il corretto funzionamento di SELECTION SORT */
int main() {
	int n_vettori = 100;
	
	/* Creo con randfiller un vettore con le dimensioni dei 100 vettori da ordinare */
	randfiller rf;

    std::vector<int> dimensioni;
    dimensioni.resize(n_vettori);
    rf.fill(dimensioni, 0, 100);
	
	/* Creo i 100 vettori, li riempio con numeri casuali con randfiller e li ordino */
	for (int i = 0; i <= n_vettori-1; i++) {

		std::vector<int> vi;
		vi.resize(dimensioni[i]);
		rf.fill(vi, -100, 100);
		
		selectionsort(vi);
		
		if (is_sorted(vi) == false) {
			return EXIT_FAILURE;
		}
	}
	
	/* Creo il vettore di stringhe e lo ordino */
	std::vector<std::string> s = {"ruote", "manubrio", "motore", "carena", "cupolino", "serbatoio", "catena", "sella", "fari", "leve", "pedaline"};
	
	selectionsort(s);
	
	if (is_sorted(s) == false) {
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}		