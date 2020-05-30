﻿#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <memory>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <set>
#include <map>
#include <functional>
#include <valarray>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::set;
using std::map;
using std::valarray;
//16.3
/*const int NUM = 26;
const string wordlist[NUM] = { "apiary", "beetle", "cereal",
"danger", "ensign", "florid", "garage", "health", "insult",
"jackal", "keeper", "loaner", "manage", "nonce", "onset",
"plaid", "quilt", "remote", "stolid", "train", "useful",
"valid", "whence", "xenon", "yearn", "zippy" };*/

//16.5
/*class Report
{
private:
	string str;
public:
	Report(const string s) : str(s) { cout << "Объект создан!\n"; }
	~Report() { cout << "Объект удален!\n"; }
	void comment() const { cout << str << endl; }
};*/

//16.7
//const int NUM = 5;

//16.8-9
/*struct Review
{
	string title;
	int rating;
};
bool FillReview(Review & r);
void ShowReview(const Review & r);
bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);*/

//16.11
//void output(const string & s) { cout << s << " "; }

//16.12 
//void outint(int n) { cout << n << " "; }

//16.14
/*typedef int KeyType;
typedef std::pair<const KeyType, string> Pair;
typedef std::multimap<KeyType, string> MapCode;*/

//16.15
/*template <typename T>
class ToBig
{
private:
	T cutoff;
public:
	ToBig(const T & t) : cutoff(t) {}
	bool operator()(const T & x) { return x > cutoff; }
};
void outint(int n) { cout << n << " "; }*/

//16.16 - fundap.cpp — использование адаптеров функций
/*void Show(double v)
{
	cout.width(6);
	cout << v << ' ';
}
const int LIM = 6;*/

//16.18 - strgstl.cpp -- применение STL к строке
/*void Show(int v)
{
	cout << v << ' ';
}
const int LIM = 10;*/

//16.19 - usealgo.срр -- использование нескольких элементов STL
/*char toLower(char ch) { return std::tolower(ch); }
string & ToLower(string & s)
{
	std::transform(s.begin(), s.end(), s.begin(), toLower);
	return s;
}
void display(const string & s)
{
	cout << s << ' ';
}*/

