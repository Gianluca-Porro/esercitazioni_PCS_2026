/* Sorts */

#include <iostream>
#include <optional>
#include <vector>

/* BUBBLE SORT */
template<typename T>
std::optional<std::vector<T>> /* std::vector<T> */
bubblesort(std::vector<T>& vec)
{
	int n = vec.size();
	if (n < 2) {
		return{};
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
	
	return vec;
}

/* INSERTION SORT */
template<typename T>
std::optional<std::vector<T>> /* std::vector<T> */
insertionsort(std::vector<T>& vec)
{
	int n = vec.size();
	if (n < 2) {
		return{};
	}
	
	for (int i = 1; i <= n-1; i++) {
		T key_value = vec[i];
		int j = i-1;
		while (j >= 0 && vec[j] > key_value) {
			T swap_value = vec[j+1];
			vec[j+1] = vec[j];
			vec[j] = swap_value;
			j = j-1;
		}
		vec[j+1] = key_value;
	}
	
	return vec;
}

/* SELECTION SORT */
template<typename T>
std::optional<std::vector<T>> /* std::vector<T> */
selectionsort(std::vector<T>& vec)
{
	int n = vec.size();
	if (n < 2) {
		return{};
	}
	
	for (int i = 0; i <= n-2; i++) { /* Parametri impostati per come messi nelle note del prof */
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
	
	return vec;
}