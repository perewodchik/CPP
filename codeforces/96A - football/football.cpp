#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input, current;
	int streak;
	bool flag;
	cin >> input;
	flag = false;
	streak = 0;
	current = "0";
	for(int i = 0; i < input.size(); i++)
	{
		if(input.at(i) == '1')
		{
			if(current == "1")
				streak++;
			else
			{
				current = "1";
				streak = 1;
			}
		}
		else
		{
			if(current == "0")
				streak++;
			else
			{
				current = "0";
				streak = 1;
			}
		}
		
		if(streak >= 7)
		{
			flag = true;
			break;
		}
	}
	if(flag)
		cout << "YES";
	else
		cout << "NO";
}
