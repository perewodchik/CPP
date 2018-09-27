#include <iostream>
using namespace std;

int main()
{
	int n, k, min, people, current;
	cin >> n >> k;
	min = 101;
	people = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> current;
		
		if(i == 1)
			min = current;
		
		if(current == 0)
			break;
		
		if(i > k)
		{
			if(current >= min)
				people++;
			else
				break;
		}
		else
		{
			min = current;
			people++;
		}
	}
	cout << people;
}
