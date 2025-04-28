#include<iostream>
#include<string>
using namespace std;

class Employee {
private:
    string name;
    int age;
    string profession;
    double yearlySalary;
    string address;
    string panNumber;
    double taxAmount;

public:
    // Default Constructor
    Employee() {
        name = "Unknown";
        age = 0;
        profession = "Unknown";
        yearlySalary = 0.0;
        address = "Unknown";
        panNumber = "Unknown";
        taxAmount = 0.0;
    }

    // Parameterized Constructor (with default values)
    Employee(string n, int a, string p, double salary, string addr, string pan) {
        name = n;
        age = a;
        profession = p;
        yearlySalary = salary;
        address = addr;
        panNumber = pan;
        taxAmount = 0.0;
    }

    // Member function to calculate tax
    void calculateTax() {
        if (yearlySalary <= 250000) {
            taxAmount = 0;
        } else if (yearlySalary <= 500000) {
            taxAmount = (yearlySalary - 250000) * 0.05;
        } else if (yearlySalary <= 1000000) {
            taxAmount = (250000 * 0.05) + (yearlySalary - 500000) * 0.2;
        } else {
            taxAmount = (250000 * 0.05) + (500000 * 0.2) + (yearlySalary - 1000000) * 0.3;
        }
    }

    // Member function to print tax details
    void printTax() {
        cout << "\n----- Employee Tax Details -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Profession: " << profession << endl;
        cout << "Yearly Salary: Rs " << yearlySalary << endl;
        cout << "Home Address: " << address << endl;
        cout << "PAN Number: " << panNumber << endl;
        cout << "Calculated Tax: Rs " << taxAmount << endl;
        cout << "---------------------------------" << endl;
    }
};

// Main function
int main() {
    // Create an Employee object using parameterized constructor
    string name, profession, address, pan;
    int age;
    double salary;

    cout << "Enter Employee Name: ";
    getline(cin, name);

    cout << "Enter Employee Age: ";
    cin >> age;
    cin.ignore(); // Clear buffer

    cout << "Enter Employee Profession: ";
    getline(cin, profession);

    cout << "Enter Employee Yearly Salary: ";
    cin >> salary;
    cin.ignore(); // Clear buffer

    cout << "Enter Employee Address: ";
    getline(cin, address);

    cout << "Enter Employee PAN Number: ";
    getline(cin, pan);

    // Create the object
    Employee emp(name, age, profession, salary, address, pan);

    // Calculate and print tax
    emp.calculateTax();
    emp.printTax();

    return 0;
}

/* output- 
Enter Employee Name: Rahul Kumar
Enter Employee Age: 28
Enter Employee Profession: Software Engineer
Enter Employee Yearly Salary: 750000
Enter Employee Address: Bhubaneswar, Odisha
Enter Employee PAN Number: ABCDE1234F

----- Employee Tax Details -----
Name: Rahul Kumar
Age: 28
Profession: Software Engineer
Yearly Salary: Rs 750000
Home Address: Bhubaneswar, Odisha
PAN Number: ABCDE1234F
Calculated Tax: Rs 62500
---------------------------------
*/
