#include <iostream>
#include <cmath>
#include <complex>
#include <stdexcept>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag,
                       real * c.imag + imag * c.real);
    }

    Complex operator/(const Complex& c) const {
        double denominator = c.real * c.real + c.imag * c.imag;

        if (denominator == 0)
            throw domain_error("Division by zero is not allowed");

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";
        return out;
    }
};

int main() {
    cout << "COMPLEX NUMBER OPERATOR OVERLOADING\n\n";

    Complex a(10, 15);
    Complex b(5, 3);

    cout << "First complex number: " << a << endl;
    cout << "Second complex number: " << b << endl;

    cout << "\nARITHMETIC OPERATIONS\n";
    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;

    cout << "\nCOMPARISON\n";
    cout << "Equality: " << (a == b ? "Equal" : "Not Equal") << endl;

    cout << "\nMAGNITUDE\n";
    cout << "Magnitude of first number: " << a.magnitude() << endl;

    cout << "\nRLC CIRCUIT IMPEDANCE\n";
    double R = 10, XL = 20, XC = 5;
    Complex impedance(R, XL - XC);

    cout << "Resistance (R): " << R << " ohms" << endl;
    cout << "Inductive reactance (XL): " << XL << " ohms" << endl;
    cout << "Capacitive reactance (XC): " << XC << " ohms" << endl;
    cout << "Total impedance: " << impedance << " ohms" << endl;
    cout << "Impedance magnitude: " << impedance.magnitude() << " ohms" << endl;

    cout << "\nSTD::COMPLEX COMPARISON\n";
    complex<double> standardA(10, 15);
    complex<double> standardB(5, 3);

    complex<double> standardResult = standardA + standardB;
    cout << "Using std::complex addition: "
         << standardResult.real() << " + "
         << standardResult.imag() << "i" << endl;

    cout << "\nDIVISION BY ZERO TEST\n";
    try {
        Complex zero(0, 0);
        Complex result = a / zero;
        cout << result << endl;
    }
    catch (const domain_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
