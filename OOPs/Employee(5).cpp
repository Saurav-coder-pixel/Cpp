#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int employeeID;
    float salary[3];
    float avgSalary;
    
public:
    void input() {
        cout << "Enter employee name: ";
        cin >> name;
        
        cout << "Enter employee ID: ";
        cin >> employeeID;
        
        cout << "Enter salary for 3 months: ";
        for (int i = 0; i < 3; i++) {
            cin >> salary[i];
        }
    }
    
    void Average() {
        avgSalary = 0.0;
        float sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += salary[i];
        }
        avgSalary = sum / 3.0;
    }

    void output() {
        cout << "\n--- Employee Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salaries: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Salary in " << i+1 << " month: " << salary[i] << endl;
        }
        cout << "\nAverage Salary: " << avgSalary << endl;
    }
};

int main() {
    Employee employee;
    employee.input();
    employee.Average();
    employee.output();
    
    return 0;
}