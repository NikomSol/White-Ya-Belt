#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()

template <typename It>
void PrintRange(It range_begin, It range_end) {
    for(auto i = range_begin; i != range_end; i++) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    vector <string> langs = {"Python", "C++", "C", "Java", "C#"};
    PrintRange(all(langs));

    auto it = find(all(langs), "C++");
    
    langs.erase(it, --end(langs));
    PrintRange(all(langs));
    
    langs.insert(begin(langs), "C++");
    PrintRange(all(langs));

    langs.insert(++begin(langs), 4, "D++");
    PrintRange(all(langs));

    langs.insert(--end(langs), {"Kek", "Mek", "Cheburek"});
    PrintRange(all(langs));
    PrintRange(rall(langs));

    // алгоритмы, принимающие итераторы не меняют размер контейнера
    // а только перемещают элементы в нем
    it = remove_if(all(langs),
            [](const string& lang) {
                return lang.back() == 'k';
            });
    langs.erase(it, end(langs));
    PrintRange(all(langs));

    it = unique(all(langs));
    langs.erase(it, end(langs));
    PrintRange(all(langs));

    it = min_element(all(langs));
    cout << *it << endl;

    auto p = minmax_element(all(langs));
    cout << *p.first << ' ' << *p.second << endl;

    cout << all_of(all(langs),
              [](const string& lang) {
                return lang[0] >= 'A' && lang[0] <= 'Z';
            });

    return 0;
}