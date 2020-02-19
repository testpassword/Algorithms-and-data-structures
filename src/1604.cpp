#include <iostream>
using namespace std;

void quickSort(pair<int,int> array[], int left, int right) {
    int i = left, j = right;
    int pivot = array[(left + right) / 2].first;
    while(i <= j) {
        while (array[i].first < pivot) i++;
        while (array[j].first > pivot) j--;
        if (i > j) break;
        int t = array[i].first;
        array[i].first = array[j].first;
        array[j].first = t;
        i++;
        j--;
    }
    if (left < j) quickSort(array, left, j);
    if (i < right) quickSort(array, i, right);
}

int main() {
    int k, sum = 0;
    cin >> k;
    pair<int, int> signs[k];
    for (int i = 0; i < k; i++) {
        signs[i].first = i + 1;
        cin >> signs[i].second;
        sum += signs[i].second;
    }
    quickSort(signs, 0, k-1);
    
    return 0;
}