#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVec(const vector<int>& v) {
    for (const auto& i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> v = {0, 1, 2, 3, 4};

    for (auto& i : v) {
        i++;
    }

    PrintVec(v);

    return 0;
}