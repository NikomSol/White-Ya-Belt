#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> result;

    auto it = copy_if(elements.begin(), elements.end(), back_inserter(result),
    [border] (const T& element) {
        return (element > border);
    });

    return result;
}

// template < class T >
// std::vector < T > FindGreaterElements(const std::set < T > &elements, const T &border) {
//     return {std::upper_bound(elements.begin(), elements.end(), border), elements.end()};
// }


int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;
  
  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}