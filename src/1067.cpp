#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class Dir {

	private: map<string, Dir*> childDirs;
	
	public:
		Dir() {}

		Dir* getDir(string name) {
			if (childDirs.find(name) != childDirs.end()) return childDirs[name];
			else return createDir(name);
		}

		Dir* createDir(string name) {
			childDirs[name] = new Dir();
			return childDirs[name];
		}

		void printTree(string separator = "") {
			string tabs = " ";
			tabs += separator;
			map<string, Dir*> contents(childDirs.begin(), childDirs.end());
			for (auto it = contents.begin(); it != contents.end(); it++) {
				cout << separator << it->first << endl;
				it->second->printTree(tabs);
			}
		}
};

int main() {
	int n;
	cin >> n;
	Dir* root = new Dir();
	for (int i = 0; i < n; i++) {
		Dir* currentDir = root;
		string fullPath, name;
		cin >> fullPath;
		stringstream ss(fullPath);
		while (getline(ss, name, '\\')) 
			currentDir = currentDir->getDir(name); //здесь '\\' - это экраннированный символ '\'
	}
	root->printTree();
	return 0;
}

/*
Нужно построить и вывести дерево каталогов, по аналогии с командой 'tree'. Самый простой вариант - 
сохранить все строки в массив, парсить по первому символу '\' и создавать новую цепочку в связанном списке. 
Но это крайне тяжёлый и долгий для компьютера способ. Нам необходимо создавать нужную строктуру каталогов 
"на лету" - сразу всё структуру для полученной строки. Так-как файловая система представляет из себя 
древовидную структуру, будет удобно использовать Map, где ключом выступит имя каталога, а значением - 
вложенные каталоги. 
1. Создадим объект Dir. Он будет инкапсулировать методы создания, получения, вывода директорий. 
2. Получим из исходной строки fullPath строку name, представляющую полный путь к каталогу и часть имени, до первого вхождения '\'. 
3. Проверим, существует ли в текущем каталоге (изначально он будет корневым), директория с именем name. 
	Если "нет" - создадим, если "да", сделаем её текущим каталогом и получим следующую часть fullPath до символа '\'. 
4. Когда дерево для fullPath будет полностью заполнено, мы снова вернёмся в корень нашей "файловой системы", и повторим 
	пункты 1-3 для новой fullPath. 
Теперь надо вывести полученную структуру. Для этого, будем рекурсивно опускаться вглубь каждой директории, 
наращивая на каждом уровне количество пробельный отступов.
*/