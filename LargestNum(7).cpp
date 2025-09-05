#include <iostream>
using namespace std;

// Macro to find maximum of two numbers
#define MAX(a,b) ((a) > (b) ? (a) : (b))

// Inline function to find maximum of three numbers
inline int largestOfThree(int x, int y, int z) {
    return MAX(MAX(x, y), z);   // using macro inside inline function
}

int main() {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    cout << "Largest number is: " << largestOfThree(a, b, c) << endl;

    return 0;
}
