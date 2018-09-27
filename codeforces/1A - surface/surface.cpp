#include <iostream>
using namespace std;

int main()
{
	unsigned long int n,m,a;
	unsigned long int n_i;
	unsigned long int m_i;
	
	cin >> n >> m >> a;
	n_i = 1;
	m_i = 1;
	while(n_i*a < n)
	{
		n_i = n_i * 2;
	}
	while(n_i*a > n)
	{
		n_i--;
	}
	while(n_i*a < n)
	{
		n_i++;
	}
	
	
	while(m_i*a < m)
	{
		m_i = m_i * 2;
	}
	while(m_i*a > m)
	{
		m_i--;
	}
	while(m_i*a < m)
	{
		m_i++;
	}

	cout << (unsigned long long) n_i * m_i;
}
