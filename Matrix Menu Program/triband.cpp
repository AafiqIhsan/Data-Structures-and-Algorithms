#include "matrix.hpp"
#include "triband.hpp"

template <typename T>
triBand<T>::triBand(){
    T tmp;

    cout << "Please Enter dimension n x n: ";
    cin >> this->n;
    this->size = ((3 * (this->n)) - 2);
    this->A = new T[this->size];

    cout << endl;
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < this->n; j++){
            if(i-j >= -1 && i-j <= 1){
                cout << "Please Enter A[" << i << "][" << j << "]: ";
                cin >> tmp;
                this->set(tmp,i,j);
            }
        }
    }
}

template <typename T>
triBand<T>::~triBand(){
    delete[] this->A;
}

template <typename T>
T triBand<T>::get(int i, int j){
    if(i == j){
        return this->A[i];
    }
    else if(i-j == 1){
        return this->A[((this->n) + j)];
    }
    else if(i-j == -1){
        return this->A[((this->n) + (this->n - 1) + i)];
    }
    else{
        return 0;
    }
}

template <typename T>
void triBand<T>::set(T value, int i, int j){
    if(i == j){
        this->A[i] = value;
    }
    else if(i-j == 1){
        this->A[((this->n) + j)] = value;
    }
    else if(i-j == -1){
        this->A[((this->n) + (this->n - 1) + i)] = value;
    }
}

template <typename T>
void triBand<T>::display(){
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < this->n; j++){
            cout << this->get(i,j) << " ";
        }
        cout << endl;
    }
}