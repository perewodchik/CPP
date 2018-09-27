#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const short YEARS = 10;
	int deposit, interest;
	float earning;
	cout << "Enter your deposit: ";
	cin >> deposit;
	cout << "Enter interest you'll get(in %): ";
	cin >> interest;
	earning = deposit;
	cout << setw(10) << "Date" << setw(15) << "You'll have" << endl;
	for (short i = 0; i < YEARS; i++)
	{
		cout << setw(10) << "year " << i << setw(15) << fixed << setprecision(2) << earning << endl;
		earning = earning + earning*( float(interest)/100 );
	}
	cout << endl << "In " << YEARS << " you will earn " << earning - deposit << endl;
}
