/* File per il measure sort */

#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include "sorts.hpp"
#include "timecounter.h"
#include "randfiller.h"

int main() {
	timecounter tc; /* instantiate the timecounter */
    
	for (int i = 4; i <= 8192; i = i*2) {
		randfiller rf;

		std::vector<int> vi;
		vi.resize(i);
		rf.fill(vi, -10000, 10000);
		
		std::cout << "Dimensione vettore: " << i << "\n";
		
		std::vector<int> vi_copia = vi;
		
		/* Test su Bubble sort */
		tc.tic();
		bubblesort(vi);
		double secs_bubble = tc.toc(); 
		std::cout << "Tempo con il Bubble sort: " << secs_bubble << " secondi\n";
		
		/* Test su Insertion sort */
		vi = vi_copia;
		tc.tic();
		insertionsort(vi);
		double secs_insertion = tc.toc(); 
		std::cout << "Tempo con il Insertion sort: " << secs_insertion << " secondi\n";
		
		/* Test su Selection sort */
		vi = vi_copia;
		tc.tic();
		selectionsort(vi);
		double secs_selection = tc.toc(); 
		std::cout << "Tempo con il Selection sort: " << secs_selection << " secondi\n";
		
		/* Test su std::sort() */
		vi = vi_copia;
		tc.tic();
		std::sort(vi.begin(), vi.end());
		double secs_sort = tc.toc(); 
		std::cout << "Tempo con il std::sort: " << secs_sort << " secondi\n";
		
		std::cout << "\n";
	}
	
	return 0;
}