#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPalindrom(const string& word) {
    int len = word.length();
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - i -1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(const vector<string>& words, const int& minLength) {
    vector<string> solution = {};
    for (const auto& word : words) {
        if (IsPalindrom(word) && word.length() >= minLength) {
            solution.push_back(word);
        }
    }
    return solution;
}

ostream& operator<<(ostream& stream, const vector<string>& vs) {
    for (const auto& s : vs) {
            stream << s << ' ';
        }
    return stream;
}

void test(const vector<string>& words, const int& minLength, const vector<string>& output) {
    vector<string> solution = PalindromFilter(words, minLength);

    if (solution != output) {
        cout << "Test Failed" << endl;
        cout << "Solution: " << solution << endl;
        cout << "Expected: " << output << endl;
        cout << endl;
        } else {
        cout << "Test Passed" << endl;
        cout << endl;
    }
}


int main() {
    test({"abacaba", "aba"}, 5 , {"abacaba"});
    test({"abacaba", "aba"}, 2 , {"abacaba", "aba"});
    test({"weew", "bro", "code"}, 4 , {"weew"});

    return 0;
}
