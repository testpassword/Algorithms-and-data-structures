#include <iostream>
using namespace std;

int main() {
    int t;
    long n, k, teamSize, remnant;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        teamSize = n / k;
        remnant = n % k;
        cout << ((k - remnant) * teamSize * (n - teamSize) + remnant * (teamSize + 1) * (n - (teamSize + 1))) / 2 << endl;
    }
    return 0;
}

/*
Так как бойцы сражаются "стенка на стенку", необходимо найти, сколько людей в "стенке" у нас будет. n и k даны, значит 
количество людей в команде = n / k. В частном случае задача сводится к простой комбинаторике: каждая команда может 
сразиться с каждой, но без повторений. Сложности же задачи добавляет тот факт, что n % k не всегда = 0, а значит надо 
как-то раскидать по командам оставшихся людей.
*/