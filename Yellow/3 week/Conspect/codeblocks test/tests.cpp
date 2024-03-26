#include "tests.h"

void TestConstructor() {
  {
    Rational r;
    AssertEqual(r.Numerator(), 0, "0");
    AssertEqual(r.Denominator(), 1, "1");
  }
  {
    Rational r(1, 1);
    AssertEqual(r.Numerator(), 1, "2");
    AssertEqual(r.Denominator(), 1, "3");
  }
  {
    Rational r(1, -1);
    AssertEqual(r.Numerator(), -1, "4");
    AssertEqual(r.Denominator(), 1, "5");
  }
  {
    Rational r(-1, -1);
    AssertEqual(r.Numerator(), 1, "4");
    AssertEqual(r.Denominator(), 1, "5");
  }
  {
    Rational r(30, 99);
    AssertEqual(r.Numerator(), 10, "6");
    AssertEqual(r.Denominator(), 33, "7");
  }
  {
    Rational r(0, 99);
    AssertEqual(r.Numerator(), 0, "8");
    AssertEqual(r.Denominator(), 1, "9");
  }
}
