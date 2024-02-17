#include "../include/experiment.h"

using namespace std;
const std::vector<size_t> lengths = { 1000, 10000, 100000 };

void fillingTree() {
	cout << "������� ����� ���������� ������ ������ " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		cout << lengths[i] << " ����������� ���������� �������: "
			<< averageFillingTime(generateRandomTree, lengths[i]) << "���." << endl;
	}
	cout << endl;
}

void fillingVector() {
	cout << "������� ����� ���������� ������� " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		cout << lengths[i] << " ����������� ���������� �������: "
			<< averageFillingTime(generateRandomVector, lengths[i]) << "���." << endl;
	}
	cout << endl;
}

void searchInTree(SearchTree& tree) {
	cout << "������� ����� ������ ���������� ����� � ����������� ������ �� " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		tree = generateRandomTree(lengths[i]);
		cout << lengths[i] << " ���������: " << averageTimeSearchInTree(tree) << "���." << endl;
		tree.clear();
	}
	cout << endl;
}

void searchInVector(vector<int>& arr) {
	cout << "������� ����� ������ ���������� ����� � ����������� ������� �� " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		arr = generateRandomVector(lengths[i]);
		cout << lengths[i] << " ���������: " << averageTimeSearchInVector(arr) << "���." << endl;
		arr.clear();
	}
	cout << endl;
}

void insertInTree(SearchTree& tree) {
	cout << "������� ����� ���������� ���������� ����� ��� ������������ ������ �� " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		tree = generateRandomTree(lengths[i]);
		cout << lengths[i] << " ���������: " << averageTimeInsertTree(tree) << "���." << endl;
		tree.clear();
	}
	cout << endl;
}

void insertInVector(vector<int>& arr) {
	cout << "������� ����� ���������� ���������� ����� ��� ������������ ������� �� " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		arr = generateRandomVector(lengths[i]);
		cout << lengths[i] << " ���������: " << averageTimeInsertVector(arr) << "���." << endl;
		arr.clear();
	}
	cout << endl;
}

void eraseInTree(SearchTree& tree) {
	cout << "������� ����� �������� ���������� ����� ��� ������������ ������ �� " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		tree = generateRandomTree(lengths[i]);
		cout << lengths[i] << " ���������: " << averageTimeEraseTree(tree) << "���." << endl;
		tree.clear();
	}
	cout << endl;
}

void eraseInVector(vector<int>& arr) {
	cout << "������� ����� �������� ���������� ����� ��� ������������ ������� �� " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		arr = generateRandomVector(lengths[i]);
		cout << lengths[i] << " ���������: " << averageTimeEraseVector(arr) << "���." << endl;
		arr.clear();
	}
	cout << endl;
}