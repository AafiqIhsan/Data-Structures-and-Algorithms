#ifndef Arr_HPP
#define Arr_HPP

#include <iostream>

using namespace std;

template <typename T>
class Arr{
    private:
        T * data; // Pointer to the Arr
        int length; // Number of data in the Arr
        int size; // size of the Arr
    
        // Resizes the array to size*2 or size/2
        void resize();

        // Mutators/Accessors
        T get(int index) {return data[index];}
        void set(T value, int index) {data[index] = value;}
    
    public:
        // Constructors
        Arr(); // Default Constructor
        Arr(const Arr& data); // Copy Constructor
        Arr(int size);
        Arr(T* data, int length, int size);

        // Destructor
        ~Arr();

        // Operations
        void display(); // displays the array
        void append(T value); // joins val to end of array
        void insert(T value, int index); // inserts val at arr[index]
        void remove(int index); // removes value at arr[index]
        int linSearch(T value); // searches array for value
        int binSearch(T value, int l, int h); // Only for sorted array, efficient search
        T max(); // Maximum value of array
        T min(); // Minimum value off array
        void reverse(); // Reverses the array
        void shift(int index); // Right shifts array by index
        void rotate(int index); // Right rotates array by index
        
        // Accessor
        int getLength(){return this->length;}

        // Insertion operator overload
        friend ostream & operator << (ostream &out, const Arr &a){
            out << "Data: ";
            for(int i = 0; i < a.length; i++){
                out << a.data[i] << " ";
            }
            out << endl << "Size: " << a.size << ", Length: " << a.length << endl;

            return out;
        }
};

#include "array.cpp"
#endif