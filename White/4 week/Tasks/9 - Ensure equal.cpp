#include <string>
#include <iostream>
#include <exception>
using namespace std;


void EnsureEqual(const string& left, const string& right) {
    if (left != right) {
        throw runtime_error(left + " != " + right);
    }
}

int main() {
    // EnsureEqual("left","right");
    EnsureEqual("left","left");

    return 0;
}