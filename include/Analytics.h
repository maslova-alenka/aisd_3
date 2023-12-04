#ifndef SORT_INCLUDE_ANALYTICS_H
#define SORT_INCLUDE_ANALYTICS_H

#include <iostream>
#include <vector>
#include <random>

#include "../include/Sort.h"
#include "../include/Random.h"


Stats average_stats(int min, int max, size_t length, Stats(*sort_func)(std::vector<int>& arr)) {
    Stats aver_stats;
    size_t count = 100;
    for (size_t i = 0; i < count; ++i) {
        std::vector<int> vec = generate_random_vect(min, max, length);
        aver_stats += sort_func(vec);
    }
    aver_stats.comparison_count /= count;
    aver_stats.copy_count /= count;

    return aver_stats;
}

void get_stats(int min, int max, const std::vector<size_t>& len_vec, Stats(*sort_func)(std::vector<int>& arr)) {
    for (size_t i = 0; i < len_vec.size(); ++i) {
        Stats stats = average_stats(min, max, len_vec[i], sort_func);
        std::cout << "Length: " << len_vec[i] << std::endl;
        std::cout << "Comparison count: " << stats.comparison_count << std::endl;
        std::cout << "Copy count: " << stats.copy_count << std::endl;
    }
    std::cout << std::endl;
}

void get_stats_sort(const std::vector<size_t>& len_vec, std::vector<int>(*generate_func)(size_t length), Stats(*sort_func)(std::vector<int>& a)) {
    for (size_t i = 0; i < len_vec.size(); ++i) {
        std::vector<int> a = generate_func(len_vec[i]);
        Stats stats = sort_func(a);
        std::cout << "Length: " << len_vec[i] << std::endl;
        std::cout << "Comparison count: " << stats.comparison_count << std::endl;
        std::cout << "Copy count: " << stats.copy_count << std::endl;
    }
    std::cout << std::endl;
}

#endif