#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) {
    return x*x*x - 2.0*x - 5.0;   // f(x) = x^3 - 2x - 5
}

int main() {
    double x0, x1, x2, f0, f1, f2, tol;
    int maxIter;

    cout << "Enter first guess: ";
    if (!(cin >> x0)) return 0;
    cout << "Enter second guess: ";
    if (!(cin >> x1)) return 0;
    cout << "Enter tolerance (e.g. 1e-6): ";
    if (!(cin >> tol)) return 0;
    cout << "Enter maximum iterations: ";
    if (!(cin >> maxIter)) return 0;

    cout << fixed << setprecision(6);
    f0 = f(x0);
    f1 = f(x1);

    if (fabs(f0 - f1) < 1e-15) {
        cout << "Mathematical error: f(x0) and f(x1) are too close.\n";
        return 0;
    }

    int iter = 0;
    bool converged = false;

    while (iter < maxIter) {
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        f2 = f(x2);

        cout << "Iter " << (iter+1)
             << "  x = " << x2
             << "  f(x) = " << f2 << '\n';

        if (fabs(f2) <= tol || fabs(x2 - x1) <= tol) {
            converged = true;
            break;
        }

        // prepare next iteration
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        ++iter;
    }

    if (converged)
        cout << "Root approximated: " << x2 << " after " << (iter+1) << " iterations.\n";
    else
        cout << "Not convergent after " << maxIter << " iterations. Last x = " << x2 << '\n';

    return 0;
}