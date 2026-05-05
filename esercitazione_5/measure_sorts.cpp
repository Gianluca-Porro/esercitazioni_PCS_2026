/* File per il measure sort */

#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include "sorts.hpp"
#include "timecounter.h"
#include "randfiller.h"

int main(void) {
	timecounter tc;
	randfiller rf;
	
	std::vector<std::vector<int>> vettori(100);
	
	std::cout << "Dimensione     " << "Bubble     " << "Insertion     " << "Selection     " << "Merge     " << "Quick     " << "Quick_mod    " << "std::sort\n";
	
	for (int j = 0; j < 100; j++) {
		std::cout << j << "              ";
	
		for (int i = 0; i < 100; i++) {
			std::vector<int> vi;
			vi.resize(j);
			rf.fill(vi, -200, 200);
		
			vettori[i] = vi;
		}
	
		std::vector<std::vector<int>> vettori_copia = vettori;
	
		/* Calcolo tempo BUBBLE SORT */
		tc.tic();
		for (int i = 0; i < 100; i++) {
			bubblesort(vettori[i]);
		}
		double secs_bubble = tc.toc();
		double avg_bubble = secs_bubble/100;
	
		std::cout << avg_bubble << "   ";
	
		/* Calcolo tempo INSERTION SORT */
		vettori = vettori_copia;
		tc.tic();
		for (int i = 0; i < 100; i++) {
			insertionsort(vettori[i]);
		}
		double secs_insertion = tc.toc();
		double avg_insertion = secs_insertion/100;
	
		std::cout << avg_insertion << "   ";
	
		/* Calcolo tempo SELECTION SORT */
		vettori = vettori_copia;
		tc.tic();
		for (int i = 0; i < 100; i++) {
			selectionsort(vettori[i]);
		}
		double secs_selection = tc.toc();
		double avg_selection = secs_selection/100;
	
		std::cout << avg_selection << "   ";
	
		/* Calcolo tempo MERGE SORT */
		vettori = vettori_copia;
		tc.tic();
		for (int i = 0; i < 100; i++) {
			int v_size = vettori[i].size();
			mergesort(vettori[i], 0, v_size-1);
		}
		double secs_merge = tc.toc();
		double avg_merge = secs_merge/100;
		
		std::cout << avg_merge << "   ";
		
		/* Calcolo tempo QUICK SORT */
		vettori = vettori_copia;
		tc.tic();
		for (int i = 0; i < 100; i++) {
			int v_size = vettori[i].size();
			quicksort(vettori[i], 0, v_size-1);
		}
		double secs_quick = tc.toc();
		double avg_quick = secs_quick/100;
		
		std::cout << avg_quick << "   ";
		
		/* Calcolo tempo QUICK SORT MODIFICATO */
		vettori = vettori_copia;
		tc.tic();
		for (int i = 0; i < 100; i++) {
			int v_size = vettori[i].size();
			quicksort_modificato(vettori[i], 0, v_size-1);
		}
		double secs_quick_modificato = tc.toc();
		double avg_quick_modificato = secs_quick_modificato/100;
		
		std::cout << avg_quick_modificato << "   ";
		
		/* Calcolo tempo STD::SORT */
		vettori = vettori_copia;
		tc.tic();
		for (int i = 0; i < 100; i++) {
			std::sort(vettori[i].begin(), vettori[i].end());
		}
		double secs_sort = tc.toc();
		double avg_sort = secs_sort/100;
		
		std::cout << avg_sort << "\n";
	}
	
	return 0;
}