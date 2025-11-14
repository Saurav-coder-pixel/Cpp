#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) const {
        if (m == 2) return isLeapYear(y) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }

    void normalizeDate() {
        while (day > daysInMonth(month, year)) {
            day -= daysInMonth(month, year);
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        while (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day += daysInMonth(month, year);
        }
    }

public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {
        normalizeDate();
    }

    void display() const {
        cout << (day < 10 ? "0" : "") << day << "/" 
             << (month < 10 ? "0" : "") << month << "/" 
             << year;
    }

    Date operator-(int days) const {
        Date result = *this;
        result.day -= days;
        result.normalizeDate();
        return result;
    }

    int operator-(const Date& other) const {
        int days1 = day + year * 365 + year / 4 - year / 100 + year / 400;
        int days2 = other.day + other.year * 365 + other.year / 4 - other.year / 100 + other.year / 400;
        
        for (int m = 1; m < month; m++) days1 += daysInMonth(m, year);
        for (int m = 1; m < other.month; m++) days2 += daysInMonth(m, other.year);
        
        return days1 - days2;
    }

    void inputDate(const string& prompt) {
        cout << prompt;
        cin >> day >> month >> year;
        normalizeDate();
    }
};

int main() {
    Date date1, date2;
    int choice, days;
    
    cout << "=== DATE OPERATIONS PROGRAM ===" << endl;
    
    do {
        cout << "\n===== MAIN MENU =====" << endl;
        cout << "1. Input Date 1" << endl;
        cout << "2. Input Date 2" << endl;
        cout << "3. Display Dates" << endl;
        cout << "4. Subtract days from Date 1" << endl;
        cout << "5. Subtract days from Date 2" << endl;
        cout << "6. Subtract Date 2 from Date 1" << endl;
        cout << "7. Subtract Date 1 from Date 2" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice (1-8): ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                date1.inputDate("Enter Date 1 (DD MM YYYY): ");
                cout << "Date 1 set to: ";
                date1.display();
                cout << endl;
                break;
                
            case 2:
                date2.inputDate("Enter Date 2 (DD MM YYYY): ");
                cout << "Date 2 set to: ";
                date2.display();
                cout << endl;
                break;
                
            case 3:
                cout << "\nCurrent Dates:" << endl;
                cout << "Date 1: ";
                date1.display();
                cout << endl;
                cout << "Date 2: ";
                date2.display();
                cout << endl;
                break;
                
            case 4:
                cout << "Enter number of days to subtract from Date 1: ";
                cin >> days;
                cout << "Date 1: ";
                date1.display();
                cout << " - " << days << " days = ";
                (date1 - days).display();
                cout << endl;
                break;
                
            case 5:
                cout << "Enter number of days to subtract from Date 2: ";
                cin >> days;
                cout << "Date 2: ";
                date2.display();
                cout << " - " << days << " days = ";
                (date2 - days).display();
                cout << endl;
                break;
                
            case 6:
                cout << "Date 1: ";
                date1.display();
                cout << " - Date 2: ";
                date2.display();
                cout << " = " << (date1 - date2) << " days" << endl;
                break;
                
            case 7:
                cout << "Date 2: ";
                date2.display();
                cout << " - Date 1: ";
                date1.display();
                cout << " = " << (date2 - date1) << " days" << endl;
                break;
                
            case 8:
                cout << "Thank you for using the program!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
    } while(choice != 8);
    
    return 0;
    cout<<"Saurav Kumar"<<endl<< " 16";
}