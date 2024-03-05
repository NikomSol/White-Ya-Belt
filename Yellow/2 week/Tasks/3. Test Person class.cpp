#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

//Testing framework

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

//Class

class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name) {
  }
  void ChangeLastName(int year, const string& last_name) {
  }
  string GetFullName(int year) {
  }
};

//Tests
void TestIncognito () {
  Person p;
  AssertEqual(p.GetFullName(0),"Incognito","1");
  p.ChangeFirstName(1000, "Nik");
  AssertEqual(p.GetFullName(0),"Incognito","2");
  p.ChangeLastName(2000, "Kov");
  AssertEqual(p.GetFullName(0),"Incognito","3");
}

void TestFirstName () {
  Person p;
  AssertEqual(p.GetFullName(2000),"Incognito","1");
  p.ChangeFirstName(1000, "Nik");
  AssertEqual(p.GetFullName(2000),"Nik with unknown last name","2");
  p.ChangeFirstName(3000, "Nikom");
  AssertEqual(p.GetFullName(2000),"Nik with unknown last name","2");

  p.ChangeLastName(1000, "Kov");
  AssertEqual(p.GetFullName(0),"Nik Kov","3");
}

void TestLastName () {
  Person p;
  AssertEqual(p.GetFullName(2000),"Incognito","1");
  p.ChangeLastName(1000, "Nik");
  AssertEqual(p.GetFullName(2000),"Nik with unknown first name","2");
  p.ChangeLastName(3000, "Nikom");
  AssertEqual(p.GetFullName(2000),"Nik with unknown first name","2");

  p.ChangeFirstName(1000, "Kov");
  AssertEqual(p.GetFullName(0),"Kov Nik","3");
}


int main() {
  TestRunner runner;
  runner.RunTest(TestIncognito, "TestIncognito");
  runner.RunTest(TestLastName, "TestLastNameo");
  runner.RunTest(TestFirstName, "TestFirstName");

  return 0;
}
