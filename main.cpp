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

// Function definitions under main
void binaryTree();
void avlTree();
void splayTree();

int main() {

    //binaryTree();

    //avlTree();

    splayTree();



    return 0;
}

bool operator > (const MarsWeather &a, const MarsWeather &b) {

    //Use the unique field to determine if the two objects are equal
    return a.getSol() > a.getSol();
}

bool operator < (const MarsWeather &a, const MarsWeather &b) {

    //Use the unique field to determine if the two objects are equal
    return b.getSol() < a.getSol();
}

bool operator == (const MarsWeather &a, const MarsWeather &b) {

    //Use the unique field to determine if the two objects are equal
    return b.getSol() == a.getSol();
}

void binaryTree() {
    /*********************
   *
   *
   * Variables 'n Stuff
   *
   *
   ********************/

    unsigned random_num = chrono::system_clock::now().time_since_epoch().count();
    const int number_tree = 101;
    int depth = 0; // Depth reference to be passed into find method
    vector<int> shuffled_vector;
    vector<MarsWeather> weather_vector;
    getWeather("mars-weather.csv", weather_vector);

    // Testing Binary Tree method
    BinarySearchTree<int> bs_tree;
    BinarySearchTree<int> bs_tree_random;
    BinarySearchTree<MarsWeather> bs_tree_weather;

    // Adding 1 - 100 to Binary Tree
    for (int i = 1; i < number_tree; ++i) {
        bs_tree.add(i);
    }

    // Write to file
    ofstream file_sequence;
    file_sequence.open("../bs_depth.txt");
    if (file_sequence) {
        for (int i = 1; i < number_tree; ++i) {
            bs_tree.find(i, depth);
            file_sequence << bs_tree.getDepth() << endl;
        }
    }
    file_sequence.close();


    /**
     * Random
     */

    // Adding 1 - 100 to vector
    for (int i = 1; i < number_tree; ++i) {
        shuffled_vector.push_back(i);
    }


    shuffle(shuffled_vector.begin(), shuffled_vector.end(), default_random_engine(random_num));

    // Adding vector elements to binary tree
    for (int i = 1; i < number_tree; ++i) {
        bs_tree_random.add(shuffled_vector[i]);
    }

    // Write to file
    ofstream file_random;
    file_random.open("../bs_depth_random.txt");
    if (file_random) {
        for (int i = 1; i < number_tree; ++i) {
            bs_tree_random.find(i, depth);
            file_random << bs_tree_random.getDepth() << endl;
        }
    }
    file_random.close();

    /**
     * Own data type
     */

    for (int i = 0; i < weather_vector.size(); ++i) {
        bs_tree_weather.add(weather_vector[i]);
    }

    // Write to file
    ofstream file_weather;
    file_weather.open("../bs_depth_weather.txt");
    if (file_weather) {
        for (int i = 0; i < weather_vector.size(); ++i ) {

            bs_tree_weather.find(weather_vector[i], depth);
            file_weather << bs_tree_weather.getDepth() << endl;

        }
    }
    file_weather.close();

}

void avlTree() {
    /*********************
 *
 *
 * Variables 'n Stuff
 *
 *
 ********************/

    unsigned random_num = chrono::system_clock::now().time_since_epoch().count();
    const int number_tree = 101;
    int depth = 0; // Depth reference to be passed into find method
    vector<int> shuffled_vector;
    vector<MarsWeather> weather_vector;
    getWeather("mars-weather.csv", weather_vector);

    /**
     * AVL Tree
     */

    // Testing AVL Tree methods
    AVLTree<int> avl_tree;
    AVLTree<int> avl_tree_random;
    AVLTree<MarsWeather> avl_tree_weather;

    // Adding 1 - 100 to AVL Tree
    for (int i = 1; i < number_tree; ++i) {
        avl_tree.add(i);
    }

    // Write to file
    ofstream file_avl_sequence;
    file_avl_sequence.open("../avl_depth.txt");
    if (file_avl_sequence) {
        for (int i = 1; i < number_tree; ++i) {
            avl_tree.find(i, depth);
            file_avl_sequence << avl_tree.getDepth() << endl;
        }
    }
    file_avl_sequence.close();

    // Adding 1 - 100 to vector
    for (int i = 1; i < number_tree; ++i) {
        shuffled_vector.push_back(i);
    }


    shuffle(shuffled_vector.begin(), shuffled_vector.end(), default_random_engine(random_num));

    // Adding vector elements to binary tree
    for (int i = 1; i < number_tree; ++i) {
        avl_tree_random.add(shuffled_vector[i]);
    }

    // Write to file
    ofstream file_avl_random;
    file_avl_random.open("../avl_depth_random.txt");
    if (file_avl_random) {
        for (int i = 1; i < number_tree; ++i) {
            avl_tree_random.find(i, depth);
            file_avl_random << avl_tree_random.getDepth() << endl;
        }
    }
    file_avl_random.close();

    for (int i = 0; i < weather_vector.size(); ++i) {
        avl_tree_weather.add(weather_vector[i]);
    }

    for (int i = 0; i < weather_vector.size(); ++i) {
        avl_tree_weather.find(weather_vector[i], depth);
        cout << avl_tree_weather.getDepth() << endl;
    }

    // Write to file
    ofstream file_weather;
    file_weather.open("../avl_depth_weather.txt");
    if (file_weather) {
        for (int i = 0; i < weather_vector.size(); ++i ) {

            avl_tree_weather.find(weather_vector[i], depth);
            file_weather << avl_tree_weather.getDepth() << endl;

        }
    }
    file_weather.close();
}



void splayTree() {

    unsigned random_num = chrono::system_clock::now().time_since_epoch().count();
    const int number_tree = 101;
    int depth = 0; // Depth reference to be passed into find method
    vector<int> shuffled_vector;
    vector<MarsWeather> weather_vector;
    getWeather("mars-weather.csv", weather_vector);

    /**
     * Splay Tree
     */

    SplayTree<int> sp_tree(false);
    SplayTree<int> sp_tree_random(false);

    for (int i = 1; i < number_tree; ++i) {
        sp_tree.add(i);
    }

    cout << "\n" << sp_tree.find(20, depth) << endl;
    cout << sp_tree.find(53, depth) << endl;
    cout << sp_tree.find(77, depth) << endl;

    // Showing 77 now at the top, returns 0 for depth
    cout << sp_tree.find(77, depth) << endl;

    // Write to file
    ofstream file_sp_sequence;
    file_sp_sequence.open("../sp_depth.txt");
    if (file_sp_sequence) {
        for (int i = 1; i < number_tree; ++i) {
            sp_tree.find(i, depth);
            file_sp_sequence << sp_tree.getDepth() << endl;
        }
    }
    file_sp_sequence.close();

}

