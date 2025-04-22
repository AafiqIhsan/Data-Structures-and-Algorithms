#include "array.hpp"

// Contructors
template <typename T>
Arr<T>::Arr(){
    data = nullptr;
    length = 0;
    size = 0;
}

template <typename T>
Arr<T>::Arr(const Arr<T>& cpy){
    if(data != nullptr && data != NULL){
        this->length = cpy.length;
        this->size = cpy.size;
        this->data = new T[size];

        for(int i = 0; i < size; i++){
            this->data[i] = cpy.data[i];
        }
        return;
    }
    this->data = nullptr;
    this->length = 0;
    this->size = 0;
}

template <typename T>
Arr<T>::Arr(int size){
    this->size = size;
    this->length = 0;
    this->data = new T[size];
}

template <typename T>
Arr<T>::Arr(T* data, int length, int size){
    this->size = size;
    this->length = length;
    this->data = new T[size];

    for(int i = 0; i < length; i++){
        this->data[i] = data[i];
    }
}


//Destructor
template <typename T>
Arr<T>::~Arr(){
    delete[] data;
    data = nullptr;
    size = 0;
    length = 0;
}


// Operators
template <typename T>
void Arr<T>::display(){
    cout << (*this);
}

template <typename T>
void Arr<T>::append(T value){
    resize();
    data[length++] = value;
}

template <typename T>
void Arr<T>::insert(T value, int index){
    if(index < length && index >= 0){
        resize();
        for(int i = length; i > index; i--){
            data[i] = data[i-1];
        }
        data[index] = value;
        length++;
        return;  
    }
    append(value);
}

template <typename T>
void Arr<T>::remove(int index){
    if(index < length && index >= 0){
        for(int i = index; i < length-1; i++){
            data[i] = data[i+1];
        }
    }
    else{
        return;
    }
    length--;
    resize();
}

template <typename T>
int Arr<T>::linSearch(T value){
    for(int i = 0; i < length; i++){
        if(data[i] == value){
            return i;
        }
    }
    return -1;
}

template <typename T>
int Arr<T>::binSearch(T value, int l, int h){
    int m = (l+h)/2;

    if(l > h){
        return -1;
    }
    else{
        if(value == data[m]){
            return m;
        }
        else if(value > data[m]){
            return binSearch(value,m+1,h);
        }
        return binSearch(value,l,m-1);
    }
}

template <typename T>
T Arr<T>::max(){
    T tmp  = data[0];
    for(int i = 1; i < length; i++){
        if(tmp < data[i]) tmp = data[i];
    }
    return tmp;
}

template <typename T>
T Arr<T>::min(){
    T tmp  = data[0];
    for(int i = 1; i < length; i++){
        if(tmp > data[i]) tmp = data[i];
    }
    return tmp;
}

template <typename T>
void Arr<T>::reverse(){
    T * tmp = new T[length];
    for(int i = length-1, j = 0; i >= 0 && j < length; i--, j++){
        tmp[j] = data[i];
    }

    for(int i = 0; i < length; i++){
        data[i] = tmp[i];
    }
    delete[] tmp;
    tmp = nullptr;
}

template <typename T>
void Arr<T>::shift(int index){
    T * tmp = new T[length];
    for(int i = 0; i < index; i++){
        tmp[i] = 0;
    }
    for(int i = index, j = 0; i < length && j < length; i++, j++){
        tmp[i] = data[j];
    }
    for(int i = 0; i < length; i++){
        data[i] = tmp[i];
    }
    delete[] tmp;
    tmp = nullptr;
}

template <typename T>
void Arr<T>::rotate(int index){
    T * tmp = new T[index];
    for(int i = 0, j = length - index; j < length; i++, j++){
        tmp[i] = data[j];
    }
    for(int i = index, j = 0; i < length; i++, j++){
        tmp[i] = data[j];
    }
    for(int i = 0; i < length; i++){
        data[i] = tmp[i];
    }
    delete[] tmp;
    tmp = nullptr;
}

template <typename T>
void Arr<T>::resize(){
    if(size != 0){
        if(length <= size/2){
            size = length + 1;
        }
        else if(length == size){
            size ++;
        }
        else{
            return;
        }

        T * tmp = new T[size];
        for(int i = 0; i < length; i++){
            tmp[i] = data[i];
        }

        delete[] data;
        data = tmp;
        tmp = nullptr;
    }
    else{
        size = 1;
        data = new T[size];
    }
}