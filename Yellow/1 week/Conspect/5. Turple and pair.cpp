#include <iostream>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

int main() {
    tuple <int, string, bool> s(7, "C++", true);
    
    tuple p(7, "C++", true); // Так тоже можно
    
    auto t = make_tuple(7, "C++", true);
    cout << get<1>(t) << endl;
    // tie - кортеж из ссылок, make_tuple - кортеж из значений
    
    // Желательно писать свою структуру

    pair q(7, "C++");
    cout << q.first << " " << q.second << endl;

    return 0;
}