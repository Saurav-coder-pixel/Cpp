#include <iostream>
#include <iomanip>
using namespace std;

float proTerm(int i, float value, float x[]) {
    float prod = 1;
    for (int j = 0; j < i; j++) {
        prod *= (value - x[j]);
    }
    return prod;
}

void dividedDiffTable(float x[], float y[][10], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j+1][i-1] - y[j][i-1]) / (x[j+i] - x[j]);
        }
    }
}

float applyFormula(float value, float x[], float y[][10], int n) {
    float sum = y[0][0];

    for (int i = 1; i < n; i++) {
        sum += (proTerm(i, value, x) * y[0][i]);
    }
    return sum;
}

int main() {
    int n;
    float x[10], y[10][10], k;

    cout << "Enter the no. of observations : ";
    cin >> n;

    cout << "Enter the different values of x\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter the corresponding values of y\n";
    for (int i = 0; i < n; i++) {
        cin >> y[i][0];
    }

    cout << "Enter the value of 'k' for f(k) evaluation : ";
    cin >> k;

    dividedDiffTable(x, y, n);

    cout << "Value at " << k << " is " << applyFormula(k, x, y, n) << endl;

    return 0;
}
