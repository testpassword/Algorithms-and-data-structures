#include <map>
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<string, long long> cityAndMoney;		// Город и его капитализированные деньги
	unordered_map<string, long long> richmanAndMoney; 	// Богач и его сумма денег
	unordered_map<string, string> richmanAndCity; 		// Богач и его местоположение
	map<long long, set<string>> moneyAndCitiesSet;		// Деньги и города, с такой суммой
	map<string, int> citiesRank;						// Финальный топ городов
	long long money;
	string name, city;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> city >> money;
		richmanAndMoney[name] = money;	//заполнение карты связью {Богач-Деньги}
		richmanAndCity[name] = city;	//заполнение карты связью {Богач-Город}
		if (cityAndMoney.find(city) != cityAndMoney.end()) {
			/*
			Если город city существует, значит над ним мы проводим операцию не первый раз, значит его 
			капитализация изменится. Отчистим в карте {Капиталиция-Города} связь (её больше не будет существовать).
			*/
			long long sum = cityAndMoney[city]; 
			moneyAndCitiesSet[sum].erase(city);
			//Если города с такой капитализацией перестали существовать, отчистим и ячейку с множеством городов.
			if (moneyAndCitiesSet[sum].size() == 0) moneyAndCitiesSet.erase(sum);	
		}
		cityAndMoney[city] += money; //увеличение капитализации города
		moneyAndCitiesSet[cityAndMoney[city]].insert(city); //заносим город в множество городов с такой капитализацией
	}
	int days, movements, day, prevDay, currDay = 0;
	cin >> days >> movements;
	for (int i = 0; i <= movements; i++) { //вычислим капитализации для каждого из городов в разные дни
		prevDay = currDay;
		//Обрабатываем ситуацию последнего дня, когда ещё нужно менять параметры сущностей, но данные вводить уже не надо.
		if (i == movements) day = days; 
		else cin >> day >> name >> city;
		currDay = day;
		map<long long, set<string>>:: reverse_iterator it = moneyAndCitiesSet.rbegin();
		/*
		Если в отсортированном по ключам контейнере {Деньги-Список городов} в ячейке, соответствующей наибольшему ключу 
		только один элемент в {set<string>}, значит сейчас существует единственный город с максимальной суммой, и ему 
		нужно добавить дни в карту {Город-Количество дней в топе}.
		*/
		if (currDay != prevDay && it->second.size() == 1) citiesRank[*(it->second.begin())] += currDay - prevDay;
		if (i < movements) {
			/*
			Старое местоположение богача: если он уехал из города, необохдимо поменять соответствующую
			информацию во всех картах.
			*/
			string oldLocation = richmanAndCity[name];
			long long oldMoney = cityAndMoney[oldLocation];
			moneyAndCitiesSet[oldMoney].erase(oldLocation);
			if (moneyAndCitiesSet[oldMoney].size() == 0) moneyAndCitiesSet.erase(oldMoney);
			cityAndMoney[oldLocation] -= richmanAndMoney[name];
			moneyAndCitiesSet[cityAndMoney[oldLocation]].insert(oldLocation);
			/*
			Новое местоположение богача: если он приехал в новый город, необходимо поменять соответствующую
			информацию во всех картах.
			*/
			long long newMoney = cityAndMoney[city];
			moneyAndCitiesSet[newMoney].erase(city);
			if(moneyAndCitiesSet[newMoney].size() == 0) moneyAndCitiesSet.erase(newMoney);
			cityAndMoney[city] += richmanAndMoney[name];
			moneyAndCitiesSet[cityAndMoney[city]].insert(city);
			richmanAndCity[name] = city;
		}
	}
	for (const auto& c: citiesRank) cout << c.first << " " << c.second << endl; //вывод топа городов
   	return 0;
}

/*
Как таковой сложности в разрабатываемом алгоритме в задаче нет. Нам просто нужно аккуратно 
манипулировать всеми данными и поддерживать связь между ними. Первое делается в лоб в одном 
цикле по мере чтения данных, а вот второе уже сложнее. Связи должны поддерживатся между всеми 
сущностями: {Деньгами}, {Богачами}, {Городами}. Для них подходит структуры данных {map} или 
{unordered_map}, где одна из сущностей будет ключом, а другая - значением. Таких карт должно 
быть несколько, для всех необходимых связей.
*/