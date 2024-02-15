#ifndef LAB_4_INCLUDE_EXPERIMENT_H
#define LAB_4_INCLUDE_EXPERIMENT_H

#include <chrono>
#include <algorithm>

#include "generator.h"

const size_t NUM_ATTEMPS1 = 100;
const size_t NUM_ATTEMPS2 = 1000;

template<typename T>
double averageFillingTime(T generate_func, size_t len) {
	double tTime = 0.0;
	for (size_t i = 0; i < NUM_ATTEMPS1; ++i) {
		auto start = std::chrono::steady_clock::now();
		generate_func(len);
		auto end = std::chrono::steady_clock::now();

		std::chrono::duration<double> duration = end - start;
		tTime += duration.count(); //tTime в секундах
	}
	double average_time = tTime / NUM_ATTEMPS1;
	return average_time;
}
//===============================================================================================================
//                                             Tree
//===============================================================================================================
double averageTimeSearchInTree(const SearchTree& tree) {
	double tTime = 0.0;
	for (size_t i = 0; i < NUM_ATTEMPS2; ++i) {
		auto start = std::chrono::steady_clock::now();
		tree.contains(lcg());
		auto end = std::chrono::steady_clock::now();

		std::chrono::duration<double> duration = end - start;
		tTime += duration.count(); //tTime в секундах
	}
	double average_time = tTime / NUM_ATTEMPS2;
	return average_time;
}

double averageTimeInsertTree(SearchTree tree) {
	double tTime = 0.0;
	for (size_t i = 0; i < NUM_ATTEMPS2; ++i) {
		auto start = std::chrono::steady_clock::now();
		tree.insert(lcg());
		auto end = std::chrono::steady_clock::now();

		std::chrono::duration<double> duration = end - start;
		tTime += duration.count(); //tTime в секундах
	}
	double average_time = tTime / NUM_ATTEMPS2;
	return average_time;
}

double averageTimeEraseTree(SearchTree tree) {
	double tTime = 0.0;
	for (size_t i = 0; i < NUM_ATTEMPS2; ++i) {
		auto start = std::chrono::steady_clock::now();
		tree.insert(lcg());
		auto end = std::chrono::steady_clock::now();

		std::chrono::duration<double> duration = end - start;
		tTime += duration.count(); //tTime в секундах
	}
	double average_time = tTime / NUM_ATTEMPS2;
	return average_time;
}
//===============================================================================================================
//                                             Vector
//===============================================================================================================
double averageTimeSearchInVector(const std::vector<int>& arr) {
	double tTime = 0.0;
	for (size_t i = 0; i < NUM_ATTEMPS2; ++i) {
		auto start = std::chrono::steady_clock::now();
		std::find(arr.begin(), arr.end(), lcg());
		auto end = std::chrono::steady_clock::now();

		std::chrono::duration<double> duration = end - start;
		tTime += duration.count(); //tTime в секундах
	}
	double average_time = tTime / NUM_ATTEMPS2;
	return average_time;
}

double averageTimeInsertVector(std::vector<int> arr) {
	double tTime = 0.0;
	for (size_t i = 0; i < NUM_ATTEMPS2; ++i) {
		auto start = std::chrono::steady_clock::now();
		arr.insert(arr.begin() + lcg(int(arr.size())), lcg());
		auto end = std::chrono::steady_clock::now();

		std::chrono::duration<double> duration = end - start;
		tTime += duration.count(); //tTime в секундах
	}
	double average_time = tTime / NUM_ATTEMPS2;
	return average_time;
}

double averageTimeEraseVector(std::vector<int> arr) {
	double tTime = 0.0;
	for (size_t i = 0; i < NUM_ATTEMPS2; ++i) {
		auto start = std::chrono::steady_clock::now();
		arr.erase(arr.begin() + lcg(int(arr.size())));
		auto end = std::chrono::steady_clock::now();

		std::chrono::duration<double> duration = end - start;
		tTime += duration.count(); //tTime в секундах
	}
	double average_time = tTime / NUM_ATTEMPS2;
	return average_time;
}


#endif