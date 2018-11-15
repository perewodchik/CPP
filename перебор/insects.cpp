#include <iostream>
using namespace std;

int V[30];
int P[30];
int best = 30000000;
void search(int K, int N, int i,int price, int capacity);
void input(int &N,int &K);

int main()
{
	freopen("insects.in", "r", stdin);
	freopen("insects.out", "w", stdout);
	int N, K;
	input(N, K);
	search(K,N,0,0,0);
	if(best != 30000000)
		cout << best;
	else
		cout << -1;
}

void input(int &N,int &K)
{
	cin >> N >> K;
	for(int i = 0; i < K; i++)
		cin >> V[i];
	for(int i = 0; i < K; i++)
		cin >> P[i];
}

void search(int K, int N, int i,int price, int capacity)
{
	if(capacity >= N)
	{
		best = min(best, price);
		return;
	}
	if( i == K )
		return;
		
	search(K, N, i+1, price, capacity);
	price += P[i];
	capacity += V[i];
	search(K, N, i+1, price, capacity);
	price -= P[i];
	capacity -= V[i];
}

