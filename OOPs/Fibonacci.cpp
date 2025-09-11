#include <iostream>
using namespace std;

class Fibonacci {
private:
    int n;
    int arr[100];
    long long sum;

public:
    void input() {
        n = 0;
        sum = 0;
        cout << "Enter number of terms: ";
        cin >> n;

        if (n > 100) {
            cout << "Limit exceeded! Please enter <= 100 terms." << endl;
            n = 0;
        }
    }

    void fibonacci() {
        if (n >= 1) arr[0] = 0;
        if (n >= 2) arr[1] = 1;

        for (int i = 2; i < n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
    }

    void Sum() {
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
    }

    void output() {
        cout << "Fibonacci Series: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Sum of series: " << sum << endl;
    }
};

int main() {
    Fibonacci f;
    f.input();
    f.fibonacci();
    f.Sum();
    f.output();

    return 0;
}
