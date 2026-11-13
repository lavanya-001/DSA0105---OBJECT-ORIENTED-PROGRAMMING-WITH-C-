#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Account {
public:
    double rate() const {
        return 3.5;
    }

    virtual double vrate() const {
        return 3.5;
    }

    ~Account() {
        cout << "Account destructor called\n";
    }
};

class SeniorAccount : public Account {
private:
    double* history;

public:
    SeniorAccount() {
        history = new double[100];
        cout << "SeniorAccount created\n";
    }

    double rate() const {
        return 4.0;
    }

    double vrate() const override {
        return 4.0;
    }

    ~SeniorAccount() {
        delete[] history;
        cout << "SeniorAccount destructor called\n";
    }
};

int main() {
    cout << "UNSAFE ACCOUNT DEMONSTRATION\n";

    Account* a = new SeniorAccount();

    cout << "Non-virtual rate: " << a->rate() << endl;
    cout << "Virtual rate: " << a->vrate() << endl;

    cout << "\nOBJECT SLICING\n";

    SeniorAccount senior;
    Account copy = senior;

    cout << "Copied account rate: " << copy.vrate() << endl;

    cout << "\nDELETING THROUGH BASE POINTER\n";
    delete a;

    cout << "\nREPAIRED ACCOUNT DESIGN\n";

    vector<unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Account>());
    accounts.push_back(make_unique<SeniorAccount>());

    for (const auto& account : accounts) {
        cout << "Account interest rate: "
             << account->vrate() << "%" << endl;
    }

    cout << "\nSmart pointers automatically release memory.\n";

    return 0;
}
