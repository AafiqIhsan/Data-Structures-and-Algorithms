#ifndef MATRIX_HPP
#define MATRIX_HPP

template <typename T>
class Matrix{
    protected:
        T* A;
        int size;
        int n;
    public:
        Matrix(){}
        virtual ~Matrix(){}

        virtual T get(int i, int j) = 0;
        virtual void set(T value, int i, int j) = 0;
        virtual void display() = 0;
};

#include "triangular.hpp"
#include "triband.hpp"

#endif