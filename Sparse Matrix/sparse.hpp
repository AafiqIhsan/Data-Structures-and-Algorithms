#ifndef SPARSE_HPP
#define SPARSE_HPP

#include <iostream>
#include "element.hpp"

using namespace std;

template <typename T>
class Sparse{
    private:
        int rows;
        int cols;
        int nonZero;
        Element<T> * e;

    public:
        Sparse();
        Sparse(Sparse const& cpy);
        Sparse(int const& rows, int const& cols, int const& nonZero);
        Sparse(int const& rows, int const& cols, int const& nonZero, Element<T> const* e);
        ~Sparse();

        Sparse<T>& add(Sparse<T> const& other);
        void display();

        template <typename U>
        friend ostream& operator<<(ostream& out, Sparse<U> const& mat);
};

#include "sparse.cpp"
#endif