#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accHolder;
    double balance;
    static double totalBankReserves;

public:
    BankAccount(string name, double initialDeposit) {
        accHolder = name;
        balance = initialDeposit;
        totalBankReserves += initialDeposit;
    }

    void displayAccount() const {
        cout << "Account Holder: " << accHolder << endl;
        cout << "Balance: $" << balance << endl;
    }

    static void displayAudit() {
        cout << "Total Reserves in Vault: $"
             << totalBankReserves << endl;
    }
};

// External definition of static data member
double BankAccount::totalBankReserves = 0.0;

int main() {
    BankAccount acc1("Alice", 5000.0);
    BankAccount acc2("Bob", 3000.0);

    BankAccount::displayAudit();

    acc1.displayAccount();
    acc2.displayAccount();

    return 0;
}
