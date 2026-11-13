#include <iostream>
#include <string>
using namespace std;

class BankingException {
protected:
    string msg;

public:
    BankingException(string m) : msg(m) {}

    virtual string getMessage() const {
        return msg;
    }
};

class InsufficientFundsException : public BankingException {
private:
    double shortfall;

public:
    InsufficientFundsException(string m, double sf)
        : BankingException(m), shortfall(sf) {}

    double getShortfall() const {
        return shortfall;
    }
};

void processWithdrawal(double balance, double amount) {
    if (amount > balance) {
        throw InsufficientFundsException(
            "Account overdrawn!", amount - balance
        );
    }

    cout << "Withdrawal successful." << endl;
}

int main() {
    try {
        processWithdrawal(500.0, 750.0);
    }
    catch (const InsufficientFundsException& ife) {
        cout << "Shortfall of: $" 
             << ife.getShortfall() << endl;
    }
    catch (const BankingException& be) {
        cout << "General Banking Error: "
             << be.getMessage() << endl;
    }
    catch (...) {
        cout << "Unknown banking error." << endl;
    }

    return 0;
}
