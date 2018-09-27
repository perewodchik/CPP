#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	double a,b,c,x1,x2,D;
	cin >> a >> b >> c;
	D = b*b - 4*a*c;
	
	
	if(D > 0)
	{
		x1 = (-b + sqrt(D))/2;
		x2 = (-b - sqrt(D))/2;
		cout << "the solutions are: " << endl << x1 << " and " << x2;
	}
	else
		cout << "This equation has no real solutions.";
}
