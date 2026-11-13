#include <iostream>
#include <string>
using namespace std;

class Address {
    string city;
    int pin;

public:
    Address(string c, int p) : city(c), pin(p) {
        cout << "Address constructed\n";
    }

    string str() const {
        return city + "-" + to_string(pin);
    }

    ~Address() {
        cout << "Address destroyed\n";
    }
};

class Course {
    string courseName;

public:
    Course(string c) : courseName(c) {
        cout << "Course constructed\n";
    }

    ~Course() {
        cout << "Course destroyed\n";
    }
};

class Person {
protected:
    string name;
    int age;
    Address home;

public:
    Person(string n, int a, string city, int pin)
        : name(n), age(a), home(city, pin) {
        cout << "Person constructed\n";
    }

    virtual ~Person() {
        cout << "Person destroyed\n";
    }
};

class Student : virtual public Person {
protected:
    long long regNo;
    Course course;

public:
    Student(string n, int a, long long r,
            string city, int pin, string c)
        : Person(n, a, city, pin),
          regNo(r), course(c) {
        cout << "Student constructed\n";
    }

    ~Student() override {
        cout << "Student destroyed\n";
    }

    void display() const {
        cout << regNo << " " << name << " (" << age
             << ") " << home.str() << endl;
    }
};

class Staff : virtual public Person {
protected:
    string department;

public:
    Staff(string n, int a, string city, int pin, string d)
        : Person(n, a, city, pin), department(d) {
        cout << "Staff constructed\n";
    }

    ~Staff() override {
        cout << "Staff destroyed\n";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int a, long long r,
                      string city, int pin, string c, string d)
        : Person(n, a, city, pin),
          Student(n, a, r, city, pin, c),
          Staff(n, a, city, pin, d) {
        cout << "TeachingAssistant constructed\n";
    }

    ~TeachingAssistant() override {
        cout << "TeachingAssistant destroyed\n";
    }
};

struct Engine {
    Engine() { cout << "Engine "; }
    ~Engine() { cout << "~Engine "; }
};

struct Vehicle {
    Vehicle() { cout << "Vehicle "; }
    ~Vehicle() { cout << "~Vehicle "; }
};

struct Car : Vehicle {
    Engine e;

    Car() { cout << "Car "; }
    ~Car() { cout << "~Car "; }
};

int main() {
    cout << "STUDENT CONSTRUCTION AND DESTRUCTION\n";

    {
        Student s("Kavya", 19, 192311001,
                  "Salem", 636001, "C++");
        s.display();
    }

    cout << "\nTEACHING ASSISTANT CONSTRUCTION\n";

    {
        TeachingAssistant ta("Lavanya", 20, 192565025,
                             "Chennai", 600001,
                             "C++", "CSE");
    }

    cout << "\nCAR CONSTRUCTION AND DESTRUCTION\n";

    {
        Car c;
        cout << "| ";
    }

    cout << "\n\nSIZE OF TEACHING ASSISTANT\n";
    cout << sizeof(TeachingAssistant) << " bytes\n";

    return 0;
}
