#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int a = 11;
    int b = 3;
    double c = 3;

    cout << a/b << ' ' << a/c << ' ' << c/a << endl;

    int x = 5;
    int y = x++; // y = x, x++
    int z = ++x; // x++, z = x

    cout << y << ' ' << z << endl;


}