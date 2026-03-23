#include <iostream>
#include <cmath>

int main()
{
	static const int N = 10;
	double arr[N] = {2.8, 8.4, 9, 4.75, 13.2, 1, 0.5, 3.12, 7.86, 10.7};
	
	double min_arr = arr[0];
	for (int i=1; i<=N-1; i++) {
		min_arr = std::min(min_arr, arr[i]);
	}
	
	double max_arr = arr[0];
	for (int i=1; i<=N-1; i++) {
		max_arr = std::max(max_arr, arr[i]);
	}
	
	double sum_arr = 0;
	for (int i=0; i<=N-1; i++) {
		sum_arr = sum_arr + arr[i];
	}
	double mean_arr = sum_arr/N;
	
	double s_arr = 0;
	for (int i=0; i<=N-1; i++) {
		s_arr = s_arr + ((arr[i] - mean_arr)*(arr[i] - mean_arr));
	}
	double std_arr = std::sqrt(s_arr/(N-1));
	
	
	std::cout << min_arr << "\n";
	std::cout << max_arr << "\n";
	std::cout << mean_arr << "\n";
	std::cout << std_arr << "\n";
	
	return 0;
}