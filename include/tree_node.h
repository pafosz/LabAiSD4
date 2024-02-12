#pragma once
#include <iostream>

struct Node {
	int key;
	Node* left, * right;

	Node(int key, Node* left = nullptr, Node* right = nullptr) : key(key), left(left), right(right) {}
};