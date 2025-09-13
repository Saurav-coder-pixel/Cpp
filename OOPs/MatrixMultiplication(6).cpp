#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int mat[10][10];
    
public:
    Matrix(int r = 0, int c = 0) {
        rows = r;
        cols = c;
    }

    void input() {
        cout << "Enter elements of " << rows << "x" << cols << " matrix: \n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    void display() {
        if (rows == 0 || cols == 0) {
            cout << "Empty matrix!" << endl;
            return;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix multiply(Matrix m2) {
        if (cols != m2.rows) {
            cout << "Matrix multiplication not possible!" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, m2.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * m2.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    Matrix m1(r1, c1);
    m1.input();
    
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;
    Matrix m2(r2, c2);
    m2.input();
    
    cout << "\nFirst Matrix:\n";
    m1.display();
    cout << "\nSecond Matrix:\n";
    m2.display();
    
    cout << "\nResultant Matrix after multiplication:\n";
    Matrix result = m1.multiply(m2);
    result.display();
    
    cout << "Saurav IT(Eve)" << endl;
    return 0;
}