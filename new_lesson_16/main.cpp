#include <iostream>
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
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::set;
using std::map;

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
	Report(const string s) : str(s) { cout << "������ ������!\n"; }
	~Report() { cout << "������ ������!\n"; }
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

//16.16 - fundap.cpp � ������������� ��������� �������
/*void Show(double v)
{
	cout.width(6);
	cout << v << ' ';
}
const int LIM = 6;*/

//16.18 - strgstl.cpp -- ���������� STL � ������
/*void Show(int v)
{
	cout << v << ' ';
}
const int LIM = 10;*/

//16.19 - usealgo.��� -- ������������� ���������� ��������� STL
char toLower(char ch) { return std::tolower(ch); }
string & ToLower(string & s)
{
	std::transform(s.begin(), s.end(), s.begin(), toLower);
	return s;
}
void display(const string & s)
{
	cout << s << ' ';
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
	
	one += " Oops!";			// ������������� +=
	cout << one << endl;

	two = "Sorry! That was ";
	three[0] = 'P';
	
	string four;			//string()
	four = two + three;		// ������������� +, =
	cout << four << endl;

	char alls[] = "All's well that ends well";
	string five(alls, 20);	//string(const char * s, size type �)
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
		std::cerr << "�� ������� ������� ����\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	std::getline(fin, item, ':');
	while (fin) // �� ��� ���, ���� ��� ������ �����
	{
		count++;
		cout << count << ": " << item << endl;
		std::getline(fin, item, ':');
	}
	fin.close();*/

	//16.3
	/*std::srand(std::time(NULL));
	char play;
	cout << "������ �������� � ��������? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[std::rand() % NUM];
		int lenght = target.length();
		string attempt(lenght, '-'); // ���������
		string badchars; //�������� �����
		int guesses = lenght;
		cout << "�������� �����, � ��� " << lenght << " ����\n���������� ���� ����� �� ���, � ��� " << guesses << " �������\n";
		cout << "���� �����: " << attempt << endl;
		while (attempt != target && guesses > 0)
		{
			char letter;
			cout << "������� �����: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "�� ��� ��������� ��� �����! ���������� ��� ���\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "�������� �����!\n";
				guesses--;
				badchars += letter;
			}
			else
			{
				cout << "�� �������!\n";
				attempt[loc] = letter;
				// ���������, �� ���������� �� ����� ��� ���
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "���� �����: " << attempt << endl;
			if (attempt != target && badchars.length() > 0)
				cout << "�������� �����: " << badchars << endl << guesses << " ������� ��������!\n";
		}
		if (guesses > 0)
			cout << "�� ������� �����!\n";
		else
			cout << "�� ���������! ���������� �����: " << target << endl;
		cout << "������ ������� ���? <y/n> ";
		cin >> play;
		play = tolower(play);
	}*/

	//16.4
	/*string empty;
	string __small = "bit";
	string larger = "Elephants are a girl's best friend";
	cout << "������� �����: \n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\t__small: " << __small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	cout << "������� �������� ����� �����: \n";
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\t__small: " << __small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;
	empty.reserve(50);
	cout << "������ ����� empty.reserve(50): " << empty.capacity() << endl;*/

	//16.5
	/*{
		std::auto_ptr<Report> ps(new Report("������������ auto_ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report> ps(new Report("������������ shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("������������ unique_ptr"));
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
	cout << "������� ����� � �� �������:\n";
	int i;
	for (i = 0; i < NUM; i++)
	{
		cout << "������� �������� ����� #" << i + 1 << ": ";
		std::getline(cin, titles[i]);
		cout << "������� �� �������: ";
		cin >> ratings[i];
		cin.get();
	}

	cout << "\n�������\t�����:\n";
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
		cout << "�� �����:\n";
		cout << "\n�������\t�����:\n";
		for (int i = 0; i < num; i++)
			ShowReview(books[i]);
		cout << "������:\n";
		cout << "\n�������\t�����:\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
		vector<Review> oldlist(books); // ������������� ������������ �����������
		if (num > 3)
		{
			// �������� ���� ���������
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "����� ��������(erase):\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
			// ������� ������ ��������
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
			cout << "����� �������(insert):\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		}
		books.swap(oldlist);
		cout << "����� ����������� oldlist � books:\n";
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
	}
	else
		cout << "�� ������ �� �����!\n";*/

	//16.9
	/*vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	if (books.size() > 0)
	{
		cout << "�� ����� "<< books.size() <<" ��������:\n";
		cout << "\n�������\t�����:\n";
		std::for_each(books.begin(), books.end(), ShowReview);
		std::sort(books.begin(), books.end());
		cout << "���������� �� ��������:\n";
		cout << "\n�������\t�����:\n";
		std::for_each(books.begin(), books.end(), ShowReview);
		std::sort(books.begin(), books.end(), worseThan);
		cout << "���������� �� ��������:\n";
		std::for_each(books.begin(), books.end(), ShowReview);
		std::random_shuffle(books.begin(), books.end());
		cout << "����� ��������� ����������:\n";
		std::for_each(books.begin(), books.end(), ShowReview);
	}
	else
		cout << "�� ������ �� �����!\n";*/

	//16.10
	/*int casts[10] = { 6, 1, 2, 9, 4, 11, 8, 1, 10, 5 };
	vector<int> dice(10);
	// ����������� �� ������� � ������
	std::copy(casts, casts + 10, dice.begin());
	cout << "��������� dice:\n";
	// �������� ��������� ostream
	std::ostream_iterator<int, char> out_iter(cout, " ");
	std::copy(dice.begin(), dice.end(), out_iter);
	cout << endl;

	cout << "������� ������������� ��������� ���������:\n";
	std::copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;

	cout << "����� ������������� ��������� ���������:\n";
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

	// ��������������� ���������� ������� ���� back_insert_iterator
	copy(s2, s2 + 2, std::back_insert_iterator<vector<string> >(words));
	std::for_each(words.begin(), words.end(), output);
	cout << endl;

	// ��������������� ���������� ������� ���� insert_iterator
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
	cout << "������ ������: ";
	std::for_each(one.begin(), one.end(), outint);
	cout << "\n������ ������: ";
	std::for_each(two.begin(), two.end(), outint);
	cout << "\n������ ������: ";
	std::for_each(three.begin(), three.end(), outint);
	three.remove(2);
	cout << "\n������ ������ ����� ��� ����� 2: ";
	std::for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);
	cout << "\n������ ������ ����� splice(): ";
	std::for_each(three.begin(), three.end(), outint);
	cout << "\n������ ������  ����� splice(): ";
	std::for_each(one.begin(), one.end(), outint);
	three.sort();
	three.unique();
	cout << "\n������ ������ sort() � unique(): ";
	std::for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);
	cout << "\nC������ ���������������� ������� ������ � �������: ";
	std::for_each(three.begin(), three.end(), outint);
	cout << endl;*/

	//16.13
	/*const int N = 6;
	string s1[N] = { "buffoon", "thinkers", "for", "heavy", "can", "for" }; 
	string s2[N] = { "metal", "any", "food", "elegant", "deliver","for" };
	set<string> A(s1, s1 + N);
	set<string> B(s2, s2 + N);
	std::ostream_iterator<string, char> out(cout, " ");
	
	cout << "Set (�����) A:\n";
	copy(A.begin(), A.end(), out);
	
	cout << "\nSet (�����) A:\n";
	for (auto x : B) cout << x << " ";
	
	cout << "\n����������� � � �:\n";
	std::set_union(A.begin(), A.end(), B.begin(), B.end(), out);

	cout << "\n����������� � � �:\n";
	std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);

	cout << "\n�������� � � �:\n";
	std::set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	set<string> C;
	std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::insert_iterator<set<string> >(C, C.begin()));
	cout << "Set (�����) C:\n";
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3("grungy");
	C.insert(s3);
	cout << "����� � ����� ������� ������:\n";
	copy(C.begin(), C.end(), out);

	cout << "\n����� ���������:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
	cout << endl;*/

	//16.14
	/*
	//typedef int KeyType;
	//typedef std::pair<const KeyType, string> Pair;
	//typedef std::multimap<KeyType, string> MapCode;

	MapCode codes;	//���� ����� ���    std::multimap<int, string> codes;
	codes.insert(std::pair<const int, string>(415, "San Francisco"));
	codes.insert(Pair(510, "Ookland"));
	codes.insert(Pair(718, "Brooklyn")); 
	codes.insert(Pair(718, "Staten Island")); 
	codes.insert(Pair(415, "San Rafael"));
	codes.insert(std::pair<const int, string>(510, "Berkeley"));
	
	cout << "���������� ������� � ����� ������� 415:\n" << codes.count(415) << endl;
	cout << "���������� ������� � ����� ������� 718:\n" << codes.count(718) << endl;
	cout << "���������� ������� � ����� ������� 510:\n" << codes.count(510) << endl;

	cout << "��� ������� | �����:\n";
	MapCode::iterator ir;	// ���� ����� ���  std::multimap<int, string>::iterator ir;
	for (ir = codes.begin(); ir != codes.end(); ir++)
		cout << " " << (*ir).first << "\t\t" << (*ir).second << endl;

	std::pair<std::multimap<int, string>::iterator, std::multimap<int, string>::iterator> range = codes.equal_range(718);
	cout << "������ � ����� ������� 718:\n";
	for (ir = range.first; ir != range.second; ir++)
		cout << (*ir).second << endl;
	*/

	//16.15
	/*ToBig<int> f100(100);
	int  vals[10] = { 50,10,90,180,60,210,415,88,188,201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etceters{ 50,10,90,180,60,210,415,88,188,201 };
	cout << "�������������� ����:\n";
	std::for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	std::for_each(etceters.begin(), etceters.end(), outint);
	cout << endl;
	yadayada.remove_if(f100); //������������� ������������ ��������������� �������
	etceters.remove_if(ToBig<int>(200)); //��������������� ��������������� �������

	cout << "��������� ������:\n";
	std::for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	std::for_each(etceters.begin(), etceters.end(), outint);
	cout << endl;*/

	//16.16 - fundap.cpp � ������������� ��������� �������
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

	//16.17 - strgstl.cpp -- ���������� STL � ������
	/*string letters;
	cout << "������� ������ ���� <quit ��� ������>: ";
	while (cin >> letters && letters != "quit")
	{
		cout << "������������ ������ ���� " << letters << endl;
		std::sort(letters.begin(), letters.end());
		cout << letters << endl;
		while (std::next_permutation(letters.begin(), letters.end()))
			cout << letters << endl;
		cout << "������� ��������� ������ ���� <quit ��� ������>: ";
	}*/

	//16.18 - strgstl.cpp -- ���������� STL � ������
	/*int ar[LIM] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };
	list<int> la(ar, ar + LIM);
	list<int> lb(la);

	cout << "����� ����������� ��������� ������:\n";
	std::for_each(la.begin(), la.end(), Show);
	cout << endl;
	la.remove(4);
	
	cout << "������ ����� ������������� ������ remove ():\n";
	std::for_each(la.begin(), la.end(), Show);
	cout << endl;
	
	list<int>::iterator last;
	last = std::remove(lb.begin(), lb.end(), 4);
	
	cout << "������ ����� ������������� ������� remove ():\n";
	std::for_each(lb.begin(), lb.end(), Show);
	cout << endl;

	lb.erase(last, lb.end());
	cout << "������ ����� ������������� ������ erase():\n";
	std::for_each(lb.begin(), lb.end(), Show);
	cout << endl;*/

	//16.19 - usealgo.��� -- ������������� ���������� ��������� STL
	vector<string> words;
	
	cout << "������� ����� (quit ��� ������): ";
	
	string input;
	while (cin >> input && input != "quit")
		words.push_back(input);
	
	cout << "�� ����� ��������� �����:\n";
	std::for_each(words.begin(), words.end(), display);
	cout << endl;

	// ��������� ���� � ����� � �������������� ���� � ��������
	set<string> wordset;
	std::transform(words.begin(), words.end(), std::insert_iterator<set<string> >(wordset, wordset.begin()), ToLower);
	
	cout << "��������� ����� � ���������� �������:\n";
	std::for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	// ��������� � ������� ��� ��������� � �����
	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		wordmap[*si] = std::count(words.begin(), words.end(), *si);

	// ����������� ����������� �����
	cout << "������� ��������� ����:\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
		cout << *si << ": " << wordmap[*si] << endl;

	return 0;
}

//16.8-9
/*bool FillReview(Review & r)
{
	cout << "������� �������� ����� <quit> ��� ������: ";
	std::getline(cin, r.title);
	if (r.title == "quit")
		return false;
	cout << "������� �� �������: ";
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