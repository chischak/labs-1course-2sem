#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
	int size;
	cout << "Введите длину последовательности:" << endl;
	cin >> size;
	int* mass = new int[size];
	for (int i = 0; i < size; i++) 
	{
		mass[i] = rand() % 100;
		cout << mass[i] << ' ';
	}	


	
	int k;
	cout << endl << "Введите число:" << ' ';
	cin >> k;
	cout << "Результат:" << ' ';
	for (int i; i < size; i++)
	{
		cout << mass[k] << " ";
		k++;
		if (k > size - 1)
		{
			k -= size;
		}
	}
	cout << endl;


	
	for (int i = size; i > 0; i--)
        {
            mass[i] = mass[i - 1];
        }
        mass[0] = rand() % 25;
        mass[size + 1] = rand() % 25;
        cout << "Массив в конечном итоге имеет следующие множества:" << ' ';
        for (int i = 0; i < size; i++)
        {
            cout << mass[i] << ' ';
        }
	

	
	cout << "Конечная версия последовательности:";
	int i = 0;
	for (int j = 0; j < size; j++)
	{
		mass[i] = mass[j];
		if (mass[j] % 2 != 0) 
		{
			i++;
			cout << mass[j] << " ";
		}
	}
}