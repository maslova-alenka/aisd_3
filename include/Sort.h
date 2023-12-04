#ifndef SORT_INCLUDE_SORT_H
#define SORT_INCLUDE_SORT_H

// сортировка вставками, быстрая сортировка, пирамидальная сортировка

#include <vector>
#include "../include/Stats.h"
//#include "../include/Random.h"
//#include "../include/Analytics.h"


// сортировка вставками
template<typename T>
Stats insertion_sort(std::vector<T>& arr) {
    Stats stats;
    if (arr.size() < 2)
        return stats;
    for (size_t i = 1; i < arr.size(); ++i) {
        size_t j = i;
        while (j != 0 && arr[j] < arr[j - 1]) {
            stats.comparison_count++;
            std::swap(arr[j - 1], arr[j]);
            stats.copy_count+=2;
            --j;
        }
    }
    return stats;
}


// быстрая сортировка 

template<typename T>
int partition(std::vector<T>& arr, int low, int high, Stats& stats) {
    T pivot = arr[high];
    int i = low - 1;

    for (size_t j = low; j <= high - 1; ++j) {
        stats.comparison_count++;
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
            stats.copy_count+=2;
        }
    }

    std::swap(arr[i + 1], arr[high]);
    stats.copy_count+=2;

    return i + 1;
}

template<typename T>
void quick_sort(std::vector<T>& arr, int low, int high, Stats& stats) {
    if (low < high) {
        int partition_index = partition(arr, low, high, stats);

        quick_sort(arr, low, partition_index - 1, stats);
        quick_sort(arr, partition_index + 1, high, stats);
    }
}

template<typename T>
Stats quick_sort_wrapper(std::vector<T>& arr) {
    Stats stats;
    quick_sort(arr, 0, arr.size() - 1, stats);
    return stats;
}


// пирамидальная сортировка
template<typename T>
void heapify(std::vector<T>& arr, int size, int index, Stats& stats) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    stats.comparison_count += 1;
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
        stats.copy_count += 1;
    }

    stats.comparison_count += 1;
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
        stats.copy_count += 1;
    }

    stats.comparison_count += 1;
    if (largest != index) {
        std::swap(arr[index], arr[largest]);
        stats.copy_count += 1;

        heapify(arr, size, largest, stats);
    }
}

template<typename T>
void heap_sort(std::vector<T>& arr, Stats& stats) {
    int size = arr.size();

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i, stats);
    }

    for (int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        stats.copy_count += 2;

        heapify(arr, i, 0, stats);
    }
}

template<typename T>
Stats heap_sort_wrapper(std::vector<T>& arr) {
    Stats stats;
    heap_sort(arr,stats);
    return stats;
}


#endif