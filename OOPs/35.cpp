#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Customer {
private:
    char name[50];
    int room_number;

public:
    void get_data() {
        cout << "Enter customer name: ";
        cin.ignore();  // Clear buffer before getline
        cin.getline(name, 50);

        cout << "Enter room number: ";
        cin >> room_number;
    }

    void display_data() {
        cout << "  Name: " << name << ", Room: " << room_number << endl;
    }
};

int main() {
    string filename = "hotel.dat";
    fstream file;
    Customer cust;
    char choice;

    // Open for appending (writing)
    file.open(filename, ios::binary | ios::app | ios::out);

    if (!file.is_open()) {
        cout << "Error: Could not open file for writing." << endl;
        return 1;
    }

    do {
        cout << "\n--- Enter New Customer Details ---" << endl;
        cust.get_data();

        file.write(reinterpret_cast<char*>(&cust), sizeof(Customer));

        cout << "\nDo you want to enter another customer? (y/n): ";
        cin >> choice;

        cin.ignore(); // <-- Clear buffer for next loop input

    } while (choice == 'y' || choice == 'Y');

    file.close();
    cout << "\nData saved successfully!" << endl;

    // Reading back all records
    int customer_count = 0;
    file.open(filename, ios::binary | ios::in);

    if (!file.is_open()) {
        cout << "Error: Could not open file for reading." << endl;
        return 1;
    }

    cout << "\n--- Customer Records in File ---" << endl;
    Customer temp_cust;

    while (file.read(reinterpret_cast<char*>(&temp_cust), sizeof(Customer))) {
        temp_cust.display_data();
        customer_count++;
    }

    file.close();

    cout << "\n-----------------------------------" << endl;
    cout << "Total number of customers: " << customer_count << endl;

    cout << "\nSaurav Kumar\n16\n";

    return 0;
}
