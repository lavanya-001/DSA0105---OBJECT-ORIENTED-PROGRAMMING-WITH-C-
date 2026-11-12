#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int& getElement(vector<int>& values, size_t index) {
    if (index >= values.size()) {
        throw out_of_range("Invalid index");
    }
    return values[index];
}

int main() {
    vector<int> numbers = {10, 20, 30};

    getElement(numbers, 1) = 200;

    cout << "Updated vector: ";
    for (int value : numbers) {
        cout << value << " ";
    }
    cout << '\n';

    return 0;
}
