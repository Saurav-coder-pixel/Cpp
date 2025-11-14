#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Auditorium {
private:
    static int personCount;

public:
    Auditorium(string name) {
        personCount++;
        cout << name << " entered." << endl;
    }

    ~Auditorium() {
        personCount--;
    }

    static void display() {
        cout << "Number of people: " << personCount << endl;
    }

    static int getCount() {
        return personCount;
    }
};

int Auditorium::personCount = 0;

int main() {
    cout << "=== AUDITORIUM ENTRY SYSTEM ===" << endl;

    vector<Auditorium*> people;  // Store pointers to keep them alive

    while(true) {
        cout << "\n1. Enter person" << endl;
        cout << "2. Show count" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            cout << "Enter name: ";
            string name;
            getline(cin, name);

            people.push_back(new Auditorium(name));  // Allocate dynamically

        } else if(choice == 2) {
            Auditorium::display();

        } else if(choice == 3) {
            cout << "Final count: ";
            Auditorium::display();
            cout << "Goodbye!" << endl;

            // Clean up memory
            for(auto person : people) {
                delete person;
            }
            break;

        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}