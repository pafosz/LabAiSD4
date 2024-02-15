#ifndef LAB_4_INCLUDE_GENERATOR_H
#define LAB_4_INCLUDE_GENERATOR_H

#include "search_tree.h"
#include <vector>

int lcg(const int& len = 116640) {
    static int x = 0;
    x = (1021 * x + 24631) % len; //116640
    return x;
}

SearchTree generateRandomTree(size_t size, int(*generate_func)(const int&) = lcg) {
    SearchTree tree;
    for (size_t i = 0; i < size; ++i) {
        tree.insert(generate_func(116640));
    }
    return tree;
}

std::vector<int> generateRandomVector(size_t size, int(*generate_func)(const int&) = lcg) {
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        arr.push_back(generate_func(116640));
    }
    return arr;
}

#endif