//16.21
const int N = 12;
void show(const valarray<int> & v, int cols)
{
	int lim = v.size();
	for (int i = 0; i < lim; i++)
	{
		cout.width(3);
		cout << v[i];
		if (i % cols == cols - 1)
			cout << endl;
		else
			cout << ' ';
	}
	if (lim % cols != 0)
		cout << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//16.1
	/*string one("Lotery Winner!"); //string (const char * s)
	cout << one << endl;

	string two(20, '$');	//string(size type n, char c)
	cout << two << endl;

	string three(one);
	cout << three << endl;	//string(const string & str)
	
	one += " Oops!";			// перегруженная +=
	cout << one << endl;

	two = "Sorry! That was ";
	three[0] = 'P';
	
	string four;			//string()
	four = two + three;		// перегруженная +, =
	cout << four << endl;

	char alls[] = "All's well that ends well";
	string five(alls, 20);	//string(const char * s, size type л)
	cout << five << "!\n";

	string six(alls + 6, alls + 10);  //template<class Iter> string(Iter begin, Iter end)
	cout << six << ", ";

	string seven(&five[6], &five[10]);  //template<class Iter> string(Iter begin, Iter end)
	cout << seven << "...\n";

	string eight(four, 7, 16); //string(const string & str, size type pos, size type n = npos)
	cout << eight << " in motion!" << endl;*/

	//16.2
	/*std::ifstream fin;
	fin.open("tobuy.txt");
	if (fin.is_open() == false)
	{
		std::cerr << "Не удается открыть файл\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	std::getline(fin, item, ':');
	while (fin) // до тех пор, пока нет ошибок ввода
	{
		count++;
		cout << count << ": " << item << endl;
		std::getline(fin, item, ':');
	}
	fin.close();*/

	//16.3
	/*std::srand(std::time(NULL));
	char play;
	cout << "Хотите поиграть в виселицу? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[std::rand() % NUM];
		int lenght = target.length();
		string attempt(lenght, '-'); // угаданное
		string badchars; //неверные буквы
		int guesses = lenght;
		cout << "Угадайте слово, в нем " << lenght << " букв\nугадываете одну букву за ход, у вас " << guesses << " попыток\n";
		cout << "Ваше слово: " << attempt << endl;
		while (attempt != target && guesses > 0)
		{
			char letter;
			cout << "Введите букву: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "Вы уже угадывали эту букву! Попробуйте еще раз\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Неверная буква!\n";
				guesses--;
				badchars += letter;
			}
			else
			{
				cout << "Вы угадали!\n";
				attempt[loc] = letter;
				// Проверить, не появляется ли буква еще раз
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Ваше слово: " << attempt << endl;
			if (attempt != target && badchars.length() > 0)
				cout << "Неверные буквы: " << badchars << endl << guesses << " попыток осталось!\n";
		}
		if (guesses > 0)
			cout << "Вы угадали слово!\n";
		else
			cout << "Вы проиграли! Загаданное слово: " << target << endl;
		cout << "Хотите сыграть еще? <y/n> ";
		cin >> play;
		play = tolower(play);
	}*/

	//16.4
	/*string empty;
	string __small = "bit";
	string larger = "Elephants are a girl's best friend";
	cout << "Размеры строк: \n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\t__small: " << __small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	cout << "Размеры текущего блока строк: \n";
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\t__small: " << __small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;
	empty.reserve(50);
	cout << "Размер после empty.reserve(50): " << empty.capacity() << endl;*/

	//16.5
	/*{
		std::auto_ptr<Report> ps(new Report("используется auto_ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report> ps(new Report("используется shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("используется unique_ptr"));
		ps->comment();
	}*/

	//16.6
	//a
	/*std::auto_ptr<string> films[5] =
	{
		std::auto_ptr<string>(new string("Fowl Balls")),
		std::auto_ptr<string>(new string("Duck Walks")),
		std::auto_ptr<string>(new string("Chicken Runs")),
		std::auto_ptr<string>(new string("Turkey Errors")),
		std::auto_ptr<string>(new string("Goose Eggs"))
	};
	std::auto_ptr<string> pwin;
	pwin = films[2];

	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "The winner is " << *pwin << "!\n";
	cin.get();
	
	//b
	std::shared_ptr<string> films[5] =
	{
		std::shared_ptr<string>(new string("Fowl Balls")),
		std::shared_ptr<string>(new string("Duck Walks")),
		std::shared_ptr<string>(new string("Chicken Runs")),
		std::shared_ptr<string>(new string("Turkey Errors")),
		std::shared_ptr<string>(new string("Goose Eggs"))
	};
	std::shared_ptr<string> pwin;
	pwin = films[2];

	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "The winner is " << *pwin << "!\n";*/

	//16.7
	/*vector<int> ratings(NUM);
	vector<string> titles(NUM);
	cout << "Введите книги и их рейтинг:\n";
	int i;
	for (i = 0; i < NUM; i++)
	{
		cout << "Введите название книги #" << i + 1 << ": ";
		std::getline(cin, titles[i]);
		cout << "Введите ее рейтинг: ";
		cin >> ratings[i];
		cin.get();
	}

	cout << "\nРейтинг\tКнига:\n";
	for (i = 0; i < NUM; i++)
		cout << ratings[i] << "\t" << titles[i] << endl;*/

	//16.8
	/*vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	int num = books.size();
	if (num > 0)
	{
		cout << "Вы ввели:\n";
		cout << "\nРейтинг\tКнига:\n";
		for (int i = 0; i < num; i++)
			ShowReview(books[i]);
		cout << "Повтор:\n";
		cout << "\nРейтинг\tКнига:\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
		vector<Review> oldlist(books); // использование конструктора копирования
		if (num > 3)
		{
			// Удаление двух элементов
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "После удаления(erase):\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
			// Вставка одного элемента
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
			cout << "После вставки(insert):\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		}
		books.swap(oldlist);
		cout << "Обмен эелементами oldlist и books:\n";
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
	}
	else
		cout << "Вы ничего не ввели!\n";*/

	//16.9
	/*vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	if (books.size() > 0)
	{
		cout << "Вы ввели "<< books.size() <<" рейтинга:\n";
		cout << "\nРейтинг\tКнига:\n";
		std::for_each(books.begin(), books.end(), ShowReview);
		std::sort(books.begin(), books.end());
		cout << "Сортировка по названию:\n";
		cout << "\nРейтинг\tКнига:\n";
		std::for_each(books.begin(), books.end(), ShowReview);
		std::sort(books.begin(), books.end(), worseThan);
		cout << "Сортировка по рейтингу:\n";
		std::for_each(books.begin(), books.end(), ShowReview);
		std::random_shuffle(books.begin(), books.end());
		cout << "После случайной сортировка:\n";
		std::for_each(books.begin(), books.end(), ShowReview);
	}
	else
		cout << "Вы ничего не ввели!\n";*/

	//16.10
	/*int casts[10] = { 6, 1, 2, 9, 4, 11, 8, 1, 10, 5 };
	vector<int> dice(10);
	// Копирование из массива в вектор
	std::copy(casts, casts + 10, dice.begin());
	cout << "Заполняем dice:\n";
	// Создание итератора ostream
	std::ostream_iterator<int, char> out_iter(cout, " ");
	std::copy(dice.begin(), dice.end(), out_iter);
	cout << endl;

	cout << "Неявное использование обратного итератора:\n";
	std::copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;

	cout << "Явное использование обратного итератора:\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ri++)
		cout << *ri << " ";*/

	//16.11
	/*string s1[4] = { "fine", "fish", "fashion", "fate" };
	string s2[2] = { "busy", "bats" };
	string s3[2] = { "silly", "singers" };
	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	std::for_each(words.begin(), words.end(), output);
	cout << endl;

	// Конструирование анонимного объекта типа back_insert_iterator
	copy(s2, s2 + 2, std::back_insert_iterator<vector<string> >(words));
	std::for_each(words.begin(), words.end(), output);
	cout << endl;

	// Конструирование анонимного объекта типа insert_iterator
	copy(s3, s3 + 2, std::insert_iterator<vector<string> >(words, words.begin()));
	std::for_each(words.begin(), words.end(), output);
	cout << endl;*/

	//16.12
	/*list<int> one(5, 2);
	int stuff[5] = { 1,2,4,8, 6 };
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);
	int more[6] = { 6, 4, 2, 4, 6, 5 };
	list<int> three(two);
	three.insert(three.end(), more, more + 6);
	cout << "Первый список: ";
	std::for_each(one.begin(), one.end(), outint);
	cout << "\nВторой список: ";
	std::for_each(two.begin(), two.end(), outint);
	cout << "\nТретий список: ";
	std::for_each(three.begin(), three.end(), outint);
	three.remove(2);
	cout << "\nТретий список минус все цифры 2: ";
	std::for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);
	cout << "\nТретий список после splice(): ";
	std::for_each(three.begin(), three.end(), outint);
	cout << "\nПервый список  после splice(): ";
	std::for_each(one.begin(), one.end(), outint);
	three.sort();
	three.unique();
	cout << "\nТретий список sort() и unique(): ";
	std::for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);
	cout << "\nCлияние отсортированного второго списка с третьим: ";
	std::for_each(three.begin(), three.end(), outint);
	cout << endl;*/

	//16.13
	/*const int N = 6;
	string s1[N] = { "buffoon", "thinkers", "for", "heavy", "can", "for" }; 
	string s2[N] = { "metal", "any", "food", "elegant", "deliver","for" };
	set<string> A(s1, s1 + N);
	set<string> B(s2, s2 + N);
	std::ostream_iterator<string, char> out(cout, " ");
	
	cout << "Set (набор) A:\n";
	copy(A.begin(), A.end(), out);
	
	cout << "\nSet (набор) A:\n";
	for (auto x : B) cout << x << " ";
	
	cout << "\nОбъединение А и В:\n";
	std::set_union(A.begin(), A.end(), B.begin(), B.end(), out);

	cout << "\nПересечение А и В:\n";
	std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);

	cout << "\nРазность А и В:\n";
	std::set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	set<string> C;
	std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::insert_iterator<set<string> >(C, C.begin()));
	cout << "Set (набор) C:\n";
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3("grungy");
	C.insert(s3);
	cout << "Набор С после вставки строки:\n";
	copy(C.begin(), C.end(), out);

	cout << "\nВывод диапазона:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
	cout << endl;*/

	//16.14
	/*
	//typedef int KeyType;
	//typedef std::pair<const KeyType, string> Pair;
	//typedef std::multimap<KeyType, string> MapCode;

	MapCode codes;	//тоже самое что    std::multimap<int, string> codes;
	codes.insert(std::pair<const int, string>(415, "San Francisco"));
	codes.insert(Pair(510, "Ookland"));
	codes.insert(Pair(718, "Brooklyn")); 
	codes.insert(Pair(718, "Staten Island")); 
	codes.insert(Pair(415, "San Rafael"));
	codes.insert(std::pair<const int, string>(510, "Berkeley"));
	
	cout << "Количество городов с кодом региона 415:\n" << codes.count(415) << endl;
	cout << "Количество городов с кодом региона 718:\n" << codes.count(718) << endl;
	cout << "Количество городов с кодом региона 510:\n" << codes.count(510) << endl;

	cout << "Код региона | Город:\n";
	MapCode::iterator ir;	// тоже самое что  std::multimap<int, string>::iterator ir;
	for (ir = codes.begin(); ir != codes.end(); ir++)
		cout << " " << (*ir).first << "\t\t" << (*ir).second << endl;

	std::pair<std::multimap<int, string>::iterator, std::multimap<int, string>::iterator> range = codes.equal_range(718);
	cout << "Города с кодом региона 718:\n";
	for (ir = range.first; ir != range.second; ir++)
		cout << (*ir).second << endl;
	*/

	//16.15
	/*ToBig<int> f100(100);
	int  vals[10] = { 50,10,90,180,60,210,415,88,188,201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etceters{ 50,10,90,180,60,210,415,88,188,201 };
	cout << "Первоначальный лист:\n";
	std::for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	std::for_each(etceters.begin(), etceters.end(), outint);
	cout << endl;
	yadayada.remove_if(f100); //использование именованного функционального объекта
	etceters.remove_if(ToBig<int>(200)); //конструирование функционального объекта

	cout << "Усеченные списки:\n";
	std::for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	std::for_each(etceters.begin(), etceters.end(), outint);
	cout << endl;*/

	//16.16 - fundap.cpp — использование адаптеров функций
	/*double arr1[LIM] = { 28, 29, 30, 35, 38, 59 };
	double arr2[LIM] = { 28, 29, 30, 35, 38, 59 };
	vector<double> gr8(arr1, arr1 + LIM);
	vector<double> m8(arr2, arr2 + LIM);

	cout.setf(std::ios_base::fixed);
	cout.precision(1);

	cout << "gr8:";
	std::for_each(gr8.begin(), gr8.end(), Show);
	cout << endl;
	cout << "m8:";
	std::for_each(m8.begin(), m8.end(), Show);
	cout << endl;

	vector<double> sum(LIM);
	std::transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), std::plus<double>());

	cout << "sum:";
	std::for_each(sum.begin(), sum.end(), Show);
	cout << endl;

	vector<double> prod(LIM);
	std::transform(gr8.begin(), gr8.end(), prod.begin(), std::bind1st(std::multiplies<double>(), 2.5));

	cout << "prod:";
	std::for_each(prod.begin(), prod.end(), Show);
	cout << endl;*/

	//16.17 - strgstl.cpp -- применение STL к строке
	/*string letters;
	cout << "Введите группу букв <quit для выхода>: ";
	while (cin >> letters && letters != "quit")
	{
		cout << "Перестановка группы букв " << letters << endl;
		std::sort(letters.begin(), letters.end());
		cout << letters << endl;
		while (std::next_permutation(letters.begin(), letters.end()))
			cout << letters << endl;
		cout << "Введите следующую группу букв <quit для выхода>: ";
	}*/

	//16.18 - strgstl.cpp -- применение STL к строке
	/*int ar[LIM] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };
	list<int> la(ar, ar + LIM);
	list<int> lb(la);

	cout << "Вывод содержимого исходного списка:\n";
	std::for_each(la.begin(), la.end(), Show);
	cout << endl;
	la.remove(4);
	
	cout << "Список после использования метода remove ():\n";
	std::for_each(la.begin(), la.end(), Show);
	cout << endl;
	
	list<int>::iterator last;
	last = std::remove(lb.begin(), lb.end(), 4);
	
	cout << "Список после использования функции remove ():\n";
	std::for_each(lb.begin(), lb.end(), Show);
	cout << endl;

	lb.erase(last, lb.end());
	cout << "Список после использования метода erase():\n";
	std::for_each(lb.begin(), lb.end(), Show);
	cout << endl;*/

	//16.19 - usealgo.срр -- использование нескольких элементов STL
	/*vector<string> words;
	
	cout << "Введите слова (quit для выхода): ";
	
	string input;
	while (cin >> input && input != "quit")
		words.push_back(input);
	
	cout << "Вы ввели следующие слова:\n";
	std::for_each(words.begin(), words.end(), display);
	cout << endl;

	// Помещение слов в набор с преобразование букв в строчные
	set<string> wordset;
	std::transform(words.begin(), words.end(), std::insert_iterator<set<string> >(wordset, wordset.begin()), ToLower);
	
	cout << "Введенные слова в алфавитном порядке:\n";
	std::for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	// Помещение и частоты его помещения в карту
	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		wordmap[*si] = std::count(words.begin(), words.end(), *si);

	// Отображение содержимого карты
	cout << "Частота появления слов:\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
		cout << *si << ": " << wordmap[*si] << endl;*/

	//16.20
	/*vector<double> data;
	double temp;

	cout << "Введите числа(<=0 для выхода):\n";
	while (cin >> temp && temp > 0)
		data.push_back(temp);

	sort(data.begin(), data.end());
	int size = data.size();
	valarray<double> numbers(size);
	int i;
	for (i = 0; i < size; i++)
		numbers[i] = data[i];
	valarray<double> sq_res(size);
	sq_res = sqrt(numbers);
	valarray<double> results(size);
	results = numbers + 2.0 * sq_res;
	cout.setf(std::ios_base::fixed);
	cout.precision(4);
	for (i = 0; i < size; i++)
	{
		cout.width(8);
		cout << numbers[i] << ": ";
		cout.width(8);
		cout << results[i] << endl;
	}*/

	//16.21
	std::srand(time(NULL));
	valarray<int> valint(N);
	for (int i = 0; i < N; i++)
		valint[i] = std::rand() % 10;

	cout << "Исходный массив\n";
	show(valint, 3);	// отображение в виде 3 столбцов
	valarray<int> vcol(valint[std::slice(1, 4, 3)]); // извлечение 2-го столбца

	cout << "Второй столбец:\n";
	show(vcol, 1); //отображение 2го столбца

	valarray<int> vrow(valint[std::slice(3, 3, 1)]);
	cout << "Вторая строка:\n";
	show(vrow, 3);

	valint[std::slice(2, 4, 3)] = 10; 
	cout << "Присваивание элементам последнего столбца значений 10:\n";
	show(valint, 3);

	cout << "Установка первого столбца в сумму двух остальных:\n";
	valint[std::slice(0, 4, 3)] = valarray<int>(valint[std::slice(1, 4, 3)]) + valarray<int>(valint[std::slice(2, 4, 3)]);

	show(valint, 3);
	return 0;
}

//16.8-9
/*bool FillReview(Review & r)
{
	cout << "Введите название книги <quit> для выхода: ";
	std::getline(cin, r.title);
	if (r.title == "quit")
		return false;
	cout << "Введите ее рейтинг: ";
	cin >> r.rating;
	if (!cin)
		return false;
	while (cin.get() != '\n')
		continue;
	return true;
}
void ShowReview(const Review & r)
{
	cout << r.rating << "\t" << r.title << endl;
}
bool operator<(const Review & r1, const Review & r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}
bool worseThan(const Review & r1, const Review & r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}*/