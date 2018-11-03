#include <iostream>
#define INF 2147483647
using namespace std;

//#19.Дана целочисленная матрица {Aij}i=1,...,n;j=1,...,m (n,m<=20).    Найти минимум из произведений элементов столбцов.

int a[20][20];

int main()
{
	int n,m,min,multiply;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	
	min = INF;
	for(int j = 0; j < m; j++)
	{
		multiply = 1;
		for(int i = 0; i < n; i++)
			multiply *= a[i][j];
			
		if(multiply < min)
			min = multiply;
	}
	cout << min;
}
