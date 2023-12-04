#include <vector>


#include "../include/Stats.h"
#include "../include/Analytics.h"
#include "../include/Sort.h"
#include "../include/Fruits.h"

template<typename T>
void print_arr(std::vector<T> arr) {
	for (T num : arr) {
		std::cout << num << ' ';
	}
}


int main() {

	std::vector<std::string> str = { "good", "table", "cake", "umbrella", "map", "jam", "argument", "bottle" };
	print_arr(str);
	std::cout << std::endl;
	insertion_sort(str);
	print_arr(str);
	std::cout << std::endl;
	std::vector<Fruits> fruits = { Fruits("Pear", 100), Fruits("Banana", 300), Fruits("Pineapple", 1032), Fruits("Watermelon", 6432), Fruits("Apple", 125) };
	std::cout << fruits;
	quick_sort_wrapper(fruits);
	std::cout << fruits;

	std::vector<int> arr{ 8, 6, 3, 2, 4, 9, 5, 1, 7 };
	print_arr(arr);
	std::cout << std::endl;
	std::cout << insertion_sort(arr);
	print_arr(arr);
	std::cout << std::endl;
	std::cout << std::endl;

	std::vector<int> data { 8, 6, 3, 2, 4, 9, 5, 1, 7 };
	print_arr(data);
	std::cout << std::endl;
	std::cout << quick_sort_wrapper(data);
	print_arr(data);
	std::cout << std::endl;
	std::cout << std::endl;

	std::vector<int> heap { 8, 6, 3, 2, 4, 9, 5, 1, 7 };
	print_arr(heap);
	std::cout << std::endl;
	std::cout << heap_sort_wrapper(heap);
	print_arr(heap);
	std::cout << std::endl;

	//std::vector<size_t> lens_arr = { 1000, 2000, 3000, 4000, 5000,6000,7000,8000,9000, 10000, 25000, 50000 };
	//int min = 1;
	//int max = 50000;

	//std::cout << "Statistics of the reverse array for heap_sort_wrapper" << std::endl;
	//get_stats_sort(lens_arr, generate_sort_vect, heap_sort_wrapper);
	//std::cout << "Statistics of the reverse array for heap_sort_wrapper" << std::endl;
	//get_stats_sort(lens_arr, generate_reverse_sort_vect, heap_sort_wrapper);
	//std::cout << "Statistics for heap_sort_wrapper" << std::endl;
	//get_stats(min, max, lens_arr, heap_sort_wrapper);


	std::cout << "Ready" << std::endl;
	

	return 0;

}

