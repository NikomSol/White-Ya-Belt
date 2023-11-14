#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main () {
    // map<string, int> b = {{"a", 1},{"b", 2}, {"c", 3}};
    
    // int sum = 0;
    // string concat = "";

    // for (auto i : b) {
    //     concat += i.first;
    //     sum += i.second;
    // }

    // cout << concat << endl;
    // cout << sum << endl;

    string a = "sdfasfsadfasdf";
    int i = 0;

    for (auto c : a) {
        if (c == 'a') {
            cout << i << endl;
        }
        i++;
    }

    for (int j = 0; j < a.size(); j++) {
        if (a[j] == 'a') {
            cout << j << endl;
            break;
        }
    }

    return 0;
}