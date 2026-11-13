#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string phone;

public:
    Person(string n, int i, string p)
        : name(n), id(i), phone(p) {
        cout << "Person ";
    }

    void displayPerson() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Phone: " << phone << endl;
    }
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;

public:
    Student(string n, int i, string p, string pr, double c)
        : Person(n, i, p), programme(pr), cgpa(c) {
        cout << "Student ";
    }
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;

public:
    Staff(string n, int i, string p, string d, double s)
        : Person(n, i, p), department(d), salary(s) {
        cout << "Staff ";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p,
                      string pr, double c, string d, double s)
        : Person(n, i, p),
          Student(n, i, p, pr, c),
          Staff(n, i, p, d, s) {
        cout << "TA ";
    }

    void display() const {
        displayPerson();
        cout << "Programme: " << programme << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

class ResearchScholar : public Student {
private:
    double fellowship;

public:
    ResearchScholar(string n, int i, string p,
                    string pr, double c, double f)
        : Person(n, i, p),
          Student(n, i, p, pr, c), fellowship(f) {}

    void displayFellowship() const {
        cout << "Research Fellowship: " << fellowship << endl;
    }
};

int main() {
    cout << "VIRTUAL BASE CLASS CONSTRUCTION\n";

    TeachingAssistant ta("Lavanya", 101, "9876543210",
                         "CSE", 8.5, "Computer Science", 25000);

    cout << "\n\nTEACHING ASSISTANT DETAILS\n";
    ta.display();

    cout << "\nRESEARCH SCHOLAR\n";
    ResearchScholar rs("Kavya", 102, "9876501234",
                       "CSE", 9.0, 15000);
    rs.displayPerson();
    rs.displayFellowship();

    cout << "\nOBJECT SIZE\n";
    cout << "TeachingAssistant size: "
         << sizeof(TeachingAssistant) << " bytes\n";

    return 0;
}
