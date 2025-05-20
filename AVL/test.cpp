#include <iostream>
#include "avl.hpp"

int main(){
    AVL<int> t;

    // Case 1: Remove from empty tree
    t.remove(10);  // Nothing happens, no crash
    t.displayLevelorder();
    std::cout << std::endl;
    
    // Case 2: Remove the only node
    t.insert(10);
    t.remove(10);  // Tree becomes empty

    t.displayLevelorder();
    std::cout << std::endl;

    // Case 3: Remove leaf node
    t.insert(10);
    t.insert(5);
    t.insert(15);
    t.remove(15);  // Removes leaf node

    t.displayLevelorder();
    std::cout << std::endl;

    // Case 4: Remove node with only left child
    t.insert(20);
    t.insert(10);
    t.insert(5);   // Now: 20 -> 10 -> 5
    t.remove(10);  // 10 has only left child (5)

    t.displayLevelorder();
    std::cout << std::endl;

    // Case 5: Remove node with only right child
    t.insert(30);
    t.insert(40);
    t.insert(50);  // Now: 30 -> 40 -> 50
    t.remove(40);  // 40 has only right child (50)

    t.displayLevelorder();
    std::cout << std::endl;

    // Case 6: Remove a node with two children
    t.insert(40);
    t.insert(20);
    t.insert(60);
    t.insert(10);
    t.insert(30);
    t.remove(20);  // 20 has two children (10, 30)

    t.displayLevelorder();
    std::cout << std::endl;

    // Case 7: LL imbalance on delete (L1)
    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(10);  // Left-heavy
    t.remove(70);  // Causes LL imbalance at 50 → LL rotation expected

    t.displayLevelorder();
    std::cout << std::endl;

    // Case 8: RR imbalance on delete (R1)
    t.insert(10);
    t.insert(5);
    t.insert(30);
    t.insert(25);
    t.insert(40);
    t.insert(50);  // Right-heavy
    t.remove(5);   // Causes RR imbalance at 10 → RR rotation expected

    t.displayLevelorder();
    std::cout << std::endl;

    // Case 9: LR imbalance on delete (L-1)
    t.insert(30);
    t.insert(10);
    t.insert(20);  // 10's right child is 20 → LR case
    t.insert(5);
    t.remove(5);   // After this, 30 becomes unbalanced → LR rotation at 30

    t.displayLevelorder();
    std::cout << std::endl;

    // Case 10: RL imbalance on delete (R-1)
    t.insert(10);
    t.insert(30);
    t.insert(20);  // 30's left child is 20 → RL case
    t.insert(35);
    t.remove(35);  // After this, 10 becomes unbalanced → RL rotation at 10

    t.displayLevelorder();
    std::cout << std::endl;

    // Case 11: Remove root with many levels
    t.insert(40);
    t.insert(20);
    t.insert(60);
    t.insert(10);
    t.insert(30);
    t.insert(50);
    t.insert(70);
    t.remove(40);  // Root with two children and subtrees

    t.displayLevelorder();
    std::cout << std::endl;

    // Case 12: Repeated Deletes to empty tree
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for(int v : values) t.insert(v);
    for(int v : values) t.remove(v);  // Tree becomes empty gradually

    t.displayLevelorder();
    std::cout << std::endl;

    return 0;
}