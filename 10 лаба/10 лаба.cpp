#include <iostream>
 #include <string>
using namespace std;
 
int main()
{
    setlocale(LC_ALL, "RU");
    int amount, j;
    cout << "Введите количество строк:";
    cin >> amount;
    string *s = new string[amount];
    cin.ignore();
    for (int i = 0; i < amount; i++)
    {
        getline(cin, s[i]);
    }
    while (j < amount)
    {
        if (s[j][0] == 'a')
		{
			for(int i = j;i < amount - 1; i++)
			{
				s[i] = s[i + 1];
			}
			amount--;
		}
		else
		{
			j++;
		}
	}
	cout << "Финальная строка:" << ' ';
	for (int i = 0; i < amount; i++)
	{
		cout << s[i] << ' ';
	}
	delete[]s;
    
   return 0;
}