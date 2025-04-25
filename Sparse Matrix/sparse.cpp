#include "sparse.hpp"

template <typename T>
Sparse<T>::Sparse(){
    cout << "For m x n matrix" << endl;
    cout << "Enter number of rows (m): " << endl;
    cin >> this->rows;
    cout << "Enter number of columns (n): " << endl;
    cin >> this->cols;
    cout << "Enter number of Non-Zero elements: " << endl;
    cin >> this->nonZero;
    
    this->e = new Element<T>[this->nonZero];
    cout << endl;
    for(int k = 0; k < nonZero; k++){
        int i,j;
        T val;
        cout << "Enter non-zero index e[" << k << "].i: ";
        cin >> i;
        this->e[k].seti(i);
        cout << "Enter non-zero index e[" << k << "].j: ";
        cin >> j;
        this->e[k].setj(j);
        cout << "Enter non-zero value e[" << k << "].value: ";
        cin >> val;
        this->e[k].setVal(val);
    }
}

template <typename T>
Sparse<T>::Sparse(Sparse const& cpy){
    this->rows = cpy.rows;
    this->cols = cpy.cols;
    this->nonZero = cpy.nonZero;
    delete[] e;
    e = new Element<T>[this->nonZero];
    for(int k = 0; k < this->nonZero; k++){
        this->e[k].seti(cpy.e[k].geti());
        this->e[k].setj(cpy.e[k].getj());
        this->e[k].setVal(cpy.e[k].getVal());
    }
}

template <typename T>
Sparse<T>::Sparse(int const& rows, int const& cols, int const& nonZero){
    this->rows = rows;
    this->cols = cols;
    this->nonZero = 0;

    this->e = new Element<T>[nonZero];

    for(int k = 0; k < nonZero; k++){
        this->e[k].seti(0);
        this->e[k].setj(0);
        this->e[k].setVal(0);
    }
}

template <typename T>
Sparse<T>::Sparse(int const& rows, int const& cols, int const& nonZero, Element<T> const* e){
    this->rows = rows;
    this->cols = cols;
    this->nonZero = nonZero;
    
    this->e = new Element<T>[this->nonZero];
    for(int k = 0; k < this->nonZero; k++){
        this->e[k].seti(e[k].geti());
        this->e[k].setj(e[k].getj());
        this->e[k].setVal(e[k].getVal());
    }
}

template <typename T>
Sparse<T>::~Sparse(){
    delete[] e;
    e = nullptr;
}

template <typename T>
Sparse<T>& Sparse<T>::add(Sparse<T> const& other){
    if(this->rows != other.rows || this->cols != other.cols){
        return *this;
    }
    else{
        int i = 0, j = 0;

        Sparse<T> * tmp = new Sparse(this->rows, this->cols, this->nonZero + other.nonZero);

        while(i < this->nonZero && j < other.nonZero){

            if(this->e[i].i < other.e[j].i){
                tmp->e[tmp->nonZero].seti(this->e[i].geti());
                tmp->e[tmp->nonZero].setj(this->e[i].getj());
                tmp->e[tmp->nonZero++].setVal(this->e[i++].getVal());
            }
            else if(this->e[i].i > other.e[j].i){
                tmp->e[tmp->nonZero].seti(other.e[j].geti());
                tmp->e[tmp->nonZero].setj(other.e[j].getj());
                tmp->e[tmp->nonZero++].setVal(other.e[j++].getVal());  
            }
            else{
                if(this->e[i].j < other.e[j].j){
                    tmp->e[tmp->nonZero].seti(this->e[i].geti());
                    tmp->e[tmp->nonZero].j = this->e[i].j;
                    tmp->e[tmp->nonZero++].value = this->e[i++].value;
                }
                else if(this->e[i].j > other.e[j].j){
                    tmp->e[tmp->nonZero].i = other.e[j].i;
                    tmp->e[tmp->nonZero].j = other.e[j].j;
                    tmp->e[tmp->nonZero++].value = other.e[j++].value;
                }
                else{
                    tmp->e[tmp->nonZero].i = this->e[i].i;
                    tmp->e[tmp->nonZero].j = this->e[i].j;
                    tmp->e[tmp->nonZero++].value = this->e[i++].value + other.e[j++].value;
                }
            }
        }
        Sparse<T> * ans = new Sparse(tmp->rows, tmp->cols, tmp->nonZero,tmp->e);
        return *ans;
    }
}

template <typename T>
void Sparse<T>::display(){
    cout << "row\t\tcol\t\tvalue" << endl;
    cout << this->rows << "\t\t" << this->cols << "\t\t" << this->nonZero << endl;
    for(int k = 0; k < this->nonZero; k++){
        cout << this->e[k].i << "\t\t" << this->e[k].j << "\t\t" << this->e[k].value << endl;
    }
}

template <typename T>
ostream& operator<<(ostream& out, Sparse<T> const& mat){
    int  k = 0;
    for(int i = 1; i <= mat.rows; i++){
        for(int j = 1; j <= mat.cols; j++){
            if(i == mat.e[k].i && j == mat.e[k].j){
                out << mat.e[k++].value << " ";
            }
            else{
                out << "0 ";
            }
        }
        out << endl;
    }

    return out;
}