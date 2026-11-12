#include <iostream>
using namespace std;

class SavingsAccount {
private:
    double balance;
    double transactions[10];
    int next;
    int count;

public:
    SavingsAccount(double initial) {
        balance = initial;
        next = 0;
        count = 0;
    }

    void deposit(double amount) {
        if (amount <= 0) return;

        balance += amount;
        addTransaction(amount);
    }

    void withdraw(double amount) {
        if (amount <= 0 || amount > balance) return;

        balance -= amount;
        addTransaction(-amount);
    }

    void addTransaction(double amount) {
        transactions[next] = amount;
        next = (next + 1) % 10;

        if (count < 10)
            count++;
    }

    void miniStatement() {
        cout << "Latest Transactions:\n";

        int start = (next - count + 10) % 10;

        for (int i = 0; i < count; i++) {
            cout << transactions[(start + i) % 10] << '\n';
        }

        cout << "Available Balance: Rs. " << balance << '\n';
    }
};

int main() {
    SavingsAccount account(5000);

    for (int i = 1; i <= 12; i++) {
        account.deposit(i * 100);
    }

    account.miniStatement();

    return 0;
}
