#ifndef DIAGONAL_HPP
#define DIAGONAL_HPP

#include <iostream>

using namespace std;

template <typename T>
class diagonalMatrix{
    private:
        T* A;
        int size;
    public:
        // Constructors
        diagonalMatrix(); // Default
        diagonalMatrix(T* data, int size);

        diagonalMatrix(const diagonalMatrix& cpy); // Copy

        ~diagonalMatrix();

        // Operator overload
        // Assignment operator overload
        diagonalMatrix& operator=(diagonalMatrix const& other);
        diagonalMatrix& operator+(diagonalMatrix const& other);
        diagonalMatrix& operator-(diagonalMatrix const& other);
        diagonalMatrix& operator*(diagonalMatrix const& other);

        // Accessor/Mutator
        T getData(int index){
            return this->A[index];
        }
        
        int getSize(){
            return size;
        }

        void setData(T value, int index){
            this->A[index] = value;
        }

        void setSize(int size){
            this->size = size;
        }

        // Extraction Operator Overload
        template <typename U>
        friend ostream& operator<<(ostream& out, const diagonalMatrix<U>& mat);
};


#include "diagonal.cpp"
#endif