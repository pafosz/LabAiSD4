#include <iostream>
#include <vector>

#include "../include/search_tree.h"
#include "../include/generator.h"
#include "../src/experiments.cc"
#include "../include/task.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");

    SearchTree tree;
    std::vector<int> vector;

    fillingTree();
    fillingVector();
    searchInTree(tree);
    searchInVector(vector);
    insertInTree(tree);
    insertInVector(vector);
    eraseInTree(tree);
    eraseInVector(vector);

    cout << endl;

    SearchTree tree1(20);
    tree1.insert(15);
    tree1.insert(25);
    tree1.insert(18);
    tree1.insert(42);
    tree1.insert(7);
    tree1.insert(4);
    tree1.print();
    
    cout << endl;

    SearchTree tree2(40);
    tree2.insert(23);
    tree2.insert(32);
    tree2.insert(42);
    tree2.insert(15);
    tree2.insert(7);
    tree2.insert(25);
    tree2.print();
    
    cout << endl;

    SearchTree combTree = combining(tree, tree2);
    combTree.print();

    cout << endl;

    SearchTree symDifTree = symmetricDifference(tree, tree2);
    symDifTree.print();

    cout << endl;
   
    return 0;
}