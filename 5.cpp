//Demonstrate use of scope resolution operator using multiple initialization of the variable
#include <iostream>
using namespace std;

int num = 100;   // Global variable

class Demo {
public:
    static int num;  // Static class variable
};

// Initialize static class variable using scope resolution
int Demo::num = 200;

int main() {
    int num = 300;   // Local variable inside main

    cout << "Local variable (inside main): " << num << endl;
    cout << "Class variable (Demo::num): " << Demo::num << endl;
    cout << "Global variable (::num): " << ::num << endl;

    return 0;
}
