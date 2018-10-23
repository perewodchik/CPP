#include <iostream>
using namespace std;

int a[10001];
int b[10001];
int c[10001];
int m[10001];

int main()
{
	freopen("peak.in", "r", stdin);
	freopen("peak.out", "w", stdout);
	ios::sync_with_stdio(0);
	
	int n,sum;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	
	for(int i = 1; i <= n+1; i++)
		m[i] = m[i]+a[i-1];
		

	for(int i = 1; i <= n+1; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(c[j] == i)
				m[i] = max(m[i], m[j] + b[j]);
		}
		m[i] = max(m[i], m[i-1]+a[i-1]);
	}
	/*
	for(int i = 1; i<= n+1; i++)
	{
		cout << i << " -> " << m[i] << " " << endl;
	}*/
	
	cout << m[n+1];
	
	return 0;
}
