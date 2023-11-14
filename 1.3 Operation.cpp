#include <iostream>
#include <string>
using namespace std;


int main() {
    int x = 4;
    int y = 5;

    cout << (x - y) * (x + y) << "\n";

    if (x < y) {
        cout << "x < y\n";
    } else {
        cout << "x >= y\n";
    }

    string q = "aas";
    string p = "asd";

    if (q < p) {
        cout << "less\n";
    } else {
        cout << "not less\n";
    } //strings as a lecsicography

    return 0;
}