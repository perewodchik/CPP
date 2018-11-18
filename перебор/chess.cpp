#include <iostream>
#include <iomanip>
using namespace std;
double probabilities[15];
int a,b,c,N,K;
int choice;
/*
	choice 1 = first person won
	choice 2 = second person won
	choice 3 = draw
*/
void input();
void handle(int i, double current_probability,int a_wins,int b_wins,int choice);
void output();

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	input();
	handle(0, 1.00, 0, 0, -1);
	output();
}

void input()
{
	cin >> a >> b >> c >> N >> K;
}

void handle(int i, double current_probability,int a_wins,int b_wins,int choice)
{
	switch (choice)
	{
		case 1:
			current_probability *= double(a)/(a+b+c);
			a_wins++;
			break;
		case 2:
			current_probability *=  double(b) / (a+b+c);
			b_wins++;
			break;
		case 3:
			current_probability *= double(c) / (a+b+c);
			break;
		default:
			break;
	}
	if(i >= N || a_wins - b_wins >= K || b_wins - a_wins >= K)
	{
		probabilities[i] += current_probability;
		return;
	}
	handle(i+1, current_probability, a_wins, b_wins, 1);
	handle(i+1, current_probability, a_wins, b_wins, 2);
	handle(i+1, current_probability, a_wins, b_wins, 3);
}

void output()
{
	double sum = 0.00;
	for(int k = 1; k <= N; k++)
		sum += k*probabilities[k];
	cout << setprecision(4) << fixed << sum;
}

