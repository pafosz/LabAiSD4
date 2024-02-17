#ifndef LAB_4_INCLUDE_GENERATOR_H
#define LAB_4_INCLUDE_GENERATOR_H

#include "search_tree.h"
#include <vector>

const size_t K = 116640;

int lcg(const int& = K);

SearchTree generateRandomTree(size_t);

std::vector<int> generateRandomVector(size_t);

#endif