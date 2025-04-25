#include "sparse.hpp"

void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

int main(){
    Sparse<int> A;
    Sparse<int> B;

    Sparse<int> C(A.add(B));
    
    clearScreen();
    cout << C << endl;

    return 0;
}