#include <iostream>
using namespace std;

int main()
{
    int n, tmp;
    cin >> n;
    int *mass;
    mass = new int[n];
    for(int i = 1;i <= n;i++)
    {
        cin>>mass[i - 1];
    }
    for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i; j < n; j++)
		{
			if (mass[j] < mass[min])
			{
				min = j;
			}
		}
		tmp = mass[i];
		mass[i] = mass[min];
		mass[min] = tmp;
	}
    for(int i = 1;i <= n;i++)
    {
        cout << mass[i- 1] << " ";
    }
    cout << endl;
    delete mass;
    return 0;
}