#include "../include/Sort.h"

template<typename T>
void print_arr(std::vector<T> arr) {
	for (T num : arr) {
		std::cout << num << ' ';
	}
}


int main() {
	std::vector<int> arr{ 1, 4, 7, 3, 9, 8, 5, 6, 2 };
	print_arr(arr);
	std::cout << std::endl;
	std::cout << insertion_sort(arr);
	print_arr(arr);
	std::cout << std::endl;


	std::vector<int> data = { 1, 4, 7, 3, 9, 8, 5, 6, 2 };
	print_arr(data);
	std::cout << std::endl;
	std::cout << quick_sort_wrapper(data);
	print_arr(data);
}