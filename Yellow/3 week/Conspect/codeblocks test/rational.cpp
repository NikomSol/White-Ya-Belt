#include "rational.h"

Rational::Rational(int numerator, int denominator) {
        if (numerator == 0) {
            num = 0;
            denom = 1;
        } else {
            int sign;
            if (numerator * denominator > 0) {
                sign = 1;
            } else {
                sign = -1;
            }
            int gcd = GCD(abs(numerator), abs(denominator));
            num = sign * abs(numerator) / gcd;
            denom = abs(denominator) / gcd;
        }
    }

int Rational::Numerator() const {
    return num;
}

int Rational::Denominator() const {
    return denom;
}

int Rational::GCD(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

