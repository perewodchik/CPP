#include <iostream>
#include <cmath>
#define INF -2147483648
using namespace std;

/*
#19.Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
Если не все диагональные элементы матрицы положительны, 
заменить все простые числа в матрице на максимальные элементы 
соответствующих столбцов. Использовать процедуры и функции!
*/

int max_column(int index, int a[][100], int size);
bool prime(int size);
void input(int a[][100],int size);
bool diag_positive(int a[][100], int size);
void replace(int a[][100], int size);
void output(int a[][100],int size);

int main()
{
	int a[100][100],n;
	cin >> n;
	input(a,n);
	if(!diag_positive(a,n))
		replace(a,n);
	output(a,n);
	
	return 0;
}

int max_column(int index, int a[][100], int size)
{
	int max = INF;
	for(int i = 0; i < size; i++)
		if(a[i][index] > max) max = a[i][index];
	return max;
}

bool prime(int n)
{
	if(n <= 1) return false;
	if(n == 2) return true;
	for(int i = 2; i < sqrt(n)+1; i++)
		if(n % i == 0) return false;
	return true;
}

void input(int a[][100],int size)
{
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			cin >> a[i][j];
}

bool diag_positive(int a[][100], int size)
{
	for(int k = 0; k < size; k++)
		if(a[k][k] <= 0) 
			return false;
	return true;
}

void replace(int a[][100], int size)
{
	int max;
	for(int j = 0; j < size; j++)
		{
			max = max_column(j, a, size);
			for(int i = 0; i < size; i++)
				if(prime(a[i][j]))
					a[i][j] = max;
		}
}

void output(int a[][100],int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
