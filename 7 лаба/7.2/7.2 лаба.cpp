#include <iostream>
#include <stdarg.h>
using namespace std;

int sum(int k, ...)
{
	va_list factor;
	va_start(factor, k);
	int s = 0;
	int tmp1 = va_arg(factor, int);
	for (int i = 1; i < k; i++)
	{
		int tmp2 = va_arg(factor, int);
		if (i % 2 == 0)
		{
			s -= tmp1 * tmp2;
		}
		else
		{
			s += tmp1 * tmp2;
		}
		tmp1 = tmp2;
	}
	va_end(factor);
	return s;
}

int main()
{
	cout << sum(5, 1, 2, 3, 4, 5) << endl;
	cout << sum(10, 2, 4, 6, 8, 10, 12, 14, 16, 17, 18) << endl;
	cout << sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << endl;
	return 0;
}