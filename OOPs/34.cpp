#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class student {
private:
    char name[50];
    int age;
    char sex[10];
    float height;
    float weight;

public:
    void get_data() {
        cout << "Enter Name: ";
        cin.ignore(); // To clear any leftover newline
        cin.getline(name, 50);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Sex (Male/Female/Other): ";
        cin >> sex;

        cout << "Enter Height (in cm): ";
        cin >> height;

        cout << "Enter Weight (in kg): ";
        cin >> weight;
    }

    void display_data() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

int main() {
    string filename = "student.dat";
    fstream file;

    student s_write;

    cout << "--- Enter Student Details ---" << endl;
    s_write.get_data();

    // Writing to file
    file.open(filename, ios::binary | ios::out);
    if (!file) {
        cout << "Error: Could not open " << filename << " for writing." << endl;
        return 1;
    }
    file.write(reinterpret_cast<char*>(&s_write), sizeof(student));
    file.close();

    cout << "\nStudent data saved successfully!" << endl;

    // Reading from file
    student s_read;
    file.open(filename, ios::binary | ios::in);
    if (!file) {
        cout << "Error: Could not open " << filename << " for reading." << endl;
        return 1;
    }
    
    cout << "\n--- Reading Data From File ---" << endl;
    file.read(reinterpret_cast<char*>(&s_read), sizeof(student));
    file.close();

    s_read.display_data();

    cout << "\nSaurav Kumar" << endl << "16" << endl;

    return 0;
}
