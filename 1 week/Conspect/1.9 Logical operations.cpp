#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    map<string, int> a;
    a["wne"] = 10;
    map<string, int> b;
    b["two"] = 2;

    // Comparison with key
    if (a > b) {
        cout << "a > b";
    } else if (a < b) {
        cout << "a < b";
    } else {
        cout << "a == b";
    }
    
    return 0;
}