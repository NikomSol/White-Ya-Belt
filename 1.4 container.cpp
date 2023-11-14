#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    string s = "abcdefg";
    for (char c : s) {
        cout << c << ", ";
    }

    vector<int> nums = {1, 5, 3, 4, 5};
    for (auto c : nums) {
        cout << c << ", ";
    }

    // algorithm
    
    // int quantity = 0;
    // for (auto i : nums) {
    //     if (i == 5) {
    //         quantity += 1;
    //     }
    // }

    int quantity = count(begin(nums), end(nums), 5);
    cout << "\n" << quantity  << "\n";

    sort(begin(nums), end(nums));
    for (auto c : nums) {
        cout << c << ", ";
    }

    return 0;
}