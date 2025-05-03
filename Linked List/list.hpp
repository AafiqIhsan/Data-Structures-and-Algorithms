#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "node.hpp"

using namespace std;

template <typename T>
class LList{
    private:
        Node<T>* first;
    public:
        LList();
        LList(LList<T>& cpy);
        ~LList();

        void display(Node<T>* ptr);
        void show(int index);
        int count();
        T sum();
        T max();
        T min();
        int Search(T data);
        void insert(T data, int index);
        void append(T data);
        void remove(int index);

        /*
        bool isSorted();
        T& reverse();
        T& concat(LList<T> const& other);
        T& merge(LList<T> const& other);
        */
       
        template <typename U>
        friend ostream& operator << (ostream& out, LList<U>& l);
};

#include "list.cpp"
#endif