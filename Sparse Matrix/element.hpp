#ifndef ELEMENT_HPP
#define ELEMENT_HPP

template <typename T>
class Element{
    private:
        int i;
        int j;
        T value;
    public:
        // Accessors
        int geti(){return i;}
        int getj(){return j;}
        T getVal(){return value;}
        
        // Mutators
        void seti(int i){this->i = i;}
        void setj(int j){this->j = j;}
        void setVal(int value){this->value = value;}
};

#include "sparse.hpp"
#endif