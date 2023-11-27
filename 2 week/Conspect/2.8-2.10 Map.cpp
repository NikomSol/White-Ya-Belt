#include <iostream>
#include <map>
#include <vector>

using namespace std;

void PrintMap1(const map<int, string>& m) {
    cout << "Size = " << m.size() << endl;
    for (const auto& item : m) {
        cout << item.first << ": " << item.second << endl;
    }
}

void PrintMap2(const map<string, int>& m) {
    cout << "Size = " << m.size() << endl;
    for (const auto& [key, value] : m) {
        cout << key << ": " << value << endl;
    }
}

void PrintMap3(const map<char, vector<string>>& m) {
    cout << "Size = " << m.size() << endl;
    for (const auto& item : m) {
        cout << item.first << ": " << item.second[0] << endl;
    }
}

int main() {
    // map<int, string> event;
    // event[1950] = "BS birth";
    // event[1941] = "DR birth";
    // event[1970] = "UNIX epoch start";
    // PrintMap1(event);

    // cout << event[1950] << endl;

    // event.erase(1970);
    // PrintMap1(event);


    vector<string> words = {"one", "two", "one", "three"};

    map<string, int> counters;
    for (const string& word : words) {
        ++counters[word];
    }
    PrintMap2(counters);

    // map<char, vector<string>> group;
    // for (const string& word : words) {
    //     group[word[0]].push_back(word);
    // }
    // PrintMap3(group);

    return 0;
}