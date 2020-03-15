# Введение в алгориты #
## 1005. Куча камней ##
https://acm.timus.ru/problem.aspx?space=1&num=1005

>   Ограничение времени: 1.0 секунды   
    Ограничение памяти: 64 МБ

У вас есть несколько камней известного веса w1, …, wn. Напишите программу, которая распределит камни в две кучи так, что разность весов этих двух куч будет минимальной.

### Исходные данные ###
Ввод содержит количество камней n (1 ≤ n ≤ 20) и веса камней w1, …, wn (1 ≤ wi ≤ 100 000) — целые, разделённые пробельными символами.

### Результат ###
Ваша программа должна вывести одно число — минимальную разность весов двух куч.

### Пример ###
| исходные данные | результат |
|-----------------|-----------|
| 5               |           |
| 5 8 13 27 14    | 3         |

## 1296. Гиперпереход ##
https://acm.timus.ru/problem.aspx?space=1&num=1296

>   Ограничение времени: 1.0 секунды   
    Ограничение памяти: 64 МБ

Гиперпереход, открытый ещё в начале XXI-го века, и сейчас остаётся основным способом перемещения на расстояния до сотен тысяч парсеков. Но совсем недавно физиками открыто новое явление. Оказывается, длительностью альфа-фазы перехода можно легко управлять. Корабль, находящийся в альфа-фазе перехода, накапливает гравитационный потенциал. Чем больше накопленный гравитационный потенциал корабля, тем меньше энергии потребуется ему на прыжок сквозь пространство. Ваша цель — написать программу, которая позволит кораблю за счёт выбора времени начала альфа-фазы и её длительности накопить максимальный гравитационный потенциал.
В самой грубой модели грави-интенсивность — это последовательность целых чисел pi. Будем считать, что если альфа-фаза началась в момент i и закончилась в момент j, то накопленный в течение альфа-фазы потенциал — это сумма всех чисел, стоящих в последовательности на местах от i до j.

### Исходные данные ###
В первой строке входа записано целое число N — длина последовательности, отвечающей за грави-интенсивность (0 ≤ N ≤ 60000). Далее идут N строк, в каждой записано целое число pi (−30000 ≤ pi ≤ 30000).

### Результат ###
Максимальный гравитационный потенциал, который может накопить корабль в альфа-фазе прыжка. Считается, что потенциал корабля в начальный момент времени равен нулю.

### Примеры ###
| исходные данные                   | результат |
|-----------------------------------|-----------|
| 10                                |           |
| 31 -41 59 26 -53 58 97 -93 -23 84 | 187       |
|___________________________________|___________|
| 3                                 |           |
| -1 -5 -6                          | 0         |

## 2025. Стенка на стенку ##
https://acm.timus.ru/problem.aspx?space=1&num=2025

>   Ограничение времени: 1.0 секунды   
    Ограничение памяти: 64 МБ

Бокс, каратэ, самбо… Классические боевые единоборства пресытили аудиторию. Поэтому известный спортивный канал запускает новый формат соревнований, основанный на традиционной русской забаве — боях стенка на стенку. В соревновании могут участвовать от двух до k команд, каждая из которых будет соперничать с остальными. Всего в соревновании примут участие n бойцов. Перед началом боя они должны разделиться на команды, каждый боец должен войти ровно в одну команду. За время боя два бойца сразятся, если они состоят в разных командах. Организаторы считают, что популярность соревнований будет тем выше, чем больше будет количество схваток между бойцами. Помогите распределить бойцов по командам так, чтобы максимизировать количество схваток между бойцами, и выведите это количество.

### Исходные данные ###
В первой строке дано количество тестов T (1 ≤ T ≤ 10). В следующих T строках перечислены тесты. 
В каждой из них записаны целые числа n и k через пробел (2 ≤ k ≤ n ≤ 104).

### Результат ###
Для каждого теста в отдельной строке выведите одно целое число — ответ на задачу.

### Пример ###
| исходные данные | результат |
|-----------------|-----------|
| 3               |           |
| 6 3             | 12        |
| 5 5             | 10        |
| 4 2             | 4         |

# Сортировка #

## 1207. Медиана на плоскости ##
https://acm.timus.ru/problem.aspx?space=1&num=1207

>   Ограничение времени: 0.5 секунды   
    Ограничение памяти: 64 МБ

На плоскости находятся N точек (N чётно). Никакие три точки не лежат на одной прямой. Ваша задача — выбрать две точки так, что прямая линия, проходящая через них, делит множество точек на две части одинакового размера.

### Исходные данные ###
Первая строка содержит целое число N (4 ≤ N ≤ 10 000). Каждая из следующих N строк содержит пары целых чисел xi, yi (−106 ≤ xi, yi ≤ 106) — координаты i-й точки.

