#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()

template <typename It>
void PrintRange(It range_begin, It range_end) {
    for(auto i = range_begin; i != range_end; i++) {
        cout << *i << "| ";
    }
    cout << endl;
}

// Есть итераторы, которые умеют только ссылаться на элемент
// Есть итераторы, которые умеют только добавлять элемент

// Типы в документации:
// Input - итераторы любых контейнеров
// Output - векторов и строк, inserter, back_inserter
// Forward, Bidir - любые (кроме set map если нужно менять)
// Random - итераторы векторов и строк (т.к. там можно прибавлять и вычитать)

int main() {
    vector <string> langs = {"Python", "C++", "C", "Java", "C#"};
    PrintRange(all(langs));

    // Перемещаем элементы удовлетворяющие условию в начало
    auto it = partition(all(langs),
              [](const string& lang) {
                return lang[0] == 'C';
            });
    cout << (it - begin(langs)) << endl;
    PrintRange(all(langs));

    // Копируем элементы удовлетворяющие условию
    vector <string> langs_c(langs.size());
    auto it2 = copy_if(all(langs), begin(langs_c),
                    [](const string& lang) {
                        return lang[0] == 'C';
                    });
    cout << (it2 - begin(langs_c)) << endl;
    // Возвращает итератор на конец нового вектора
    langs_c.erase(it2, end(langs_c));
    PrintRange(all(langs_c));

    // Копируем элементы удовлетворяющие условию, не задавая длины массива
    // Используем специальный итератор, для добавления в конец контейнера
    vector <string> langs_c2;
    auto it4 = copy_if(all(langs), back_inserter(langs_c2),
                    [](const string& lang) {
                        return lang[0] == 'C';
                    });
    PrintRange(all(langs_c2));

    // Поиск пересечения множеств 
    set<int> a = {1, 8, 3};
    set<int> b = {3, 6, 8};
    vector<int> v(a.size());
    auto it3 = set_intersection(all(a), all(b), begin(v));
    v.erase(it3, end(v));
    PrintRange(all(v));

    // inserter добавляет в определенное место контейнера
    set<int> c;
    set_intersection(all(a), all(b), inserter(c, end(c)));
    PrintRange(all(c));

    // next указывает на следующий элемент, не изменяя значения итератора
    auto it5 = b.find(6);
    cout << *it5 << ' ' << *next(it5) << endl;

    return 0;
}