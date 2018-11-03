#include <iostream>
#define INF -2147483648 
using namespace std;

/*
#19. Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
Найти столбец с наибольшей суммой элементов и заменить все элементы этого столбца этой суммой.
*/

int a[100][100];

int main()
{
	int n,m,sum,index,max=INF;
	
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
			
	for(int j = 0; j < m; j++)
	{
		sum = 0;
		for(int i = 0; i < n; i++)
			sum += a[i][j];
			
		if(sum > max)
		{
			max = sum;
			index = j;
		}
	}
	
	for(int i = 0; i < n; i++)
		a[i][index] = max;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
