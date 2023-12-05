#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2) {
    First f = p1.first * p2.first;
    Second s = p1.second * p2.second;
    return make_pair(f, s);
}


template <typename T>
T Sqr(T x) {
    return x * x;
}

int main () {
    cout << Sqr(2.5) << endl;

    auto q = make_pair(2.5, 3);
    auto res = Sqr(q);
    cout << res.first << " " << res.second << endl;

    // В случае неопределленного типа в шаблонной функции его нужно указать
    cout << max<double>(2,3.5) << endl;

    return 0;
}