#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string a,b;
	cin >> a;
	cin >> b;
	short state = 0;
	transform(a.begin(), a.end(),a.begin(), ::tolower);
	transform(b.begin(), b.end(),b.begin(), ::tolower);
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] > b[i])
		{
			state = 1;
			break;
		}
		if(a[i] < b[i])
		{
			state = -1;
			break;
		}
	}
	cout << state;
}
