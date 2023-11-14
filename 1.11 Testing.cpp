#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Return the minimum string of the three entered
    vector<string> vs = {"", "", ""};

    cin >> vs[0] >> vs[1] >> vs[2];

    sort(begin(vs), end(vs));

    cout << vs[0];

    return 0;
}