// #include <cassert>
#include <iostream>
#include <exception>
#include <sstream>

using namespace std;

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        stringstream ss;
        ss << "Assertion failed: " << t << " != " << u << " Hint: " << hint;
        throw runtime_error(ss.str());
    }
}

void Assert(const bool& b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (runtime_error& ex) {
            ++fail_count;
            cerr << test_name << " FAIL: " << ex.what() << endl;
        }
    }

    ~TestRunner() {
        if (fail_count) {
            cerr << fail_count << " tests failed. Terminate.";
            exit(1);
        }
    }
private:
    int fail_count = 0;
};

int Sum(int x, int y) {
    return x + abs(y);
}

int Dif(int x, int y) {
    return x - y;
}

void TestSum () {
    AssertEqual(Sum(2, 3), 5, "#1");
    AssertEqual(Sum(-2, -3), -5, "#2");
    AssertEqual(Sum(-2, 3), 1, "#3");
}

void TestDif () {
    AssertEqual(Dif(2, 3), -1, "#1");
    AssertEqual(Dif(-2, -3), 1, "#2");
    AssertEqual(Dif(-2, 3), -5, "#3");
}

void TestAll () {
    TestRunner tr;
    tr.RunTest(TestSum, "TestSum");
    tr.RunTest(TestDif, "TestDif");

}

int main() {
    TestAll();
    
    cout << "Main output" << endl;

    return 0;
}