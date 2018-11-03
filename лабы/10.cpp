#include <iostream>
using namespace std;
/*
#19.������ ������������������ ����������� ����� {Aj}j=1...n (n<=1000). 
����������� ������������������ �� ���������� ���������� ����� �����, 
����� � ����������� ����������� ������� ������������� ����������� �� ���������� ������������ ���� �����, 
����� � ����������� ����������� ������� � ����������� �������������� ���� ������������� ����������� �� ���������� ������ �����.
*/

int a[1001];

bool min_digit(int a)
{
	int x;
	int a_min = 10;
	while(a)
	{
		x = a % 10;
		if(x < a_min)
			a_min = x;
		a /= 10;
	}
	return a_min;
}

bool digit_multiply(int a)
{
	int x;
	int multiply = 1;
	while(a)
	{
		x = a % 10;
		multiply *= x;
		a /= 10;
	}
	return multiply;
}

int main()
{
	int n;
	cin >> n;
	//���� ������������������
	for(int i = 1; i <= n; i++)
		a[i] = i;
	
	//���������� �� ������ ��������
	for(int i = n; i > 1; i--)
	{
		for(int j = 1; j < i; j++)
		{
			if( min_digit(a[j]) > min_digit(a[j+1]) )
				swap(a[j], a[j+1]);
			else if( min_digit(a[j]) == min_digit(a[j+1]) )
			{
				if( digit_multiply(a[j]) > digit_multiply(a[j+1]) )
					swap(a[j], a[j+1]);
				else if( digit_multiply(a[j]) == digit_multiply(a[j+1]) )
					if(a[j] > a[j+1])
						swap(a[j], a[j+1]);
			}
		}
	}
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
}
