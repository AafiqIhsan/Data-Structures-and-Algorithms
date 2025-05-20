// Programmer: Dibbya (Aafiq Ihsan)
// Date: May 13, 2025
// The avl.hpp file contains the templated class definition for the AVL<T> class
// It defines the class data and methods for an AVL Tree Data Structure

#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include "node.hpp"

template <typename T>
class AVL{
    private:
        Node<T>* root; // Pointer to the root node of the tree

        // Private Methods
        // These are dummy methods to help hide data from the user

        // The search() method recursively searches a node from the tree
        // It is similar to the binary search
        // It searches the left subtree if key < node->data
        // It searches the right subtree if key > node->data
        // Pre: The > and < operators should be defined for the T data type
        // Post: The node with the passed key is returned if found
        //      else nullptr is returned
        Node<T>* rSearch(Node<T>* root, T key);

        // The search() method iteratively searches a node from the tree
        // It is similar to the binary search
        // It searches the left subtree if key < node->data
        // It searches the right subtree if key > node->data
        // Pre: The > and < operators should be defined for the T data type
        // Post: The node with the passed key is returned if found
        //      else nullptr is returned
        Node<T>* searchIter(Node<T>* root, T key);

        // The rInsert() method recursively inserts a node into the tree
        // Pre: The >, <, and == operators should be defined for the T data type
        // Post: A new key is inserted into the tree
        Node<T>* rInsert(Node<T>* root, T key);

        // Recursive Display Methods
        // The displayPreorder() function outputs the tree data in preorder
        // Pre: The << operator should be defined for the T data type
        // Post: The tree is outputted
        void displayPreorder(Node<T>* root);

        // The displayInorder() function outputs the tree data in Inorder
        // Pre: The << operator should be defined for the T data type
        // Post: The tree is outputted
        void displayInorder(Node<T>* root);
        
        // The displayPostorder() function outputs the tree data in postorder
        // Pre: The << operator should be defined for the T data type
        // Post: The tree is outputted
        void displayPostorder(Node<T>* root);

        // The displayLevelorder() function outputs the tree data in postorder
        // Pre: The << operator should be defined for the T data type
        // Post: The tree is outputted
        void displayLevelorder(Node<T>* root);
        
        // The nodeCount() function returns the total nodes in the tree
        // Pre: None
        // Post: The node count of the passed root is returned
        int nodeCount(Node<T>* root);

        // The height() function returns the max height of the tree
        // Pre: None
        // Post: The height of the passed root is returned
        int height(Node<T>* root);

        // The max() function returns the node with the maximum value for the passed node
        // Pre: None
        // Post: The node with the maximum value is returned
        Node<T>* max(Node<T>* root); // Uses: Inorder Predecessor for left subtree

        // The min() function returns the node with the minimum value for the passed node
        // Pre: None
        // Post: The node with the minimum value is returned
        Node<T>* min(Node<T>* root); // Uses: Inorder Successor for right subtree

        // The remove() method recursively removes a node from the tree
        // Pre: The == operator should be defined for the T data type
        // Post: The node with the passed key is removed from the tree
        Node<T>* remove(Node<T>* root, T key);

        // The deleteTree() function recursively deletes the left and right subtree
        // and then deletes the node itself
        // Pre: The delete operator should be defined for Node<T>*
        // Post: The tree is deleted and the memory is deallocated
        void deleteTree(Node<T>* root);

        // LLRotation() performs a right rotation on the root node to the right
        // Pre: Assignment operator must be defined for Node<T>*
        // Post: The tree becomes right rotated with a proper balance factor
        Node<T>* LLRotation(Node<T>* root);

        // LRRotation() performs a left rotation on the left subtree
        // then a right rotation on the root node
        // Pre: Assignment operator must be defined for Node<T>*
        // Post: The tree becomes right rotated with a proper balance factor
        Node<T>* LRRotation(Node<T>* root);

        // RLRotation() performs a right rotation on the right subtree
        // then a left rotation on the root node
        // Pre: Assignment operator must be defined for Node<T>*
        // Post: The tree becomes right rotated with a proper balance factor
        Node<T>* RLRotation(Node<T>* root);

        // RRRotation() performs a left rotation on the root node
        // Pre: Assignment operator must be defined for Node<T>*
        // Post: The tree becomes right rotated with a proper balance factor
        Node<T>* RRRotation(Node<T>* root);

        int balanceFactor(Node<T>* root);
    public:
        // Constructors
        // Default Constructor
        // The default constructor sets the root of the tree to nullptr
        // Pre: The assignment operator should be defined for the Node<T>* type
        // Post: The root is set to nullptr
        AVL():root(nullptr){};
        AVL(Node<T>*root):root(root){};
        
        // Destructor
        // The tree destructor deallocates memory for the nodes, left and right Children of the tree
        // The delete operator should be defined for the Node<T> data type
        ~AVL(){deleteTree(this->root);}

        // Accessor/Getter
        // returns the root node pointer of the tree
        // Pre: none
        // Post: Root node pointer is returned
        Node<T>* getRoot(){return this->root;}

        // The insert() function allows the user to insert a node into the tree
        // Pre: None
        // Post: A node is inserted into the tree if it already doesn't exist
        void insert(T key){this->root = rInsert(this->root,key);}

        // The remove() function allows the user to delete a node from the tree
        // Pre: None
        // Post: A node is removed from the tree if it exists
        void remove(T key){this->root = remove(this->root,key);}

        // The search() function searches the key and returns the pointer to the Node with key
        // Pre: None
        // Post: Node pointer to the node with key is returned
        Node<T>* search(T key){return search(this->root,key);}

        // 
        void generatePreorder(std::string preorder);
        int nodeCount(){return nodeCount(this->root);}
        void displayPreorder(){displayPreorder(this->root);}
        void displayInorder(){displayInorder(this->root);}
        void displayPostorder(){displayPostorder(this->root);}
        void displayLevelorder(){displayLevelorder(this->root);}
        void createPreorder(T * arr, int size);
};

#include "avl.cpp"
#endif