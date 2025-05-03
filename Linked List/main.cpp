#include "list.hpp"

int main(){
    LList<int> A;
    A.append(2);
    A.append(3);
    A.append(5);
    A.append(7);
    A.append(1);
    A.append(6);
    cout << A;
    cout << "Count: " << A.count() << endl;
    A.insert(4,2);
    A.insert(8,3);
    A.insert(9,0);
    A.insert(10,8);
    A.insert(11,10);
    cout << A;
    cout << "Count: " << A.count() << endl;
    cout << "Max: " << A.max() << endl;
    cout << "Min: " << A.min() << endl;
    cout << A;
    A.remove(3);
    cout << "A.remove(3)" << endl;
    cout << A;
    cout << "Count: " << A.count() << endl;
    A.remove(5);
    cout << "A.remove(5)" << endl;
    cout << A;
    cout << "Count: " << A.count() << endl;
    A.remove(0);
    cout << "A.remove(0)" << endl;
    cout << A;
    cout << "Count: " << A.count() << endl;

    cout << "A.Search(10): " << A.Search(10) << endl;
    cout << "A.Search(2): " << A.Search(2) << endl;
    cout << "A.Search(11): " << A.Search(11) << endl;
    cout << "A.Search(55): " << A.Search(55) << endl;

    cout << "A.sum(): " << A.sum() << endl;

    return 0;
}