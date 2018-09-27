#include <iostream>
#include <vector>
using namespace std;

struct taxi
{
	short people;
	bool used;
	bool on_taxi;	
};

int main()
{
	int n;
	cin >> n;
	vector<taxi> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].people;
	}
	for(int i = 0; i < n; i++)
	{
		if(a[i].people)
	}
}
