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
    for(int i = 0;i < n;i++)
    {
        for(int j = i;j > 0 and mass[j - 1] > mass[j];j--)
        {
                tmp = mass[j];
				mass[j] = mass[j - 1];
				mass[j - 1] = tmp;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        cout << mass[i- 1] << " ";
    }
    cout << endl;
    delete mass;
    return 0;
}