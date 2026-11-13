#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual void display() const = 0;
    virtual ~Bill() {
        cout << "Bill destroyed\n";
    }
};

class OutPatient : public Bill {
public:
    double total() const override {
        return 1500;
    }

    void display() const override {
        cout << "Outpatient Bill: Rs." << total() << '\n';
    }
};

class InPatient : public Bill {
public:
    double total() const override {
        return 25000;
    }

    void display() const override {
        cout << "Inpatient Bill: Rs." << total() << '\n';
    }
};

// New bill type without changing existing classes
class EmergencyBill : public Bill {
public:
    double total() const override {
        return 10000;
    }

    void display() const override {
        cout << "Emergency Bill: Rs." << total() << '\n';
    }
};

class Payer {
public:
    virtual void pay(double amount) const = 0;
    virtual ~Payer() = default;
};

class SelfPay : public Payer {
public:
    void pay(double amount) const override {
        cout << "Self payment: Rs." << amount << '\n';
    }
};

class Insurance : public Payer {
public:
    void pay(double amount) const override {
        cout << "Insurance payment: Rs." << amount << '\n';
    }
};

// New payer type
class CorporatePayer : public Payer {
public:
    void pay(double amount) const override {
        cout << "Corporate payment: Rs." << amount << '\n';
    }
};

void processPayment(const Bill& bill, const Payer& payer) {
    if (bill.total() <= 0)
        throw runtime_error("Invalid bill amount");

    bill.display();
    payer.pay(bill.total());
}

int main() {
    cout << "HOSPITAL BILLING SYSTEM\n\n";

    vector<unique_ptr<Bill>> bills;

    bills.push_back(make_unique<OutPatient>());
    bills.push_back(make_unique<InPatient>());
    bills.push_back(make_unique<EmergencyBill>());

    SelfPay self;
    Insurance insurance;
    CorporatePayer corporate;

    vector<const Payer*> payers = {
        &self, &insurance, &corporate
    };

    for (size_t i = 0; i < bills.size(); i++) {
        try {
            processPayment(*bills[i], *payers[i]);
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << '\n';
        }

        cout << '\n';
    }

    cout << "All transactions completed.\n";

    return 0;
}
