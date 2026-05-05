/* Sorts */

#include <iostream>
#include <vector>

/* BUBBLE SORT */
template<typename T>
void bubblesort(std::vector<T>& vec)
{
	int n = vec.size();
	if (n < 2) {
		return;
	}
	
	for (int i = 0; i <= n-2; i++) {
		for (int j = n-1; j >= i+1; j--) {
			if (vec[j] < vec[j-1]) {
				T swap_value = vec[j];
				vec[j] = vec[j-1];
				vec[j-1] = swap_value;
			}
		}
	}
}

/* INSERTION SORT */
template<typename T>
void insertionsort(std::vector<T>& vec)
{
	int n = vec.size();
	if (n < 2) {
		return;
	}
	
	for (int i = 1; i <= n-1; i++) {
		T key_value = vec[i];
		int j = i-1;
		while (j >= 0 && vec[j] > key_value) {
			vec[j+1] = vec[j];
			j = j-1;
		}
		vec[j+1] = key_value;
	}
}

/* SELECTION SORT */
template<typename T>
void selectionsort(std::vector<T>& vec)
{
	int n = vec.size();
	if (n < 2) {
		return;
	}
	
	for (int i = 0; i <= n-2; i++) {
		int min_index = i;
		for (int j = i+1; j <= n-1; j++) {
			if (vec[j] < vec[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i) {
			T swap_value = vec[i];
			vec[i] = vec[min_index];
			vec[min_index] = swap_value;
		}
	}
}

/* MERGE */
template<typename T>
void merge(std::vector<T>& vec, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	
	std::vector<T> L(n1);
	std::vector<T> R(n2);
	
	for (int i = 0; i < n1; i++) {
		L[i] = vec[p + i];
	}
	
	for (int j = 0; j < n2; j++) {
		R[j] = vec[q + j + 1];
	}
	
	int i = 0;
	int j = 0;
	int k = p;
    
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			vec[k] = L[i];
			i = i + 1;
		}
		else {
			vec[k] = R[j];
			j = j + 1;
		}
		k = k + 1;
	}
	
	while (i < n1) {
		vec[k] = L[i];
		i = i + 1;
		k = k + 1;
	}
	
	while (j < n2) {
		vec[k] = R[j];
		j = j + 1;
		k = k + 1;
	}
		
}

/* MERGE SORT */
template<typename T>
void mergesort(std::vector<T>& vec, int p, int r)
{
	if (p < r) {
		int q = (p+r)/2;
		mergesort(vec, p, q);
		mergesort(vec, q+1, r);
		merge(vec, p, q, r);
	}
}

/* PARTITION */
template<typename T>
int partition(std::vector<T>& vec, int p, int r)
{
	T x = vec[r];
	int i = p - 1;
	
	for (int j = p; j <= r - 1; j++) {
		if (vec[j] <= x) {
			i = i + 1;
			T swap_value = vec[i];
			vec[i] = vec[j];
			vec[j] = swap_value;
		}
	}
	
	T swap_value = vec[i+1];
	vec[i+1] = vec[r];
	vec[r] = swap_value;
	
	return i+1;
}

/* QUICK SORT */
template<typename T>
void quicksort(std::vector<T>& vec, int p, int r)
{
	if (p < r) {
		int q = partition(vec, p, r);
		quicksort(vec, p, q-1);
		quicksort(vec, q+1, r);
	}
}

/* INSERTION SORT MODIFICATO*/
template<typename T>
void insertionsort_modificato(std::vector<T>& vec, int p, int r)
{
	int n = vec.size();
	if (n < 2) {
		return;
	}
	
	for (int i = p + 1; i <= r; i++) {
		T key_value = vec[i];
		int j = i-1;
		while (j >= p && vec[j] > key_value) {
			vec[j+1] = vec[j];
			j = j-1;
		}
		vec[j+1] = key_value;
	}
}

/* QUICK SORT MODIFICATO */
template<typename T>
void quicksort_modificato(std::vector<T>& vec, int p, int r)
{
	int soglia = 30;
	if (r - p < soglia) {
		insertionsort_modificato(vec, p, r);
	}
	
	if (p < r) {
		int q = partition(vec, p, r);
		quicksort_modificato(vec, p, q-1);
		quicksort_modificato(vec, q+1, r);
	}
}