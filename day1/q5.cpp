#include <iostream>
using namespace std;

// Base class for Account
class Account {
protected:
    int balance;

public:
    Account(int balance) : balance(balance) {}

    virtual void calculateInterest() const = 0; // Pure virtual function for polymorphism
};

// Derived class for SavingsAccount
class SavingsAccount : public Account {
private:
    double rate;
    int time;

public:
    SavingsAccount(int balance, double rate, int time) 
        : Account(balance), rate(rate), time(time) {}

    void calculateInterest() const override {
        double interest = balance * (rate / 100) * time;
        cout << "Account Type: Savings Account\n";
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << rate << "%\n";
        cout << "Time: " << time << " years\n";
        cout << "Interest Earned: " << interest << endl;
        cout << "Total Balance: " << (balance + interest) << endl;
    }
};

// Derived class for CurrentAccount
class CurrentAccount : public Account {
private:
    int maintenanceFee;

public:
    CurrentAccount(int balance, int maintenanceFee) 
        : Account(balance), maintenanceFee(maintenanceFee) {}

    void calculateInterest() const override {
        int totalDeductions = maintenanceFee * 12; // Assuming 1 year of fees
        cout << "Account Type: Current Account\n";
        cout << "Balance: " << balance << endl;
        cout << "Monthly Maintenance Fee: " << maintenanceFee << endl;
        cout << "Yearly Fee Deduction: " << totalDeductions << endl;
        cout << "Final Balance After Fee Deduction: " 
             << (balance - totalDeductions) << endl;
    }
};

int main() {
    int type;
    cout << "Enter Account Type (1 for Savings, 2 for Current): ";
    cin >> type;

    if (type == 1) {
        int balance;
        double rate;
        int time;
        cout << "Enter Balance: ";
        cin >> balance;
        cout << "Enter Interest Rate (%): ";
        cin >> rate;
        cout << "Enter Time (years): ";
        cin >> time;

        if (balance < 1000 || balance > 1000000 || rate < 1 || rate > 15 || time < 1 || time > 10) {
            cout << "Invalid input values.\n";
            return 0;
        }

        SavingsAccount savings(balance, rate, time);
        savings.calculateInterest();
    } else if (type == 2) {
        int balance;
        int fee;
        cout << "Enter Balance: ";
        cin >> balance;
        cout << "Enter Monthly Maintenance Fee: ";
        cin >> fee;

        if (balance < 1000 || balance > 1000000 || fee < 50 || fee > 500) {
            cout << "Invalid input values.\n";
            return 0;
        }

        CurrentAccount current(balance, fee);
        current.calculateInterest();
    } else {
        cout << "Invalid account type.\n";
    }

    return 0;
}
