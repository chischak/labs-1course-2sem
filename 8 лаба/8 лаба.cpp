#include <iostream>
#include <stdio.h>
using namespace std;
int n;
FILE* f;
struct book
{
	string name;
	string adress;
	int group;
	int rating;
};
void create(int a)
{
    setlocale(LC_ALL,"RU");
	book* st = new book[a];
	for (int i = 0; i < a; i++)
	{
		cout << "ФИО: " << ' ';
		cin >> st[i].name;
		cout << endl;
		cout << "Домашний адрес:" << ' ';
		cin >> st[i].author;
		cout << endl;
		cout << "Группа:" << ' ';
		cin >> st[i].year;
		cout << endl;
		cout << "Рейтинг:" << ' ';
		cin >> st[i].pages;
		cout << endl;
	}
	if ((f = fopen("book", "w")) == NULL)
	{
		perror("Файл не открыт...");
		exit(0);
	}
	fwrite(&st, sizeof(book), 1, f);
	fclose(f);
}
void print(int a)
{
	book* st = new book[a];
	cout << "Книги:" << endl;
		if ((f = fopen("book", "r")) == NULL)
		{
			perror("Ошибка!");
			exit(0);
		}
		fread(&st, sizeof(a), 1, f);
		fclose(f);
		for (int i = 0; i < a; i++)
		{
			cout << "ФИО:" << st[i].name << ' ' << endl;
			cout << "Домашний адрес:" << st[i].author << ' ' << endl;
			cout << "Группа: " << st[i].year << ' ' << endl;
			cout << "Рейтинг:" << st[i].pages << ' ' << endl;
			cout << endl;
		}
}
void del(int a)
{
	book* st = new book[a];
		if ((f = fopen("book", "r")) == NULL)
		{
			perror("Ошибка");
			exit(0);
		}
		fread(&st, sizeof(a), 1, f);
		fclose(f);
		if (a <= 3)
		{
			cout << "Попробуйте снова!";
			n = 0;
				return;
		}
		else if (a == 4)
		{
			n -= 3;
			a -= 3;
			st[0].name = st[3].name;
			st[0].author = st[3].author;
			st[0].year = st[3].year;
			st[0].pages = st[3].pages;
		}
		else if (a == 5)
		{
			n -= 3;
			a -= 3;
			st[0].name = st[3].name;
			st[0].author = st[3].author;
			st[0].year = st[3].year;
			st[0].pages = st[3].pages;
			st[1].name = st[4].name;
			st[1].author = st[4].author;
			st[1].year = st[4].year;
			st[1].pages = st[4].pages;
		}
		else
		{
			n -= 3;
			a -= 3;
			for (int i = 0; i < a; i++)
			{
				st[i].name = st[i + 3].name;
				st[i].author = st[i + 3].author;
				st[i].year = st[i + 3].year;
				st[i].pages = st[i + 3].pages;
			}
		}
		if ((f = fopen("book", "w")) == NULL)
		{
			perror("Файл не открыт...");
			exit(0);
		}
		fwrite(&st, sizeof(book), 1, f);
		fclose(f);
}
void add(int a)
{
	book* st = new book[a];
	if ((f = fopen("book", "r")) == NULL)
	{
		perror("Ошибка!");
		exit(0);
	}
	fread(&st, sizeof(a), 1, f);
	fclose(f);
	int num;
	cout << "Введите индекс для того, чтобы добавить новую книгу:";
	cin >> num;
	if (num >= a)
	{
		cout << "Введите меньший индекс" << ' ' << a << endl;
		cin >> num;
	}
	int i = a;
		while (i != num)
		{
			st[i].name = st[i - 1].name;
			st[i].author = st[i - 1].author;
			st[i].year = st[i - 1].year;
			st[i].pages = st[i - 1].pages;
			i--;
		}
	cout << "Новый стундент" << endl;
	cout << "ФИО:" << ' ';
	cin >> st[num].name;
	cout << "Домашний адрес:" << ' ';
	cin >> st[num].author;
	cout << "Группа" << ' ';
	cin >> st[num].year;
	cout << "Рейтинг:" << ' ';
	cin >> st[num].pages;
	cout << endl;
	n++;
	a++;
	if ((f = fopen("book", "w")) == NULL)
	{
		perror("ERROR");
		exit(0);
	}
	fwrite(&st, sizeof(book), 1, f);
	fclose(f);
}
int main()
{
	cout << "Сколько студентов имеется?" << endl;
	cin >> n;
	cout << endl;
	create(n);
	print(n);
	del(n);
	if (n == 0)
	{
		return 0;
	}
	cout << "После удаления:" << endl;
	print(n);
	add(n);
	cout << "После добавления:" << endl;
	print(n);
	return 0;
}