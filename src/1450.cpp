#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct GasPipeline {
    int from, to, price;
};

int main() {
    int n, m;
    cin >> n >> m;
    GasPipeline wires[m];
    int res[n * n];
    fill_n(res, n * n, -1);
    for (int i = 0; i < m; i++) cin >> wires[i].from >> wires[i].to >> wires[i].price;
    int s, f;
    cin >> s >> f;
    res[s] = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            if (res[wires[j].from] != -1 && res[wires[j].to] < res[wires[j].from] + wires[j].price)
                res[wires[j].to] = res[wires[j].from] + wires[j].price;
    if (res[f] != -1) cout << res[f];
    else cout << "No solution";
    return 0;
}

/*
Задача на алгоритм Дейкстры, с той лишь разницей, что нужно вывести не минимальный путь от a до b, а максимальный. 
Выделим память под массив res, который будет содержать путь от выделенной вершины s до всех остальных вершин V 
взвешенного ориентированного графа G = (V, E). Изначально res[s] = 0 - это значит, что путь из s в f пока ещё = 0, 
но необходимо для старта алгоритма, а для остальных вершин это длина равна заведомо невозможному минимальному числу (-inf или -1). 
Для облегчения понимания кода создадим структуру GasPipeline, содержащую ребро графа e = {u, v} и его вес, 
чтобы в явном виде не хранить массив предков являющейся предпоследней в длиннейшем пути до вершины v. 
Найдём для узла s самое большое ребро из узлов {s + 1}, и пересчитаем стоимость соседей этого узла. 
Повторим так для каждого, и в конце получим элементов res[f], который будет содержать сумму рёбер от s до f 
(если res[f] == -1, значит f оказалась непосешённой, следовательно до неё не добраться из s). 
Доказательство алгоритма таково: для вершины s имеем res[s] = 0, что и является длиной кратчайшего пути до неё. 
Пусть теперь это утверждение выполнено для всех предыдущих итераций, т.е. всех уже помеченных вершин; 
докажем, что оно не нарушается после выполнения текущей итерации. Пусть v — вершина, которую алгоритм собирается пометить на текущей итерации. 
res[v] = l[v], где l[v] - длине кратчайшего пути до res[v]. Рассмотрим кратчайший путь P до вершины v. Этот путь можно разбить на два пути: 
p1, состоящий только из помеченных вершин, и p2 - остальная часть пути. res[p1] = l[p1], ведь на одной из прошлых итераций мы перебирали 
вершины из p2. Вследствие не отрицательности стоимостей рёбер длина кратчайшего пути l[p2] не превосходит длины l[v] кратчайшего пути до вершины v. 
Учитывая, что l[v] <= res[v] получаем: d[p2] = l[p2] <= l[v] <= d[v]. Поскольку p2 и v — вершины непомеченные, то так как на текущей итерации 
была выбрана именно вершина v, а не вершина p, то получаем: d[p2] >= d[v] => d[p2] = d[v] => d[v] = l[v].
*/