#include <iostream>
using namespace std;

class Factorial {
private:
    int num;

public:
    // Constructor
    Factorial(int n) {
        num = n;
    }

    // Method to calculate factorial
    long long calculate() {
        long long fact = 1;
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
        return fact;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Factorial f(n);  // Object created
    cout << "Factorial of " << n << " is: " << f.calculate() << endl;

    return 0;
}
