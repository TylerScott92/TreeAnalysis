#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "Node.h"
#include "SplayTree.h"
#include "Weather.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main() {

    unsigned random_num = chrono::system_clock::now().time_since_epoch().count();
    const int number_tree = 101;
    vector<int> shuffled_vector;
    vector<MarsWeather> weather_vector;
    getWeather("mars-weather.csv", weather_vector);

    /**
     * Binary Tree
     */
    // Testing Binary Tree method
    BinarySearchTree<int> bs_tree;
    BinarySearchTree<int> bs_tree_random;
    BinarySearchTree<MarsWeather> bs_tree_weather;

    // Adding 1 - 100 to Binary Tree
    for (int i = 1; i < number_tree; ++i) {
        bs_tree.add(i);
    }

    // Test to find depth of Node, should just be same as content
    // Linear line along right side of tree (always adding larger number from loop population).
    //cout << bs_tree.find(20, 0) << endl;
    //cout << bs_tree.find(64, 0) << endl;

    //Need to get depth for null values still
    //cout << bs_tree.find(105, 0) << endl;

    // Adding 1 - 100 to vector
    for (int i = 1; i < number_tree; ++i) {
        shuffled_vector.push_back(i);
    }


    shuffle(shuffled_vector.begin(), shuffled_vector.end(), default_random_engine(random_num));

    // Adding vector elements to binary tree
    for (int i = 1; i < number_tree; ++i) {
        bs_tree_random.add(shuffled_vector[i]);
    }

    cout << bs_tree_random.find(5, 0);
    cout << bs_tree_random.find(22, 0);
    cout << bs_tree_random.find(102, 0);

    /**
     *
     *
     * NEED TO OVERLOAD OPERATORS TO MAKE COMPARISONS WITH OWN DATA TYPE
     *
     *
     */
    // Using own data type
    for (int i = 0; i < weather_vector.size(); ++i) {
        bs_tree_weather.add(weather_vector[i]);
    }




    /**
     * AVL Tree
     */
    // Testing AVL Tree methods
    AVLTree<int> avl_tree;

    // Adding 1 - 100 to AVL Tree
    for (int i = 1; i < number_tree; ++i) {
        avl_tree.add(i);
    }

    // Test to find depth of Node, debug has 20 at depth of 6
    cout << avl_tree.find(20, 0) << endl;
    cout << avl_tree.find(53, 0) << endl;
    cout << avl_tree.find(77, 0) << endl;


    /**
     * Splay Tree
     */

    SplayTree<int> sp_tree(false);

    for (int i = 1; i < number_tree; ++i) {
        sp_tree.add(i);
    }

    // IDK about splay tree yet lol
    //cout << "\n" << sp_tree.find(20, 0) << endl;
    //cout << sp_tree.find(53,0) << endl;
    //cout << sp_tree.find(77,0) << endl;

    // Write to file example
    //ofstream file_out;
    //file_out.open("../exampleFile.txt");
    //if (file_out) {
    //    for (int i = 0; i < 100; ++i) {
    //        file_out << i << endl;
    //    }
    //}
    //file_out.close();

    return 0;
}
