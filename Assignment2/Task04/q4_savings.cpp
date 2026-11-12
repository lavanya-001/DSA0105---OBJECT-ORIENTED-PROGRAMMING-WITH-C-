#include <iostream>
using namespace std;

class SavingsAccount {
private:
    double balance;
    double transactions[10];
    int count;

public:
    SavingsAccount(double initialBalance) {
        balance = initialBalance;
        count = 0;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit\n";
            return;
        }

        balance += amount;
        addTransaction(amount);
    }

    void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Invalid withdrawal\n";
            return;
        }

        balance -= amount;
        addTransaction(-amount);
    }

    void addTransaction(double amount) {
        if (count < 10) {
            transactions[count++] = amount;
        } else {
            for (int i = 0; i < 9; i++) {
                transactions[i] = transactions[i + 1];
            }
            transactions[9] = amount;
        }
    }

    void miniStatement() {
        cout << "Mini Statement:\n";

        for (int i = 0; i < count; i++) {
            cout << transactions[i] << '\n';
        }

        cout << "Available Balance: Rs. " << balance << '\n';
    }
};

int main() {
    SavingsAccount account(5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);

    account.miniStatement();

    return 0;
}
