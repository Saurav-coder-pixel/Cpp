#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int Empno;
    string Ename;
    float Basic;
    float Hra;      
    float Da;       
    float Netpay;   

    void Calculate() {
        Hra = 0.10f * Basic;
        Da = 0.20f * Basic;
        Netpay = Basic + Hra + Da;
    }

public:
    void Havedata() {
        cout << "Enter Employee Number: ";
        cin >> Empno;
        cout << "Enter Employee Name: ";
        cin.ignore();  
        getline(cin, Ename);
        cout << "Enter Basic Salary: ";
        cin >> Basic;

        Calculate(); 
    }

    void Dispdata() {
        cout << "\n--- Employee Details ---\n";
        cout << "Employee Number: " << Empno << endl;
        cout << "Employee Name  : " << Ename << endl;
        cout << "Basic Salary   : " << Basic << endl;
        cout << "HRA (10%)      : " << Hra << endl;
        cout << "DA  (20%)      : " << Da << endl;
        cout << "Net Pay        : " << Netpay << endl;
    }
};

int main() {
    Employee emp;
    emp.Havedata();
    emp.Dispdata();
    return 0;
}
