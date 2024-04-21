#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

// Классика:
// v.count(x) - количество элементов
// v.find(x) - найти элемент

// В отсортированном векторе есть алгоритмы с бинарным поиском:
// binary_search(all(v),x)
// equal_range(all(v),x)
// upper_bound(all(v),x)
// lower_bound(all(v),x)
// Определяют границы входжения элемента

// Для множества
// v.count(x)
// v.find(x)
// s.equal_range(x)
// s.upper_bound(x)
// s.lower_bound(x)