#include "../include/search_tree.h"

//================================================================================================
//                                           private
//================================================================================================
// 
//Рекурсивный помощник копирования дерева

SearchTree::Node* SearchTree::copy_tree_helper(Node* origNode) {
	if (!origNode)
		return nullptr;
	Node* newNode = new Node(origNode->key);
	newNode->left = copy_tree_helper(origNode->left);
	newNode->right = copy_tree_helper(origNode->right);

	return newNode;
}

//Рекурсивный помощник добавления элемента в дерево

SearchTree::Node* SearchTree::insert_helper(Node** currentRoot, const int& key) {
	if (*currentRoot == nullptr)
		return new Node(key);

	if (key < (*currentRoot)->key)
		(*currentRoot)->left = insert_helper(&((*currentRoot)->left), key);

	else if (key > (*currentRoot)->key)
		(*currentRoot)->right = insert_helper(&((*currentRoot)->right), key);

	else
		return (*currentRoot);

	return (*currentRoot);
}

//Рекурсивный помощник удаления дерева

SearchTree::Node* SearchTree::clear_helper(Node* root) {
	if (!root) return nullptr;

	root->left = clear_helper(root->left);
	root->right = clear_helper(root->right);

	delete root;
	_size = 0;
	_root = nullptr;
	return _root;
}

//Рекурсивный помощник вывода дерева в виде строки

void SearchTree::print_helper(Node* root) const {
	if (!root) return;
	
	print_helper(root->left);
	std::cout << root->key << " ";
	print_helper(root->right);
}

//Рекурсивный помощник вывода дерева в виде дерева

void SearchTree::print_tree_helper(Node* root, int spaces) const {
	if (!root) return;
	
	while (root)
	{
		print_tree_helper(root->right, spaces + 5);

		for (int i = 1; i < spaces; ++i)
			std::cout << ' ';

		std::cout << root->key << std::endl;

		root = root->left;
		spaces += 5;
	}
}

//Рекурсивный помощник нахождения минимального элемента

SearchTree::Node* SearchTree::find_min_helper(Node* root) {
	Node* current = root;
	while (current && current->left) {
		current = current->left;
	}
	return current;
}

//Рекурсивный помощник нахождения элемента в дереве

bool SearchTree::contains_helper(Node* root, const int& key) const {
	if (!root) return false;

	if (key == root->key) return true;

	if (key < root->key) {
		return contains_helper(root->left, key);
	}
	
	return contains_helper(root->right, key);
}

//Рекурсивный помощник сравнения узлов на неравенство

bool SearchTree::inequality_operator(Node* first_node, Node* second_node) {
	if (!first_node && !second_node) return false;
	if (!first_node || !second_node) return true;
	if (first_node->key != second_node->key) return true;
	return inequality_operator(first_node->left, second_node->left)
		|| inequality_operator(first_node->right, second_node->right);
}

//Сравнение узлов

bool SearchTree::operator!=(const SearchTree& other) {
	return inequality_operator(_root, other._root);
}

//Рекурсивный помощник удаления элемента из дерева

SearchTree::Node* SearchTree::erase_helper(Node** root, const int& key) {
	if (!root) return nullptr;
	if (key == (*root)->key) {
		Node* removable = *root;
		if (!(*root)->left && !(*root)->right) {
			*root = nullptr;
			delete removable;
		}
		else if (!(*root)->left) {
			*root = (*root)->right;
			delete removable;
		}
		else if (!(*root)->right) {
			*root = (*root)->left;
			delete removable;
		}
		else if ((*root)->left && (*root)->right) {
			Node* tmp = find_min_helper((*root)->right);
			(*root)->key = tmp->key;
			(*root)->right = erase_helper(&(*root)->right, tmp->key);
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
	return *root;
}

//================================================================================================
//                                           public
//================================================================================================

SearchTree::Iterator::Iterator(Node* root) {
	current = root;
	while (current != nullptr) {
		tree.push(current);
		current = current->left;
	}
}

int SearchTree::Iterator::operator*() {
	return tree.top()->key;
}

void SearchTree::Iterator::operator++() {
	Node* top_node = tree.top();
	tree.pop();
	if (top_node->right) {
		current = top_node->right;
		while (current) {
			tree.push(current);
			current = current->left;
		}
	}
}

bool SearchTree::Iterator::operator==(const Iterator& other) {
	return tree == other.tree;
}

bool SearchTree::Iterator::operator!=(const Iterator& other) {
	return !tree.empty() || !other.tree.empty();
}

SearchTree::SearchTree() : _root(nullptr), _size(0) {}

SearchTree::SearchTree(const int& key, size_t size) {
	_root = new Node(key);
	_size = size;
}

SearchTree::SearchTree(const SearchTree& other) : SearchTree() {
	_root = copy_tree_helper(other._root);
	_size = other._size;
}

SearchTree::~SearchTree() {
	clear();
}

SearchTree& SearchTree::operator=(const SearchTree& other) {
	if (this != &other) {
		clear();
		_root = copy_tree_helper(other._root);
		_size = other._size;
	}
	return *this;
}

bool SearchTree::insert(const int& key) {
	if (contains(key)) return false;
	_root = insert_helper(&_root, key);
	++_size;
	return true;
}

bool SearchTree::contains(const int& key) const {
	return contains_helper(_root, key);
}

SearchTree::Node* SearchTree::find_min() {
	return find_min_helper(_root);
}

void SearchTree::print() const {	
	return print_helper(_root);
}

void SearchTree::print_tree() const {
	print_tree_helper(_root);
}

size_t SearchTree::get_size() const {
	return _size;
}

void SearchTree::clear() {
	clear_helper(_root);
}

bool SearchTree::erase(const int& key) {
	if (!contains(key)) return false;
	_root = erase_helper(&_root, key);
	--_size;
	return true;
}

SearchTree::Iterator SearchTree::begin() { 	return Iterator(_root); }

SearchTree::Iterator SearchTree::end() { return Iterator(nullptr); }