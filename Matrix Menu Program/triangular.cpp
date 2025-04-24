#include "matrix.hpp"
#include "triangular.hpp"

template <typename T>
lowerTriangular<T>::lowerTriangular(){
    T tmp;

    cout << "Please Enter dimension n x n: ";
    cin >> this->n;
    this->size = ((this->n * (this->n+1)) / 2);
    this->A = new T[this->size];

    cout << endl;
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j <= i; j++){
                cout << "Please Enter A[" << i << "][" << j << "]: ";
                cin >> tmp;
                this->set(tmp,i,j);
        }
    }
}

template <typename T>
lowerTriangular<T>::~lowerTriangular(){
    delete[] this->A;
}

template <typename T>
T lowerTriangular<T>::get(int i, int j){
    if(i < j){
        return 0;
    }
    else{
        return this->A[(((i*(i+1))/2) + j)];
    }
}

template <typename T>
void lowerTriangular<T>::set(T value, int i, int j){
    if(i >= j){
        this->A[(((i*(i+1))/2) + j)] = value;
    }
}

template <typename T>
void lowerTriangular<T>::display(){
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < this->n; j++){
            cout << this->get(i,j) << " ";
        }
        cout << endl;
    }
}


// ***********************Upper Triangular*********************** //
template <typename T>
upperTriangular<T>::upperTriangular(){
    T tmp;

    cout << "Please Enter dimension n x n: ";
    cin >> this->n;
    this->size = ((this->n * (this->n+1)) / 2);
    this->A = new T[this->size];

    cout << endl;
    for(int i = 0; i < this->n; i++){
        for(int j = i; j < this->n; j++){
                cout << "Please Enter A[" << i << "][" << j << "]: ";
                cin >> tmp;
                this->set(tmp,i,j);
        }
    }
}

template <typename T>
upperTriangular<T>::~upperTriangular(){
    delete[] this->A;
}

template <typename T>
T upperTriangular<T>::get(int i, int j){
    if(i > j){
        return 0;
    }
    else{
        return this->A[((this->n*i) - ((i*(i-1))/2) + (j-i))];
    }
}

template <typename T>
void upperTriangular<T>::set(T value, int i, int j){
    if(j >= i){
        this->A[((this->n*i) - ((i*(i-1))/2) + (j-i))] = value;
    }
}

template <typename T>
void upperTriangular<T>::display(){
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < this->n; j++){
            cout << this->get(i,j) << " ";
        }
        cout << endl;
    }
}