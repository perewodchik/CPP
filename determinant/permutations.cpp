#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#define VI vector<int>
#define SI set<int>

using namespace std;

//generates permutations of n elements and outputs them in file "permutations.txt"
void generate_permutations(int n, VI permutations={}, SI used={}, int deep=-1)
{
	if(deep == -1)
		deep = n;
		
	if(deep == 0)
	{
		
		for(int i = 0; i < permutations.size(); i++)
		{
			if(i != 0)
				cout << " ";
			cout << permutations[i];
		}
		cout << endl;
		return;
	}
	
	for(int i = 1; i <= n; i++)
	{
		//if element is in set
		if(used.find(i) != used.end() )
			continue;
		permutations.push_back(i);
		used.insert(i);
		generate_permutations(n, permutations, used, deep-1);
		permutations.pop_back();
		used.erase(i);
	}
	
}

int main()
{
	int n;
	n = 1;
	freopen("1.txt", "w", stdout);
	generate_permutations(n);
}
