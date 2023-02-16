#include <iostream>

using namespace std;
void HanoiTower (int n, int from, int to, int extra )
{
    if (n == 0)
    {
        return;
    }
    HanoiTower (n - 1, from, extra, to);
     cout << "Move disk " << n << " from stick " << from << " to stick " << to << endl;
    HanoiTower (n - 1, extra, to, from);
     
}

int main()
{
    int n;
    cin >> n;
    HanoiTower (n, 1, 2, 3);

    return 0;
}