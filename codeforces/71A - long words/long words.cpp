#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string *words = 0;
	words = new string[n];
	for(int i = 0; i < n; i++)
	{
		cin >> words[i];
	}
	for(int i = 0; i < n; i++)
	{
		if (words[i].length() > 10)
		{
			cout << words[i].at(0) << words[i].length()-2 << words[i].at(words[i].length()-1) << endl;
		}
		else
		{
			cout << words[i] << endl;
		}
	}
	return 0;
}
