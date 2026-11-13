#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Staff {
protected:
    string name;
    int id;
    double basic;

public:
    Staff(string n, int i, double b)
        : name(n), id(i), basic(b) {}

    virtual double pay() const = 0;

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: Rs. " << pay() << endl;
    }

    virtual ~Staff() = default;
};

class Professor : public Staff {
private:
    double research;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i, b), research(r) {}

    double pay() const override {
        return basic + basic * 0.42 + research;
    }
};

class LabAssistant : public Staff {
public:
    LabAssistant(string n, int i, double b)
        : Staff(n, i, b) {}

    double pay() const override {
        return basic + basic * 0.42;
    }
};

class GuestFaculty : public Staff {
private:
    double hours, rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i, 0), hours(h), rate(r) {}

    double pay() const override {
        return hours * rate;
    }
};

int main() {
    vector<unique_ptr<Staff>> staff;

    staff.push_back(make_unique<Professor>(
        "Arun", 101, 50000, 10000));

    staff.push_back(make_unique<LabAssistant>(
        "Priya", 102, 30000));

    staff.push_back(make_unique<GuestFaculty>(
        "Kumar", 103, 40, 1000));

    cout << "COLLEGE PAYROLL SYSTEM\n\n";

    for (const auto& s : staff) {
        s->display();
        cout << "-------------------\n";
    }

    return 0;
}
