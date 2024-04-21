#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> result;

    auto start = s.begin();

    while (start != s.end()) {
        auto stop = find(next(start), s.end(), ' ');
        result.push_back({next(start), stop});
        start = stop;
    }

    return result;   
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  //out: С/Cpp/Java/Python
  
  return 0;
}