### Результат ###
Выведите номера выбранных точек.

### Пример ###
| исходные данные| результат|
|----------------|----------|
| 4              | 1 4      |
| 0 0            |          |
| 1 0            |          |
| 0 1            |          |
| 1 1            |          |

## 1604. В стране дураков ##
https://acm.timus.ru/problem.aspx?space=1&num=1604

>   Ограничение времени: 1.0 секунды   
    Ограничение памяти: 64 МБ

Главный бульдог-полицейский Страны Дураков решил ввести ограничение скоростного режима на автомобильной трассе, ведущей от Поля Чудес к пруду Черепахи Тортиллы. Для этого он заказал у Папы Карло n знаков ограничения скорости. Папа Карло слабо разбирался в дорожном движении и поэтому изготовил знаки с разными ограничениями на скорость: 49 км/ч, 34 км/ч, 42 км/ч, и т.д. Всего получилось k различных ограничений: n1 знаков с одним ограничением, n2 знаков со вторым ограничением, и т.д. (n1 + … + nk = n) Бульдог-полицейский ничуть не расстроился, получив такие знаки, напротив, он решил извлечь из этого экономическую выгоду. Дело в том, что по Правилам дорожного движения Страны Дураков ограничение на скорость действует вплоть до следующего знака. Если на знаке написано число 60, это означает, что участок от данного знака до следующего нужно проехать ровно со скоростью 60 километров в час — не больше и не меньше. Бульдог распорядился расставить знаки так, чтобы обогатившимся на Поле Чудес автолюбителям во время своего движения по трассе приходилось как можно больше раз менять скорость. Для этого нужно расставить имеющиеся знаки в правильном порядке. Если Вы поможете бульдогу это сделать, то он готов будет поделиться с Вами частью своих доходов.

### Исходные данные ###
В первой строке дано число k — количество различных типов знаков с ограничением скорости (1 ≤ k ≤ 10000). Во второй строке через пробел перечислены целые положительные числа n1, …, nk. Сумма всех ni не превосходит 10000.

### Результат ###
Выведите n целых чисел в пределах от 1 до k — порядок, в котором нужно расставить по трассе имеющиеся знаки. Вне зависимости от того, какой знак стоит первым, считается, что, проезжая его, водитель меняет скорость, так как до этого ограничения не действовали. Если задача имеет несколько решений, выведите любое.

### Пример ###
| исходные данные| результат|
|----------------|----------|
| 2              |          |
| 2 2            | 2        |

## 1726. Кто ходит в гости… ##
https://acm.timus.ru/problem.aspx?space=1&num=1726

>   Ограничение времени: 1.0 секунды   
    Ограничение памяти: 64 МБ

Программный комитет школьных соревнований по программированию, проходящих в УрГУ — многочисленная, весёлая и дружная команда. Дружная настолько, что общения в университете им явно не хватает, поэтому они часто ходят друг к другу в гости. Все ребята в программном комитете очень спортивные и ходят только пешком. Однажды хранитель традиций олимпиадного движения УрГУ подумал, что на пешие прогулки от дома к дому члены программного комитета тратят слишком много времени, которое могли бы вместо этого потратить на придумывание и подготовку задач. Чтобы доказать это, он решил посчитать, какое расстояние в среднем преодолевают члены комитета, когда ходят друг к другу в гости. Хранитель традиций достал карту Екатеринбурга, нашёл на ней дома всех членов программного комитета и выписал их координаты. Но координат оказалось так много, что хранитель не смог справиться с этой задачей самостоятельно и попросил вас помочь ему. Город Екатеринбург представляет собой прямоугольник со сторонами, ориентированными по сторонам света. Все улицы города идут строго с запада на восток или с севера на юг, проходя через весь город от края до края. Дома всех членов программного комитета расположены строго на пересечении каких-то двух перпендикулярных улиц. Известно, что все члены комитета ходят только по улицам, поскольку идти по тротуару гораздо приятнее, чем по дворовым тропинкам. И, конечно, при переходе от дома к дому они всегда выбирают кратчайший путь. Программный комитет очень дружный, и все его члены ходят в гости ко всем одинаково часто.

### Исходные данные ###
Первая строка содержит целое число n — количество членов программного комитета (2 ≤ n ≤ 105). В i-й из следующих n строк через пробел записаны целые числа xi, yi — координаты дома i-го члена программного комитета (1 ≤ xi, yi ≤ 106).

### Результат ###
Выведите среднее расстояние, которое проходит член программного комитета от своего дома до дома своего товарища, округлённое вниз до целых.

