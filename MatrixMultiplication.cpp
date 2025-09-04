// Write a program to multiple two matrix using oops
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
        cout << "Enter elements of " << rows << "x" << cols << " matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    
    int getRows() { return rows; }
    int getCols() { return cols; }

    
    Matrix multiply(Matrix m) {
        Matrix result(rows, m.cols);

        if (cols != m.rows) {
            cout << "Matrix multiplication not possible!" << endl;
            return result;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.mat[i][j] = 0;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
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

    cout << "\nFirst Matrix:" << endl;
    m1.display();

    cout << "\nSecond Matrix:" << endl;
    m2.display();

    if (c1 != r2) {
        cout << "\nMatrix multiplication not possible (columns of first != rows of second)." << endl;
    } else {
        Matrix result = m1.multiply(m2);
        cout << "\nResultant Matrix after multiplication:" << endl;
        result.display();
    }

    return 0;
}
