#include <iostream>
#include <string>
using namespace std;

void alphabetSort(string s)
{
	if (s[0] != '1' and s[0] != '2' and s[0] != '3' and s[0] != '4' and s[0] != '5' and s[0] != '6' and s[0] != '7' and s[0] != '8' and s[0] != '9' and s[0] != '0')
	{
		for (int i = 0; i < s.length() - 1; i++)
		{
			for (int j = i + 1; j < s.length(); j++)
			{
				if (s[i] > s[j])
				{
					char t = s[i];
					s[i] = s[j];
					s[j] = t;
				}
			}
		}
	}							
	cout << s << " ";
}


int main()
{
	string s = "";
	getline(cin, s);
	string word = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			alphabetSort(word);
			word = "";
		}
		else
		{
			word += s[i];
		}
		if (i == s.length() - 1)
		{
			alphabetSort(word);
		}
	}
	return 0;
}