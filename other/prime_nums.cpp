#include <iostream>
#include <vector>
#include <iomanip>

#define VI vector<int>

using namespace std;

int main()
{
	
	VI prime;
	const int supremum = 1000000;
	bool is_prime;
	
	prime.push_back(2);
	
	for(int i = 3; i < supremum; i++)
	{
		is_prime = true;
		for(int j = 0; j < prime.size(); j++)
		{
			if(i % prime[j] == 0)
				is_prime = false;
		}
		
		if(is_prime)
			prime.push_back(i);
		
	}
	
	for(int i = 0; i < prime.size(); i++)
		{
			cout << setw(7) << prime[i];
		}
}
