#ifndef SORT_INCLUDE_SORT_H
#define SORT_INCLUDE_SORT_H

// сортировка вставками, быстрая сортировка, пирамидальная сортировка

#include <vector>
#include "../include/Stats.h"


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
            stats.copy_count++;
            --j;
        }
    }
    return stats;
}



#endif