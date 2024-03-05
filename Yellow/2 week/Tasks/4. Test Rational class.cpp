#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

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

int main() {
  TestRunner runner;
  runner.RunTest(TestConstructor,"TestConstructor");

  return 0;
}
