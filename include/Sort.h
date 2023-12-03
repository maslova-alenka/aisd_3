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


// быстрая сортировка 
struct Partition {
    int start;
    int end;
};

Stats quick_sort(std::vector<int>& arr, int start, int end) {
    Stats stats;
    std::vector<Partition> partitions;
    partitions.push_back({ start, end });

    while (!partitions.empty()) {
        start = partitions.back().start;
        end = partitions.back().end;
        partitions.pop_back();

        if (start < end) {
            int pivot = arr[end];
            int i = start - 1;

            for (int j = start; j <= end - 1; ++j) {
                stats.comparison_count++;
                if (arr[j] < pivot) {
                    ++i;
                    std::swap(arr[i], arr[j]);
                    stats.copy_count++;
                }
            }

            std::swap(arr[i + 1], arr[end]);
            stats.copy_count++;

            int partition_index = i + 1;

            partitions.push_back({ start, partition_index - 1 });
            partitions.push_back({ partition_index + 1, end });
        }
    }

    return stats;
}

Stats quick_sort_wrapper(std::vector<int>& arr) {
    return quick_sort(arr, 0, arr.size() - 1);
}

// пирамидальная сортировка


#endif