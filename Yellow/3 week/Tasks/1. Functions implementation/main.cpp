#include "sum_reverse_sort.h"
#include <iostream>

using namespace std;

int main() {

    cout << Sum(1, -2) << endl;
    cout << Reverse("abs") << endl;

    vector<int> nums = {1, 5, 3, 4, 5};
    Sort(nums);
    for(auto i : nums) {
        cout << i;
    }
    cout << endl;

    return 0;
}