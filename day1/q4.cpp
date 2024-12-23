#include <iostream>
#include <string>
using namespace std;

// Base class for Employee
class Employee {
protected:
    string name;
    int id;
    int salary;

public:
    Employee(string name, int id, int salary) : name(name), id(id), salary(salary) {}

    virtual void displayDetails() const = 0; // Pure virtual function for polymorphism
};

// Derived class for Manager
class Manager : public Employee {
private:
    int rating;

public:
    Manager(string name, int id, int salary, int rating)
        : Employee(name, id, salary), rating(rating) {}

    void displayDetails() const override {
        int bonus = (salary * 10 / 100) * rating;
        int totalEarnings = salary + bonus;
        cout << "Employee: " << name << " (ID: " << id << ")\n";
        cout << "Role: Manager\n";
        cout << "Base Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Earnings: " << totalEarnings << endl;
    }
};

// Derived class for Developer
class Developer : public Employee {
private:
    int extraHours;

public:
    Developer(string name, int id, int salary, int extraHours)
        : Employee(name, id, salary), extraHours(extraHours) {}

    void displayDetails() const override {
        int overtimeCompensation = extraHours * 500;
        int totalEarnings = salary + overtimeCompensation;
        cout << "Employee: " << name << " (ID: " << id << ")\n";
        cout << "Role: Developer\n";
        cout << "Base Salary: " << salary << endl;
        cout << "Overtime Compensation: " << overtimeCompensation << endl;
        cout << "Total Earnings: " << totalEarnings << endl;
    }
};

int main() {
    int type;
    cout << "Enter Employee Type (1 for Manager, 2 for Developer): ";
    cin >> type;

    if (type == 1) {
        string name;
        int id, salary, rating;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Rating (1–5): ";
        cin >> rating;

        if (rating < 1 || rating > 5 || salary < 10000 || salary > 1000000) {
            cout << "Invalid input values.\n";
            return 0;
        }

        Manager manager(name, id, salary, rating);
        manager.displayDetails();
    } else if (type == 2) {
        string name;
        int id, salary, extraHours;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Extra Hours Worked (0–100): ";
        cin >> extraHours;

        if (extraHours < 0 || extraHours > 100 || salary < 10000 || salary > 1000000) {
            cout << "Invalid input values.\n";
            return 0;
        }

        Developer developer(name, id, salary, extraHours);
        developer.displayDetails();
    } else {
        cout << "Invalid employee type.\n";
    }

    return 0;
}
