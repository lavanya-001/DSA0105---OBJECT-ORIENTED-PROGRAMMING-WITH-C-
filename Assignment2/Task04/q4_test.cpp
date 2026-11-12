#include <iostream>
using namespace std;

class SavingsAccount {
private:
    double balance;
    double transactions[10];
    int count = 0;

public:
    SavingsAccount(double initial) : balance(initial) {}

    void deposit(double amount) {
        balance += amount;

        if (count < 10) {
            transactions[count++] = amount;
        } else {
            for (int i = 0; i < 9; i++)
                transactions[i] = transactions[i + 1];

            transactions[9] = amount;
        }
    }

    void miniStatement() {
        cout << "Latest transactions:\n";
        for (int i = 0; i < count; i++)
            cout << transactions[i] << '\n';

        cout << "Balance: Rs. " << balance << '\n';
    }
};

int main() {
    SavingsAccount account(1000);

    for (int i = 1; i <= 12; i++)
        account.deposit(i * 100);

    account.miniStatement();
    return 0;
}
