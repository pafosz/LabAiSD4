#pragma once

#include <iostream>

struct Node {
	int key;
	Node* left, * right;

	Node(int key, Node* left = nullptr, Node* right = nullptr): key(key), left(left), right(right){}
	
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

	Node* insert_helper(Node** currentRoot, const int& key) {
		if (*currentRoot == nullptr) 
			return new Node(key);
		
		if (key < (*currentRoot)->key)
			(*currentRoot)->left = insert_helper(&((*currentRoot)->left), key);

		else if (key > (*currentRoot)->key)
			(*currentRoot)->right = insert_helper(&((*currentRoot)->right), key);

		else
			return (*currentRoot);
	}

	Node* clear(Node* currentRoot) {
		if (!currentRoot) return nullptr;

		currentRoot->left = clear(currentRoot->left);
		currentRoot->right = clear(currentRoot->right);

		delete currentRoot;
		_size = 0;
		_root = nullptr;
	}

	void print_helper(Node* root, int spaces = 0) const
	{
		if (!root) return;
		while (root)
		{
			print_helper(root->right, spaces + 5);

			for (int i = 1; i < spaces; ++i)
				std::cout << ' ';

			std::cout << root->key << std::endl;

			root = root->left;
			spaces += 5;
		}
	}

	bool contains_helper(Node* root, const int& key) {
		if (!root) return false;

		if (key == root->key) return true;

		else if (key < root->key) contains_helper(root->left, key);
		else contains_helper(root->right, key);
	}

	bool inequality_operator(Node* first_node, Node* second_node) {
		if (!first_node && !second_node) return false;
		if (!first_node || !second_node) return true;
		if (first_node->key != second_node->key) return true;
		return inequality_operator(first_node->left, second_node->left)
			|| inequality_operator(first_node->right, second_node->right);
	}

	bool operator!=(const SearchTree& other) {
		return inequality_operator(_root, other._root);
	}

	bool erase_helper(Node** root, const int& key) {
		if (!root) return false;
		if (key == (*root)->key) {
			Node* removable = *root;
			if (!(*root)->left && !(*root)->right) {
				*root = nullptr;
				delete removable;
				return true;
			}
			else if (!(*root)->left) {
				*root = (*root)->right;
				delete removable;
				return true;
			}
			else if (!(*root)->right) {
				*root = (*root)->left;
				delete removable;
				return true;
			}
			else if((*root)->left && (*root)->right){
				Node* tmp = removable;
				Node* replaceable = (*root)->left;
				while (replaceable->right) {
					tmp = replaceable;
					replaceable = replaceable->right;
				}
				replaceable->right = removable->right;
				if (replaceable->left && replaceable->right) {					
					tmp->right = replaceable->left;
					replaceable->left = removable->left;
				}
				else {
					tmp->left = nullptr;					
				}
				
				*root = replaceable;							
				
				delete removable;
				replaceable = nullptr;
				return true;
			}
		}
		else
		{
			if ((*root)->key > key)
				erase_helper(&((*root)->left), key);
			else
			{
				if ((*root)->key < key)
					erase_helper(&((*root)->right), key);
			}
		}
	}

public:
	SearchTree() : _root(nullptr), _size(0){}

	SearchTree(int key, size_t size = 1) {
		_root = new Node(key);		
		_size = size;
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
		_root = insert_helper(&_root, key);
		_size++;
		return true;
	}

	bool contains(int key) {
		return contains_helper(_root, key);
	}

	void print(){
		print_helper(_root);
	}	

	size_t get_size() const {
		return _size;
	}

	void clear() {
		clear(_root);
	}

	bool erase(const int& key) {
		return erase_helper(&_root, key);
	}

};

