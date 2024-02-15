#include "../include/generator.h"

int lcg(const int& len) {
    static int x = 0;
    x = (1021 * x + 24631) % len; //116640
    return x;
}

SearchTree generateRandomTree(size_t size) {
    SearchTree tree;
    for (size_t i = 0; i < size; ++i) {
        tree.insert(lcg());
    }
    return tree;
}

std::vector<int> generateRandomVector(size_t size) {
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        arr.push_back(lcg());
    }
    return arr;
}