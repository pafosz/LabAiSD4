#include <iostream>
#include <vector>

#include "../include/search_tree.h"
#include "../include/generator.h"
using namespace std;


int main() {
    
    SearchTree tree;
    /*tree1.insert(10);
    tree1.insert(8);
    tree1.insert(15);
    tree1.insert(26);
    tree1.insert(7);
    tree1.insert(9);
    tree1.insert(12);
    tree1.insert(22);
    tree1.insert(20);
    tree1.insert(6);
    tree1.insert(20);
    tree1.insert(18);
    tree1.insert(21);
    tree1.insert(32);
    tree1.print();
    cout << endl;*/
    tree = generateRandomTree(10);
    tree.print();
    
    
    return 0;
}