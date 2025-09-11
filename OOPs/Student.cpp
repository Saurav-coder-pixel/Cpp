#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int enrollmentNo;
    int marks[5];
    float avg;
    
public:
    void input() {
        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter enrollment number: ";
        cin >> enrollmentNo;
        
        cout << "Enter marks in 5 subjects: ";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
        }
    }

    void calculateAverage() {
        avg = 0.0;
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        avg = sum / 5.0;
    }

    void output() {
        cout << "\n--- Student Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Enrollment No: " << enrollmentNo << endl;
        cout << "Marks: " << endl;
        for (int i = 0; i < 5; i++) {
            cout << i+1 << " subject marks: " << marks[i] << endl;
        }
        cout << "\nAverage Marks: " << avg << endl;
    }
};

int main() {
    Student student;
    student.input();
    student.calculateAverage();
    student.output();
    
    return 0;
}