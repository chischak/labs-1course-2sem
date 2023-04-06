#include <iostream>
using namespace std;

int size;
void m(int** pp, int* p, int u)
{
    setlocale (LC_ALL, "RU");
    for (int i = 0; i < u; i++)
    {
        int imax = i;
        int jmax = 0;
        for (int k = i; k < u; k++)
        {
            for (int j = 0; j < u - i; j++)
            {
                if (pp[k][j] > pp[imax][jmax])
                {
                    imax = k;
                    jmax = j;
                }
            }
        }
        if (imax > i)
        {
            for (int j = 0; j < u; j++)
            {
                p[j] = pp[imax][j];
            }
            for (int k = imax; k > i; k--)
            {
                for (int j = 0; j < u; j++)
                {
                    pp[k][j] = pp[k - 1][j];
                }
            }
            for (int j = 0; j < u; j++)
            {
                pp[i][j] = p[j];
            }
        }
        if (jmax < u - i - 1)
        {
            for (int k = 0; k < u; k++)
            {
                p[k] = pp[k][jmax];
            }
            for (int j = jmax; j < u - i - 1; j++)
            {
                for (int k = 0; k < u; k++)
                {
                    pp[k][j] = pp[k][j + 1];
                }
            }
            for (int k = 0; k < u; k++)
            {
                pp[k][u - i - 1] = p[k];
            }
        }
    }
    cout << "Конечная последовательность:" << endl;
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < u; j++)
        {
            cout << pp[i][j] << " ";
        }
        cout << endl;
    }
    bool flag = false;
    int m = 1;
    while (m < u and flag == false)
    {
        if (pp[m][u - m - 1] >= pp[m - 1][u - m])
        {
            flag = true;
        }
        else
        {
            m++;
        }
    }
    if (flag == true)
    {
        cout << "Диагоноаль не убывает.";
    }
    else
    {
        cout << "Диагональ убывает.";
    }
}
int main()
{
    cout << " Введите длину последовательности: " << endl;
    cin >> size;
    int** a = new int* [size];
    int* b = new int [size];
    for (int i = 0; i < size; i++)
    {
        a[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            a[i][j] = rand() % 1001;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    m(a, b, size);
    return 0;
}