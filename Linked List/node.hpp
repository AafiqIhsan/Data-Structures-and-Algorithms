#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

using namespace std;

template <typename T>
class LList;

template <typename T>
class Node{
    private:
        T data;
        Node *next;
        friend LList<T>;
    public:
        Node(T data, Node<T>* next){
            this->data = data;
            this->next = next;
        }
        ~Node(){
            delete next;
        }
};

#include "list.hpp"
#endif