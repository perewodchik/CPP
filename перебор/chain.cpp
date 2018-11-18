#include <iostream>
#include <vector>
#define N_MAX 40
using namespace std;
int N, sequence[N_MAX], best_seq[N_MAX], max_seq = 0;
vector<string> words(N_MAX);
bool used[N_MAX];

void input();
void handle(int i);
void output();
/*
	IDEA:
	take first word, take second word, 
	if ending of first is equal to beginning of second, then they make a chain!
	
	Words are counted from 0 to N-1
	Sequence looks at which words are currently in the chain
	Used checks whether word has been taken
*/

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	input();
	handle(0);
	output();
}

void input()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> words[i];
}

void handle(int i)
{
	if(i >= 2)
	{
		/*	here we check the added words and we check whether the last symbol of previous word
			is equal to first symbol of current word.
			if so, then it forms a chain we might consider it as the best sequence and save it 
				AND we are gonna look for the next word without returning
			if not, then we return and will check for the next word
		*/
		if( words[ sequence[i-2] ][ words[ sequence[i-2] ].size()-1 ] == words[ sequence[i-1] ][0] )
		{
			if(i > max_seq)
			{
				max_seq = i;
				for(int l = 0; l < max_seq; l++)
					best_seq[l] = sequence[l];
			}
		}
		else return;
	}
	
	//All words are used
	if(i > N)
		return;
		
	for(int k = 0; k < N; k++)
	{
		//if word is not used, we add it to the list
		//and after handling that word is removed
		if(!used[k]) 
		{
			sequence[i] = k;
			used[k] = true;
			handle(i+1);
			sequence[i] = 0;
			used[k] = false;
		}
	}
}

void output()
{
	for(int i = 0; i < max_seq; i++)
		cout << words[ best_seq[i] ] << "\n";
}
