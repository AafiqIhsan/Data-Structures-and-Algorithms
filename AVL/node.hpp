#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class AVL;

template <typename T>
class Node{
    private:
        Node<T>* lChild;
        T data;
        Node<T>* rChild;
        int height;

        friend AVL<T>;
    public:
        Node(T data, int height = 0, Node<T>*lChild = nullptr, Node<T>* rChild = nullptr){
            this->data = data;
            this->height = height;
            this->lChild = lChild;
            this->rChild = rChild;
        }
};

#endif