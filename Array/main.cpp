#include "array.hpp"

int main(){
    int * tmp = new int[5];
    for(int i = 0; i < 5; i++){
        tmp[i] = 2*i*i + 4*i + 6;
        cout << tmp[i] << " ";
    }
    cout << endl;

    cout << "**********Default constructor**********" << endl;
    Arr<int> arr;
    cout << arr << endl;

    cout << "**********Constructor with all arguments**********" << endl;
    Arr<int> a(tmp,5,5);
    cout << a << endl;

    Arr<string> names((string[5]){"Rahim", "Karim", "Jashim", "Oshim", "Badal"}, 5, 10);
    cout << names << endl;

    cout << "**********Copy Constructor**********" << endl;
    Arr<string> names2(names);
    cout << names2 << endl;

    cout << "**********Constructor with size argument**********" << endl;
    Arr<float> afloat(10);
    cout << afloat << endl;

    cout << "**********display()**********" << endl;
    names.display();
    cout << endl;

    cout << "**********append(val)**********" << endl;
    arr.append(4);
    arr.append(3);
    arr.append(2);
    arr.append(1);
    cout << arr << endl;

    names2.append("Paglu");
    names2.append("Chaglu");
    cout << names2 << endl;

    cout << "**********insert(val,ind)**********" << endl;
    arr.insert(5,2);
    cout << arr << endl;

    cout << "**********remove(ind)**********" << endl;
    arr.remove(2);
    cout << arr << endl;

    cout << "**********linSearch(val)**********" << endl;
    cout << arr.linSearch(8) << endl;
    cout << arr.linSearch(3) << endl;

    cout << "**********max()**********" << endl;
    cout << arr.max() << endl;

    cout << "**********min()**********" << endl;
    cout << arr.min() << endl;

    cout << "**********reverse()**********" << endl;
    arr.reverse();
    cout << arr << endl;

    cout << "**********shift(ind)**********" << endl;
    arr.append(5);
    arr.append(6);
    arr.append(7);
    arr.append(8);
    arr.append(8);
    cout << arr << endl;
    arr.shift(4);
    cout << arr << endl;

    cout << "**********rotate(ind)**********" << endl;
    cout << arr << endl;
    arr.rotate(5);
    cout << arr << endl;

    cout << "**********binSearch(val)**********" << endl;
    arr.remove(5);
    arr.remove(5);
    arr.remove(5);
    arr.remove(5);
    arr.remove(2);
    arr.append(23);
    arr.append(34);
    arr.append(45);
    arr.append(56);
    arr.append(67);
    arr.append(78);
    cout << arr << endl;
    cout << arr.binSearch(4, 0 , arr.getLength()-1) << endl;
    cout << arr.binSearch(56, 0 , arr.getLength()-1) << endl;
    cout << arr.binSearch(88, 0, arr.getLength()-1) << endl;
    cout << arr.binSearch(1, 0, arr.getLength()-1) << endl;
    cout << arr.binSearch(78, 0, arr.getLength()-1) << endl;

    return 0;
}