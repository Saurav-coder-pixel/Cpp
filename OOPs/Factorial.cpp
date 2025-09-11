#include <iostream>
using namespace std;

class Factorial {
private:
    int num;
    int fact;

public:
    void input() {
        fact = 1;
        cout << "Enter a number: ";
        cin >> num;
    }

    void factorial() {
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
    }

    void output() {
        cout << "Factorial of " << num << " is: " << fact << endl;
    }
};

int main() {
    Factorial f;
    f.input();
    f.factorial();
    f.output();

    cout << "Made by Devashish :)" << endl;
    return 0;
}
