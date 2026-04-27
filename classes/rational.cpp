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
        Rational(int num);
        Rational(int numerator, int denominator);

        int Numerator() const;
        int Denominator() const;

        Rational &operator+=(const Rational &x);
        Rational &operator-=(const Rational &x);
        Rational &operator*=(const Rational &x);
        Rational &operator/=(const Rational &x);

        friend Rational operator+(const Rational &a, const Rational &b);
        friend Rational operator-(const Rational &a, const Rational &b);
        friend Rational operator*(const Rational &a, const Rational &b);
        friend Rational operator/(const Rational &a, const Rational &b);

        Rational operator-() const;
        Rational operator+() const;

        friend bool operator==(const Rational &a, const Rational &b);
        friend bool operator!=(const Rational &a, const Rational &b);
};

void Rational::normalize() {
    int g = std::gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
    if(denominator < 0) {
        denominator *= (-1);
        numerator *= (-1);
    }
}

Rational Rational::operator-() const {
    return Rational(-numerator, denominator);
}

Rational Rational::operator+() const {
    return Rational(numerator, denominator);
}

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int num) {
    numerator = num;
    denominator = 1;
}

Rational::Rational(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    normalize();
}

int Rational::Numerator() const { return numerator; }
int Rational::Denominator() const { return denominator; }

Rational& Rational::operator+=(const Rational &x) {
    numerator = numerator * x.denominator + x.numerator * denominator;
    denominator *= x.denominator;
    normalize();
    return *this;
}
Rational& Rational::operator*=(const Rational &x) {
    numerator *= x.numerator;
    denominator *= x.denominator;
    normalize();
    return *this;
}
Rational& Rational::operator-=(const Rational &x) {
    numerator = numerator * x.denominator - x.numerator * denominator;
    denominator *= x.denominator;
    normalize();
    return *this;
}
Rational& Rational::operator/=(const Rational &x) {
    numerator *= x.denominator;
    denominator *= x.numerator;
    normalize();
    return *this;
}

Rational operator+(const Rational &a, const Rational &b) {
    return Rational(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
}
Rational operator*(const Rational &a, const Rational &b) {
    return Rational(a.numerator * b.numerator, a.denominator * b.denominator);
}
Rational operator-(const Rational &a, const Rational &b) {
    return Rational(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
}
Rational operator/(const Rational &a, const Rational &b) {
    return Rational(a.numerator * b.denominator, a.denominator * b.numerator);
}

bool operator==(const Rational &a, const Rational &b) {
    return (a.denominator == b.denominator and a.numerator == b.numerator);
}

bool operator!=(const Rational &a, const Rational &b) {
    return (a.denominator != b.denominator or a.numerator != b.numerator);
}

std::ostream &operator<<(std::ostream &fout, Rational &x) {
    fout << x.Numerator() << " " << x.Denominator() << "\n";
    return fout;
}

int main() { 
    Rational a, b(5, 2);
    Rational c = (a + 2) * b;
    std::cout << c << "\n";

    return 0; 
}