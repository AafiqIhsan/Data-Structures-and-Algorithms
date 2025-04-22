#include "diagonal.hpp"

int main(){
    diagonalMatrix<int> A((int[5]){7,9,5,4,6},5);
    diagonalMatrix<int> B((int[5]){8,9,2,3,5},5);
    diagonalMatrix<int> C(A);
    diagonalMatrix<int> D;
    diagonalMatrix<int> E = (A * B);

    cout << "A" << endl;
    cout << A << endl << endl;
    cout << "B" << endl;
    cout << B << endl << endl;
    cout << "C" << endl;
    cout << C << endl << endl;
    cout << "D" << endl;
    cout << D << endl << endl;
    cout << "E" << endl;
    cout << E << endl << endl;
    cout << "A+B" << endl;
    cout << A+B << endl << endl;
    cout << "A-B" << endl;
    cout << A-B << endl << endl;
    cout << "A*B" << endl;
    cout << A*B << endl << endl;

    return 0;
}