#include <iostream>
#include <numeric>

class Rational {
    private:
        int numerator;
        int denominator;

        void normalize();

    public:
        Rational();
        Rational(int& numerator, int& denominator);

        int Numerator() const;
        int Denominator() const;

        Rational &operator+=(Rational &x);
        Rational &operator-=(Rational &x);
        Rational &operator*=(Rational &x);
        Rational &operator/=(Rational &x);
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

Rational::Rational(int& numerator, int& denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

int Rational::Numerator() const { return numerator; }
int Rational::Denominator() const { return denominator; }

Rational& Rational::operator+=(Rational &x) {
    numerator = numerator * x.denominator + x.numerator * denominator;
    denominator *= x.numerator;
    normalize();
    return *this;
}

int main() { return 0; }