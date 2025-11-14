#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Date {
public:
    int d, m, y;
    void input() { cin >> d >> m >> y; }
    void show() { cout << d << "/" << m << "/" << y; }
};

class Patient {
public:
    string name, disease;
    Date admit, discharge;
    bool isDischarged;
    
    void getData() {
        cin.ignore();
        cout << "Name: "; getline(cin, name);
        cout << "Disease: "; getline(cin, disease);
        cout << "Admit date (DD MM YYYY): "; admit.input();
        cout << "Discharged? (1/0): "; cin >> isDischarged;
        if(isDischarged) {
            cout << "Discharge date: "; discharge.input();
        }
    }
    
    void showData(int id) {
        cout << "\nPatient " << id << ": " << name;
        cout << "\nDisease: " << disease;
        cout << "\nAdmit: "; admit.show();
        if(isDischarged) {
            cout << "\nDischarge: "; discharge.show();
        }
        cout << endl;
    }
};

int main() {
    vector<Patient> patients;
    int choice;
    
    while(true) {
        cout << "\n1.Add \n2.Show \n3.Exit\nChoice: ";
        cin >> choice;
        
        if(choice == 1) {
            Patient p;
            p.getData();
            patients.push_back(p);
        }
        else if(choice == 2) {
            for(int i=0; i<patients.size(); i++) {
                patients[i].showData(i+1);
            }
        }
        else if(choice == 3) break;
    }
    return 0;
    cout<<"Saurav Kumar"<<endl<< " 16";
}