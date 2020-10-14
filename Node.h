//
// Created by Lisa Dion on 9/11/20.
//

#ifndef LINKEDLISTA_NODE_H
#define LINKEDLISTA_NODE_H

/** Represents one node to be used in a linked list
    Contains data (object) and reference to next in list
*/

template<typename Object>
class Node {
private:
    Object item;
    // Store a pointer to the next Node
    // Pointers are data types that store references (memory addresses)
    // Use an asterisk * to declare a pointer
    Node* next;


public:
    /** Create new node with specified data
        Have it reference null
        @param newItem is data to added to new node
    */
    Node(Object newItem) {
        item = newItem;
        next = nullptr;
    }

    /** Create new node with specified data
        Have it reference nextNode
        @param newItem is data to added to new node
        @param nextNode is reference that new Node's next will hold

    */
    Node(Object newItem, Node* nextNode) {
        item = newItem;
        next = nextNode;
    }
    /** set data field (item) of Node
        @param newItem, to set item field to
    */
    void setItem(Object newItem) {
        item = newItem;
    } // end setItem

    /** get data field (item) of Node
        @return item field
    */
    Object getItem() const {
        return item;
    }

    /** set next field  of Node
        @param nextNode, to set next field to
    */
    void setNext(Node* nextNode) {
        next = nextNode;
    }

    /** get next field  Node
        @return next field
    */
    Node* getNext() const {
        return next;
    }
};


#endif //LINKEDLISTA_NODE_H
