#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <sstream>
#include <iomanip>
#define VI vector<int>
#define SI set<int>

using namespace std;

//converts string into vector of integers
vector<int> string_to_number(string str)
{
	vector<int> nums;
	bool negativ = false;
	int j = 0;
	
	//handling first number
	nums.push_back(0);
	
	for(int i = 0; i < str.size(); i++)
	{
		//if new number found
		if(str[i] == ' ')
		{
			if(negativ)
				nums[j] = -nums[j]; 
				
			nums.push_back(0);
			negativ = false;
			j++;
		}	
		
		if(str[i] == '-')
		{
			negativ = true;
		}
		
		if(str[i] >= '0' && str[i] <='9')
		{
			nums[j] *= 10;
			nums[j] += (str[i] - '0');
		}		
	}
	
	if(negativ)
		nums[j] = -nums[j];
	
	return nums;
}


int factorial(int n)
{
	if(n == 1 || n == 0)
	{
		return 1;
	}
	return factorial(n-1)*n;
}


int main()
{
	int n,input;
	fstream matrix_input;
	
	
	matrix_input.open("matrix.txt", fstream::in);
	matrix_input >> n;

	vector< vector<int> > matrix(n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			matrix_input >> input;
			matrix[i].push_back(input);
		}
	}
	
	//working with file
	fstream permutations;
	ostringstream convert;
	string filename;
	convert << n;
	filename = "permutations\\" + convert.str() + ".txt";
	permutations.open(filename.c_str(), fstream::in);
	
	string line;
	vector<int> number_line;
	long determinant = 0;
	int inversions;
	//Reading a line in permutations
	for(int i = 0; i < factorial(n); i++)
	{
		getline(permutations, line);
		number_line = string_to_number(line);
		
		//handling a line of permutations
		
		//finding amount of inversions in this permutations
		inversions = 0;
		for(int i_1 = 0; i_1 < number_line.size()-1; i_1++)
		{
			for(int j = i_1+1; j < number_line.size(); j++)
			{
				if(number_line[i_1] > number_line[j])
					inversions++;
			}
		}
		
		
		int epsilon = 0;
		if(inversions % 2 == 0)
			epsilon = 1;
		else
			epsilon = -1;
			
		int det_term = 1;
		for(int i_2 = 0; i_2 < n; i_2++)
		{
			det_term *= matrix[i_2][ number_line[i_2]-1 ];
		}
		
		determinant += det_term*epsilon;
		
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << left << setw(4) << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl << "This is a square matrix of size " << n << endl << endl;
	cout << "For this matrix determinant is " << determinant << endl << endl;
	
	
	matrix_input.close();
	permutations.close();
	system("pause");
	return 0;
}
