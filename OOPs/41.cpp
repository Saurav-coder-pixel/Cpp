#include <iostream>
#include <exception> 
#include <string>

using namespace std;

class NegativeAgeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Age cannot be negative.";
    }
};

void validate_age(int age) {
    if (age < 0) {
        throw NegativeAgeException();
    }
    
    cout << "Age (" << age << ") is valid." << endl;
}

int main() {
    int age;
    cout << "--- User-Defined Exception Test ---" << endl;
    cout << "Enter an age: ";
    cin >> age;

    try {
        validate_age(age);
        cout << "Successfully validated age." << endl;
    
    } catch (const NegativeAgeException& e) {
        cerr << "\n--- EXCEPTION CAUGHT ---" << endl;
        cerr << e.what() << endl; 
        cerr << "You entered: " << age << endl;
    }

    cout << "\nProgram continues after the try-catch block." << endl;

    cout << "\n";
    cout<<"Saurav Kumar"<<endl<< " 16"; 

    return 0;
}