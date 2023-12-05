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


int main() {
    // Part 1
    {
        {
            const Rational r(3, 10);
            if (r.Numerator() != 3 || r.Denominator() != 10) {
                cout << "Rational(3, 10) != 3/10" << endl;
                return 1;
            }
        }

        {
            const Rational r(8, 12);
            if (r.Numerator() != 2 || r.Denominator() != 3) {
                cout << "Rational(8, 12) != 2/3" << endl;
                return 2;
            }
        }

        {
            const Rational r(-4, 6);
            if (r.Numerator() != -2 || r.Denominator() != 3) {
                cout << "Rational(-4, 6) != -2/3" << endl;
                return 3;
            }
        }

        {
            const Rational r(4, -6);
            if (r.Numerator() != -2 || r.Denominator() != 3) {
                cout << "Rational(4, -6) != -2/3" << endl;
                return 3;
            }
        }

        {
            const Rational r(0, 15);
            if (r.Numerator() != 0 || r.Denominator() != 1) {
                cout << "Rational(0, 15) != 0/1" << endl;
                return 4;
            }
        }

        {
            const Rational defaultConstructed;
            if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
                cout << "Rational() != 0/1" << endl;
                return 5;
            }
        }

        cout << "OK" << endl;
    }
    
    // Part 2
    {
        {
            Rational r1(4, 6);
            Rational r2(2, 3);
            bool equal = r1 == r2;
            if (!equal) {
                cout << "4/6 != 2/3" << endl;
                return 1;
            }
        }

        {
            Rational a(2, 3);
            Rational b(4, 3);
            Rational c = a + b;
            bool equal = c == Rational(2, 1);
            if (!equal) {
                cout << "2/3 + 4/3 != 2" << endl;
                return 2;
            }
        }

        {
            Rational a(5, 7);
            Rational b(2, 9);
            Rational c = a - b;
            bool equal = c == Rational(31, 63);
            if (!equal) {
                cout << "5/7 - 2/9 != 31/63" << endl;
                return 3;
            }
        }

        cout << "OK" << endl;
    }

    // Part 3
    {
        {
            Rational a(2, 3);
            Rational b(4, 3);
            Rational c = a * b;
            bool equal = c == Rational(8, 9);
            if (!equal) {
                cout << "2/3 * 4/3 != 8/9" << endl;
                return 1;
            }
        }

        {
            Rational a(5, 4);
            Rational b(15, 8);
            Rational c = a / b;
            bool equal = c == Rational(2, 3);
            if (!equal) {
                cout << "5/4 / 15/8 != 2/3" << endl;
                return 2;
            }
        }

        cout << "OK" << endl;
    }

    // Part 4
    {
        {
            ostringstream output;
            output << Rational(-6, 8);
            if (output.str() != "-3/4") {
                cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
                return 1;
            }
        }

        {
            istringstream input("5/7");
            Rational r;
            input >> r;
            bool equal = r == Rational(5, 7);
            if (!equal) {
                cout << "5/7 is incorrectly read as " << r << endl;
                return 2;
            }
        }

        {
            istringstream input("5/7 10/8");
            Rational r1, r2;
            input >> r1 >> r2;
            bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
            if (!correct) {
                cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
                return 3;
            }

            input >> r1;
            input >> r2;
            correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
            if (!correct) {
                cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
                return 4;
            }
        }

        cout << "OK" << endl;
    }

    // Part 5
    {
        {
            const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
            if (rs.size() != 3) {
                cout << "Wrong amount of items in the set" << endl;
                return 1;
            }

            vector<Rational> v;
            for (auto x : rs) {
                v.push_back(x);
            }
            if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
                cout << "Rationals comparison works incorrectly" << endl;
                return 2;
            }
        }

        {
            map<Rational, int> count;
            ++count[{1, 2}];
            ++count[{1, 2}];

            ++count[{2, 3}];

            if (count.size() != 2) {
                cout << "Wrong amount of items in the map" << endl;
                return 3;
            }
        }

        cout << "OK" << endl;
    }

    return 0;
}
