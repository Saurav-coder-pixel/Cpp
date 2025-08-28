#include <iostream>
using namespace std;

class Bank {
private:
    string Name;
    int accNo;
    char accType;
    double balance;

public:
    void initialize(string name, int acc_no, char acc_type, double bal) {
        Name = name;
        accNo = acc_no;
        accType = acc_type;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        }
    }

    void display() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Holder: " << Name << endl;
        cout << "Account Number: " << accNo << endl;
        cout << "Account Type: " << accType << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Global main function
int main() {
    Bank b;
    b.initialize("Saurav", 123456, 'S', 1000.0);
    b.display();

    b.deposit(500.0);
    b.withdraw(200.0);

    b.display();

    return 0;
}