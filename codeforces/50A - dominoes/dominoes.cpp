#include <iostream>
using namespace std;

int main()
{
	int a,b, dominoes;
	cin >> a >> b;
	if( a % 2 == 0 || b % 2 == 0)
	{
		if(a % 2 == 0)
		{
			dominoes = (a/2)*b;
		}
		else
		{
			dominoes = (b/2)*a;
		}
	}
	else
	{
		dominoes = (a*b-1)/2;
	}
	cout << dominoes;
}
