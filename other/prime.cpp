#include <iostream>
using namespace std;

int main()
{
	int number;
	number = 120393019;
	bool is_prime=true;
	for (int i = 2; i < number; i++)
	{
		if ( (number % i == 0) && (number != 2) ) 
		{
			is_prime = false;
			break;
		}
	}
	if(is_prime)
	{
		cout << number << " is prime" << endl;
	}
	else
	{
		cout << number <<  " is not prime" << endl;
	}

}
