#ifndef TRIBAND_HPP
#define TRIBAND_HPP

#include <iostream>

using namespace std;

// Square Band will be similar but i - j == k/-k instead of 1/-1
template <typename T>
class triBand : public Matrix<T>{
    public:
        triBand();
        ~triBand();
        T get(int i, int j) override;
        void set(T value, int i, int j) override;
        void display() override;
};

#include "triband.cpp"
#endif