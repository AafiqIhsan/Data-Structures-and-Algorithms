#ifndef TRIANGULAR_HPP
#define TRIANGULAR_HPP

#include <iostream>

using namespace std;

template <typename T>
class lowerTriangular : public Matrix<T>{
    public:
        lowerTriangular();
        ~lowerTriangular();
        T get(int i, int j) override;
        void set(T value, int i, int j) override;
        void display() override;
};

template <typename T>
class upperTriangular : public Matrix<T>{
    public:
        upperTriangular();
        ~upperTriangular();
        T get(int i, int j) override;
        void set(T value, int i, int j) override;
        void display() override;
};

#include "triangular.cpp"
#endif