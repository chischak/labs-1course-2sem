#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int n;
int main()
{
    setlocale(LC_ALL, "RU");
	cout << "Введите количество стрjr:" << ' ';
	cin >> n;
	if (n <= 10)
	{
	    cout << "Советую ввести больше 10 стрjr";
	    return 0;
	}
	cin.ignore();
	ofstream f1("F1.txt");
	if (!f1.is_open())
	{
		cout << "Файл не открыт" << endl;
		return 0;
	}
	string str;
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		f1 << str << endl;
	}
	f1.close();
	ifstream file("F1.txt");
	if (!file.is_open())
	{
		cout << "Файл не открыт" << endl;
		return 0;
	}
	cout << "F1:" << endl;
	for (int i = 0; i < n; i++)
	{
		getline(file, str);
		cout << str << endl;
	}
	file.close();
	ifstream f("F1.txt");
	ofstream f2("F2.txt");
	if (!f.is_open() and !f2.is_open())
	{
		cout << "Файл не открыт" << endl;
		return 0;
	}
	int g = 0;
	for (int i = 0; i < n; i++)
	{
		getline(f, str);
		string s;
		string mass[50];
		stringstream str_word(str);
		int j = 0;
		while (str_word >> s)
		{
			mass[j] = s;
			j++;
		}
		bool flag = false;
		for (int q = 0; q < j; q++)
		{
			for(int k = q + 1; k < j;k++)
			{
				if (mass[q] == mass[k])
				{
					flag = true;
					g++;
				}
			}
		}
		if (flag == false)
		{
			f2 << str << endl;
		}
	}
	f.close();
	f2.close();
	ifstream F2("F2.txt");
	if (!F2.is_open())
	{
		cout << "Файл не открыт" << endl;
		return 0;
	}
	n -= g;
	cout << "F2:" << endl;
	for (int i = 0; i < n; i++)
	{
		getline(F2, str);
		cout << str << endl;
	}
	F2.close();
	ifstream file2("F2.txt");
	if (!file2.is_open())
	{
		cout << "Файл не открыт" << endl;
		return 0;
	}
	getline(file2, str);
	 g = 0;
	for (auto c : str)
	{
		switch (c)
		{
		case 'a': case 'e': case 'i': case 'o': case 'u': case 'y': case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y': g++;
		}
	}
	cout << "Количество гласных в первой строке F2:" << ' ' << g << endl;
	file2.close();
	return 0;
}