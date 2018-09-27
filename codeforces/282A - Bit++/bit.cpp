#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,value;
	string input;
	value = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> input;
		if(input.find("++") == 1 || input.find("++") == 0)
		{
			value++;
		}
		else
		{
			value--;
		}
	}
	cout << value; 
}
