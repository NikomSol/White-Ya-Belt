#pragma once
#include <iostream>
using namespace std;

class Rational {
public:
    Rational(int=0, int=0);
    int Numerator() const;
    int Denominator() const;

private:
    int GCD(int a, int b);

    int num;
    int denom;
};
