#include <iostream>
using namespace std;

int main()
{
	int n,a,b,c, problems;
	cin >> n;
	problems = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		if(a + b + c >= 2)
			problems++;
	}
	cout << problems;
	return 0;
}
