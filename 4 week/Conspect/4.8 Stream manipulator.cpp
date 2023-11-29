#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void Print(const vector<string>& names, const vector<double>& values, const int& width) {
    for (const auto& name : names) {
        cout << setw(width)  << name << ' ';
    }
    cout << endl;

    cout << fixed << setprecision(2);
    for (const auto& value : values) {
        cout << setw(width) << value << ' ';
    }
    cout << endl;
}


int main() {
    vector<string> names = {"a", "b", "c"};
    vector<double> values = {1, 10, 0.00005};
    cout << setfill('.');
    cout << left;
    Print(names, values, 10);

    return 0;
}