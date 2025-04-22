#include "diagonal.hpp"

template <typename T>
diagonalMatrix<T>::diagonalMatrix(){
    A = nullptr;
    size = 0;
}

template <typename T>
diagonalMatrix<T>::diagonalMatrix(T* data, int size){
    A = new T[size];
    this->size = size;
    for(int i = 0; i < size; i++){
        A[i] = data[i];
    }
}

template <typename T>
diagonalMatrix<T>::diagonalMatrix(diagonalMatrix<T> const& cpy){
    this->size = cpy.size;

    this->A = new T[this->size];

    for(int i = 0; i < this->size; i++){
        this->A[i] = cpy.A[i];
    }
}

template <typename T>
diagonalMatrix<T>::~diagonalMatrix(){
    delete[] A;
    A = nullptr;
    size = 0;
}


// Operator Overloading
template <typename T>
diagonalMatrix<T>& diagonalMatrix<T>::operator=(diagonalMatrix<T> const& other){
    if(this == &other){
        return (*this);
    }
    delete[] A;
    this->size = other.size;
    A = new T[size];
    for(int i = 0; i < size; i++){
        A[i] = other.A[i];
    }
    return (*this);
}

template <typename T>
diagonalMatrix<T>& diagonalMatrix<T>::operator+(diagonalMatrix<T> const& other){
    if(this->size != other.size){
        return (*this);
    }

    else if(this->A != nullptr && other.A != nullptr && this->A != NULL && other.A != NULL){
        diagonalMatrix<T> * tmp = new diagonalMatrix<T>(*this);
        for(int i = 0; i < tmp->getSize(); i++){
            tmp->setData(tmp->getData(i) + other.A[i], i);
        }
        return *tmp;
    }

    else{
        diagonalMatrix<T> * tmp = new diagonalMatrix<T>(*this);
        for(int i = 0; i < tmp->getSize(); i++){
            tmp->setData(0,i);
        }
        return *tmp;
    }
}

template <typename T>
diagonalMatrix<T>& diagonalMatrix<T>::operator-(diagonalMatrix<T> const& other){
    if(this->size != other.size){
        return (*this);
    }

    else if(this->A != nullptr && other.A != nullptr && this->A != NULL && other.A != NULL){
        diagonalMatrix<T> * tmp = new diagonalMatrix<T>(*this);
        for(int i = 0; i < tmp->getSize(); i++){
            tmp->setData(tmp->getData(i) - other.A[i], i);
        }
        return *tmp;
    }

    else{
        diagonalMatrix<T> * tmp = new diagonalMatrix<T>(*this);
        for(int i = 0; i < tmp->getSize(); i++){
            tmp->setData(0,i);
        }
        cout << "tmp = " << endl << *tmp << endl;
        return *tmp;
    }
}

template <typename T>
diagonalMatrix<T>& diagonalMatrix<T>::operator*(diagonalMatrix<T> const& other){
    if(this->size != other.size){
        return (*this);
    }

    else if(this->A != nullptr && other.A != nullptr && this->A != NULL && other.A != NULL){
        diagonalMatrix<T> * tmp = new diagonalMatrix<T>(*this);
        for(int i = 0; i < tmp->getSize(); i++){
            tmp->setData(tmp->getData(i) * other.A[i], i);
        }
        return *tmp;
    }

    else{
        diagonalMatrix<T> * tmp = new diagonalMatrix<T>(*this);
        for(int i = 0; i < tmp->getSize(); i++){
            tmp->setData(0,i);
        }
        return *tmp;
    }
}

template <typename U>
ostream& operator<< (ostream& out, diagonalMatrix<U> const& mat){
    for(int i = 0; i < mat.size; i++){
        for(int j = 0; j < mat.size; j++){
            if(i == j){
                out << mat.A[i] << " ";
            }
            else{
                out << "0 ";
            }
        }
        out << endl;
    }
    return out;
}