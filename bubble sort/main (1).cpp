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
        cin>>mass[i];
    }
    for(int i = 0;i <= n - 1;i++) // running along the length of the array
    {
        for(int j = 0;j <= n - 1 - i;j++) // comparing two bubbles and not counting the sorted ones
        {
            if(mass[j] > mass[j + 1])
            {
                tmp = mass[j + 1];
				mass[j + 1] = mass[j];
				mass[j] = tmp;
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        cout << mass[i] << " ";
    }
    cout << endl;
    delete mass;
    return 0;
}