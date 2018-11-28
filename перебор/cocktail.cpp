#include <iostream>
#define NMAX 30
using namespace std;
int N,M, best=0,
	pairs[NMAX][NMAX],
	taken[NMAX];
void input();
void handle(int i, int ingredients);
void output();

int main()
{
	freopen("cocktail.in", "r", stdin);
	freopen("cocktail.out", "w", stdout);
	input();
	handle(1, 0);
	output();
}

void input()
{
	cin >> N >> M;
	int a,b;
	for(int i = 1; i <= M; i++)
	{
		cin >> a >> b;
		pairs[a][b] = 1;
		pairs[b][a] = 1;
	}
}

void handle(int i, int ingredients)
{
	best = max(best, ingredients);
	if(i > N)
	{
		return;
	}
	//not taking	
	handle(i+1, ingredients);
	//taking if we can
	if(taken[i] == 0)
	{
		taken[i] = 1;
		//...and adding possible restrictions
		for(int k = 1; k <= N; k++)
			taken[k] += pairs[i][k];
			
		handle(i+1, ingredients+1);
		
		taken[i] = 0;
		for(int k = 1; k <= N; k++)
			taken[k] -= pairs[i][k];
	}
}

void output()
{
	cout << best << endl;
}
