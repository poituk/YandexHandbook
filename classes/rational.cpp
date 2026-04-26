#include <iostream>
#include <numeric>
#include <fstream>

class Rational {    
    private:
        int numerator;
        int denominator;

        void normalize();

    public:
        Rational();
        Rational(int numerator, int denominator);

        int Numerator() const;
        int Denominator() const;

        Rational &operator+=(Rational &x);
        Rational &operator-=(Rational &x);
        Rational &operator*=(Rational &x);
        Rational &operator/=(Rational &x);

        Rational operator+(Rational &x);
        Rational operator-(Rational &x);
        Rational operator*(Rational &x);
        Rational operator/(Rational &x);
};

void Rational::normalize() {
    int g = std::gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
}

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    normalize();
}

int Rational::Numerator() const { return numerator; }
int Rational::Denominator() const { return denominator; }

Rational& Rational::operator+=(Rational &x) {
    numerator = numerator * x.denominator + x.numerator * denominator;
    denominator *= x.denominator;
    normalize();
    return *this;
}
Rational& Rational::operator*=(Rational &x) {
    numerator *= x.numerator;
    denominator *= x.denominator;
    normalize();
    return *this;
}
Rational& Rational::operator-=(Rational &x) {
    numerator = numerator * x.denominator - x.numerator * denominator;
    denominator *= x.denominator;
    normalize();
    return *this;
}
Rational& Rational::operator/=(Rational &x) {
    numerator *= x.denominator;
    denominator *= x.numerator;
    normalize();
    return *this;
}

Rational Rational::operator+(Rational &x) {
    return Rational(numerator * x.denominator + x.numerator * denominator, denominator * x.denominator);
}
Rational Rational::operator*(Rational &x) {
    return Rational(numerator * x.numerator, denominator * x.denominator);
}
Rational Rational::operator-(Rational &x) {
    return Rational(numerator * x.denominator - x.numerator * denominator, denominator * x.denominator);
}
Rational Rational::operator/(Rational &x) {
    return Rational(numerator * x.numerator, denominator * x.numerator);
}

std::ostream &operator<<(std::ostream &fout, Rational &x) {
    fout << x.Numerator() << " " << x.Denominator() << "\n";
    return fout;
}

int main() { 
    Rational a(1, 2), b(1, 2);
    Rational c = a * b;
    a += b;
    std::cout << c;

    return 0; 
}