#include "matrix.hpp"

void mainMenu(){
    cout << "\t****Welcome to Matrix Displayer****\t" << endl;
    cout << "1.\tCreate" << endl;
    cout << "2.\tGet" << endl;
    cout << "3.\tSet" << endl;
    cout << "4.\tDisplay" << endl;
    cout << "0.\tExit" << endl;
}

void createMenu(){
    cout << "\t****Choose Type of Matrix****\t" << endl;
    cout << "1.\tTri-Band Matrix" << endl;
    cout << "2.\tLower Triangular Matrix" << endl;
    cout << "3.\tUpper Triangular Matrix" << endl;
}

void getMenu(int& i, int& j){
    cout << "\t****get****\t" << endl;
    cout << "Please Enter i: ";
    cin >> i;
    cout << "Please Enter j: ";
    cin >> j;
}

template <typename T>
void setMenu(T& value, int&i, int& j){
    cout << "\t****set****\t" << endl;
    cout << "Please Enter i: ";
    cin >> i;
    cout << "Please Enter j: ";
    cin >> j;
    cout << "Please Enter value: ";
    cin >> value;
}

bool isExit(int choice){
    if(choice == 0){
        return true;
    }
    return false;
}

int main(){
    int choice = 0;
    int type = 0;
    int value = 0;
    int i,j;
    Matrix<int> * mat = nullptr;

    do{
        mainMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                createMenu();
                cout << endl << "Please Enter type: ";
                cin >> type;
                switch (type)
                {
                    case 1:
                        mat = new triBand<int>;
                        break;
                    
                    case 2:
                        mat = new lowerTriangular<int>;
                        break;
                    case 3:
                        mat = new upperTriangular<int>;
                        break;
                    default:
                        cout << "Invalid Type. Try Again!" << endl;
                        break;
                }
                break;
            case 2:
                if(mat != nullptr){
                    getMenu(i,j);
                    cout << mat->get(i,j) << endl;
                }
                else{
                    cout << "Cannot get Non-Existent Matrix. Try Again!" << endl;
                }
                break;
            case 3:
                if(mat != nullptr){
                    setMenu(value,i,j);
                    mat->set(value,i,j);
                }
                else{
                    cout << "Cannot set Non-Existent Matrix. Try Again!" << endl;
                }
                break;
            case 4:
                if(mat != nullptr){
                    cout << endl;
                    mat->display();
                }
                else{
                    cout << "Cannot display Non-Existent Matrix. Try Again!" << endl;
                }
                break;
            case 0:
                break;
            default:
                cout << endl << "Invalid Input. Enter Valid choice." << endl;
                break;
        }
    }while(!isExit(choice));
    
    cout << endl << "Goodbye" << endl;

    delete mat;
    mat = nullptr;

    return 0;
}