#include "../include/search_tree.h"

SearchTree::Node* SearchTree::copy_tree_helper(Node* origNode) {
	if (!origNode)
		return nullptr;
	Node* newNode = new Node(origNode->key);
	newNode->left = copy_tree_helper(origNode->left);
	newNode->right = copy_tree_helper(origNode->right);

	return newNode;
}

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

SearchTree::Node* SearchTree::clear(Node* root) {
	if (!root) return nullptr;

	root->left = clear(root->left);
	root->right = clear(root->right);

	delete root;
	_size = 0;
	_root = nullptr;
	return _root;
}

void SearchTree::print_helper(Node* root, int spaces = 0) const {
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

bool SearchTree::contains_helper(Node* root, const int& key) const {
	if (!root) return false;

	if (key == root->key) return true;

	else if (key < root->key) {
		contains_helper(root->left, key);		
	}
	else if (key > root->key) {
		contains_helper(root->right, key);		
	}
	else return false;
}

bool SearchTree::inequality_operator(Node* first_node, Node* second_node) {
	if (!first_node && !second_node) return false;
	if (!first_node || !second_node) return true;
	if (first_node->key != second_node->key) return true;
	return inequality_operator(first_node->left, second_node->left)
		|| inequality_operator(first_node->right, second_node->right);
}

bool SearchTree::operator!=(const SearchTree& other) {
	return inequality_operator(_root, other._root);
}

SearchTree::Node* SearchTree::find_min(Node* root) {
	Node* current = root;
	while (current && current->left) {
		current = current->left;
	}
	return current;
}

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
			Node* tmp = find_min((*root)->right);
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


//public:
int SearchTree::Iterator::operator*() {
	return current->key;
}

SearchTree::Iterator& SearchTree::Iterator::operator++() {
	
}

SearchTree::SearchTree() : _root(nullptr), _size(0) {}

SearchTree::SearchTree(const int& key, size_t size = 1) {
	_root = new Node(key);
	_size = size;
}

SearchTree::SearchTree(const SearchTree& other) : SearchTree() {
	_root = copy_tree_helper(other._root);
	_size = other._size;
}

SearchTree::~SearchTree() {
	clear(_root);
}

SearchTree& SearchTree::operator=(const SearchTree& other) {
	if (this != &other) {
		clear(_root);
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

void SearchTree::print() const {
	print_helper(_root);
}

size_t SearchTree::get_size() const {
	return _size;
}

void SearchTree::clear() {
	clear(_root);
}

bool SearchTree::erase(const int& key) {
	if (!contains(key)) return false;
	_root = erase_helper(&_root, key);
	--_size;
	return true;
}