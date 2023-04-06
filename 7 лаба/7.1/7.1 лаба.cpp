#include <iostream>

using namespace std;

int NOD (int a, int b)
{
    while(a > 0 && b > 0)
 
        if(a > b)
        {
            a %= b;
        }
 
        else
        {
            b %= a;
        }
 
    return (a + b);
}

void addition(int aChis, int aZnam, int bChis, int bZnam)
{
    int Chislitel, Znamenatel, Sokraschenie;
    Chislitel = (aChis * bZnam) + (bChis * aZnam);
    Znamenatel = (aZnam * bZnam);
    Sokraschenie = NOD(Chislitel, Znamenatel);
    Chislitel /= Sokraschenie;
    Znamenatel /= Sokraschenie;
    cout << Chislitel << "/" << Znamenatel << endl;
    
}

void addition(float a, float b)
{
    cout << (a + b);
}

int main()
{
    setlocale(LC_ALL, "RU");
    int aChis, aZnam, bChis, bZnam;
    float a, b;
    cout << " Введите дроби, которые вы хотите сложить:" << endl; 
    cin >> aChis >> aZnam >> bChis >> bZnam;
    cout << "Введите десятичные дроби, которые вы хотите сложить:" << endl;
    cin >> a >> b;
    addition (aChis, aZnam, bChis, bZnam);
    addition (a, b);

    return 0;
}