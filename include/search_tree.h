#ifndef LAB_4_INCLUDE_SEARCHTREE_H
#define LAB_4_INCLUDE_SEARCHTREE_H

#include <iostream>
#include <stack>

class SearchTree {
private:
	struct Node {
		int key;
		Node* left, * right;

		Node(int key, Node* left = nullptr, Node* right = nullptr) : key(key), left(left), right(right) {}
	};
	Node* _root;
	size_t _size;

	Node* copy_tree_helper(Node* origNode);

	Node* insert_helper(Node** currentRoot, const int& key);

	Node* clear(Node* currentRoot);

	void print_helper(Node* root, int spaces) const;

	bool contains_helper(Node* root, const int& key) const;

	bool inequality_operator(Node* first_node, Node* second_node);

	bool operator!=(const SearchTree& other);

	Node* find_min(Node* root);

	Node* erase_helper(Node** root, const int& key);

public:

	class Iterator {
		Node* current;

		friend class SearchTree;
	public:
		Iterator(Node* root): current(root){}

		int operator*();

		Iterator& operator++();

		bool operator==(const SearchTree& other) const;

		bool operator!=(const SearchTree& other) const;
	};

	SearchTree();

	SearchTree(const int& key, size_t size);

	SearchTree(const SearchTree& other);

	~SearchTree();

	SearchTree& operator=(const SearchTree& other);

	bool insert(const int& key);

	bool contains(const int& key) const;

	void print() const;

	size_t get_size() const;

	void clear();

	bool erase(const int& key);

};

#endif
