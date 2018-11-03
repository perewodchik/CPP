#include <iostream>
#include <cmath>
using namespace std;

/*
	#19.���� ������������������ ������������ ����� {Aj}.
	H���� ������������ ����� � ������� �p����� ������,
	���������� �� ����� ����� � ����p ����� ����� � ������������������.
*/

int main()
{
	double input, fract;
	long long multiply=1;
	int i=1, min=INT_MAX, min_index=0;
	
	while(cin >> input)
	{
		fract = modf(input, &input);
		if(fract == 0)
		{
			multiply *= (int)input;
			if(input < min)
			{
				min_index = i;
				min = input;
			}
		}
		i++;
	}
	
	if(min_index)
		cout << multiply << ", " << min << ", " << min_index << endl;
	
	return 0;
}
