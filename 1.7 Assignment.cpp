#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Глубокое копирование в C++
    string s = "hello";
    string t = s;
    
    t += ", world";

    cout << "s = " << s << endl;
    cout << "t = " << t << endl;

    vector<string> w = {"a", "b", "c"};
    vector<string> v;

    v = w;
    v[0] = "d";

    cout << "w[0] = " << w[0] << endl;
    cout << "v[0] = " << v[0] << endl;

    return 0;
}