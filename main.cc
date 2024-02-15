#include <iostream>
#include <vector>

#include "../include/search_tree.h"
#include "../include/generator.h"
#include "../src/experiment.cc"
#include "../include/task.h"
using namespace std;


int main() {
    auto start = std::chrono::steady_clock::now();
    setlocale(LC_ALL, "rus");
    double tTime = 0.0;
    SearchTree tree1;
    vector<int> vector;

  /*  fillingTree();
    fillingVector();
    searchInTree(tree);
    searchInVector(vector);
    insertInTree(tree);
    insertInVector(vector);
    eraseInTree(tree);
    eraseInVector(vector);*/
    tree1 = generateRandomTree(5);
    tree1.print();
    cout << "\n" << endl;
    SearchTree tree2;
    tree2 = generateRandomTree(5);
    tree2.print();
    cout << "\n" << endl;
    SearchTree tree3 = symmetricDifference(tree1, tree2);

    tree3.print();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    tTime += duration.count();
    cout << tTime;
    return 0;
}