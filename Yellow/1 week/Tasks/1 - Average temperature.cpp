#include <iostream>
#include <vector>
#include <sstream>
#include <cstdint>

using namespace std;

int main() {
    // stringstream cin("5 100000000 100000000 -100000000 100000000 -100000000");
    stringstream cin("5 5 4 1 -2 7");

    int n;
    cin >> n;

    vector<int> data(n);
    int64_t sum = 0;
    for(int i = 0; i < n; i++) {
        int buf;
        cin >> buf;
        data[i] = buf;
        sum += buf;
    }


    int average = sum / 5;
    
    vector<int> high_temp = {};
    int counter = 0;
    for(int i = 0; i < n; i++) {
        if (data[i] > average) {
            high_temp.push_back(i);
            counter ++;
        }
    }

    cout << counter << endl;
    for(int item : high_temp) {
        cout << item << ' ';
    }

    return 0;
}