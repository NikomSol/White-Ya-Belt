#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Rational {
public:
Rational(int numerator = 0, int denominator = 1) {
    if (denominator == 0) {
        throw invalid_argument("Invalid argument");
    } else if (numerator == 0) {
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

int Numerator() const {
    return num;
}

int Denominator() const {
    return denom;
}

private:
int GCD(int a, int b) {
    while (b) {
        a %= b;
        swap (a, b);
    }
    return a;
}

int num;
int denom;
};

bool operator== (const Rational& lhs, const Rational& rhs) {
return ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator()));
}

bool operator< (const Rational& lhs, const Rational& rhs) {
return (lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator() < 0);
}

Rational operator+ (const Rational& lhs, const Rational& rhs) {
int numerator = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
int denominator = lhs.Denominator() * rhs.Denominator();
return Rational(numerator, denominator);
}

Rational operator- (const Rational& lhs, const Rational& rhs) {
int numerator = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
int denominator = lhs.Denominator() * rhs.Denominator();
return Rational(numerator, denominator);
}

Rational operator* (const Rational& lhs, const Rational& rhs) {
int numerator = lhs.Numerator() * rhs.Numerator();
int denominator = lhs.Denominator() * rhs.Denominator();
return Rational(numerator, denominator);
}

Rational operator/ (const Rational& lhs, const Rational& rhs) {
if (rhs.Numerator() == 0) {
    throw domain_error("Devizion by zero");
}
int numerator = lhs.Numerator() * rhs.Denominator();
int denominator = lhs.Denominator() * rhs.Numerator();
return Rational(numerator, denominator);
}

istream& operator>>(istream& stream, Rational& r) {
int numerator;
int denominator = 0;
stream >> numerator;
if (!stream) {
    return stream;
}
stream.ignore(1);
stream >> denominator;
if (!stream) {
    return stream;
}
r = Rational(numerator, denominator);
return stream;
}

ostream& operator<<(ostream& stream, const Rational& r) {
stream << r.Numerator() << '/' << r.Denominator();
return stream;
}

void Calculate(istream& input) {
    Rational r1, r2;
    char calc_operator;

    try {
        input >> r1;
        input >> calc_operator;
        input >> r2;

        if (calc_operator == '+') {
            cout << r1 + r2;
        } else if (calc_operator == '-') {
            cout << r1 - r2;
        } else if (calc_operator == '*') {
            cout << r1 * r2;
        } else if (calc_operator == '/') {
            cout << r1 / r2;
        } else {
            cout << "Invalid operator";
        }
        cout << endl;

    } catch (exception& ex) {
        cout << ex.what() << endl;
    }
}

int main() {
    // task 10
    {
        try {
            Rational r(1, 0);
            cout << "Doesn't throw in case of zero denominator" << endl;
            return 1;
        } catch (invalid_argument&) {
        }

        try {
            auto x = Rational(1, 2) / Rational(0, 1);
            cout << "Doesn't throw in case of division by zero" << endl;
            return 2;
        } catch (domain_error&) {
        }

        cout << "OK" << endl;
    }

    // task 11
    {
        stringstream input1("1/2 + 1/3");
        Calculate(input1);
        stringstream input2("1/2 + 5/0");
        Calculate(input2);
        stringstream input3("4/5 / 0/8");
        Calculate(input3);

    }

    return 0;
}
