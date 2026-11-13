#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int n, int d)
        : numerator(n), denominator(d) {}

    // Friend function for stream insertion
    friend std::ostream& operator<<(std::ostream& os,
                                    const Fraction& f);
};

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}

int main() {
    Fraction f1(3, 4);

    std::cout << "Fraction: " << f1 << std::endl;

    return 0;
}
