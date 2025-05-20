#include "avl.hpp"
#include <queue>

template <typename T>
Node<T>* AVL<T>::rSearch(Node<T>* root, T key){
    if(root == nullptr) return nullptr;
    if(root->data == key) return root;
    else if(key < root->data) return rSearch(root->lChild, key);
    else if(key > root->data) return rSearch(root->rChild, key);
    return nullptr;
}

template <typename T>
Node<T>* AVL<T>::searchIter(Node<T>* root, T key){
    while(root != nullptr){
        if(root->data == key) return root;
        else if(key  < root->data) root = root->lChild;
        else root = root->rChild;
    }
    return nullptr;
}

template <typename T>
Node<T>* AVL<T>::rInsert(Node<T>* root, T key){
    // Find if key is present
    // If not present, create new node
    if(root == nullptr) root = new Node<T>(key);
    else if(key < root->data) root->lChild = rInsert(root->lChild, key);
    else if(key > root->data) root->rChild = rInsert(root->rChild, key);

    // Set root height
    int hl = root->lChild ? root->lChild->height : 0;
    int hr = root->rChild ? root->rChild->height : 0;
    root->height = std::max(hl, hr) + 1;

    // Balance the tree
    if(balanceFactor(root) == 2 && balanceFactor(root->lChild) >= 0) return LLRotation(root);
    if(balanceFactor(root) == 2 && balanceFactor(root->lChild) < 0) return LRRotation(root);
    if(balanceFactor(root) == -2 && balanceFactor(root->rChild) > 0) return RLRotation(root);
    if(balanceFactor(root) == -2 && balanceFactor(root->rChild) <= 0) return RRRotation(root);

    return root;
}

template <typename T>
void AVL<T>::displayPreorder(Node<T>* root){
    if(root != nullptr){
        std::cout << root->data << " ";
        displayPreorder(root->lChild);
        displayPreorder(root->rChild);
    }
}

template <typename T>
void AVL<T>::displayInorder(Node<T>* root){
    if(root != nullptr){
        displayInorder(root->lChild);
        std::cout << root->data << " ";
        displayInorder(root->rChild);
    }
}

template <typename T>
void AVL<T>::displayPostorder(Node<T>* root){
    if(root != nullptr){
        displayPostorder(root->lChild);
        displayPostorder(root->rChild);
        std::cout << root->data << " ";
    }
}

template <typename T>
void AVL<T>::displayLevelorder(Node<T>* root){
    if(root == nullptr) return;

    std::queue<Node<T>*> q;
    Node<T>* current = root;

    q.push(current);

    while(!q.empty()){
        int size = q.size();
        while(size--){
            current = q.front();
            q.pop();

            std::cout << current->data << " ";

            if(current->lChild != nullptr) q.push(current->lChild);
            if(current->rChild != nullptr) q.push(current->rChild);
        }
        std::cout << "\n";
    }
}

template <typename T>
int AVL<T>::nodeCount(Node<T>* root){
    if(root == nullptr) return 0;
    return nodeCount(root->lChild) + nodeCount(root->rChild) + 1;
}

template <typename T>
int AVL<T>::height(Node<T>* root){
    if(root == nullptr) return 0;
    int hl,hr;
    hl = root->lChild? (root->lChild->height) : 0;
    hr = root->rChild? (root->rChild->height) : 0;
    // Don't add +1 in hl and hr calls because the else condition 
    // of the ternary operator doesn't return proper values
    // return(hl>hr?hl+1:hr+1); // Inefficient

    return std::max(hl,hr) + 1;
}

template <typename T>
Node<T>* AVL<T>::max(Node<T>* root){
    if(root->rChild == nullptr) return root;
    return max(root->rChild);
}

template <typename T>
Node<T>* AVL<T>::min(Node<T>* root){
    if(root->lChild == nullptr) return root;
    return min(root->lChild);
}

