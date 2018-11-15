#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	int rows1,columns1,rows2,columns2;
	
	cout << "Creating first matrice..." << endl;
	cout << "Enter amount of rows: ";
	cin >> rows1;
	cout << "Enter amount of columns: ";
	cin >> columns1;
	int A[rows1][columns1];
	for (int i = 0; i < rows1; i++)
	{
		cout << "Type numbers one at a time to complete row number " << i+1 << endl;
		for (int j = 0; j < columns1; j++)
		{
			cin >> A[i][j];
		}
	}
	cout << "You have completed first matrice! This is how it looks like" << endl << endl;


	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < columns1; j++)
		{
			cout << setw(4) << A[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	cout << "Now let's create second matrice" << endl;

	cout << "Creating second matrice...";
	cout << "Enter amount of rows: ";
	cin >> rows2;
	cout << "Enter amount of columns: ";
	cin >> columns2;
	int B[rows2][columns2];
	for (int i = 0; i < rows2; i++)
	{
		cout << "Type numbers one at a time to complete row number " << i+1 << endl;
		for (int j = 0; j < columns2; j++)
		{
			cin >> B[i][j];
		}
	}
	cout << "You have completed second matrice! This is how it looks like" << endl << endl;
	for (int i = 0; i < rows2; i++)
	{
		for (int j = 0; j < columns2; j++)
		{
			cout << setw(4) << B[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	if (columns1 != rows2)
	{
		cout << "you can't multiply these 2 matrices. Try again";
		system("PAUSE");
		return 0;
	}
	
	int C[rows1][columns2];
	int sum;
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < columns2; j++)
		{
			sum = 0;
			for (int k = 0; k < rows1; k++)
			{
				sum += A[i][k]*B[k][j];	
			}
			C[i][j] = sum;	
		}
	}
	
	cout << "Multiplication is complete. Look at the result!" << endl << endl;
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < columns2; j++)
		{
			cout << setw(4) << C[i][j];
		}
		cout << endl;
	}
	
	system("PAUSE");
	return 0;
}
