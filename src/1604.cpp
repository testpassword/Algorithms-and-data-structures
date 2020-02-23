#include <iostream>
using namespace std;

struct SignBox {
	int amount;
	int index;
};

pair<int, int> findCurrentPair(SignBox array[], int k) {
	static pair<int, int> currentPair = make_pair(0, 0);
	int minAmount = INT_MAX, maxAmount = INT_MIN;
	for(int i = 0; i < k; i++) {
		if (array[i].amount > 0) {
			if (array[i].amount >= maxAmount) {
				maxAmount = array[i].amount;
				currentPair.second = i;
			}
			if (array[i].amount < minAmount) {
				minAmount = array[i].amount;
				currentPair.first = i;
			}
		}
	}
	return currentPair;
}

int main() {
	int k, minAmount = INT_MAX, maxAmount = INT_MIN, amountOfSigns = 0;
	cin >> k;
	SignBox signs[k];
	for (int i = 0; i < k; i++) {
		cin >> signs[i].amount;
		signs[i].index = i + 1;
		amountOfSigns += signs[i].amount;
	}
	pair<int, int> signsPair;
	while (amountOfSigns > 0) {
		signsPair = findCurrentPair(signs, k);
		if (signs[signsPair.second].amount > 0) {
			cout << signs[signsPair.second].index << " ";
			signs[signsPair.second].amount--;
			amountOfSigns--;
		}
		if (signs[signsPair.first].amount > 0) {
			cout << signs[signsPair.first].index << " ";
			signs[signsPair.first].amount--;
			amountOfSigns--;
		}
	}
	return 0;
}

/*
По условию задачи, нам необходимо расставить дорожные знаки так, чтобы в полученной последовательности было 
как можно меньше знаков одного типа рядом. Тогда с большей вероятностью водитель не успеет переключить скорость 
и заплатит штраф Бульдогу-полицейскому. Создадим отдельную структуру для удобного хранения информации о знаках - 
SignBox - объект-обёртка, содержащая количество знаков определённого типа и их порядковый номер (можно использовать 
и объект pair, но это сделает код менее читаемым). Теперь попытается понять, как нужно расставлять знаки. 
Пусть S - суммарное количество экземпляров всех знаков, a - количество экземпляров одного любого знака, тогда, 
если количество экземпляров одного знака - (a > s/2 + 1), то знаки где-то в последовательности всё же будут повторяться. 
Чтобы избежать этого в случайном месте результирующей последовательности, имеет смысл работать ставить знак сначала 
с amax, потом с минимальным amin, в таком случае, повторения в последовательности могут быть только после того, как 
закончатся все a < amax. Сделать это можно двумя способами: 
А. Отсортировать массив типа SignBox по количеству экземпяров знака и брать элементы с концов этого массива. 
B. Пока не кончились экземпляры знаков, находить знак с amin и amax, и ставить их в последовательность. 
Я реализовал вариант B, потому что мне это показалось чуть-чуть проще, а полученный результат всё равно проходит 
по времени и памяти.
*/