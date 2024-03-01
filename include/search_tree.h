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

	Node* copy_tree_helper(Node*);

	Node* insert_helper(Node**, const int&);

	Node* clear_helper(Node*);

	void print_helper(Node*) const; // выводит дерево от меньшего к большему (обход ЛКП)

	void print_tree_helper(Node*, int = 0) const; // выводит дерево в виде дерева :)

	bool contains_helper(Node*, const int&) const;

	bool inequality_operator(Node*, Node*);

	bool operator!=(const SearchTree&);

	Node* find_min_helper(Node*);

	Node* erase_helper(Node**, const int&);

public:

	class Iterator {
		std::stack<Node*> tree;
		Node* current;
	public:
		Iterator(Node* root);

		int operator*();

		void operator++();

		bool operator==(const Iterator&);

		bool operator!=(const Iterator&);
	};
	

	SearchTree();

	SearchTree(const int&, size_t = 1);

	SearchTree(const SearchTree&);

	~SearchTree();

	SearchTree& operator=(const SearchTree&);

	bool insert(const int&);

	bool contains(const int&) const;

	Node* find_min();

	void print() const;

	void print_tree() const;

	size_t get_size() const;

	void clear();

	bool erase(const int&);

	Iterator begin();

	Iterator end();
};

#endif
