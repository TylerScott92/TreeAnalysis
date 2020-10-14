#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "Node.h"
#include "SplayTree.h"
#include "Weather.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main() {

    unsigned random_num = chrono::system_clock::now().time_since_epoch().count();
    const int number_tree = 101;
    vector<int> numbers_vector;
    vector<MarsWeather> weather;
    getWeather("mars-weather.csv", weather);

    // Testing Binary Tree method
    BinarySearchTree<int>(BinarySearchTree);

    // Adding 1 - 100 to Binary Tree
    for (int i = 1; i < number_tree; ++i) {
        BinarySearchTree.add(i);
    }

    // Adding 1 - 100 to vector
    for (int i = 0; i < number_tree; ++i) {
        numbers_vector.push_back(i);
    }

    // Testing if all values in tree
    //for (int i = 0; i < number_tree; ++i) {
    //    cout << BinarySearchTree.find(i) << endl;
    //}

    //shuffle(numbers_vector.front(), numbers_vector.back(), default_random_engine(random_num));

    // Printing shuffled vector
    //for (int i = 0; i < number_tree; ++i) {
    //    cout << numbers_vector[i] << endl;
    //}

    cout << "\n";




    // Test to find depth of Node, should just be same as content
    // Linear line along right side of tree (always adding larger number from loop population).
    cout << BinarySearchTree.find(20, 0) << endl;

    // Testing AVL Tree methods
    AVLTree<int>(AVLTree);

    // Adding 1 - 100 to AVL Tree
    for (int i = 0; i < number_tree; ++i) {
        AVLTree.add(i);
    }

    // Test to find depth of Node, debug has 20 at depth of 6
    cout << AVLTree.find(20, 0) << endl;


    //SplayTree<int>(SplayTree);









    return 0;
}
