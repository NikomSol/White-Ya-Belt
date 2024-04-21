#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <string>
using namespace std;
 
int main()
{
    int N;
    cin >> N;

    string s;
    for (int i = N; i > 0; i--) {
        s += to_string(i);
    }

    do
    {
        cout << s << endl;
    }
    while (prev_permutation(s.begin(), s.end()));

}