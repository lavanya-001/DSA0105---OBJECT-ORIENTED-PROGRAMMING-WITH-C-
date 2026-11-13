#include <iostream>
using namespace std;

class Person {
public:
    int id = 100;
};

class Student : public Person {};
class Staff : public Person {};

class TeachingAssistant : public Student, public Staff {};

int main() {
    TeachingAssistant ta;

    cout << "Size without virtual inheritance: "
         << sizeof(ta) << " bytes\n";

    cout << "Student Person ID: "
         << ta.Student::id << endl;

    cout << "Staff Person ID: "
         << ta.Staff::id << endl;

    return 0;
}