### Пример ###
| исходные данные | результат |
|-----------------|-----------|
| 3               | 13        |
| 10 10           |           |
| 20 20           |           |
| 10 20           |           |

# Структуры данных #

## 1494. Disk Tree ##
https://acm.timus.ru/problem.aspx?space=1&num=1067

>   Ограничение времени: 2.0 секунды
    Ограничение памяти: 64 МБ

Hacker Bill has accidentally lost all the information from his workstation's hard drive and he has no backup copies of its contents. He does not regret for the loss of the files themselves, but for the very nice and convenient directory structure that he had created and cherished during years of work.
Fortunately, Bill has several copies of directory listings from his hard drive. Using those listings he was able to recover full paths (like "WINNT\SYSTEM32\CERTSRV\CERTCO~1\X86") for some directories. He put all of them in a file by writing each path he has found on a separate line.
Your task is to write a program that will help Bill to restore his state of the art directory structure by providing nicely formatted directory tree.

### Исходные данные ###
The first line of the input contains single integer number N (1 ≤ N ≤ 500) that denotes a total number of distinct directory paths. Then N lines with directory paths follow. Each directory path occupies a single line and does not contain any spaces, including leading or trailing ones. No path exceeds 80 characters. Each path is listed once and consists of a number of directory names separated by a back slash ("\").
Each directory name consists of 1 to 8 uppercase letters, numbers, or the special characters from the following list: exclamation mark, number sign, dollar sign, percent sign, ampersand, apostrophe, opening and closing parenthesis, hyphen sign, commercial at, circumflex accent, underscore, grave accent, opening and closing curly bracket, and tilde ("!#$%&'()-@^_`{}~").

### Результат ###
Write to the output the formatted directory tree. Each directory name shall be listed on its own line preceded by a number of spaces that indicate its depth in the directory hierarchy. The subdirectories shall be listed in lexicographic order immediately after their parent directories preceded by one more space than their parent directory. Top level directories shall have no spaces printed before their names and shall be listed in lexicographic order. See sample below for clarification of the output format.

### Пример ###
| исходные данные                     | результат  |
|-------------------------------------|------------|
| 7                                   | GAMES      |
| WINNT\SYSTEM32\CONFIG               |  DRIVERS   |
| GAMES                               | HOME       |
| WINNT\DRIVERS                       | WIN        |
| HOME                                |  SOFT      |
| WIN\SOFT                            | WINNT      |
| GAMES\DRIVERS                       |  DRIVERS   |
| WINNT\SYSTEM32\CERTSRV\CERTCO~1\X86 |  SYSTEM32  |
|                                     |   CERTSRV  |
|                                     |    CERTO~1 |
|                                     |     X86    |
|                                     |   CONFIG   |

## 1494. Монобильярд ##
https://acm.timus.ru/problem.aspx?space=1&num=1494

>   Ограничение времени: 1.0 секунды   
    Ограничение памяти: 64 МБ

Стол для монобильярда, установленный в игровом доме уездного города N, оказался очень прибыльным вложением. До того, как в городе появился небезызвестный господин Чичиков. Раз за разом он выигрывал, и хозяин, подсчитывая убытки, понимал, что дело тут нечисто. Однако уличить подлеца в жульничестве не удавалось до прибытия в город N ревизора из Петербурга.
Правила игры в монобильярд очень просты: нужно последовательно закатить в единственную лузу шары с номерами 1, 2, …, N (именно в этом порядке). Пока господин Чичиков играл, ревизор несколько раз подходил к столу и забирал из лузы последний закатившийся туда шар. В конце концов, оказалось, что Чичиков закатил в лузу все шары, а ревизор все шары достал и обследовал. Аферист утверждал, что закатил шары в правильном порядке. Хозяин понял, что это его шанс: ревизор должен помнить, в каком порядке он доставал шары. Однако так ли легко будет доказать жульничество?

### Исходные данные ###
В первой строке записано целое число N — количество бильярдных шаров (1 ≤ N ≤ 100000). В следующих N строках даны номера этих шаров в том порядке, в котором ревизор забирал их из лузы.

### Результат ###
Выведите слово «Cheater», если Чичиков не мог закатить все N шаров в правильном порядке. Иначе выведите «Not a proof».

### Пример ###
| исходные данные | результат  |
|-----------------|------------|
| 2               | Not a proof|
| 2               |            |
| 1               |            |
|-----------------|------------|
| 3               |            |
| 3               |            |
| 1               |            |
| 2               |            |

### Замечания ###
В первом примере Чичиков мог закатить шары в правильном порядке, если ревизор достал их оба по очереди уже после того, как Чичиков закатил второй шар. Во втором примере Чичиков мог закатить шары в любом порядке, кроме правильного 1-2-3.