#include <vector>
// v.push_back()
// v.pop_back() - удаляет последний элемент
// v[i]
// Вектор долго удаляет из начала (сдвигает весь вектор)
// v.erase(begin(v)) 

// Двухсторонняя очередь
#include <deque>
// d.push_back(x)
// d.pop_back()
// d.push_front(x)
// d.pop_front() - удаляет первый элемент
// d[i]
// Больше возможностей - меньше оптимизация в целом


// Максимально ограниченная функциональность, нельзя даже итерироваться

// Очередь
#include <queue>
// q.push(x), q.pop() (добавить в конец, удалить из начала)
// q.front(), q.back() (обратиться к крайним элементам)
// q.size(), q.empty()

// Стек
#include <stack>
// st.push(x), st.pop() (добавть в один конец, удалить из конца)
// st.top() (обратиться к верхнему элементу)
// st.size(), st.empty()

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()

template <typename It>
void PrintRange(It range_begin, It range_end) {
    for(auto i = range_begin; i != range_end; i++) {
        cout << *i << "| ";
    }
    cout << endl;
}

int main() {
    deque<int> d = {2};
    
    d.push_back(3);
    d.push_front(1);
    PrintRange(all(d));
    d.pop_back();
    d.pop_front();
    PrintRange(all(d));

    return 0;
}