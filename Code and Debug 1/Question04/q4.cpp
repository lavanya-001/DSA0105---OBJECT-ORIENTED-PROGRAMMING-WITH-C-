#include <iostream>
using namespace std;

int main() {
    int a = 25;
    int& refA = a;

    int literalValue = 100;
    int& refLiteral = literalValue;

    double pi = 3.14159;
    int convertedPi = static_cast<int>(pi);
    int& refInt = convertedPi;

    const int& constRef = 50;

    cout << a << " " << refA << endl;
    cout << refLiteral << " " << refInt << " " << constRef << endl;

    return 0;
}
