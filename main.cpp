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

    /**
     * Random Search
     */

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

    /**
     * Own Type
     */

    for (int i = 0; i < weather_vector.size(); ++i) {
        avl_tree_weather.add(weather_vector[i]);
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
    vector<MarsWeather> shuffled_weather_vector;
    vector<MarsWeather> weather_vector;
    getWeather("mars-weather.csv", weather_vector);

    /**
     * Splay Tree
     */

    SplayTree<int> sp_tree(false);
    SplayTree<int> sp_tree_random(false);

    // Own Type
    SplayTree<MarsWeather> sp_tree_weather_false_one(false);
    SplayTree<MarsWeather> sp_tree_weather_false_two(false);
    SplayTree<MarsWeather> sp_tree_weather_true_one(true);
    SplayTree<MarsWeather> sp_tree_weather_true_two(true);

    for (int i = 1; i < number_tree; ++i) {
        sp_tree.add(i);
    }

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


    /**
     * Random
     */

    // Adding 1 - 100 to vector
    for (int i = 1; i < number_tree; ++i) {
        shuffled_vector.push_back(i);
    }

    shuffle(shuffled_vector.begin(), shuffled_vector.end(), default_random_engine(random_num));

    for (int i = 1; i < number_tree; ++i) {
        sp_tree_random.add(i);
    }

    // Write to file, uses vector of random numbers to search randomly
    ofstream file_sp_random;
    file_sp_random.open("../sp_depth_random.txt");
    if (file_sp_random) {
        for (int i = 1; i < number_tree; ++i) {
            sp_tree_random.find(shuffled_vector[i], depth);
            file_sp_random << sp_tree_random.getDepth() << endl;
        }
    }
    file_sp_random.close();

    /**
     * Own Type
     *
     */


    // For Sequential Searches
    for (int i = 0; i < weather_vector.size(); ++i) {
        sp_tree_weather_false_one.add(weather_vector[i]);
    }

    // Write to file
    ofstream file_weather_false_one;
    file_weather_false_one.open("../sp_depth_weather_sequential_false.txt");
    if (file_weather_false_one) {
        for (int i = 0; i < weather_vector.size(); ++i ) {

            sp_tree_weather_false_one.find(weather_vector[i], depth);
            file_weather_false_one << sp_tree_weather_false_one.getDepth() << endl;

        }
    }
    file_weather_false_one.close();

    for (int i = 0; i < weather_vector.size(); ++i) {
        sp_tree_weather_true_one.add(weather_vector[i]);
    }

    // Write to file
    ofstream file_weather_true_one;
    file_weather_true_one.open("../sp_depth_weather_sequential_true.txt");
    if (file_weather_true_one) {
        for (int i = 0; i < weather_vector.size(); ++i ) {

            sp_tree_weather_true_one.find(weather_vector[i], depth);
            file_weather_true_one << sp_tree_weather_true_one.getDepth() << endl;

        }
    }
    file_weather_true_one.close();



    /**
     *
     *
     * Weather Random
     *
     *
     */

    // For Random Searches

    for (int i = 0; i < weather_vector.size(); ++i) {
        sp_tree_weather_false_two.add(weather_vector[i]);
    }

    // Adding 1 - 100 to vector
    for (int i = 1; i < weather_vector.size(); ++i) {
        shuffled_weather_vector.push_back(weather_vector[i]);
    }

    shuffle(shuffled_weather_vector.begin(), shuffled_weather_vector.end(), default_random_engine(random_num));


    // Write to file
    ofstream file_weather_false_two;
    file_weather_false_two.open("../sp_depth_weather_random_false.txt");
    if (file_weather_false_two) {
        for (int i = 0; i < weather_vector.size(); ++i ) {

            sp_tree_weather_false_two.find(shuffled_weather_vector[i], depth);
            file_weather_false_two << sp_tree_weather_false_two.getDepth() << endl;

        }
    }
    file_weather_false_two.close();

    for (int i = 0; i < weather_vector.size(); ++i) {
        sp_tree_weather_true_two.add(weather_vector[i]);
    }

    // Write to file
    ofstream file_weather_true_two;
    file_weather_true_two.open("../sp_depth_weather_random_true.txt");
    if (file_weather_true_two) {
        for (int i = 0; i < weather_vector.size(); ++i ) {

            sp_tree_weather_true_two.find(shuffled_weather_vector[i], depth);
            file_weather_true_two << sp_tree_weather_true_two.getDepth() << endl;

        }
    }
    file_weather_true_two.close();



}

