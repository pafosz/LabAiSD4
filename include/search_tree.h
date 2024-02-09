#pragma once

#include <iostream>

struct Node {
	int key;
	Node* left, * right;

	Node(int key, Node* left = nullptr, Node* rigth = nullptr): key(key), left(left), right(right){}
	
};

class SearchTree {
	Node* _root;
	size_t _size;

	Node* copy_tree_helper(Node* origNode) {
		if (!origNode)
			return nullptr;
		Node* newNode = new Node(origNode->key);
		newNode->left = copy_tree_helper(origNode->left);
		newNode->right = copy_tree_helper(origNode->right);

		return newNode;
	}

	Node* insert_helper(Node* currentRoot, int key) {
		if (!currentRoot) 
			return new Node(key);
		
		if (key < currentRoot->key)
			currentRoot->left = insert_helper(currentRoot->left, key);

		else if (key > currentRoot->key)
			currentRoot->right = insert_helper(currentRoot->right, key);

		else
			return currentRoot;
	}

	Node* clear(Node* currentRoot) {
		if (!_root)	return nullptr;

		currentRoot->left = clear(currentRoot->left);
		currentRoot->right = clear(currentRoot->right);

		delete currentRoot;
		_size = 0;
	}

	bool inequality_operator(Node* first_node, Node* second_node) {
		if (!first_node && !second_node) return false;
		if (!first_node || !second_node) return true;
		if (first_node->key != second_node->key) return true;
		return inequality_operator(first_node->left, second_node->left)
			|| inequality_operator(first_node->right, second_node->right);
	}
	
	void print_helper(Node* root, int tabs = 0) {
		if (!root) return;
		tabs += 5;

		print_helper(root->left, tabs);
		for (int i = 0; i < tabs; i++) std::cout << " ";
		std::cout << root->key << std::endl;

		print_helper(root->right, tabs);
		tabs -= 5;
		return;
	}

public:
	SearchTree() : _root(nullptr), _size(0){}

	SearchTree(int key){
		_root = new Node(key);
		_size++;
	}
	SearchTree(const SearchTree& other) : SearchTree() {
		_root = copy_tree_helper(other._root);
		_size = other._size;
	}
	~SearchTree() {
		clear(_root);
	}
	SearchTree& operator=(const SearchTree& other) {
		if (this != &other) {
			clear(_root);
			_root = copy_tree_helper(other._root);
			_size = other._size;
		}
		return *this;
	}
	bool insert(int key) {
		insert_helper(_root, key);
		_size++;
		return true;
	}

	void print() {
		print_helper(_root);
	}
	
	bool operator!=(const SearchTree& other) {
		return inequality_operator(_root, other._root);
	}

};

