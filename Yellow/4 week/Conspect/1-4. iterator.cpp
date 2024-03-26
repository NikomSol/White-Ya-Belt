#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// using LangIt = vector<string>::iterator;

template <typename It>
void PrintRange(It range_begin, It range_end) {
    for(auto i = range_begin; i != range_end; i++) {
        cout << *i << ' ';
    }
}

int main() {
    vector <string> langs = {"Python", "C++", "C", "Java"};
    auto result = find_if(
        begin(langs), end(langs),
        [](const string& lang) {
            return lang[0] == 'C';
        });

    if (result != end(langs)) {
        // result - ссылка на строку
        // *result - достали саму строку
        // string s создали копию строки
        string s = *result;
        s = "D++";
        cout << s << " " << *result << endl;

        // string& ref ссылаемся на исходную строку и разименовываем?
        string& ref = *result;
        ref = "D++";
        cout << ref << " " << *result << endl;
    } else {
        cout << "Not found";
    }

    //begin - ссылка (итератор) на первый элемент контейнера
    //end - ссылка (итератор) на что-то после последнего элемента
    // По итератору можно делать ++ --, выход за бегин енд может привести к развалу программы
    string ss = "qwa";
    auto it = begin(ss);
    cout << *it << endl;
    ++it;
    cout << *it << endl;
    it = end(ss);
    cout << *it << endl;

    // Подтип типа
    for (string::iterator iter = begin(ss); iter < end(ss); ++iter) {
        cout << *iter << endl;
    }

    // universal conteiner print
    PrintRange(begin(langs), end(langs));
    PrintRange(begin(ss), end(ss));


    return 0;
}