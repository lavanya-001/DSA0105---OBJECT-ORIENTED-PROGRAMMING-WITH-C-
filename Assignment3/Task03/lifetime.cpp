#include <iostream>
using namespace std;

class Logger {
private:
    string name;

public:
    Logger(string n) {
        name = n;
        cout << "Constructor: " << name << endl;
    }

    ~Logger() {
        cout << "Destructor: " << name << endl;
    }
};

int main() {
    cout << "Program started\n\n";

    Logger first("Stack Object");

    {
        cout << "\nEntering block\n";
        Logger second("Block Object");
        cout << "Leaving block\n";
    }

    cout << "\nCreating heap object\n";
    Logger* third = new Logger("Heap Object");

    cout << "Deleting heap object\n";
    delete third;

    cout << "\nProgram ending\n";

    return 0;
}
