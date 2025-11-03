#include <iostream>
using namespace std;

const int Array_Size = 10;

class matrix {
    int *array;
public:
    
    void* operator new(size_t size) {
        matrix* obj = (matrix*)::operator new(size);  
        obj->array = new int[Array_Size];             
        return obj;
    }

    
    void operator delete(void* ptr) {
        matrix* obj = (matrix*)ptr;
        delete[] obj->array;      
        ::operator delete(obj);   
    }

    
    void setValue(int index, int value) {
        if (index >= 0 && index < Array_Size)
            array[index] = value;
    }

    
    void display() {
        for (int i = 0; i < Array_Size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    
    matrix* v = new matrix;

    
    for (int i = 0; i < Array_Size; i++) {
        v->setValue(i, i * 10);
    }

    
    cout << "Values in matrix object: ";
    v->display();


    delete v;
    

    return 0;
}