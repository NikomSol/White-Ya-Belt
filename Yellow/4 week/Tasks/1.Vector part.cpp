#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define all(c) c.begin(), c.end()

template <typename It>
void PrintRange(It range_begin, It range_end) {
    for(auto i = range_begin; i != range_end; i++) {
        cout << *i << ' ';
    }
    cout << endl;
}

void PrintVectorPart(const vector<int>& numbers) {
    auto pos = find_if(all(numbers), 
                        [](const int& num) {
                        return num < 0;
                    });

    for (auto i = pos; i != numbers.begin(); i--) {
        cout << *(i-1) << ' ';
    }
    cout << endl;
}


int main() {
  PrintVectorPart({6, 1, 8, -5, 4}); // 8 1 6
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  PrintVectorPart({6, 1, 8, 5, 4}); // 4 5 8 1 6
  return 0;
}