#include <iostream>
using namespace std;

// Forward declaration
class ClassB;

class ClassA {
private:
    int numA;
public:
    ClassA(int n) : numA(n) {}
    
    // Friend function declaration
    friend int findGreatest(ClassA, ClassB);
};

class ClassB {
private:
    int numB;
public:
    ClassB(int n) : numB(n) {}
    
    // Friend function declaration
    friend int findGreatest(ClassA, ClassB);
};

// Friend function definition
int findGreatest(ClassA objA, ClassB objB) {
    if (objA.numA > objB.numB) {
        return objA.numA;
    } else {
        return objB.numB;
    }
}

int main() {
    int num1, num2;
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    // Create objects of both classes
    ClassA objA(num1);
    ClassB objB(num2);
    
    // Find greatest using friend function
    int greatest = findGreatest(objA, objB);
    
    cout << "\nThe greatest number is: " << greatest << endl;
    cout << "Saurav Kumar" << endl << " 16" << endl;
    
    return 0;
}