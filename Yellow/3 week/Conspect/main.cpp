#include <iostream>

using namespace std;

#include "rational.h"
#include "tests.h"


int main() {
  TestRunner runner;
  runner.RunTest(TestConstructor,"TestConstructor");

  Rational r(1, 2);
  cout <<  r.Numerator() << " / " << r.Denominator() << endl;

  return 0;
}