template <typename T>
Node<T>* AVL<T>::remove(Node<T>* root, T key){
    Node<T>* tmp = nullptr;

    if(root == nullptr) return nullptr;
    // Find node with key and set respective pointer to left or right child
    if(key < root->data) root->lChild = remove(root->lChild, key);
    else if(key > root->data) root->rChild = remove(root->rChild, key);

    else{
        // Case 1: 0 Children
        if(root->lChild == nullptr && root->rChild == nullptr){
            delete root;
            return nullptr;
        }

        // Case 2: 1 Child only
        else if(root->lChild == nullptr){
            tmp = root->rChild;
            delete root;
            root = nullptr;
            return tmp;
        }

        else if(root->rChild == nullptr){
            tmp = root->lChild;
            delete root;
            root = nullptr;
            return tmp;
        }
        
        // Case 3: 2 Children
        else{
            // Choose which subtree to change based on deeper height
            // Because we want to maintain the overall balance of the tree
            if(height(root->lChild) > height(root->rChild)){
                tmp = max(root->lChild);
                root->data = tmp->data;
                root->lChild =  remove(root->lChild, tmp->data);
            }
            else{
                tmp = min(root->rChild);
                root->data = tmp->data;
                root->rChild =  remove(root->rChild, tmp->data);
            }
        }
    }

    if(root == nullptr) return root;

    int hl = root->lChild? root->lChild->height : 0;
    int hr = root->rChild? root->rChild->height : 0;
    root->height = std::max(hl, hr) + 1;

    // Imbalance in left subtree
    if(balanceFactor(root) == 2 && balanceFactor(root->lChild) >= 0) return LLRotation(root); // L1
    if(balanceFactor(root) == 2 && balanceFactor(root->lChild) < 0) return LRRotation(root); // L-1
    
    // Imbalance in right subtree
    if(balanceFactor(root) == -2 && balanceFactor(root->rChild) <= 0) return RRRotation(root); // R1
    if(balanceFactor(root) == -2 && balanceFactor(root->rChild) > 0) return RLRotation(root); // R-1

    return root;
}

template <typename T>
void AVL<T>::deleteTree(Node<T>* root){
    if(root != nullptr){
        deleteTree(root->lChild);
        deleteTree(root->rChild);
        delete root;
    }
}

template <typename T>
Node<T>* AVL<T>::LLRotation(Node<T>* root){
    Node<T>* A = root;
    Node<T>* B = root->lChild;
    Node<T>* BR = B->rChild;
    
    B->rChild = A;
    A->lChild = BR;
    A->height = height(A);
    B->height = height(B);

    if(this->root == root) this->root = B;

    return B;
}

template <typename T>
Node<T>* AVL<T>::LRRotation(Node<T>* root){
    Node<T>* A = root;
    Node<T>* B = root->lChild;
    Node<T>* C = B->rChild;
    Node<T>* CL = C->lChild;
    Node<T>* CR = C->rChild;

    C->rChild = A;
    C->lChild = B;
    B->rChild = CL;
    A->lChild = CR;

    A->height = height(A);
    B->height = height(B);
    C->height = height(C);

    if(this->root == root) this->root = C;

    return C;
}

template <typename T>
Node<T>* AVL<T>::RLRotation(Node<T>* root){
    Node<T>* A = root;
    Node<T>* B = root->rChild;
    Node<T>* C = B->lChild;
    Node<T>* CL = C->lChild;
    Node<T>* CR = C->rChild;

    C->rChild = B;
    C->lChild = A;
    B->lChild = CR;
    A->rChild = CL;

    A->height = height(A);
    B->height = height(B);
    C->height = height(C);

    if(this->root == root) this->root = C;

    return C;
}

template <typename T>
Node<T>* AVL<T>::RRRotation(Node<T>* root){
    Node<T>* A = root;
    Node<T>* B = root->rChild;
    Node<T>* BL = B->lChild;
    
    B->lChild = A;
    A->rChild = BL;
    
    A->height = height(A);
    B->height = height(B);

    if(this->root == root) this->root = B;

    return B;
}

template <typename T>
int AVL<T>::balanceFactor(Node<T>* root){
    if(root == nullptr) return 0;
    // Bug was in height function because proper hl and hr 
    // values were not being returned if hl+1 and hr+1 
    // was done from the ternary operator
    int hl = root->lChild? root->lChild->height : 0; // this works
    int hr = root->rChild? root->rChild->height : 0; // this works
    // int hl = height(root->lChild); // Also works
    // int hr = height(root->rChild); // Also works

    return hl-hr;
}

// Public Methods
template <typename T>
void AVL<T>::createPreorder(T * arr, int size){
    for(int i = 0; i < size; i++){
        this->insert(arr[i]);
    }
}