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

bool Gt2(int x) {
    if (x > 2) {
        return true;
    }
    return false;
}

int main() {
    cout << min(2, 3) << endl;
    cout << max(2, 3) << endl;
    
    vector<int> v = {1, 4 , 3, 5, 4};
    PrintVec(v);

    sort(begin(v), end(v));
    PrintVec(v);
    
    cout << count(begin(v), end(v), 4) << endl;
    cout << count_if(begin(v), end(v), Gt2) << endl;
    
    // lambda functions
    int th = 0;
    cin >> th;
    
    cout << count_if(begin(v), end(v), [th](int x) {
        if (x > th) {
            return true;
        }
        return false;
    });

    cout << endl;

    return 0;
}