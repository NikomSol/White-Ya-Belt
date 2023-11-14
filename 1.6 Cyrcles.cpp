#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    /* str1
     * str2
     * str3 */

    vector<int> nums = {1, 2, 3, 4, 5};
    int sum1 = 0;

    for (auto x : nums) {
        sum1 += x;
    }

    int n = 5;
    int sum2 = 0;

    for (int i = 1; i <= n; ++i) {
        sum2 += i;
    }

    int i = 1;
    int sum3 = 0;
    
    while (i <= n) {
        sum3 += i;
        i++;
    }

    cout << sum1 << ' ' << sum2 << ' ' << sum3 <<'\n';

    return 0;
}