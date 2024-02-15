#include "../include/experiment.h"

using namespace std;
const std::vector<size_t> lengths = { 1000, 10000, 100000 };

void fillingTree() {
	cout << "—реднее врем€ заполнени€ дерева поиска " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		cout << lengths[i] << " уникальными случайными числами: "
			<< averageFillingTime(generateRandomTree, lengths[i]) << "сек." << endl;
	}
	cout << endl;
}

void fillingVector() {
	cout << "—реднее врем€ заполнени€ вектора " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		cout << lengths[i] << " уникальными случайными числами: "
			<< averageFillingTime(generateRandomVector, lengths[i]) << "сек." << endl;
	}
	cout << endl;
}

void searchInTree(SearchTree& tree) {
	cout << "—реднее врем€ поиска случайного числа в заполненном дереве из " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		tree = generateRandomTree(lengths[i]);
		cout << lengths[i] << " элементов: " << averageTimeSearchInTree(tree) << "сек." << endl;
		tree.clear();
	}
	cout << endl;
}

void searchInVector(vector<int>& arr) {
	cout << "—реднее врем€ поиска случайного числа в заполненном векторе из " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		arr = generateRandomVector(lengths[i]);
		cout << lengths[i] << " элементов: " << averageTimeSearchInVector(arr) << "сек." << endl;
		arr.clear();
	}
	cout << endl;
}

void insertInTree(SearchTree& tree) {
	cout << "—реднее врем€ добавлени€ случайного числа дл€ заполненного дерева из " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		tree = generateRandomTree(lengths[i]);
		cout << lengths[i] << " элементов: " << averageTimeInsertTree(tree) << "сек." << endl;
		tree.clear();
	}
	cout << endl;
}

void insertInVector(vector<int>& arr) {
	cout << "—реднее врем€ добавлени€ случайного числа дл€ заполненного вектора из " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		arr = generateRandomVector(lengths[i]);
		cout << lengths[i] << " элементов: " << averageTimeInsertVector(arr) << "сек." << endl;
		arr.clear();
	}
	cout << endl;
}

void eraseInTree(SearchTree& tree) {
	cout << "—реднее врем€ удалени€ случайного числа дл€ заполненного дерева из " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		tree = generateRandomTree(lengths[i]);
		cout << lengths[i] << " элементов: " << averageTimeEraseTree(tree) << "сек." << endl;
		tree.clear();
	}
	cout << endl;
}

void eraseInVector(vector<int>& arr) {
	cout << "—реднее врем€ удалени€ случайного числа дл€ заполненного вектора из " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		arr = generateRandomVector(lengths[i]);
		cout << lengths[i] << " элементов: " << averageTimeEraseVector(arr) << "сек." << endl;
		arr.clear();
	}
	cout << endl;
}