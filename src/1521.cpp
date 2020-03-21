#include <iostream>
using namespace std;

class FlavicksTree {

    private: 
        pair<int, int>* soldiers;
        int z = 1;
    
    public:
        FlavicksTree(int n) {
            soldiers = new pair<int, int>[4 * n];
    }

        void createNode(int v, int tl, int tr) {
            if (tl == tr) {
                soldiers[v] = make_pair(1, z++);
                return;
            }
            int tm = (tl + tr) / 2;
            createNode(2 * v, tl, tm); 
	        createNode(2 * v + 1, tm + 1, tr);
            soldiers[v].first = soldiers[2 * v].first + soldiers[2 * v + 1].first;
            soldiers[v].second = -1;
        }

        int modify(int v, int tl, int tr, int n) {
            if (tl == tr) {
                --soldiers[v].first;
                return soldiers[v].second;
            }
            int tm = (tl + tr) / 2;
            soldiers[v].first--;
            if (soldiers[2 * v].first >= n) modify(2 * v, tl, tm, n);
            else modify(2 * v + 1, tm + 1, tr, n - soldiers[2 * v].first);
        }
};

int main() {
    int n, k;
	cin >> n >> k;
    FlavicksTree* tree = new FlavicksTree(n);
    tree->createNode(1, 1, n);
    int current = k;
    for (int i = 0; i < n; i++) {
        int dead = tree->modify(1, 1, n, current);
        cout << dead << " ";
        if (i == n - 1) break;
        current = (current - 1 + k) % (n - 1 - i);
        if (current == 0) current += n - 1 - i;
    }
    return 0;
}

/*
Это модификация задачи Иосифа Флавия, с той лишь разницей, что вывести нужно не номер выжившего, а номера всех в порядке умерщвления. 
Для решения, попытаемся найти зависимость ответа от n (количества солдат) и k (разница между номера убийцы и убиваемого). 

      k 1 2 3 4 5 6 7 8 9 10    
    n
    1   1 1 1 1 1 1 1 1 1 1
    2   2 1 2 1 2 1 2 1 2 1
    3   3 3 2 2 1 1 3 3 2 2
    4   4 1 1 2 2 3 2 3 3 4
    5   5 3 4 1 2 4 4 1 2 4
    6   6 5 1 5 1 4 5 3 5 2
    7   7 7 4 2 6 3 5 4 7 5
    8   8 1 7 6 3 1 4 4 8 7
    9   9 3 1 1 8 7 2 3 8 8
   10  10 5 4 5 3 3 9 1 7 8

Видна закономерность решения: Jn,k = (J(n-1),k + k) % n
Значит, рекурсивная реализация, возвращающая номер выжившего, будет выглядеть так (асимптотика O(n)):

    int solve(int n, int k) {return n > 1 ? (joseph (n-1, k) + k - 1) % n + 1 : 1;}

Так-как нам нужно вывести не выжившего, а последовательность убывания, задача становится значительно сложнее. 
Всех солдат нужно хранить в какой-либо структуре данных. Нам придётся n раз проходить по кругу из солдат, 
из-за чего обычный массив отработает за O(n^2). Попробуем уменьшить количество операций алгоритма, 
воспользовавшись структурой данных - дерево отрезков, которое даст нам O(log(n)). Дерево можно реализовать 
в виде массиве, где каждая ячейка является узлом. На нулевом уровне дерева запросом затрагивается единственная вершина — 
корень дерева. Дальше на первом уровне рекурсивный вызов в худшем случае разбивается на два рекурсивных вызова, 
но важно здесь то, что запросы в этих двух вызовах будут соседствовать, т.е. число l'' запроса во втором рекурсивном 
вызове будет на единицу больше числа r' запроса в первом рекурсивном вызове. Отсюда следует, что на следующем уровне 
каждый из этих двух вызовов мог породить ещё по два рекурсивных вызова, но в таком случае половина этих запросов 
отработает нерекурсивно, взяв нужное значение из вершины дерева отрезков. Таким образом, всякий раз у нас будет не более 
двух реально работающих ветвей рекурсии (можно сказать, что одна ветвь приближается к левой границе запроса, а вторая 
ветвь — к правой), а всего число затронутых отрезков не могло превысить высоты дерева отрезков, умноженной на четыре, 
т.е. оно есть число O(log(n)).
Каждый узел дерева будет хранить 
номер убийцы, и номер убиваемого. При модификации будем получать номер нового убиваемого, и изменять узлы дерева. 
Сделать это нужно n раз, финальная сложность = O(n * log(n)). 
*/