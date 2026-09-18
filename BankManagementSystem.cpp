

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string customerName;
    double balance;

public:

    BankAccount() {
        accountNumber = 0;
        customerName = "";
        balance = 0.0;
    }

    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        if (balance < 0) {
            cout << "Invalid balance!\n";
            balance = 0;
        }

        saveAccount();

        cout << "\nAccount created successfully!\n";
    }

    void deposit() {
        double amount;

        cout << "\nEnter deposit amount: ";
        cin >> amount;

        if (amount > 0) {
            balance = balance + amount;
            saveAccount();

            cout << "Amount deposited successfully!\n";
            cout << "Current Balance: " << balance << endl;
        }
        else {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw() {
        double amount;

        cout << "\nEnter withdrawal amount: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount!\n";
        }
        else if (amount > balance) {
            cout << "Insufficient balance!\n";
        }
        else {
            balance = balance - amount;
            saveAccount();

            cout << "Amount withdrawn successfully!\n";
            cout << "Current Balance: " << balance << endl;
        }
    }

    void checkBalance() {
        cout << "\n-----------------------------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Balance        : " << balance << endl;
        cout << "-----------------------------\n";
    }

    void loadAccount() {
        ifstream file("accounts.txt");

        if (file.is_open()) {
            file >> accountNumber;
            file.ignore();

            getline(file, customerName);

            file >> balance;

            file.close();
        }
    }

private:

    void saveAccount() {
        ofstream file("accounts.txt");

        if (file.is_open()) {
            file << accountNumber << endl;
            file << customerName << endl;
            file << balance << endl;

            file.close();
        }
    }
};

int main() {

    BankAccount account;

    // Load previous account data
    account.loadAccount();

    int choice;

    do {

        cout << "\n====================================\n";
        cout << "       BANK MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                account.createAccount();
                break;

            case 2:
                account.deposit();
                break;

            case 3:
                account.withdraw();
                break;

            case 4:
                account.checkBalance();
                break;

            case 5:
                cout << "\nThank you for using Bank Management System!\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

