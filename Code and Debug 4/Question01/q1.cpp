#include <iostream>
using namespace std;

class Person {
public:
    int idNumber;

    Person(int id = 0) : idNumber(id) {
        cout << "Person initialized: " << idNumber << endl;
    }
};

class Student : virtual public Person {
public:
    Student(int id) : Person(id) {}
};

class Employee : virtual public Person {
public:
    Employee(int id) : Person(id) {}
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(int sId, int eId)
        : Person(sId), Student(sId), Employee(eId) {}
};

int main() {
    TeachingAssistant ta(101, 202);

    cout << "TA ID: " << ta.idNumber << endl;

    return 0;
}
