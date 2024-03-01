#include <vector>
#include "../include/task.h"

SearchTree combining(SearchTree& first_tree, SearchTree& second_tree) {
	SearchTree res_tree;
	for (auto node : first_tree) {
		res_tree.insert(node);
	}
	for (auto node : second_tree) {
		res_tree.insert(node);
	}
	return res_tree;
}

SearchTree difference(SearchTree& first_tree, SearchTree& second_tree) {
	SearchTree res_tree = first_tree;
	for (auto node : second_tree) {
		res_tree.erase(node);
	}
	return res_tree;
}

SearchTree symmetricDifference(SearchTree& first_tree, SearchTree& second_tree) {
	SearchTree dif1 = difference(first_tree, second_tree);
	SearchTree dif2 = difference(second_tree, first_tree);
	return combining(dif1, dif2);
}