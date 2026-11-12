#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> values;
    values.reserve(2);

    values.push_back(10);
    values.push_back(20);

    int& ref = values[0];

    cout << "Before reallocation: " << ref << '\n';
    cout << "Vector capacity: " << values.capacity() << '\n';

    values.push_back(30);

    cout << "After adding an element, vector size: "
         << values.size() << '\n';

    cout << "The old reference may now be invalid.\n";
    cout << "Do not access ref after reallocation.\n";

    return 0;
}
