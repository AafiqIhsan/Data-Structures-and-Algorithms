#include "list.hpp"

template <typename T>
LList<T>::LList(){
    this->first = nullptr;
}

template <typename T>
LList<T>::LList(LList<T>& cpy){
    this->first = new Node<T>;

    Node<T>* cpyPtr = cpy.first;
    Node<T>* thisPtr = this->first;

    while(cpyPtr != nullptr){
        thisPtr->next = new Node<T>;
        thisPtr->data = cpyPtr->data;
        thisPtr = thisPtr->next;
        cpyPtr = cpyPtr->next;
    }
}

template <typename T>
LList<T>::~LList(){
    Node<T>* thisPtr = this->first;
    Node<T>*tmp;
    while(thisPtr != nullptr){
        tmp = thisPtr->next;
        thisPtr->next = nullptr;
        delete thisPtr;
        thisPtr = tmp;
    }
}

template <typename T>
void LList<T>::display(Node<T>* ptr){
    if(ptr == nullptr){
        return;
    }
    cout << ptr->data << " ";
    display(ptr->next);
}

template <typename T>
void LList<T>::show(int index){
    Node<T> *tmp = this->first;

    for(int i = 0; i < index-1; i++){
        if(tmp->next == nullptr){
            cout << "Out of Bounds!" << endl;
            return;
        }
        tmp = tmp->next;
    }
    cout << "Element[" << index << "]: " << tmp->data << endl;
}

template <typename T>
int LList<T>::count(){
    int count = 0;
    Node<T> *tmp = this->first;
    while(tmp != nullptr){
        count++;
        tmp = tmp->next;
    }
    return count;
}

template <typename T>
T LList<T>::sum(){
    int sum = 0;
    Node<T> *tmp = this->first;
    while(tmp != nullptr){
        sum+=tmp->data;
        tmp = tmp->next;
    }
    return sum;
}

template <typename T>
T LList<T>::max(){
    T max = this->first->data;
    Node<T> *tmp = this->first->next;
    while(tmp != nullptr){
        if(tmp->data > max){
            max = tmp->data;
        }
        tmp = tmp->next;
    }
    return max;
}

template <typename T>
T LList<T>::min(){
    T min = this->first->data;
    Node<T> *tmp = this->first->next;
    while(tmp != nullptr){
        if(tmp->data < min){
            min = tmp->data;
        }
        tmp = tmp->next;
    }
    return min;
}

template <typename T>
int LList<T>::Search(T data){
    int count = 0;
    Node<T> *tmp = this->first;
    while(tmp != nullptr){
        if(tmp->data == data){
            return count;
        }
        tmp = tmp->next;
        count++;
    }
    return -1;
}

template <typename T>
void LList<T>::insert(T data, int index){
    Node<T>* ptr = this->first;
    if(this->count() == 0){
        this->first = new Node<T>(data,nullptr);
    }
    else if(index == 0){
        Node<T>* tmp = new Node<T>(data,this->first);
        this->first = tmp;
        tmp = nullptr;
    }
    else if(index > 0 && index <= this->count()){
        for(int i = 0; i < index-1 && ptr->next != nullptr; i++){
            ptr = ptr->next;
        }
        ptr->next = new Node<T>(data,ptr->next);
    }
}

template <typename T>
void LList<T>::append(T data){
    if(this->first == nullptr){
        this->first = new Node<T>(data,nullptr);
        return;
    }
    else{
        Node<T>* ptr = this->first;
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = new Node<T>(data,nullptr);
    }

}

template <typename T>
void LList<T>::remove(int index){
    int size = this->count();
    if(this->first == nullptr || index >= size){
        return;
    }
    else if(index >= 0 && index < size){
        Node<T>* ptr = this->first;
        if(index == 0){
            this->first = ptr->next;
            ptr->next = nullptr;
            delete ptr;
            ptr = nullptr;
            return;
        }
        for(int i = 0; i < index-1; i++){
            ptr = ptr->next;
        }
        Node<T>* tmp = ptr->next;
        ptr->next = tmp->next;
        tmp->next = nullptr;
        delete tmp;
        tmp = nullptr;
    }
}

/*
template <typename T>
bool LList<T>::isSorted(){

}

template <typename T>
T& LList<T>::reverse(){
    // 2 Methods
    // 1. Reversing Elements [Use array]
    // 2. Reversing Links(node->next) [Use sliding pointers]
    // Method 2
    Node<T>* p = this->first;
    Node<T>* q = nullptr;
    Node<T>* r - nullptr;
    
    while(p != nullptr){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
    p = q = r = nullptr;
    return *this;
}

template <typename T>
T& LList<T>::concat(LList<T> const& other){

}

template <typename T>
T& LList<T>::merge(LList<T> const& other){

}
*/

template <typename T>
ostream& operator<<(ostream& out, LList<T>& l){
    l.display(l.first);
    out << endl;
    return out;
}