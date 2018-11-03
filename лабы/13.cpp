#include <iostream>
using namespace std;
/*
#19. Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
Удалить из последовательности числа, содержащие цифру 2, а среди оставшихся продублировать числа-палиндромы.

Сначала введите последовательность так, как она задана во входном файле. Затем удалите и продублируйте элементы. 
Затем выведите полученную последовательность (каждый элемент по одному разу). Используйте в программе только один массив.
*/


int a[20000];

int has_two(int a)
{
	while(a)
	{
		if(a%10 == 2)
			return true;
		a /= 10;
	}
	return false;
}

int palindrome(int n)
{
	int reverse = 0;
	int a = n;
	while(a)
	{
		reverse = (reverse*10) + a%10;
		a /= 10;
	}
	return n == reverse;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	
	for(int i = 0; i < n; i++)
	{
		if(has_two(a[i]))
		{
			n--;
			for(int k = i; k < n; k++)
				a[k]=a[k+1];
			i--;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		if(palindrome(a[i]))
		{
			n++;
			for(int k = n-1; k > i; k--)
				a[k] = a[k-1];
			i++;
		}
	}
	
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	
	return 0;
}

